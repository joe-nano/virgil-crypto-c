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


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#ifndef VSCR_RATCHET_H_INCLUDED
#define VSCR_RATCHET_H_INCLUDED

#include "vscr_library.h"
#include "vscr_error.h"
#include "vscr_ratchet_common.h"
#include "vscr_olm_message.h"
#include "vscr_olm_message_key.h"
#include "vscr_olm_kdf_info.h"
#include "vscr_olm_sender_chain.h"
#include "vscr_olm_chain_key.h"
#include "vscr_olm_cipher.h"
#include "vscr_olm_receiver_chain_list_node.h"
#include "vscr_olm_skipped_message_key_list_node.h"

#include <virgil/foundation/vscf_hmac256.h>
#include <virgil/foundation/vscf_hkdf.h>
#include <virgil/common/vsc_data.h>
#include <virgil/common/vsc_buffer.h>
//  @end


#ifdef __cplusplus
extern "C" {
#endif


//  @generated
// --------------------------------------------------------------------------
// clang-format off
//  Generated section start.
// --------------------------------------------------------------------------

//
//  Public integral constants.
//
enum {
    vscr_ratchet_OLM_MESSAGE_VERSION = 1,
    vscr_ratchet_OLM_SHARED_KEY_LENGTH = vscf_hmac256_DIGEST_LEN,
    vscr_ratchet_MAX_SKIPPED_MESSAGED = 40,
    vscr_ratchet_MAX_RECEIVERS_CHAINS = 5,
    vscr_ratchet_MAX_MESSAGE_GAP = 2000
};

//
//  Handle 'ratchet' context.
//
typedef struct vscr_ratchet_t vscr_ratchet_t;
struct vscr_ratchet_t {
    //
    //  Function do deallocate self context.
    //
    vscr_dealloc_fn self_dealloc_cb;
    //
    //  Reference counter.
    //
    size_t refcnt;

    vscr_olm_cipher_t *cipher;

    vscr_olm_kdf_info_t *kdf_info;

    vscr_olm_sender_chain_t *sender_chain;

    vscr_olm_receiver_chain_list_node_t *receiver_chains;

    vscr_olm_skipped_message_key_list_node_t *skipped_message_keys;

    byte root_key[vscr_ratchet_common_OLM_SHARED_KEY_LENGTH];
};

//
//  Perform initialization of pre-allocated context.
//
VSCR_PUBLIC void
vscr_ratchet_init(vscr_ratchet_t *ratchet_ctx);

//
//  Release all inner resources including class dependencies.
//
VSCR_PUBLIC void
vscr_ratchet_cleanup(vscr_ratchet_t *ratchet_ctx);

//
//  Allocate context and perform it's initialization.
//
VSCR_PUBLIC vscr_ratchet_t *
vscr_ratchet_new(void);

//
//  Release all inner resources and deallocate context if needed.
//  It is safe to call this method even if context was allocated by the caller.
//
VSCR_PUBLIC void
vscr_ratchet_delete(vscr_ratchet_t *ratchet_ctx);

//
//  Delete given context and nullifies reference.
//  This is a reverse action of the function 'vscr_ratchet_new ()'.
//
VSCR_PUBLIC void
vscr_ratchet_destroy(vscr_ratchet_t **ratchet_ctx_ref);

//
//  Copy given class context by increasing reference counter.
//
VSCR_PUBLIC vscr_ratchet_t *
vscr_ratchet_copy(vscr_ratchet_t *ratchet_ctx);

VSCR_PUBLIC void
vscr_ratchet_respond(vscr_ratchet_t *ratchet_ctx, vsc_data_t shared_secret, vsc_buffer_t *ratchet_public_key);

VSCR_PUBLIC void
vscr_ratchet_initiate(vscr_ratchet_t *ratchet_ctx, vsc_data_t shared_secret, vsc_buffer_t *ratchet_private_key);

VSCR_PUBLIC size_t
vscr_ratchet_encrypt_len(vscr_ratchet_t *ratchet_ctx, vsc_data_t plain_text);

VSCR_PUBLIC vscr_error_t
vscr_ratchet_encrypt(vscr_ratchet_t *ratchet_ctx, vsc_data_t plain_text, vsc_buffer_t *cipher_text);

VSCR_PUBLIC size_t
vscr_ratchet_decrypt_len(vscr_ratchet_t *ratchet_ctx, vsc_data_t cipher_text);

VSCR_PUBLIC vscr_error_t
vscr_ratchet_decrypt(vscr_ratchet_t *ratchet_ctx, vsc_data_t cipher_text, vsc_buffer_t *plain_text);


// --------------------------------------------------------------------------
//  Generated section end.
// clang-format on
// --------------------------------------------------------------------------
//  @end


#ifdef __cplusplus
}
#endif


//  @footer
#endif // VSCR_RATCHET_H_INCLUDED
//  @end
