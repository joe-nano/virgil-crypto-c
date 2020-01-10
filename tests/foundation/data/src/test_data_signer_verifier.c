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


#include "test_data_signer_verifier.h"


static const byte DATA_BYTES[] = {
    0x4d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20,
    0x74, 0x6f, 0x20, 0x62, 0x65, 0x20, 0x73, 0x69,
    0x67, 0x6e, 0x65, 0x64, 0x21
};

const vsc_data_t test_signer_DATA = {
    DATA_BYTES, sizeof(DATA_BYTES)
};


static const byte ED25519_PUBLIC_KEY_PKCS8_BYTES[] = {
    0x30, 0x2A, 0x30, 0x05, 0x06, 0x03, 0x2B, 0x65,
    0x70, 0x03, 0x21, 0x00, 0x86, 0x61, 0x40, 0x74,
    0xB7, 0xA5, 0xD1, 0x13, 0x04, 0x48, 0xBE, 0x69,
    0xA4, 0xA2, 0x5C, 0xE5, 0x8D, 0xBF, 0x76, 0x0A,
    0x87, 0xBB, 0xF9, 0x2A, 0x03, 0xAD, 0xD9, 0x73,
    0xF3, 0x8E, 0xCE, 0x7C
};

const vsc_data_t test_signer_ED25519_PUBLIC_KEY_PKCS8 = {
    ED25519_PUBLIC_KEY_PKCS8_BYTES, sizeof(ED25519_PUBLIC_KEY_PKCS8_BYTES)
};

static const byte ED25519_PRIVATE_KEY_PKCS8_BYTES[] = {
    0x30, 0x2E, 0x02, 0x01, 0x00, 0x30, 0x05, 0x06,
    0x03, 0x2B, 0x65, 0x70, 0x04, 0x22, 0x04, 0x20,
    0x10, 0xDA, 0x87, 0x56, 0x6B, 0x44, 0x6E, 0xDB,
    0x74, 0xAF, 0xA6, 0xEB, 0x67, 0x54, 0x77, 0x43,
    0x67, 0x08, 0x1E, 0xFA, 0x5F, 0xCD, 0x39, 0xC1,
    0x9E, 0x64, 0xA3, 0x68, 0x30, 0x44, 0x5B, 0x1B
};

const vsc_data_t test_signer_ED25519_PRIVATE_KEY_PKCS8 = {
    ED25519_PRIVATE_KEY_PKCS8_BYTES, sizeof(ED25519_PRIVATE_KEY_PKCS8_BYTES)
};

static const byte ED25519_SHA384_SIGNATURE_BYTES[] = {
    0x30, 0x4F, 0x30, 0x0B, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02, 0x04,
    0x40, 0x31, 0x29, 0x1C, 0x2F, 0x09, 0xD1, 0xCC,
    0xC7, 0xEF, 0x0B, 0x27, 0x2C, 0x31, 0x31, 0x67,
    0x7D, 0xEC, 0x18, 0x7B, 0xD5, 0x61, 0x01, 0x95,
    0x36, 0x41, 0x57, 0x2F, 0xB8, 0x28, 0xC3, 0x8E,
    0xE1, 0x93, 0xA2, 0x32, 0xFC, 0x0C, 0x05, 0x91,
    0xE0, 0x7C, 0x09, 0x5F, 0xD3, 0x7A, 0xFB, 0x9A,
    0x7A, 0x96, 0x2E, 0x3E, 0xFC, 0x79, 0xFC, 0x25,
    0xBA, 0x83, 0xFE, 0x66, 0x46, 0xF9, 0xD7, 0xED,
    0x0C
};

const vsc_data_t test_signer_ED25519_SHA384_SIGNATURE = {
    ED25519_SHA384_SIGNATURE_BYTES, sizeof(ED25519_SHA384_SIGNATURE_BYTES)
};

static const byte ED25519_SHA384_SIGNATURE_V2_COMPAT_BYTES[] = {
    0x30, 0x51, 0x30, 0x0D, 0x06, 0x09, 0x60, 0x86,
    0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02, 0x05,
    0x00, 0x04, 0x40, 0x31, 0x29, 0x1C, 0x2F, 0x09,
    0xD1, 0xCC, 0xC7, 0xEF, 0x0B, 0x27, 0x2C, 0x31,
    0x31, 0x67, 0x7D, 0xEC, 0x18, 0x7B, 0xD5, 0x61,
    0x01, 0x95, 0x36, 0x41, 0x57, 0x2F, 0xB8, 0x28,
    0xC3, 0x8E, 0xE1, 0x93, 0xA2, 0x32, 0xFC, 0x0C,
    0x05, 0x91, 0xE0, 0x7C, 0x09, 0x5F, 0xD3, 0x7A,
    0xFB, 0x9A, 0x7A, 0x96, 0x2E, 0x3E, 0xFC, 0x79,
    0xFC, 0x25, 0xBA, 0x83, 0xFE, 0x66, 0x46, 0xF9,
    0xD7, 0xED, 0x0C
};

