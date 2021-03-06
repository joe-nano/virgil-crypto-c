/**
 * Copyright (C) 2015-2020 Virgil Security, Inc.
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


const precondition = require('./precondition');

const initRatchetGroupParticipantsInfo = (Module, modules) => {
    /**
     * Container for array of participants' info
     */
    class RatchetGroupParticipantsInfo {

        /**
         * Create object with underlying C context.
         *
         * Note. Parameter 'ctxPtr' SHOULD be passed from the generated code only.
         */
        constructor(ctxPtr) {
            this.name = 'RatchetGroupParticipantsInfo';

            if (typeof ctxPtr === 'undefined') {
                this.ctxPtr = Module._vscr_ratchet_group_participants_info_new();
            } else {
                this.ctxPtr = ctxPtr;
            }
        }

        /**
         * Acquire C context by making it's shallow copy.
         *
         * Note. This method is used in generated code only, and SHOULD NOT be used in another way.
         */
        static newAndUseCContext(ctxPtr) {
            // assert(typeof ctxPtr === 'number');
            return new RatchetGroupParticipantsInfo(Module._vscr_ratchet_group_participants_info_shallow_copy(ctxPtr));
        }

        /**
         * Acquire C context by taking it ownership.
         *
         * Note. This method is used in generated code only, and SHOULD NOT be used in another way.
         */
        static newAndTakeCContext(ctxPtr) {
            // assert(typeof ctxPtr === 'number');
            return new RatchetGroupParticipantsInfo(ctxPtr);
        }

        /**
         * Release underlying C context.
         */
        delete() {
            if (typeof this.ctxPtr !== 'undefined' && this.ctxPtr !== null) {
                Module._vscr_ratchet_group_participants_info_delete(this.ctxPtr);
                this.ctxPtr = null;
            }
        }

        /**
         * Creates new array for size elements
         */
        static newSize(size) {
            precondition.ensureNumber('size', size);

            let proxyResult;
            proxyResult = Module._vscr_ratchet_group_participants_info_new_size(size);

            const jsResult = RatchetGroupParticipantsInfo.newAndTakeCContext(proxyResult);
            return jsResult;
        }

        /**
         * Add participant info
         */
        addParticipant(id, pubKey) {
            precondition.ensureNotNull('this.ctxPtr', this.ctxPtr);
            precondition.ensureByteArray('id', id);
            precondition.ensureByteArray('pubKey', pubKey);

            //  Copy bytes from JS memory to the WASM memory.
            const idSize = id.length * id.BYTES_PER_ELEMENT;
            const idPtr = Module._malloc(idSize);
            Module.HEAP8.set(id, idPtr);

            //  Create C structure vsc_data_t.
            const idCtxSize = Module._vsc_data_ctx_size();
            const idCtxPtr = Module._malloc(idCtxSize);

            //  Point created vsc_data_t object to the copied bytes.
            Module._vsc_data(idCtxPtr, idPtr, idSize);

            //  Copy bytes from JS memory to the WASM memory.
            const pubKeySize = pubKey.length * pubKey.BYTES_PER_ELEMENT;
            const pubKeyPtr = Module._malloc(pubKeySize);
            Module.HEAP8.set(pubKey, pubKeyPtr);

            //  Create C structure vsc_data_t.
            const pubKeyCtxSize = Module._vsc_data_ctx_size();
            const pubKeyCtxPtr = Module._malloc(pubKeyCtxSize);

            //  Point created vsc_data_t object to the copied bytes.
            Module._vsc_data(pubKeyCtxPtr, pubKeyPtr, pubKeySize);

            try {
                const proxyResult = Module._vscr_ratchet_group_participants_info_add_participant(this.ctxPtr, idCtxPtr, pubKeyCtxPtr);
                modules.RatchetError.handleStatusCode(proxyResult);
            } finally {
                Module._free(idPtr);
                Module._free(idCtxPtr);
                Module._free(pubKeyPtr);
                Module._free(pubKeyCtxPtr);
            }
        }
    }

    return RatchetGroupParticipantsInfo;
};

module.exports = initRatchetGroupParticipantsInfo;
