#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Scenario_GetInstance(void);
void* BgVram_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);

struct Bcb8Params;
void BgImage_Place(struct Bcb8Params* s, int arg1, int arg2);

struct Struct_0201bb78 { unsigned short unknown_0_; };
extern "C" int func_0201bb78(struct Struct_0201bb78* arg0, unsigned int arg1);

void MapDisplay_DrawSprite(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);

int Scenario_TestFlag(int unused, unsigned char* arr, int index);
void ClampPositionToBounds0202630c(void* obj, int* pos, int margin);

extern "C" int abs(int arg0);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);

extern int data_020fdc4c;

struct Struct_02025f28 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov026_021de6dc { int unknown_0_, unknown_4_, unknown_8_; };

struct Struct_02025f28_2 {
    char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
};

// Main, originally func_02025f28 (USA 0x02025f28, EUR 0x02025f38, JPN 0x020258fc)
extern "C" ARM void MapDisplay_DrawWorldMap(unsigned char* obj) {
#if defined(jpn)
    enum { Enum_02025f28_2713 = 0x9cd, Enum_02025f28_2716 = 0x9d0, Enum_02025f28_68 = 0x64, Enum_02025f28_72 = 0x68, Enum_02025f28_10100 = 0x27b4, Enum_02025f28_12 = 0x8 };
#else
    enum { Enum_02025f28_2713 = 0xa99, Enum_02025f28_2716 = 0xa9c, Enum_02025f28_68 = 0x44, Enum_02025f28_72 = 0x48, Enum_02025f28_10100 = 0x2774, Enum_02025f28_12 = 0xc };
#endif
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    BgVram_GetInstance();
    void* g = Zone3D_GetInstance();
    unsigned short g0 = *(unsigned short*)g;
    GameObject* c1;
    int i;
    int flag2;
    void* g8 = *(void**)((char*)g + 8);
    c1 = battle->GetLeader();
    battle->GetProtagonist();
    struct Vec3i pos0 = *(struct Vec3i*)((char*)c1 + 0x44);

    if (*(unsigned char*)(obj + 0x55c) != 0) {
        *(unsigned char*)(obj + 0x55c) = 0;
        BgImage_Place((struct Bcb8Params*)(*(char**)(obj + 0x20) + 8), 0, 0);
    }

    flag2 = 1;
    for (i = 0; i < *(unsigned char*)(obj + regionalOffset0); i++) {
        if (LookupBitFromValueRange0201bb78((struct Obj_0201bb78*)g, (unsigned short)((*(struct Elem0xa9c**)(obj + regionalOffset1))[i].h0 * 100)) == 0) continue;
        struct Elem0xa9c* e = &(*(struct Elem0xa9c**)(obj + regionalOffset1))[i];
        int x = e->w4;
        int z = e->w8;
        if ((*(struct Elem0xa9c**)(obj + regionalOffset1))[i].b2 == 1) {
            MapDisplay_DrawSprite(obj, x + 0x7d000, z + 0x5d000, 0x18,
                (i + 0x55) & 0xff, flag2, 0xff, 0xff, 0x1000, 0x1000);
        } else if ((*(struct Elem0xa9c**)(obj + regionalOffset1))[i].b2 == 2) {
            MapDisplay_DrawSprite(obj, x + 0x7d000, z + 0x5d000, 0x17,
                (i + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }

    i = 1;
    flag2 = i;
    if (g0 == 10000 || Scenario_TestFlag((int)ctx, ctx + 0x8c, 0x2b) == 0) flag2 = 0;
    int posVec[3];
    if (g0 == 10000 || g0 == 10100) {
        posVec[0] = pos0.x + 0x80000;
        posVec[2] = pos0.z + 0x60000;
    } else if (((struct G8Obj*)g8)->lowNibble == 0) {
        posVec[0] = fix32_Divide((fix32_t)(pos0.x + *(int*)((char*)g + regionalOffset2)), (fix32_t)(0x6000)) + 0x80000;
        posVec[2] = fix32_Divide((fix32_t)(pos0.z + *(int*)((char*)g + regionalOffset3)), (fix32_t)(0x6000)) + 0x60000;
    } else if (*(int*)((char*)g + regionalOffset2) != 0 && *(int*)((char*)g + regionalOffset3) != 0) {
        posVec[0] = *(int*)((char*)g + regionalOffset2) + 0x80000;
        posVec[2] = *(int*)((char*)g + regionalOffset3) + 0x60000;
    } else {
        var5 = 0;
    }

    if (flag2) {
        struct Vec3i v = *(struct Vec3i*)((char*)g + regionalOffset4);
        v.x += 0x80000;
        v.z += 0x60000;
        ClampPositionToBounds0202630c(obj, (int*)&v, 0x7000);
        v.x -= 0x4000;
        v.z -= 0x4000;
        MapDisplay_DrawSprite(obj, v.x, v.z, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
    }

    int var14 = (*(unsigned int*)((char*)&data_020fdc4c + Enum_02025f28_12) + var0->GetEffectiveDeltaTime()) % 0x560u;
    *(unsigned int*)((char*)&data_020fdc4c + Enum_02025f28_12) = var14;
    var14 = abs((var14 - 0x2b0) / 0x2b) * 0x4b / 100 + 5;
    if (var14 > 0x10) var14 = 0x10;
    int var15 = 0x10 - var14;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04001050, 0, 3, var14, var15);

    func_0202630c(arg0, var12, 0x5000);
    var12[0] -= 0x4000;
    var12[2] -= 0x4000;

    if (i) {
        short f4 = c1->obj3D_.actorIndex_;
        unsigned char p5 = (unsigned char)(f4 + 0x44);
        unsigned short p7 = (unsigned short)(f4 + 4);
        MapDisplay_DrawSprite(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
