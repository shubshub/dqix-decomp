#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
enum { regionalState0d = 0xe, regionalState26 = 0x29 };
#else
#define REGIONAL_OFFSET(jp, us) us
enum { regionalState0d = 0xd, regionalState26 = 0x26 };
#endif

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Struct_0205def8;
struct ArrayContainsByteStruct;
struct KeyMap020a0b3c;
struct KeyMap020a0a08;
struct KeyMap020a095c;
struct Slots02083994;
struct Container020dedd0;
int BuildFlaggedCombatantSlotList_02154f4c(unsigned char *obj);
void *GetFieldAt0x150_02053c6c(unsigned char *obj);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CountFlag0x800MatchesEqualsTarget020dcc20(int targetCount, int flag);
void *GetPtrField0x2a04_02010828(GameState *gs);
int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct *s, int val);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
extern "C" int func_0205df38(void *list, int key);
int CheckAnyByteMatches020dcbbc(unsigned char *arr, int count, int b, int c, int d);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int LookupValueByKey020a0b3c(struct KeyMap020a0b3c *map, int key);
int DecrementKeyValue020a0a08(KeyMap020a0a08*, int, int);
extern "C" int _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii(struct KeyMap020a095c *map, int key, signed char amount);
int CountMatchingUntilNegative02083994(struct Slots02083994 *s, int value);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" int *func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int *p);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
int GetField0x3acValue_020100a8(GameState *gs);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
int CheckFlagOrThreshold_02161b48(char *base, int a);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215d654(char *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b2c8(char *self);
extern "C" void func_ov002_0216bfd4(char *self, int a);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" char g_sePlayer[];

#define L(base) ((base) + REGIONAL_OFFSET(0xe20, 0x2c8 + 0xc00))

// USA: func_ov002_02163bd0
extern "C" ARM void func_ov002_02163bd0(char *base) {
    GameState *gs = GameState::GetInstance();
    int state     = *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa88, 0xbc0));
    if (state == 0) {
        *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) = BuildFlaggedCombatantSlotList_02154f4c((unsigned char *) base);
        if (gs->GetProtagonist() != NULL) {
            int i;
            for (i = 0; i <= *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d)); i++) {
                GameObject *m = gs->GetPartyMemberByIndex(*(unsigned char *) (base + i + 0x1000 + REGIONAL_OFFSET(0xb2c, 0xc68)));
                if (m != NULL && *(int *) ((char *) m + REGIONAL_OFFSET(0x1b8, 0x1c4)) != 0) {
                    int j;
                    for (j = i; j <= *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d)); j++) {
                        *(unsigned char *) (base + j + 0x1000 + REGIONAL_OFFSET(0xb2c, 0xc68)) = *(unsigned char *) (base + REGIONAL_OFFSET(0x32c + 0x1800, 0x68 + 0x1c00) + (j + 1));
                        *(unsigned char *) (base + REGIONAL_OFFSET(0x32c + 0x1800, 0x68 + 0x1c00) + (j + 1)) = 0xff;
                    }
                    (*(unsigned char *) (base + REGIONAL_OFFSET(0x31 + 0x1b00, 0x6d + 0x1c00)))--;
                }
            }
            int x = *(short *) ((char *) GetFieldAt0x150_02053c6c((unsigned char *) gs->GetProtagonist()) + REGIONAL_OFFSET(0x800 + 0xc6, 0x900 + 0x5e));
            int j;
            for (j = 0; j <= *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d)); j++) {
                if (x == *(unsigned char *) (base + j + 0x1000 + REGIONAL_OFFSET(0xb2c, 0xc68))) {
                    *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) = j;
                    break;
                }
            }
        }
        func_ov002_0215b814(base);
        *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xae9, 0xc21)) =
            *(unsigned char *) (base + *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) + 0x1000 + REGIONAL_OFFSET(0xb2c, 0xc68));
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) L(base), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215d654(base);
        *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa88, 0xbc0)) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + REGIONAL_OFFSET(0x2ac, 0x47c)) |= 4;
        int old = *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee));
        *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) L(base));
        if (old != *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee))) *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa94, 0xbcc)) = 1;
        if (*(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) < *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d))) {
            *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xae9, 0xc21)) =
                *(unsigned char *) (base + *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee)) + 0x1000 + REGIONAL_OFFSET(0xb2c, 0xc68));
        } else {
            *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xae9, 0xc21)) = 4;
        }
        if (!CountFlag0x800MatchesEqualsTarget020dcc20(*(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d)), 1)) {
            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee))        = -1;
            *(signed char *) (base + 0x1000 + REGIONAL_OFFSET(0xae9, 0xc21)) = -1;
            func_ov002_02156e90(base);
            return;
        }
        int flag = 0;
        if (!ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct *) GetPtrField0x2a04_02010828(gs),
                               *(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21))) &&
            *(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21)) != 4)
        {
            SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) L(base), flag, regionalState0d);
        } else {
            SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) L(base), 1, regionalState0d);
            if (func_0205df38(L(base), regionalState0d)) flag = 1;
        }
        if (*(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb88, 0xcc4)) != 0 ||
            CheckAnyByteMatches020dcbbc((unsigned char *) (base + REGIONAL_OFFSET(0x32c + 0x1800, 0x68 + 0x1c00)),
                                                  *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb31, 0xc6d)), 0, 0, 0))
        {
            *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa94, 0xbcc)) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8)), 0);
        }
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) L(base), regionalState0d, 1);
        if (old != *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee))) return;
        int ta = g_keyManager.TestKeysPressed(0x601);
        int tb = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(L(base)), 0x14);
        if (((ta | tb) ? 1 : 0) || flag) {
            GameObject *pr = gs->GetProtagonist();
            if (pr != NULL) {
                int v = *(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21));
                *(short *) ((char *) GetFieldAt0x150_02053c6c((unsigned char *) pr) + REGIONAL_OFFSET(0x800 + 0xc6, 0x900 + 0x5e)) = v;
            }
            if (*(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21)) == 4) {
                SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                *(unsigned int *) (base + 0x2000 + REGIONAL_OFFSET(0x2ac, 0x47c)) &= ~4;
                if (*(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe8, 0x1c00 + 0x20)) == 4) {
                    void *map = GetPtrField0x2a04_02010828(GameState::GetInstance());
                    int v     = LookupValueByKey020a0b3c((struct KeyMap020a0b3c *) map,
                                                                               *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)));
                    DecrementKeyValue020a0a08((struct KeyMap020a0a08 *) map, *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)), (signed char)v);
                    _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) map,
                                                                      *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)), v);
                    *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf0, 0x1c00 + 0x28)) = 0x236e;
                } else {
                    GameState *g2 = GameState::GetInstance();
                    void *map     = GetPtrField0x2a04_02010828(g2);
                    char *m       = (char *)GetCombatantWithFlag0x100_0200ff1c(g2, *(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe8, 0x1c00 + 0x20)));
                    if (m != NULL) {
                        func_ov002_0215a7b4(base, *(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe8, 0x1c00 + 0x20)), *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)),
                                            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb0, 0x1b00 + 0xe8)), 0);
                        _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) map,
                                                                          *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)), 1);
