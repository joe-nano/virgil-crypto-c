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

#include "test_data_message_info_der.h"

// --------------------------------------------------------------------------
//  One Key Recipient
// --------------------------------------------------------------------------
static const byte ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES[] = {
    0x30, 0x82, 0x01, 0x8C, 0x02, 0x01, 0x00, 0x30,
    0x82, 0x01, 0x85, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x07, 0x03, 0xA0, 0x82,
    0x01, 0x76, 0x30, 0x82, 0x01, 0x72, 0x02, 0x01,
    0x02, 0x31, 0x82, 0x01, 0x3E, 0x30, 0x82, 0x01,
    0x3A, 0x02, 0x01, 0x02, 0xA0, 0x22, 0x04, 0x20,
    0xE9, 0x5F, 0x12, 0x2C, 0x87, 0x2B, 0x54, 0x85,
    0x85, 0x3F, 0xDF, 0x9C, 0xF3, 0x73, 0x9A, 0x9F,
    0x4E, 0xBF, 0xC3, 0x6C, 0x95, 0xF5, 0x7B, 0x69,
    0x1F, 0x4A, 0xE8, 0x87, 0x18, 0xD4, 0x21, 0xD8,
    0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
    0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04,
    0x82, 0x01, 0x00, 0x1E, 0x66, 0xCF, 0xE2, 0xE8,
    0xC2, 0x5E, 0xD8, 0xC0, 0xB2, 0xDD, 0xED, 0x05,
    0xB8, 0x7C, 0xCC, 0xF7, 0x81, 0xD4, 0xF6, 0xE9,
    0x6E, 0x68, 0x17, 0xE1, 0x4C, 0x5C, 0xF4, 0xD4,
    0xA3, 0x08, 0x30, 0x1D, 0x95, 0x5E, 0x2E, 0xB0,
    0x3C, 0x95, 0xEA, 0xAB, 0xB6, 0xCB, 0x91, 0xB3,
    0x7C, 0x96, 0x93, 0xE7, 0xD6, 0x4B, 0x80, 0x2B,
    0xE1, 0x99, 0xA5, 0xF0, 0x62, 0xA5, 0xFE, 0x7E,
    0x0D, 0x83, 0x8A, 0x4F, 0xE0, 0x4C, 0x7C, 0xFA,
    0xAF, 0x61, 0x74, 0x0E, 0xFF, 0x37, 0xDE, 0x9D,
    0x4E, 0x54, 0x1D, 0xF5, 0x2C, 0xE0, 0x1C, 0x14,
    0x91, 0x29, 0x9C, 0x81, 0xDC, 0x9A, 0x92, 0x73,
    0x24, 0x35, 0xA1, 0x2C, 0x03, 0xE0, 0x56, 0x41,
    0x2E, 0xFC, 0xD2, 0xE8, 0x81, 0x5B, 0x4F, 0x39,
    0x3E, 0x22, 0xE0, 0xCF, 0xB9, 0x90, 0xCD, 0x85,
    0xAA, 0x4D, 0x92, 0xB4, 0x80, 0x62, 0xEA, 0x84,
    0x96, 0xFE, 0x44, 0x43, 0x17, 0x50, 0xCD, 0xC1,
    0x50, 0xBE, 0xD7, 0xDD, 0xAC, 0x9E, 0x24, 0x44,
    0xAA, 0x79, 0xEF, 0x9D, 0x62, 0x2F, 0xC2, 0x63,
    0xF4, 0x72, 0xDD, 0x72, 0xAF, 0x1A, 0x12, 0xB4,
    0x70, 0xF2, 0xE7, 0x36, 0x7E, 0x63, 0x30, 0x36,
    0x9C, 0xC3, 0x2D, 0xAC, 0xDD, 0x66, 0x8A, 0xCA,
    0x63, 0x75, 0xA5, 0x82, 0x38, 0xE9, 0xF0, 0x5D,
    0xE1, 0xEE, 0x35, 0xB4, 0xE6, 0xA8, 0x1E, 0x80,
    0xEC, 0xE0, 0x4D, 0x75, 0xA1, 0x5D, 0x46, 0x10,
    0x98, 0xBF, 0x3F, 0x5F, 0xE2, 0x70, 0x09, 0xB9,
    0x77, 0x6C, 0x52, 0xFD, 0x4A, 0xC4, 0xF6, 0xEE,
    0x7C, 0x56, 0x32, 0x8E, 0x2D, 0x18, 0x44, 0x17,
    0x74, 0x67, 0xCE, 0x3B, 0x97, 0x9D, 0x9E, 0x1C,
    0x3D, 0xE3, 0x83, 0x07, 0x7C, 0x9A, 0xE1, 0x12,
    0x8A, 0x1A, 0x8E, 0x24, 0x5F, 0x36, 0xBD, 0x8D,
    0xDE, 0x03, 0xED, 0xCA, 0x44, 0xFD, 0xBE, 0x3C,
    0xB7, 0x4F, 0xA8, 0x30, 0x2B, 0x06, 0x09, 0x2A,
    0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01,
    0x30, 0x1E, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01,
    0x65, 0x03, 0x04, 0x01, 0x2E, 0x30, 0x11, 0x04,
    0x0C, 0x7E, 0xD7, 0x89, 0x7C, 0x64, 0xA2, 0xD8,
    0x5C, 0xBF, 0xB9, 0x6C, 0xF2, 0x02, 0x01, 0x0C,
};

