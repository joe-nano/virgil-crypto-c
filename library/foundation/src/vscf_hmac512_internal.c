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
//  This module contains logic for interface/implementation architecture.
//  Do not use this module in any part of the code.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_hmac512_internal.h"
#include "vscf_memory.h"
#include "vscf_assert.h"
#include "vscf_hmac512.h"
#include "vscf_hmac512_impl.h"
#include "vscf_hmac_info_api.h"
#include "vscf_hmac_api.h"
#include "vscf_hmac_stream_api.h"
//  @end


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Configuration of the interface API 'hmac info api'.
//
static const vscf_hmac_info_api_t hmac_info_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'hmac_info' MUST be equal to the 'vscf_api_tag_HMAC_INFO'.
    //
    vscf_api_tag_HMAC_INFO,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_HMAC512,
    //
    //  Size of the digest (hmac output) in bytes.
    //
    vscf_hmac512_DIGEST_LEN
};

//
//  Configuration of the interface API 'hmac api'.
//
static const vscf_hmac_api_t hmac_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'hmac' MUST be equal to the 'vscf_api_tag_HMAC'.
    //
    vscf_api_tag_HMAC,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_HMAC512,
    //
    //  Link to the inherited interface API 'hmac info'.
    //
    &hmac_info_api,
    //
    //  Calculate hmac over given data.
    //
    (vscf_hmac_api_hmac_fn)vscf_hmac512_hmac
};

//
//  Configuration of the interface API 'hmac stream api'.
//
static const vscf_hmac_stream_api_t hmac_stream_api = {
    //
    //  API's unique identifier, MUST be first in the structure.
    //  For interface 'hmac_stream' MUST be equal to the 'vscf_api_tag_HMAC_STREAM'.
    //
    vscf_api_tag_HMAC_STREAM,
    //
    //  Implementation unique identifier, MUST be second in the structure.
    //
    vscf_impl_tag_HMAC512,
    //
    //  Link to the inherited interface API 'hmac info'.
    //
    &hmac_info_api,
    //
    //  Reset HMAC.
    //
    (vscf_hmac_stream_api_reset_fn)vscf_hmac512_reset,
    //
    //  Start a new HMAC.
    //
    (vscf_hmac_stream_api_start_fn)vscf_hmac512_start,
    //
    //  Add given data to the HMAC.
    //
    (vscf_hmac_stream_api_update_fn)vscf_hmac512_update,
    //
    //  Accompilsh HMAC and return it's result (a message digest).
    //
    (vscf_hmac_stream_api_finish_fn)vscf_hmac512_finish
};

//
//  Null-terminated array of the implemented 'Interface API' instances.
//
static const vscf_api_t *api_array[] = {
    (const vscf_api_t *)&hmac_info_api,
    (const vscf_api_t *)&hmac_api,
    (const vscf_api_t *)&hmac_stream_api,
    NULL
};

//
//  Compile-time known information about 'hmac512' implementation.
//
static const vscf_impl_info_t info = {
    //
    //  Implementation unique identifier, MUST be first in the structure.
    //
    vscf_impl_tag_HMAC512,
    //
    //  NULL terminated array of the implemented interfaces.
    //  MUST be second in the structure.
    //
    api_array,
    //
    //  Release acquired inner resources.
    //
    (vscf_impl_cleanup_fn)vscf_hmac512_cleanup,
    //
    //  Self destruction, according to destruction policy.
    //
    (vscf_impl_delete_fn)vscf_hmac512_delete
};

//
//  Perform initialization of preallocated implementation context.
//
VSCF_PUBLIC void
vscf_hmac512_init(vscf_hmac512_impl_t *hmac512_impl) {

    VSCF_ASSERT_PTR(hmac512_impl);
    VSCF_ASSERT_PTR(hmac512_impl->info == NULL);

    hmac512_impl->info = &info;

    vscf_hmac512_init_ctx(hmac512_impl);
}

//
//  Cleanup implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_hmac512_init()'.
//  All dependencies that is under ownership will be destroyed.
//  All dependencies that is not under ownership will untouched.
//
VSCF_PUBLIC void
vscf_hmac512_cleanup(vscf_hmac512_impl_t *hmac512_impl) {

    VSCF_ASSERT_PTR(hmac512_impl);

    if (hmac512_impl->info == NULL) {
        return;
    }

    vscf_hmac512_cleanup_ctx(hmac512_impl);

    hmac512_impl->info = NULL;
}

//
//  Allocate implementation context and perform it's initialization.
//  Postcondition: check memory allocation result.
//
VSCF_PUBLIC vscf_hmac512_impl_t *
vscf_hmac512_new(void) {

    vscf_hmac512_impl_t *hmac512_impl = (vscf_hmac512_impl_t *) vscf_alloc(sizeof (vscf_hmac512_impl_t));
    VSCF_ASSERT_ALLOC(hmac512_impl);

    vscf_hmac512_init(hmac512_impl);

    hmac512_impl->refcnt = 1;

    return hmac512_impl;
}

//
//  Delete given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_hmac512_new()'.
//  All dependencies that is not under ownership will be cleaned up.
//  All dependencies that is under ownership will be destroyed.
//
VSCF_PUBLIC void
vscf_hmac512_delete(vscf_hmac512_impl_t *hmac512_impl) {

    if (hmac512_impl && (--hmac512_impl->refcnt == 0)) {
        vscf_hmac512_cleanup(hmac512_impl);
        vscf_dealloc(hmac512_impl);
    }
}

//
//  Destroy given implementation context and it's dependencies.
//  This is a reverse action of the function 'vscf_hmac512_new()'.
//  All dependencies that is not under ownership will be cleaned up.
//  All dependencies that is under ownership will be destroyed.
//  Given reference is nullified.
//
VSCF_PUBLIC void
vscf_hmac512_destroy(vscf_hmac512_impl_t **hmac512_impl_ref) {

    VSCF_ASSERT_PTR(hmac512_impl_ref);

    vscf_hmac512_impl_t *hmac512_impl = *hmac512_impl_ref;
    *hmac512_impl_ref = NULL;

    vscf_hmac512_delete(hmac512_impl);
}

//
//  Copy given implementation context by increasing reference counter.
//  If deep copy is required interface 'clonable' can be used.
//
VSCF_PUBLIC vscf_hmac512_impl_t *
vscf_hmac512_copy(vscf_hmac512_impl_t *hmac512_impl) {

    // Proxy to the parent implementation.
    return (vscf_hmac512_impl_t *)vscf_impl_copy((vscf_impl_t *)hmac512_impl);
}

//
//  Returns instance of the implemented interface 'hmac info'.
//
VSCF_PUBLIC const vscf_hmac_info_api_t *
vscf_hmac512_hmac_info_api(void) {

    return &hmac_info_api;
}

//
//  Returns instance of the implemented interface 'hmac'.
//
VSCF_PUBLIC const vscf_hmac_api_t *
vscf_hmac512_hmac_api(void) {

    return &hmac_api;
}

//
//  Return size of 'vscf_hmac512_impl_t' type.
//
VSCF_PUBLIC size_t
vscf_hmac512_impl_size(void) {

    return sizeof (vscf_hmac512_impl_t);
}

//
//  Cast to the 'vscf_impl_t' type.
//
VSCF_PUBLIC vscf_impl_t *
vscf_hmac512_impl(vscf_hmac512_impl_t *hmac512_impl) {

    VSCF_ASSERT_PTR(hmac512_impl);
    return (vscf_impl_t *)(hmac512_impl);
}


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end
