#include <globaldefs.h>
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif


extern "C" void func_0205af84(int a, void* b, int c);
extern "C" void SpriteContext_DrawSprite(int a, void* b);

struct Struct_ov008_021889f8 { char pad[0x2bc]; int unknown_2bc_; int unknown_2c0_; };

struct Struct_ov008_02184878 {
    char pad0[0x730];
    int f730;
    struct Struct_ov008_021889f8* f734;
    char pad1[0xb18 - 0x738];
    unsigned int unknown_b18_;
};

// USA: func_ov008_021889f8
extern "C" ARM void func_ov008_021889f8(struct Struct_ov008_02184878* obj) {
    if (obj->f730 == 0) return;
    if (!(obj->unknown_b18_ & 0x80000)) return;
    struct Struct_ov008_021889f8* s = obj->f734;
    s->unknown_2bc_ = R(0xd0000, 0xc8000);
    s->unknown_2c0_ = 0x62000;
    func_0205af84(obj->f730, (char*)obj->f734 + 0x2a8, 1);
    SpriteContext_DrawSprite(obj->f730, (char*)obj->f734 + 0x2a8);
}