static const byte V2_COMPATIBLE_ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES[] = {
    0x30, 0x82, 0x01, 0x87, 0x02, 0x01, 0x00, 0x30,
    0x82, 0x01, 0x80, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x07, 0x03, 0xA0, 0x82,
    0x01, 0x71, 0x30, 0x82, 0x01, 0x6D, 0x02, 0x01,
    0x02, 0x31, 0x82, 0x01, 0x3E, 0x30, 0x82, 0x01,
    0x3A, 0x02, 0x01, 0x02, 0xA0, 0x22, 0x04, 0x20,
    0xE9, 0x5F, 0x12, 0x2C, 0x87, 0x2B, 0x54, 0x85,
    0x85, 0x3F, 0xDF, 0x9C, 0xF3, 0x73, 0x9A, 0x9F,
    0x4E, 0xBF, 0xC3, 0x6C, 0x95, 0xF5, 0x7B, 0x69,
    0x1F, 0x4A, 0xE8, 0x87, 0x18, 0xD4, 0x21, 0xD8,
    0x30, 0x0D, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
    0xF7, 0x0D, 0x01, 0x01, 0x01, 0x05, 0x00, 0x04,
    0x82, 0x01, 0x00, 0x1E, 0x66, 0xCF, 0xE2, 0xE8,
    0xC2, 0x5E, 0xD8, 0xC0, 0xB2, 0xDD, 0xED, 0x05,
    0xB8, 0x7C, 0xCC, 0xF7, 0x81, 0xD4, 0xF6, 0xE9,
    0x6E, 0x68, 0x17, 0xE1, 0x4C, 0x5C, 0xF4, 0xD4,
    0xA3, 0x08, 0x30, 0x1D, 0x95, 0x5E, 0x2E, 0xB0,
    0x3C, 0x95, 0xEA, 0xAB, 0xB6, 0xCB, 0x91, 0xB3,
    0x7C, 0x96, 0x93, 0xE7, 0xD6, 0x4B, 0x80, 0x2B,
    0xE1, 0x99, 0xA5, 0xF0, 0x62, 0xA5, 0xFE, 0x7E,
    0x0D, 0x83, 0x8A, 0x4F, 0xE0, 0x4C, 0x7C, 0xFA,
    0xAF, 0x61, 0x74, 0x0E, 0xFF, 0x37, 0xDE, 0x9D,
    0x4E, 0x54, 0x1D, 0xF5, 0x2C, 0xE0, 0x1C, 0x14,
    0x91, 0x29, 0x9C, 0x81, 0xDC, 0x9A, 0x92, 0x73,
    0x24, 0x35, 0xA1, 0x2C, 0x03, 0xE0, 0x56, 0x41,
    0x2E, 0xFC, 0xD2, 0xE8, 0x81, 0x5B, 0x4F, 0x39,
    0x3E, 0x22, 0xE0, 0xCF, 0xB9, 0x90, 0xCD, 0x85,
    0xAA, 0x4D, 0x92, 0xB4, 0x80, 0x62, 0xEA, 0x84,
    0x96, 0xFE, 0x44, 0x43, 0x17, 0x50, 0xCD, 0xC1,
    0x50, 0xBE, 0xD7, 0xDD, 0xAC, 0x9E, 0x24, 0x44,
    0xAA, 0x79, 0xEF, 0x9D, 0x62, 0x2F, 0xC2, 0x63,
    0xF4, 0x72, 0xDD, 0x72, 0xAF, 0x1A, 0x12, 0xB4,
    0x70, 0xF2, 0xE7, 0x36, 0x7E, 0x63, 0x30, 0x36,
    0x9C, 0xC3, 0x2D, 0xAC, 0xDD, 0x66, 0x8A, 0xCA,
    0x63, 0x75, 0xA5, 0x82, 0x38, 0xE9, 0xF0, 0x5D,
    0xE1, 0xEE, 0x35, 0xB4, 0xE6, 0xA8, 0x1E, 0x80,
    0xEC, 0xE0, 0x4D, 0x75, 0xA1, 0x5D, 0x46, 0x10,
    0x98, 0xBF, 0x3F, 0x5F, 0xE2, 0x70, 0x09, 0xB9,
    0x77, 0x6C, 0x52, 0xFD, 0x4A, 0xC4, 0xF6, 0xEE,
    0x7C, 0x56, 0x32, 0x8E, 0x2D, 0x18, 0x44, 0x17,
    0x74, 0x67, 0xCE, 0x3B, 0x97, 0x9D, 0x9E, 0x1C,
    0x3D, 0xE3, 0x83, 0x07, 0x7C, 0x9A, 0xE1, 0x12,
    0x8A, 0x1A, 0x8E, 0x24, 0x5F, 0x36, 0xBD, 0x8D,
    0xDE, 0x03, 0xED, 0xCA, 0x44, 0xFD, 0xBE, 0x3C,
    0xB7, 0x4F, 0xA8, 0x30, 0x26, 0x06, 0x09, 0x2A,
    0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01,
    0x30, 0x19, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01,
    0x65, 0x03, 0x04, 0x01, 0x2E, 0x04, 0x0C, 0x7E,
    0xD7, 0x89, 0x7C, 0x64, 0xA2, 0xD8, 0x5C, 0xBF,
    0xB9, 0x6C, 0xF2
};

