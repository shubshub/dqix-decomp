#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov025_021eb8e8_3 {
    unsigned long long unknown_0_;
    char unknown_8_[0x10];
    unsigned int unknown_18_;
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
};

struct Struct_ov025_021eb8e8 {
    char unknown_0_[0x28];
    unsigned int unknown_28_;
    char unknown_2c_[3];
    unsigned char unknown_2f_;
};

struct Struct_ov025_021eb8e8_2 {
    char unknown_0_[0xc];
    int unknown_c_;
};

void* GetActiveCombatWork_ov000_02160130(void);
char* GetOffsetPtr02160f08(void* obj);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
HitEntry_021eb8e8* GetSubstructField0x68_0204a01c(unsigned char* obj);
extern "C" void func_ov000_02162dc4(void* work, GameObject* lead, GameObject* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int flag);
HudEntry_021eb8e8* FindEntryById_021dafd0(char* obj, int id);
extern "C" void func_ov000_0217616c(HudEntry_021eb8e8* p);
void SetByteField37_0216ff20(char*, unsigned char);
void SetSubstructWord0x68_0204a00c(unsigned char* obj, int value);
int CheckSubstructFlag0x400_0204a0f8(unsigned char* obj);
void ClearSubstructFlag0x400_0204a0e0(unsigned char* obj);
int GetSubstructByte0x6c_0204a040(unsigned char* obj);
void SetSubstructByte0x6c_0204a030(unsigned char* obj, int value);
extern "C" void GameObject_FaceGameObject(GameObject* obj, int id, int flag);

// USA: func_ov025_021eb8e8
extern "C" ARM void func_ov025_021eb8e8(Struct_ov025_021eb8e8_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_ov000_02160130();
    char* var2 = func_ov000_02160f08(var1);
    short var3[16];
    int var4 = 0;
    var4 = var4 + func_ov000_0215e9fc(arg0->unknown_c_, var3, 0x10, var4);
    var4 = var4 + func_ov000_0215ec1c(arg0->unknown_c_, var3 + var4, 0x10 - var4, 0);
    short* var5 = var3;
    for (int var6 = 0; var6 < var4; var5++, var6++) {
        GameObject* var7 = var0->GetCombatantByIndex(*var5);
        if (var7 == 0) {
            continue;
        }
        Struct_ov025_021eb8e8_3* var8 = func_0204a01c((unsigned char*)var7);
        if (var8 != 0) {
            unsigned int var9 = var8->unknown_18_ & ~0x80000;
            func_ov000_02162dc4(var1, 0, var7, var9, var8->unknown_1d_, var8->unknown_1e_, var8->unknown_0_, 1);
            Struct_ov025_021eb8e8* var10 = func_ov025_021dafd0(var2, *var5);
            if (var10 != 0) {
                var10->unknown_28_ = var9;
                func_ov000_0217616c(var10);
                func_ov000_0216ff20((char*)var10, var8->unknown_1d_);
                var10->unknown_2f_ = var8->unknown_1e_;
            }
            func_0204a00c((unsigned char*)var7, 0);
        }
        if (func_0204a0f8((unsigned char*)var7)) {
            var7->obj3D_.SetInheritedAlpha(0x1f);
            func_0204a0e0((unsigned char*)var7);
        }
        if (GetSubstructByte0x6c_0204a040((unsigned char*)c) != 0xff) {
            GameObject_FaceGameObject(c, GetSubstructByte0x6c_0204a040((unsigned char*)c), 1);
            SetSubstructByte0x6c_0204a030((unsigned char*)c, 0xff);
        }
    }
}
