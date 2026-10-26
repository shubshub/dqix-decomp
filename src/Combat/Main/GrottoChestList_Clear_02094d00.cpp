#include <globaldefs.h>

struct ClearThreeWords02094d00Struct {
    int a;
    int b;
    int c;
};

// Main, originally ClearThreeWords02094d00 (USA 0x02094d00, EUR 0x02094d10, JPN 0x02096950)
ARM void GrottoChestList_Clear(struct ClearThreeWords02094d00Struct* s) {
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
