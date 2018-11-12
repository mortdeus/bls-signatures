#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {} blsPrivateKey;
typedef struct {} blsPublicKey;
typedef struct {} blsSignature;

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen);
void blsPrivateKeyFromBytes(blsPrivateKey *priv, const uint8_t* bytes, int modOrder);
void blsPrivateKeySerialize(blsPrivateKey *priv, uint8_t* buffer);
void blsPrivateKeySign(blsSignature *sign, const uint8_t *msg, size_t len);

void blsPublicKeyFromBytes(blsPublicKey *pub, const uint8_t* key);
void blsPublicKeySerialize(blsPublicKey *pub, uint8_t* buffer);

void blsGetPublicKey(blsPublicKey *pub, blsPrivateKey *priv);

int blsVerify(blsPublicKey *pub, blsSignature *sign, const uint8_t *msg, size_t len);

#ifdef __cplusplus
}
#endif