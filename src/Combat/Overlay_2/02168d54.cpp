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

extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov002_021682c0(char* self);
void SetSubBrightness(GameResources* resources, int brightness, int duration);
extern "C" void* func_020d6c00(void);
extern "C" void func_020466e4(unsigned int* arg0, unsigned int arg1);
extern "C" void func_020dc2bc(void);
extern "C" void func_0209a338(Struct_ov002_02168d54_2* arg0);
extern "C" void func_0209a470(Struct_ov002_02168d54_3* arg0, SafeAllocator* arg1, Struct_ov002_02168d54_4* arg2, int arg3);
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" int func_ov013_021870f0(char* arg0);
extern "C" void func_ov013_02184360(char* arg0, int arg1);
extern "C" void func_ov013_02184cf0(char* arg0, SafeAllocator* arg1);
extern "C" int func_ov002_021574d4(void* arg0, int arg1);
extern "C" GameObject* func_0200ff1c(GameState* arg0, int arg1);
extern "C" void func_ov013_02184b4c(char* arg0, GameObject* arg1);
extern "C" void func_ov002_02168354(char* arg0);
extern "C" void func_ov013_0218782c(char* arg0, int arg1, int arg2);
extern "C" void func_ov013_021870c0(void* arg0);
extern "C" void func_ov002_021685bc(char* arg0);
extern "C" void func_ov002_0216885c(char* arg0);
extern "C" int func_020421a0(void);
extern "C" void func_02043204(char* arg0);
extern "C" void func_02043124(void* arg0);
extern "C" void func_020a1ef0(int arg0);
extern "C" void func_0209fe9c(char* arg0);
extern "C" void func_0209fee4(Struct_ov002_02168d54_7* arg0, SafeAllocator* arg1, int arg2, int arg3);
extern "C" void func_0209ff64(Struct_ov002_02168d54_5* arg0, int arg1);
extern "C" void func_0209ff6c(Struct_ov002_02168d54_6* arg0);
extern "C" int func_ov002_02168c00(unsigned char* arg0);
extern "C" void func_ov013_02186fa0(char* arg0);
extern "C" void func_ov002_021688f8(char* arg0);
extern "C" void func_020727ec(Struct_ov002_02168d54_8* arg0);
extern "C" void func_020e5280(void* arg0);
extern "C" void func_ov023_021eb138(char* arg0, int arg1);
extern "C" void func_ov023_021eb080(char* arg0, SafeAllocator* arg1);
extern "C" void func_ov023_021eb564(char* arg0, int arg1, int arg2);
extern "C" void func_ov023_021eb26c(void* arg0);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, unsigned int pixel1Source, unsigned int pixel2Source, unsigned int pixel1Alpha, unsigned int pixel2Alpha);
extern "C" void func_020466f4(Struct_ov002_02168d54_9* arg0, unsigned int arg1);
extern "C" void func_020a1f4c(int arg0);
extern "C" void func_020dc2d0(int arg0);
extern "C" void func_ov002_0215a938(char* arg0);
extern "C" void func_ov002_02161cf0(char* arg0);
extern "C" void func_0205de24(Struct_ov002_0215624c_11* arg0, unsigned char arg1, unsigned char arg2);
extern "C" void func_ov002_02160274(char* arg0);

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

    if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0) {
        arg0[REGION_VALUE(0x228a, 0x2456)] = 1;
        func_020a1940(OVERLAY_ID(13));
        func_ov002_021682c0(arg0);
        SetSubBrightness(var1, -0x10, 0xf);
        *(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)) = var2->QueueLoadFile(&data_ov002_0216d350, NULL);
#if !defined(jpn)
        func_020466e4((unsigned int*)func_020d6c00(), 1);
        func_020dc2bc();
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
            func_020466e4((unsigned int*)func_020d6c00(), 1);
            func_020dc2bc();
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
        char* var8 = (char*)func_020421a0();
        if (*(int*)(var8 + REGION_VALUE(0x868, 0x998)) != 0) {
            var8[REGION_VALUE(0x17de, 0x19ae)] = 0;
            if (*(int*)(var8 + REGION_VALUE(0x870, 0x9a0)) != 3) {
                return;
            }
            if (!g_keyManager.TestKeysPressed(0x203) && !g_touchInput.IsPressed()) {
                return;
            }
        }
        func_02043204(var8);
        func_02043124(var8);
        Struct_0208cb08* var9 = func_02094a00();
        func_02094b3c(var9, 0xc);
        func_02094ab0(var9);
        arg0[REGION_VALUE(0x2288, 0x2454)] = 0;
        arg0[REGION_VALUE(0x2289, 0x2455)] = 0;
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
        SetSubBrightness(var1, -0x10, 0xf);
        arg0[REGION_VALUE(0x228a, 0x2456)] = 0;
        func_020a1ef0(1);
        arg0[REGION_VALUE(0x22a2, 0x2472)] = 1;
        arg0[REGION_VALUE(0x1afb, 0x1c33)] = 1;
        arg0[REGION_VALUE(0x22bf, 0x248f)] = 1;
        *(int*)(arg0 + REGION_VALUE(0x228c, 0x2458)) = var2->QueueLoadFile(&data_ov002_0216d368, NULL);
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 9) {
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
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xe) {
        arg0[REGION_VALUE(0x22a2, 0x2472)] = 0;
        func_ov023_021eb26c(*(void**)(arg0 + REGION_VALUE(0x2298, 0x2468)));
        ((SafeAllocator*)(arg0 + REGION_VALUE(0x78c, 0x828)))->Reset();
        ((SafeAllocator*)(arg0 + REGION_VALUE(0x7c8, 0x864)))->Reset();
        *(void**)(arg0 + REGION_VALUE(0x2298, 0x2468)) = NULL;
        *(int*)(arg0 + REGION_VALUE(0x229c, 0x246c)) = 0;
        arg0[REGION_VALUE(0x22a0, 0x2470)] = 0;
        arg0[REGION_VALUE(0x22a1, 0x2471)] = 0;
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0xf) {
        Struct_0208cb08* var13 = func_02094a00();
        func_02094b40(var13);
        func_02094b30(var13, 100, 0);
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 0x10) {
        if (func_02094b4c(func_02094a00())) {
            *(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) = 100;
            ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 10, 6);
        }
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 100) {
        func_020466f4((Struct_ov002_02168d54_9*)func_020d6c00(), 1);
        func_020a1f4c(1);
        arg0[REGION_VALUE(0x1afb, 0x1c33)] = 0;
        arg0[REGION_VALUE(0x22bf, 0x248f)] = 0;
        func_020dc2d0(0);
        *(int*)(arg0 + REGION_VALUE(0x22ac, 0x247c)) |= 2;
        arg0[REGION_VALUE(0x22aa, 0x247a)] = 0;
        (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
    } else if (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)) == 101) {
        if (!(*(int*)(arg0 + REGION_VALUE(0x22ac, 0x247c)) & 2)) {
            (*(int*)(arg0 + REGION_VALUE(0x1a88, 0x1bc0)))++;
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