static const byte ONE_RSA2048_KEY_RECIPIENT_RECIPIENT_ID_BYTES[] = {
    0xE9, 0x5F, 0x12, 0x2C, 0x87, 0x2B, 0x54, 0x85,
    0x85, 0x3F, 0xDF, 0x9C, 0xF3, 0x73, 0x9A, 0x9F,
    0x4E, 0xBF, 0xC3, 0x6C, 0x95, 0xF5, 0x7B, 0x69,
    0x1F, 0x4A, 0xE8, 0x87, 0x18, 0xD4, 0x21, 0xD8,
};

static const byte ONE_RSA2048_KEY_RECIPIENT_ENCRYPTED_KEY_BYTES[] = {
    0x1E, 0x66, 0xCF, 0xE2, 0xE8, 0xC2, 0x5E, 0xD8,
    0xC0, 0xB2, 0xDD, 0xED, 0x05, 0xB8, 0x7C, 0xCC,
    0xF7, 0x81, 0xD4, 0xF6, 0xE9, 0x6E, 0x68, 0x17,
    0xE1, 0x4C, 0x5C, 0xF4, 0xD4, 0xA3, 0x08, 0x30,
    0x1D, 0x95, 0x5E, 0x2E, 0xB0, 0x3C, 0x95, 0xEA,
    0xAB, 0xB6, 0xCB, 0x91, 0xB3, 0x7C, 0x96, 0x93,
    0xE7, 0xD6, 0x4B, 0x80, 0x2B, 0xE1, 0x99, 0xA5,
    0xF0, 0x62, 0xA5, 0xFE, 0x7E, 0x0D, 0x83, 0x8A,
    0x4F, 0xE0, 0x4C, 0x7C, 0xFA, 0xAF, 0x61, 0x74,
    0x0E, 0xFF, 0x37, 0xDE, 0x9D, 0x4E, 0x54, 0x1D,
    0xF5, 0x2C, 0xE0, 0x1C, 0x14, 0x91, 0x29, 0x9C,
    0x81, 0xDC, 0x9A, 0x92, 0x73, 0x24, 0x35, 0xA1,
    0x2C, 0x03, 0xE0, 0x56, 0x41, 0x2E, 0xFC, 0xD2,
    0xE8, 0x81, 0x5B, 0x4F, 0x39, 0x3E, 0x22, 0xE0,
    0xCF, 0xB9, 0x90, 0xCD, 0x85, 0xAA, 0x4D, 0x92,
    0xB4, 0x80, 0x62, 0xEA, 0x84, 0x96, 0xFE, 0x44,
    0x43, 0x17, 0x50, 0xCD, 0xC1, 0x50, 0xBE, 0xD7,
    0xDD, 0xAC, 0x9E, 0x24, 0x44, 0xAA, 0x79, 0xEF,
    0x9D, 0x62, 0x2F, 0xC2, 0x63, 0xF4, 0x72, 0xDD,
    0x72, 0xAF, 0x1A, 0x12, 0xB4, 0x70, 0xF2, 0xE7,
    0x36, 0x7E, 0x63, 0x30, 0x36, 0x9C, 0xC3, 0x2D,
    0xAC, 0xDD, 0x66, 0x8A, 0xCA, 0x63, 0x75, 0xA5,
    0x82, 0x38, 0xE9, 0xF0, 0x5D, 0xE1, 0xEE, 0x35,
    0xB4, 0xE6, 0xA8, 0x1E, 0x80, 0xEC, 0xE0, 0x4D,
    0x75, 0xA1, 0x5D, 0x46, 0x10, 0x98, 0xBF, 0x3F,
    0x5F, 0xE2, 0x70, 0x09, 0xB9, 0x77, 0x6C, 0x52,
    0xFD, 0x4A, 0xC4, 0xF6, 0xEE, 0x7C, 0x56, 0x32,
    0x8E, 0x2D, 0x18, 0x44, 0x17, 0x74, 0x67, 0xCE,
    0x3B, 0x97, 0x9D, 0x9E, 0x1C, 0x3D, 0xE3, 0x83,
    0x07, 0x7C, 0x9A, 0xE1, 0x12, 0x8A, 0x1A, 0x8E,
    0x24, 0x5F, 0x36, 0xBD, 0x8D, 0xDE, 0x03, 0xED,
    0xCA, 0x44, 0xFD, 0xBE, 0x3C, 0xB7, 0x4F, 0xA8,
};

