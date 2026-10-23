#include <globaldefs.h>
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define K(u, j) (j)
#define func_ov002_0215b6c0 func_ov002_0215c914
#else
#define RG(u, j) (u)
#define K(u, j) (u)
#endif

struct GameState;
struct GameObject;
struct Struct_ov002_0216acf0_4;

extern "C" GameState* _ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState21GetEffectiveDeltaTimeEv(GameState* gs);
extern "C" int _ZNK9GameState12GetTickCountEv(GameState* gs);
char* GetGlobalField0x1c020421a0(void);
extern "C" SearchStruct* func_0202ae18(void);
char* GetCombatantWithFlag0x100_0200ff1c(GameState* gs, int id);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, const void* src);
int TestFlagBitAt0xe_0202c578(SearchStruct* s, int bit);
int DecrementOrClearCounterC74_0216c628(unsigned char*, int);
extern "C" void func_ov002_0215b6c0(char* self);
extern "C" void func_ov002_0215a7b4(char* self, int a, int b, int c, int d);
extern "C" void func_ov002_02159900(char* self, char* arr, int flag);
extern "C" void func_ov002_0215a0a4(char* self, char* arr, int flag);
struct SePlayer;
void SePlayer_Play(SePlayer*, int, int);
void InitStateArray02157ce0(char* arr);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(Struct0205de24*, unsigned char, unsigned char);
void InitBattleTag02161174(char* self);
extern "C" void func_ov002_0216bfd4(char* self, int v);
int CheckFlagOrThreshold_02161b48(char* self, int v);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
struct Obj_0205da38;
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void func_ov002_0216c28c(char* self, int v);
struct Struct020444bc;
void SetField9a0AndIncrementField78(Struct020444bc*);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_0218b5f8(int a);
struct Struct0205d888;
char* GetLastEntry0205d888(Struct0205d888*);
void ClearMatchingEntry_02156ff0(unsigned char*, int);
int GetCountByType02157108(void*, int);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(Obj0205dee8*, int);
struct Struct_0205d81c;
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
extern "C" void func_ov002_02161cf0(char* self);
extern "C" void func_ov023_021dca88(char* obj);
extern "C" void func_0205d7a0(char* obj, int v);
extern "C" void func_ov002_0215c988(char* self, void* buf, int v);
struct StructA0205d5d0;
#if defined(jpn)
extern "C" void func_0205d5d0(Struct_ov002_0215bba8_3*, int, int, int);
#define TAE_LAST(x)
#else
extern "C" void func_0205d5d0(Struct_ov002_0215bba8_3*, int, int, int, unsigned char);
#define TAE_LAST(x) , x
#endif
extern "C" void func_ov002_0215b9a4(char* arg0, int arg1, int arg2);
extern "C" void func_0205ebc0(void* arg0, int arg1, int arg2);
extern "C" void func_0205ebfc(void* arg0, int arg1, int arg2);
extern "C" void func_02043204(char* arg0);
struct Struct_ov002_0216acf0_3;
extern "C" void func_0205d6a0(Struct_ov002_0216acf0_3*, int);
extern "C" char* func_0205d81c(Struct_ov002_02155960_2*, int);

struct Struct_020fdcb0_2 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_[2];
    int unknown_18_;
    int unknown_1c_;
};

struct Struct_ov002_0216acf0_5 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};

extern Totals020fdcb0 data_020fdcb0[];
extern char g_sePlayer;

#define U8(o) (*(unsigned char*)(arg0 + (o)))
#define S8(o) (*(signed char*)(arg0 + (o)))
#define S16(o) (*(short*)(arg0 + (o)))
#define S32(o) (*(int*)(arg0 + (o)))

static inline int inline_ov002_0216acf0(int arg0, int arg1) { return (arg0 | arg1) != 0; }

static inline int inline_ov002_0216acf0_2(char* arg0) { return *(int*)(arg0 + RG(0x998, 0x868)) == 0; }

