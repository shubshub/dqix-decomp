#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"


struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" void* GameState_GetParty(GameState*);

extern "C" int func_02080468(void* obj, int id);
struct Struct_02081f20_2;
extern "C" void func_0208203c(Struct_02081f20_2*);
struct SePlayer;
extern "C" void SePlayer_Play(SePlayer*, int, int);
struct Struct_0207fe44;
extern "C" void func_0207fe44(Struct_0207fe44*);
extern "C" int func_ov003_02155ffc(void* obj, int id);
extern "C" int func_ov003_02155f88(void* obj, int id);
extern "C" void func_ov003_0215873c(void* obj);
extern "C" void func_ov003_02158a50(unsigned char*);
struct Struct0209c830;
extern "C" void func_0209c830(Struct0209c830*, int);
extern "C" int func_0209ca2c(void* obj);
extern "C" void Scenario_SetFlag(void* a, unsigned char* b, int c, int d);
extern "C" void* ItemTable_Construct(void* obj);
extern "C" void func_0207cbe8(char* obj);
extern "C" void func_0207cc0c(char* obj);
extern "C" int func_ov023_021ed6cc(int tag);
struct Struct_020a13c4;
extern "C" void func_020a13c4(Struct_020a13c4*);
extern "C" void func_020a13e4(void* p0, void* p1, int p2, unsigned short p3, unsigned char p4);
struct Struct_020a1180;
extern "C" void func_020a1380(Struct_020a1180*);
struct Struct_ov003_021575dc;
extern "C" void func_ov003_021580a0(Struct_ov003_021575dc*);
struct Struct_020a15bc;
extern "C" void* func_020a15bc(Struct_020a15bc*, int);
struct Struct_ov003_021575dc_2;
extern "C" void func_ov003_02158140(Struct_ov003_021575dc_2*, int);

extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void ItemTable_Init(void* obj);
extern "C" ARM int func_020de980(void* a, void* b, void* c, int d, int e);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_020dc2d0(int);
struct GameResources;
ARM int IsBrightnessTransitionActive(GameResources*);
extern "C" ARM void* ResourceScriptEntry_Init(void* obj);

extern "C" void __clear(void* buf, int len);
extern "C" void* ExtractFileFromGP2(const char* arg0, const char* innerFilePath, unsigned int* outSize);
extern "C" ARM int func_020813ec(void* obj, int id);
extern "C" void func_0207d300(void* obj, int a, int b, int c);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_020e046c(void* a, void* b, int c, int d);
extern "C" void ResourceScriptEntry_LoadLevel(void* a, void* b, int c, int d, int e);
extern "C" void func_ov003_02158334(void* self);
extern "C" int func_ov003_021550dc(void* self);
extern "C" int func_ov003_02155208(void* self);
extern "C" int func_ov003_02155fc0(void* self, int id);
extern "C" void func_ov003_02155580(void* self, int a);
extern "C" int func_ov003_02155618(void* self);
extern "C" void func_ov003_02155e38(void* self);
extern "C" void func_ov003_021580d8(void* dst, void* src);
extern "C" int func_ov003_02158754(void* self);
extern "C" int func_ov023_021ed724(void* a, void* b, int c);
extern "C" void func_ov023_021eb138(void* a, int b);
extern "C" void func_ov023_021eb080(void* a, void* b);
extern "C" void func_ov023_021eb564(void* a, void* b, int c);
extern "C" void func_ov023_021eb43c(void* a);
extern "C" void func_ov023_021eb26c(void* a);

extern char g_sePlayer;
extern char data_ov003_0217fdbb;
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern short data_ov003_0217f2e8[];
extern char g_bgmPlayer;
extern short data_ov003_0217f2ce[];
extern char data_ov003_0217fdd0;
extern char data_ov003_0217fde7;

struct Struct_ov003_021575dc_3 { unsigned char bit0 : 1; };

