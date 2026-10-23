#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02169eec_228 = 0xe0, Enum_ov003_02169eec_8 = 12, Enum_ov003_02169eec_0 = 1, Enum_ov003_02169eec_312 = 0x134 };
#else
enum { Enum_ov003_02169eec_228 = 0xe4, Enum_ov003_02169eec_8 = 8, Enum_ov003_02169eec_0 = 0, Enum_ov003_02169eec_312 = 0x138 };
#endif

struct Struct_0205bbcc;
struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0205bcdc;
struct Struct_0205bd58;
struct Struct_ov003_02169eec_2;
struct Struct_0205d81c;
struct Struct_0205bc2c;
struct Struct_0205bd04;
struct Struct_0205bc10;
struct Struct_0205c570;
struct Struct_0205bf3c;
struct Struct_0205bb84;
struct Struct0200fb08;
struct SePlayer;
struct Struct0205cf1c;

extern "C" void func_ov003_02169594(void* self);
extern "C" void func_ov003_021696f4(void* self, int v);
extern "C" int func_ov003_02169674(void* self, int x, int y, void* rects);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);
extern "C" int GridCursor_Update(void* obj, int v);

void SetChannelAFlag0205cef8(void* chan);
void SetChannelBFlag0205cf04(void* chan);
void Init0205bbcc(Struct_0205bbcc* obj);
void GridCursor_SetDimensions(Struct_0205ba68* obj, int a, int b, int c);
void GridCursor_SetCount(Node0205bacc* obj, int v);
void SetIndexIfValid0205bcdc(Struct_0205bcdc* obj, int v);
void SetFields0205bd58(Struct_0205bd58* obj, int a, int b, int c, int d, int e);
void ClearFields_0216a85c(S0216a85c* obj);
unsigned char* FindElementForFieldB0_0205d8c4(Struct_0205d81c* chan);
void GetFourSubstructPointers_0204f138(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);
void SetFieldAt0x30_0205bc24(void* obj, int v);
int UpdateActiveState0205bc2c(Struct_0205bc2c*, int);
int GetScaledSumIfActive0205bd04(Struct_0205bd04* obj);
int GridCursor_GetCount(void* obj);
void ClearFlagFields_02169658(void* self);
void ClearBytes0x4cTo0x4e(Struct_0205bc10* obj);
int Window_GetSelectedIndex(Struct_0205c570* chan);
void UpdateEntryAndField4ea_021694b8(void* self, int v);
void ResetState0205bf3c(Struct_0205bf3c* obj);
int GridCursor_GetSelectedIndex(Struct_0205bb84* obj);
int NormalizeField5_0200fb08(Struct0200fb08* gs);
void SePlayer_Play(SePlayer* obj, int a, int b);
void ClearChannelAFlag0205cf10(void* chan);
void ClearFlagByte0205cf1c(Struct0205cf1c* chan);

extern unsigned char data_ov003_0217f544[];
extern unsigned char data_ov003_0217f545[];
extern unsigned char data_ov003_0217f546[];
extern unsigned char data_ov003_0217f547[];
extern unsigned char data_ov003_0217f548[];
extern SePlayer g_sePlayer;

struct Struct_ov003_02169674 {
    short unknown_0_;
    short unknown_2_;
    signed char unknown_4_;
    char unknown_5_;
    short* unknown_8_;
    short* unknown_c_;
    short* unknown_10_;
    short* unknown_14_;
};

struct Struct_ov003_02169eec {
    char unknown_0_[Enum_ov003_02169eec_228];
    char unknown_e4_[0x179 - 0xe4];
    unsigned char unknown_179_;
    char unknown_17a_[0x4e9 - 0x17a];
    unsigned char unknown_4e9_;
    unsigned char unknown_4ea_;
    char unknown_4eb_[3];
    signed char unknown_4ee_;
    signed char unknown_4ef_[4];
    signed char unknown_4f3_[4];
    char unknown_4f7_;
    unsigned int unknown_4f8_;
    char unknown_4fc_[0x53c - 0x4fc];
    char unknown_53c_[4];
    int unknown_540_;
    char unknown_544_[0x574 - 0x544];
    short unknown_574_;
    short unknown_576_;
    char unknown_578_[0x588 - 0x578];
    unsigned char unknown_588_;
    char unknown_589_[3];
    short unknown_58c_[8];
    signed char unknown_59c_;
    unsigned char unknown_59d_;
    signed char unknown_59e_;
    char unknown_59f_;
    unsigned int unknown_5a0_;
    char unknown_5a4_[2];
    unsigned char unknown_5a6_;
    unsigned char unknown_5a7_;
    Struct_ov003_02169674 unknown_5a8_;
    Struct_ov003_02169674 unknown_5c0_;
};

