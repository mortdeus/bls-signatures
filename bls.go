package bls

/*
#cgo CFLAGS: -Isrc
#cgo LDFLAGS: -Lsrc
#include "src/bls_cgo.h"
*/
import "C"

type Key struct {
}

func NewKey() *Key {
	C.blsPrivateKeyFromSeed(nil, nil, 0)
	return nil
}
