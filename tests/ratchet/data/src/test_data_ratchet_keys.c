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
//  SERVICES = { LOSS OF USE, DATA, OR PROFITS = { OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>

#include <test_data_ratchet_keys.h>

const byte test_data_ratchet_keys_shared_secret_BYTES[] = {
        0xe1, 0xcc, 0x63, 0x4b, 0x3e, 0xc0, 0x5b, 0x11,
        0xb1, 0xae, 0x40, 0xa8, 0x1b, 0xad, 0xf6, 0xc7,
        0xe3, 0x1b, 0x18, 0x60, 0xa4, 0x36, 0x07, 0xba,
        0xff, 0x54, 0x5a, 0xe8, 0x14, 0x46, 0xb9, 0xa5,
        0x2e, 0x76, 0x68, 0xfc, 0x48, 0xac, 0x5e, 0x58,
        0xa4, 0xdc, 0xf9, 0xf8, 0x55, 0x84, 0x0b, 0x29,
        0x1e, 0xdc, 0xd4, 0x8e, 0xf3, 0x0b, 0x42, 0x50,
        0xd5, 0x36, 0x1b, 0xd8, 0xfe, 0x3a, 0x54, 0x49,
        0x30, 0xfe, 0xac, 0x08, 0xb0, 0xc2, 0x8d, 0x15,
        0x89, 0x0b, 0xf7, 0x21, 0xf6, 0x1d, 0x80, 0x3b,
        0xf9, 0xa3, 0x2c, 0xdf, 0x19, 0x5d, 0x21, 0x02,
        0x73, 0xf1, 0x8c, 0x1f, 0x12, 0x07, 0xcb, 0x63,
        0x7b, 0x23, 0x41, 0xca, 0xe1, 0x66, 0x69, 0xa4,
        0xcd, 0x41, 0x64, 0x4a, 0xbb, 0xc7, 0x75, 0x75,
        0x72, 0xf0, 0x07, 0x5a, 0x03, 0xb7, 0x50, 0x49,
        0x2f, 0x6a, 0x29, 0x79, 0x6d, 0x37, 0xd6, 0x97,
};

const byte test_data_ratchet_keys_root_key_BYTES[] = {
        0x5E, 0x62, 0x4E, 0xA8, 0x8F, 0xBF, 0x37, 0xB1,
        0xE1, 0x9D, 0x43, 0x6A, 0xA5, 0x44, 0xCF, 0x9E,
        0x91, 0x97, 0x15, 0xD8, 0x5D, 0xF6, 0x09, 0x9C,
        0x25, 0xCC, 0x12, 0xFD, 0x2B, 0x6C, 0x93, 0x8C,
};

const byte test_data_ratchet_keys_chain_key_BYTES[] = {
        0xF5, 0xF1, 0xC0, 0x64, 0xA1, 0xF3, 0x57, 0x54,
        0xC7, 0x45, 0x20, 0xDF, 0x9C, 0x56, 0x51, 0x3A,
        0x68, 0xC6, 0xDD, 0xD7, 0x8B, 0xB5, 0x15, 0xBD,
        0x6F, 0xDE, 0x79, 0xF4, 0xE2, 0x97, 0xE0, 0xDA,
};

const byte test_data_ratchet_keys_shared_secret_weak_BYTES[] = {
        0xdf, 0x78, 0xb1, 0x02, 0x58, 0x6d, 0x13, 0x9d,
        0x86, 0x48, 0x20, 0x8b, 0x26, 0x2d, 0x9d, 0x71,
        0x55, 0xd2, 0x6f, 0x87, 0x7e, 0x6b, 0xc1, 0xe3,
        0x67, 0x4c, 0x8b, 0xb9, 0x4c, 0x2e, 0xe2, 0xce,
        0xce, 0xbb, 0x74, 0x6c, 0x65, 0x64, 0x9b, 0x13,
        0x85, 0xdc, 0x59, 0x1b, 0x5d, 0xf0, 0xed, 0x8a,
        0x05, 0x43, 0x44, 0x23, 0x71, 0x31, 0xa8, 0xb5,
        0xfc, 0x1f, 0x79, 0x47, 0x47, 0x56, 0x5c, 0xd6,
        0x72, 0xe1, 0x35, 0x35, 0x2c, 0xbe, 0xa6, 0x11,
        0x90, 0x21, 0x68, 0x60, 0x09, 0xaa, 0x3f, 0x48,
        0xe8, 0xc1, 0x29, 0x50, 0xd9, 0x3c, 0x14, 0x8f,
        0x33, 0x26, 0x0b, 0xd1, 0x28, 0x62, 0x10, 0x7e,
};

