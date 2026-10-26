#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

#if defined(jpn)
enum { Enum_ov003_02169eec_228 = 0xe0, Enum_ov003_02169eec_8 = 12, Enum_ov003_02169eec_0 = 1, kResetOffset = 0x134 };
#else
enum { Enum_ov003_02169eec_228 = 0xe4, Enum_ov003_02169eec_8 = 8, Enum_ov003_02169eec_0 = 0, kResetOffset = 0x138 };
#endif

struct Struct_0205bbcc;
struct GridCursor;
struct Struct_0205bcdc;
struct Struct_0205bd58;
struct Struct_ov003_02169eec_2;
struct Struct_0205d81c;
struct Struct_0205bc2c;
struct Struct_0205bd04;
struct Struct_0205bc10;
struct Struct_0205c570;
struct Struct0200fb08;
struct SePlayer;
struct Struct_0205cf1c;

extern "C" void func_ov003_02169594(void* self);
extern "C" void func_ov003_021696f4(void* self, int v);
extern "C" int func_ov003_02169674(void* self, int x, int y, void* rects);
extern "C" void GridCursor_SetSelectedIndex(void* obj, int v);
extern "C" int GridCursor_Update(void* obj, int v);

extern "C" void func_0205cef8(void* chan);
extern "C" void func_0205cf04(void* chan);
extern "C" void func_0205bbcc(Struct_0205bbcc* obj);
extern "C" void GridCursor_SetDimensions(GridCursor* obj, int a, int b, int c);
extern "C" void GridCursor_SetCount(GridCursor* obj, int v);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc* obj, int v);
extern "C" void func_0205bd58(Struct_0205bd58* obj, int a, int b, int c, int d, int e);
extern "C" void func_ov003_0216a85c(Struct_ov003_02169eec_2* obj);
extern "C" unsigned char* Window_GetActivePane(Struct_0205d81c* chan);
extern "C" void func_0204f138(unsigned char* elem, unsigned char** a, unsigned char** b, unsigned char** c,
                              unsigned char** d);
extern "C" void TouchGrid_SetTouchedCell(void* obj, int v);
extern "C" int func_0205bc2c(Struct_0205bc2c*, int);
extern "C" int func_0205bd04(Struct_0205bd04* obj);
extern "C" int GridCursor_GetCount(void* obj);
extern "C" void func_ov003_02169658(void* self);
extern "C" void func_0205bc10(Struct_0205bc10* obj);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* chan);
extern "C" void func_ov003_021694b8(void* self, int v);
extern "C" void GridCursor_ResetKeyRepeat(GridCursor* obj);
extern "C" int GridCursor_GetSelectedIndex(GridCursor* obj);
extern "C" int GameState_GetLanguage(Struct0200fb08* gs);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_0205cf10(void* chan);
extern "C" void func_0205cf1c(Struct_0205cf1c* chan);

extern unsigned char data_ov003_0217f544[];
extern unsigned char data_ov003_0217f545[];
extern unsigned char data_ov003_0217f546[];
extern unsigned char data_ov003_0217f547[];
extern unsigned char data_ov003_0217f548[];
extern SePlayer g_sePlayer;

struct Struct_ov003_02169674 {
    short originX;
    short originY;
    signed char count;
    char pad5;
    short* unknown_8_;
    short* unknown_c_;
    short* unknown_10_;
    short* unknown_14_;
};

