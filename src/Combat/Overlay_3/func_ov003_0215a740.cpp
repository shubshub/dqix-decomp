#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215a740_2464 = 0x870 };
enum { Enum_ov003_0215a740_2478 = 0x7de };
enum { Enum_ov003_0215a740_2400 = 0x800 };
enum { Enum_ov003_0215a740_2384 = 0x8b8, Enum_ov003_0215a740_336 = 0x144, Enum_ov003_0215a740_396 = 0x180, Enum_ov003_0215a740_14080 = 0x34f0 };
#define data_ov003_0217f39c data_ov003_0217e09c
#else
enum { Enum_ov003_0215a740_2464 = 0x9a0 };
enum { Enum_ov003_0215a740_2478 = 0x9ae };
enum { Enum_ov003_0215a740_2400 = 0x960 };
enum { Enum_ov003_0215a740_2384 = 0x950, Enum_ov003_0215a740_336 = 0x150, Enum_ov003_0215a740_396 = 0x18c, Enum_ov003_0215a740_14080 = 0x3700 };
#endif

#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

void* MessageSystem_GetInstance(void);
struct Struct_0205d81c;
void Window_SetPanePalette(Struct_0205d81c*, int, int);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void func_ov003_02159290(void*, unsigned short, int);
struct Struct_0205dee8;
extern "C" void func_0205dee8(Struct_0205dee8*, int);
extern "C" void func_ov003_0215be20(void*);
extern "C" int func_ov003_0215bd34(void*);
extern "C" void func_ov003_0215c01c(void*, int, int);
extern "C" void* memset(void*, int, unsigned int);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" int _s32_div_f(int, int);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void SetByteInRange_020465f0(unsigned char*, int, unsigned char);
void NameText_InitFromPartyMember(void*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" int func_ov003_0215bf18(void*, int);
extern "C" int func_ov003_0215b580(void*, int);
struct Struct_02109bf4_2;
extern "C" void func_0209c830(Struct_02109bf4_2*, int);
extern "C" int func_0209ca2c(void*);
extern "C" void func_02048150(void*, int, int);
void TryClearFlags0x130_02048418(unsigned char*, unsigned short);
void* GameState_GetParty(GameState*);
extern "C" void func_0207c378(void*, short, int, int);
extern "C" void func_02052d7c(void*, signed char, int);
extern "C" void* LinkSession_GetInstance(void);
int LinkSession_IsActive(int*);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
struct FieldTaskQueue;
void FieldTaskQueue_Update(FieldTaskQueue*);
struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_ov017_021c9e00(int, int, int, int);

extern int g_bgmPlayer;
extern const signed char data_ov003_0217f39c[12];

struct Struct_ov003_0215a740 {
    char unknown_0_[8];
    struct {
        unsigned int unknown_0_0_ : 4;
        unsigned int unknown_0_4_ : 14;
        unsigned int unknown_2_2_ : 1;
        unsigned int unknown_2_3_ : 13;
    } unknown_8_;
    char unknown_c_[0x18 - 0xc];
    short unknown_18_;
};

struct Struct_ov003_0215a740_2 {
    char unknown_0_[0xc];
};

// USA: func_ov003_0215a740
extern "C" ARM void func_ov003_0215a740(void* self, int p1, int p2) {
    unsigned char* s = (unsigned char*)self;
    GameState* game = GameState::GetInstance();
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();

    if (*(int*)(var2 + Enum_ov003_0215a740_2464) == 3) {
        *(unsigned char*)(var2 + 0x1000 + Enum_ov003_0215a740_2478) = 0;
    }

    unsigned char var3 = *(unsigned char*)(var0 + 0x580);

    if (state == 0) {
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 0);
        func_ov003_02159250(self,
            KeyTable_Get((Container020e0310*)(s + 0x64), (short)p2));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (var3 == 1) {
        if (*(int*)(var2 + Enum_ov003_0215a740_2464) != 3) return;
        func_0205dee8((Struct_0205dee8*)(var0 + 0xf4), 2);
        *(unsigned char*)(var0 + 0x585) = 0;
        func_ov003_0215be20(arg0);
        *(unsigned char*)(var0 + 0x59f) = *(unsigned char*)(var0 + 0x59f) | 4;
        *(unsigned char*)(var0 + 0x580) = *(unsigned char*)(var0 + 0x580) + 1;
    }

    if (var3 == 2) {
        int var4 = func_ov003_0215bd34(arg0);
        if (var4 == -1) return;
        if (var4 == -2) {
            func_ov003_0215c01c(arg0, 1, 0);
            memset(*(void**)(var0 + 0x7c), 0, Enum_ov003_0215a740_2400);
            func_ov003_02159290(arg0, 0x424, 0x42e);
            func_ov003_02159250(arg0, *(void**)(var0 + 0x7c));
            *(unsigned char*)(var0 + 0x580) = 6;
        } else if (var4 >= 0) {
            func_ov003_0215c01c(arg0, 1, 1);
            func_ov003_0215c01c(arg0, 2, 1);
            *(unsigned char*)(var0 + 0x5a1) = (unsigned char)var4;
            unsigned char* var5 =
                (unsigned char*)(void*)func_0200ff1c(var1, *(unsigned char*)(var0 + *(signed char*)(var0 + 0x5a1) + 0x591));
            unsigned char* var6 = func_02053c6c(var5);
            int var7 = *(int*)(var6 + Enum_ov003_0215a740_2384);
            *(int*)(var0 + 0x5a4) = *(int*)(var5 + 0x134);
            *(int*)(var0 + 0x5a8) = *(int*)(*(int**)(var5 + 0x130));
            int var8 = 0;
            switch (arg2) {
            case 0x406:
                if (*(int*)(*(int**)(var5 + 0x130)) & 1) {
                    unsigned short var9 = *(unsigned short*)(var6 + var7 * 2 + 0x100 + 0x6c);
                    *(int*)(var0 + 0x5ac) = ((var9 * var9 + 0x14) / 0x14) * 0xa;
                    var8 = 1;
                }
                break;
            case 0x410:
                if (*(int*)(var0 + 0x5a8) & 2) {
                    *(int*)(var0 + 0x5ac) = 5;
                    var8 = 1;
                }
                break;
            case 0x406 + 20:
                if (*(int*)(var0 + 0x5a8) & 4) {
                    unsigned short var10 = *(unsigned short*)(var6 + var7 * 2 + 0x100 + 0x6c);
                    *(int*)(var0 + 0x5ac) = var10 * 0x1e;
                    var8 = 1;
                }
            }
            if (var8 != 0) {
                func_020465c0((Struct_020465c0*)var2, 0, *(int*)(var0 + 0x5ac));
                func_020465f0(var2, 0, 0);
                memset(*(void**)(var0 + 0x7c), 0, Enum_ov003_0215a740_2400);
                func_ov003_02159290(arg0, 0x425, 0x42e);
                func_ov003_02159250(arg0, *(void**)(var0 + 0x7c));
                *(unsigned char*)(var0 + 0x580) = *(unsigned char*)(var0 + 0x580) + 1;
            } else {
#if !defined(jpn)
                NameBuf0215a740 nb;
                NameText_InitFromPartyMember(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
#endif
                MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)(s + 0x5a4));
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                AppendFieldTwice_02159290(self, (p2 + 2), 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            }
        }
    }

    if (state == 3) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, kRegion960);
            AppendFieldTwice_02159290(self, 0x426, 0x42e);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 6;
        } else if (r == 0) {
            if (AddCappedFieldF6c_0215b580(self, -*(int*)(s + 0x5ac)) == 0) {
                memset(*(void**)(s + 0x7c), 0, kRegion960);
                AppendFieldTwice_02159290(self, 0x427, 0x42e);
                func_ov003_02159250(self, *(void**)(s + 0x7c));
                *(unsigned char*)(s + 0x580) = 6;
            } else {
                *(unsigned char*)(var0 + 0x59f) = *(unsigned char*)(var0 + 0x59f) | 0x10;
#if defined(jpn)
                MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)(s + 0x5a4));
