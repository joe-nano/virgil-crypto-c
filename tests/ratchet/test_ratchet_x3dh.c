//  Copyright (C) 2015-2020 Virgil Security, Inc.
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

#define UNITY_BEGIN() UnityBegin(__FILENAME__)

#include <test_utils.h>
#include "unity.h"

#define TEST_DEPENDENCIES_AVAILABLE VSCR_RATCHET
#if TEST_DEPENDENCIES_AVAILABLE

#include <ed25519/ed25519.h>
#include "vscr_ratchet_x3dh.h"
#include "test_data_ratchet_x3dh.h"
#include "test_utils_ratchet.h"

void
test__initiator_x3dh__fixed_keys__should_match(void) {
    vscr_ratchet_symmetric_key_t shared_secret;

    vscr_status_t status =
            vscr_ratchet_x3dh_compute_initiator_x3dh_secret(test_data_ratchet_x3dh_sender_identity_private_key.bytes,
                    test_data_ratchet_x3dh_sender_ephemeral_private_key.bytes,
                    test_data_ratchet_x3dh_receiver_identity_public_key.bytes,
                    test_data_ratchet_x3dh_receiver_long_term_public_key.bytes, true,
                    test_data_ratchet_x3dh_receiver_one_time_public_key.bytes, shared_secret);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);
    TEST_ASSERT_EQUAL_DATA(test_data_ratchet_x3dh_shared_secret, vsc_data(shared_secret, sizeof(shared_secret)));
}

void
test__initiator_x3dh__fixed_keys_weak__should_match(void) {
    vscr_ratchet_symmetric_key_t shared_secret;

    vscr_status_t status =
            vscr_ratchet_x3dh_compute_initiator_x3dh_secret(test_data_ratchet_x3dh_sender_identity_private_key.bytes,
                    test_data_ratchet_x3dh_sender_ephemeral_private_key.bytes,
                    test_data_ratchet_x3dh_receiver_identity_public_key.bytes,
                    test_data_ratchet_x3dh_receiver_long_term_public_key.bytes, false, NULL, shared_secret);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);
    TEST_ASSERT_EQUAL_DATA(test_data_ratchet_x3dh_shared_secret_weak, vsc_data(shared_secret, sizeof(shared_secret)));
}

void
test__responder_x3dh__fixed_keys__should_match(void) {
    vscr_ratchet_symmetric_key_t shared_secret;

    vscr_status_t status =
            vscr_ratchet_x3dh_compute_responder_x3dh_secret(test_data_ratchet_x3dh_sender_identity_public_key.bytes,
                    test_data_ratchet_x3dh_sender_ephemeral_public_key.bytes,
                    test_data_ratchet_x3dh_receiver_identity_private_key.bytes,
                    test_data_ratchet_x3dh_receiver_long_term_private_key.bytes, true,
                    test_data_ratchet_x3dh_receiver_one_time_private_key.bytes, shared_secret);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);
    TEST_ASSERT_EQUAL_DATA(test_data_ratchet_x3dh_shared_secret, vsc_data(shared_secret, sizeof(shared_secret)));
}

void
test__responder_x3dh__fixed_keys_weak__should_match(void) {
    vscr_ratchet_symmetric_key_t shared_secret;

    vscr_status_t status =
            vscr_ratchet_x3dh_compute_responder_x3dh_secret(test_data_ratchet_x3dh_sender_identity_public_key.bytes,
                    test_data_ratchet_x3dh_sender_ephemeral_public_key.bytes,
                    test_data_ratchet_x3dh_receiver_identity_private_key.bytes,
                    test_data_ratchet_x3dh_receiver_long_term_private_key.bytes, false, NULL, shared_secret);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);
    TEST_ASSERT_EQUAL_DATA(test_data_ratchet_x3dh_shared_secret_weak, vsc_data(shared_secret, sizeof(shared_secret)));
}