// USA: func_ov003_021575dc
extern "C" ARM void func_ov003_021575dc(void* self) {
    char* s = (char*)self;
    GameState* bs = GameState::GetInstance();
    void* p2a04 = GameState_GetParty(bs);
    unsigned char state = *(unsigned char*)(s + 0x1f9);
    void* root;
    short* evt = (short*)(s + 0x1ec);
    void* var6 = *(void**)(s + 0x18);

    if (state == 0) {
        *(short*)(s + 0x1e6) = 3;
        unsigned char v = *(unsigned char*)((char*)p2a04 + 0xf7c);
        switch (v) {
        case 3: *(short*)(s + 0x1e6) = 4; break;
        case 4: *(short*)(s + 0x1e6) = 5; break;
        }
        if (*(short*)(s + 0x1e2) < 0) {
            short id = (short)func_02080468(var6, *(short*)(s + 0x1e6));
            *(short*)(s + 0x1e2) = id;
            *(short*)(s + 0x1e8) = *(short*)(s + 0x1e2);
        }
        *(short*)((char*)var6 + 0x36) = *(short*)(s + 0x1e2);
        func_ov003_02158334(self);
        func_0208203c((Struct_02081f20_2*)(s + 0x80));
        *(int*)(s + 8) = 0;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 1) {
        *(void**)(s + 8) = (void*)(s + 0x1e2);
        if (func_ov003_021550dc(self) != 0) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
            func_0208203c((Struct_02081f20_2*)(s + 0x80));
            *(void**)(s + 8) = 0;
            int var9 = func_02080468(var6, *(short*)(s + 0x1e6));
            short diff = *(short*)(s + 0x1e2) - var9;
            unsigned char v = *(unsigned char*)(s + 0x1f2 + diff);
            *(unsigned char*)(s + 0x1f7) = v;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            func_0207fe44((Struct_0207fe44*)var6);
        } else if (func_ov003_02155208(self) != 0) {
            *(void**)(s + 8) = 0;
            evt[0] = 7;
            *(unsigned char*)(s + 0x1f8) = 7;
            func_0207fe44((Struct_0207fe44*)var6);
        }
    } else if (state == 2) {
        signed char idx = *(signed char*)(s + 0x1f7);
        if (func_ov003_02155ffc(self, idx) != 0) {
            evt[0] = 0x10;
            *(unsigned char*)(s + 0x1f8) = 7;
            return;
        }
        evt[0] = 0x11;
        idx = *(signed char*)(s + 0x1f7);
        if (func_ov003_02155fc0(self, idx) != 0) {
            evt[1] = 0x41;
            *(unsigned char*)(s + 0x1f8) = 7;
            func_0207fe44((Struct_0207fe44*)var6);
            return;
        }
        idx = *(signed char*)(s + 0x1f7);
        if (func_ov003_02155f88(self, idx) != 0) {
            evt[1] = 0x12;
            *(unsigned char*)(s + 0x1f8) = 7;
            func_0207fe44((Struct_0207fe44*)var6);
            return;
        }
        evt[1] = 0x13;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 3) {
        func_ov003_02155580(self, 1);
        *(short*)(s + 0x1e8) = *(short*)(s + 0x1ea) = 7;
        *(short*)((char*)*(void**)(s + 0x18) + 0x36) = *(short*)(s + 0x1ea);
        func_020813ec(*(void**)(s + 0x18), *(short*)(s + 0x1e6));
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 4) {
        int r = func_ov003_02155618(self);
        if (r == -1) goto state4_neg1;
        if (r != 1) goto state4_done;
        evt[0] = 0x15;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        goto state4_done;
    state4_neg1:
        evt[0] = 0x14;
        *(unsigned char*)(s + 0x1f8) = 7;
    state4_done:;
    } else if (state == 5) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        signed char idx = *(signed char*)(s + 0x1f7);
        int val = 0;
        GameObject* comb = bs->GetPartyMemberByIndex(idx);
        if (comb != 0) {
            void* var18 = *(void**)((char*)comb + 0x150);
            val = *(int*)((char*)var18 + 0x950);
        }
        char buf[0x18];
        __clear(buf, 0x18);
        sprintf(buf, &data_ov003_0217fdbb, val);
        *(int*)(s + 0x1d0) = loader->QueueLoadFile(buf, (SafeAllocator*)0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 6) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(s + 0x1d0)) != 0) {
            void* outPtr; unsigned int outLen;
            loader->GetLoadedFileByID(*(int*)(s + 0x1d0), &outPtr, &outLen);
            ResourceScriptEntry_Init(s + 0x90);
            if (outPtr != 0) {
                ResourceScriptEntry_LoadLevel(s + 0x90, outPtr, outLen, 1, 0);
            }
            loader->RemoveTask(*(int*)(s + 0x1d0));
            *(int*)(s + 0x1d0) = -1;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
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
                void* var29 = *(void**)((char*)comb + 0x150);
                int field950 = *(int*)((char*)var29 + 0x950);
                *(short*)(s + 0x1f0) = data_ov003_0217f2e8[field950];
            }
            loader->RemoveTask(*(int*)(s + 0x1d0));
            *(int*)(s + 0x1d0) = -1;
            short var31 = *(short*)(s + 0x1f0);
            ItemTable_Init(s + 0x178);
            func_020de980(s + 0x178, *(char**)s + 0x78, outPtr, outLen, var31);
            *(unsigned char*)(s + 0x338) = 1;
            func_ov003_0215873c(self);
            *(unsigned char*)(s + 0x1f9) = 0x32;
        }
    } else if (state == 9) {
        MessageSystem_Reset((char*)MessageSystem_GetInstance());
        func_ov003_02158a50((unsigned char*)self);
        func_0209c830((Struct0209c830*)&g_bgmPlayer, 0x34);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0xa) {
        if (func_0209ca2c(&g_bgmPlayer) != 0) {
            goto tail;
        }
        if (((Object3D*)(s + 0x280))->HasAnimationStopped() == 0) {
            goto tail;
        }
        *(int*)(s + 0x32c) = 0;
        func_ov003_02155e38(self);
        signed char idx = *(signed char*)(s + 0x1f7);
        GameObject* comb = bs->GetPartyMemberByIndex(idx);
        int field950 = -1;
        if (comb != 0) {
            void* var35 = *(void**)((char*)comb + 0x150);
            field950 = *(int*)((char*)var35 + 0x950);
        }
        if (field950 > 0) {
            void* base = Scenario_GetInstance();
            if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100) == 0) {
                Scenario_SetFlag(base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100, 1);
                evt[0] = 0x16;
                evt[1] = 0x17;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;

                char bufFc[0x38];
                ((SafeAllocator*)bufFc)->ResetAllocatorPointer();
                ItemTable_Construct(bufFc + 0x14);
                func_0207cbe8(bufFc);
                func_0207cbe8(bufFc);
                *(void**)(bufFc + 0x2c) = s + 0x178;
                func_0207d300(bufFc, *(short*)(s + 0x1f0), 1, 0);
                func_0207cc0c(bufFc);
                return;
            }
        }
        *(unsigned char*)(s + 0x1f9) = 0x64;
    } else if (state == 0xb) {
        evt[0] = 0x18;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    } else if (state == 0x64) {
        short var38[12];
        __clear(var38, 0x18);
        unsigned short var39 = 0;
        int fieldVal = GameState_GetProtagonistIndex(bs);
        struct CombatantStruct* combatant = (CombatantStruct*)func_0200ff1c(bs, fieldVal);
        for (int i = 1; i < 13; i++) {
            void* var43 = *(void**)((char*)combatant + 0x150);
            if (*(unsigned char*)((char*)var43 + (unsigned char)i + 0x186) >= 0xa) {
                short tag = data_ov003_0217f2ce[i];
                if (func_ov023_021ed6cc(tag) == 0) {
                    var38[var39] = tag;
                    var39++;
                }
            }
        }
        if (var39 == 0) goto emptyResult0x64;
        {
            root = *(void**)s;
            ((SafeAllocator*)((char*)root + 0x64))->Reset();
            char scratch[0x14];
            func_020a13c4((Struct_020a13c4*)scratch);
            func_020a13e4(scratch, (char*)root + 0x64, (int)var38, var39, 8);

            char arr[12 * 0x244];
            char* p = arr;
            do {
                func_020a1380((Struct_020a1180*)p);
                func_ov003_021580a0((Struct_ov003_021575dc*)p);
                p += 0x244;
            } while (p < arr + sizeof(arr));

            short outBuf[12];
            __clear(outBuf, 0x18);
            int outCount = 0;
            for (int j = 0; j < var39; j++) {
                short tag = var38[j];
                void* found = func_020a15bc((Struct_020a15bc*)scratch, tag);
                if (found != 0) {
                    func_ov003_021580a0((Struct_ov003_021575dc*)(arr + outCount * 0x244));
                    func_ov003_021580d8(arr + outCount * 0x244, found);
                    char buf80[0x38];
                    __clear(buf80, 0x38);
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outLen = 0;
                    char buf40[0x40];
                    __clear(buf40, 0x40);
                    char var56[0x20];
                    __clear(var56, 0x20);
                    int var57 = ((struct Struct_ov003_021575dc_3*)((char*)*(void**)((char*)combatant + 0x150) + 0x49c))->bit0;
                    sprintf(buf40, &data_ov003_0217fdd0, var57);
                    int bit2 = ((struct Struct_ov003_021575dc_3*)((char*)*(void**)((char*)combatant + 0x150) + 0x49c))->bit0;
                    sprintf(var56, &data_ov003_0217fde7, bit2);
                    void* var59 = ExtractFileFromGP2(buf40, var56, &outLen);
                    if (var59 != 0) {
                        func_020e046c(buf80, var59, outLen, var38[j]);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    func_ov003_02158140((Struct_ov003_021575dc_2*)(arr + outCount * 0x244), (int)buf80);
                    outBuf[outCount] = var38[j];
                    outCount++;
                }
            }
            if (outCount <= 0) goto emptyResult0x64;
            {
                int flags = func_ov023_021ed724(scratch, outBuf, outCount);
                ((SafeAllocator*)((char*)root + 0x64))->Reset();
                *(void**)(s + 0x200) = ((SafeAllocator*)((char*)root + 0x64))->Allocate(outCount * 0x244);
                for (int k = 0; k < outCount; k++) {
                    char* src = arr + k * 0x244;
                    char* elem = (char*)*(void**)(s + 0x200) + k * 0x244;
                    func_ov003_021580a0((Struct_ov003_021575dc*)elem);
                    func_ov003_021580d8(elem, src);
                    func_ov003_02158140((Struct_ov003_021575dc_2*)elem, (int)(src + 0xc));
                }
                void* var64 = ((SafeAllocator*)((char*)root + 0x64))->Allocate(1100);
                *(void**)(s + 0x204) = var64;
                func_ov023_021eb138(var64, 6);
                func_ov023_021eb080(*(void**)(s + 0x204), (char*)root + 0x64);
                func_ov023_021eb564(*(void**)(s + 0x204), *(void**)(s + 0x200), var39);
                char* menu = *(char**)(s + 0x204);
                if (flags & 1) {
                    *(unsigned short*)(menu + 0x438) |= 0x400;
                } else {
                    *(unsigned short*)(menu + 0x438) &= ~0x400;
                }
                char* var66 = (char*)*(void**)(s + 0x204);
                unsigned short* var67;
                var66 += 0x400;
                var67 = (unsigned short*)(var66 + 0x38);
                *var67 = *var67 | 0x10;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
                return;
            }
        }
        goto stateEnd;
    emptyResult0x64:
        *(unsigned char*)(s + 0x338) = 0;
        evt[0] = 0x16;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    stateEnd:;
    } else if (state == 0x65) {
        if (*(void**)(s + 0x204) != 0) {
            func_ov023_021eb43c(*(void**)(s + 0x204));
            if (*(unsigned short*)(*(char**)(s + 0x204) + 0x438) & 4) {
                func_ov023_021eb26c(*(void**)(s + 0x204));
                ((SafeAllocator*)(*(char**)s + 0x64))->Reset();
                *(void**)(s + 0x200) = 0;
                *(void**)(s + 0x204) = 0;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            }
        }
    } else if (state == 0x66) {
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b40(g);
        func_02094b34(g, 0x66, 501, 0, 0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0x67) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            func_020dc2d0(0);
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        }
    } else if (state == 0x68) {
        GameResources* r = GetGameResources();
        if (IsBrightnessTransitionActive(r) != 0) {
            return;
        }
        *(unsigned char*)(s + 0x338) = 0;
        evt[0] = 0x16;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    }

tail:
    if (*(unsigned char*)(s + 0x1f9) == 0x32) {
        if (func_ov003_02158754(self) != 0) {
            *(unsigned char*)(s + 0x1f9) = 9;
        }
    }
}
