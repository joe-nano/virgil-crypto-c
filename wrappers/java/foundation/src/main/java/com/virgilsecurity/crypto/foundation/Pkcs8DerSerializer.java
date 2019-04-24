/*
* Copyright (C) 2015-2019 Virgil Security, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
* (1) Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
*
* (2) Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in
* the documentation and/or other materials provided with the
* distribution.
*
* (3) Neither the name of the copyright holder nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
*/

package com.virgilsecurity.crypto.foundation;

/*
* Implements PKCS#8 key serialization to DER format.
*/
public class Pkcs8DerSerializer implements AutoCloseable, KeySerializer {

    public long cCtx;

    /* Create underlying C context. */
    public Pkcs8DerSerializer() {
        super();
        this.cCtx = FoundationJNI.INSTANCE.pkcs8DerSerializer_new();
    }

    /*
    * Acquire C context.
    * Note. This method is used in generated code only, and SHOULD NOT be used in another way.
    */
    public Pkcs8DerSerializer(long cCtx) {
        super();
        this.cCtx = cCtx;
    }

    public void setAsn1Writer(Asn1Writer asn1Writer) {
        FoundationJNI.INSTANCE.pkcs8DerSerializer_setAsn1Writer(this.cCtx, asn1Writer);
    }

    /*
    * Setup predefined values to the uninitialized class dependencies.
    */
    public void setupDefaults() {
        FoundationJNI.INSTANCE.pkcs8DerSerializer_setupDefaults(this.cCtx);
    }

    /*
    * Serialize Public Key by using internal ASN.1 writer.
    * Note, that caller code is responsible to reset ASN.1 writer with
    * an output buffer.
    */
    public int serializePublicKeyInplace(PublicKey publicKey) throws FoundationException {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializePublicKeyInplace(this.cCtx, publicKey);
    }

    /*
    * Serialize Private Key by using internal ASN.1 writer.
    * Note, that caller code is responsible to reset ASN.1 writer with
    * an output buffer.
    */
    public int serializePrivateKeyInplace(PrivateKey privateKey) throws FoundationException {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializePrivateKeyInplace(this.cCtx, privateKey);
    }

    /* Close resource. */
    public void close() {
        FoundationJNI.INSTANCE.pkcs8DerSerializer_close(this.cCtx);
    }

    /*
    * Calculate buffer size enough to hold serialized public key.
    *
    * Precondition: public key must be exportable.
    */
    public int serializedPublicKeyLen(PublicKey publicKey) {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializedPublicKeyLen(this.cCtx, publicKey);
    }

    /*
    * Serialize given public key to an interchangeable format.
    *
    * Precondition: public key must be exportable.
    */
    public byte[] serializePublicKey(PublicKey publicKey) throws FoundationException {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializePublicKey(this.cCtx, publicKey);
    }

    /*
    * Calculate buffer size enough to hold serialized private key.
    *
    * Precondition: private key must be exportable.
    */
    public int serializedPrivateKeyLen(PrivateKey privateKey) {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializedPrivateKeyLen(this.cCtx, privateKey);
    }

    /*
    * Serialize given private key to an interchangeable format.
    *
    * Precondition: private key must be exportable.
    */
    public byte[] serializePrivateKey(PrivateKey privateKey) throws FoundationException {
        return FoundationJNI.INSTANCE.pkcs8DerSerializer_serializePrivateKey(this.cCtx, privateKey);
    }
}
