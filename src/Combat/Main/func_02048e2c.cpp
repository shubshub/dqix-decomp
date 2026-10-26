#include "Combat/FormationPosition.h"
#include <globaldefs.h>

struct Struct_02048e2c_2 {
    char unknown_0_[0x10];
    int unknown_10_[3];
    char unknown_1c_[0x4];
    unsigned int flags;
    unsigned char cells[0x10];
    unsigned char cellCount;
    char unknown_35_[0x3];
    int unknown_38_;
    unsigned short unknown_3c_;
    char unknown3e[0x2];
    int unknown_40_[3];
};

struct Struct_02048e2c {
    char unknown_0_[0x13c];
    Struct_02048e2c_2 *path;
    Struct_02048e2c_2 *inline_02048e2c() const { return path; }
};

static inline Struct_02048cf0 inline_02048e2c_2(const int &cell) {
    return func_ov000_0216f74c(const_cast<int *>(&cell));
}

// USA: func_02048e2c
extern "C" ARM void func_02048e2c(Struct_02048e2c *actor) {
    if (actor->path == 0) {
        return;
    }

    {
        Struct_02048e2c_2 *state  = actor->path;
        unsigned char var1 = state->cells[0];
        int var2;
        int var3 = 1;
        var2      = var3;
        while (var2 < actor->path->cellCount) {
            const unsigned char *cell = state->cells;
            cell += var2;
            unsigned char var5 = *cell;
            if (var1 != var5) {
                actor->inline_02048e2c()->cells[var3] = var5;
                state                               = actor->path;
                var3++;
                var1 = state->cells[var2];
            }
            var2++;
        }
        state->cellCount = var3;
    }

    if (actor->path->cellCount <= 1) {
        actor->path->cellCount = 0;
        return;
    }

    for (;;) {
        Struct_02048cf0 position = inline_02048e2c_2(actor->path->cells[1]);
        int x                  = position.x;
        int z                  = position.y;
        if (actor->path->unknown_40_[0] == x && actor->path->unknown_40_[2] == z) {
            actor->path->cellCount--;
            if (actor->path->cellCount <= 1) {
                actor->path->cellCount = 0;
                return;
            }
            for (int var9 = 1; var9 < actor->path->cellCount; var9++) {
                actor->path->cells[var9] = actor->path->cells[var9 + 1];
            }
        } else {
            actor->path->flags |= 0x10;
            return;
        }
    }
}