const vsc_data_t test_signer_ED25519_SHA384_SIGNATURE_V2_COMPAT = {
    ED25519_SHA384_SIGNATURE_V2_COMPAT_BYTES, sizeof(ED25519_SHA384_SIGNATURE_V2_COMPAT_BYTES)
};


static const byte RSA2048_PUBLIC_KEY_PKCS8_BYTES[] = {
    0x30, 0x82, 0x01, 0x21, 0x30, 0x0d, 0x06, 0x09,
    0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
    0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0e, 0x00,
    0x30, 0x82, 0x01, 0x09, 0x02, 0x82, 0x01, 0x00,
    0x53, 0x7c, 0xc7, 0xe8, 0xfb, 0x4b, 0x09, 0x75,
    0x73, 0x9f, 0x3f, 0xf6, 0x13, 0xd0, 0x1a, 0x98,
    0xd5, 0x03, 0x9e, 0xb8, 0x59, 0xc0, 0xfd, 0x8b,
    0x01, 0xdf, 0x72, 0xa6, 0x36, 0x73, 0xef, 0xad,
    0x12, 0x1c, 0x33, 0x74, 0x6f, 0x2a, 0x1c, 0x1b,
    0xe4, 0x39, 0x99, 0xcf, 0xc5, 0x45, 0xfa, 0xb8,
    0x97, 0x56, 0x91, 0x31, 0xae, 0x7e, 0xb7, 0x60,
    0x13, 0xe8, 0x7a, 0xc3, 0x27, 0x07, 0xa9, 0xc9,
    0x10, 0xf1, 0x3a, 0xa7, 0x98, 0xcf, 0xa0, 0x5e,
    0x78, 0x71, 0x1b, 0x71, 0x6b, 0xb5, 0xc8, 0xf3,
    0xa7, 0x0b, 0xad, 0xd3, 0x7e, 0x93, 0x75, 0xac,
    0xf7, 0x52, 0xc1, 0xd0, 0x96, 0xa9, 0xef, 0xba,
    0xed, 0x84, 0x84, 0x72, 0x1e, 0x9e, 0xbb, 0x08,
    0x65, 0xfd, 0x0c, 0x55, 0x47, 0x09, 0x46, 0x17,
    0xd7, 0x13, 0xf8, 0x6f, 0x92, 0xa3, 0x2f, 0x43,
    0xd6, 0xfd, 0x3b, 0x52, 0xd5, 0x85, 0x5c, 0x73,
    0x84, 0x50, 0x4a, 0xad, 0x7f, 0xdf, 0x95, 0xce,
    0xff, 0xef, 0x80, 0x6a, 0xed, 0x6b, 0x75, 0xeb,
    0xd6, 0x50, 0xb7, 0x33, 0xee, 0xee, 0xea, 0x53,
    0x47, 0x9e, 0xf3, 0x8f, 0x59, 0xc5, 0xf6, 0x82,
    0x90, 0x72, 0x4a, 0x62, 0xed, 0xd0, 0x13, 0xdb,
    0xb6, 0xee, 0xa5, 0x66, 0xfd, 0x5c, 0xb4, 0x4e,
    0x7a, 0xcd, 0xc0, 0x27, 0xe4, 0x8f, 0x7d, 0xb6,
    0x20, 0xde, 0x7e, 0xca, 0xb1, 0x87, 0xc3, 0x14,
    0x98, 0x7b, 0xad, 0xe4, 0xcb, 0xe1, 0xd1, 0x9d,
    0xd4, 0x3b, 0x0c, 0x86, 0xef, 0xf9, 0x00, 0xeb,
    0x4e, 0xe1, 0xf7, 0x93, 0xe8, 0xd0, 0x33, 0xd9,
    0x45, 0x9b, 0x14, 0x6a, 0xaf, 0xf9, 0x97, 0x1d,
    0xc1, 0xc7, 0x27, 0x40, 0x8e, 0x97, 0x22, 0xa9,
    0x1d, 0x27, 0xae, 0x3b, 0xb3, 0x15, 0x1e, 0x97,
    0xae, 0xc7, 0xf3, 0x60, 0x56, 0x22, 0xa0, 0xe3,
    0x8b, 0x8b, 0xb4, 0xea, 0x46, 0xe6, 0x10, 0xeb,
    0x02, 0x03, 0x01, 0x00, 0x01
};