static inline short inline_ov003_02169eec(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_0_;
}
static inline short inline_ov003_02169eec_2(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_2_;
}
static inline short* inline_02000c9c_11(Struct_ov003_02169eec* arg0) {
    return arg0->unknown_5c0_.unknown_c_;
}

static inline short inline_ov003_02169eec_3(unsigned char* arg0) {
    return *(short*)(arg0 + 0xac);
}
static inline short inline_ov003_02169eec_4(unsigned char* arg0) {
    return *(short*)(arg0 + 0xae);
}

// USA: func_ov003_02169eec
extern "C" ARM int func_ov003_02169eec(Struct_ov003_02169eec* arg0, unsigned int arg1) {
    int var0;
    int var1;
    int var2;
    int var3;

    if (self->state == 0) {
        func_ov003_02169594(self);
        SetChannelAFlag0205cef8(self->chan);
        SetChannelBFlag0205cf04(self->chan);
        func_ov003_021696f4(self, self->cursor);
        Init0205bbcc((Struct_0205bbcc*)self->node);
        GridCursor_SetDimensions((Struct_0205ba68*)self->node, 1, 2, 0);
        self->w540 = 1;
        GridCursor_SetCount((Node0205bacc*)self->node, 2);
        SetIndexIfValid0205bcdc((Struct_0205bcdc*)self->node, 0);
        self->h58c[0] = 0;
        self->h58c[1] = 0;
        self->h58c[2] = 0;
        self->h58c[3] = 0x10;
        self->h58c[4] = kCellWidth;
        self->h58c[5] = kCellWidth;
        self->h58c[6] = 0x10;
        self->h58c[7] = 0x10;
        SetFields0205bd58((Struct_0205bd58*)self->node, 2, (int)&self->h58c[0], (int)&self->h58c[2],
                          (int)&self->h58c[4], (int)&self->h58c[6]);
        ClearFields_0216a85c((S0216a85c*)&self->rectA);
        self->rectA.count = 2;
        self->rectA.xMinArr = &self->h58c[kRectXIndex];
        self->rectA.yMinArr = &self->h58c[2];
        self->rectA.xWidthArr = &self->h58c[4];
        self->rectA.yWidthArr = &self->h58c[6];
        ClearFields_0216a85c((S0216a85c*)&self->rectB);
        unsigned char* elem = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)self->chan);
        short ex = ElemX(elem);
        short ey = ElemY(elem);
        self->rectB.originX = ex << 3;
        self->rectB.originY = ey << 3;
        self->rectB.count = 4;
        GetFourSubstructPointers_0204f138(elem, (unsigned char**)&self->rectB.xMinArr, (unsigned char**)&self->rectB.yMinArr,
                                 (unsigned char**)&self->rectB.xWidthArr, (unsigned char**)&self->rectB.yWidthArr);
        self->state++;
    } else if (self->state == 1) {
        signed char cur;
        signed char* cells = self->cells;
        cur = self->cursor;
        if (g_touchInput.pressed_ != 0 || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
            g_touchInput.released_ != 0) {
            g_touchInput.GetTouchPoint(&var0, &var1);
            int var9 = (func_0205d8c4((Struct_0205d81c*)arg0->unknown_e4_)[0xc5] & 2) != 0;
            unsigned char var10 = 0;
            if (g_touchInput.pressed_ != 0) {
                short var11 = inline_ov003_02169eec(arg0);
                short var12 = inline_ov003_02169eec_2(arg0);
                int var13 = arg0->unknown_4ee_;
#if defined(jpn)
                short var14 = (short)(var11 + arg0->unknown_5c0_.unknown_8_[var13]);
                short var15 = (short)(var12 + arg0->unknown_5c0_.unknown_c_[var13]);
                if (var9 == 0) {
                    var14 = (short)(var14 - 1);
                    var15 = (short)(var15 - 10);
                }
#else
                short var14 = (short)(var11 + (var13 * 8 + 0x24));
                short var15 = (short)(var12 + arg0->unknown_5c0_.unknown_c_[var13]);
                if (var9 == 0) {
                    var15 = (short)(var15 - 10);
                }
#endif
                self->h574 = x;
                self->h576 = y;
                self->rectA.originX = x;
                self->rectA.originY = y;
                SetFieldAt0x30_0205bc24(self->node, func_ov003_02169674(self, ax, ay, &self->rectA));
                if (func_ov003_02169674(self, ax, ay, &self->rectA) >= 0) {
                    r7 = 1;
                    if (UpdateActiveState0205bc2c((Struct_0205bc2c*)self->node, sb) != 0) {
                        self->b59d = r7;
                        self->code = 2;
                        self->b59e = 0x14;
                        int dir = GetScaledSumIfActive0205bd04((Struct_0205bd04*)self->node);
                        int n = (signed char)GridCursor_GetCount(self->list);
                        if (dir == 0) {
                            cells[cur]++;
                            signed char cv = cells[cur];
                            if (cv == n) {
                                cells[cur] = 0;
                            }
                            arg0->unknown_59c_ = 1;
                            arg0->unknown_5a6_ = 1;
                            arg0->unknown_5a7_ = 0;
                        } else if (var16 == 1) {
                            var8[var7]--;
                            if (var8[var7] == -1) {
                                var8[var7] = var17 - 1;
                            }
                            arg0->unknown_59c_ = -1;
                            arg0->unknown_5a6_ = 0;
                            arg0->unknown_5a7_ = 1;
                        }
                    }
                }
            } else {
                int var19 = (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0);
                unsigned char var20 = g_touchInput.isRepeatValid_;
                if (!(var19 == 0 && g_touchInput.released_ == 0)) {
                    if (arg0->unknown_59d_ != 0) {
                        var10 = 1;
                        if (var20 != 0 && g_touchInput.currentReading_.isHeld != 0) {
                            if (arg1 < (unsigned int)arg0->unknown_59e_) {
                                arg0->unknown_59e_ -= arg1;
                            } else {
                                self->b59e = 10;
                                cells[cur] += self->step;
                                signed char n = GridCursor_GetCount(self->list);
                                if (cells[cur] > n - 1) {
                                    cells[cur] = n - 1;
                                }
                                if (var8[var7] < 0) {
                                    var8[var7] = 0;
                                }
                                arg0->unknown_4ea_ = 2;
                            }
                        }
                        if (g_touchInput.released_ != 0) {
                            if (arg0->unknown_588_ != 0) {
                                arg0->unknown_4ea_ = 4;
                            } else {
                                arg0->unknown_4ea_ = 3;
                            }
                            func_ov003_02169658(arg0);
                            func_0205bc10((Struct_0205bc10*)arg0->unknown_53c_);
                        }
                    }
                }
            }
            if (r7 == 0) {
                int before = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                self->b179 = 0;
                UpdateEntryAndField4ea_021694b8(self, sb);
                self->b179 = 1;
                int after = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
            }
            if (var9 != 0 && g_touchInput.released_ != 0) {
                if (func_ov003_02169674(arg0, var0, var1, &arg0->unknown_5c0_) < 0) {
                    arg0->unknown_4ea_ = 3;
                }
            }
        } else {
            if (g_keyManager.TestKeysHeld(0x40) || g_keyManager.TestKeysPressed(0x40) ||
                g_keyManager.TestKeysReleased(0x40) || g_keyManager.TestKeysHeld(0x80) ||
                g_keyManager.TestKeysPressed(0x80) ||
                g_keyManager.TestKeysReleased(0x80)) {
                ResetState0205bf3c((Struct_0205bf3c*)((char*)self + kResetOffset));
                int old = cells[cur];
                int n = GridCursor_GetCount(self->list);
                GridCursor_SetSelectedIndex(self->list, n - 1 - cells[cur]);
                if (GridCursor_Update(self->list, sb) != 0) {
                    cells[cur] = n - 1 - GridCursor_GetSelectedIndex((Struct_0205bb84*)self->list);
                    if (old != cells[cur]) {
                        self->code = 1;
                    }
                }
            } else {
                int before = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                UpdateEntryAndField4ea_021694b8(self, sb);
                int after = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
                if (g_keyManager.TestKeysPressed(0x10) && arg0->unknown_4ee_ == 3) {
                    for (int var28 = 0; var28 < 4; var28++) {
                        arg0->unknown_4ef_[var28] = 0;
                    }
                    arg0->unknown_4ea_ = 1;
                } else if (g_keyManager.TestKeysPressed(0x20) && arg0->unknown_4ee_ == 0) {
                    for (int var29 = 0; var29 < 4; var29++) {
                        arg0->unknown_4ef_[var29] = arg0->unknown_4f3_[var29];
                    }
                    arg0->unknown_4ea_ = 1;
                }
            }
        }

        self->cursor = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
        unsigned int total = 0;
        unsigned int mul = 1000;
        for (int i = 3; i >= 0; i--) {
            total += mul * self->cells[i];
            mul *= 10;
        }
        if (var30 > arg0->unknown_4f8_) {
            for (int var33 = 0; var33 < 4; var33++) {
                arg0->unknown_4ef_[var33] = arg0->unknown_4f3_[var33];
            }
        }

        int var34 = 0;
        int var35 = 0;
        if (g_touchInput.pressed_ != 0) {
            g_touchInput.GetTouchPoint(&var2, &var3);
            if (var3 >= 0x60 && var3 < 0x6b) {
#if defined(jpn)
                short var37 = 0x8f;
                short var38 = 0xbb;
                short var39 = 0xc8;
                short var40 = 0xec;
#else
                int var36 = func_0200fb08((Struct_02000c9c_8*)GameState::GetInstance());
                short var37 = 0x8f;
                short var38 = 0xba;
                short var39 = 0xc5;
                short var40 = 0xed;
                for (int var41 = 0; var41 < 5; var41++) {
                    if (var36 == data_ov003_0217f544[var41 * 5]) {
                        var37 = data_ov003_0217f545[var41 * 5] - 1;
                        var38 = data_ov003_0217f546[var41 * 5] + var37 + 2;
                        var39 = data_ov003_0217f547[var41 * 5] - 1;
                        var40 = data_ov003_0217f548[var41 * 5] + var39 + 2;
                        break;
                    }
                }
#endif
                if (px >= lox && px < hix) {
                    hit1 = 1;
                } else if (px >= loy && px < hiy) {
                    hit2 = 1;
                    SePlayer_Play(&g_sePlayer, hit2, 0);
                }
            }
        }
        int var42 = g_keyManager.TestKeysPressed(1);
        int var43 = g_keyManager.TestKeysPressed(0x400);
        if ((var42 | var43) != 0) {
            var34 = 1;
        } else if (g_keyManager.TestKeysPressed(2) != 0) {
            var35 = 1;
        }
        if (hit1 != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            unsigned int m = 1000;
            for (int i = 3; i >= 0; i--) {
                self->w5a0 += m * self->cells[i];
                m *= 10;
            }
            func_0205cf10(arg0->unknown_e4_);
            func_0205cf1c((Struct_0205cf1c*)arg0->unknown_e4_);
            arg0->unknown_4e9_ = 0;
            return arg0->unknown_5a0_ == 0 ? -2 : 0;
        }
        if (var35 != 0) {
            func_0205cf10(arg0->unknown_e4_);
            func_0205cf1c((Struct_0205cf1c*)arg0->unknown_e4_);
            arg0->unknown_4e9_ = 0;
            return -2;
        }
    }
    return -1;
}
