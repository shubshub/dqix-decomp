#include <globaldefs.h>
#include "Resource/GameResources.h"

struct GameResources;
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);

struct Struct_020db3f4_3 {
    unsigned char pad[0x6c];
    unsigned char f6c;
};

// USA: func_020db844
extern "C" ARM void func_020db844(struct Struct_020db3f4_3* a, int b, int c, int d) {
    int base = (int)GetGameResources();
    if (base == 0) return;
    a->f6c = 0;
    if (b == 0) SetMainBrightness((GameResources*)base, c, d);
    else SetSubBrightness((GameResources*)base, c, d);
    a->f6c = 1;
}
