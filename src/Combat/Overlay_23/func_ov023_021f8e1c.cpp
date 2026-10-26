#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Input/Input.h"


struct Struct_ov023_021f8e1c {
    int x;
    int y;
    int z;
};

static inline const Struct_ov023_021f8e1c* inline_ov023_021f8e1c_35(const Struct_ov023_021f8e1c& v) { return &v; }

class Struct_ov023_021f8e1c_3 {
public:
    virtual void v00(); virtual void inline_ov023_021f8e1c_37(); virtual void inline_ov023_021f8e1c_38(); virtual void inline_ov023_021f8e1c_39();
    virtual void v04(); virtual void inline_ov023_021f8e1c_43(); virtual void inline_ov023_021f8e1c_44(); virtual void inline_ov023_021f8e1c_45();
    virtual Struct_ov023_021f8e1c inline_ov023_021f8e1c_46();
    virtual void inline_ov023_021f8e1c_47(); virtual void v10(); virtual void inline_ov023_021f8e1c_49(); virtual void inline_ov023_021f8e1c_50();
    virtual void inline_ov023_021f8e1c_51(); virtual void v14(); virtual void inline_ov023_021f8e1c_53();
    virtual int inline_ov023_021f8e1c_54();
    virtual void inline_ov023_021f8e1c_55();
    virtual int inline_ov023_021f8e1c_56();
    virtual void inline_ov023_021f8e1c_57(); virtual void v20(); virtual void inline_ov023_021f8e1c_59(); virtual void inline_ov023_021f8e1c_60();
    virtual void inline_ov023_021f8e1c_61(); virtual void v24(); virtual void inline_ov023_021f8e1c_63(); virtual void inline_ov023_021f8e1c_64();
    virtual void inline_ov023_021f8e1c_65(); virtual void v28(); virtual void inline_ov023_021f8e1c(); virtual void v30();
    virtual void inline_ov023_021f8e1c_3();
    virtual int inline_ov023_021f8e1c_4();
    virtual void inline_ov023_021f8e1c_5(); virtual void v34(); virtual void inline_ov023_021f8e1c_7(); virtual void inline_ov023_021f8e1c_8();
    virtual void inline_ov023_021f8e1c_9(); virtual void v38(); virtual void inline_ov023_021f8e1c_11(); virtual void v40();
    virtual void inline_ov023_021f8e1c_13(); virtual void inline_ov023_021f8e1c_14(); virtual void inline_ov023_021f8e1c_15(); virtual void v44();
    virtual void inline_ov023_021f8e1c_17(); virtual void inline_ov023_021f8e1c_18(); virtual void inline_ov023_021f8e1c_19(); virtual void v48();
    virtual void inline_ov023_021f8e1c_21(); virtual void v50(); virtual void inline_ov023_021f8e1c_23(); virtual void inline_ov023_021f8e1c_24();
    virtual void inline_ov023_021f8e1c_25(); virtual void v54(); virtual void inline_ov023_021f8e1c_27(); virtual void inline_ov023_021f8e1c_28();
    virtual void inline_ov023_021f8e1c_29(); virtual void v58(); virtual void inline_ov023_021f8e1c_31(); virtual void v60();

#if !defined(jpn)
    virtual void inline_ov023_021f8e1c_33();
#endif
    virtual int inline_ov023_021f8e1c_34();

    char pad4[0x2c];
    short unknown_30_;
    short unknown_32_;
};

struct Struct_ov023_021f8e1c_2 {
    char pad0[6];
    unsigned short id;
    char pad8[4];
    unsigned char flags;
    char unknown_d_[0x13];
    unsigned short* table;
    unsigned short rows;
    unsigned short cols;
    unsigned short row;
    unsigned short col;
    Struct_ov023_021f8e1c offset;
    int dirty;
    unsigned short unknown_3c_;
    unsigned short unknown_3e_;
    unsigned short unknown_40_;
    unsigned short unknown_42_;
    unsigned short unknown_44_;
    unsigned short unknown_46_;
    unsigned short unknown_48_;
    unsigned short unknown_4a_;
    unsigned short unknown_4c_;
    unsigned short unknown_4e_;
    unsigned short unknown_50_;
    unsigned short unknown_52_;
    unsigned short unknown_54_;
    unsigned short unknown_56_;
    unsigned short unknown_58_;
    unsigned short unknown_5a_;
    short page;
    short pageCount;
    unsigned char wrap;
    unsigned char unknown_61_;
    unsigned char unknown_62_;
};