static const byte ONE_RSA2048_KEY_RECIPIENT_DATA_ALG_NONCE_BYTES[] = {
    0x7E, 0xD7, 0x89, 0x7C, 0x64, 0xA2, 0xD8, 0x5C,
    0xBF, 0xB9, 0x6C, 0xF2
};


const test_one_key_recipient_cms_t test_message_info_cms_ONE_RSA2048_KEY_RECIPIENT = {
    { ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_RECIPIENT_ID_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_RECIPIENT_ID_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_ENCRYPTED_KEY_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_ENCRYPTED_KEY_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_DATA_ALG_NONCE_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_DATA_ALG_NONCE_BYTES) },
};


const test_one_key_recipient_cms_t test_message_info_cms_V2_COMPATIBLE_ONE_RSA2048_KEY_RECIPIENT = {
    { V2_COMPATIBLE_ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES, sizeof(V2_COMPATIBLE_ONE_RSA2048_KEY_RECIPIENT_SERIALIZED_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_RECIPIENT_ID_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_RECIPIENT_ID_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_ENCRYPTED_KEY_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_ENCRYPTED_KEY_BYTES) },
    { ONE_RSA2048_KEY_RECIPIENT_DATA_ALG_NONCE_BYTES, sizeof(ONE_RSA2048_KEY_RECIPIENT_DATA_ALG_NONCE_BYTES) },
};

