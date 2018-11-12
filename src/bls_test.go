package bls

import "testing"

func TestPrivKey(t *testing.T) {
	var p *PrivateKey
	p.SetFromBytes([]byte{1, 1, 0, 1, 0, 1, 0})
}