struct Struct_ov011_02184a00;
struct Struct_ov011_02184bd8;
struct Struct_ov011_02184bcc;
struct Struct_ov004_02153978;
struct Struct_02047a5c;
struct Struct_02047a3c;
struct SePlayer;

extern "C" unsigned short func_ov011_02184a00(struct Struct_ov011_02184a00* obj);
extern "C" int GXx_GetMasterBrightness_(volatile unsigned short* p);
extern "C" void* func_ov023_021f7318(void* p);
extern "C" unsigned char func_02047a5c(struct Struct_02047a5c* owner, int index);
extern "C" int func_02047a3c(struct Struct_02047a3c* obj, int index);
extern "C" unsigned short func_ov023_021f8c50(unsigned char* obj);
extern "C" unsigned short func_ov023_021f8c60(unsigned char* obj);
extern "C" unsigned int func_ov023_021f6f08(struct Struct_ov004_02153978* obj);
extern "C" int func_ov011_02184bd8(struct Struct_ov011_02184bd8* obj);
extern "C" void func_ov011_02184bcc(struct Struct_ov011_02184bcc* obj);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void* func_ov023_021f9cb8(void* unused, void* other, void* node);

extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov011_02184a40(void* obj, int val);
extern "C" int func_ov023_021f9bc8(void* obj);
extern "C" Struct_ov023_021f8e1c_3* func_ov023_021f6880(void* base, int key);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f88b8(void* obj, void* other, int id);
extern "C" Struct_ov023_021f8e1c func_ov023_021f8b78(void* src, void* other);
extern "C" void func_ov023_021f98e0(void* obj, void* other);
extern "C" int func_ov023_021f9da8(void* obj, void* other, int x, int y);

extern struct SePlayer g_sePlayer;
extern unsigned int data_ov023_021fff24;
extern const unsigned short data_ov023_021fd922[];

static inline int GetMasterBrightnessMain_021f8e1c() { return GXx_GetMasterBrightness_((volatile unsigned short*)0x400006c); }
static inline int GetMasterBrightnessSub_021f8e1c() { return GXx_GetMasterBrightness_((volatile unsigned short*)0x400106c); }