// --------------------------------------------------------------------------
//  One Password Recipient
// --------------------------------------------------------------------------
static const byte ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES[] = {
    0x30, 0x81, 0xE6, 0x02, 0x01, 0x00, 0x30, 0x81,
    0xE0, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x07, 0x03, 0xA0, 0x81, 0xD2, 0x30,
    0x81, 0xCF, 0x02, 0x01, 0x03, 0x31, 0x81, 0x9C,
    0xA3, 0x81, 0x99, 0x30, 0x81, 0x96, 0x02, 0x01,
    0x00, 0x30, 0x5F, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0D, 0x30, 0x52,
    0x30, 0x31, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
    0xF7, 0x0D, 0x01, 0x05, 0x0C, 0x30, 0x24, 0x04,
    0x10, 0xD0, 0x6D, 0xC3, 0x7E, 0x27, 0xDD, 0x88,
    0xA9, 0x32, 0x69, 0xB2, 0xB4, 0x64, 0x10, 0x57,
    0xEF, 0x02, 0x02, 0x1E, 0xAE, 0x30, 0x0C, 0x06,
    0x08, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x02,
    0x0A, 0x05, 0x00, 0x30, 0x1D, 0x06, 0x09, 0x60,
    0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x01, 0x2A,
    0x04, 0x10, 0x4A, 0x2D, 0xDB, 0xD1, 0x69, 0x79,
    0x95, 0x4B, 0x6B, 0xEF, 0x5A, 0x63, 0x6D, 0x94,
    0xFD, 0x79, 0x04, 0x30, 0xAB, 0x63, 0x20, 0x08,
    0xD8, 0xF9, 0xAB, 0x10, 0xE6, 0x10, 0xE3, 0x97,
    0xCE, 0xA6, 0x8C, 0x26, 0xFA, 0xB6, 0x21, 0xFF,
    0xC9, 0x4F, 0x91, 0xAC, 0x3E, 0x04, 0xB9, 0x59,
    0x16, 0x5E, 0xFE, 0x83, 0x7F, 0x94, 0x84, 0x21,
    0x0C, 0x7A, 0x18, 0xAA, 0xC4, 0xC0, 0xED, 0x28,
    0xA5, 0xBD, 0x7B, 0x68, 0x30, 0x2B, 0x06, 0x09,
    0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07,
    0x01, 0x30, 0x1E, 0x06, 0x09, 0x60, 0x86, 0x48,
    0x01, 0x65, 0x03, 0x04, 0x01, 0x2E, 0x30, 0x11,
    0x04, 0x0C, 0x4A, 0xB6, 0x43, 0x08, 0xD1, 0xFD,
    0x5C, 0x52, 0x91, 0xAF, 0x4C, 0xA3, 0x02, 0x01,
    0x0C
};

static const byte V2_COMPATIBLE_ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES[] = {
    0x30, 0x81, 0xE4, 0x02, 0x01, 0x00, 0x30, 0x81,
    0xDE, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7,
    0x0D, 0x01, 0x07, 0x03, 0xA0, 0x81, 0xD0, 0x30,
    0x81, 0xCD, 0x02, 0x01, 0x03, 0x31, 0x81, 0x9A,
    0xA3, 0x81, 0x97, 0x30, 0x81, 0x94, 0x02, 0x01,
    0x00, 0x30, 0x5D, 0x06, 0x09, 0x2A, 0x86, 0x48,
    0x86, 0xF7, 0x0D, 0x01, 0x05, 0x0D, 0x30, 0x50,
    0x30, 0x2F, 0x06, 0x09, 0x2A, 0x86, 0x48, 0x86,
    0xF7, 0x0D, 0x01, 0x05, 0x0C, 0x30, 0x22, 0x04,
    0x10, 0xD0, 0x6D, 0xC3, 0x7E, 0x27, 0xDD, 0x88,
    0xA9, 0x32, 0x69, 0xB2, 0xB4, 0x64, 0x10, 0x57,
    0xEF, 0x02, 0x02, 0x1E, 0xAE, 0x30, 0x0A, 0x06,
    0x08, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x02,
    0x0A, 0x30, 0x1D, 0x06, 0x09, 0x60, 0x86, 0x48,
    0x01, 0x65, 0x03, 0x04, 0x01, 0x2A, 0x04, 0x10,
    0x4A, 0x2D, 0xDB, 0xD1, 0x69, 0x79, 0x95, 0x4B,
    0x6B, 0xEF, 0x5A, 0x63, 0x6D, 0x94, 0xFD, 0x79,
    0x04, 0x30, 0xAB, 0x63, 0x20, 0x08, 0xD8, 0xF9,
    0xAB, 0x10, 0xE6, 0x10, 0xE3, 0x97, 0xCE, 0xA6,
    0x8C, 0x26, 0xFA, 0xB6, 0x21, 0xFF, 0xC9, 0x4F,
    0x91, 0xAC, 0x3E, 0x04, 0xB9, 0x59, 0x16, 0x5E,
    0xFE, 0x83, 0x7F, 0x94, 0x84, 0x21, 0x0C, 0x7A,
    0x18, 0xAA, 0xC4, 0xC0, 0xED, 0x28, 0xA5, 0xBD,
    0x7B, 0x68, 0x30, 0x2B, 0x06, 0x09, 0x2A, 0x86,
    0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01, 0x30,
    0x1E, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65,
    0x03, 0x04, 0x01, 0x2E, 0x30, 0x11, 0x04, 0x0C,
    0x4A, 0xB6, 0x43, 0x08, 0xD1, 0xFD, 0x5C, 0x52,
    0x91, 0xAF, 0x4C, 0xA3, 0x02, 0x01, 0x0C
};

