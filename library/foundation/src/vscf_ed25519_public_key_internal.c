//  @license
// --------------------------------------------------------------------------
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
// --------------------------------------------------------------------------
// clang-format off


//  @description
// --------------------------------------------------------------------------
//  This module contains logic for interface/implementation architecture.
//  Do not use this module in any part of the code.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_ed25519_public_key_internal.h"
#include "vscf_memory.h"
#include "vscf_assert.h"
#include "vscf_ed25519_public_key_defs.h"
#include "vscf_defaults.h"
#include "vscf_defaults_api.h"
#include "vscf_alg.h"
#include "vscf_alg_api.h"
#include "vscf_key.h"
#include "vscf_key_api.h"
#include "vscf_encrypt.h"
#include "vscf_encrypt_api.h"
#include "vscf_verify_hash.h"
#include "vscf_verify_hash_api.h"
#include "vscf_public_key.h"
#include "vscf_public_key_api.h"
#include "vscf_generate_ephemeral_key.h"
#include "vscf_generate_ephemeral_key_api.h"
#include "vscf_random.h"
#include "vscf_ecies.h"
#include "vscf_impl.h"
#include "vscf_api.h"

// clang-format on
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

static const vscf_api_t *
vscf_ed25519_public_key_find_api(vscf_api_tag_t api_tag);

//
//  Configuration of the interface API 'defaults api'.
//
static const vscf_defaults_api_t defaults_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'defaults' MUST be equal to the 'vscf_api_tag_DEFAULTS'.
    //
    vscf_api_tag_DEFAULTS,
    //
    //  Setup predefined values to the uninitialized class dependencies.
    //
    (vscf_defaults_api_setup_defaults_fn)vscf_ed25519_public_key_setup_defaults
};

//
//  Configuration of the interface API 'alg api'.
//
static const vscf_alg_api_t alg_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'alg' MUST be equal to the 'vscf_api_tag_ALG'.
    //
    vscf_api_tag_ALG,
    //
    //  Provide algorithm identificator.
    //
    (vscf_alg_api_alg_id_fn)vscf_ed25519_public_key_alg_id,
    //
    //  Produce object with algorithm information and configuration parameters.
    //
    (vscf_alg_api_produce_alg_info_fn)vscf_ed25519_public_key_produce_alg_info,
    //
    //  Restore algorithm configuration from the given object.
    //
    (vscf_alg_api_restore_alg_info_fn)vscf_ed25519_public_key_restore_alg_info
};

//
//  Configuration of the interface API 'key api'.
//
static const vscf_key_api_t key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'key' MUST be equal to the 'vscf_api_tag_KEY'.
    //
    vscf_api_tag_KEY,
    //
    //  Link to the inherited interface API 'alg'.
    //
    &alg_api,
    //
    //  Length of the key in bytes.
    //
    (vscf_key_api_key_len_fn)vscf_ed25519_public_key_key_len,
    //
    //  Length of the key in bits.
    //
    (vscf_key_api_key_bitlen_fn)vscf_ed25519_public_key_key_bitlen
};

//
//  Configuration of the interface API 'encrypt api'.
//
static const vscf_encrypt_api_t encrypt_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'encrypt' MUST be equal to the 'vscf_api_tag_ENCRYPT'.
    //
    vscf_api_tag_ENCRYPT,
    //
    //  Encrypt given data.
    //
    (vscf_encrypt_api_encrypt_fn)vscf_ed25519_public_key_encrypt,
    //
    //  Calculate required buffer length to hold the encrypted data.
    //
    (vscf_encrypt_api_encrypted_len_fn)vscf_ed25519_public_key_encrypted_len
};

//
//  Configuration of the interface API 'verify hash api'.
//
static const vscf_verify_hash_api_t verify_hash_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'verify_hash' MUST be equal to the 'vscf_api_tag_VERIFY_HASH'.
    //
    vscf_api_tag_VERIFY_HASH,
    //
    //  Verify data with given public key and signature.
    //
    (vscf_verify_hash_api_verify_hash_fn)vscf_ed25519_public_key_verify_hash
};

