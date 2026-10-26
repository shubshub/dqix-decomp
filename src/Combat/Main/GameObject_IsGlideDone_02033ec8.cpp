#include <globaldefs.h>

struct ShortField02033ec8 {
    char pad[0xc6];
    short unknown_c6_;
};

// Main, originally CheckField0xc6Zero (USA 0x02033ec8, EUR 0x02033ed8, JPN 0x02033a00)
extern "C" ARM int GameObject_IsGlideDone(struct ShortField02033ec8* p) {
    return p->unknown_c6_ == 0;
}
