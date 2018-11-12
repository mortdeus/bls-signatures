package bls

/*
#cgo CFLAGS:-I /home/zypherx/Desktop/Code/Cpp/prysmaticlabs/bls-signatures/contrib/relic/include -I /home/zypherx/Desktop/Code/Cpp/prysmaticlabs/bls-signatures/contrib/relic/src -I /home/zypherx/Desktop/Code/Cpp/prysmaticlabs/bls-signatures/contrib/relic/lib
#cgo CXXFLAGS: -std=c++11
#cgo LDFLAGS:-L/home/zypherx/Desktop/Code/Cpp/prysmaticlabs/bls-signatures/contrib/relic/lib -lrelic_s -lgmp -lstdc++
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

// SetFromBytes --
func (priv *PrivateKey) SetFromBytes() {
	C.blsPrivateKeyFromBytes(priv.getPointer())
}
