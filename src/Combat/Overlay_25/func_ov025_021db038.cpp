#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Memory/SafeAllocator.h"
#include <std_library_functions.h>
#include "Resource/Brightness.h"

struct Struct_ov000_02161e30 { char unknown_0_[0x8e14]; signed char unknown_8e14_; char unknown_8e15_[0xb]; int unknown_8e20_; int unknown_8e24_; };
struct Struct_ov025_021db038 {
    int unknown_0_;
    char unknown_4_[0x80];
    int unknown_84_;
    char unknown_88_[0x18];
    unsigned char unknown_a0_;
    unsigned char unknown_a1_;
};
struct Struct_ov000_021537b8 {
    char unknown_0_[0x30]; SafeAllocator unknown_30_;
#if defined(jpn)
    char unknown_44_[0x138-0x30-sizeof(SafeAllocator)]; char unknown_14c_[0x218-0x138];
#else
    char unknown1_44_[0x14c-0x30-sizeof(SafeAllocator)]; char unknown_14c_[0x29c-0x14c];
#endif

#if defined(jpn)
    Struct_ov000_02161e30* unknown_29c_; char unknown_21c_[8]; char unknown_2a8_[0x9bc-0x224];
#else
    Struct_ov000_02161e30* unknown_29c_; char unknown_2a0_[8]; char unknown_2a8_[0xa40-0x2a8];
#endif

#if defined(jpn)
    Struct_ov025_021db038 unknown_a40_; char unknown_a60_[0xaac-0xa60];
#else
    Struct_ov025_021db038 unknown_a40_; char unknown_ae4_[0xb30-0xae4];
#endif

#if defined(jpn)
    char unknown_b30_[0xb94-0xaac]; char unknown_c18_[0xdf4-0xb94];
#else
    char unknown_b30_[0xc18-0xb30]; char unknown_c18_[0xe78-0xc18];
#endif

#if defined(jpn)
    unsigned char unknown_e78_; char unknown_df5_[0xe28-0xdf5]; int unknown_eac_;
#else
    unsigned char unknown_e78_; char unknown_e79_[0xeac-0xe79]; int unknown_eac_;
#endif

#if defined(jpn)
    char unknown_e2c_[0x57c8-0xe2c]; int unknown_55d8_;
#else
    char unknown_eb0_[0x55d8-0xeb0]; int unknown_55d8_;
#endif

#if defined(jpn)
    char unknown_57cc_[0x5b41-0x57cc]; unsigned char unknown_5951_0_ : 2; unsigned char unknown_5b41_2_ : 6;
#else
    char unknown_55dc_[0x5951-0x55dc]; unsigned char unknown_5951_0_ : 2; unsigned char unknown_5951_2_ : 6;
#endif

};
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;
struct Struct_ov000_02160094 { char unknown_0_[0x20]; unsigned short unknown_20_; };
struct Struct_ov000_021600f8 { int unknown_0_; char unknown_4_[8]; int unknown_c_; char unknown_10_[8]; unsigned char unknown_18_; char unknown_19_[2]; unsigned char unknown_1b_; };
#if defined(jpn)
struct Struct_02021b84 { char unknown_0_[0x868]; int unknown_998_; };
#else
struct Struct_02021b84 { char unknown_0_[0x998]; int unknown_998_; };
#endif

