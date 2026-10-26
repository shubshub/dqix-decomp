#include <globaldefs.h>

struct Struct_ov023_021f8b78_2 { int x; int y; int z; };

class Struct_ov023_021f8b78_3 {
public:
    virtual void v00(); virtual void inline_ov023_021f8b78_2(); virtual void inline_ov023_021f8b78_3(); virtual void inline_ov023_021f8b78_4();
    virtual void v04(); virtual void inline_ov023_021f8b78_6(); virtual void inline_ov023_021f8b78_7(); virtual void inline_ov023_021f8b78_8();
    virtual Struct_ov023_021f8b78_2 inline_ov023_021f8b78_9();
};

struct Struct_ov023_021f8b78 {
    char pad0[0x34];
    unsigned short f34;
    char unknown_36_[0x3a - 0x36];
    unsigned short unknown_3a_;
    unsigned short f3c;
};

extern "C" void __clear(void* buf, int n);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" Struct_ov023_021f8b78_3* func_ov023_021f6880(void* base, int key);

// USA: func_ov023_021f8b78
extern "C" ARM Struct_ov023_021f8b78_2 func_ov023_021f8b78(struct Struct_ov023_021f8b78* src, void* arg1) {
    Struct_ov023_021f8b78_2 local;
    __clear(&local, 0xc);
    local.x = src->unknown_3a_ << 12;
    local.y = src->f3c << 12;

    void* base = func_ov011_021849c8(arg1);
    Struct_ov023_021f8b78_3* node = func_ov023_021f6880(base, src->f34);
    if (node != NULL) {
        Struct_ov023_021f8b78_2 v = node->inline_ov023_021f8b78_9();
        local.x = local.x + v.x;
        local.y = local.y + v.y;
    }
    return local;
}
