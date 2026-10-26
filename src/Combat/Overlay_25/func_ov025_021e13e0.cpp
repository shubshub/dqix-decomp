#include <globaldefs.h>

struct Struct_ov025_021e13e0_3 {
    char pad[0x10];
    unsigned int flags;
};

struct Struct_ov025_021e13e0 {
    unsigned short flags;
    char pad[0x146];
    Struct_ov025_021e13e0_3* unknown_148_;
};

struct Struct_ov025_021e13e0_2 {
    unsigned char id;
    unsigned char val;
    char pad[6];
    Struct_ov025_021e13e0* obj;
};

extern "C" unsigned int func_020493a4(unsigned char*);
extern "C" unsigned int func_020493ec(unsigned char*);
extern "C" void func_ov025_021e12f8(unsigned char* seen, int pos, int val, unsigned char kind, int a, int b);

static inline void inline_ov025_021e13e0(unsigned char* seen, unsigned int pos, unsigned char val) {
    if (pos < 0x51) {
        seen[pos] = val;
    }
}

// USA: func_ov025_021e13e0
extern "C" ARM void func_ov025_021e13e0(unsigned char* seen, Struct_ov025_021e13e0_2* ent) {
    if (ent == 0 || ent->obj == 0) {
        return;
    }
    unsigned int pos = func_020493a4((unsigned char*)ent->obj);
    if (pos < 0x51) {
        inline_ov025_021e13e0(seen, pos, ent->val);
    }
    pos = func_020493ec((unsigned char*)ent->obj);
    if (pos < 0x51) {
        inline_ov025_021e13e0(seen, pos, ent->val);
    }
    Struct_ov025_021e13e0* obj = ent->obj;
    if (!(obj->flags & 0x400) || obj->unknown_148_ == 0) {
        return;
    }
    unsigned int kind = (obj->unknown_148_->flags << 1) >> 30;
    if (kind == 0) {
        return;
    }
    func_ov025_021e12f8(seen, pos, ent->val, kind, 0, 0);
}
