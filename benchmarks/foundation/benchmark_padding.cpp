//  Copyright (C) 2015-2019 Virgil Security, Inc.
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      (1) Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
//
//      (2) Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in
//      the documentation and/or other materials provided with the
//      distribution.
//
//      (3) Neither the name of the copyright holder nor the names of its
//      contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
//  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
//  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
//  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>


#include "benchmark/benchmark.h"

#include "vscf_memory.h"
#include "vscf_random_padding.h"
#include "vscf_padding_cipher.h"
#include "vscf_aes256_gcm.h"
#include "vscf_fake_random.h"
#include "vscf_padding_params.h"

#include "benchmark_data.h"
#include <chrono>

static const size_t chunk_size = 32;

void
compare_encrypt(benchmark::State &state) {
    // manual initialize
    vscf_aes256_gcm_t *aes256_gcm = vscf_aes256_gcm_new();

    size_t zero_len = state.range(0);
    byte *zero_bytes = (byte *)calloc(zero_len, 1);

    vscf_aes256_gcm_set_key(aes256_gcm, bench_data_padding_cipher_AES256_KEY);
    vscf_aes256_gcm_set_nonce(aes256_gcm, bench_data_padding_cipher_AES256_NONCE);

    vsc_data_t zeros = vsc_data(zero_bytes, zero_len);

    vscf_fake_random_t *fake_random = vscf_fake_random_new();
    vscf_fake_random_setup_source_byte(fake_random, 0xAB);

    vscf_random_padding_t *padding = vscf_random_padding_new();
    vscf_random_padding_take_random(padding, vscf_fake_random_impl(fake_random));

    vscf_padding_cipher_t *padding_cipher = vscf_padding_cipher_new();
    vscf_padding_cipher_take_padding(padding_cipher, vscf_random_padding_impl(padding));
    vscf_padding_cipher_use_cipher(padding_cipher, vscf_aes256_gcm_impl(aes256_gcm));

    vscf_padding_cipher_start_encryption(padding_cipher);

    const size_t out_len =
            vscf_padding_cipher_out_len(padding_cipher, zero_len) + vscf_padding_cipher_out_len(padding_cipher, 0);
    vsc_buffer_t *out = vsc_buffer_new_with_capacity(out_len);

    for (auto _ : state) {

        auto start_manual = std::chrono::high_resolution_clock::now();
        vscf_aes256_gcm_start_encryption(aes256_gcm);

        for (int i = 0; i < zero_len; i += chunk_size) {
            size_t current_chunk_size = chunk_size;
            if (i + current_chunk_size > zero_len) {
                current_chunk_size = zero_len - i;
            }

            vscf_aes256_gcm_update(aes256_gcm, vsc_data_slice_beg(zeros, i, current_chunk_size), out);
        }

        vscf_aes256_gcm_finish(aes256_gcm, out);

        auto end_manual = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds_manual =
                std::chrono::duration_cast<std::chrono::duration<double>>(end_manual - start_manual);

        vsc_buffer_reset(out);

        auto start_padding = std::chrono::high_resolution_clock::now();

        vscf_padding_cipher_start_encryption(padding_cipher);
        vscf_padding_cipher_update(padding_cipher, zeros, out);
        vscf_padding_cipher_finish(padding_cipher, out);

        auto end_padding = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds_padding =
                std::chrono::duration_cast<std::chrono::duration<double>>(end_padding - start_padding);

        vsc_buffer_reset(out);

        state.counters["1. manual"] =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_seconds_manual).count();
        state.counters["2. padding"] =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_seconds_padding).count();

        state.counters["3. p/m %"] = ((elapsed_seconds_padding.count() - elapsed_seconds_manual.count()) /
                                      elapsed_seconds_manual.count() * 100);
        state.SetIterationTime(elapsed_seconds_manual.count() + elapsed_seconds_padding.count());
    }

    vscf_padding_cipher_destroy(&padding_cipher);
    vscf_aes256_gcm_destroy(&aes256_gcm);
    vsc_buffer_destroy(&out);
}

