#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {} blsPrivateKey;
typedef struct {} blsPublicKey;

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen);
void blsPrivateKeyFromBytes(blsPrivateKey *priv, const uint8_t* bytes, bool modOrder = false);
void blsGetPublicKey(blsPublicKey *pub, const blsPrivateKey *priv);

#ifdef __cplusplus
}
#endif
