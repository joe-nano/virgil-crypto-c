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
//  SERVICES_BYTES[] = { LOSS OF USE, DATA, OR PROFITS_BYTES[] = { OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
//  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//
//  Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>

#include <test_data_ratchet_message.h>

const byte test_data_ratchet_message_raw_key1_BYTES[] = {
        0xb3, 0x8e, 0x3e, 0xd3, 0xb1, 0xf5, 0x65, 0xfb,
        0x80, 0xb9, 0x88, 0xff, 0x14, 0x62, 0xcd, 0xc5,
        0x7a, 0x0c, 0xe3, 0xcb, 0xb5, 0xbd, 0x94, 0xd6,
        0xb3, 0x35, 0x4f, 0x9d, 0x9c, 0x35, 0x04, 0x8f,
};

const byte test_data_ratchet_message_raw_key2_BYTES[] = {
        0xef, 0x1b, 0xda, 0xe8, 0xcb, 0xf1, 0x35, 0x9a,
        0x98, 0xda, 0xd6, 0x1d, 0x67, 0x86, 0xe7, 0x5b,
        0x2e, 0x25, 0x26, 0x57, 0x6e, 0x33, 0x4a, 0x9b,
        0x65, 0xcc, 0x0b, 0xf9, 0x0c, 0xf7, 0xc4, 0x58,
};

const byte test_data_ratchet_message_raw_key3_BYTES[] = {
        0xb0, 0x09, 0x69, 0x04, 0x02, 0xff, 0x7c, 0x0b,
        0x2b, 0x2a, 0x7d, 0x88, 0x6b, 0xa3, 0xa5, 0x84,
        0x01, 0x76, 0xf2, 0x65, 0x18, 0x16, 0x2a, 0xa3,
        0xbf, 0x06, 0xa4, 0x0f, 0x19, 0x82, 0xaa, 0x8b,
};

const byte test_data_ratchet_message_raw_key4_BYTES[] = {
        0x4e, 0x4e, 0xe5, 0x01, 0xb8, 0x11, 0xc2, 0x08,
        0xf0, 0xaf, 0xd7, 0x76, 0xd1, 0xf2, 0xd9, 0xff,
        0xef, 0x57, 0x57, 0x1d, 0x0e, 0xda, 0x40, 0xd9,
        0x7f, 0xb6, 0xf4, 0x26, 0xfd, 0x88, 0xe1, 0x8b,
};

const byte test_data_ratchet_message_raw_key5_BYTES[] = {
        0x8c, 0xeb, 0x9b, 0x82, 0xa0, 0x21, 0x4e, 0x77,
        0x9a, 0xba, 0x3a, 0x89, 0x9f, 0xd0, 0x22, 0xe2,
        0xa7, 0x9d, 0x46, 0xce, 0x09, 0x90, 0x43, 0x6e,
        0x4e, 0xbd, 0xa7, 0x30, 0x5a, 0xf6, 0xa2, 0x10,
};

const byte test_data_ratchet_message_data_BYTES[] = {
        0xcc, 0x48, 0x49, 0x7e, 0x21, 0xf1, 0xb0, 0x2a,
        0x03, 0x25, 0x56, 0x39, 0xa0, 0x6d, 0xf3, 0x27,
        0x23, 0xe0, 0x27, 0xf1, 0x1d, 0xad, 0xc9, 0x13,
        0xd7, 0x5b, 0x69, 0x2d, 0x80, 0xb3, 0xa4, 0xe8,
        0x2c, 0x3e, 0xe0, 0xe8, 0xad, 0x8b, 0x77, 0x9c,
        0x7f, 0xfa, 0x77, 0x1a, 0xaf, 0x9b, 0xcd, 0x90,
        0x53, 0xdd, 0xf9, 0xad, 0xce, 0x89, 0xe1, 0x53,
        0xca, 0x71, 0x40, 0x6d, 0x6a, 0x7b, 0xba, 0x51,
        0x8f, 0x99, 0xbc, 0xc5, 0x85, 0x0b, 0x6a, 0x92,
        0xb1, 0x04, 0xa6, 0x1b, 0x4f, 0x8a, 0x78, 0x80,
        0xb5, 0xa5, 0x45, 0xbc, 0xe0, 0x1f, 0xce, 0xda,
        0x46, 0x78, 0xa8, 0x70, 0x81, 0xc2, 0x7e, 0xe5,
        0x63, 0x53, 0xb9, 0x62, 0x0f, 0x00, 0x5d, 0x4a,
        0x03, 0x46, 0x17, 0xeb, 0xa6, 0x7e, 0x5e, 0xe2,
        0x4c, 0x80, 0x2a, 0x75, 0x09, 0x0b, 0xf1, 0x90,
        0xcc, 0x12, 0x71, 0x95, 0xb7, 0xd5, 0x9c, 0xa9,
};

const vsc_data_t test_data_ratchet_message_raw_key1 = {
        test_data_ratchet_message_raw_key1_BYTES, sizeof(test_data_ratchet_message_raw_key1_BYTES)
};

const vsc_data_t test_data_ratchet_message_raw_key2 = {
        test_data_ratchet_message_raw_key2_BYTES, sizeof(test_data_ratchet_message_raw_key2_BYTES)
};

const vsc_data_t test_data_ratchet_message_raw_key3 = {
        test_data_ratchet_message_raw_key3_BYTES, sizeof(test_data_ratchet_message_raw_key3_BYTES)
};

const vsc_data_t test_data_ratchet_message_raw_key4 = {
        test_data_ratchet_message_raw_key4_BYTES, sizeof(test_data_ratchet_message_raw_key4_BYTES)
};

const vsc_data_t test_data_ratchet_message_raw_key5 = {
        test_data_ratchet_message_raw_key5_BYTES, sizeof(test_data_ratchet_message_raw_key5_BYTES)
};

const vsc_data_t test_data_ratchet_message_data = {
        test_data_ratchet_message_data_BYTES, sizeof(test_data_ratchet_message_data_BYTES)
};