void
test__x3dh__random_keys__should_match(void) {
    vscf_ctr_drbg_t *rng = vscf_ctr_drbg_new();
    TEST_ASSERT_EQUAL(vscf_status_SUCCESS, vscf_ctr_drbg_setup_defaults(rng));

    vsc_buffer_t *sender_identity_private_key, *sender_identity_public_key;
    vsc_buffer_t *sender_ephemeral_private_key, *sender_ephemeral_public_key;
    vsc_buffer_t *receiver_identity_private_key, *receiver_identity_public_key;
    vsc_buffer_t *receiver_long_term_private_key, *receiver_long_term_public_key;
    vsc_buffer_t *receiver_one_time_private_key, *receiver_one_time_public_key;

    generate_raw_keypair(rng, &sender_identity_private_key, &sender_identity_public_key, true);
    generate_raw_keypair(rng, &sender_ephemeral_private_key, &sender_ephemeral_public_key, true);
    generate_raw_keypair(rng, &receiver_identity_private_key, &receiver_identity_public_key, true);
    generate_raw_keypair(rng, &receiver_long_term_private_key, &receiver_long_term_public_key, true);
    generate_raw_keypair(rng, &receiver_one_time_private_key, &receiver_one_time_public_key, true);

    vscr_ratchet_symmetric_key_t shared_secret_sender;
    vscr_ratchet_symmetric_key_t shared_secret_receiver;

    vscr_status_t status = vscr_ratchet_x3dh_compute_responder_x3dh_secret(vsc_buffer_bytes(sender_identity_public_key),
            vsc_buffer_bytes(sender_ephemeral_public_key), vsc_buffer_bytes(receiver_identity_private_key),
            vsc_buffer_bytes(receiver_long_term_private_key), true, vsc_buffer_bytes(receiver_one_time_private_key),
            shared_secret_sender);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);

    status = vscr_ratchet_x3dh_compute_responder_x3dh_secret(vsc_buffer_bytes(sender_identity_public_key),
            vsc_buffer_bytes(sender_ephemeral_public_key), vsc_buffer_bytes(receiver_identity_private_key),
            vsc_buffer_bytes(receiver_long_term_private_key), true, vsc_buffer_bytes(receiver_one_time_private_key),
            shared_secret_receiver);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);

    TEST_ASSERT_EQUAL_DATA(vsc_data(shared_secret_sender, sizeof(shared_secret_sender)),
            vsc_data(shared_secret_receiver, sizeof(shared_secret_receiver)));

    vsc_buffer_destroy(&sender_identity_private_key);
    vsc_buffer_destroy(&sender_identity_public_key);
    vsc_buffer_destroy(&sender_ephemeral_private_key);
    vsc_buffer_destroy(&sender_ephemeral_public_key);
    vsc_buffer_destroy(&receiver_identity_private_key);
    vsc_buffer_destroy(&receiver_identity_public_key);
    vsc_buffer_destroy(&receiver_long_term_private_key);
    vsc_buffer_destroy(&receiver_long_term_public_key);
    vsc_buffer_destroy(&receiver_one_time_private_key);
    vsc_buffer_destroy(&receiver_one_time_public_key);

    vscf_ctr_drbg_destroy(&rng);
}

void
test__x3dh__random_keys_weak__should_match(void) {
    vscf_ctr_drbg_t *rng = vscf_ctr_drbg_new();
    TEST_ASSERT_EQUAL(vscf_status_SUCCESS, vscf_ctr_drbg_setup_defaults(rng));

    vsc_buffer_t *sender_identity_private_key, *sender_identity_public_key;
    vsc_buffer_t *sender_ephemeral_private_key, *sender_ephemeral_public_key;
    vsc_buffer_t *receiver_identity_private_key, *receiver_identity_public_key;
    vsc_buffer_t *receiver_long_term_private_key, *receiver_long_term_public_key;

    generate_raw_keypair(rng, &sender_identity_private_key, &sender_identity_public_key, true);
    generate_raw_keypair(rng, &sender_ephemeral_private_key, &sender_ephemeral_public_key, true);
    generate_raw_keypair(rng, &receiver_identity_private_key, &receiver_identity_public_key, true);
    generate_raw_keypair(rng, &receiver_long_term_private_key, &receiver_long_term_public_key, true);

    vscr_ratchet_symmetric_key_t shared_secret_sender;
    vscr_ratchet_symmetric_key_t shared_secret_receiver;

    vscr_status_t status = vscr_ratchet_x3dh_compute_responder_x3dh_secret(vsc_buffer_bytes(sender_identity_public_key),
            vsc_buffer_bytes(sender_ephemeral_public_key), vsc_buffer_bytes(receiver_identity_private_key),
            vsc_buffer_bytes(receiver_long_term_private_key), false, NULL, shared_secret_sender);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);

    status = vscr_ratchet_x3dh_compute_responder_x3dh_secret(vsc_buffer_bytes(sender_identity_public_key),
            vsc_buffer_bytes(sender_ephemeral_public_key), vsc_buffer_bytes(receiver_identity_private_key),
            vsc_buffer_bytes(receiver_long_term_private_key), false, NULL, shared_secret_receiver);

    TEST_ASSERT_EQUAL(vscr_status_SUCCESS, status);
    TEST_ASSERT_EQUAL_DATA(vsc_data(shared_secret_sender, sizeof(shared_secret_sender)),
            vsc_data(shared_secret_receiver, sizeof(shared_secret_receiver)));

    vsc_buffer_destroy(&sender_identity_private_key);
    vsc_buffer_destroy(&sender_identity_public_key);
    vsc_buffer_destroy(&sender_ephemeral_private_key);
    vsc_buffer_destroy(&sender_ephemeral_public_key);
    vsc_buffer_destroy(&receiver_identity_private_key);
    vsc_buffer_destroy(&receiver_identity_public_key);
    vsc_buffer_destroy(&receiver_long_term_private_key);
    vsc_buffer_destroy(&receiver_long_term_public_key);

    vscf_ctr_drbg_destroy(&rng);
}

#endif

// --------------------------------------------------------------------------
// Entrypoint.
// --------------------------------------------------------------------------
int
main(void) {
    UNITY_BEGIN();

#if TEST_DEPENDENCIES_AVAILABLE
    RUN_TEST(test__initiator_x3dh__fixed_keys__should_match);
    RUN_TEST(test__initiator_x3dh__fixed_keys_weak__should_match);
    RUN_TEST(test__responder_x3dh__fixed_keys__should_match);
    RUN_TEST(test__responder_x3dh__fixed_keys_weak__should_match);
    RUN_TEST(test__x3dh__random_keys__should_match);
    RUN_TEST(test__x3dh__random_keys_weak__should_match);
#else
    RUN_TEST(test__nothing__feature_disabled__must_be_ignored);
#endif

    return UNITY_END();
}