const vsc_data_t test_signer_RSA2048_PUBLIC_KEY_PKCS8 = {
    RSA2048_PUBLIC_KEY_PKCS8_BYTES, sizeof(RSA2048_PUBLIC_KEY_PKCS8_BYTES)
};

static const byte RSA2048_PRIVATE_KEY_PKCS8_BYTES[] = {
    0x30, 0x82, 0x04, 0xbc, 0x02, 0x01, 0x00, 0x30,
    0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
    0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04, 0x82,
    0x04, 0xa6, 0x30, 0x82, 0x04, 0xa2, 0x02, 0x01,
    0x00, 0x02, 0x82, 0x01, 0x00, 0x53, 0x7c, 0xc7,
    0xe8, 0xfb, 0x4b, 0x09, 0x75, 0x73, 0x9f, 0x3f,
    0xf6, 0x13, 0xd0, 0x1a, 0x98, 0xd5, 0x03, 0x9e,
    0xb8, 0x59, 0xc0, 0xfd, 0x8b, 0x01, 0xdf, 0x72,
    0xa6, 0x36, 0x73, 0xef, 0xad, 0x12, 0x1c, 0x33,
    0x74, 0x6f, 0x2a, 0x1c, 0x1b, 0xe4, 0x39, 0x99,
    0xcf, 0xc5, 0x45, 0xfa, 0xb8, 0x97, 0x56, 0x91,
    0x31, 0xae, 0x7e, 0xb7, 0x60, 0x13, 0xe8, 0x7a,
    0xc3, 0x27, 0x07, 0xa9, 0xc9, 0x10, 0xf1, 0x3a,
    0xa7, 0x98, 0xcf, 0xa0, 0x5e, 0x78, 0x71, 0x1b,
    0x71, 0x6b, 0xb5, 0xc8, 0xf3, 0xa7, 0x0b, 0xad,
    0xd3, 0x7e, 0x93, 0x75, 0xac, 0xf7, 0x52, 0xc1,
    0xd0, 0x96, 0xa9, 0xef, 0xba, 0xed, 0x84, 0x84,
    0x72, 0x1e, 0x9e, 0xbb, 0x08, 0x65, 0xfd, 0x0c,
    0x55, 0x47, 0x09, 0x46, 0x17, 0xd7, 0x13, 0xf8,
    0x6f, 0x92, 0xa3, 0x2f, 0x43, 0xd6, 0xfd, 0x3b,
    0x52, 0xd5, 0x85, 0x5c, 0x73, 0x84, 0x50, 0x4a,
    0xad, 0x7f, 0xdf, 0x95, 0xce, 0xff, 0xef, 0x80,
    0x6a, 0xed, 0x6b, 0x75, 0xeb, 0xd6, 0x50, 0xb7,
    0x33, 0xee, 0xee, 0xea, 0x53, 0x47, 0x9e, 0xf3,
    0x8f, 0x59, 0xc5, 0xf6, 0x82, 0x90, 0x72, 0x4a,
    0x62, 0xed, 0xd0, 0x13, 0xdb, 0xb6, 0xee, 0xa5,
    0x66, 0xfd, 0x5c, 0xb4, 0x4e, 0x7a, 0xcd, 0xc0,
    0x27, 0xe4, 0x8f, 0x7d, 0xb6, 0x20, 0xde, 0x7e,
    0xca, 0xb1, 0x87, 0xc3, 0x14, 0x98, 0x7b, 0xad,
    0xe4, 0xcb, 0xe1, 0xd1, 0x9d, 0xd4, 0x3b, 0x0c,
    0x86, 0xef, 0xf9, 0x00, 0xeb, 0x4e, 0xe1, 0xf7,
    0x93, 0xe8, 0xd0, 0x33, 0xd9, 0x45, 0x9b, 0x14,
    0x6a, 0xaf, 0xf9, 0x97, 0x1d, 0xc1, 0xc7, 0x27,
    0x40, 0x8e, 0x97, 0x22, 0xa9, 0x1d, 0x27, 0xae,
    0x3b, 0xb3, 0x15, 0x1e, 0x97, 0xae, 0xc7, 0xf3,
    0x60, 0x56, 0x22, 0xa0, 0xe3, 0x8b, 0x8b, 0xb4,
    0xea, 0x46, 0xe6, 0x10, 0xeb, 0x02, 0x03, 0x01,
    0x00, 0x01, 0x02, 0x82, 0x01, 0x00, 0x48, 0xa0,
    0xa0, 0x77, 0xf9, 0x43, 0xc9, 0xb2, 0xb7, 0x26,
    0xae, 0x49, 0xaf, 0xea, 0xb5, 0x78, 0x86, 0xb6,
    0x63, 0x79, 0x13, 0xfb, 0x63, 0x95, 0x6d, 0xc7,
    0xa8, 0xc1, 0x17, 0x55, 0xbc, 0x06, 0xdf, 0x5e,
    0x51, 0x14, 0xd5, 0x2f, 0xd8, 0xcc, 0x1a, 0xba,
    0x51, 0x28, 0x02, 0x01, 0x62, 0x9e, 0xfa, 0x68,
    0x80, 0x5e, 0xab, 0xe1, 0xe8, 0x3c, 0x58, 0x95,
    0x41, 0x56, 0x4b, 0xb9, 0xca, 0xe5, 0xf3, 0x2b,
    0x27, 0x4f, 0x6d, 0x0c, 0x12, 0x02, 0x9c, 0xdc,
    0x28, 0x77, 0x7e, 0xaf, 0xe1, 0x64, 0xb4, 0xc8,
    0xe0, 0x2a, 0xc0, 0x4e, 0x1f, 0x6c, 0x9c, 0xab,
    0x0d, 0x98, 0x1b, 0xb9, 0x31, 0xa7, 0x77, 0xc0,
    0x74, 0x47, 0xa2, 0x83, 0x8b, 0x49, 0x3f, 0x0f,
    0xe7, 0x8e, 0xb8, 0x01, 0x45, 0x4c, 0xaf, 0xf9,
    0xdb, 0x81, 0x94, 0x1b, 0x09, 0x9f, 0x06, 0x83,
    0xbc, 0xfb, 0xce, 0x6b, 0xf9, 0x84, 0x34, 0x7f,
    0xc0, 0xf3, 0xb6, 0x93, 0xa4, 0xa3, 0x55, 0x68,
    0x7f, 0xd4, 0x64, 0xaa, 0x72, 0x89, 0xd3, 0x4c,
    0x5b, 0x86, 0x68, 0x95, 0xdd, 0x41, 0xaa, 0xbb,
    0x54, 0xd0, 0xb3, 0x40, 0x74, 0x75, 0x67, 0x46,
    0x9c, 0xea, 0xa3, 0x6f, 0x39, 0x20, 0xdf, 0x1c,
    0x39, 0x3c, 0x9b, 0x8f, 0xca, 0x82, 0x4e, 0x2b,
    0xe7, 0x41, 0xa0, 0x94, 0xd7, 0x92, 0x25, 0x9d,
    0x5c, 0xb7, 0x1a, 0x98, 0x1e, 0xed, 0x71, 0x27,
    0x18, 0x1e, 0x61, 0xb9, 0x14, 0x7f, 0x25, 0x73,
    0x98, 0x2d, 0x7a, 0x31, 0xc7, 0x05, 0xb0, 0x89,
    0xc3, 0x88, 0x1d, 0xd2, 0x85, 0xab, 0x0e, 0x8d,
    0xc7, 0x75, 0x24, 0x9c, 0xe3, 0xaf, 0xcc, 0xc1,
    0x9c, 0xe1, 0xfb, 0xa4, 0x67, 0x6b, 0x84, 0xdd,
    0x79, 0x05, 0x7a, 0xa2, 0xb0, 0xe8, 0x72, 0xa5,
    0xee, 0xc9, 0x83, 0x57, 0xe3, 0x1b, 0x0b, 0x58,
    0xdc, 0xcb, 0xf6, 0x01, 0xd2, 0x21, 0x02, 0x81,
    0x81, 0x00, 0xa3, 0x79, 0xb8, 0xfd, 0xb3, 0x1d,
    0x79, 0x53, 0x25, 0x61, 0x3b, 0x14, 0x72, 0x2c,
    0x91, 0xc2, 0xdf, 0x5b, 0x4b, 0x1d, 0x79, 0x68,
    0xfa, 0x18, 0x03, 0xdc, 0x57, 0x44, 0x93, 0xf0,
    0x72, 0x7a, 0xfe, 0xa8, 0x2a, 0x1a, 0x83, 0x76,
    0x35, 0x32, 0xb4, 0xa4, 0x48, 0x49, 0x71, 0xd7,
    0x89, 0x8a, 0x17, 0x9b, 0xaf, 0xf9, 0x21, 0x99,
    0x6c, 0x74, 0xdd, 0x92, 0x0b, 0x5a, 0x01, 0x19,
    0x57, 0x45, 0x1c, 0x3c, 0x5e, 0xe0, 0x17, 0x8a,
    0x0e, 0x5b, 0x56, 0x73, 0xc5, 0x6d, 0x56, 0x0e,
    0xc5, 0x4f, 0xcb, 0x1e, 0x18, 0xd6, 0xa8, 0xbd,
    0x0b, 0x12, 0x15, 0xf0, 0x20, 0xcb, 0x1d, 0xef,
    0x12, 0xdb, 0x03, 0x25, 0xf9, 0x33, 0x7f, 0x40,
    0x39, 0xa7, 0x9f, 0xca, 0xae, 0x33, 0x5e, 0x06,
    0x94, 0x23, 0x67, 0x5a, 0x00, 0x0f, 0x1f, 0x73,
    0x37, 0xfc, 0x86, 0x1f, 0x0a, 0x24, 0x63, 0x55,
    0xa0, 0xdd, 0x02, 0x81, 0x81, 0x00, 0x82, 0xbd,
    0x6f, 0x58, 0xf1, 0x21, 0xe6, 0xc8, 0xdc, 0xa3,
    0xd6, 0x2c, 0x20, 0x79, 0xae, 0x7d, 0xad, 0xd8,
    0xd9, 0xf1, 0x8c, 0x67, 0x8a, 0x36, 0xe1, 0xd9,
    0x7e, 0xba, 0x58, 0xd7, 0x39, 0x2d, 0x5c, 0x64,
    0x1b, 0x23, 0xef, 0x4f, 0x17, 0x2e, 0xf6, 0x45,
    0x02, 0x7f, 0x6d, 0xf8, 0xea, 0xd0, 0xeb, 0xda,
    0x15, 0x4b, 0x72, 0x3b, 0x98, 0x21, 0x2d, 0xd1,
    0xbf, 0x7c, 0x4b, 0x90, 0xaa, 0x8a, 0xad, 0x06,
    0xfe, 0xab, 0xee, 0xaa, 0x3f, 0x8c, 0xbb, 0xe0,
    0x2e, 0xb8, 0xd0, 0xe5, 0xb8, 0x19, 0x35, 0x6b,
    0xce, 0x6c, 0x0f, 0x55, 0x9e, 0x25, 0x9f, 0xf4,
    0xff, 0x11, 0xc4, 0x5b, 0xea, 0x46, 0xdf, 0xab,
    0xf7, 0x98, 0x3d, 0x05, 0x9a, 0xb6, 0xae, 0x28,
    0xc2, 0xbc, 0x64, 0xe5, 0xd3, 0x33, 0x5e, 0x96,
    0xb2, 0xa4, 0x46, 0x37, 0x1c, 0xf3, 0x19, 0x17,
    0xa3, 0x70, 0xf0, 0x2a, 0x38, 0x67, 0x02, 0x81,
    0x80, 0x70, 0x21, 0x79, 0x13, 0x83, 0xfd, 0xae,
    0x8f, 0xaa, 0xaf, 0x23, 0xd0, 0x25, 0x74, 0x8e,
    0xd2, 0xc5, 0x54, 0x20, 0x94, 0xea, 0x07, 0x68,
    0xac, 0x7a, 0x51, 0x74, 0x06, 0x95, 0x17, 0x33,
    0xdf, 0x4b, 0xb7, 0xdb, 0x91, 0x6e, 0x24, 0xf1,
    0xde, 0x82, 0xeb, 0xc0, 0xad, 0xa8, 0x09, 0xb8,
    0xcc, 0xe0, 0xde, 0xa8, 0x78, 0xd1, 0x64, 0x24,
    0x71, 0x90, 0xdd, 0xb1, 0x2d, 0x9e, 0x5d, 0x5c,
    0x70, 0x0a, 0x2b, 0x1a, 0xc4, 0xc9, 0x40, 0xa8,
    0x12, 0x5c, 0x9d, 0x72, 0x89, 0x49, 0xa3, 0x3e,
    0x12, 0x3a, 0x77, 0xbd, 0x7f, 0xd8, 0x24, 0x3b,
    0x68, 0xbf, 0x65, 0x83, 0x88, 0xef, 0x52, 0x62,
    0x73, 0x99, 0x98, 0x3d, 0x73, 0xe6, 0x50, 0x0e,
    0x7b, 0xfc, 0xee, 0x10, 0x49, 0x29, 0xb0, 0x87,
    0x82, 0x35, 0x4d, 0x15, 0x87, 0x4a, 0x02, 0x45,
    0x1f, 0xd0, 0x7b, 0x90, 0x00, 0x5f, 0xa6, 0x87,
    0x7d, 0x02, 0x81, 0x80, 0x4a, 0x9f, 0x93, 0xd1,
    0xa1, 0x78, 0xe7, 0x40, 0x98, 0xe7, 0x8f, 0x14,
    0x8a, 0xc8, 0xc9, 0x77, 0x04, 0xe6, 0xb4, 0xa7,
    0x71, 0xab, 0x9b, 0xb1, 0x6d, 0xc1, 0xf5, 0xda,
    0xa9, 0x60, 0xd7, 0x4a, 0xf3, 0xe4, 0x53, 0xb5,
    0x74, 0x1f, 0xa1, 0xac, 0xf5, 0x76, 0x38, 0x51,
    0xc1, 0xd4, 0x85, 0x3b, 0x10, 0x93, 0xde, 0xf9,
    0xbc, 0x4f, 0x15, 0xab, 0x42, 0x7a, 0xe9, 0x20,
    0x2a, 0x05, 0x7d, 0xc2, 0x3f, 0xb6, 0xb1, 0x60,
    0x33, 0x8e, 0xcb, 0x4d, 0x29, 0xe3, 0x70, 0xe7,
    0x9e, 0x9c, 0xb0, 0x32, 0xfb, 0x51, 0xf8, 0x75,
    0xa7, 0x5f, 0x08, 0x30, 0x93, 0x97, 0x84, 0x8b,
    0x80, 0x97, 0xb2, 0x26, 0x17, 0xff, 0x11, 0x08,
    0xbd, 0x33, 0xd8, 0xb6, 0x12, 0xbc, 0x43, 0x42,
    0xc3, 0x18, 0x87, 0x2f, 0x57, 0xfb, 0x0e, 0x26,
    0x43, 0xc9, 0xab, 0x65, 0x7a, 0x5a, 0x0a, 0xb9,
    0x28, 0xec, 0x00, 0x5b, 0x02, 0x81, 0x81, 0x00,
    0x94, 0x69, 0x45, 0xf8, 0x1b, 0xd8, 0x13, 0xfd,
    0x29, 0xf9, 0x9d, 0xa0, 0xee, 0x71, 0xd9, 0x94,
    0xcc, 0x30, 0x25, 0xfc, 0x78, 0x1a, 0xc9, 0xa3,
    0x1d, 0x73, 0x49, 0x51, 0xa5, 0xd7, 0x65, 0xc9,
    0xa3, 0xf7, 0x6d, 0x35, 0xa5, 0x18, 0xb6, 0x80,
    0x4e, 0x5c, 0x7a, 0x1c, 0xc9, 0x5c, 0x2d, 0xf4,
    0xde, 0xfc, 0x69, 0x00, 0x85, 0x0a, 0x2c, 0x8b,
    0xad, 0xec, 0x1c, 0x1a, 0xa4, 0x51, 0x6a, 0x8a,
    0x47, 0xbb, 0xbe, 0x73, 0x9b, 0xe7, 0x93, 0xfb,
    0x63, 0x5e, 0xcd, 0xe6, 0x92, 0x8a, 0xef, 0x68,
    0x84, 0x20, 0xa8, 0x33, 0xb5, 0x4f, 0xca, 0x49,
    0x26, 0x54, 0x73, 0xae, 0xca, 0x51, 0x8b, 0x64,
    0xa7, 0x7a, 0x3c, 0x02, 0x0a, 0x76, 0x67, 0xea,
    0x76, 0xdc, 0xcf, 0x1f, 0x85, 0xc5, 0x67, 0xeb,
    0xbd, 0x94, 0x48, 0x08, 0xbb, 0x17, 0x52, 0x27,
    0xd8, 0x28, 0x21, 0x39, 0x93, 0xe8, 0x03, 0x01,
};

