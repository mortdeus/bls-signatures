#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {} blsPrivateKey;

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen);
void blsPrivateKeyFromBytes(blsPrivateKey *priv, const uint8_t* bytes, bool modOrder);
void blsPrivateKeySerialize(blsPrivateKey *priv, uint8_t* buffer);

#ifdef __cplusplus
}
#endif