static const byte ONE_PASSWORD_RECIPIENT_KDF_SALT_BYTES[] = {
    0xD0, 0x6D, 0xC3, 0x7E, 0x27, 0xDD, 0x88, 0xA9,
    0x32, 0x69, 0xB2, 0xB4, 0x64, 0x10, 0x57, 0xEF,
};

static const byte ONE_PASSWORD_RECIPIENT_KEY_ALG_NONCE_BYTES[] = {
    0x4A, 0x2D, 0xDB, 0xD1, 0x69, 0x79, 0x95, 0x4B,
    0x6B, 0xEF, 0x5A, 0x63, 0x6D, 0x94, 0xFD, 0x79,
};

static const byte ONE_PASSWORD_RECIPIENT_DATA_ALG_NONCE_BYTES[] = {
    0x4A, 0xB6, 0x43, 0x08, 0xD1, 0xFD, 0x5C, 0x52,
    0x91, 0xAF, 0x4C, 0xA3
};

static const byte ONE_PASSWORD_RECIPIENT_ENCRYPTED_KEY_BYTES[] = {
    0xAB, 0x63, 0x20, 0x08, 0xD8, 0xF9, 0xAB, 0x10,
    0xE6, 0x10, 0xE3, 0x97, 0xCE, 0xA6, 0x8C, 0x26,
    0xFA, 0xB6, 0x21, 0xFF, 0xC9, 0x4F, 0x91, 0xAC,
    0x3E, 0x04, 0xB9, 0x59, 0x16, 0x5E, 0xFE, 0x83,
    0x7F, 0x94, 0x84, 0x21, 0x0C, 0x7A, 0x18, 0xAA,
    0xC4, 0xC0, 0xED, 0x28, 0xA5, 0xBD, 0x7B, 0x68,
};

const test_one_password_recipient_cms_t test_message_info_cms_ONE_PASSWORD_RECIPIENT = {
    { ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES) },
    { ONE_PASSWORD_RECIPIENT_KDF_SALT_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_KDF_SALT_BYTES) },
    7854,
    { ONE_PASSWORD_RECIPIENT_KEY_ALG_NONCE_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_KEY_ALG_NONCE_BYTES) },
    { ONE_PASSWORD_RECIPIENT_DATA_ALG_NONCE_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_DATA_ALG_NONCE_BYTES) },
    { ONE_PASSWORD_RECIPIENT_ENCRYPTED_KEY_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_ENCRYPTED_KEY_BYTES) },
};

const test_one_password_recipient_cms_t test_message_info_cms_V2_COMPATIBLE_ONE_PASSWORD_RECIPIENT = {
    { V2_COMPATIBLE_ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES, sizeof(V2_COMPATIBLE_ONE_PASSWORD_RECIPIENT_SERIALIZED_BYTES) },
    { ONE_PASSWORD_RECIPIENT_KDF_SALT_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_KDF_SALT_BYTES) },
    7854,
    { ONE_PASSWORD_RECIPIENT_KEY_ALG_NONCE_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_KEY_ALG_NONCE_BYTES) },
    { ONE_PASSWORD_RECIPIENT_DATA_ALG_NONCE_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_DATA_ALG_NONCE_BYTES) },
    { ONE_PASSWORD_RECIPIENT_ENCRYPTED_KEY_BYTES, sizeof(ONE_PASSWORD_RECIPIENT_ENCRYPTED_KEY_BYTES) },
};

const char INT_CUSTOM_PARAM_KEY_STR[] = "int_parameter_key";

const vsc_data_t test_message_info_cms_INT_CUSTOM_PARAM_KEY = {
    (const byte *)INT_CUSTOM_PARAM_KEY_STR, sizeof(INT_CUSTOM_PARAM_KEY_STR) - 1
};

const int test_message_info_cms_INT_CUSTOM_PARAM_VALUE = 35777;

const char STRING_CUSTOM_PARAM_KEY_STR[] = " string_parameter_key";

