#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void* Zone3D_GetInstance(void);
struct Struct_ov017_021973e8;
extern "C" int _ZN8Object3D4DrawEb(void* obj, int flag);
struct Bits40_37464;

struct Struct_ov017_021973e8_2 { int a[3]; };
struct Struct_ov017_021973e8_3;
extern "C" void _ZNK8Object3D20MaybeGetShadowSourceEv(struct Struct_ov017_021973e8_2* dst, struct Struct_ov017_021973e8_3* src);
extern "C" void func_0208f87c(const void* self, int b, int c, int d, int polygonId);

#if defined(jpn)
enum { Enum_ov017_021973e8_56 = 0x58, Enum_ov017_021973e8_60 = 0x5c };
#else
enum { Enum_ov017_021973e8_56 = 0x38, Enum_ov017_021973e8_60 = 0x3c };
#endif

// USA: func_ov017_021973e8
extern "C" ARM void func_ov017_021973e8(unsigned int* arg0) {
    GameState* bs = GameState::GetInstance();
    void* ctx = Zone3D_GetInstance();
    unsigned short field38 = *(unsigned short*)((char*)ctx + Enum_ov017_021973e8_56);
    unsigned int field3c = *(unsigned int*)((char*)ctx + Enum_ov017_021973e8_60);

    if (TestFlags04((GameResources*)arg0, 0x100) != 0) return;

    int var4 = 1;
    if (TestFlags04((GameResources*)arg0, 0x1000) != 0) {
        var4 = 0;
    }

    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        GameObject* c = bs->GetGameObjectByIndex(id);
        if (!c) continue;
        if (((Object3D*)((struct Struct_ov017_021973e8*)c))->IsChild()) continue;
        if (c->obj3D_.GetFlag(0x40000000) != 0) continue;
        ((Object3D*)((unsigned char*)c))->EnableFlag(4);
        if (!_ZN8Object3D4DrawEb(c, var4)) continue;
        if (c->obj3D_.GetFlag(0x10) != 0) continue;

        int bits = ((Object3D*)((struct Bits40_37464*)c))->GetInheritedAlpha();
        int var8 = (int)((float)field3c / 31.0f * (float)bits);

        struct Struct_ov017_021973e8_2 vec;
        _ZNK8Object3D20MaybeGetShadowSourceEv(&vec, (struct Struct_ov017_021973e8_3*)c);
        int var10 = ((Object3D*)((unsigned char*)c))->GetRadius();
        func_0208f87c(&vec, field38, var10, var8, 8);
    }
}
