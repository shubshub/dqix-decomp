#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "Input/Input.h"

#if defined(jpn)
#define REGION_VALUE(j, u) (j)
#define func_ov002_02168354 func_ov002_02168de4
#define data_ov002_0216d350 data_ov002_0216dacf
#define data_ov002_0216d368 data_ov002_0216dae7
#else
#define REGION_VALUE(j, u) (u)
#endif

struct Struct_ov002_02168d54_2;
struct Struct_ov002_02168d54_3;
struct Struct_ov002_02168d54_4;
struct Struct_ov002_02168d54_5;
struct Struct_ov002_02168d54_6;
struct Struct_ov002_02168d54_7;
struct Struct_ov002_02168d54_8;
struct Struct_ov002_02168d54_9;
struct Struct_ov002_0215624c_11;

extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov002_021682c0(char* self);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
void* GlobalFlags_GetInstance(void);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);
void OrGlobalFlag0x40_020dc2bc(void);
void ClearFirstTwoWords0209a338(Pair0209a338* p);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" int func_ov013_021870f0(char* obj);
extern "C" void func_ov013_02184360(char* obj, int v);
extern "C" void func_ov013_02184cf0(char* obj, SafeAllocator* alloc);
int GetField110ArrayValue021574d4(void* self, int index);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* gameState, int combatantId);
extern "C" void func_ov013_02184b4c(char* obj, GameObject* combatant);
extern "C" void func_ov002_02168354(char* self);
extern "C" void func_ov013_0218782c(char* obj, int a, int b);
void HandleFieldFlagsAndState021870c0(void* obj);
extern "C" void func_ov002_021685bc(char* self);
extern "C" void _Z31UpdateBattleTagCounter_0216885cPc(char* self);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
void PushInputLogB_020a1ef0(int id);
void Reset0209fe9c(char* obj);
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4* obj, SafeAllocator* alloc, int data, int length);
void SetIntAt0x60(IntField0x60_0209ff64* obj, int v);
void PollOv017Task0209ff6c(TaskState0209ff6c* task);
int AreFields60And64BothNegOne_02168c00(unsigned char* obj);
extern "C" void func_ov013_02186fa0(char* obj);
extern "C" void func_ov002_021688f8(char* self);
void ResetListHeader020727ec(List020727d8* list);
void Zero4Bytes020e5280(void* obj);
extern "C" void func_ov023_021eb138(char* obj, int v);
extern "C" void func_ov023_021eb080(char* obj, SafeAllocator* alloc);
extern "C" void func_ov023_021eb564(char* obj, int a, int b);
extern "C" void func_ov023_021eb26c(void* obj);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, unsigned int pixel1Source, unsigned int pixel2Source, unsigned int pixel1Alpha, unsigned int pixel2Alpha);
void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
void PopStack1AndTrigger_020a1f4c(int flag);
void SetCombatModeFromCase020dc2d0(int mode);
extern "C" void func_ov002_0215a938(char* self);
extern "C" void func_ov002_02161cf0(char* base);
void FindAndLinkMatchingEntry0205de24(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_02160274(char* self);

extern char data_ov002_0216d350;
extern char data_ov002_0216d368;

// USA: func_ov002_02168d54; JPN: func_ov002_021695d8
#if defined(jpn)
extern "C" ARM void func_ov002_021695d8(char* arg0) {
#else
extern "C" ARM void func_ov002_02168d54(char* arg0) {
#endif
    GameState* gs = GameState::GetInstance();
    GameResources* res = gs->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0) {
        self[REGION_VALUE(0x228a, 0x2456)] = 1;
        Overlay_Load(OVERLAY_ID(13));
        func_ov002_021682c0(self);
        SetSubBrightness(res, -0x10, 0xf);
        *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = loader->QueueLoadFile(&data_ov002_0216d350, NULL);
#if !defined(jpn)
        FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
        OrGlobalFlag0x40_020dc2bc();
#endif
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 1) {
        if (*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)) >= 0) {
            if (var2->GetTaskStatus(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458))) != 0) {
                void* var3;
                unsigned int var4;
                var2->GetLoadedFileByID(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)), &var3, &var4);
                func_0209a338((Struct_ov002_02168d54_2*)(arg0 + REGION_VALUE(0x2274, 0x243c)));
                func_0209a470((Struct_ov002_02168d54_3*)(arg0 + REGION_VALUE(0x2274, 0x243c)), (SafeAllocator*)(arg0 + REGION_VALUE(0x7b4, 0x850)), (Struct_ov002_02168d54_4*)var3, var4);
                var2->RemoveTask(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)));
                *(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)) = -1;
            }
        } else if (!IsSubBrightnessTransitionActive(var1)) {
#if defined(jpn)
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
            OrGlobalFlag0x40_020dc2bc();
#endif
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 2) {
        if (func_ov013_021870f0(arg0 + REGION_VALUE(0x1bc8, 0x1d04))) {
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 3) {
        SetSubBrightness(var1, 0, 0xf);
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 4) {
        if (!IsSubBrightnessTransitionActive(var1)) {
            ((SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)))->Reset();
            func_ov013_02184360(arg0 + REGION_VALUE(0x1c20, 0x1d70), 0);
            func_ov013_02184cf0(arg0 + REGION_VALUE(0x1c20, 0x1d70), (SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)));
            *(int*)(arg0 + REGION_VALUE(0x1c38, 0x1d88)) = *(int*)(arg0 + REGION_VALUE(0x19c0, 0x1a68));
            *(short*)(arg0 + REGION_VALUE(0x1c3c, 0x1d8c)) = 0;
            GameObject* var5 = func_0200ff1c(var0, func_ov002_021574d4(arg0, *(short*)(arg0 + REGION_VALUE(0x1ad0, 0x1c08))));
            if (var5) {
                func_ov013_02184b4c(arg0 + REGION_VALUE(0x1c20, 0x1d70), var5);
            }
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 5) {
        func_ov002_02168354(arg0);
#if !defined(jpn)
        int var6 = *(int*)(arg0 + 0x23cc);
        int var7 = func_ov002_021574d4(arg0, *(short*)(arg0 + REGION_VALUE(0x1ad0, 0x1c08)));
        func_ov013_0218782c(arg0 + REGION_VALUE(0x1bc8, 0x1d04), (signed char)var7, (unsigned char)var6);
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 6) {
#if !defined(jpn)
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        func_ov002_021685bc(arg0);
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 7) {
#if !defined(jpn)
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        func_ov002_0216885c(arg0);
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 8) {
#if !defined(jpn)
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        char* controller = (char*)MessageSystem_GetInstance();
        if (*(int*)(controller + REGION_VALUE(0x868, 0x998)) != 0) {
            controller[REGION_VALUE(0x17de, 0x19ae)] = 0;
            if (*(int*)(controller + REGION_VALUE(0x870, 0x9a0)) != 3) {
                return;
            }
            if (!g_keyManager.TestKeysPressed(0x203) && !g_touchInput.IsPressed()) {
                return;
            }
        }
        MessageSystem_Reset(controller);
        MessageSystem_Stop(controller);
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b3c(global, 0xc);
        FontBankLoader_CancelLoads(global);
        self[REGION_VALUE(0x2288, 0x2454)] = 0;
        self[REGION_VALUE(0x2289, 0x2455)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        SetSubBrightness(res, -0x10, 0xf);
        self[REGION_VALUE(0x228a, 0x2456)] = 0;
        PushInputLogB_020a1ef0(1);
        self[REGION_VALUE(0x22a2, 0x2472)] = 1;
        self[REGION_VALUE(0x1afb, 0x1c33)] = 1;
        self[REGION_VALUE(0x22bf, 0x248f)] = 1;
        *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = loader->QueueLoadFile(&data_ov002_0216d368, NULL);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 9) {
#if !defined(jpn)
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (var2->GetTaskStatus(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458))) != 0) {
            void* var10;
            unsigned int var11;
            var2->GetLoadedFileByID(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)), &var10, &var11);
            ((SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)))->Reset();
            *(char**)(arg0 + REGION_VALUE(0x2290, 0x2460)) = (char*)((SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)))->Allocate(0xd0);
            func_0209fe9c(*(char**)(arg0 + REGION_VALUE(0x2290, 0x2460)));
            func_0209fee4(*(Struct_ov002_02168d54_7**)(arg0 + REGION_VALUE(0x2290, 0x2460)), (SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)), (int)var10, var11);
            var2->RemoveTask(*(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)));
            *(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)) = -1;
            func_0209ff64(*(Struct_ov002_02168d54_5**)(arg0 + REGION_VALUE(0x2290, 0x2460)), 100);
            do {
                func_0209ff6c(*(Struct_ov002_02168d54_6**)(arg0 + REGION_VALUE(0x2290, 0x2460)));
            } while (!func_ov002_02168c00(*(unsigned char**)(arg0 + REGION_VALUE(0x2290, 0x2460))));
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xa) {
#if !defined(jpn)
        func_ov013_021870c0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (!IsSubBrightnessTransitionActive(var1)) {
            func_ov013_02186fa0(arg0 + REGION_VALUE(0x1bc8, 0x1d04));
            ((SafeAllocator*)(arg0 + REGION_VALUE(0x7b4, 0x850)))->Reset();
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xb) {
        func_ov002_021688f8(arg0);
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xc) {
#if !defined(jpn)
        if (*(Struct_ov002_02168d54_8**)(arg0 + 0x2448) != NULL) {
            func_020727ec(*(Struct_ov002_02168d54_8**)(arg0 + 0x2448));
        }
        *(void**)(arg0 + 0x2448) = NULL;
        if (*(void**)(arg0 + 0x244c) != NULL) {
            func_020e5280(*(void**)(arg0 + 0x244c));
        }
        *(void**)(arg0 + 0x244c) = NULL;
#endif
        ((SafeAllocator*)(arg0 + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(char**)(arg0 + REGION_VALUE(0x2298, 0x2468)) = (char*)((SafeAllocator*)(arg0 + REGION_VALUE(0x7c8, 0x864)))->Allocate(0x44c);
        func_ov023_021eb138(*(char**)(arg0 + REGION_VALUE(0x2298, 0x2468)), 7);
        func_ov023_021eb080(*(char**)(arg0 + REGION_VALUE(0x2298, 0x2468)), (SafeAllocator*)(arg0 + REGION_VALUE(0x7c8, 0x864)));
        func_ov023_021eb564(*(char**)(arg0 + REGION_VALUE(0x2298, 0x2468)), *(int*)(arg0 + REGION_VALUE(0x229c, 0x246c)), *(unsigned char*)(arg0 + REGION_VALUE(0x22a0, 0x2470)));
        char* var12 = *(char**)(arg0 + REGION_VALUE(0x2298, 0x2468));
        if (*(unsigned char*)(arg0 + REGION_VALUE(0x22a1, 0x2471)) != 0) {
            *(unsigned short*)(var12 + 0x438) |= 0x400;
        } else {
            *(unsigned short*)(var12 + 0x438) &= ~0x400;
        }
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xd) {
        if (*(unsigned short*)(*(char**)(arg0 + REGION_VALUE(0x2298, 0x2468)) + 0x438) & 4) {
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xe) {
        self[REGION_VALUE(0x22a2, 0x2472)] = 0;
        func_ov023_021eb26c(*(void**)(self + REGION_VALUE(0x2298, 0x2468)));
        ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
        ((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(void**)(self + REGION_VALUE(0x2298, 0x2468)) = NULL;
        *(int*)(self + REGION_VALUE(0x229c, 0x246c)) = 0;
        self[REGION_VALUE(0x22a0, 0x2470)] = 0;
        self[REGION_VALUE(0x22a1, 0x2471)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xf) {
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b40(global);
        BlankFunction02094b30(global, 100, 0);
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0x10) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) {
            *(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) = 100;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 100) {
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
        PopStack1AndTrigger_020a1f4c(1);
        self[REGION_VALUE(0x1afb, 0x1c33)] = 0;
        self[REGION_VALUE(0x22bf, 0x248f)] = 0;
        SetCombatModeFromCase020dc2d0(0);
        *(int*)(self + REGION_VALUE(0x22ac, 0x247c)) |= 2;
        self[REGION_VALUE(0x22aa, 0x247a)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 101) {
        if (!(*(int*)(self + REGION_VALUE(0x22ac, 0x247c)) & 2)) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 102) {
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 103) {
        func_ov002_0215a938(arg0);
        *(int*)(arg0 + REGION_VALUE(0x1a80, 0x1bb8)) = REGION_VALUE(0x20, 0x1f);
        func_ov002_02161cf0(arg0);
        func_0205de24((Struct_ov002_0215624c_11*)(arg0 + REGION_VALUE(0xe20, 0xec8)), 0, 2);
        func_ov002_02160274(arg0);
    }
}