const vsc_data_t test_signer_RSA2048_PRIVATE_KEY_PKCS8 = {
    RSA2048_PRIVATE_KEY_PKCS8_BYTES, sizeof(RSA2048_PRIVATE_KEY_PKCS8_BYTES)
};

static const byte RSA2048_SHA384_SIGNATURE_BYTES[] = {
    0x30, 0x82, 0x01, 0x11, 0x30, 0x0B, 0x06, 0x09,
    0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02,
    0x02, 0x04, 0x82, 0x01, 0x00, 0x3E, 0xD2, 0xDA,
    0xDE, 0xB0, 0xC3, 0xBC, 0xBB, 0xCA, 0xB0, 0xC8,
    0xC6, 0x04, 0x15, 0x36, 0x23, 0xCC, 0xD8, 0xCD,
    0xAA, 0x72, 0x73, 0xDC, 0x8E, 0xDC, 0x8D, 0xC3,
    0xEE, 0x01, 0x0A, 0x1D, 0x04, 0x02, 0xD8, 0x40,
    0x62, 0x60, 0xED, 0x70, 0xFF, 0x85, 0xE6, 0x1E,
    0x20, 0x98, 0x94, 0x41, 0x15, 0x2E, 0xD7, 0xB5,
    0xD4, 0x64, 0xDB, 0x2A, 0x7B, 0xDB, 0xB2, 0xC9,
    0x3D, 0x42, 0xA8, 0x3D, 0xB5, 0xE9, 0xA0, 0x81,
    0x94, 0x06, 0x22, 0x3C, 0xAC, 0xB9, 0xAD, 0x53,
    0xCE, 0x7F, 0x74, 0x37, 0x0C, 0x5B, 0x12, 0x2D,
    0x9C, 0x29, 0xF1, 0x46, 0x36, 0x3C, 0x0C, 0xDB,
    0x32, 0x09, 0xCC, 0x54, 0x38, 0x0D, 0x99, 0xBD,
    0x96, 0x79, 0x1F, 0xD8, 0x1E, 0x24, 0xB7, 0x0D,
    0xE1, 0x7A, 0xB3, 0xA5, 0x64, 0xCD, 0xAC, 0x03,
    0x09, 0xAA, 0xC6, 0xA9, 0xEE, 0x72, 0xBA, 0x25,
    0x02, 0x88, 0x5C, 0xE8, 0x16, 0x4E, 0xA3, 0xD4,
    0x48, 0x87, 0x02, 0xD1, 0xBC, 0xA0, 0x01, 0xAF,
    0x8F, 0xE6, 0x5D, 0xEC, 0x1E, 0x79, 0x09, 0xD4,
    0x81, 0x39, 0x1B, 0x17, 0x40, 0x43, 0xE5, 0x49,
    0xEC, 0xB6, 0x2C, 0x28, 0x0C, 0x82, 0x43, 0xA5,
    0x8B, 0x58, 0x6B, 0x24, 0x0F, 0x04, 0x50, 0x8C,
    0x19, 0x2C, 0x77, 0x0E, 0xAD, 0x77, 0xB7, 0x64,
    0xD7, 0xBE, 0x24, 0xAC, 0x44, 0x6E, 0xC4, 0xB6,
    0x57, 0xC3, 0x2B, 0xF3, 0xA6, 0x7B, 0xBF, 0x4E,
    0xDC, 0x18, 0x0B, 0x83, 0xE8, 0x95, 0xF7, 0x4C,
    0x1B, 0xEE, 0x0B, 0xCD, 0x17, 0x3A, 0x46, 0x02,
    0xFE, 0x54, 0xDD, 0xA8, 0x5D, 0x4C, 0x87, 0xC1,
    0x30, 0x50, 0x79, 0xC6, 0x90, 0xAF, 0x07, 0xE9,
    0xA2, 0x88, 0x7E, 0xEF, 0xF5, 0xBD, 0x82, 0xA0,
    0x1A, 0x3A, 0x89, 0xA3, 0x41, 0xA7, 0xF0, 0xE1,
    0x80, 0x88, 0x35, 0xC5, 0x63, 0xB1, 0xBF, 0x45,
    0x38, 0x66, 0x75, 0x11, 0x11
};