void
compare_decrypt(benchmark::State &state) {

    // manual initialize
    vscf_aes256_gcm_t *aes256_gcm = vscf_aes256_gcm_new();

    size_t zero_len = state.range(0);
    byte *zero_bytes = (byte *)calloc(zero_len, 1);

    vsc_data_t zeroes = vsc_data(zero_bytes, zero_len);

    vscf_aes256_gcm_set_key(aes256_gcm, bench_data_padding_cipher_AES256_KEY);
    vscf_aes256_gcm_set_nonce(aes256_gcm, bench_data_padding_cipher_AES256_NONCE);

    // encrypt zeros
    vsc_buffer_t *encrypted = vsc_buffer_new_with_capacity(vscf_aes256_gcm_encrypted_len(aes256_gcm, zero_len));
    vscf_aes256_gcm_encrypt(aes256_gcm, zeroes, encrypted);
    vsc_data_t encrypted_zeros = vsc_buffer_data(encrypted);


    // padding initialize
    vscf_fake_random_t *fake_random = vscf_fake_random_new();
    vscf_fake_random_setup_source_byte(fake_random, 0xAB);

    vscf_random_padding_t *padding = vscf_random_padding_new();
    vscf_random_padding_take_random(padding, vscf_fake_random_impl(fake_random));

    vscf_padding_cipher_t *padding_cipher = vscf_padding_cipher_new();
    vscf_padding_cipher_take_padding(padding_cipher, vscf_random_padding_impl(padding));
    vscf_padding_cipher_use_cipher(padding_cipher, vscf_aes256_gcm_impl(aes256_gcm));

    vscf_padding_cipher_start_decryption(padding_cipher);

    const size_t out_len = vscf_padding_cipher_out_len(padding_cipher, encrypted_zeros.len) +
                           vscf_padding_cipher_out_len(padding_cipher, 0);
    vsc_buffer_t *out = vsc_buffer_new_with_capacity(out_len);
    size_t encrypted_zeroes_len = encrypted_zeros.len;

    for (auto _ : state) {
        auto start_manual = std::chrono::high_resolution_clock::now();
        vscf_aes256_gcm_start_decryption(aes256_gcm);
        for (int i = 0; i < encrypted_zeroes_len; i += chunk_size) {
            size_t current_chunk_size = chunk_size;
            if (i + current_chunk_size > encrypted_zeroes_len) {
                current_chunk_size = encrypted_zeroes_len - i;
            }

            vscf_aes256_gcm_update(aes256_gcm, vsc_data_slice_beg(encrypted_zeros, i, current_chunk_size), out);
        }
        vscf_aes256_gcm_finish(aes256_gcm, out);

        auto end_manual = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds_manual =
                std::chrono::duration_cast<std::chrono::duration<double>>(end_manual - start_manual);
        vsc_buffer_reset(out);

        auto start_padding = std::chrono::high_resolution_clock::now();

        vscf_padding_cipher_start_decryption(padding_cipher);

        vscf_padding_cipher_update(padding_cipher, encrypted_zeros, out);
        vscf_padding_cipher_finish(padding_cipher, out);

        auto end_padding = std::chrono::high_resolution_clock::now();
        auto elapsed_seconds_padding =
                std::chrono::duration_cast<std::chrono::duration<double>>(end_padding - start_padding);

        state.counters["1. manual"] =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_seconds_manual).count();
        state.counters["2. padding"] =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_seconds_padding).count();


        state.counters["3. p/m %"] = ((elapsed_seconds_padding.count() - elapsed_seconds_manual.count()) /
                                      elapsed_seconds_manual.count() * 100);
        state.SetIterationTime(elapsed_seconds_manual.count() + elapsed_seconds_padding.count());
        vsc_buffer_reset(out);
    }

    vscf_aes256_gcm_destroy(&aes256_gcm);
    vsc_buffer_destroy(&out);
}


BENCHMARK(compare_encrypt)->Arg(1024)->Iterations(100000);
BENCHMARK(compare_encrypt)->Arg(1024 * 1024 * 4)->Iterations(10);

// add this to program argument --benchmark_counters_tabular=true
// note that time in this benchmark is just total time of 2
BENCHMARK(compare_decrypt)->Arg(1024)->Iterations(100000);
BENCHMARK(compare_decrypt)->Arg(1024 * 1024 * 4)->Iterations(10);
