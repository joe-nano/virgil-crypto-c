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
// clang-format off


//  @description
// --------------------------------------------------------------------------
//  This module contains 'ed25519 private key' implementation.
// --------------------------------------------------------------------------


//  @warning
// --------------------------------------------------------------------------
//  This file is partially generated.
//  Generated blocks are enclosed between tags [@<tag>, @end].
//  User's code can be added between tags [@end, @<tag>].
// --------------------------------------------------------------------------

#include "vscf_ed25519_private_key.h"
#include "vscf_assert.h"
#include "vscf_memory.h"
#include "vscf_ed25519_private_key_impl.h"
#include "vscf_ed25519_private_key_internal.h"

// clang-format on
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

static uint32_t get_tick()
{
    struct timespec ts;
    uint32_t tick = 0U;
    clock_gettime( CLOCK_REALTIME, &ts );
    tick  = ts.tv_nsec / 1000000;
    tick += ts.tv_sec * 1000;
    return tick;
}

//
//  Provides initialization of the implementation specific context.
//  Note, this method is called automatically when method vscf_ed25519_private_key_init() is called.
//  Note, that context is already zeroed.
//
VSCF_PRIVATE void
vscf_ed25519_private_key_init_ctx(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

	VSCF_ASSERT_PTR(ed25519_private_key_impl);
	memset(ed25519_private_key_impl, 0, sizeof(vscf_ed25519_private_key_impl_t));
}

//
//  Release resources of the implementation specific context.
//  Note, this method is called automatically once when class is completely cleaning up.
//  Note, that context will be zeroed automatically next this method.
//
VSCF_PRIVATE void
vscf_ed25519_private_key_cleanup_ctx(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

	VSCF_ASSERT_PTR(ed25519_private_key_impl);
	memset(ed25519_private_key_impl, 0, sizeof(vscf_ed25519_private_key_impl_t));
}

//
//  Length of the key in bytes.
//
VSCF_PUBLIC size_t
vscf_ed25519_private_key_key_len(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

  VSCF_ASSERT_PTR(ed25519_private_key_impl);
  return (sizeof(ed25519_private_key_impl->secret_key));
}

//
//  Length of the key in bits.
//
VSCF_PUBLIC size_t
vscf_ed25519_private_key_key_bitlen(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

  VSCF_ASSERT_PTR(ed25519_private_key_impl);
	return (8*sizeof(ed25519_private_key_impl->secret_key));
}

//
//  Generate new private or secret key.
//  Note, this operation can be slow.
//
VSCF_PUBLIC vscf_error_t
vscf_ed25519_private_key_generate_key(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

  VSCF_ASSERT_PTR(ed25519_private_key_impl);
	srand(get_tick());
	for(int i = 0; i < ED25519_KEY_LEN; i++) {
		ed25519_private_key_impl->secret_key[i] = rand();
	}
	ed25519_private_key_impl->secret_key[0] &= 248;
	ed25519_private_key_impl->secret_key[ED25519_KEY_LEN-1] &= 127;
	ed25519_private_key_impl->secret_key[ED25519_KEY_LEN-1] |= 64;
	return vscf_SUCCESS;
}

//
//  Extract public part of the key.
//
VSCF_PUBLIC vscf_impl_t *
vscf_ed25519_private_key_extract_public_key(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

  VSCF_ASSERT_PTR(ed25519_private_key_impl);
  vscf_ed25519_public_key_impl_t * ed25519_public_key_impl = vscf_ed25519_public_key_new();
  VSCF_ASSERT_ALLOC(ed25519_public_key_impl != NULL);
  (void)ed25519_get_pubkey(ed25519_public_key_impl->public_key, ed25519_private_key_impl->secret_key);
  memcpy(ed25519_public_key_impl->signature, ed25519_private_key_impl->signature, sizeof(ed25519_private_key_impl->signature));
  return vscf_ed25519_public_key_impl_t(ed25519_public_key_impl);
}

//
//  Decrypt given data.
//
VSCF_PUBLIC vscf_error_t
vscf_ed25519_private_key_decrypt(
        vscf_ed25519_private_key_impl_t *ed25519_private_key_impl, vsc_data_t data, vsc_buffer_t *out) {

    //  TODO: This is STUB. Implement me.
		// will add in the feature
}

//
//  Calculate required buffer length to hold the decrypted data.
//
VSCF_PUBLIC size_t
vscf_ed25519_private_key_decrypted_len(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl, size_t data_len) {

    //  TODO: This is STUB. Implement me.
}

//
//  Sign data given private key.
//
VSCF_PUBLIC vscf_error_t
vscf_ed25519_private_key_sign(
        vscf_ed25519_private_key_impl_t *ed25519_private_key_impl, vsc_data_t data, vsc_buffer_t *signature) {

    VSCF_ASSERT_PTR(ed25519_private_key_impl);
    VSCF_ASSERT_PTR(signature);
    VSCF_ASSERT_PTR(data.bytes);
    (void)ed25519_sign(ed25519_private_key_impl->signature, signature.bytes, data.bytes, data.len);
    return vscf_SUCCESS;
}

//
//  Return length in bytes required to hold signature.
//
VSCF_PUBLIC size_t
vscf_ed25519_private_key_signature_len(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

    return (sizeof(ed25519_private_key_impl->signature));
}

//
//  Export private key in the binary format.
//
VSCF_PUBLIC vscf_error_t
vscf_ed25519_private_key_export_private_key(
        vscf_ed25519_private_key_impl_t *ed25519_private_key_impl, vsc_buffer_t *out) {

    VSCF_ASSERT_PTR(ed25519_private_key_impl);
    VSCF_ASSERT(vsc_buffer_is_valid(out));
    
}

//
//  Return length in bytes required to hold exported private key.
//
VSCF_PUBLIC size_t
vscf_ed25519_private_key_exported_private_key_len(vscf_ed25519_private_key_impl_t *ed25519_private_key_impl) {

    //  TODO: This is STUB. Implement me.
}

//
//  Import private key from the binary format.
//
VSCF_PUBLIC vscf_error_t
vscf_ed25519_private_key_import_private_key(
        vscf_ed25519_private_key_impl_t *ed25519_private_key_impl, vsc_data_t data) {

    VSCF_ASSERT_PTR(ed25519_private_key_impl);
    VSCF_ASSERT_PTR(data.bytes);

}