const byte test_data_ratchet_keys_root_key_weak_BYTES[] = {
        0xB8, 0x8F, 0xE4, 0x4B, 0xF9, 0x32, 0xC0, 0xCB,
        0xCF, 0x9E, 0xFF, 0x97, 0x78, 0xD2, 0x3D, 0x6A,
        0x48, 0x89, 0x5C, 0x60, 0xA3, 0xA3, 0x63, 0x02,
        0x93, 0xDB, 0x19, 0xE1, 0x38, 0x03, 0x22, 0xB2,
};

const byte test_data_ratchet_keys_chain_key_weak_BYTES[] = {
        0x9A, 0x3D, 0x68, 0x67, 0x4E, 0x18, 0xAC, 0x4C,
        0xAF, 0xCD, 0xB4, 0xEC, 0xBC, 0xC3, 0x1A, 0x96,
        0x91, 0xFF, 0x41, 0x2D, 0x13, 0x84, 0xB3, 0x0D,
        0xA0, 0x8B, 0x67, 0x4C, 0x17, 0xA9, 0x4A, 0x73,
};

const byte test_data_ratchet_keys_private_key_BYTES[] = {
        0x25, 0x50, 0x5E, 0x5B, 0x59, 0xF6, 0x9D, 0x12,
        0x16, 0x87, 0x17, 0xFC, 0x1F, 0xD4, 0x2E, 0x4A,
        0x0B, 0xD5, 0xF7, 0x63, 0xF8, 0xB8, 0x84, 0x2C,
        0x34, 0xC8, 0x53, 0xAB, 0x93, 0xA9, 0xDB, 0x73,
};

const byte test_data_ratchet_keys_public_BYTES[] = {
        0xA0, 0xF7, 0x55, 0x9B, 0x06, 0x9D, 0x82, 0x91,
        0xB7, 0x2C, 0x96, 0x30, 0xE3, 0x35, 0xE7, 0xB3,
        0x48, 0x82, 0xC4, 0x1F, 0x67, 0xA1, 0xFD, 0xAC,
        0x5F, 0xAB, 0x6A, 0xC3, 0x1C, 0x3F, 0x2B, 0x08,
};

const byte test_data_ratchet_keys_new_root_key_BYTES[] = {
        0x4C, 0x87, 0xB5, 0xD2, 0x0F, 0x21, 0x75, 0x6B,
        0xF7, 0x42, 0x45, 0x23, 0x98, 0x5C, 0x70, 0x00,
        0x41, 0x97, 0xD0, 0xDB, 0x4F, 0x8B, 0xFE, 0x33,
        0xB8, 0x8E, 0xAE, 0x4A, 0x28, 0x33, 0x3F, 0x51,
};

const byte test_data_ratchet_keys_new_chain_key_BYTES[] = {
        0x97, 0x5E, 0x93, 0x12, 0x41, 0x4B, 0x57, 0xE9,
        0xEB, 0x8E, 0x44, 0xD1, 0x6B, 0xCD, 0xB3, 0xDD,
        0x5F, 0xDD, 0x32, 0x28, 0xF4, 0x59, 0x99, 0xF3,
        0x3D, 0x45, 0x7E, 0xC5, 0x31, 0xF9, 0xD3, 0xD9,
};

