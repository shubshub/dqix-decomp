#include <globaldefs.h>
#include "Combat/FormationPosition.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

static inline Struct_02048cf0 inline_02048e2c_2(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov025_021e1480
extern "C" ARM unsigned char func_ov025_021e1480(unsigned char arg0, unsigned char* cells, int count) {
    unsigned char var0 = 0;
    Struct_02048cf0 origin = inline_02048e2c_2(arg0);
    int var2 = 0x400000;
    for (int i = 0; i < count; i++) {
        Struct_02048cf0 pos = inline_02048e2c_2(cells[i]);
        int dist = FxMul(origin.x - pos.x, origin.x - pos.x) + FxMul(origin.y - pos.y, origin.y - pos.y);
        if (dist < var2) {
            var0 = cells[i];
            var2 = dist;
        }
    }
    return var0;
}
