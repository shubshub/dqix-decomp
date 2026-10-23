#include <globaldefs.h>

struct Obj0204b010;
void Background_ClearMap(struct Obj0204b010* obj, void* p);

struct Obj0204b8d0;
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

extern "C" void Background_FlushMap(void* obj, void* p);

struct Obj021ecdfc {
    char pad0[0x64];
    char f64[0x400 - 0x64];
    char pad400[0x38];
    unsigned short f438;
    char pad43a[0x43d - 0x43a];
    unsigned char f43d;
    char pad43e[0];
    short f43e;
    short f440;
    short f442;
    short f444;
    short f446;
};

// USA: func_ov023_021ecdfc  (semantic: ClearAndDispatchEntry_021ecdfc)
extern "C" ARM void func_ov023_021ecdfc(struct Obj021ecdfc* obj) {
    if ((obj->f438 & 0x40) != 0 || (obj->f438 & 0x200) != 0) {
        Background_ClearMap((struct Obj0204b010*)&obj->f64, NULL);

        short base = obj->f43e;
        short v1 = obj->f442 + base;
        short v2 = obj->f446 - base;
        Background_DrawScreen((struct Obj0204b8d0*)&obj->f64, obj->f43d, 0, base, obj->f440, v1, obj->f444, v2, 0xffff);

        Background_FlushMap(&obj->f64, NULL);
    }
}