const vsc_data_t test_message_info_cms_STRING_CUSTOM_PARAM_KEY = {
    (const byte *)STRING_CUSTOM_PARAM_KEY_STR, sizeof(STRING_CUSTOM_PARAM_KEY_STR) - 1
};

const char STRING_CUSTOM_PARAM_VALUE_STR[] = "string parameter";

const vsc_data_t test_message_info_cms_STRING_CUSTOM_PARAM_VALUE = {
    (const byte *)STRING_CUSTOM_PARAM_VALUE_STR, sizeof(STRING_CUSTOM_PARAM_VALUE_STR) - 1
};

const char DATA_CUSTOM_PARAM_KEY_STR[] = "data_parameter_key";

const vsc_data_t test_message_info_cms_DATA_CUSTOM_PARAM_KEY = {
    (const byte *)DATA_CUSTOM_PARAM_KEY_STR, sizeof(DATA_CUSTOM_PARAM_KEY_STR) - 1
};

const char DATA_CUSTOM_PARAM_VALUE_STR[] = "will be stored as an octet string";

const vsc_data_t test_message_info_cms_DATA_CUSTOM_PARAM_VALUE = {
    (const byte *)DATA_CUSTOM_PARAM_VALUE_STR, sizeof(DATA_CUSTOM_PARAM_VALUE_STR) - 1
};

const byte NO_RECIPIENTS_AND_3_CUSTOM_PARAMS_BYTES[] = {
    0x30, 0x81, 0xD0, 0x02, 0x01, 0x00, 0x30, 0x41,
    0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D,
    0x01, 0x07, 0x03, 0xA0, 0x34, 0x30, 0x32, 0x02,
    0x01, 0x02, 0x31, 0x00, 0x30, 0x2B, 0x06, 0x09,
    0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07,
    0x01, 0x30, 0x1E, 0x06, 0x09, 0x60, 0x86, 0x48,
    0x01, 0x65, 0x03, 0x04, 0x01, 0x2E, 0x30, 0x11,
    0x04, 0x0C, 0x7E, 0xD7, 0x89, 0x7C, 0x64, 0xA2,
    0xD8, 0x5C, 0xBF, 0xB9, 0x6C, 0xF2, 0x02, 0x01,
    0x0C, 0xA0, 0x81, 0x87, 0x31, 0x81, 0x84, 0x30,
    0x1A, 0x0C, 0x11, 0x69, 0x6E, 0x74, 0x5F, 0x70,
    0x61, 0x72, 0x61, 0x6D, 0x65, 0x74, 0x65, 0x72,
    0x5F, 0x6B, 0x65, 0x79, 0xA0, 0x05, 0x02, 0x03,
    0x00, 0x8B, 0xC1, 0x30, 0x2B, 0x0C, 0x15, 0x20,
    0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x5F, 0x70,
    0x61, 0x72, 0x61, 0x6D, 0x65, 0x74, 0x65, 0x72,
    0x5F, 0x6B, 0x65, 0x79, 0xA1, 0x12, 0x0C, 0x10,
    0x73, 0x74, 0x72, 0x69, 0x6E, 0x67, 0x20, 0x70,
    0x61, 0x72, 0x61, 0x6D, 0x65, 0x74, 0x65, 0x72,
    0x30, 0x39, 0x0C, 0x12, 0x64, 0x61, 0x74, 0x61,
    0x5F, 0x70, 0x61, 0x72, 0x61, 0x6D, 0x65, 0x74,
    0x65, 0x72, 0x5F, 0x6B, 0x65, 0x79, 0xA2, 0x23,
    0x04, 0x21, 0x77, 0x69, 0x6C, 0x6C, 0x20, 0x62,
    0x65, 0x20, 0x73, 0x74, 0x6F, 0x72, 0x65, 0x64,
    0x20, 0x61, 0x73, 0x20, 0x61, 0x6E, 0x20, 0x6F,
    0x63, 0x74, 0x65, 0x74, 0x20, 0x73, 0x74, 0x72,
    0x69, 0x6E, 0x67
};

const vsc_data_t test_message_info_cms_NO_RECIPIENTS_AND_3_CUSTOM_PARAMS = {
    NO_RECIPIENTS_AND_3_CUSTOM_PARAMS_BYTES, sizeof(NO_RECIPIENTS_AND_3_CUSTOM_PARAMS_BYTES)
};

