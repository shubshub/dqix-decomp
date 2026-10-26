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

struct Pair0209a338;
struct Struct_ov002_02168d54_3;
struct StreamHeader;
struct Struct_ov002_02168d54_5;
struct Struct_ov002_02168d54_6;
struct Struct_ov002_02168d54_7;
struct Struct_ov002_02168d54_8;
struct FlagWord020466f4;
struct Struct0205de24;

extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov002_021682c0(char* self);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" void func_020dc2bc(void);
extern "C" void func_0209a338(Pair0209a338* p);
extern "C" void func_0209a470(Struct_ov002_02168d54_3* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" int func_ov013_021870f0(char* obj);
extern "C" void func_ov013_02184360(char* obj, int v);
extern "C" void func_ov013_02184cf0(char* obj, SafeAllocator* alloc);
extern "C" int func_ov002_021574d4(void* self, int index);
extern "C" GameObject* func_0200ff1c(GameState* gameState, int combatantId);
extern "C" void func_ov013_02184b4c(char* obj, GameObject* combatant);
extern "C" void func_ov002_02168354(char* self);
extern "C" void func_ov013_0218782c(char* obj, int a, int b);
extern "C" void func_ov013_021870c0(void* obj);
extern "C" void func_ov002_021685bc(char* self);
extern "C" void func_ov002_0216885c(char* self);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
extern "C" void func_020a1ef0(int id);
extern "C" void func_0209fe9c(char* obj);
extern "C" void func_0209fee4(Struct_ov002_02168d54_7* obj, SafeAllocator* alloc, int data, int length);
extern "C" void func_0209ff64(Struct_ov002_02168d54_5* obj, int v);
extern "C" void func_0209ff6c(Struct_ov002_02168d54_6* task);
extern "C" int func_ov002_02168c00(unsigned char* obj);
extern "C" void func_ov013_02186fa0(char* obj);
extern "C" void func_ov002_021688f8(char* self);
extern "C" void func_020727ec(Struct_ov002_02168d54_8* list);
extern "C" void func_020e5280(void* obj);
extern "C" void func_ov023_021eb138(char* obj, int v);
extern "C" void func_ov023_021eb080(char* obj, SafeAllocator* alloc);
extern "C" void func_ov023_021eb564(char* obj, int a, int b);
extern "C" void func_ov023_021eb26c(void* obj);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, unsigned int pixel1Source, unsigned int pixel2Source, unsigned int pixel1Alpha, unsigned int pixel2Alpha);
extern "C" void FlagWord_ClearBits(FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020a1f4c(int flag);
extern "C" void func_020dc2d0(int mode);
extern "C" void func_ov002_0215a938(char* self);
extern "C" void func_ov002_02161cf0(char* base);
extern "C" void func_0205de24(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_02160274(char* self);

extern char data_ov002_0216d350;
extern char data_ov002_0216d368;

// USA: func_ov002_02168d54; JPN: func_ov002_021695d8
#if defined(jpn)
extern "C" ARM void func_ov002_021695d8(char* self) {
#else
extern "C" ARM void func_ov002_02168d54(char* self) {
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
        func_020dc2bc();
#endif
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 1) {
        if (*(int*)(self + REGION_VALUE(0x228c, 0x2458)) >= 0) {
            if (loader->GetTaskStatus(*(int*)(self + REGION_VALUE(0x228c, 0x2458))) != 0) {
                void* data;
                unsigned int length;
                loader->GetLoadedFileByID(*(int*)(self + REGION_VALUE(0x228c, 0x2458)), &data, &length);
                func_0209a338((Pair0209a338*)(self + REGION_VALUE(0x2274, 0x243c)));
                func_0209a470((Struct_ov002_02168d54_3*)(self + REGION_VALUE(0x2274, 0x243c)), (SafeAllocator*)(self + REGION_VALUE(0x7b4, 0x850)), (StreamHeader*)data, length);
                loader->RemoveTask(*(int*)(self + REGION_VALUE(0x228c, 0x2458)));
                *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = -1;
            }
        } else if (!IsSubBrightnessTransitionActive(res)) {
#if defined(jpn)
            FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
            func_020dc2bc();
#endif
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 2) {
        if (func_ov013_021870f0(self + REGION_VALUE(0x1bc8, 0x1d04))) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 3) {
        SetSubBrightness(res, 0, 0xf);
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 4) {
        if (!IsSubBrightnessTransitionActive(res)) {
            ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
            func_ov013_02184360(self + REGION_VALUE(0x1c20, 0x1d70), 0);
            func_ov013_02184cf0(self + REGION_VALUE(0x1c20, 0x1d70), (SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)));
            *(int*)(self + REGION_VALUE(0x1c38, 0x1d88)) = *(int*)(self + REGION_VALUE(0x19c0, 0x1a68));
            *(short*)(self + REGION_VALUE(0x1c3c, 0x1d8c)) = 0;
            GameObject* combatant = func_0200ff1c(gs, func_ov002_021574d4(self, *(short*)(self + REGION_VALUE(0x1ad0, 0x1c08))));
            if (combatant) {
                func_ov013_02184b4c(self + REGION_VALUE(0x1c20, 0x1d70), combatant);
            }
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 5) {
        func_ov002_02168354(self);
#if !defined(jpn)
        int variant = *(int*)(self + 0x23cc);
        int value = func_ov002_021574d4(self, *(short*)(self + REGION_VALUE(0x1ad0, 0x1c08)));
        func_ov013_0218782c(self + REGION_VALUE(0x1bc8, 0x1d04), (signed char)value, (unsigned char)variant);
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 6) {
#if !defined(jpn)
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        func_ov002_021685bc(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 7) {
#if !defined(jpn)
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        func_ov002_0216885c(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 8) {
#if !defined(jpn)
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
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
        func_02094b3c(global, 0xc);
        FontBankLoader_CancelLoads(global);
        self[REGION_VALUE(0x2288, 0x2454)] = 0;
        self[REGION_VALUE(0x2289, 0x2455)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        SetSubBrightness(res, -0x10, 0xf);
        self[REGION_VALUE(0x228a, 0x2456)] = 0;
        func_020a1ef0(1);
        self[REGION_VALUE(0x22a2, 0x2472)] = 1;
        self[REGION_VALUE(0x1afb, 0x1c33)] = 1;
        self[REGION_VALUE(0x22bf, 0x248f)] = 1;
        *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = loader->QueueLoadFile(&data_ov002_0216d368, NULL);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 9) {
#if !defined(jpn)
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (loader->GetTaskStatus(*(int*)(self + REGION_VALUE(0x228c, 0x2458))) != 0) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(*(int*)(self + REGION_VALUE(0x228c, 0x2458)), &data, &length);
            ((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Reset();
            *(char**)(self + REGION_VALUE(0x2290, 0x2460)) = (char*)((SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)))->Allocate(0xd0);
            func_0209fe9c(*(char**)(self + REGION_VALUE(0x2290, 0x2460)));
            func_0209fee4(*(Struct_ov002_02168d54_7**)(self + REGION_VALUE(0x2290, 0x2460)), (SafeAllocator*)(self + REGION_VALUE(0x78c, 0x828)), (int)data, length);
            loader->RemoveTask(*(int*)(self + REGION_VALUE(0x228c, 0x2458)));
            *(int*)(self + REGION_VALUE(0x228c, 0x2458)) = -1;
            func_0209ff64(*(Struct_ov002_02168d54_5**)(self + REGION_VALUE(0x2290, 0x2460)), 100);
            do {
                func_0209ff6c(*(Struct_ov002_02168d54_6**)(self + REGION_VALUE(0x2290, 0x2460)));
            } while (!func_ov002_02168c00(*(unsigned char**)(self + REGION_VALUE(0x2290, 0x2460))));
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xa) {
#if !defined(jpn)
        func_ov013_021870c0(self + REGION_VALUE(0x1bc8, 0x1d04));
#endif
        if (!IsSubBrightnessTransitionActive(res)) {
            func_ov013_02186fa0(self + REGION_VALUE(0x1bc8, 0x1d04));
            ((SafeAllocator*)(self + REGION_VALUE(0x7b4, 0x850)))->Reset();
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xb) {
        func_ov002_021688f8(self);
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xc) {
#if !defined(jpn)
        if (*(Struct_ov002_02168d54_8**)(self + 0x2448) != NULL) {
            func_020727ec(*(Struct_ov002_02168d54_8**)(self + 0x2448));
        }
        *(void**)(self + 0x2448) = NULL;
        if (*(void**)(self + 0x244c) != NULL) {
            func_020e5280(*(void**)(self + 0x244c));
        }
        *(void**)(self + 0x244c) = NULL;
#endif
        ((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(char**)(self + REGION_VALUE(0x2298, 0x2468)) = (char*)((SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)))->Allocate(0x44c);
        func_ov023_021eb138(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), 7);
        func_ov023_021eb080(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), (SafeAllocator*)(self + REGION_VALUE(0x7c8, 0x864)));
        func_ov023_021eb564(*(char**)(self + REGION_VALUE(0x2298, 0x2468)), *(int*)(self + REGION_VALUE(0x229c, 0x246c)), *(unsigned char*)(self + REGION_VALUE(0x22a0, 0x2470)));
        char* menu = *(char**)(self + REGION_VALUE(0x2298, 0x2468));
        if (*(unsigned char*)(self + REGION_VALUE(0x22a1, 0x2471)) != 0) {
            *(unsigned short*)(menu + 0x438) |= 0x400;
        } else {
            *(unsigned short*)(menu + 0x438) &= ~0x400;
        }
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0xd) {
        if (*(unsigned short*)(*(char**)(self + REGION_VALUE(0x2298, 0x2468)) + 0x438) & 4) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
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
        func_02094b40(global);
        func_02094b30(global, 100, 0);
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 0x10) {
        if (func_02094b4c(FontBankLoader_GetInstance())) {
            *(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) = 100;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 100) {
        FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
        func_020a1f4c(1);
        self[REGION_VALUE(0x1afb, 0x1c33)] = 0;
        self[REGION_VALUE(0x22bf, 0x248f)] = 0;
        func_020dc2d0(0);
        *(int*)(self + REGION_VALUE(0x22ac, 0x247c)) |= 2;
        self[REGION_VALUE(0x22aa, 0x247a)] = 0;
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 101) {
        if (!(*(int*)(self + REGION_VALUE(0x22ac, 0x247c)) & 2)) {
            (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
        }
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 102) {
        (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(self + REGION_VALUE(0x1a88, 0x1bc0)) == 103) {
        func_ov002_0215a938(self);
        *(int*)(self + REGION_VALUE(0x1a80, 0x1bb8)) = REGION_VALUE(0x20, 0x1f);
        func_ov002_02161cf0(self);
        func_0205de24((Struct0205de24*)(self + REGION_VALUE(0xe20, 0xec8)), 0, 2);
        func_ov002_02160274(self);
    }
}
