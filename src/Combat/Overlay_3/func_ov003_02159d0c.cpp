#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"


#if defined(jpn)
enum { Enum_ov003_02159d0c_2464 = 0x870 };
enum { Enum_ov003_02159d0c_2478 = 0x7de };
enum { Enum_ov003_02159d0c_2400 = 0x800 };
enum { Enum_ov003_02159d0c_2456 = 0x868 };
enum { Enum_ov003_02159d0c_13504 = 0x3280 };
#else
enum { Enum_ov003_02159d0c_2464 = 0x9a0 };
enum { Enum_ov003_02159d0c_2478 = 0x9ae };
enum { Enum_ov003_02159d0c_2400 = 0x960 };
enum { Enum_ov003_02159d0c_2456 = 0x998 };
enum { Enum_ov003_02159d0c_13504 = 0x34c0 };
#endif

void* MessageSystem_GetInstance(void);
void* GlobalFlags_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
void AppendFieldTwice_02159290(void*, unsigned short, int);
extern "C" void func_ov003_02159250(void*, void*);
struct Struct_0205d81c;
void Window_SetPanePalette(Struct_0205d81c*, int, int);
int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsGuest(void*);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" int func_ov003_0215bf18(void*, int);
extern "C" int func_020457e0(void*);
extern "C" void* Scenario_GetInstance(void);
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(void*);
void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_ov017_021d1118(int, int, int, int);
extern "C" void func_ov017_021d1014(int, int, int);
struct Struct_02109bf4_2;
extern "C" void func_0209c830(Struct_02109bf4_2*, int);
extern "C" int func_020bc0a4(int);
struct Struct_020a9ea4;
extern "C" void func_020a9ea4(Struct_020a9ea4*);
extern "C" int func_020aad1c(void*, void*, int, int);
extern "C" void func_0209c7fc(void*);
extern "C" void func_02046380(void*);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
void Text_Append(char*, char const*);
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void* memset(void*, int, unsigned int);

extern int g_bgmPlayer;
extern int g_fileLoadBuffer;

