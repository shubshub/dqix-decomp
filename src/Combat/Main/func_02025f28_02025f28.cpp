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
extern "C" ARM void func_02025f28(unsigned char* arg0) {
#if defined(jpn)
    enum { Enum_02025f28_2713 = 0x9cd, Enum_02025f28_2716 = 0x9d0, Enum_02025f28_68 = 0x64, Enum_02025f28_72 = 0x68, Enum_02025f28_10100 = 0x27b4, Enum_02025f28_12 = 0x8 };
#else
    enum { Enum_02025f28_2713 = 0xa99, Enum_02025f28_2716 = 0xa9c, Enum_02025f28_68 = 0x44, Enum_02025f28_72 = 0x48, Enum_02025f28_10100 = 0x2774, Enum_02025f28_12 = 0xc };
#endif
    GameState* battle = GameState::GetInstance();
    unsigned char* ctx = (unsigned char*)Scenario_GetInstance();
    GetData02105254_0203b628();
    void* g = Zone3D_GetInstance();
    unsigned short g0 = *(unsigned short*)g;
    GameObject* c1;
    int i;
    int flag2;
    void* g8 = *(void**)((char*)g + 8);
    c1 = battle->GetUnknownGameObject();
    battle->GetProtagonist();
    struct Vec3i pos0 = *(struct Vec3i*)((char*)c1 + 0x44);

    if (*(unsigned char*)(arg0 + 0x55c) != 0) {
        *(unsigned char*)(arg0 + 0x55c) = 0;
        func_0203bcb8((struct Struct_02020fc4_3*)(*(char**)(arg0 + 0x20) + 8), 0, 0);
    }

    var6 = 1;
    for (var5 = 0; var5 < *(unsigned char*)(arg0 + Enum_02025f28_2713); var5++) {
        if (func_0201bb78((struct Struct_0201bb78*)var2, (unsigned short)((*(struct Struct_02025f28**)(arg0 + Enum_02025f28_2716))[var5].unknown_0_ * 100)) == 0) continue;
        struct Struct_02025f28* var9 = &(*(struct Struct_02025f28**)(arg0 + Enum_02025f28_2716))[var5];
        int var10 = var9->unknown_4_;
        int var11 = var9->unknown_8_;
        if ((*(struct Struct_02025f28**)(arg0 + Enum_02025f28_2716))[var5].unknown_2_ == 1) {
            func_0202756c(arg0, var10 + 0x7d000, var11 + 0x5d000, 0x18,
                (var5 + 0x55) & 0xff, var6, 0xff, 0xff, 0x1000, 0x1000);
        } else if ((*(struct Struct_02025f28**)(arg0 + Enum_02025f28_2716))[var5].unknown_2_ == 2) {
            func_0202756c(arg0, var10 + 0x7d000, var11 + 0x5d000, 0x17,
                (var5 + 0x55) & 0xff, 0, 0xff, 0xff, 0x1000, 0x1000);
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

    if (var6) {
        struct Struct_ov026_021de6dc var13 = *(struct Struct_ov026_021de6dc*)((char*)var2 + Enum_02025f28_10100);
        var13.unknown_0_ += 0x80000;
        var13.unknown_8_ += 0x60000;
        func_0202630c(arg0, (int*)&var13, 0x7000);
        var13.unknown_0_ -= 0x4000;
        var13.unknown_8_ -= 0x4000;
        func_0202756c(arg0, var13.unknown_0_, var13.unknown_8_, 0x19, 0x54, 0, 0xff, 0xff, 0x1000, 0x1000);
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
        SetElementFields0202756c(obj, posVec[0], posVec[2], 5, p5, 0, p7, 0xff, 0x1000, 0x1000);
    }
}
