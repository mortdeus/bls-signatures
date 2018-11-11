#include <stdint.h>
#include <stdlib.h>

typedef struct {} blsPrivateKey;

void blsPrivateKeyFromSeed(blsPrivateKey *priv, const uint8_t* seed, size_t seedLen);
