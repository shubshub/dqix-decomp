#include "GameState/GameState.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205def8;
struct Obj_0205da38;
struct SePlayer;
struct Obj02061bd8;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int a, int b);
void FilterSlotsWithFlag0x800020dc4d0(signed char *out, signed char *outCount);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *gameState, int combatantId);
int CheckField0x56bLowNibble(struct Obj02061bd8 *obj);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int *p, unsigned int bits);
int CheckFlagOrThreshold_02161b48(char *base, int a);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215e1d0(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" void func_020d79e0(char *base, int id);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" char g_sePlayer[];
extern "C" unsigned short data_ov002_0216cca4[];
extern "C" unsigned short data_ov002_0216cc86[];

#if defined(jpn)
#define OFF_STATE_02164d14 0x1a88
#define OFF_NEXT_02164d14 0x1a80
#define OFF_LIST_02164d14 0xe20
#define OFF_SEL_02164d14 0x1abe
#define OFF_FLAGS_02164d14 0x22ac
#define K_0E_02164d14 0xf
#define K_0F_02164d14 0x10
#define K_29_02164d14 0x2c
#define K_2B_02164d14 0x2e
#else
#define OFF_STATE_02164d14 (0x1000 + 0xbc0)
#define OFF_NEXT_02164d14 (0x1000 + 0xbb8)
#define OFF_LIST_02164d14 (0x2c8 + 0xc00)
#define OFF_SEL_02164d14 (0x1b00 + 0xf6)
#define OFF_FLAGS_02164d14 (0x2000 + 0x47c)
#define K_0E_02164d14 0xe
#define K_0F_02164d14 0xf
#define K_29_02164d14 0x29
#define K_2B_02164d14 0x2b
#endif

struct Struct_ov002_02164d14 {
    char unknown_0_[0x60];
    int unknown_60_;
};
// USA: func_ov002_02164d14
extern "C" ARM void func_ov002_02164d14(char *arg0) {
    int var0 = *(int *) (arg0 + OFF_STATE_02164d14);
    if (var0 == 0) {
        func_ov002_0215b814(arg0);
        func_0205de24((struct Struct_0205de24_2 *) (arg0 + OFF_LIST_02164d14), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215e1d0(arg0);
        *(int *) (arg0 + OFF_STATE_02164d14) += 1;
    } else if (var0 == 1) {
        GameState *var1 = GameState::GetInstance();
        if (*(short *) (arg0 + OFF_SEL_02164d14) != 0) {
            func_0205def8((struct Struct_0205def8 *) (arg0 + OFF_LIST_02164d14), 1, 1);
            func_0205def8((struct Struct_0205def8 *) (arg0 + OFF_LIST_02164d14), 1, K_0E_02164d14);
            func_0205def8((struct Struct_0205def8 *) (arg0 + OFF_LIST_02164d14), 1,
                                                                    K_29_02164d14);
        }
        *(unsigned int *) (arg0 + OFF_FLAGS_02164d14) |= 4;
        short var2 = *(short *) (arg0 + OFF_SEL_02164d14);
        *(short *) (arg0 + OFF_SEL_02164d14) =
            func_0205d794((struct Struct_0205c570 *) (arg0 + OFF_LIST_02164d14));
        signed char var3[7];
        signed char var4;
        Struct_ov002_02164d14 *var5 = (Struct_ov002_02164d14 *) (arg0 + OFF_LIST_02164d14) + 1;
        int var6         = 0;
        func_020dc4d0(var3, &var4);
        int var7 = var6;
        for (int var8 = 0; var8 < var4; var8++) {
            GameObject *var9 = func_0200ff1c(var1, var3[var8]);
            if (var9 != NULL && func_02061bd8((struct Struct_0205faf4_11 *) var9)) var7++;
        }
        var4 -= var7;
        if (var4 + 1 != (var5 - 1)->unknown_60_) var6 = 1;
        if ((var5 - 1)->unknown_60_ <= *(short *) (arg0 + OFF_SEL_02164d14)) var6 = 1;
        if (var6) {
            *(unsigned int *) (arg0 + OFF_FLAGS_02164d14) &= ~4;
            *(short *) (arg0 + OFF_SEL_02164d14) = -1;
            func_ov002_02156e90(arg0);
            *(int *) (arg0 + OFF_NEXT_02164d14) = K_0E_02164d14;
            *(int *) (arg0 + OFF_STATE_02164d14) = 0;
            return;
        }
        if (old != *(short *) (base + OFF_SEL_02164d14)) return;
        int a = g_keyManager.TestKeysPressed(0x601);
        int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + OFF_LIST_02164d14), 0x14);
        if ((a | b) ? 1 : 0) {
            if (*(unsigned int *) (base + OFF_FLAGS_02164d14) & 2) return;
            if (*(short *) (base + OFF_SEL_02164d14) == count) {
                *(unsigned int *) (base + OFF_FLAGS_02164d14) &= ~4;
                SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
                *(int *) (base + OFF_NEXT_02164d14) = K_0F_02164d14;
                *(int *) (base + OFF_STATE_02164d14) = 0;
                for (int i = 0; i < 4; i++) {
                    unsigned short off = data_ov002_0216cca4[i] * 0x20;
                    CleanInvalidateCacheRange(data_ov002_0216cc86, 2);
                    LoadToMainBGStandardPalette(data_ov002_0216cc86, (unsigned short) (var13 + 2), 2);
                    CleanCacheRange(data_ov002_0216cc86, 2);
                }
                return;
            }
            if (var3[*(short *) (arg0 + OFF_SEL_02164d14)] < 0) return;
            func_020466e4((unsigned int *) func_020d6c00(), 1);
            if (func_02061bd8(
                    (struct Struct_0205faf4_11 *) func_0200ff1c(var1, var3[*(short *) (arg0 + OFF_SEL_02164d14)])))
            {
                for (int var14 = 0; var14 < 4; var14++) {
                    short *var15 = (short *) (arg0 + OFF_SEL_02164d14);
                    (*var15)++;
                    *var15          = *var15 % 4;
                    GameObject *var16 = func_0200ff1c(var1, var3[*(short *) (arg0 + OFF_SEL_02164d14)]);
                    if (var16 != NULL && !func_02061bd8((struct Struct_0205faf4_11 *) var16)) break;
                }
            }
            func_020d79e0(arg0, var3[*(short *) (arg0 + OFF_SEL_02164d14)]);
            *(int *) (arg0 + OFF_NEXT_02164d14) = K_2B_02164d14;
            *(int *) (arg0 + OFF_STATE_02164d14) = 0;
            func_02012fe4();
            func_02017c58();
        } else if (func_ov002_02161b48(arg0, 1)) {
            *(short *) (arg0 + OFF_SEL_02164d14) = -1;
            func_ov002_02156e90(arg0);
        }
    }
}
