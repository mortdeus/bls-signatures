#include "bls_cgo.h"
#include "bls.hpp"

using namespace bls;

static PrivateKey *cast(blsPrivateKey *p) { return reinterpret_cast<PrivateKey*>(p); }
static const PrivateKey *cast(const blsPrivateKey *p) { return reinterpret_cast<const PrivateKey*>(p); }

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen) {
    cast(priv)->FromSeed(seed, seedLen);
}

void blsPrivateKeyFromBytes(blsPrivateKey *priv, const uint8_t* bytes, bool modOrder) {
    cast(priv)->FromBytes(bytes, modOrder);
}