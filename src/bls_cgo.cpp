#include "bls_cgo.hpp"
#include "bls.hpp"

using namespace bls;

static PrivateKey *cast(blsPrivateKey *p) { return reinterpret_cast<PrivateKey*>(p); }
static const PrivateKey *cast(const blsPrivateKey *p) { return reinterpret_cast<const PrivateKey*>(p); }

static PublicKey *cast(blsPublicKey *p) { return reinterpret_cast<PublicKey*>(p); }
static const PublicKey *cast(const blsPublicKey *p) { return reinterpret_cast<const PublicKey*>(p); }

static Signature *cast(blsSignature *p) { return reinterpret_cast<Signature*>(p); }
static const Signature *cast(const blsSignature *p) { return reinterpret_cast<const Signature*>(p); }

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen) {
    cast(priv)->FromSeed(seed, seedLen);
}

void blsPrivateKeyFromBytes(blsPrivateKey *priv) {
    return;
}

void blsPublicKeyFromBytes(blsPublicKey *pub, const uint8_t* key) {
    cast(pub)->FromBytes(key);
}

void blsGetPublicKey(void* pub, blsPrivateKey *priv) {
    PublicKey p = cast(priv)->GetPublicKey();
    pub = &p;
}

void blsPrivateKeySign(blsPrivateKey *priv, void* sign, const uint8_t *msg, size_t len) {
    Signature s = cast(priv)->Sign(msg, len);
    sign = &s;
}

int blsVerify(blsPublicKey *pub, blsSignature *sign, const uint8_t *msg, size_t len) {
    Signature *s = cast(sign);
    s->SetAggregationInfo(AggregationInfo::FromMsg(*cast(pub), msg, len));
    return s->Verify();
}