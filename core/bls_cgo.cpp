#include <iostream>
#include "bls_cgo.hpp"
#include "bls.hpp"

using namespace bls;

static PrivateKey *cast(blsPrivateKey *p) { return reinterpret_cast<PrivateKey*>(p); }
static const PrivateKey *cast(const blsPrivateKey *p) { return reinterpret_cast<const PrivateKey*>(p); }

static PublicKey *cast(blsPublicKey *p) { return reinterpret_cast<PublicKey*>(p); }
static const PublicKey *cast(const blsPublicKey *p) { return reinterpret_cast<const PublicKey*>(p); }

static Signature *cast(blsSignature *p) { return reinterpret_cast<Signature*>(p); }
static const Signature *cast(const blsSignature *p) { return reinterpret_cast<const Signature*>(p); }

void blsPrivateKeyFromSeed(blsPrivateKey* priv, const uint8_t* seed, size_t seedLen) {
    cast(priv)->FromSeed(seed, seedLen);
}

int blsPrivateKeySerialize(uint8_t* buffer, blsPrivateKey *priv) {
    std::vector<uint8_t> data = cast(priv)->Serialize();
    buffer = &data[0];
    return (int)(sizeof(buffer) / sizeof(buffer[0]));
}