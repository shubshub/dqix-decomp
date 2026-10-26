#include <globaldefs.h>

struct FlagWord020466f4 {
    unsigned int flags;
};

// Main, originally ClearFlags020466f4 (USA 0x020466f4, EUR 0x02046704, JPN 0x02047514)
extern "C" ARM void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask) {
    word->flags &= ~mask;
}
