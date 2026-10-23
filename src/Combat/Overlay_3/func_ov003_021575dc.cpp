#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};
extern "C" void* func_02010828(GameState*);

int FindMappedMemberId02080468(void* obj, int id);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
int IsTableValueNot99_02155ffc(void* obj, int id);
int IsCombatantFlagit2Set_02155f88_02155f88(void* obj, int id);
void ResetFields_0215873c(void* obj);
void SetFlag_02158a50_02158a50(unsigned char*);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
int IsAnimationActive0209ca2c(void* obj);
extern "C" void func_0206df6c(void* a, unsigned char* b, int c, int d);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
int TestBattleBlockBit_021ed6cc(int tag);
struct S020a13c4;
void ClearStruct020a13c4(S020a13c4*);
void SetupGlobalAndRunScript020a13e4(void* p0, void* p1, int p2, unsigned short p3, unsigned char p4);
struct BitfieldRecord020a1380;
void ResetBitfieldRecord(BitfieldRecord020a1380*);
struct Struct021580a0;
void InitBuffers_021580a0(Struct021580a0*);
struct Array020a15bc;
void* FindElementByField020a15bc(Array020a15bc*, int);
struct Obj02158140;
void AppendFormattedNumber_02158140(Obj02158140*, int);

int GetField0x3acValue_020100a8(GameState*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
void ItemTable_Init(void* obj);
ARM int BuildDescriptorFlag1_020de980(void* a, void* b, void* c, int d, int e);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
void SetCombatModeFromCase020dc2d0(int);
struct GameResources;
ARM int IsBrightnessTransitionActive(GameResources*);
extern "C" ARM void* func_0208247c(void* arg0);

extern "C" void __clear(void* arg0, int arg1);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* arg1, unsigned int* arg2);
extern "C" ARM int func_020813ec(void* arg0, int arg1);
extern "C" void func_0207d300(void* arg0, int arg1, int arg2, int arg3);
extern "C" void* func_0205ec34(void);
extern "C" void func_020e046c(void* arg0, void* arg1, int arg2, int arg3);
extern "C" void func_02082490(void* arg0, void* arg1, int arg2, int arg3, int arg4);
extern "C" void func_ov003_02158334(void* arg0);
extern "C" int func_ov003_021550dc(void* arg0);
extern "C" int func_ov003_02155208(void* arg0);
extern "C" int func_ov003_02155fc0(void* arg0, int arg1);
extern "C" void func_ov003_02155580(void* arg0, int arg1);
extern "C" int func_ov003_02155618(void* arg0);
extern "C" void func_ov003_02155e38(void* arg0);
extern "C" void func_ov003_021580d8(void* arg0, void* arg1);
extern "C" int func_ov003_02158754(void* arg0);
extern "C" int func_ov023_021ed724(void* arg0, void* arg1, int arg2);
extern "C" void func_ov023_021eb138(void* arg0, int arg1);
extern "C" void func_ov023_021eb080(void* arg0, void* arg1);
extern "C" void func_ov023_021eb564(void* arg0, void* arg1, int arg2);
extern "C" void func_ov023_021eb43c(void* arg0);
extern "C" void func_ov023_021eb26c(void* arg0);

extern char g_sePlayer;
extern char data_ov003_0217fdbb;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern short data_ov003_0217f2e8[];
extern char data_02109bf4;
extern short data_ov003_0217f2ce[];
extern char data_ov003_0217fdd0;
extern char data_ov003_0217fde7;

struct Struct_ov003_021575dc_3 { unsigned char unknown_0_0_ : 1; };

