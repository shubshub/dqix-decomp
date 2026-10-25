#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* Scenario_GetInstance(void);
void* GetData02105254_0203b628(void);
extern "C" void* Zone3D_GetInstance(void);

struct Struct_02020fc4_3;
extern "C" void func_0203bcb8(struct Struct_02020fc4_3* arg0, int arg1, int arg2);

struct Struct_0201bb78 { unsigned short unknown_0_; };
extern "C" int func_0201bb78(struct Struct_0201bb78* arg0, unsigned int arg1);

extern "C" void func_0202756c(void* arg0, int arg1, int arg2, int arg3,
        unsigned char arg4, unsigned char arg5, unsigned short arg6, unsigned char arg7, int arg8, int arg9);

int Scenario_TestFlag(int unused, unsigned char* arr, int index);
void ClampPositionToBounds0202630c(void* obj, int* pos, int margin);

extern "C" int _u32_div_f(int arg0, int arg1);
extern "C" int _s32_div_f(int a, int b);
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

// USA: func_02025f28
extern "C" ARM void func_02025f28(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    GetData02105254_0203b628();
    void* g = Zone3D_GetInstance();
    unsigned short g0 = *(unsigned short*)g;
    void* g8 = *(void**)((char*)g + 8);
    GameObject* c1 = battle->GetUnknownGameObject();
    battle->GetProtagonist();
    struct Vec3i pos0 = *(struct Vec3i*)((char*)c1 + 0x44);

    if (*(unsigned char*)(arg0 + 0x55c) != 0) {
        *(unsigned char*)(arg0 + 0x55c) = 0;
        func_0203bcb8((struct Struct_02020fc4_3*)(*(char**)(arg0 + 0x20) + 8), 0, 0);
    }

    int var7 = 1;
    for (int var8 = 0; var8 < *(unsigned char*)(arg0 + 0xa99); var8++) {
        struct Struct_02025f28* var9 = *(struct Struct_02025f28**)(arg0 + 0xa9c);
        int var10 = func_0201bb78((struct Struct_0201bb78*)var2, (unsigned short)(var9[var8].unknown_0_ * 100));
        if (var10 == 0) continue;
        struct Struct_02025f28* var11 = *(struct Struct_02025f28**)(arg0 + 0xa9c) + var8;
        if (var11->unknown_2_ == 1) {
            func_0202756c(arg0, var11->unknown_4_ + 0x7d000, var11->unknown_8_ + 0x5d000, 0x18,
                (var8 + 0x55) & 0xff, var7, 0xff, 0xff, 0x1000, 0x1000);
        } else if (var11->unknown_2_ == 2) {
            func_0202756c(arg0, var11->unknown_4_ + 0x7d000, var11->unknown_8_ + 0x5d000, 0x17,
                (var8 + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
        }
    }

    int flag2 = (g0 != 10000) && (Scenario_TestFlag((int)ctx, ctx + 0x8c, 0x2b) != 0);
    int posVec[3];
    int ok = 1;
    if (g0 == 10000 || g0 == 10100) {
        posVec[0] = pos0.x + 0x80000;
        posVec[2] = pos0.z + 0x60000;
    } else if (((struct G8Obj*)g8)->lowNibble == 0) {
        posVec[0] = fix32_Divide((fix32_t)(pos0.x + *(int*)((char*)g + 0x44)), (fix32_t)(0x6000)) + 0x80000;
        posVec[2] = fix32_Divide((fix32_t)(pos0.z + *(int*)((char*)g + 0x48)), (fix32_t)(0x6000)) + 0x60000;
    } else {
        int var15 = *(int*)((char*)var2 + 0x44);
        if (var15 == 0 || *(int*)((char*)var2 + 0x48) == 0) {
            if (var15 == 0) var14 = 0;
        } else {
            var13[0] = var15 + 0x80000;
            var13[2] = *(int*)((char*)var2 + 0x48) + 0x60000;
        }
    }

    if (var12) {
        struct Struct_ov026_021de6dc var16 = *(struct Struct_ov026_021de6dc*)((char*)var2 + 0x2774);
        var16.unknown_0_ += 0x80000;
        var16.unknown_8_ += 0x60000;
        func_0202630c(arg0, (int*)&var16, 0x7000);
        var16.unknown_0_ -= 0x4000;
        var16.unknown_8_ -= 0x4000;
        func_0202756c(arg0, var16.unknown_0_, var16.unknown_8_, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
    }

    int var17 = var0->GetEffectiveDeltaTime();
    unsigned int var18 = *(unsigned int*)((char*)&data_020fdc4c + 0xc) + (unsigned int)var17;
    unsigned int var19 = var18 % 0x560u;
    int var20 = ((int)var19 - 0x2b0) / 0x2b;
    *(unsigned int*)((char*)&data_020fdc4c + 0xc) = var19;
    int var21 = abs(var20);
    int var22 = (var21 * 0x4b) / 100;
    int var23 = var22 + 5;
    if (var23 > 0x10) var23 = 0x10;
    int var24 = 0x10 - var23;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04001050, 0, 3, var23, var24);

    func_0202630c(arg0, var13, 0x5000);
    var13[0] -= 0x4000;
    var13[2] -= 0x4000;

    if (ok) {
        short f4 = c1->obj3D_.actorIndex_;
        unsigned char p5 = (unsigned char)(f4 + 0x44);
        unsigned short p7 = (unsigned short)(f4 + 4);
        _Z24SetElementFields0202756cPviiihhthii(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
