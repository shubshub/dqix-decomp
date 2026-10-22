#include <globaldefs.h>
#include "std_library_functions.h"
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define K(u, j) (j)
#define func_ov002_0215a0a4 func_ov002_0215b558
#define func_ov002_0215b6c0 func_ov002_0215c914
#else
#define RG(u, j) (u)
#define K(u, j) (u)
#endif

struct GameState;
struct GameObject;
struct SearchStruct;

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
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
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
void TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int);
#define TAE_LAST(x)
#else
void TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);
#define TAE_LAST(x) , x
#endif
extern "C" void func_ov002_0215b9a4(char* self, int key, int flag);
void SetForwardAndStore0205ebc0(void* obj, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void ReinitController02043204(char* g);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
char* FindElementByC40205d81c(Struct_0205d81c*, int);

struct Totals020fdcb0 {
    int a0;
    int b0;
    int a1;
    int b1;
    int pad10[2];
    int c;
    int pad1c;
};

struct Slot0216acf0 {
    unsigned char state;
    unsigned char pad1;
    unsigned short value;
    unsigned char active;
    unsigned char pad5;
};

extern Totals020fdcb0 data_020fdcb0[];
extern char g_sePlayer;

#define U8(o) (*(unsigned char*)(self + (o)))
#define S8(o) (*(signed char*)(self + (o)))
#define S16(o) (*(short*)(self + (o)))
#define S32(o) (*(int*)(self + (o)))

static inline int AnySet(int a, int b) { return (a | b) != 0; }

static inline int IsIdle(char* g) { return *(int*)(g + RG(0x998, 0x868)) == 0; }

// USA: func_ov002_0216acf0
extern "C" ARM void func_ov002_0216acf0(char* self) {
    if (U8(RG(0x1cc5, 0x1b89)) != 0) {
        U8(RG(0x1cc5, 0x1b89)) = 0;
        return;
    }

    GameState* gs = _ZN9GameState11GetInstanceEv();
    char* g = GetGlobalField0x1c020421a0();
    SearchStruct* search = func_0202ae18();

    int sumA = 0;
    int sumB = 0;
    int sumC = 0;
    for (int i = 0; i < 4; i++) {
        Totals020fdcb0* e = &data_020fdcb0[i];
        if (e->a0 >= 0) sumA += e->a0;
        if (e->b0 >= 0) sumB += e->b0;
        if (e->a1 >= 0) sumA += e->a1;
        if (e->b1 >= 0) sumB += e->b1;
        sumC += e->c;
    }
    if (!(S16(RG(0x2548, 0x2370)) == sumA && S16(RG(0x254a, 0x2372)) == sumB && S32(RG(0x254c, 0x2374)) == sumC)) {
        if (S32(RG(0x1bc0, 0x1a88)) != 0) {
            func_ov002_0215b6c0(self);
        }
    }
    S16(RG(0x2548, 0x2370)) = sumA;
    S16(RG(0x254a, 0x2372)) = sumB;
    S32(RG(0x254c, 0x2374)) = sumC;

    if (U8(RG(0x2522, 0x2352)) != 0 && S32(RG(0x1bc0, 0x1a88)) != 0) {
        if (S32(RG(0x1bc0, 0x1a88)) != 0) {
            S32(RG(0x2530, 0x2360)) = S32(RG(0x2530, 0x2360)) + _ZNK9GameState21GetEffectiveDeltaTimeEv(gs);
            if (S32(RG(0x2530, 0x2360)) > 10000) {
                S32(RG(0x2530, 0x2360)) = 10000;
            }
        }
        char* c = GetCombatantWithFlag0x100_0200ff1c(gs, S8(RG(0x1c21, 0x1ae9)));
        if (c != 0) {
            int pos[3];
            _ZN8Vector3iaSERKS_(pos, c + 0x44);
            if (pos[0] != S32(RG(0x2524, 0x2354)) || pos[1] != S32(RG(0x2528, 0x2358)) || pos[2] != S32(RG(0x252c, 0x235c)) || U8(RG(0x2523, 0x2353)) != 0) {
                *(unsigned int*)(c + RG(0x18c, 0x180)) &= ~1;
                U8(RG(0x2523, 0x2353)) = 1;
            }
        }
    }

    *(unsigned char*)(g + RG(0x19ae, 0x17de)) = 0;

    int state = S32(RG(0x1bc0, 0x1a88));
    if (state == 0) {
        if (U8(RG(0x1c7a, 0x1b3e)) == 0 || U8(RG(0x1c7b, 0x1b3f)) == 10) {
            goto reset;
        }
        int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
        if (ticks == 0) ticks = 1;
        if (U8(RG(0x1c7b, 0x1b3f)) == 0x14) {
            int found = 0;
            for (int i = 0; i < U8(RG(0x1ccb, 0x1b8f)); i++) {
                if (TestFlagBitAt0xe_0202c578(search, *(signed char*)(self + i + RG(0x1ccc, 0x1b90)))) {
                    found = 1;
                    break;
                }
            }
            if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) == 0 || found != 0) {
                Slot0216acf0* a = (Slot0216acf0*)(self + RG(0xcd0 + 0x1000, 0x1b94));
                Slot0216acf0* b = (Slot0216acf0*)(self + RG(0xe8 + 0x1c00, 0x1bac));
                for (int i = 0; i < U8(RG(0x1ccb, 0x1b8f)); i++) {
                    if (a[i].active != 0 || b[i].active != 0) {
                        a[i].state = 0;
                        a[i].value = 0;
                        b[i].state = 0;
                        b[i].value = 0;
                    }
                }
                U8(RG(0x1c7b, 0x1b3f)) = 0x15;
            }
        }
        if (U8(RG(0x1c7b, 0x1b3f)) == 0x15) {
            Slot0216acf0* a = (Slot0216acf0*)(self + RG(0xcd0 + 0x1000, 0x1b94));
            Slot0216acf0* b = (Slot0216acf0*)(self + RG(0xe8 + 0x1c00, 0x1bac));
            int any = 0;
            for (int i = 0; i < U8(RG(0x1ccb, 0x1b8f)); i++) {
                if (a[i].state == 3 || b[i].state == 3) {
                    any = 1;
                }
            }
            if (U8(RG(0x1cc6, 0x1b8a)) != 0) {
                if (any != 0) {
                    func_ov002_0215a7b4(self, S8(RG(0x1c20, 0x1ae8)), S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 1);
                }
                func_ov002_02159900(self, self + RG(0xc8 + 0x1c00, 0x1b8c), any);
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
            InitStateArray02157ce0(self + RG(0xc8 + 0x1c00, 0x1b8c));
            U8(RG(0x1c7a, 0x1b3e)) = 0;
            U8(RG(0x1c7b, 0x1b3f)) = 0;
        }
        return;
        {
        reset:
            S32(RG(0x247c, 0x22ac)) &= ~4;
            S16(RG(0x1c16, 0x1ade)) = 0;
            S16(RG(0x1c18, 0x1ae0)) = 0;
            FindAndLinkMatchingEntry0205de24((Struct0205de24*)(self + RG(0x2c8 + 0xc00, 0xe20)), 0, 3);
            InitBattleTag02161174(self);
            S32(RG(0x247c, 0x22ac)) &= ~4;
            S32(RG(0x1bc0, 0x1a88)) = 1;
            return;
        }
        return;
    }

    if (state == 1) {
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
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) != 0) {
                return;
            }
            switch (U8(RG(0x1c79, 0x1b3d))) {
            case 1:
                func_ov002_0216bfd4(self, 6);
                break;
            case 2:
                if (*(int*)(g + RG(0x9a0, 0x870)) == 3) {
                    if (CheckFlagOrThreshold_02161b48(self, 0) != 0 || g_touchInput.pressed_ != 0) {
                        func_ov002_0216bfd4(self, 3);
                    }
                }
                break;
            case 8:
                if (U8(RG(0x1c78, 0x1b3c)) == 0) {
                    func_ov002_0215a7b4(self, S8(RG(0x1c20, 0x1ae8)), S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 0);
                } else {
                    func_ov002_0215a7b4(self, 4, S16(RG(0x1c22, 0x1aea)), S16(RG(0x1be8, 0x1ab0)), 0);
                }
                EnqueueEventTag170_021d0198(3, S8(RG(0x1c20, 0x1ae8)), S8(RG(0x1c21, 0x1ae9)), S16(RG(0x1c22, 0x1aea)));
                func_ov002_0216bfd4(self, 9);
                break;
            }
            return;
        }
        if (U8(RG(0x1c7a, 0x1b3e)) != 0) {
            int ticks = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
            if (ticks == 0) ticks = 1;
            int ok = 0;
            int flag = g_keyManager.TestKeysPressed(0x601);
            if (AnySet(flag, IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + RG(0x2c8 + 0xc00, 0xe20)), 0x14)) ||
                CheckFlagOrThreshold_02161b48(self, 1) != 0 ||
                g_keyManager.TestKeysPressed(0xf0) != 0 || g_touchInput.pressed_ != 0) {
                ok = 1;
            }
            switch (U8(RG(0x1c7b, 0x1b3f))) {
            case 10:
                if (DecrementOrClearCounterC74_0216c628((unsigned char*)self, ticks) == 0) {
                    func_ov002_0216c28c(self, 0xc);
                }
                break;
            case 11:
                if (ok != 0) {
                    U8(RG(0x1c7a, 0x1b3e)) = 0;
                    U8(RG(0x1c7b, 0x1b3f)) = 0;
                    S32(RG(0x1bb8, 0x1a80)) = K(0x26, 0x29);
                    S32(RG(0x1bbc, 0x1a84)) = K(0x11, 0x12);
                    U8(RG(0x248a, 0x22ba)) = 0;
                }
                break;
            case 12:
                if (ok != 0) {
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
        if (U8(RG(0x2522, 0x2352)) != 0 && *(int*)(g + RG(0x9a0, 0x870)) != 3) {
            char* c = GetCombatantWithFlag0x100_0200ff1c(gs, S8(RG(0x1c21, 0x1ae9)));
            if (c != 0) {
                int pos[3];
                _ZN8Vector3iaSERKS_(pos, c + 0x44);
                if (pos[0] != S32(RG(0x2524, 0x2354)) || pos[1] != S32(RG(0x2528, 0x2358)) || pos[2] != S32(RG(0x252c, 0x235c)) || U8(RG(0x2523, 0x2353)) != 0) {
                    *(unsigned int*)(c + RG(0x18c, 0x180)) &= ~1;
                    U8(RG(0x2523, 0x2353)) = 1;
                    if (*(int*)(g + RG(0x9a0, 0x870)) == 2 && S32(RG(0x2530, 0x2360)) >= 1000) {
                        SetField9a0AndIncrementField78((Struct020444bc*)g);
                        SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
                        U8(RG(0x2522, 0x2352)) = 0;
                        U8(RG(0x2523, 0x2353)) = 0;
                        memset(self + RG(0x124 + 0x2400, 0x2354), 0, 0xc);
                        S32(RG(0x2530, 0x2360)) = 0;
                    }
                    return;
                }
            }
        }
        if (U8(RG(0x1c31, 0x1af9)) != 0) {
            if (!IsIdle(g)) {
                return;
            }
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
            U8(RG(0x1c31, 0x1af9)) = 0;
            char* e = GetLastEntry0205d888((Struct0205d888*)(self + RG(0x2c8 + 0xc00, 0xe20)));
            if (e != 0) {
                int next = S32(RG(0x1bbc, 0x1a84));
                if (next != *(unsigned char*)(e + 0xc4) && next != K(0x26, 0x29) && next != K(0x10, 0x11) && next != K(0x11, 0x12)) {
                    ClearMatchingEntry_02156ff0((unsigned char*)self, next);
                }
            }
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 1;
            if (S32(RG(0x1bb8, 0x1a80)) == 5) {
                if (U8(RG(0x2478, 0x22a8)) != 0) {
                    int count = GetCountByType02157108(self, S8(RG(0x1c20, 0x1ae8)));
                    if (count == 0) {
                        S16(RG(0x1c22, 0x1aea)) = -1;
                        S16(RG(0x1be8, 0x1ab0)) = -1;
                        S32(RG(0x1bb8, 0x1a80)) = 4;
                        S32(RG(0x1bc0, 0x1a88)) = 1;
                        SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4);
                        SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                        func_ov002_02161cf0(self);
                        if (S32(RG(0x247c, 0x22ac)) & 1) {
                            func_ov023_021dca88(self + RG(0x50, 0x38));
                        }
                        return;
                    }
                    if (S16(RG(0x1be8, 0x1ab0)) >= count) {
                        S16(RG(0x1be8, 0x1ab0)) = count - 1;
                        func_0205d7a0(self + RG(0x2c8 + 0xc00, 0xe20), S16(RG(0x1be8, 0x1ab0)));
                    }
                    memset(*(void**)(self + RG(0x1bd0, 0x1a98)), 0, RG(0x960, 0x800));
                    func_ov002_0215c988(self, *(void**)(self + RG(0x1bd0, 0x1a98)), 0);
                    TryApplyElemFields0205d5d0((StructA0205d5d0*)(self + RG(0x2c8 + 0xc00, 0xe20)), (unsigned char)S32(RG(0x1bb8, 0x1a80)), (int)(*(void**)(self + RG(0x1bd0, 0x1a98))), 1 TAE_LAST(0));
                    U8(RG(0x2478, 0x22a8)) = 0;
                }
            } else if (S32(RG(0x1bb8, 0x1a80)) == K(0x11, 0x12)) {
                if (S16(RG(0x1c26, 0x1aee)) == 0x22 || S16(RG(0x1c26, 0x1aee)) == 0x310) {
                    func_ov002_02161cf0(self);
                }
            } else if (S32(RG(0x247c, 0x22ac)) & 1) {
                func_ov023_021dca88(self + RG(0x50, 0x38));
            }
        }
        if (*(int*)(g + RG(0x9a0, 0x870)) != 3) {
            return;
        }
        U8(RG(0x2522, 0x2352)) = 0;
        U8(RG(0x2523, 0x2353)) = 0;
        memset(self + RG(0x124 + 0x2400, 0x2354), 0, 0xc);
        S32(RG(0x2530, 0x2360)) = 0;
        if (U8(RG(0x248a, 0x22ba)) != 0) {
            ClearMatchingEntry_02156ff0((unsigned char*)self, K(0x26, 0x29));
            func_ov002_0215b9a4(self, S32(RG(0x1bb8, 0x1a80)) & 0xff, 1);
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
            ReinitController02043204(g);
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
            char* e = GetLastEntry0205d888((Struct0205d888*)(self + RG(0x2c8 + 0xc00, 0xe20)));
            if (U8(RG(0x2521, 0x2351)) != 0) {
                S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
                SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                func_ov002_02161cf0(self);
                U8(RG(0x2521, 0x2351)) = 0;
            } else if (e != 0) {
                int next = S32(RG(0x1bbc, 0x1a84));
                if (next != *(unsigned char*)(e + 0xc4) && next != K(0x26, 0x29) && next != K(0x10, 0x11) && next != K(0x11, 0x12) &&
                    next != K(9, 0xa) && next != K(0xb, 0xc)) {
                    ClearMatchingEntry_02156ff0((unsigned char*)self, next);
                }
            }
            S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
            S32(RG(0x1bc0, 0x1a88)) = 1;
        }
        if (U8(RG(0x248c, 0x22bc)) != 0) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)(self + RG(0x2c8 + 0xc00, 0xe20)), 1);
            S32(RG(0x1bb8, 0x1a80)) = K(0x2b, 0x2e);
            return;
        }
        int cur = S32(RG(0x1bb8, 0x1a80));
        if (cur == K(0xb, 0xc)) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0xb, 0xc), 0);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0xb, 0xc));
            func_ov002_02161cf0(self);
        } else if (cur == 3) {
            short saved = S16(RG(0x1be4, 0x1aac));
            func_ov002_02161cf0(self);
            S16(RG(0x1be4, 0x1aac)) = saved;
            func_ov002_0215b9a4(self, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        } else if (cur == K(0x10, 0x11)) {
            func_ov002_0215b9a4(self, cur & 0xff, 0);
            S32(RG(0x247c, 0x22ac)) |= 4;
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12), 1);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0x10, 0x11));
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0x10, 0x11), 0);
            S32(RG(0x1bc0, 0x1a88)) = 1;
            func_ov002_02161cf0(self);
        } else if (cur == K(0x15, 0x16)) {
            short saved = S16(RG(0x1bfe, 0x1ac6));
            func_ov002_02161cf0(self);
            S16(RG(0x1bfe, 0x1ac6)) = saved;
            func_ov002_0215b9a4(self, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        } else if (cur == K(0x11, 0x12)) {
            if (FindElementByC40205d81c((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(7, 8)) != 0 || S16(RG(0x1bfc, 0x1ac4)) >= 0) {
                ClearMatchingEntry_02156ff0((unsigned char*)self, K(0x13, 0x14));
                SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12));
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(0x11, 0x12), 0);
                S32(RG(0x1bc0, 0x1a88)) = 1;
                S32(RG(0x1bb8, 0x1a80)) = K(0x11, 0x12);
                if (S16(RG(0x1bfc, 0x1ac4)) >= 0) {
                    S16(RG(0x1bfc, 0x1ac4)) = -1;
                    S16(RG(0x1c26, 0x1aee)) = -1;
                    func_ov002_02161cf0(self);
                    func_ov002_0215b9a4(self, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
                }
            }
            func_ov002_02161cf0(self);
        } else if (cur == K(9, 0xa)) {
            func_ov002_02161cf0(self);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(9, 0xa), 0);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), K(9, 0xa));
            S32(RG(0x1bc8, 0x1a90)) = 1;
            S32(RG(0x1bcc, 0x1a94)) = 1;
            func_ov002_0215b9a4(self, S32(RG(0x1bb8, 0x1a80)) & 0xff, 0);
        }
        if (S32(RG(0x1bb8, 0x1a80)) == 5) {
            if (U8(RG(0x2478, 0x22a8)) != 0) {
                int count = GetCountByType02157108(self, S8(RG(0x1c20, 0x1ae8)));
                if (count == 0) {
                    S16(RG(0x1c22, 0x1aea)) = -1;
                    S16(RG(0x1be8, 0x1ab0)) = -1;
                    S32(RG(0x1bb8, 0x1a80)) = 4;
                    S32(RG(0x1bc0, 0x1a88)) = 1;
                    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4);
                    SetElementFieldC2_0205deb4((Struct_0205d81c*)(self + RG(0x2c8 + 0xc00, 0xe20)), 4, 0);
                    func_ov002_02161cf0(self);
                    if (S32(RG(0x247c, 0x22ac)) & 1) {
                        func_ov023_021dca88(self + RG(0x50, 0x38));
                    }
                    return;
                }
                if (S16(RG(0x1be8, 0x1ab0)) >= count) {
                    S16(RG(0x1be8, 0x1ab0)) = count - 1;
                    func_0205d7a0(self + RG(0x2c8 + 0xc00, 0xe20), S16(RG(0x1be8, 0x1ab0)));
                }
                memset(*(void**)(self + RG(0x1bd0, 0x1a98)), 0, RG(0x960, 0x800));
                func_ov002_0215c988(self, *(void**)(self + RG(0x1bd0, 0x1a98)), 0);
                TryApplyElemFields0205d5d0((StructA0205d5d0*)(self + RG(0x2c8 + 0xc00, 0xe20)), (unsigned char)S32(RG(0x1bb8, 0x1a80)), (int)(*(void**)(self + RG(0x1bd0, 0x1a98))), 1 TAE_LAST(0));
                U8(RG(0x2478, 0x22a8)) = 0;
            }
        } else if (S32(RG(0x1bb8, 0x1a80)) != K(9, 0xa)) {
            if (S32(RG(0x247c, 0x22ac)) & 1) {
                func_ov023_021dca88(self + RG(0x50, 0x38));
            }
        }
        return;
    }

    if (state == 3) {
        S32(RG(0x1bb8, 0x1a80)) = S32(RG(0x1bbc, 0x1a84));
        S32(RG(0x1bc0, 0x1a88)) = 0;
    }
}
