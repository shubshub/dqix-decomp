#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
extern char data_020f29cc;
#endif

extern "C" int func_ov017_021959b4(void);
void* MessageSystem_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
char* GameState_GetFollowCamera(char*);
extern "C" unsigned short* Zone3D_GetInstance(void);
void InitBattleIfListHasId0x1c_020d9a58(void* self);
int LinkSession_IsActive(int* p);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void func_ov017_021cf730(int a, int b);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" void func_020531f0(void* obj);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
void ResetElapsedState020e11a4(void);
extern "C" void func_02046380(void* global);
int StandardStrings_Get(int value);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, void* arg1, int arg2, int arg3);
#endif
extern "C" int func_020457e0(void* global);
extern "C" void func_ov017_021ab860(short value, int flag);
void InitContext020e1154(void* obj);
void MessageSystem_Reset(char* obj);
void GameObject_EnableControl(void* obj);
void InitBattleAndControllerState_020d9ab0(void* self);
int ZoneId_IsGrottoBossFloor(int x);

struct Struct_020d9870 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[0x8 - 0x2];
    unsigned char unknown_8_;
};

// Main, originally func_020d9870 (USA 0x020d9870, EUR 0x020d9880, JPN 0x020db27c)
extern "C" ARM void FieldTask_ConfirmEvac(struct Obj020d9870* self) {
#if defined(jpn)
    enum { Enum_020d9870_6578 = 0x17e2, Enum_020d9870_2456 = 0x868 };
#else
    enum { Enum_020d9870_6578 = 0x19b2, Enum_020d9870_2456 = 0x998 };
#endif
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    void* unkObj = gs->GetLeader();
    void* g1c = MessageSystem_GetInstance();
    FontBankLoader* g = FontBankLoader_GetInstance();
    void* t = LinkSession_GetInstance();
    char* f4 = GameState_GetFollowCamera((char*)gs);
    unsigned short* p = Zone3D_GetInstance();

    if (func_ov017_021959b4() != 0) {
        func_020d9a58(arg0);
        return;
    }

    if (self->state == 0) {
        if (LinkSession_IsActive((int*)t) != 0 && LinkSession_IsHostOrSolo(t) != 0) {
            func_ov017_021cf730(-1, 0);
        }
        func_020a27b8((unsigned char*)var5);
        arg0->unknown_8_ = 1;
    } else if (arg0->unknown_8_ == 1) {
        func_02094b30(var3, 0x20e, 0);
        arg0->unknown_8_ = 2;
    } else if (arg0->unknown_8_ == 2) {
        if (func_02094b4c(var3) != 0) {
            arg0->unknown_8_ = 3;
        }
    } else if (self->state == 3) {
        if (unkObj != NULL) {
            func_020531f0(unkObj);
            GameObject_DisableControl((Obj020397cc*)unkObj, 1);
        }
        func_020e11a4();
        func_02046380(var2);
#if defined(jpn)
        func_0204500c(var2, &data_020f29cc, 0);
#else
        func_0204500c(g1c, (void*)StandardStrings_Get(0x3e), 0, 0xe3);
#endif
        *(unsigned char*)((char*)var2 + Enum_020d9870_6578) = 0;
        *(int*)((char*)var2 + Enum_020d9870_2456) = 1;
        arg0->unknown_8_ = 4;
    } else if (arg0->unknown_8_ == 4) {
        if (*(int*)((char*)var2 + Enum_020d9870_2456) == 0) {
            if (func_020457e0(var2) == 0) {
                func_ov017_021ab860(*(short*)((char*)var1 + 4), 1);
                func_020e1154((void*)0xbb8);
            }
            MessageSystem_Reset((char*)g1c);
            self->state = 5;
        }
    } else if (self->state == 5) {
        GameObject_EnableControl(unkObj);
        InitBattleAndControllerState_020d9ab0(self);
    }

    if (ZoneId_IsGrottoBossFloor(*p) != 0) {
        return;
    }
    func_020d9ab0(arg0);
}
