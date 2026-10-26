#include <globaldefs.h>

struct S02046730 {
    int unknown_0_;
};

// Main, originally ClearField0x0_02046730 (USA 0x02046730, EUR 0x02046740, JPN 0x02047550)
extern "C" ARM void FlagWord_Clear(struct S02046730* p) {
    p->unknown_0_ = 0;
}