//
//  Configuration of the interface API 'public key api'.
//
static const vscf_public_key_api_t public_key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'public_key' MUST be equal to the 'vscf_api_tag_PUBLIC_KEY'.
    //
    vscf_api_tag_PUBLIC_KEY,
    //
    //  Link to the inherited interface API 'key'.
    //
    &key_api,
    //
    //  Export public key in the binary format.
    //
    //  Binary format must be defined in the key specification.
    //  For instance, RSA public key must be exported in format defined in
    //  RFC 3447 Appendix A.1.1.
    //
    (vscf_public_key_api_export_public_key_fn)vscf_ed25519_public_key_export_public_key,
    //
    //  Return length in bytes required to hold exported public key.
    //
    (vscf_public_key_api_exported_public_key_len_fn)vscf_ed25519_public_key_exported_public_key_len,
    //
    //  Import public key from the binary format.
    //
    //  Binary format must be defined in the key specification.
    //  For instance, RSA public key must be imported from the format defined in
    //  RFC 3447 Appendix A.1.1.
    //
    (vscf_public_key_api_import_public_key_fn)vscf_ed25519_public_key_import_public_key,
    //
    //  Define whether a public key can be exported or not.
    //
    vscf_ed25519_public_key_CAN_EXPORT_PUBLIC_KEY,
    //
    //  Defines whether a public key can be imported or not.
    //
    vscf_ed25519_public_key_CAN_IMPORT_PUBLIC_KEY
};

//
//  Configuration of the interface API 'generate ephemeral key api'.
//
static const vscf_generate_ephemeral_key_api_t generate_ephemeral_key_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'generate_ephemeral_key' MUST be equal to the 'vscf_api_tag_GENERATE_EPHEMERAL_KEY'.
    //
    vscf_api_tag_GENERATE_EPHEMERAL_KEY,
    //
    //  Generate ephemeral private key of the same type.
    //
    (vscf_generate_ephemeral_key_api_generate_ephemeral_key_fn)vscf_ed25519_public_key_generate_ephemeral_key
};

//
//  Compile-time known information about 'ed25519 public key' implementation.
//
static const vscf_impl_info_t info = {
    //
    //  Callback that returns API of the requested interface if implemented, otherwise - NULL.
    //  MUST be second in the structure.
    //
    vscf_ed25519_public_key_find_api,
    //
    //  Release acquired inner resources.
    //
    (vscf_impl_cleanup_fn)vscf_ed25519_public_key_cleanup,
    //
    //  Self destruction, according to destruction policy.
    //
    (vscf_impl_delete_fn)vscf_ed25519_public_key_delete
};

//
//  Perform initialization of preallocated implementation context.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_init(vscf_ed25519_public_key_t *self) {

    VSCF_ASSERT_PTR(self);

    vscf_zeroize(self, sizeof(vscf_ed25519_public_key_t));

    self->info = &info;
    self->refcnt = 1;

    vscf_ed25519_public_key_init_ctx(self);
}

//
//  Cleanup implementation context and release dependencies.
//  This is a reverse action of the function 'vscf_ed25519_public_key_init()'.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_cleanup(vscf_ed25519_public_key_t *self) {

    if (self == NULL || self->info == NULL) {
        return;
    }

    if (self->refcnt == 0) {
        return;
    }

    if (--self->refcnt > 0) {
        return;
    }

    vscf_ed25519_public_key_release_random(self);
    vscf_ed25519_public_key_release_ecies(self);

    vscf_ed25519_public_key_cleanup_ctx(self);

    vscf_zeroize(self, sizeof(vscf_ed25519_public_key_t));
}

//
//  Allocate implementation context and perform it's initialization.
//  Postcondition: check memory allocation result.
//
VSCF_PUBLIC vscf_ed25519_public_key_t *
vscf_ed25519_public_key_new(void) {

    vscf_ed25519_public_key_t *self = (vscf_ed25519_public_key_t *) vscf_alloc(sizeof (vscf_ed25519_public_key_t));
    VSCF_ASSERT_ALLOC(self);

    vscf_ed25519_public_key_init(self);

    return self;
}

//
//  Delete given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_ed25519_public_key_new()'.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_delete(vscf_ed25519_public_key_t *self) {

    vscf_ed25519_public_key_cleanup(self);

    if (self && (self->refcnt == 0)) {
        vscf_dealloc(self);
    }
}

//
//  Destroy given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_ed25519_public_key_new()'.
//  Given reference is nullified.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_destroy(vscf_ed25519_public_key_t **self_ref) {

    VSCF_ASSERT_PTR(self_ref);

    vscf_ed25519_public_key_t *self = *self_ref;
    *self_ref = NULL;

    vscf_ed25519_public_key_delete(self);
}

