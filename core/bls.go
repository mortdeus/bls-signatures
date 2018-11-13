package bls

/*
#cgo CFLAGS:-I ../contrib/relic/include -I ../contrib/core -I ../contrib/relic/lib
#cgo CXXFLAGS: -std=c++11
#cgo LDFLAGS:-L ../contrib/relic/lib -lrelic_s -lstdc++
#include "bls_cgo.hpp"
*/
import "C"
import "unsafe"

// PrivateKey --
type PrivateKey struct {
	key C.blsPrivateKey
}

func (priv *PrivateKey) getPointer() (p *C.blsPrivateKey) {
	// #nosec
	return (*C.blsPrivateKey)(unsafe.Pointer(priv))
}

// FromSeed --
func (priv *PrivateKey) FromSeed(seed []int) {
	C.blsPrivateKeyFromSeed(priv.getPointer(), (*C.uint8_t)(unsafe.Pointer(&seed[0])), (C.size_t)(len(seed)))
}

// Bytes --
func (priv *PrivateKey) Bytes() []byte {
	buf := make([]byte, 2048)
	// #nosec
	n := C.blsPrivateKeySerialize((*C.uint8_t)(unsafe.Pointer(&buf[0])), priv.getPointer())
	return buf[:n]
}