// USA: func_ov023_021f8e1c
extern "C" ARM void func_ov023_021f8e1c(Struct_ov023_021f8e1c_2* self, void* other) {
    if (self->id != func_ov011_02184a00((struct Struct_ov011_02184a00*)other)) {
        return;
    }
    if (self->flags & 0x10) {
        return;
    }
    func_ov023_021f9bc8(self);

    int row;
    int scroll;
    int cell;
    int locked = 0;
    if (GetMasterBrightnessMain_021f8e1c() != 0 && GetMasterBrightnessSub_021f8e1c() != 0) {
        locked = 1;
    }

    void* nodes = func_ov011_021849c8(other);
    int done = 0;
    row = self->row;
    int col = self->col;

    unsigned short var7[5];
    __clear(var7, sizeof(var7));
    var7[1] = self->unknown_3e_;
    var7[2] = self->unknown_3c_;
    unsigned short var8[5];
    var8[0] = self->unknown_4a_;
    var8[1] = self->unknown_50_;
    var8[2] = self->unknown_52_;
    var8[3] = self->unknown_58_;
    var8[4] = self->unknown_5a_;

    if (!locked) {
        for (int i = 0; i < 5; i++) {
            if (g_keyManager.TestKeysPressed(data_ov023_021fd922[i])) {
                int var10 = 0;
                if (var7[i] != 0) {
                    func_ov011_021848a0(other, var7[i]);
                    var10 = 1;
                }
                if (var8[i] != 0) {
                    func_ov011_02184a40(other, var8[i]);
                    var10 = 1;
                }
                if (var10) {
                    return;
                }
            }
        }
    }

    int cancel = 0;
    if (self->unknown_62_ != 0) {
        if (g_keyManager.TestKeysPressed(0x400)) {
            cancel = 1;
        }
    }
    if (g_keyManager.TestKeysPressed(1) || cancel) {
        done = 1;
    }
    int up = g_keyManager.TestKeysPressed(0x40);
    int down = g_keyManager.TestKeysPressed(0x80);
    int left = g_keyManager.TestKeysPressed(0x20);
    int right = g_keyManager.TestKeysPressed(0x10);

    if (done == 0) {
        unsigned int var16 = GameState::GetInstance()->GetEffectiveDeltaTime();
        if (g_keyManager.TestKeysHeld(0x40)) {
            if (data_ov023_021fff24 < var16) {
                up = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x80)) {
            if (data_ov023_021fff24 < var16) {
                down = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x20)) {
            if (data_ov023_021fff24 < var16) {
                left = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else if (g_keyManager.TestKeysHeld(0x10)) {
            if (data_ov023_021fff24 < var16) {
                right = 1;
            } else {
                data_ov023_021fff24 -= var16;
            }
        } else {
            data_ov023_021fff24 = 500;
        }
    }

    int moved = 0;
    if (up) {
        row--;
        if (self->unknown_4c_ != 0) {
            func_ov011_02184a40(other, self->unknown_4c_);
            return;
        }
    } else if (down) {
        row++;
        if (self->unknown_4e_ != 0) {
            func_ov011_02184a40(other, self->unknown_4e_);
            return;
        }
    } else if (left) {
        col--;
        if (self->unknown_56_ != 0) {
            func_ov011_02184a40(other, self->unknown_56_);
            return;
        }
    } else if (right) {
        col++;
        if (self->unknown_54_ != 0) {
            func_ov011_02184a40(other, self->unknown_54_);
            return;
        }
    }

    scroll = 0;
    if (self->wrap != 0) {
        int top;
        for (top = 0; top < self->rows; top++) {
            if (self->table[top * self->cols + self->col] != 0) {
                break;
            }
        }
        int bottom;
        for (bottom = self->rows - 1; bottom >= 0; bottom--) {
            if (self->table[bottom * self->cols + self->col] != 0) {
                break;
            }
        }
        int var20;
        for (var20 = 0; var20 < self->cols; var20++) {
            if (self->table[self->row * self->cols + var20] != 0) {
                break;
            }
        }
        int var21;
        for (var21 = self->cols - 1; var21 >= 0; var21--) {
            if (self->table[self->row * self->cols + var21] != 0) {
                break;
            }
        }
        if (row < top) {
            row = bottom;
        } else if (bottom < row) {
            row = top;
        } else if (col < var20) {
            col = var20;
            scroll = -1;
            if (self->pageCount == 1) {
                col = var21;
            }
        } else if (var21 < col) {
            col = var21;
            scroll = 1;
            if (self->pageCount == 1) {
                col = var20;
            }
        }
    } else {
        if (row < 0) {
            row = 0;
        } else if (self->rows <= row) {
            row = self->rows - 1;
        } else if (col < 0) {
            col = 0;
            scroll = -1;
        } else if (self->cols <= col) {
            col = self->cols - 1;
            scroll = 1;
        }
    }

    int idx = row * self->cols + col;
    if (self->pageCount == 1) {
        scroll = 0;
    }
    if (self->table[idx] == 0) {
        row = self->row;
        col = self->col;
    }
    if (row != self->row || col != self->col) {
        moved = 1;
        Struct_ov023_021f8e1c_3* node = func_ov023_021f6880(nodes, self->table[func_ov023_021f9bc8(self)]);
        void* linked = func_ov023_021f9cb8(self, other, node);
        if (linked != 0) {
            func_ov023_021f88b8(linked, other, 0x8000);
        }
    }

    if (moved == 0 && g_touchInput.pressed_ != 0) {
        int touchX;
        int touchY;
        g_touchInput.GetTouchPoint(&touchX, &touchY);
        scroll = func_ov023_021f9da8(self, other, touchX, touchY);
        if (scroll == 0) {
            int x;
            int y;
            int w;
            int h;
            int total = self->cols * self->rows;
            for (cell = 0; cell < total; cell++) {
                x = y = w = h = 0;
                if (self->table[cell] == 0) {
                    continue;
                }
                Struct_ov023_021f8e1c_3* node = func_ov023_021f6880(nodes, self->table[cell]);
                if (node == 0) {
                    continue;
                }
                Struct_ov023_021f8e1c pos = node->inline_ov023_021f8e1c_46();
                if (func_ov023_021f6f10(node) == 0) {
                    x = (int)(pos.x / 4096.0f);
                    y = (int)(pos.y / 4096.0f);
                    void* elem = func_ov023_021f7318(node);
                    w = func_02047a5c((struct Struct_02047a5c*)elem, 0);
                    h = func_02047a3c((struct Struct_02047a3c*)elem, 0);
                } else if (func_ov023_021f6f10(node) == 8) {
                    const Struct_ov023_021f8e1c* v = inline_ov023_021f8e1c_35(func_ov023_021f8b78(node, other));
                    pos.x = v->x;
                    pos.y = v->y;
                    pos.z = v->z;
                    x = (int)(pos.x / 4096.0f) + node->unknown_30_;
                    y = (int)(pos.y / 4096.0f) + node->unknown_32_;
                    w = func_ov023_021f8c50((unsigned char*)node);
                    h = func_ov023_021f8c60((unsigned char*)node);
                }
                if (x < touchX && touchX <= x + w && y < touchY && touchY <= y + h) {
                    col = cell % self->cols;
                    row = cell / self->cols;
                    node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
                    if (node != 0 && func_ov023_021f6f10(node) == 8 && node->inline_ov023_021f8e1c_34() == 0) {
                        void* linked = func_ov023_021f9cb8(self, other, node);
                        if (linked != 0) {
                            func_ov023_021f88b8(linked, other, (unsigned short)func_ov023_021f6f08((struct Struct_ov004_02153978*)node));
                        }
                    } else if (row == self->row && col == self->col) {
                        done = 1;
                    }
                    break;
                }
            }
        }
    }

    if (row != self->row || col != self->col) {
        self->row = row;
        self->col = col;
        self->dirty = 1;
    }
    if (func_ov011_02184bd8((struct Struct_ov011_02184bd8*)other)) {
        self->dirty = 1;
        func_ov011_02184bcc((struct Struct_ov011_02184bcc*)other);
    }
    if (self->dirty) {
        func_ov023_021f98e0(self, other);
    }

    if (scroll != 0) {
        self->page += scroll;
        if (self->pageCount <= self->page) {
            self->page = 0;
        } else if (self->page < 0) {
            self->page = self->pageCount - 1;
        }
        if (self->unknown_48_ != 0) {
            func_ov011_02184a40(other, self->unknown_48_);
        }
        return;
    }

    if (up || down || left || right) {
        return;
    }

    if (done != 0) {
        if (locked) {
            return;
        }
        col = self->col;
        row = self->row;
        Struct_ov023_021f8e1c_3* node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
        int var38 = 0;
        if (node != 0) {
            int se = node->inline_ov023_021f8e1c_54();
            if (se > 0) {
                func_ov011_021848a0(other, se);
                var38 = 1;
            }
            se = node->inline_ov023_021f8e1c_56();
            if (se > 0) {
                func_ov011_02184a40(other, se);
                var38 = 1;
            }
        }
        if (self->unknown_42_ != 0) {
            func_ov011_021848a0(other, self->unknown_42_);
        }
        if (self->unknown_40_ != 0) {
            func_ov011_02184a40(other, self->unknown_40_);
        }
        if (var38 && self->unknown_61_ != 0) {
            SePlayer_Play(&g_sePlayer, 1, 0);
        }
    }

    if (g_keyManager.TestKeysPressed(2)) {
        if (locked) {
            return;
        }
        if (self->unknown_44_ != 0) {
            func_ov011_021848a0(other, self->unknown_44_);
        }
        if (self->unknown_46_ != 0) {
            func_ov011_02184a40(other, self->unknown_46_);
        }
    }

    if (g_keyManager.TestKeysPressed(0x400)) {
        if (self->unknown_62_ == 0 && !locked) {
            col = self->col;
            row = self->row;
            Struct_ov023_021f8e1c_3* node = func_ov023_021f6880(nodes, self->table[row * self->cols + col]);
            int var41 = 0;
            if (node != 0) {
                int se = node->inline_ov023_021f8e1c_4();
                if (se > 0) {
                    func_ov011_02184a40(other, se);
                    var41 = 1;
                }
            }
            if (var41 && self->unknown_61_ != 0) {
                SePlayer_Play(&g_sePlayer, 1, 0);
            }
        }
    }
}