// USA: func_ov003_02159d0c
extern "C" ARM void func_ov003_02159d0c(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    void* dp = GlobalFlags_GetInstance();
    void* f = LinkSession_GetInstance();
    char buf[0x34];

    if (*(int*)(var1 + Enum_ov003_02159d0c_2464) == 3) {
        *(unsigned char*)(var1 + 0x1000 + Enum_ov003_02159d0c_2478) = 0;
    }

    unsigned char var5 = *(unsigned char*)(var0 + 0x580);

    if (var5 == 0) {
        if (*(unsigned char*)(var0 + 0x5b4) != 0) {
            if (*(unsigned char*)(var0 + 0x59d) != 0) return;
            memset(*(void**)(var0 + 0x7c), 0, Enum_ov003_02159d0c_2400);
            func_ov003_02159290(arg0, 0x3e8, 0x64);
            func_ov003_02159250(arg0, *(void**)(var0 + 0x7c));
            *(unsigned char*)(var0 + 0x5b3) = 5;
            *(unsigned char*)(var0 + 0x580) = 2;
            return;
        }
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
        int key = 0x3f2;
        if (LinkSession_IsActive((int*)f) && LinkSession_IsGuest(f)) {
            key += 8;
        }
        func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), key));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (var5 == 1) {
        if (*(int*)(var1 + Enum_ov003_02159d0c_2464) != 3) return;
        int var7 = func_ov003_0215bf18(arg0, 0);
        if (var7 == -1) return;
        if (var7 == -2 || var7 == 1) {
            memset(*(void**)(var0 + 0x7c), 0, Enum_ov003_02159d0c_2400);
            func_ov003_02159290(arg0, 0x3f4, 0x3f5);
            func_ov003_02159250(arg0, *(void**)(var0 + 0x7c));
            *(unsigned char*)(var0 + 0x580) = 4;
        } else if (var7 == 0) {
            *(unsigned char*)(var0 + 0x580) = *(unsigned char*)(var0 + 0x580) + 1;
        }
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
    }

    if (var5 == 2) {
        if (*(unsigned char*)(var0 + 0x5b4) != 0) {
            if (*(int*)(var1 + Enum_ov003_02159d0c_2456) == 0) {
                *(unsigned char*)(var0 + 0x588) = 0xb;
                *(unsigned char*)(var0 + 0x580) = 0;
                return;
            }
            unsigned char var8 = *(unsigned char*)(var0 + 0x5b3);
            int var9 = *(int*)(var1 + Enum_ov003_02159d0c_2464);
            unsigned char var10 = var9;
            int var11 = 1;
            if (var8 == 6 && var10 == 5) {
                if (func_020457e0(var1) == 0) var11 = 0;
            }
            *(unsigned char*)(var0 + 0x5b3) = (unsigned char)*(int*)(var1 + Enum_ov003_02159d0c_2464);
            if (var11) return;
        }
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
        if (Scenario_RunTrigger(Scenario_GetInstance(), 0xc, buf)) {
            EventQuery_RunQueuedCommands(buf);
        }
        if (*(unsigned char*)(s + 0x5b4) == 0) {
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x64));
        }
        FlagWord_SetBits((unsigned int*)dp, 0x80);
        *(int*)(s + 0x598) = 0xf;
        if (LinkSession_IsActive((int*)f)) {
            func_ov017_021d1118(-1, 1, 1, 2);
            func_ov017_021d1014(-1, 1, 0);
        }
        *(unsigned char*)(var0 + 0x580) = 0x64;
    }

    if (state == 0x64) {
        if (LinkSession_IsActive((int*)f)) {
            signed char* p = (signed char*)GameState::GetInstance() + 0x4000 + kRegionValue34C0_3280;
            for (int i = 0; i < 3; i++, p += 10) {
                if (p[6] >= 4) {
                    if (((unsigned char*)p)[7] != 0 || ((unsigned char*)p)[8] != 0) return;
                    if (p[9] >= 0) return;
                }
            }
        }
        SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, 0x3c);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 2;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (var5 == 0x65) {
        if (*(int*)(var1 + Enum_ov003_02159d0c_2464) != 3) return;
        if (func_020bc0a4(0x3c) == 0) return;
        if (*(int*)(var1 + Enum_ov003_02159d0c_2464) == 3) {
            *(unsigned char*)(var1 + 0x1000 + Enum_ov003_02159d0c_2478) = 0;
        }
        if (*(unsigned char*)(var0 + 0x59c) == 0) {
            *(unsigned char*)(var0 + 0x59c) = 1;
        }
        func_020a9ea4((Struct_020a9ea4*)(var0 + 0x1b8 + 0x400));
        *(unsigned char*)(var0 + 0x580) = 0x66;
    }

    if (state == 0x66) {
        int flags = 1;
        if (LinkSession_IsGuest(f)) flags |= 0x14;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c(s + 0x1b8 + 0x400, &g_fileLoadBuffer, flags, 0) == 1) {
            *(unsigned char*)(s + 0x580) = 3;
        }
        BackgroundLoader::RemoveLockGlobal();
    }

    if (var5 == 3) {
        if (*(int*)(var1 + Enum_ov003_02159d0c_2464) == 3) {
            *(unsigned char*)(var1 + 0x1000 + Enum_ov003_02159d0c_2478) = 0;
        }
        StopAndReset0209c7fc(&g_bgmPlayer);
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~2;
        memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            unsigned char* obj = (unsigned char*)GameState::GetInstance()->GetLeader();
            func_02046380(g);
            MessageSystem_SetStringArgument((Obj02046574*)g, 0, (char*)(*(void**)(obj + 0x134)));
            Text_Append((char*)(*(void**)(s + 0x7c)), (char const*)KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f3));
        } else {
            func_ov003_02159290(arg0, 0x3f3, 0x3f5);
        }
        func_ov003_02159250(self, *(void**)(s + 0x7c));
        FlagWord_ClearBits((FlagWord020466f4*)dp, 0x80);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~0x10;
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            *(unsigned char*)(s + 0x580) = 7;
            return;
        }
        *(unsigned char*)(var0 + 0x580) = *(unsigned char*)(var0 + 0x580) + 1;
    }

    if (state == 4) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            if (*(unsigned char*)(s + 0x59c) == 0) {
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f7));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
                return;
            }
            if (LinkSession_IsActive((int*)f)) {
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        } else if (r == 0) {
            Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x442));
            *(unsigned char*)(s + 0x580) = 7;
        }
    }

    if (state == 5) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
            Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
            Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f8));
            *(unsigned char*)(s + 0x580) = 1;
            return;
        } else if (r == 0) {
            if (LinkSession_IsActive((int*)f)) {
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
                Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (state == 6) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x442));
            *(unsigned char*)(s + 0x580) = 7;
            return;
        } else if (r == 0) {
            Window_ClosePane((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, KeyTable_Get((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (var5 == 7) {
        if (*(int*)(var1 + Enum_ov003_02159d0c_2456) == 0) {
            *(unsigned char*)(var0 + 0x588) = 0xb;
            *(unsigned char*)(var0 + 0x580) = 0;
        }
    }
}