#if !defined(jpn)
                        func_ov002_0215b2c8(base);
#endif
                        if (**(int **) (m + 0x130) & 1) {
                            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf0, 0x1c00 + 0x28)) = 0x2362;
                        } else {
                            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf0, 0x1c00 + 0x28)) = 0x2361;
                        }
                        if (*(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)) == 0x570a &&
                            CountMatchingUntilNegative02083994(
                                (struct Slots02083994 *) GetFieldAt0x150_02053c6c((unsigned char *) m), 0x570a) == 0)
                        {
                            *(unsigned char *) (*(char **) (m + 0x130) + 8) = 0;
                            func_ov017_021c9e00(*(short *) (m + 4), 0, 0, 1);
                        }
                    } else {
                        *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf0, 0x1c00 + 0x28)) = 0x2361;
                    }
                }
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8)), 1);
                func_ov002_0215b9a4(base, regionalState0d, 0);
                *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf2, 0x1c00 + 0x2a))          = -1;
                *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8))           = regionalState26;
                *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa84, 0xbbc))           = 5;
                *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa88, 0xbc0))           = 0;
                *(unsigned char *) (base + 0x2000 + REGIONAL_OFFSET(0x2a8, 0x478)) = 1;
            } else if (func_020dc920(*(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21)) & 0xff, 0, 0, 0)) {
                SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                *(unsigned int *) (base + 0x2000 + REGIONAL_OFFSET(0x2ac, 0x47c)) &= ~4;
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8)), 1);
                if (CheckField0NonZero_0202b7d8(func_0202ae18())) {
                    int ok = 1;
                    int i  = 0;
                    for (; i < *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xafc, 0xc38)); i++) {
                        if (*(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe9, 0x1c00 + 0x21)) == *(int *) (base + i * 4 + 0x1000 + REGIONAL_OFFSET(0xb00, 0xc3c))) ok = 0;
                    }
                    if (ok) {
                        int good = 0;
                        char *e  = FindElementByKey020dedd0(
                            (struct Container020dedd0 *) (base + REGIONAL_OFFSET(0x750, 0x3ec + 0x400)), *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xea, 0x1c00 + 0x22)));
                        if (e != NULL && ((*(unsigned int *) (e + 8) << 14) >> 30) == 1) good = 1;
                        if (!good) {
                            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf0, 0x1c00 + 0x28)) = 0x2376;
                            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xf2, 0x1c00 + 0x2a)) = -1;
                            *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8))  = regionalState26;
                            *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa84, 0xbbc))  = 5;
                            *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa88, 0xbc0))  = 0;
                            return;
                        }
                        if (*(signed char *) (base + REGIONAL_OFFSET(0x1a00 + 0xe8, 0x1c00 + 0x20)) == 4) {
                            *(signed char *) (base + 0x1000 + REGIONAL_OFFSET(0xae8, 0xc20))   = GetField0x3acValue_020100a8(GameState::GetInstance());
                            *(unsigned char *) (base + 0x1000 + REGIONAL_OFFSET(0xb3c, 0xc78)) = 1;
                        }
                        func_ov002_0216bfd4(base, 0);
                        return;
                    }
                }
                *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa80, 0xbb8)) = regionalState0d;
                *(int *) (base + 0x1000 + REGIONAL_OFFSET(0xa88, 0xbc0)) = 0;
                SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) L(base), regionalState0d);
            }
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(short *) (base + REGIONAL_OFFSET(0x1a00 + 0xb6, 0x1b00 + 0xee))        = -1;
            *(signed char *) (base + 0x1000 + REGIONAL_OFFSET(0xae9, 0xc21)) = -1;
            func_ov002_02156e90(base);
        }
    }
}
