#include <stdlib.h>
#include <vector>

using namespace std;

#include "cgo_interface.h"

extern "C" {
    void createPrivateKey() {
        vector<int> ivec;   // empty vector
        for (vector<int>::size_type ix = 0; ix != 10; ++ix)
            ivec[ix] = ix; // disaster: ivec has no elementsl
    }
}