package foundation

// #cgo CFLAGS: -I${SRCDIR}/../binaries/include/
// #cgo LDFLAGS: -L${SRCDIR}/../binaries/lib -lvsc_foundation -lvsc_foundation_pb -led25519 -lprotobuf-nanopb -lvsc_common -lmbedcrypto
// #include <virgil/crypto/foundation/vscf_foundation_public.h>
import "C"


/*
* Add and/or remove recipients and it's parameters within message info.
*
* Usage:
* 1. Unpack binary message info that was obtained from RecipientCipher.
* 2. Add and/or remove key recipients.
* 3. Pack MessagInfo to the binary data.
*/
type MessageInfoEditor struct {
    cCtx *C.vscf_message_info_editor_t /*ct2*/
}

/* Handle underlying C context. */
func (obj *MessageInfoEditor) ctx () *C.vscf_impl_t {
    return (*C.vscf_impl_t)(obj.cCtx)
}

func NewMessageInfoEditor () *MessageInfoEditor {
    ctx := C.vscf_message_info_editor_new()
    return &MessageInfoEditor {
        cCtx: ctx,
    }
}

/* Acquire C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newMessageInfoEditorWithCtx (ctx *C.vscf_message_info_editor_t /*ct2*/) *MessageInfoEditor {
    return &MessageInfoEditor {
        cCtx: ctx,
    }
}

/* Acquire retained C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newMessageInfoEditorCopy (ctx *C.vscf_message_info_editor_t /*ct2*/) *MessageInfoEditor {
    return &MessageInfoEditor {
        cCtx: C.vscf_message_info_editor_shallow_copy(ctx),
    }
}

/*
* Release underlying C context.
*/
func (obj *MessageInfoEditor) Delete () {
    C.vscf_message_info_editor_delete(obj.cCtx)
}

func (obj *MessageInfoEditor) SetRandom (random IRandom) {
    C.vscf_message_info_editor_release_random(obj.cCtx)
    C.vscf_message_info_editor_use_random(obj.cCtx, (*C.vscf_impl_t)(random.ctx()))
}

/*
* Set dependencies to it's defaults.
*/
func (obj *MessageInfoEditor) SetupDefaults () error {
    proxyResult := /*pr4*/C.vscf_message_info_editor_setup_defaults(obj.cCtx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Unpack serialized message info.
*
* Note that recipients can only be removed but not added.
* Note, use "unlock" method to be able to add new recipients as well.
*/
func (obj *MessageInfoEditor) Unpack (messageInfoData []byte) error {
    messageInfoDataData := helperWrapData (messageInfoData)

    proxyResult := /*pr4*/C.vscf_message_info_editor_unpack(obj.cCtx, messageInfoDataData)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Decrypt encryption key this allows adding new recipients.
*/
func (obj *MessageInfoEditor) Unlock (ownerRecipientId []byte, ownerPrivateKey IPrivateKey) error {
    ownerRecipientIdData := helperWrapData (ownerRecipientId)

    proxyResult := /*pr4*/C.vscf_message_info_editor_unlock(obj.cCtx, ownerRecipientIdData, (*C.vscf_impl_t)(ownerPrivateKey.ctx()))

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Add recipient defined with id and public key.
*/
func (obj *MessageInfoEditor) AddKeyRecipient (recipientId []byte, publicKey IPublicKey) error {
    recipientIdData := helperWrapData (recipientId)

    proxyResult := /*pr4*/C.vscf_message_info_editor_add_key_recipient(obj.cCtx, recipientIdData, (*C.vscf_impl_t)(publicKey.ctx()))

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return err
    }

    return nil
}

/*
* Remove recipient with a given id.
* Return false if recipient with given id was not found.
*/
func (obj *MessageInfoEditor) RemoveKeyRecipient (recipientId []byte) bool {
    recipientIdData := helperWrapData (recipientId)

    proxyResult := /*pr4*/C.vscf_message_info_editor_remove_key_recipient(obj.cCtx, recipientIdData)

    return bool(proxyResult) /* r9 */
}

/*
* Remove all existent recipients.
*/
func (obj *MessageInfoEditor) RemoveAll () {
    C.vscf_message_info_editor_remove_all(obj.cCtx)

    return
}

/*
* Return length of serialized message info.
* Actual length can be obtained right after applying changes.
*/
func (obj *MessageInfoEditor) PackedLen () uint32 {
    proxyResult := /*pr4*/C.vscf_message_info_editor_packed_len(obj.cCtx)

    return uint32(proxyResult) /* r9 */
}

/*
* Return serialized message info.
* Precondition: this method can be called after "apply".
*/
func (obj *MessageInfoEditor) Pack () []byte {
    messageInfoBuf, messageInfoBufErr := bufferNewBuffer(int(obj.PackedLen() /* lg2 */))
    if messageInfoBufErr != nil {
        return nil
    }
    defer messageInfoBuf.Delete()


    C.vscf_message_info_editor_pack(obj.cCtx, messageInfoBuf.ctx)

    return messageInfoBuf.getData() /* r7 */
}