struct Struct_ov003_02169eec {
    char pad0[Enum_ov003_02169eec_228];
    char chan[0x179 - 0xe4];
    unsigned char unknown_179_;
    char unknown_17a_[0x4e9 - 0x17a];
    unsigned char state;
    unsigned char code;
    char unknown_4eb_[3];
    signed char cursor;
    signed char cells[4];
    signed char unknown_4f3_[4];
    char unknown_4f7_;
    unsigned int limit;
    char list[0x53c - 0x4fc];
    char node[4];
    int unknown_540_;
    char unknown_544_[0x574 - 0x544];
    short unknown_574_;
    short unknown_576_;
    char unknown_578_[0x588 - 0x578];
    unsigned char unknown_588_;
    char unknown_589_[3];
    short unknown_58c_[8];
    signed char step;
    unsigned char unknown_59d_;
    signed char unknown_59e_;
    char unknown_59f_;
    unsigned int unknown_5a0_;
    char unknown_5a4_[2];
    unsigned char unknown_5a6_;
    unsigned char unknown_5a7_;
    Struct_ov003_02169674 rectA;
    Struct_ov003_02169674 unknown_5c0_;
};

static inline short inline_ov003_02169eec(Struct_ov003_02169eec* m) {
    return m->unknown_5c0_.originX;
}
static inline short inline_ov003_02169eec_2(Struct_ov003_02169eec* m) {
    return m->unknown_5c0_.originY;
}
static inline short* inline_02000c9c_11(Struct_ov003_02169eec* m) {
    return m->unknown_5c0_.unknown_c_;
}

static inline short inline_ov003_02169eec_3(unsigned char* e) {
    return *(short*)(e + 0xac);
}
static inline short inline_ov003_02169eec_4(unsigned char* e) {
    return *(short*)(e + 0xae);
}