const byte test_data_ratchet_keys_message_key_BYTES[] = {
        0x49, 0x3A, 0xF1, 0x12, 0x22, 0x66, 0x34, 0x51,
        0xDC, 0x98, 0xDB, 0x40, 0xB5, 0xE7, 0x1C, 0x02,
        0x02, 0x5C, 0xB3, 0xD7, 0x10, 0x09, 0x6D, 0xEE,
        0x3E, 0x8F, 0x72, 0xE3, 0x2B, 0xA0, 0x2C, 0xAC,
};

const uint32_t test_data_ratchet_keys_message_key_index = 42;

const uint32_t test_data_ratchet_keys_chain_key_index = 19;

const byte test_data_ratchet_keys_next_chain_key_BYTES[] = {
        0xAE, 0xB8, 0x07, 0xA4, 0xD8, 0xC9, 0x3A, 0x8E,
        0x19, 0xAF, 0x10, 0x9F, 0x98, 0xE9, 0xB0, 0x2D,
        0xFD, 0xEE, 0xD7, 0xC8, 0x25, 0x02, 0x13, 0x01,
        0x64, 0x8F, 0xDB, 0x6F, 0x31, 0x30, 0x60, 0x9D,
};

const byte test_data_ratchet_keys_next_chain_key2_BYTES[] = {
        0x69, 0xBD, 0xCB, 0x42, 0x44, 0x2B, 0xB2, 0x26,
        0xBF, 0x92, 0xF9, 0xFF, 0xB2, 0x14, 0xCD, 0x05,
        0x12, 0x65, 0xC0, 0x57, 0x48, 0x54, 0xC3, 0x2A,
        0x8D, 0xCF, 0xCD, 0x64, 0x25, 0xB2, 0xC5, 0x38,
};

const vsc_data_t test_data_ratchet_keys_shared_secret = {
        test_data_ratchet_keys_shared_secret_BYTES, sizeof(test_data_ratchet_keys_shared_secret_BYTES)
};

const vsc_data_t test_data_ratchet_keys_root_key = {
        test_data_ratchet_keys_root_key_BYTES, sizeof(test_data_ratchet_keys_root_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_chain_key = {
        test_data_ratchet_keys_chain_key_BYTES, sizeof(test_data_ratchet_keys_chain_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_shared_secret_weak = {
        test_data_ratchet_keys_shared_secret_weak_BYTES, sizeof(test_data_ratchet_keys_shared_secret_weak_BYTES)
};

const vsc_data_t test_data_ratchet_keys_root_key_weak = {
        test_data_ratchet_keys_root_key_weak_BYTES, sizeof(test_data_ratchet_keys_root_key_weak_BYTES)
};

const vsc_data_t test_data_ratchet_keys_chain_key_weak = {
        test_data_ratchet_keys_chain_key_weak_BYTES, sizeof(test_data_ratchet_keys_chain_key_weak_BYTES)
};

const vsc_data_t test_data_ratchet_keys_private_key = {
        test_data_ratchet_keys_private_key_BYTES, sizeof(test_data_ratchet_keys_private_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_public = {
        test_data_ratchet_keys_public_BYTES, sizeof(test_data_ratchet_keys_public_BYTES)
};

const vsc_data_t test_data_ratchet_keys_new_root_key = {
        test_data_ratchet_keys_new_root_key_BYTES, sizeof(test_data_ratchet_keys_new_root_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_new_chain_key = {
        test_data_ratchet_keys_new_chain_key_BYTES, sizeof(test_data_ratchet_keys_new_chain_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_message_key = {
        test_data_ratchet_keys_message_key_BYTES, sizeof(test_data_ratchet_keys_message_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_next_chain_key = {
        test_data_ratchet_keys_next_chain_key_BYTES, sizeof(test_data_ratchet_keys_next_chain_key_BYTES)
};

const vsc_data_t test_data_ratchet_keys_next_chain_key2 = {
        test_data_ratchet_keys_next_chain_key2_BYTES, sizeof(test_data_ratchet_keys_next_chain_key2_BYTES)
};