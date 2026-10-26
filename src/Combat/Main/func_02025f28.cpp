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

extern "C" int _u32_div_f(int a, int b);
extern "C" int _s32_div_f(int a, int b);
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

// USA: MapDisplay_DrawWorldMap
extern "C" ARM void MapDisplay_DrawWorldMap(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    BgVram_GetInstance();
    void* g = Zone3D_GetInstance();
    unsigned short g0 = *(unsigned short*)g;
    void* var4 = *(void**)((char*)g + 8);
    GameObject* c1 = battle->GetLeader();
    battle->GetProtagonist();
    struct Struct_ov026_021de6dc var6 = *(struct Struct_ov026_021de6dc*)((char*)c1 + 0x44);

    if (*(unsigned char*)(obj + 0x55c) != 0) {
        *(unsigned char*)(obj + 0x55c) = 0;
        BgImage_Place((struct Bcb8Params*)(*(char**)(obj + 0x20) + 8), 0, 0);
    }

    int var7 = 1;
    for (int i = 0; i < *(unsigned char*)(obj + 0xa99); i++) {
        struct Struct_02025f28* arr = *(struct Struct_02025f28**)(obj + 0xa9c);
        int result = func_0201bb78((struct Obj_0201bb78*)g, (unsigned short)(arr[i].h0 * 100));
        if (result == 0) continue;
        struct Struct_02025f28* e = *(struct Struct_02025f28**)(obj + 0xa9c) + i;
        if (e->b2 == 1) {
            MapDisplay_DrawSprite(obj, e->w4 + 0x7d000, e->w8 + 0x5d000, 0x18,
                (i + 0x55) & 0xff, var7, 0xff, 0xff, 0x1000, 0x1000);
        } else if (e->b2 == 2) {
            MapDisplay_DrawSprite(obj, e->w4 + 0x7d000, e->w8 + 0x5d000, 0x17,
                (i + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }

    int flag2 = (g0 != 10000) && (Scenario_TestFlag((int)ctx, ctx + 0x8c, 0x2b) != 0);
    int posVec[3];
    int ok = 1;
    if (g0 == 10000 || g0 == 10100) {
        posVec[0] = var6.x + 0x80000;
        posVec[2] = var6.z + 0x60000;
    } else if (((struct Struct_02025f28_2*)var4)->unknown_c_0_ == 0) {
        posVec[0] = fix32_Divide((fix32_t)(var6.x + *(int*)((char*)g + 0x44)), (fix32_t)(0x6000)) + 0x80000;
        posVec[2] = fix32_Divide((fix32_t)(var6.z + *(int*)((char*)g + 0x48)), (fix32_t)(0x6000)) + 0x60000;
    } else {
        int var15 = *(int*)((char*)g + 0x44);
        if (var15 == 0 || *(int*)((char*)g + 0x48) == 0) {
            if (var15 == 0) ok = 0;
        } else {
            posVec[0] = var15 + 0x80000;
            posVec[2] = *(int*)((char*)g + 0x48) + 0x60000;
        }
    }

    if (flag2) {
        struct Struct_ov026_021de6dc v = *(struct Struct_ov026_021de6dc*)((char*)g + 0x2774);
        v.x += 0x80000;
        v.z += 0x60000;
        func_0202630c(obj, (int*)&v, 0x7000);
        v.x -= 0x4000;
        v.z -= 0x4000;
        MapDisplay_DrawSprite(obj, v.x, v.z, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
    }

    int fieldVal = battle->GetEffectiveDeltaTime();
    unsigned int sum = *(unsigned int*)((char*)&data_020fdc4c + 0xc) + (unsigned int)fieldVal;
    unsigned int rem = sum % 0x560u;
    int q = ((int)rem - 0x2b0) / 0x2b;
    *(unsigned int*)((char*)&data_020fdc4c + 0xc) = rem;
    int var21 = abs(q);
    int var22 = (var21 * 0x4b) / 100;
    int c = var22 + 5;
    if (c > 0x10) c = 0x10;
    int d = 0x10 - c;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04001050, 0, 3, c, d);

    func_0202630c(obj, posVec, 0x5000);
    posVec[0] -= 0x4000;
    posVec[2] -= 0x4000;

    if (ok) {
        short f4 = c1->obj3D_.actorIndex_;
        unsigned char p5 = (unsigned char)(f4 + 0x44);
        unsigned short p7 = (unsigned short)(f4 + 4);
        MapDisplay_DrawSprite(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
