#include <globaldefs.h>

struct S02046730 {
    int field0x0;
};

// Main, originally ClearField0x0_02046730 (USA 0x02046730, EUR 0x02046740, JPN 0x02047550)
ARM void FlagWord_Clear(struct S02046730* p) {
    p->field0x0 = 0;
}
