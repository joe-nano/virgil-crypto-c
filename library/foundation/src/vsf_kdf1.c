//  @license
// --------------------------------------------------------------------------
//  Copyright (C) 2015-2018 Virgil Security Inc.
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
// --------------------------------------------------------------------------


//  @description
// --------------------------------------------------------------------------
//  This module contains 'kdf1' implementation.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vsf_kdf1.h"
#include "vsf_assert.h"
#include "vsf_memory.h"
#include "vsf_hash_stream.h"
#include "vsf_kdf1_impl.h"
#include "vsf_kdf1_internal.h"
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Calculate hash over given data.
//
VSF_PUBLIC void
vsf_kdf1_derive(vsf_kdf1_impl_t* kdf1_impl, const byte* data, size_t data_len, byte* key, size_t key_len) {

    VSF_ASSERT_PTR(kdf1_impl);
    VSF_ASSERT_PTR(kdf1_impl->hash);
    VSF_ASSERT_PTR(data);
    VSF_ASSERT_PTR(key);


    // Get HASH parameters
    size_t digest_len = vsf_hash_info_digest_size(vsf_hash_info_api(kdf1_impl->hash));
    unsigned char* digest = vsf_alloc(digest_len);

    // Get KDF parameters
    size_t counter = 0;
    size_t counter_len = VSF_CEIL(key_len, digest_len);
    size_t current_key_len = 0;
    unsigned char counter_string[4] = {0x0};

    // Start hashing
    for (; counter < counter_len; ++counter) {
        counter_string[0] = (unsigned char)((counter >> 24) & 255);
        counter_string[1] = (unsigned char)((counter >> 16) & 255);
        counter_string[2] = (unsigned char)((counter >> 8)) & 255;
        counter_string[3] = (unsigned char)(counter & 255);

        vsf_hash_stream_start(kdf1_impl->hash);
        vsf_hash_stream_update(kdf1_impl->hash, data, data_len);
        vsf_hash_stream_update(kdf1_impl->hash, counter_string, sizeof(counter_string));

        if (current_key_len + digest_len <= key_len) {
            vsf_hash_stream_finish(kdf1_impl->hash, key + current_key_len, digest_len);
            current_key_len += digest_len;

        } else {
            vsf_hash_stream_finish(kdf1_impl->hash, digest, digest_len);
            memcpy(key + current_key_len, digest, key_len - current_key_len);
            current_key_len = key_len;
        }
    }

    vsf_erase(digest, data_len);
    vsf_dealloc(digest);
}