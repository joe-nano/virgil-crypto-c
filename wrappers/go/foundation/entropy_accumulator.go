package foundation

// #cgo CFLAGS: -I${SRCDIR}/../binaries/include/
// #cgo LDFLAGS: -L${SRCDIR}/../binaries/lib -lvsc_foundation -lvsc_foundation_pb -led25519 -lprotobuf-nanopb -lvsc_common -lmbedcrypto
// #include <virgil/crypto/foundation/vscf_foundation_public.h>
import "C"


/*
* Implementation based on a simple entropy accumulator.
*/
type EntropyAccumulator struct {
    IEntropySource
    cCtx *C.vscf_entropy_accumulator_t /*ct10*/
}

func EntropyAccumulatorGetSourcesMax () uint32 {
    return 15
}

/*
* Setup predefined values to the uninitialized class dependencies.
*/
func (obj *EntropyAccumulator) SetupDefaults () {
    C.vscf_entropy_accumulator_setup_defaults(obj.cCtx)

    return
}

/*
* Add given entropy source to the accumulator.
* Threshold defines minimum number of bytes that must be gathered
* from the source during accumulation.
*/
func (obj *EntropyAccumulator) AddSource (source IEntropySource, threshold uint32) {
    C.vscf_entropy_accumulator_add_source(obj.cCtx, (*C.vscf_impl_t)(source.ctx()), (C.size_t)(threshold)/*pa10*/)

    return
}

/* Handle underlying C context. */
func (obj *EntropyAccumulator) ctx () *C.vscf_impl_t {
    return (*C.vscf_impl_t)(obj.cCtx)
}

func NewEntropyAccumulator () *EntropyAccumulator {
    ctx := C.vscf_entropy_accumulator_new()
    return &EntropyAccumulator {
        cCtx: ctx,
    }
}

/* Acquire C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newEntropyAccumulatorWithCtx (ctx *C.vscf_entropy_accumulator_t /*ct10*/) *EntropyAccumulator {
    return &EntropyAccumulator {
        cCtx: ctx,
    }
}

/* Acquire retained C context.
* Note. This method is used in generated code only, and SHOULD NOT be used in another way.
*/
func newEntropyAccumulatorCopy (ctx *C.vscf_entropy_accumulator_t /*ct10*/) *EntropyAccumulator {
    return &EntropyAccumulator {
        cCtx: C.vscf_entropy_accumulator_shallow_copy(ctx),
    }
}

/*
* Release underlying C context.
*/
func (obj *EntropyAccumulator) Delete () {
    C.vscf_entropy_accumulator_delete(obj.cCtx)
}

/*
* Defines that implemented source is strong.
*/
func (obj *EntropyAccumulator) IsStrong () bool {
    proxyResult := /*pr4*/C.vscf_entropy_accumulator_is_strong(obj.cCtx)

    return bool(proxyResult) /* r9 */
}

/*
* Gather entropy of the requested length.
*/
func (obj *EntropyAccumulator) Gather (len uint32) ([]byte, error) {
    outBuf, outBufErr := bufferNewBuffer(int(len))
    if outBufErr != nil {
        return nil, outBufErr
    }
    defer outBuf.Delete()


    proxyResult := /*pr4*/C.vscf_entropy_accumulator_gather(obj.cCtx, (C.size_t)(len)/*pa10*/, outBuf.ctx)

    err := FoundationErrorHandleStatus(proxyResult)
    if err != nil {
        return nil, err
    }

    return outBuf.getData() /* r7 */, nil
}
