#include <globaldefs.h>

extern "C" void* __clear(void* dst, int count);

struct Struct_ov025_021ead5c_2 {
    char pad0[0xe];
    short hp;
    char pad10[0x20 - 0x10];
    struct Struct_ov025_021ead5c_2* next;
};

struct Struct_ov000_021600f8 {
    struct Struct_ov025_021ead5c_2* members;
    char pad4[0x20 - 0x4];
    struct Struct_ov000_021600f8* next;
};

struct Struct_ov000_0215440c {
    char pad0[0x1e];
    unsigned short unknown_1e_;
    unsigned short field20;
};

struct Struct_ov025_021ead5c {
    char pad0[0x5ca];
    unsigned char triggered;
    unsigned char unknown_5cb_;
    char unknown_5cc_[0x5d2 - 0x5cc];
    short unknown_5d2_[9];
    int unknown_5e4_;
    char queue[1];
};

extern "C" void* func_ov000_02160130(void);
extern "C" Struct_ov000_0215440c* func_ov000_02160f20(void* work);
extern "C" Struct_ov000_021600f8* func_ov000_021600f8(Struct_ov000_0215440c* list, int index);
extern "C" int func_ov000_0215fd90(Struct_ov025_021ead5c_2* member, int flag);
extern "C" short func_ov000_0215ffa0(Struct_ov000_021600f8* node);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short arg5, unsigned short arg6);

static inline int inline_ov017_021c530c(int id) {
    return (id >= 0xc0 && id <= 0xc7) ? 1 : 0;
}

static inline int inline_ov025_021ead5c(int id) {
    return (id >= 0 && id <= 3) ? 1 : 0;
}

// USA: func_ov025_021ead5c
extern "C" ARM void func_ov025_021ead5c(Struct_ov025_021ead5c* self, int all) {
    if (all == 0) {
        if (self->triggered != 0) {
            return;
        }
        self->triggered = 1;
    }
    if (all != 0) {
        if (self->unknown_5cb_ != 0) {
            return;
        }
        self->unknown_5cb_ = 1;
    }
    Struct_ov000_0215440c* slot = func_ov000_02160f20(func_ov000_02160130());
    unsigned char seen[4];
    int var2[4];
    __clear(seen, sizeof(seen));
    int var3 = 0;
    __clear(var2, sizeof(var2));
    int var4 = 0;
    if (slot->unknown_1e_ != 0 || slot->field20 != 0) {
        for (Struct_ov000_021600f8* node = func_ov000_021600f8(slot, 0); node != NULL; node = node->next) {
            for (Struct_ov025_021ead5c_2* m = node->members; m != NULL; m = m->next) {
                if (func_ov000_0215fd90(m, 0xd) != 0) {
                    continue;
                }
                if (m->hp > 0) {
                    continue;
                }
                int id = func_ov000_0215ffa0(node);
                if (inline_ov017_021c530c(id)) {
                    if (var3 == 0) {
                        var3 = id;
                    }
                } else if (inline_ov025_021ead5c(id)) {
                    if (seen[id] == 0) {
                        var2[var4] = id;
                        seen[id] = 1;
                        var4++;
                    }
                }
                break;
            }
        }
    }
    if (all != 0) {
        for (int i = 0; i < self->unknown_5e4_; i++) {
            func_ov025_021ed380(self->queue, 8, self->unknown_5d2_[i], 0, 0, -1, 0);
        }
        self->unknown_5e4_ = 0;
    } else if (var3 != 0) {
        func_ov025_021ed380(self->queue, slot->field20, (short)var3, 0, 0, -1, 0);
    }
}
