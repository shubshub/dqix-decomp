#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include <std_library_functions.h>

struct Struct_02070f98_2;
struct Struct_02070fe4;
struct Struct_02070f98 { unsigned short unknown_0_0_ : 15; unsigned short unknown_1_7_ : 1; };
struct Struct_ov025_021e7b74 { char unknown_0_[0x400]; unsigned int unknown_400_[3]; };
struct Struct_ov025_021e7b74_2 { char unknown_0_[0x284]; Struct_ov025_021e7b74 unknown_284_; };
struct Struct_ov001_02158ae4_3 { char unknown_0_[0x240]; Vector3i unknown_240_; };
struct Struct_02033834;
extern "C" Struct_ov025_021e7b74_2* func_ov017_021b8478(void*);
extern "C" void* func_ov000_02160130();
extern "C" int func_ov000_0215eb1c(void*, short*, int, int);
extern "C" int func_ov000_0215ed34(void*, short*, int);
extern "C" int func_ov000_02167484(short*, int);
extern "C" int func_02070fe4(Struct_02070fe4*);
extern "C" Struct_02070f98* func_02070f98(Struct_02070f98_2*, int);
extern "C" void func_ov025_021e771c(short*, int, short*, int);
extern "C" void func_ov000_02161c0c(void*, int);
extern "C" void func_0200fd48(GameState*, int);
extern "C" void func_ov000_021677fc(void*);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char*);
extern "C" CameraState* func_ov000_02160f14(void*);
void GameObject_SnapFacing(Obj02033874*, int);
unsigned char* GetField02163524(void*);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
int GetSubstructByte0x1c_020493a4(unsigned char*);
extern "C" void func_ov000_02167fb0(void*, GameObject*);
extern "C" void func_020d7334(unsigned char*, int);

// USA: func_ov025_021e7b74
extern "C" ARM int func_ov025_021e7b74(void*, void*, void*, void* arg3) {
    int var0;
    Struct_ov025_021e7b74* var1;
    GameResources* var2 = GetGameResources();
    GameState* var3 = GameState::GetInstance();
    Struct_ov025_021e7b74_2* var4 = func_ov017_021b8478(var2->unknown_ptr_3718);
    void* var5 = func_ov000_02160130();
    short var6[8];
    var0 = (unsigned char)func_ov000_0215eb1c(arg3, var6, 8, 0x10);
    short var7[12];
    unsigned char var8 = func_ov000_0215ed34(arg3, var7, 12);
    unsigned char var9 = func_ov000_02167484(var7, var8);
    var1 = &var4->unknown_284_;
    int var10 = func_02070fe4((Struct_02070fe4*)var1->unknown_400_);
    for (int var11 = 0; var11 < var10; ++var11) {
        Struct_02070f98* var12 = func_02070f98((Struct_02070f98_2*)var1->unknown_400_, var11);
        if (!var12) continue;
        int var13 = 1;
        short* var14 = var7;
        for (int var15 = 0; var15 < var9; ++var15, ++var14) {
            if (var12->unknown_0_0_ == *var14) { var13 = 0; break; }
        }
        if (var13) var7[var9++] = var12->unknown_0_0_;
    }
    func_ov025_021e771c(var7, var8, var7, var9);
    unsigned char var16[8];
    memset(var16, 0, sizeof(var16));
    short* var17 = var6;
    for (int var18 = 0; var18 < var0; ++var18) {
        int var19 = *var17;
        var17++;
        var16[var19 - 0xc0] = 1;
        func_ov000_02161c0c(var5, var19);
    }
    unsigned char* var20 = var16;
    for (short var21 = 0xc0; var21 <= 0xc7; ++var21, ++var20) {
        if (!*var20) func_0200fd48(var3, var21);
    }
    func_ov000_021677fc(work);
    RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)work);
    Vector3i cameraPosition = func_ov000_02160f14(work)->position;
    int cameraZ = cameraPosition.z;
    for (int id = 0xc0; id < 0xc8; ++id) {
        GameObject* actor = game->GetCombatantByIndex(id);
        if (!actor) continue;
        Vector3i target = {};
        target.z = cameraZ;
        Vector3i position = actor->obj3D_.position_;
        position.y = 0;
        Vector3i direction;
        Vector3fix_Subtract(&target, &position, &direction);
        direction.y = 0;
        Vector3fix_Normalize(&direction, &direction);
        GameObject_SnapFacing((Obj02033874*)actor, fix32_Atan2(direction.x, direction.z));
    }
    unsigned char* var29 = func_ov000_02163524(var5);
    short* var30 = var6;
    for (int var31 = 0; var31 < var0; ++var30, ++var31) {
        GameObject* var32 = func_0200fea4(var3, *var30);
        if (var32 && func_020493a4((unsigned char*)var32) == 0xff) {
            func_ov000_02167fb0(var5, var32);
            func_020d7334(var29, *var30);
        }
    }
    return 1;
}