// USA: func_ov002_0216acf0
extern "C" ARM void func_ov002_0216acf0(char* arg0) {
    if (U8(RG(0x1cc5, 0x1b89)) != 0) {
        U8(RG(0x1cc5, 0x1b89)) = 0;
        return;
    }

    GameState* var0 = _ZN9GameState11GetInstanceEv();
    char* var1 = func_020421a0();
    Struct_ov002_0216acf0_4* var2 = func_0202ae18();

    int var3 = 0;
    int var4 = 0;
    int var5 = 0;
    for (int var6 = 0; var6 < 4; var6++) {
        Struct_020fdcb0_2* var7 = &data_020fdcb0[var6];
        if (var7->unknown_0_ >= 0) var3 += var7->unknown_0_;
        if (var7->unknown_4_ >= 0) var4 += var7->unknown_4_;
        if (var7->unknown_8_ >= 0) var3 += var7->unknown_8_;
        if (var7->unknown_c_ >= 0) var4 += var7->unknown_c_;
        var5 += var7->unknown_18_;
    }
    if (!(S16(RG(0x2548, 0x2370)) == var3 && S16(RG(0x254a, 0x2372)) == var4 && S32(RG(0x254c, 0x2374)) == var5)) {
        if (S32(RG(0x1bc0, 0x1a88)) != 0) {
            func_ov002_0215b6c0(arg0);
        }
    }
    S16(RG(0x2548, 0x2370)) = var3;
    S16(RG(0x254a, 0x2372)) = var4;
    S32(RG(0x254c, 0x2374)) = var5;

    if (U8(RG(0x2522, 0x2352)) != 0 && S32(RG(0x1bc0, 0x1a88)) != 0) {
        if (S32(RG(0x1bc0, 0x1a88)) != 0) {
            S32(RG(0x2530, 0x2360)) = S32(RG(0x2530, 0x2360)) + _ZNK9GameState21GetEffectiveDeltaTimeEv(var0);
            if (S32(RG(0x2530, 0x2360)) > 10000) {
                S32(RG(0x2530, 0x2360)) = 10000;
            }
        }
        char* var8 = func_0200ff1c(var0, S8(RG(0x1c21, 0x1ae9)));
        if (var8 != 0) {
            int var9[3];
            _ZN8Vector3iaSERKS_(var9, var8 + 0x44);
            if (var9[0] != S32(RG(0x2524, 0x2354)) || var9[1] != S32(RG(0x2528, 0x2358)) || var9[2] != S32(RG(0x252c, 0x235c)) || U8(RG(0x2523, 0x2353)) != 0) {
                *(unsigned int*)(var8 + RG(0x18c, 0x180)) &= ~1;
                U8(RG(0x2523, 0x2353)) = 1;
            }
        }
    }

    *(unsigned char*)(var1 + RG(0x19ae, 0x17de)) = 0;

    int var10 = S32(RG(0x1bc0, 0x1a88));
    if (var10 == 0) {
        if (U8(RG(0x1c7a, 0x1b3e)) == 0 || U8(RG(0x1c7b, 0x1b3f)) == 10) {
            goto reset;
        }
        int var11 = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
        if (var11 == 0) var11 = 1;
        if (U8(RG(0x1c7b, 0x1b3f)) == 0x14) {
            int var12 = 0;
            for (int var13 = 0; var13 < U8(RG(0x1ccb, 0x1b8f)); var13++) {
                if (func_0202c578(var2, *(signed char*)(arg0 + var13 + RG(0x1ccc, 0x1b90)))) {
                    var12 = 1;
                    break;
                }
            }
            if (func_ov002_0216c628((unsigned char*)arg0, var11) == 0 || var12 != 0) {
                Struct_ov002_0216acf0_5* var14 = (Struct_ov002_0216acf0_5*)(arg0 + RG(0xcd0 + 0x1000, 0x1b94));
                Struct_ov002_0216acf0_5* var15 = (Struct_ov002_0216acf0_5*)(arg0 + RG(0xe8 + 0x1c00, 0x1bac));
                for (int var16 = 0; var16 < U8(RG(0x1ccb, 0x1b8f)); var16++) {
                    if (var14[var16].unknown_4_ != 0 || var15[var16].unknown_4_ != 0) {
                        var14[var16].unknown_0_ = 0;
                        var14[var16].unknown_2_ = 0;
                        var15[var16].unknown_0_ = 0;
                        var15[var16].unknown_2_ = 0;
                    }
                }
                U8(RG(0x1c7b, 0x1b3f)) = 0x15;
            }
        }
        if (U8(RG(0x1c7b, 0x1b3f)) == 0x15) {
            Struct_ov002_0216acf0_5* var17 = (Struct_ov002_0216acf0_5*)(arg0 + RG(0xcd0 + 0x1000, 0x1b94));
            Struct_ov002_0216acf0_5* var18 = (Struct_ov002_0216acf0_5*)(arg0 + RG(0xe8 + 0x1c00, 0x1bac));
            int var19 = 0;
            for (int var20 = 0; var20 < U8(RG(0x1ccb, 0x1b8f)); var20++) {
                if (var17[var20].unknown_0_ == 3 || var18[var20].unknown_0_ == 3) {
                    var19 = 1;
                }
            }
            if (U8(RG(0x1cc6, 0x1b8a)) != 0) {
                if (var19 != 0) {
                    func_ov002_0215a7b4(arg0, S8(RG(0x1c20, 0x1ae8)), S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 1);
                }
                func_ov002_02159900(arg0, arg0 + RG(0xc8 + 0x1c00, 0x1b8c), var19);
                if (S32(RG(0x1d00, 0x1bc4)) != 0) {
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x2b, 0x2e);
                } else {
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = 5;
                }
            }
            if (U8(RG(0x1cc7, 0x1b8b)) != 0) {
                func_ov002_0215a0a4(self, self + RG(0xc8 + 0x1c00, 0x1b8c), any);
                SePlayer_Play((SePlayer*)&g_sePlayer, 100, 0);
                if (S32(RG(0x1d00, 0x1bc4)) != 0) {
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x2b, 0x2e);
                } else {
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x11, 0x12);
                }
            }
            func_ov002_02157ce0(arg0 + RG(0xc8 + 0x1c00, 0x1b8c));
            U8(RG(0x1c7a, 0x1b3e)) = 0;
            U8(RG(0x1c7b, 0x1b3f)) = 0;
        }
        return;
        {
        reset:
            S32(RG(0x247c, 0x22ac)) &= ~4;
            S16(RG(0x1c16, 0x1ade)) = 0;
            S16(RG(0x1c18, 0x1ae0)) = 0;
            func_0205de24((Struct_ov002_0215624c_11*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 0, 3);
            func_ov002_02161174(arg0);
            S32(RG(0x247c, 0x22ac)) &= ~4;
            S32(RG(0x1bc0, 0x1a88)) = 1;
            return;
        }
        return;
    }

    if (var10 == 1) {
        if (U8(RG(0x1c2e, 0x1af6)) != 0) {
            S32(RG(0x1bb8, 0x1a80)) = K(0x25, 0x28);
            S32(RG(0x1bc0, 0x1a88)) = 0;
            return;
        }
        if (S32(RG(0x1bbc, 0x1a84)) == K(0x24, 0x27)) {
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 2;
            if (U8(RG(0x1cc2, 0x1b86)) != 0) {
                S32(RG(0x1bc0, 0x1a88)) = 3;
            }
            return;
        }
        if (U8(RG(0x1c30, 0x1af8)) != 0) {
            int var21 = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (var21 == 0) var21 = 1;
            if (func_ov002_0216c628((unsigned char*)arg0, var21) != 0) {
                return;
            }
            switch (U8(RG(0x1c79, 0x1b3d))) {
            case 1:
                func_ov002_0216bfd4(arg0, 6);
                break;
            case 2:
                if (*(int*)(var1 + RG(0x9a0, 0x870)) == 3) {
                    if (func_ov002_02161b48(arg0, 0) != 0 || g_touchInput.pressed_ != 0) {
                        func_ov002_0216bfd4(arg0, 3);
                    }
                }
                break;
            case 8:
                if (U8(RG(0x1c78, 0x1b3c)) == 0) {
                    func_ov002_0215a7b4(arg0, S8(RG(0x1c20, 0x1ae8)), S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 0);
                } else {
                    func_ov002_0215a7b4(arg0, 4, S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 0);
                }
                func_ov017_021d0198(3, S8(RG(0x1c20, 0x1ae8)), S8(RG(0x1c21, 0x1ae9)), S16(RG(0x1c22, 0x1aea)));
                func_ov002_0216bfd4(arg0, 9);
                break;
            }
            return;
        }
        if (U8(RG(0x1c7a, 0x1b3e)) != 0) {
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            int ok = 0;
            int flag = g_keyManager.TestKeysPressed(0x601);
            if (AnySet(flag, Window_IsSelectionTouched((struct Obj_0205da38*)(self + RG(0x2c8 + 0xc00, 0xe20)), 0x14)) ||
                CheckFlagOrThreshold_02161b48(self, 1) != 0 ||
                g_keyManager.TestKeysPressed(0xf0) != 0 || g_touchInput.pressed_ != 0) {
                var23 = 1;
            }
            switch (U8(RG(0x1c7b, 0x1b3f))) {
            case 10:
                if (func_ov002_0216c628((unsigned char*)arg0, var22) == 0) {
                    func_ov002_0216c28c(arg0, 0xc);
                }
                break;
            case 11:
                if (var23 != 0) {
                    U8(RG(0x1c7a, 0x1b3e)) = 0;
                    U8(RG(0x1c7b, 0x1b3f)) = 0;
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x11, 0x12);
                    U8(RG(0x248a, 0x22ba)) = 0;
                }
                break;
            case 12:
                if (var23 != 0) {
                    U8(RG(0x1c7a, 0x1b3e)) = 0;
                    U8(RG(0x1c7b, 0x1b3f)) = 0;
                    S16(RG(0x1c28, 0x1af0)) = 0x232b;
                    S16(RG(0x1c2a, 0x1af2)) = -1;
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x11, 0x12);
                    U8(RG(0x248a, 0x22ba)) = 0;
                    S32(RG(0x1bc0, 0x1a88)) = 0;
                }
                break;
            }
            return;
        }
        if (U8(RG(0x2522, 0x2352)) != 0 && *(int*)(var1 + RG(0x9a0, 0x870)) != 3) {
            char* var25 = func_0200ff1c(var0, S8(RG(0x1c21, 0x1ae9)));
            if (var25 != 0) {
                int var26[3];
                _ZN8Vector3iaSERKS_(var26, var25 + 0x44);
                if (var26[0] != S32(RG(0x2524, 0x2354)) || var26[1] != S32(RG(0x2528, 0x2358)) || var26[2] != S32(RG(0x252c, 0x235c)) || U8(RG(0x2523, 0x2353)) != 0) {
                    *(unsigned int*)(var25 + RG(0x18c, 0x180)) &= ~1;
                    U8(RG(0x2523, 0x2353)) = 1;
                    if (*(int*)(g + RG(0x9a0, 0x870)) == 2 && S32(RG(0x2530, 0x2360)) >= 1000) {
                        SetField9a0AndIncrementField78((Struct020444bc*)g);
                        SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
                        U8(RG(0x2522, 0x2352)) = 0;
                        U8(RG(0x2523, 0x2353)) = 0;
                        memset(arg0 + RG(0x124 + 0x2400, 0x2354), 0, 0xc);
                        S32(RG(0x2530, 0x2360)) = 0;
                    }
                    return;
                }
            }
        }
        if (U8(RG(0x1c31, 0x1af9)) != 0) {
            if (!inline_ov002_0216acf0_2(var1)) {
                return;
            }
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            U8(RG(0x1c31, 0x1af9)) = 0;
            char* var27 = func_0205d888((Struct_ov002_0216acf0_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)));
            if (var27 != 0) {
                int var28 = S32(RG(0x1bbc, 0x1a84));
                if (var28 != *(unsigned char*)(var27 + 0xc4) && var28 != K(0x26, 0x29) && var28 != K(0x10, 0x11) && var28 != K(0x11, 0x12)) {
                    func_ov002_02156ff0((unsigned char*)arg0, var28);
                }
            }
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 1;
            if (S32(RG(0x1bb8, 0x1a80)) == 5) {
                if (U8(RG(0x2478, 0x22a8)) != 0) {
                    int var29 = func_ov002_02157108(arg0, S8(RG(0x1c20, 0x1ae8)));
                    if (var29 == 0) {
                        S16(RG(0x1c22, 0x1aea)) = -1;
                        S16(RG(0x1be8, 0x1ab0)) = -1;
                        S32(RG(0x1bb8, 0x1a80)) = 4;
                        S32(RG(0x1bc0, 0x1a88)) = 1;
                        func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4);
                        func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                        func_ov002_02161cf0(arg0);
                        if (S32(RG(0x247c, 0x22ac)) & 1) {
                            func_ov023_021dca88(arg0 + RG(0x50, 0x38));
                        }
                        return;
                    }
                    if (S16(RG(0x1be8, 0x1ab0)) >= var29) {
                        S16(RG(0x1be8, 0x1ab0)) = var29 - 1;
                        func_0205d7a0(arg0 + RG(0x2c8 + 0xc00, 0xe20), S16(RG(0x1be8, 0x1ab0)));
                    }
                    memset(*(void**)(arg0 + RG(0x1bd0, 0x1a98)), 0, RG(0x960, 0x800));
                    func_ov002_0215c988(arg0, *(void**)(arg0 + RG(0x1bd0, 0x1a98)), 0);
                    func_0205d5d0((Struct_ov002_0215bba8_3*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), (unsigned char)S32(RG(0x1bb8, 0x1a80)), (int)(*(void**)(arg0 + RG(0x1bd0, 0x1a98))), 1 TAE_LAST(0));
                    U8(RG(0x2478, 0x22a8)) = 0;
                }
            } else if (S32(RG(0x1bb8, 0x1a80)) == K(0x11, 0x12)) {
                if (S16(RG(0x1c26, 0x1aee)) == 0x22 || S16(RG(0x1c26, 0x1aee)) == 0x310) {
                    func_ov002_02161cf0(arg0);
                }
            } else if (S32(RG(0x247c, 0x22ac)) & 1) {
                func_ov023_021dca88(arg0 + RG(0x50, 0x38));
            }
        }
        if (*(int*)(var1 + RG(0x9a0, 0x870)) != 3) {
            return;
        }
        U8(RG(0x2522, 0x2352)) = 0;
        U8(RG(0x2523, 0x2353)) = 0;
        memset(arg0 + RG(0x124 + 0x2400, 0x2354), 0, 0xc);
        S32(RG(0x2530, 0x2360)) = 0;
        if (U8(RG(0x248a, 0x22ba)) != 0) {
            func_ov002_02156ff0((unsigned char*)arg0, K(0x26, 0x29));
            func_ov002_0215b9a4(arg0, S32(RG(0x1bb8, 0x1a80)) & 0xff, 1);
            S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
            S16(RG(0x1c28, 0x1af0)) = S16(RG(0x2488, 0x22b8));
            S16(RG(0x2488, 0x22b8)) = -1;
            U8(RG(0x248a, 0x22ba)) = 0;
            S32(RG(0x1bc0, 0x1a88)) = 0;
            if (S16(RG(0x1c28, 0x1af0)) == 0x7532 || S16(RG(0x1c28, 0x1af0)) == 0x7531) {
                SetForwardAndStore0205ebc0(&g_sePlayer, 0x75, 0x75);
                DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
            }
            return;
        }
        if (S32(RG(0x1bbc, 0x1a84)) == K(0x17, 0x18)) {
            if (S8(RG(0x1caf, 0x1b73)) == 4) {
                U8(RG(0x1cae, 0x1b72)) = 5;
                U8(RG(0x1caf, 0x1b73)) = 0;
            }
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 0;
        } else {
            func_02043204(var1);
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            if (S8(RG(0x1caf, 0x1b73)) == 4) {
                U8(RG(0x1cae, 0x1b72)) = 5;
                U8(RG(0x1caf, 0x1b73)) = 0;
            }
            if (S16(RG(0x1c28, 0x1af0)) == 0x7530) {
                SetForwardAndStore0205ebc0(&g_sePlayer, 0x75, 0x75);
                DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
            }
            char* var30 = func_0205d888((Struct_ov002_0216acf0_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)));
            if (U8(RG(0x2521, 0x2351)) != 0) {
                S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
                func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4);
                func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                func_ov002_02161cf0(arg0);
                U8(RG(0x2521, 0x2351)) = 0;
            } else if (var30 != 0) {
                int var31 = S32(RG(0x1bbc, 0x1a84));
                if (var31 != *(unsigned char*)(var30 + 0xc4) && var31 != K(0x26, 0x29) && var31 != K(0x10, 0x11) && var31 != K(0x11, 0x12) &&
                    var31 != K(9, 0xa) && var31 != K(0xb, 0xc)) {
                    func_ov002_02156ff0((unsigned char*)arg0, var31);
                }
            }
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 1;
        }
        if (U8(RG(0x248c, 0x22bc)) != 0) {
            func_0205d6a0((Struct_ov002_0216acf0_3*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 1);
            S32(RG(0x1bb8, 0x1a80)) = K(0x2b, 0x2e);
            return;
        }
        int var32 = S32(RG(0x1bb8, 0x1a80));
        if (var32 == K(0xb, 0xc)) {
            func_ov002_0215b9a4(arg0, var32 & 0xff, 0);
            func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0xb, 0xc), 0);
            func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0xb, 0xc));
            func_ov002_02161cf0(arg0);
        } else if (var32 == 3) {
            short var33 = S16(RG(0x1be4, 0x1aac));
            func_ov002_02161cf0(arg0);
            S16(RG(0x1be4, 0x1aac)) = var33;
            func_ov002_0215b9a4(arg0, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        } else if (var32 == K(0x10, 0x11)) {
            func_ov002_0215b9a4(arg0, var32 & 0xff, 0);
            S32(RG(0x247c, 0x22ac)) |= 4;
            func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12), 1);
            func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0x10, 0x11));
            func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0x10, 0x11), 0);
            S32(RG(0x1bc0, 0x1a88)) = 1;
            func_ov002_02161cf0(arg0);
        } else if (var32 == K(0x15, 0x16)) {
            short var34 = S16(RG(0x1bfe, 0x1ac6));
            func_ov002_02161cf0(arg0);
            S16(RG(0x1bfe, 0x1ac6)) = var34;
            func_ov002_0215b9a4(arg0, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        } else if (var32 == K(0x11, 0x12)) {
            if (func_0205d81c((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(7, 8)) != 0 || S16(RG(0x1bfc, 0x1ac4)) >= 0) {
                func_ov002_02156ff0((unsigned char*)arg0, K(0x13, 0x14));
                func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12));
                func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12), 0);
                S32(RG(0x1bc0, 0x1a88)) = 1;
                S32(RG(0x1bb8, 0x1a80)) = K(0x11, 0x12);
                if (S16(RG(0x1bfc, 0x1ac4)) >= 0) {
                    S16(RG(0x1bfc, 0x1ac4)) = -1;
                    S16(RG(0x1c26, 0x1aee)) = -1;
                    func_ov002_02161cf0(arg0);
                    func_ov002_0215b9a4(arg0, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
                }
            }
            func_ov002_02161cf0(arg0);
        } else if (var32 == K(9, 0xa)) {
            func_ov002_02161cf0(arg0);
            func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(9, 0xa), 0);
            func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), K(9, 0xa));
            S32(RG(0x1bc8, 0x1a90)) = 1;
            S32(RG(0x1bcc, 0x1a94)) = 1;
            func_ov002_0215b9a4(arg0, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        }
        if (S32(RG(0x1bb8, 0x1a80)) == 5) {
            if (U8(RG(0x2478, 0x22a8)) != 0) {
                int var35 = func_ov002_02157108(arg0, S8(RG(0x1c20, 0x1ae8)));
                if (var35 == 0) {
                    S16(RG(0x1c22, 0x1aea)) = -1;
                    S16(RG(0x1be8, 0x1ab0)) = -1;
                    S32(RG(0x1bb8, 0x1a80)) = 4;
                    S32(RG(0x1bc0, 0x1a88)) = 1;
                    func_0205dee8((Struct_ov002_02164748_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4);
                    func_0205deb4((Struct_ov002_02155960_2*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                    func_ov002_02161cf0(arg0);
                    if (S32(RG(0x247c, 0x22ac)) & 1) {
                        func_ov023_021dca88(arg0 + RG(0x50, 0x38));
                    }
                    return;
                }
                if (S16(RG(0x1be8, 0x1ab0)) >= var35) {
                    S16(RG(0x1be8, 0x1ab0)) = var35 - 1;
                    func_0205d7a0(arg0 + RG(0x2c8 + 0xc00, 0xe20), S16(RG(0x1be8, 0x1ab0)));
                }
                memset(*(void**)(arg0 + RG(0x1bd0, 0x1a98)), 0, RG(0x960, 0x800));
                func_ov002_0215c988(arg0, *(void**)(arg0 + RG(0x1bd0, 0x1a98)), 0);
                func_0205d5d0((Struct_ov002_0215bba8_3*)(arg0 + RG(0x2c8 + 0xc00, 0xe20)), (unsigned char)S32(RG(0x1bb8, 0x1a80)), (int)(*(void**)(arg0 + RG(0x1bd0, 0x1a98))), 1 TAE_LAST(0));
                U8(RG(0x2478, 0x22a8)) = 0;
            }
        } else if (S32(RG(0x1bb8, 0x1a80)) != K(9, 0xa)) {
            if (S32(RG(0x247c, 0x22ac)) & 1) {
                func_ov023_021dca88(arg0 + RG(0x50, 0x38));
            }
        }
        return;
    }

    if (var10 == 3) {
        S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
        S32(RG(0x1bc0, 0x1a88)) = 0;
    }
}