const vsc_data_t test_signer_RSA2048_SHA384_SIGNATURE = {
    RSA2048_SHA384_SIGNATURE_BYTES, sizeof(RSA2048_SHA384_SIGNATURE_BYTES)
};

static const byte RSA2048_SHA384_SIGNATURE_V2_COMPAT_BYTES[] = {
    0x30, 0x82, 0x01, 0x13, 0x30, 0x0D, 0x06, 0x09,
    0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02,
    0x02, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0x3E,
    0xD2, 0xDA, 0xDE, 0xB0, 0xC3, 0xBC, 0xBB, 0xCA,
    0xB0, 0xC8, 0xC6, 0x04, 0x15, 0x36, 0x23, 0xCC,
    0xD8, 0xCD, 0xAA, 0x72, 0x73, 0xDC, 0x8E, 0xDC,
    0x8D, 0xC3, 0xEE, 0x01, 0x0A, 0x1D, 0x04, 0x02,
    0xD8, 0x40, 0x62, 0x60, 0xED, 0x70, 0xFF, 0x85,
    0xE6, 0x1E, 0x20, 0x98, 0x94, 0x41, 0x15, 0x2E,
    0xD7, 0xB5, 0xD4, 0x64, 0xDB, 0x2A, 0x7B, 0xDB,
    0xB2, 0xC9, 0x3D, 0x42, 0xA8, 0x3D, 0xB5, 0xE9,
    0xA0, 0x81, 0x94, 0x06, 0x22, 0x3C, 0xAC, 0xB9,
    0xAD, 0x53, 0xCE, 0x7F, 0x74, 0x37, 0x0C, 0x5B,
    0x12, 0x2D, 0x9C, 0x29, 0xF1, 0x46, 0x36, 0x3C,
    0x0C, 0xDB, 0x32, 0x09, 0xCC, 0x54, 0x38, 0x0D,
    0x99, 0xBD, 0x96, 0x79, 0x1F, 0xD8, 0x1E, 0x24,
    0xB7, 0x0D, 0xE1, 0x7A, 0xB3, 0xA5, 0x64, 0xCD,
    0xAC, 0x03, 0x09, 0xAA, 0xC6, 0xA9, 0xEE, 0x72,
    0xBA, 0x25, 0x02, 0x88, 0x5C, 0xE8, 0x16, 0x4E,
    0xA3, 0xD4, 0x48, 0x87, 0x02, 0xD1, 0xBC, 0xA0,
    0x01, 0xAF, 0x8F, 0xE6, 0x5D, 0xEC, 0x1E, 0x79,
    0x09, 0xD4, 0x81, 0x39, 0x1B, 0x17, 0x40, 0x43,
    0xE5, 0x49, 0xEC, 0xB6, 0x2C, 0x28, 0x0C, 0x82,
    0x43, 0xA5, 0x8B, 0x58, 0x6B, 0x24, 0x0F, 0x04,
    0x50, 0x8C, 0x19, 0x2C, 0x77, 0x0E, 0xAD, 0x77,
    0xB7, 0x64, 0xD7, 0xBE, 0x24, 0xAC, 0x44, 0x6E,
    0xC4, 0xB6, 0x57, 0xC3, 0x2B, 0xF3, 0xA6, 0x7B,
    0xBF, 0x4E, 0xDC, 0x18, 0x0B, 0x83, 0xE8, 0x95,
    0xF7, 0x4C, 0x1B, 0xEE, 0x0B, 0xCD, 0x17, 0x3A,
    0x46, 0x02, 0xFE, 0x54, 0xDD, 0xA8, 0x5D, 0x4C,
    0x87, 0xC1, 0x30, 0x50, 0x79, 0xC6, 0x90, 0xAF,
    0x07, 0xE9, 0xA2, 0x88, 0x7E, 0xEF, 0xF5, 0xBD,
    0x82, 0xA0, 0x1A, 0x3A, 0x89, 0xA3, 0x41, 0xA7,
    0xF0, 0xE1, 0x80, 0x88, 0x35, 0xC5, 0x63, 0xB1,
    0xBF, 0x45, 0x38, 0x66, 0x75, 0x11, 0x11
};

const vsc_data_t test_signer_RSA2048_SHA384_SIGNATURE_V2_COMPAT = {
    RSA2048_SHA384_SIGNATURE_V2_COMPAT_BYTES, sizeof(RSA2048_SHA384_SIGNATURE_V2_COMPAT_BYTES)
};