// USA: func_ov003_021575dc
extern "C" ARM void func_ov003_021575dc(void* arg0) {
    char* var0 = (char*)arg0;
    GameState* var1 = GameState::GetInstance();
    void* var2 = func_02010828(var1);
    unsigned char var3 = *(unsigned char*)(var0 + 0x1f9);
    void* var4;
    short* var5 = (short*)(var0 + 0x1ec);
    void* var6 = *(void**)(var0 + 0x18);

    if (var3 == 0) {
        *(short*)(var0 + 0x1e6) = 3;
        unsigned char var7 = *(unsigned char*)((char*)var2 + 0xf7c);
        switch (var7) {
        case 3: *(short*)(var0 + 0x1e6) = 4; break;
        case 4: *(short*)(var0 + 0x1e6) = 5; break;
        }
        if (*(short*)(var0 + 0x1e2) < 0) {
            short var8 = (short)func_02080468(var6, *(short*)(var0 + 0x1e6));
            *(short*)(var0 + 0x1e2) = var8;
            *(short*)(var0 + 0x1e8) = *(short*)(var0 + 0x1e2);
        }
        *(short*)((char*)obj18 + 0x36) = *(short*)(s + 0x1e2);
        func_ov003_02158334(self);
        ResetWithSub0208203c((Obj0208203c*)(s + 0x80));
        *(int*)(s + 8) = 0;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 1) {
        *(void**)(s + 8) = (void*)(s + 0x1e2);
        if (func_ov003_021550dc(self) != 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)(s + 0x80));
            *(void**)(s + 8) = 0;
            int mm = FindMappedMemberId02080468(obj18, *(short*)(s + 0x1e6));
            short diff = *(short*)(s + 0x1e2) - mm;
            unsigned char v = *(unsigned char*)(s + 0x1f2 + diff);
            *(unsigned char*)(s + 0x1f7) = v;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
        } else if (func_ov003_02155208(self) != 0) {
            *(void**)(s + 8) = 0;
            evt[0] = 7;
            *(unsigned char*)(s + 0x1f8) = 7;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
        }
    } else if (var3 == 2) {
        signed char var12 = *(signed char*)(var0 + 0x1f7);
        if (func_ov003_02155ffc(arg0, var12) != 0) {
            var5[0] = 0x10;
            *(unsigned char*)(var0 + 0x1f8) = 7;
            return;
        }
        var5[0] = 0x11;
        var12 = *(signed char*)(var0 + 0x1f7);
        if (func_ov003_02155fc0(arg0, var12) != 0) {
            var5[1] = 0x41;
            *(unsigned char*)(var0 + 0x1f8) = 7;
            func_0207fe44((Struct_0207fe44*)var6);
            return;
        }
        var12 = *(signed char*)(var0 + 0x1f7);
        if (func_ov003_02155f88(arg0, var12) != 0) {
            var5[1] = 0x12;
            *(unsigned char*)(var0 + 0x1f8) = 7;
            func_0207fe44((Struct_0207fe44*)var6);
            return;
        }
        var5[1] = 0x13;
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
    } else if (var3 == 3) {
        func_ov003_02155580(arg0, 1);
        *(short*)(var0 + 0x1e8) = *(short*)(var0 + 0x1ea) = 7;
        *(short*)((char*)*(void**)(var0 + 0x18) + 0x36) = *(short*)(var0 + 0x1ea);
        func_020813ec(*(void**)(var0 + 0x18), *(short*)(var0 + 0x1e6));
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
    } else if (var3 == 4) {
        int var13 = func_ov003_02155618(arg0);
        if (var13 == -1) goto state4_neg1;
        if (var13 != 1) goto state4_done;
        var5[0] = 0x15;
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
        goto state4_done;
    state4_neg1:
        var5[0] = 0x14;
        *(unsigned char*)(var0 + 0x1f8) = 7;
    state4_done:;
    } else if (var3 == 5) {
        BackgroundLoader* var14 = BackgroundLoader::GetInstance();
        signed char var15 = *(signed char*)(var0 + 0x1f7);
        int var16 = 0;
        GameObject* var17 = var1->GetPartyMemberByIndex(var15);
        if (var17 != 0) {
            void* var18 = *(void**)((char*)var17 + 0x150);
            var16 = *(int*)((char*)var18 + 0x950);
        }
        char var19[0x18];
        __clear(var19, 0x18);
        sprintf(var19, &data_ov003_0217fdbb, var16);
        *(int*)(var0 + 0x1d0) = var14->QueueLoadFile(var19, (SafeAllocator*)0);
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
    } else if (var3 == 6) {
        BackgroundLoader* var20 = BackgroundLoader::GetInstance();
        if (var20->GetTaskStatus(*(int*)(var0 + 0x1d0)) != 0) {
            void* var21; unsigned int var22;
            var20->GetLoadedFileByID(*(int*)(var0 + 0x1d0), &var21, &var22);
            func_0208247c(var0 + 0x90);
            if (var21 != 0) {
                func_02082490(var0 + 0x90, var21, var22, 1, 0);
            }
            var20->RemoveTask(*(int*)(var0 + 0x1d0));
            *(int*)(var0 + 0x1d0) = -1;
            *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
        }
    } else if (state == 7) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        *(int*)(s + 0x1d0) = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, (SafeAllocator*)0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 8) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(s + 0x1d0)) != 0) {
            void* outPtr; unsigned int outLen;
            loader->GetLoadedFileByID(*(int*)(s + 0x1d0), &outPtr, &outLen);
            ((SafeAllocator*)(*(char**)s + 0x78))->Reset();
            *(short*)(s + 0x1f0) = -1;
            signed char idx = *(signed char*)(s + 0x1f7);
            GameObject* comb = bs->GetPartyMemberByIndex(idx);
            if (comb != 0) {
                void* p150 = *(void**)((char*)comb + 0x150);
                int field950 = *(int*)((char*)p150 + 0x950);
                *(short*)(s + 0x1f0) = data_ov003_0217f2e8[field950];
            }
            loader->RemoveTask(*(int*)(s + 0x1d0));
            *(int*)(s + 0x1d0) = -1;
            short f0val = *(short*)(s + 0x1f0);
            ItemTable_Init(s + 0x178);
            BuildDescriptorFlag1_020de980(s + 0x178, *(char**)s + 0x78, outPtr, outLen, f0val);
            *(unsigned char*)(s + 0x338) = 1;
            ResetFields_0215873c(self);
            *(unsigned char*)(s + 0x1f9) = 0x32;
        }
    } else if (var3 == 9) {
        func_02043204((char*)func_020421a0());
        func_ov003_02158a50((unsigned char*)arg0);
        func_0209c830((Struct_02109bf4_2*)&data_02109bf4, 0x34);
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
    } else if (var3 == 0xa) {
        if (func_0209ca2c(&data_02109bf4) != 0) {
            goto tail;
        }
        if (((Object3D*)(var0 + 0x280))->HasAnimationStopped() == 0) {
            goto tail;
        }
        *(int*)(var0 + 0x32c) = 0;
        func_ov003_02155e38(arg0);
        signed char var32 = *(signed char*)(var0 + 0x1f7);
        GameObject* var33 = var1->GetPartyMemberByIndex(var32);
        int var34 = -1;
        if (var33 != 0) {
            void* var35 = *(void**)((char*)var33 + 0x150);
            var34 = *(int*)((char*)var35 + 0x950);
        }
        if (var34 > 0) {
            void* var36 = func_0205ec34();
            if (func_0206dfb0((int)var36, (unsigned char*)var36 + 0x8c, var34 + 0x8b + 0x1100) == 0) {
                func_0206df6c(var36, (unsigned char*)var36 + 0x8c, var34 + 0x8b + 0x1100, 1);
                var5[0] = 0x16;
                var5[1] = 0x17;
                *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;

                char var37[0x38];
                ((SafeAllocator*)var37)->ResetAllocatorPointer();
                func_020de824(var37 + 0x14);
                func_0207cbe8(var37);
                func_0207cbe8(var37);
                *(void**)(var37 + 0x2c) = var0 + 0x178;
                func_0207d300(var37, *(short*)(var0 + 0x1f0), 1, 0);
                func_0207cc0c(var37);
                return;
            }
        }
        *(unsigned char*)(var0 + 0x1f9) = 0x64;
    } else if (var3 == 0xb) {
        var5[0] = 0x18;
        var5[1] = 0x19;
        *(unsigned char*)(var0 + 0x1f8) = 7;
    } else if (var3 == 0x64) {
        short var38[12];
        __clear(var38, 0x18);
        unsigned short var39 = 0;
        int var40 = func_020100a8(var1);
        struct Struct_0203d028_3* var41 = (Struct_0203d028_3*)func_0200ff1c(var1, var40);
        for (int var42 = 1; var42 < 13; var42++) {
            void* var43 = *(void**)((char*)var41 + 0x150);
            if (*(unsigned char*)((char*)var43 + (unsigned char)var42 + 0x186) >= 0xa) {
                short var44 = data_ov003_0217f2ce[var42];
                if (func_ov023_021ed6cc(var44) == 0) {
                    var38[var39] = var44;
                    var39++;
                }
            }
        }
        if (var39 == 0) goto emptyResult0x64;
        {
            var4 = *(void**)var0;
            ((SafeAllocator*)((char*)var4 + 0x64))->Reset();
            char var45[0x14];
            func_020a13c4((Struct_020a13c4*)var45);
            func_020a13e4(var45, (char*)var4 + 0x64, (int)var38, var39, 8);

            char var46[12 * 0x244];
            char* var47 = var46;
            do {
                func_020a1380((Struct_020a1180*)var47);
                func_ov003_021580a0((Struct_ov003_021575dc*)var47);
                var47 += 0x244;
            } while (var47 < var46 + sizeof(var46));

            short var48[12];
            __clear(var48, 0x18);
            int var49 = 0;
            for (int var50 = 0; var50 < var39; var50++) {
                short var51 = var38[var50];
                void* var52 = func_020a15bc((Struct_020a15bc*)var45, var51);
                if (var52 != 0) {
                    func_ov003_021580a0((Struct_ov003_021575dc*)(var46 + var49 * 0x244));
                    func_ov003_021580d8(var46 + var49 * 0x244, var52);
                    char var53[0x38];
                    __clear(var53, 0x38);
                    BackgroundLoader::AddLockGlobal();
                    unsigned int var54 = 0;
                    char var55[0x40];
                    __clear(var55, 0x40);
                    char var56[0x20];
                    __clear(var56, 0x20);
                    int var57 = ((struct Struct_ov003_021575dc_3*)((char*)*(void**)((char*)var41 + 0x150) + 0x49c))->unknown_0_0_;
                    sprintf(var55, &data_ov003_0217fdd0, var57);
                    int var58 = ((struct Struct_ov003_021575dc_3*)((char*)*(void**)((char*)var41 + 0x150) + 0x49c))->unknown_0_0_;
                    sprintf(var56, &data_ov003_0217fde7, var58);
                    void* var59 = ExtractFileFromGP2(var55, var56, &var54);
                    if (var59 != 0) {
                        func_020e046c(var53, var59, var54, var38[var50]);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    func_ov003_02158140((Struct_ov003_021575dc_2*)(var46 + var49 * 0x244), (int)var53);
                    var48[var49] = var38[var50];
                    var49++;
                }
            }
            if (var49 <= 0) goto emptyResult0x64;
            {
                int var60 = func_ov023_021ed724(var45, var48, var49);
                ((SafeAllocator*)((char*)var4 + 0x64))->Reset();
                *(void**)(var0 + 0x200) = ((SafeAllocator*)((char*)var4 + 0x64))->Allocate(var49 * 0x244);
                for (int var61 = 0; var61 < var49; var61++) {
                    char* var62 = var46 + var61 * 0x244;
                    char* var63 = (char*)*(void**)(var0 + 0x200) + var61 * 0x244;
                    func_ov003_021580a0((Struct_ov003_021575dc*)var63);
                    func_ov003_021580d8(var63, var62);
                    func_ov003_02158140((Struct_ov003_021575dc_2*)var63, (int)(var62 + 0xc));
                }
                void* var64 = ((SafeAllocator*)((char*)var4 + 0x64))->Allocate(1100);
                *(void**)(var0 + 0x204) = var64;
                func_ov023_021eb138(var64, 6);
                func_ov023_021eb080(*(void**)(var0 + 0x204), (char*)var4 + 0x64);
                func_ov023_021eb564(*(void**)(var0 + 0x204), *(void**)(var0 + 0x200), var39);
                char* var65 = *(char**)(var0 + 0x204);
                if (var60 & 1) {
                    *(unsigned short*)(var65 + 0x438) |= 0x400;
                } else {
                    *(unsigned short*)(var65 + 0x438) &= ~0x400;
                }
                char* var66 = (char*)*(void**)(var0 + 0x204);
                unsigned short* var67;
                var66 += 0x400;
                var67 = (unsigned short*)(var66 + 0x38);
                *var67 = *var67 | 0x10;
                *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
                return;
            }
        }
        goto stateEnd;
    emptyResult0x64:
        *(unsigned char*)(var0 + 0x338) = 0;
        var5[0] = 0x16;
        var5[1] = 0x19;
        *(unsigned char*)(var0 + 0x1f8) = 7;
    stateEnd:;
    } else if (var3 == 0x65) {
        if (*(void**)(var0 + 0x204) != 0) {
            func_ov023_021eb43c(*(void**)(var0 + 0x204));
            if (*(unsigned short*)(*(char**)(var0 + 0x204) + 0x438) & 4) {
                func_ov023_021eb26c(*(void**)(var0 + 0x204));
                ((SafeAllocator*)(*(char**)var0 + 0x64))->Reset();
                *(void**)(var0 + 0x200) = 0;
                *(void**)(var0 + 0x204) = 0;
                *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
            }
        }
    } else if (var3 == 0x66) {
        Struct_0208cb08* var68 = func_02094a00();
        func_02094b40(var68);
        func_02094b34(var68, 0x66, 501, 0, 0);
        *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
    } else if (var3 == 0x67) {
        if (func_02094b4c(func_02094a00()) != 0) {
            func_020dc2d0(0);
            *(unsigned char*)(var0 + 0x1f9) = *(unsigned char*)(var0 + 0x1f9) + 1;
        }
    } else if (var3 == 0x68) {
        GameResources* var69 = GetGameResources();
        if (IsBrightnessTransitionActive(var69) != 0) {
            return;
        }
        *(unsigned char*)(var0 + 0x338) = 0;
        var5[0] = 0x16;
        var5[1] = 0x19;
        *(unsigned char*)(var0 + 0x1f8) = 7;
    }

tail:
    if (*(unsigned char*)(var0 + 0x1f9) == 0x32) {
        if (func_ov003_02158754(arg0) != 0) {
            *(unsigned char*)(var0 + 0x1f9) = 9;
        }
    }
}
