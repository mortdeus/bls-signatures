package bls

/*
#cgo CFLAGS:-I ../contrib/relic/include -I ../contrib/relic/core -I ../contrib/relic/lib
#cgo CXXFLAGS: -std=c++11
#cgo LDFLAGS:-L ../contrib/relic/lib -lrelic_s -lstdc++
#include "bls_cgo.hpp"
*/
import "C"
import "unsafe"

// PrivateKey --
type PrivateKey struct{}

func (priv *PrivateKey) getPointer() (p *C.blsPrivateKey) {
	// #nosec
	return (*C.blsPrivateKey)(unsafe.Pointer(priv))
}

// PublicKey --
func (priv *PrivateKey) PublicKey() (pub *C.blsPublicKey) {
	var pk *C.blsPublicKey
	C.blsGetPublicKey(unsafe.Pointer(pk), priv.getPointer())
	return pk
}