struct SePlayer;
struct Struct0216fe48;
struct ShortSetStruct0216fdf8;
struct Struct0216fd0c;
struct Struct0216fd38;
struct EntryTask0216fd80;
void* GetSlotPtr02160f20(void*);
extern "C" void* func_02057924();
unsigned char* GetField02163524(void*);
extern "C" unsigned char _ZZ16GetTimer021ef974vE1s __attribute__((aligned(4)));
extern SePlayer g_sePlayer;
extern "C" void func_ov025_021db6dc(Work*);
int ClassifyField0x81fe_ov000_0215fc60(char*);
ListNode02160094* GetNodeAtIndex02160094(List02160094*, int);
ListNode021600f8* GetNodeAtIndex021600f8(List021600f8*, int);
extern "C" void func_ov025_021e88d8(char*);
extern "C" void func_ov025_021e8a40(char*, int, int);
extern "C" void func_ov025_021e8a4c(char*, int);
extern "C" void func_ov000_0216df00(void*, int, int, int, float);
extern "C" void func_ov000_021626a0(void*, int, int);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void*, int);
void ClearCombatWorkFlags0x55f4_ov000_02160fbc(void*, int);
void SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov025_021dbe10(Work*);
void ResetStruct0216fe48(Struct0216fe48*);
void AppendUniqueShort0216fdf8(ShortSetStruct0216fdf8*, int);
void SetField0FromCallFunc0202fa38(Struct0216fd0c*);
MessageSystem* GetGlobalField0x1c020421a0();
void CheckOrSetFlagA0_0216fd38(Struct0216fd38*);
int GetArrayEntry_021e8a54_021e8a54(char*);
void BeginListEntryTask_0216fd80(EntryTask0216fd80*, int);
char* GetFieldByKeyFromWork0x88_ov000_0216fcfc(void*, int);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_02021b84*, char*, int, int);
#endif
extern "C" void func_ov025_021eedb0(char*);
extern "C" void func_ov025_021dcf14(Struct_ov000_021537b8*);
extern "C" void func_ov025_021de124(Struct_ov000_021537b8*);
extern "C" void func_ov025_021e9fc4(char*);
extern "C" void func_ov025_021dc168(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc324(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc590(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc694(Struct_ov000_021537b8*);
extern "C" void func_ov025_021dc880(Struct_ov000_021537b8*);
extern "C" void func_ov025_021db458(Struct_ov000_021537b8*);
extern "C" void func_ov025_021db7f8(Struct_ov000_021537b8*);
extern "C" void func_ov000_02160d80(void*, int);
inline unsigned int inline_ov025_021db038(unsigned int arg0) { return (arg0 + 3) & ~3; }

#if defined(jpn)
extern "C" void func_0204500c(Struct_02021b84*,char*,int);
#endif
// USA: func_ov025_021db038
extern "C" ARM void func_ov025_021db038(Struct_ov000_021537b8* arg0) {
    Struct_ov025_021db038* var0;
    Struct_ov000_02161e30* var1 = arg0->unknown_29c_;
    void* var2 = func_ov000_02160f20(arg0);
    GameState* var3 = GameState::GetInstance();
    GameResources* var4 = GetGameResources();
    func_02057924();
    func_ov000_02163524(arg0);
    _ZZ21inline_ov025_021dcf14vE1s = 0;
    var0 = &arg0->unknown_a40_;
    if (!arg0->unknown_e78_) _ZZ21inline_ov025_021dcf14vE1s = 1;
    if (!arg0->unknown_eac_) func_ov025_021db6dc(arg0);
    if (arg0->unknown_eac_ == 1) {
        int var5;
        Struct_ov000_021600f8* var6;
        Struct_ov000_02160094* var7;
        int var8;
        var8 = -1;
        if (func_ov000_0215fc60((char*)var1)) {
            var7 = func_ov000_02160094((Struct_ov000_0215440c_2*)var2, 0);
            var6 = func_ov000_021600f8((Struct_ov000_0215440c*)var2, 0);
            if (var7) {
                var5 = var7->unknown_20_;
                if (var1->unknown_8e20_ == 1 && var5 == 0xc0) {
                    func_ov025_021e88d8(arg0->unknown_2a8_);
                    func_ov025_021e8a40(arg0->unknown_2a8_, (int)&arg0->unknown_30_, (int)arg0->unknown_14c_);
                    func_ov025_021e8a4c(arg0->unknown_2a8_, (int)var1);
                    func_ov000_0216df00(arg0->unknown_c18_, var5, 0, 0, 1.8f);
                    func_ov000_021626a0(arg0, 4, 0);
                    func_ov000_021626a0(arg0, 0, 1);
                    func_ov000_02160fa8(arg0, 0x1000000);
                    if (func_ov000_0215fc60((char*)var1) == 1) var8 = 0x1ee;
                    else if (func_ov000_0215fc60((char*)var1) == 2) var8 = 0x211;
                }
                if (actor->id == 0) {
                    SePlayer_Play(&g_sePlayer, 7, 0);
                    if (target) { target->flags = 0; target->flag18 = 0; target->value = 0; target->flag1b = 0; }
                }
            }
        }
        func_ov025_021dbe10(arg0);
        if (var8 > 0) {
            func_ov000_0216fe48((Struct_ov000_0216fe48*)var0);
            func_ov000_0216fdf8((Struct_ov000_0216fdf8*)var0, (short)var8);
            func_ov000_0216fd0c((Struct_ov000_0216fd0c*)var0);
        }
    }
    if (func_ov000_02160fd4(arg0, 0x1000000)) {
        GameState* var9;
        char* var10;
        GameObject* var11;
        Struct_02021b84* var12;
        var9 = GameState::GetInstance();
        var12 = func_020421a0();
        Struct_ov025_021db038* var13 = &arg0->unknown_a40_;
        if (!var13->unknown_a0_) {
            func_ov000_0216fd38((Struct_ov000_0216fd38*)var13);
            if (!var13->unknown_a0_) return;
            func_ov000_0216fd80((Struct_ov000_0216fd80*)var13, func_ov025_021e8a54(arg0->unknown_2a8_));
            var11 = func_0200ff1c(var9, 0);
            var10 = 0;
            if (func_ov000_0215fc60((char*)var1) == 1) var10 = func_ov000_0216fcfc(var13, 0x1ee);
            else if (func_ov000_0215fc60((char*)var1) == 2) var10 = func_ov000_0216fcfc(var13, 0x211);
            if (!var11 || !var10) return;
            char* var14 = (char*)var11->baseStats_;
            int var15 = strlen(var10);
            var15 += strlen(var14);
            char* var16 = (char*)arg0->unknown_30_.Allocate(inline_ov025_021db038(var15 - 1));
            if (!var16) return;
            sprintf(var16, var10, var11->baseStats_);
#if defined(jpn)
            func_0204500c(var12, var16, 0);
#else
            func_0204500c(var12, var16, 0, 0xe3);
#endif

            var12->unknown_998_ = 1;
            return;
        }
        if (var12->unknown_998_) return;
        func_ov000_02160fbc(arg0, 0x1000000);
        return;
    }
    func_ov025_021eedb0(arg0->unknown_b30_);
    func_ov025_021dcf14(arg0);
    func_ov025_021de124(arg0);
    func_ov025_021e9fc4(arg0->unknown_2a8_);
    if (arg0->unknown_5951_0_ != 1) func_ov025_021dc168(arg0);
    if (arg0->unknown_eac_ == 6) func_ov025_021dc324(arg0);
    if (arg0->unknown_eac_ == 3) func_ov025_021dc590(arg0);
    if (arg0->unknown_eac_ == 4) func_ov025_021dc694(arg0);
    if (arg0->unknown_eac_ == 5) func_ov025_021dc880(arg0);
    func_ov025_021db458(arg0);
    if (arg0->unknown_55d8_ != var1->unknown_8e24_) return;
    func_ov025_021db7f8(arg0);
    if (arg0->unknown_29c_->unknown_8e14_ == 2) func_ov000_02160d80(arg0, 10);
    else if (arg0->unknown_29c_->unknown_8e14_ == 1) func_ov000_02160d80(arg0, 9);
    else {
        func_ov000_02160d80(arg0, 7);
        SetFlags00(var4, 0x800);
    }
    var3->SetGameSpeed(0x1000);
}