// USA: func_ov003_02169eec
extern "C" ARM int func_ov003_02169eec(Struct_ov003_02169eec* self, unsigned int sb) {
    int ax;
    int ay;
    int px;
    int var3;

    if (self->state == 0) {
        func_ov003_02169594(self);
        func_0205cef8(self->chan);
        func_0205cf04(self->chan);
        func_ov003_021696f4(self, self->cursor);
        func_0205bbcc((Struct_0205bbcc*)self->node);
        GridCursor_SetDimensions((GridCursor*)self->node, 1, 2, 0);
        self->unknown_540_ = 1;
        GridCursor_SetCount((GridCursor*)self->node, 2);
        GridCursor_SelectIfValid((Struct_0205bcdc*)self->node, 0);
        self->unknown_58c_[0] = 0;
        self->unknown_58c_[1] = 0;
        self->unknown_58c_[2] = 0;
        self->unknown_58c_[3] = 0x10;
        self->unknown_58c_[4] = Enum_ov003_02169eec_8;
        self->unknown_58c_[5] = Enum_ov003_02169eec_8;
        self->unknown_58c_[6] = 0x10;
        self->unknown_58c_[7] = 0x10;
        func_0205bd58((Struct_0205bd58*)self->node, 2, (int)&self->unknown_58c_[0], (int)&self->unknown_58c_[2],
                          (int)&self->unknown_58c_[4], (int)&self->unknown_58c_[6]);
        func_ov003_0216a85c((Struct_ov003_02169eec_2*)&self->rectA);
        self->rectA.count = 2;
        self->rectA.unknown_8_ = &self->unknown_58c_[Enum_ov003_02169eec_0];
        self->rectA.unknown_c_ = &self->unknown_58c_[2];
        self->rectA.unknown_10_ = &self->unknown_58c_[4];
        self->rectA.unknown_14_ = &self->unknown_58c_[6];
        func_ov003_0216a85c((Struct_ov003_02169eec_2*)&self->unknown_5c0_);
        unsigned char* elem = Window_GetActivePane((Struct_0205d81c*)self->chan);
        short var5 = inline_ov003_02169eec_3(elem);
        short var6 = inline_ov003_02169eec_4(elem);
        self->unknown_5c0_.originX = var5 << 3;
        self->unknown_5c0_.originY = var6 << 3;
        self->unknown_5c0_.count = 4;
        func_0204f138(elem, (unsigned char**)&self->unknown_5c0_.unknown_8_, (unsigned char**)&self->unknown_5c0_.unknown_c_,
                                 (unsigned char**)&self->unknown_5c0_.unknown_10_, (unsigned char**)&self->unknown_5c0_.unknown_14_);
        self->state++;
    } else if (self->state == 1) {
        signed char cur;
        signed char* cells = self->cells;
        cur = self->cursor;
        if (g_touchInput.pressed_ != 0 || (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) ||
            g_touchInput.released_ != 0) {
            g_touchInput.GetTouchPoint(&ax, &ay);
            int r8 = (Window_GetActivePane((Struct_0205d81c*)self->chan)[0xc5] & 2) != 0;
            unsigned char r7 = 0;
            if (g_touchInput.pressed_ != 0) {
                short var11 = inline_ov003_02169eec(self);
                short by = inline_ov003_02169eec_2(self);
                int idx = self->cursor;
#if defined(jpn)
                short x = (short)(var11 + self->unknown_5c0_.unknown_8_[idx]);
                short y = (short)(by + self->unknown_5c0_.unknown_c_[idx]);
                if (r8 == 0) {
                    x = (short)(x - 1);
                    y = (short)(y - 10);
                }
#else
                short x = (short)(var11 + (idx * 8 + 0x24));
                short y = (short)(by + self->unknown_5c0_.unknown_c_[idx]);
                if (r8 == 0) {
                    y = (short)(y - 10);
                }
#endif
                self->unknown_574_ = x;
                self->unknown_576_ = y;
                self->rectA.originX = x;
                self->rectA.originY = y;
                TouchGrid_SetTouchedCell(self->node, func_ov003_02169674(self, ax, ay, &self->rectA));
                if (func_ov003_02169674(self, ax, ay, &self->rectA) >= 0) {
                    r7 = 1;
                    if (func_0205bc2c((Struct_0205bc2c*)self->node, sb) != 0) {
                        self->unknown_59d_ = r7;
                        self->code = 2;
                        self->unknown_59e_ = 0x14;
                        int dir = func_0205bd04((Struct_0205bd04*)self->node);
                        int n = (signed char)GridCursor_GetCount(self->list);
                        if (dir == 0) {
                            cells[cur]++;
                            signed char var18 = cells[cur];
                            if (var18 == n) {
                                cells[cur] = 0;
                            }
                            self->step = 1;
                            self->unknown_5a6_ = 1;
                            self->unknown_5a7_ = 0;
                        } else if (dir == 1) {
                            cells[cur]--;
                            if (cells[cur] == -1) {
                                cells[cur] = n - 1;
                            }
                            self->step = -1;
                            self->unknown_5a6_ = 0;
                            self->unknown_5a7_ = 1;
                        }
                    }
                }
            } else {
                int active = (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0);
                unsigned char var20 = g_touchInput.isRepeatValid_;
                if (!(active == 0 && g_touchInput.released_ == 0)) {
                    if (self->unknown_59d_ != 0) {
                        r7 = 1;
                        if (var20 != 0 && g_touchInput.currentReading_.isHeld != 0) {
                            if (sb < (unsigned int)self->unknown_59e_) {
                                self->unknown_59e_ -= sb;
                            } else {
                                self->unknown_59e_ = 10;
                                cells[cur] += self->step;
                                signed char n = GridCursor_GetCount(self->list);
                                if (cells[cur] > n - 1) {
                                    cells[cur] = n - 1;
                                }
                                if (cells[cur] < 0) {
                                    cells[cur] = 0;
                                }
                                self->code = 2;
                            }
                        }
                        if (g_touchInput.released_ != 0) {
                            if (self->unknown_588_ != 0) {
                                self->code = 4;
                            } else {
                                self->code = 3;
                            }
                            func_ov003_02169658(self);
                            func_0205bc10((Struct_0205bc10*)self->node);
                        }
                    }
                }
            }
            if (r7 == 0) {
                int before = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                self->unknown_179_ = 0;
                func_ov003_021694b8(self, sb);
                self->unknown_179_ = 1;
                int after = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
            }
            if (r8 != 0 && g_touchInput.released_ != 0) {
                if (func_ov003_02169674(self, ax, ay, &self->unknown_5c0_) < 0) {
                    self->code = 3;
                }
            }
        } else {
            if (g_keyManager.TestKeysHeld(0x40) || g_keyManager.TestKeysPressed(0x40) ||
                g_keyManager.TestKeysReleased(0x40) || g_keyManager.TestKeysHeld(0x80) ||
                g_keyManager.TestKeysPressed(0x80) ||
                g_keyManager.TestKeysReleased(0x80)) {
                GridCursor_ResetKeyRepeat((GridCursor*)((char*)self + kResetOffset));
                int old = cells[cur];
                int n = GridCursor_GetCount(self->list);
                GridCursor_SetSelectedIndex(self->list, n - 1 - cells[cur]);
                if (GridCursor_Update(self->list, sb) != 0) {
                    cells[cur] = n - 1 - GridCursor_GetSelectedIndex((GridCursor*)self->list);
                    if (old != cells[cur]) {
                        self->code = 1;
                    }
                }
            } else {
                int before = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                func_ov003_021694b8(self, sb);
                int after = Window_GetSelectedIndex((Struct_0205c570*)self->chan);
                if (before != after) {
                    func_ov003_021696f4(self, after);
                }
                if (g_keyManager.TestKeysPressed(0x10) && self->cursor == 3) {
                    for (int i = 0; i < 4; i++) {
                        self->cells[i] = 0;
                    }
                    self->code = 1;
                } else if (g_keyManager.TestKeysPressed(0x20) && self->cursor == 0) {
                    for (int i = 0; i < 4; i++) {
                        self->cells[i] = self->unknown_4f3_[i];
                    }
                    self->code = 1;
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
        if (total > self->limit) {
            for (int i = 0; i < 4; i++) {
                self->cells[i] = self->unknown_4f3_[i];
            }
        }

        int var34 = 0;
        int hit2 = 0;
        if (g_touchInput.pressed_ != 0) {
            g_touchInput.GetTouchPoint(&px, &var3);
            if (var3 >= 0x60 && var3 < 0x6b) {
#if defined(jpn)
                short var37 = 0x8f;
                short var38 = 0xbb;
                short var39 = 0xc8;
                short var40 = 0xec;
#else
                int key = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
                short var37 = 0x8f;
                short var38 = 0xba;
                short var39 = 0xc5;
                short var40 = 0xed;
                for (int i = 0; i < 5; i++) {
                    if (key == data_ov003_0217f544[i * 5]) {
                        var37 = data_ov003_0217f545[i * 5] - 1;
                        var38 = data_ov003_0217f546[i * 5] + var37 + 2;
                        var39 = data_ov003_0217f547[i * 5] - 1;
                        var40 = data_ov003_0217f548[i * 5] + var39 + 2;
                        break;
                    }
                }
#endif
                if (px >= var37 && px < var38) {
                    var34 = 1;
                } else if (px >= var39 && px < var40) {
                    hit2 = 1;
                    SePlayer_Play(&g_sePlayer, hit2, 0);
                }
            }
        }
        int a = g_keyManager.TestKeysPressed(1);
        int b = g_keyManager.TestKeysPressed(0x400);
        if ((a | b) != 0) {
            var34 = 1;
        } else if (g_keyManager.TestKeysPressed(2) != 0) {
            hit2 = 1;
        }
        if (var34 != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            unsigned int m = 1000;
            for (int i = 3; i >= 0; i--) {
                self->unknown_5a0_ += m * self->cells[i];
                m *= 10;
            }
            func_0205cf10(self->chan);
            func_0205cf1c((Struct_0205cf1c*)self->chan);
            self->state = 0;
            return self->unknown_5a0_ == 0 ? -2 : 0;
        }
        if (hit2 != 0) {
            func_0205cf10(self->chan);
            func_0205cf1c((Struct_0205cf1c*)self->chan);
            self->state = 0;
            return -2;
        }
    }
    return -1;
}
