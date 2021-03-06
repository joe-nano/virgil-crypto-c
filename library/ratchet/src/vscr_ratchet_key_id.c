//  @license
// --------------------------------------------------------------------------
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
// --------------------------------------------------------------------------
// clang-format off


//  @description
// --------------------------------------------------------------------------
//  Utils class for working with keys formats.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscr_ratchet_key_id.h"
#include "vscr_memory.h"
#include "vscr_assert.h"
#include "vscr_ratchet_key_id_defs.h"

#include <virgil/crypto/foundation/vscf_sha512.h>
#include <virgil/crypto/common/private/vsc_buffer_defs.h>

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscr_ratchet_key_id_init() is called.
//  Note, that context is already zeroed.
//
static void
vscr_ratchet_key_id_init_ctx(vscr_ratchet_key_id_t *self);

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscr_ratchet_key_id_cleanup_ctx(vscr_ratchet_key_id_t *self);

//
//  Return size of 'vscr_ratchet_key_id_t'.
//
VSCR_PUBLIC size_t
vscr_ratchet_key_id_ctx_size(void) {

    return sizeof(vscr_ratchet_key_id_t);
}

//
//  Perform initialization of pre-allocated context.
//
VSCR_PUBLIC void
vscr_ratchet_key_id_init(vscr_ratchet_key_id_t *self) {

    VSCR_ASSERT_PTR(self);

    vscr_zeroize(self, sizeof(vscr_ratchet_key_id_t));

    self->refcnt = 1;

    vscr_ratchet_key_id_init_ctx(self);
}

//
//  Release all inner resources including class dependencies.
//
VSCR_PUBLIC void
vscr_ratchet_key_id_cleanup(vscr_ratchet_key_id_t *self) {

    if (self == NULL) {
        return;
    }

    vscr_ratchet_key_id_cleanup_ctx(self);

    vscr_zeroize(self, sizeof(vscr_ratchet_key_id_t));
}

//
//  Allocate context and perform it's initialization.
//
VSCR_PUBLIC vscr_ratchet_key_id_t *
vscr_ratchet_key_id_new(void) {

    vscr_ratchet_key_id_t *self = (vscr_ratchet_key_id_t *) vscr_alloc(sizeof (vscr_ratchet_key_id_t));
    VSCR_ASSERT_ALLOC(self);

    vscr_ratchet_key_id_init(self);

    self->self_dealloc_cb = vscr_dealloc;

    return self;
}

//
//  Release all inner resources and deallocate context if needed.
//  It is safe to call this method even if the context was statically allocated.
//
VSCR_PUBLIC void
vscr_ratchet_key_id_delete(vscr_ratchet_key_id_t *self) {

    if (self == NULL) {
        return;
    }

    size_t old_counter = self->refcnt;
    VSCR_ASSERT(old_counter != 0);
    size_t new_counter = old_counter - 1;

    #if defined(VSCR_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    while (!VSCR_ATOMIC_COMPARE_EXCHANGE_WEAK(&self->refcnt, &old_counter, new_counter)) {
        old_counter = self->refcnt;
        VSCR_ASSERT(old_counter != 0);
        new_counter = old_counter - 1;
    }
    #else
    self->refcnt = new_counter;
    #endif

    if (new_counter > 0) {
        return;
    }

    vscr_dealloc_fn self_dealloc_cb = self->self_dealloc_cb;

    vscr_ratchet_key_id_cleanup(self);

    if (self_dealloc_cb != NULL) {
        self_dealloc_cb(self);
    }
}

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vscr_ratchet_key_id_new ()'.
//
VSCR_PUBLIC void
vscr_ratchet_key_id_destroy(vscr_ratchet_key_id_t **self_ref) {

    VSCR_ASSERT_PTR(self_ref);

    vscr_ratchet_key_id_t *self = *self_ref;
    *self_ref = NULL;

    vscr_ratchet_key_id_delete(self);
}

//
//  Copy given class context by increasing reference counter.
//
VSCR_PUBLIC vscr_ratchet_key_id_t *
vscr_ratchet_key_id_shallow_copy(vscr_ratchet_key_id_t *self) {

    VSCR_ASSERT_PTR(self);

    #if defined(VSCR_ATOMIC_COMPARE_EXCHANGE_WEAK)
    //  CAS loop
    size_t old_counter;
    size_t new_counter;
    do {
        old_counter = self->refcnt;
        new_counter = old_counter + 1;
    } while (!VSCR_ATOMIC_COMPARE_EXCHANGE_WEAK(&self->refcnt, &old_counter, new_counter));
    #else
    ++self->refcnt;
    #endif

    return self;
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


//
//  Perform context specific initialization.
//  Note, this method is called automatically when method vscr_ratchet_key_id_init() is called.
//  Note, that context is already zeroed.
//
static void
vscr_ratchet_key_id_init_ctx(vscr_ratchet_key_id_t *self) {

    VSCR_ASSERT_PTR(self);

    self->key_utils = vscr_ratchet_key_utils_new();
}

//
//  Release all inner resources.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
static void
vscr_ratchet_key_id_cleanup_ctx(vscr_ratchet_key_id_t *self) {

    VSCR_ASSERT_PTR(self);

    vscr_ratchet_key_utils_destroy(&self->key_utils);
}

//
//  Computes 8 bytes key pair id from Curve25519 (in PKCS8 or raw format) public key
//
VSCR_PUBLIC vscr_status_t
vscr_ratchet_key_id_compute_public_key_id(vscr_ratchet_key_id_t *self, vsc_data_t public_key, vsc_buffer_t *key_id) {

    if (public_key.len == vscr_ratchet_common_hidden_KEY_LEN) {
        byte digest[vscf_sha512_DIGEST_LEN];

        vsc_buffer_t digest_buf;
        vsc_buffer_init(&digest_buf);
        vsc_buffer_use(&digest_buf, digest, sizeof(digest));

        vscf_sha512_hash(public_key, &digest_buf);

        vsc_buffer_delete(&digest_buf);

        vsc_buffer_write_data(key_id, vsc_data(digest, vscr_ratchet_common_KEY_ID_LEN));

        return vscr_status_SUCCESS;
    }

    vscr_error_t error_ctx;
    vscr_error_reset(&error_ctx);

    vsc_buffer_t *raw_public_key = vscr_ratchet_key_utils_extract_ratchet_public_key(
            self->key_utils, public_key, true, true, false, &error_ctx);

    if (vscr_error_has_error(&error_ctx)) {
        return vscr_error_status(&error_ctx);
    }

    vscr_status_t result = vscr_ratchet_key_id_compute_public_key_id(self, vsc_buffer_data(raw_public_key), key_id);

    vsc_buffer_destroy(&raw_public_key);

    return result;
}