#else
                NameBuf0215a740 nb;
                NameText_InitFromPartyMember(&nb,
                    *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591));
                *(void**)(g + 0x10) = &nb;
#endif
                func_ov003_02159250(self,
                    KeyTable_Get((Container020e0310*)(s + 0x64), (short)(p2 + 1)));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
            }
        }
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 0, 0);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 1, 1);
        Window_SetPanePalette((Struct_0205d81c*)(s + 0xf4), 2, 0);
    }

    if (state == 4) {
        if (*(int*)(g + kRegion9a0) != 3) return;
        SetValueAndActivate0209c830((Struct0209c830*)&g_bgmPlayer, 0x3b);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (var3 == 5) {
        if (*(int*)(var2 + Enum_ov003_0215a740_2464) == 3) {
            *(unsigned char*)(var2 + 0x1000 + Enum_ov003_0215a740_2478) = 0;
        }
        if (IsAnimationActive0209ca2c(&g_bgmPlayer) != 0) return;
        int cid = *(unsigned char*)(s + *(signed char*)(s + 0x5a1) + 0x591);
        unsigned char* combatant = (unsigned char*)(void*)GetCombatantWithFlag0x100_0200ff1c(game, cid);
        switch (p2) {
        case 0x406: {
            func_02048150(var15, 0, 1);
            int var16 = *(int*)(var15 + Enum_ov003_0215a740_396);
            if (var16 & 1) {
                *(int*)(var15 + Enum_ov003_0215a740_396) = var16 & ~1;
            }
            break;
        }
        case 0x410:
            func_02048418((unsigned char*)var15, 2);
            break;
        case 0x406 + 20: {
            TryClearFlags0x130_02048418((unsigned char*)combatant, 4);
            unsigned char* c4 = (unsigned char*)GameState_GetParty(game);
            int flag = 0;
            for (int i = 0; i < 0xb; i++) {
                if (i == 2 || i == 3 || i == 4) continue;
                unsigned char j = (unsigned char)i;
                unsigned char* ep = *(unsigned char**)(combatant + kRegion150) + 0x194 + j * 0x20;
                if (ep == 0) continue;
                struct Slot0215a740* e = (struct Slot0215a740*)ep;
                if (e->bits.hit == 0) continue;
                short sv = e->sv;
                int lo = e->bits.lo;
                func_0207c378(c4 + 0x1d4, sv, 1, lo);
                func_02052d7c(combatant, data_ov003_0217f39c[i], -1);
                flag = 1;
            }
            if (flag != 0) {
                if (LinkSession_IsActive((int*)LinkSession_GetInstance()) != 0) {
                    func_ov017_021c3fb4(cid, 1);
                    func_ov017_021c4418(cid, -1);
                }
                void* bg = (void*)GetGameResources();
                void* ctxA = *(void**)((char*)bg + kRegion3700);
                void* ctxB = *(void**)((char*)bg + kRegion3700 + 4);
                void* loader = BackgroundLoader::GetInstance();
                func_ov017_0218f5a4(bg, cid, 1, 0, 0);
                while (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)ctxA) == 0x13) {
                    ((BackgroundLoader*)loader)->RemoveAllLocks();
                    FieldTaskQueue_Update((FieldTaskQueue*)ctxA);
                    if (FieldTaskQueue_GetCurrentKind((HeadNode02046b24**)ctxB) == 0x14) {
                        FieldTaskQueue_Update((FieldTaskQueue*)ctxB);
                    }
                }
            }
        }
        }
        *(unsigned char*)(var0 + 0x59f) = *(unsigned char*)(var0 + 0x59f) & ~0x10;
        *(unsigned char*)(var0 + 0x583) = 1;
        func_ov017_0218b5f8(-1);
        func_ov017_021c9e00(cid, 1, 0, 1);
        func_ov003_02159250(self,
            KeyTable_Get((Container020e0310*)(s + 0x64), 0x42e));
        *(signed char*)(s + 0x585) = -1;
        func_ov003_0215c01c(self, 1, 0);
        func_ov003_0215c01c(self, 2, 0);
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (var3 == 6 && *(int*)(var2 + Enum_ov003_0215a740_2464) == 3) {
        *(unsigned char*)(var0 + 0x59f) = *(unsigned char*)(var0 + 0x59f) & ~4;
        *(signed char*)(var0 + 0x585) = -1;
        func_ov003_0215c01c(arg0, 1, 0);
        func_ov003_0215c01c(arg0, 2, 0);
        *(signed char*)(var0 + 0x5a1) = -1;
        *(int*)(var0 + 0x5a4) = 0;
        *(int*)(var0 + 0x5a8) = 0;
        *(int*)(var0 + 0x5ac) = 0;
        *(unsigned char*)(var0 + 0x588) = 2;
        *(unsigned char*)(var0 + 0x580) = 0;
    }
}
