package bls

/*
#cgo CFLAGS: -I${SRCDIR}/src
#cgo LDFLAGS: -L${SRCDIR}/src
#include "src/bls_cgo.h"
*/
import "C"

type Key struct {
}

func NewKey() *Key {
	C.blsPrivateKeyFromSeed(nil, nil, 0)
	return nil
}
