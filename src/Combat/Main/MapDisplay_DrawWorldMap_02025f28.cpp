#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Scenario_GetInstance(void);
extern "C" void* BgVram_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);

struct Bcb8Params;
extern "C" void BgImage_Place(struct Bcb8Params* s, int arg1, int arg2);

struct Obj_0201bb78 { unsigned short field0; };
extern "C" int func_0201bb78(struct Obj_0201bb78* obj, unsigned int val);

extern "C" void MapDisplay_DrawSprite(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);

extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" void func_0202630c(void* obj, int* pos, int margin);

extern "C" int abs(int x);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);

extern int data_020fdc4c;

struct Struct_02025f28 {
    unsigned short h0;
    unsigned char b2;
    char pad3;
    int w4;
    int w8;
};

struct Struct_ov026_021de6dc { int x, y, z; };

struct Struct_02025f28_2 {
    char pad[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
};

// Main, originally func_02025f28 (USA 0x02025f28, EUR 0x02025f38, JPN 0x020258fc)
extern "C" ARM void MapDisplay_DrawWorldMap(unsigned char* obj) {
#if defined(jpn)
    enum { regionalOffset0 = 0x9cd, regionalOffset1 = 0x9d0, regionalOffset2 = 0x64, regionalOffset3 = 0x68, regionalOffset4 = 0x27b4, regionalOffset5 = 0x8 };
#else
    enum { regionalOffset0 = 0xa99, regionalOffset1 = 0xa9c, regionalOffset2 = 0x44, regionalOffset3 = 0x48, regionalOffset4 = 0x2774, regionalOffset5 = 0xc };
#endif
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    BgVram_GetInstance();
    void* g = Zone3D_GetInstance();
    unsigned short g0 = *(unsigned short*)g;
    GameObject* c1;
    int i;
    int flag2;
    void* var7 = *(void**)((char*)g + 8);
    c1 = battle->GetLeader();
    battle->GetProtagonist();
    struct Struct_ov026_021de6dc var8 = *(struct Struct_ov026_021de6dc*)((char*)c1 + 0x44);

    if (*(unsigned char*)(obj + 0x55c) != 0) {
        *(unsigned char*)(obj + 0x55c) = 0;
        BgImage_Place((struct Bcb8Params*)(*(char**)(obj + 0x20) + 8), 0, 0);
    }

    flag2 = 1;
    for (i = 0; i < *(unsigned char*)(obj + regionalOffset0); i++) {
        if (func_0201bb78((struct Obj_0201bb78*)g, (unsigned short)((*(struct Struct_02025f28**)(obj + regionalOffset1))[i].h0 * 100)) == 0) continue;
        struct Struct_02025f28* e = &(*(struct Struct_02025f28**)(obj + regionalOffset1))[i];
        int x = e->w4;
        int z = e->w8;
        if ((*(struct Struct_02025f28**)(obj + regionalOffset1))[i].b2 == 1) {
            MapDisplay_DrawSprite(obj, x + 0x7d000, z + 0x5d000, 0x18,
                (i + 0x55) & 0xff, flag2, 0xff, 0xff, 0x1000, 0x1000);
        } else if ((*(struct Struct_02025f28**)(obj + regionalOffset1))[i].b2 == 2) {
            MapDisplay_DrawSprite(obj, x + 0x7d000, z + 0x5d000, 0x17,
                (i + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }

    i = 1;
    flag2 = i;
    if (g0 == 10000 || Scenario_TestFlag((int)ctx, ctx + 0x8c, 0x2b) == 0) flag2 = 0;
    int posVec[3];
    if (g0 == 10000 || g0 == 10100) {
        posVec[0] = var8.x + 0x80000;
        posVec[2] = var8.z + 0x60000;
    } else if (((struct Struct_02025f28_2*)var7)->unknown_c_0_ == 0) {
        posVec[0] = fix32_Divide((fix32_t)(var8.x + *(int*)((char*)g + regionalOffset2)), (fix32_t)(0x6000)) + 0x80000;
        posVec[2] = fix32_Divide((fix32_t)(var8.z + *(int*)((char*)g + regionalOffset3)), (fix32_t)(0x6000)) + 0x60000;
    } else if (*(int*)((char*)g + regionalOffset2) != 0 && *(int*)((char*)g + regionalOffset3) != 0) {
        posVec[0] = *(int*)((char*)g + regionalOffset2) + 0x80000;
        posVec[2] = *(int*)((char*)g + regionalOffset3) + 0x60000;
    } else {
        i = 0;
    }

    if (flag2) {
        struct Struct_ov026_021de6dc v = *(struct Struct_ov026_021de6dc*)((char*)g + regionalOffset4);
        v.x += 0x80000;
        v.z += 0x60000;
        func_0202630c(obj, (int*)&v, 0x7000);
        v.x -= 0x4000;
        v.z -= 0x4000;
        MapDisplay_DrawSprite(obj, v.x, v.z, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
    }

    int c = (*(unsigned int*)((char*)&data_020fdc4c + regionalOffset5) + battle->GetEffectiveDeltaTime()) % 0x560u;
    *(unsigned int*)((char*)&data_020fdc4c + regionalOffset5) = c;
    c = abs((c - 0x2b0) / 0x2b) * 0x4b / 100 + 5;
    if (c > 0x10) c = 0x10;
    int d = 0x10 - c;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04001050, 0, 3, c, d);

    func_0202630c(obj, posVec, 0x5000);
    posVec[0] -= 0x4000;
    posVec[2] -= 0x4000;

    if (i) {
        short f4 = c1->obj3D_.actorIndex_;
        unsigned char p5 = (unsigned char)(f4 + 0x44);
        unsigned short p7 = (unsigned short)(f4 + 4);
        MapDisplay_DrawSprite(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