//
//  Copy given implementation context by increasing reference counter.
//  If deep copy is required interface 'clonable' can be used.
//
VSCF_PUBLIC vscf_ed25519_public_key_t *
vscf_ed25519_public_key_shallow_copy(vscf_ed25519_public_key_t *self) {

    // Proxy to the parent implementation.
    return (vscf_ed25519_public_key_t *)vscf_impl_shallow_copy((vscf_impl_t *)self);
}

//
//  Return size of 'vscf_ed25519_public_key_t' type.
//
VSCF_PUBLIC size_t
vscf_ed25519_public_key_impl_size(void) {

    return sizeof (vscf_ed25519_public_key_t);
}

//
//  Cast to the 'vscf_impl_t' type.
//
VSCF_PUBLIC vscf_impl_t *
vscf_ed25519_public_key_impl(vscf_ed25519_public_key_t *self) {

    VSCF_ASSERT_PTR(self);
    return (vscf_impl_t *)(self);
}

//
//  Setup dependency to the interface 'random' with shared ownership.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_use_random(vscf_ed25519_public_key_t *self, vscf_impl_t *random) {

    VSCF_ASSERT_PTR(self);
    VSCF_ASSERT_PTR(random);
    VSCF_ASSERT(self->random == NULL);

    VSCF_ASSERT(vscf_random_is_implemented(random));

    self->random = vscf_impl_shallow_copy(random);
}

//
//  Setup dependency to the interface 'random' and transfer ownership.
//  Note, transfer ownership does not mean that object is uniquely owned by the target object.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_take_random(vscf_ed25519_public_key_t *self, vscf_impl_t *random) {

    VSCF_ASSERT_PTR(self);
    VSCF_ASSERT_PTR(random);
    VSCF_ASSERT_PTR(self->random == NULL);

    VSCF_ASSERT(vscf_random_is_implemented(random));

    self->random = random;
}

//
//  Release dependency to the interface 'random'.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_release_random(vscf_ed25519_public_key_t *self) {

    VSCF_ASSERT_PTR(self);

    vscf_impl_destroy(&self->random);
}

//
//  Setup dependency to the implementation 'ecies' with shared ownership.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_use_ecies(vscf_ed25519_public_key_t *self, vscf_ecies_t *ecies) {

    VSCF_ASSERT_PTR(self);
    VSCF_ASSERT_PTR(ecies);
    VSCF_ASSERT(self->ecies == NULL);

    self->ecies = vscf_ecies_shallow_copy(ecies);
}

//
//  Setup dependency to the implementation 'ecies' and transfer ownership.
//  Note, transfer ownership does not mean that object is uniquely owned by the target object.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_take_ecies(vscf_ed25519_public_key_t *self, vscf_ecies_t *ecies) {

    VSCF_ASSERT_PTR(self);
    VSCF_ASSERT_PTR(ecies);
    VSCF_ASSERT_PTR(self->ecies == NULL);

    self->ecies = ecies;
}

//
//  Release dependency to the implementation 'ecies'.
//
VSCF_PUBLIC void
vscf_ed25519_public_key_release_ecies(vscf_ed25519_public_key_t *self) {

    VSCF_ASSERT_PTR(self);

    vscf_ecies_destroy(&self->ecies);
}

static const vscf_api_t *
vscf_ed25519_public_key_find_api(vscf_api_tag_t api_tag) {

    switch(api_tag) {
        case vscf_api_tag_ALG:
            return (const vscf_api_t *) &alg_api;
        case vscf_api_tag_DEFAULTS:
            return (const vscf_api_t *) &defaults_api;
        case vscf_api_tag_ENCRYPT:
            return (const vscf_api_t *) &encrypt_api;
        case vscf_api_tag_GENERATE_EPHEMERAL_KEY:
            return (const vscf_api_t *) &generate_ephemeral_key_api;
        case vscf_api_tag_KEY:
            return (const vscf_api_t *) &key_api;
        case vscf_api_tag_PUBLIC_KEY:
            return (const vscf_api_t *) &public_key_api;
        case vscf_api_tag_VERIFY_HASH:
            return (const vscf_api_t *) &verify_hash_api;
        default:
            return NULL;
    }
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end
