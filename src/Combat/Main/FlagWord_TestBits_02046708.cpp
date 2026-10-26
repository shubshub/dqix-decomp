#include <globaldefs.h>

struct FlagWord02046708 {
    unsigned int flags;
};

// Main, originally TestFlags02046708 (USA 0x02046708, EUR 0x02046718, JPN 0x02047528)
extern "C" ARM int FlagWord_TestBits(struct FlagWord02046708* word, unsigned int mask) {
    return (word->flags & mask) != 0;
}
