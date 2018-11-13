#include <stdint.h>
#include <stdlib.h>

#include "../contrib/relic/include/relic_conf.h"
#include "../contrib/relic/include/relic.h"
#include "../contrib/relic/include/relic_test.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    bn_t* keydata;
} blsPrivateKey;

typedef struct {} blsPublicKey;

typedef struct {} blsSignature;

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen);
void blsPrivateKeyFromBytes(blsPrivateKey *priv);
int blsPrivateKeySerialize(uint8_t* buffer, blsPrivateKey *priv);
void blsPrivateKeySign(blsSignature *sign, const uint8_t *msg, size_t len);

void blsPublicKeyFromBytes(blsPublicKey *pub, const uint8_t* key);
void blsPublicKeySerialize(blsPublicKey *pub, uint8_t* buffer);

void blsGetPublicKey(void* pub, blsPrivateKey *priv);

int blsVerify(blsPublicKey *pub, blsSignature *sign, const uint8_t *msg, size_t len);

#ifdef __cplusplus
}
#endif