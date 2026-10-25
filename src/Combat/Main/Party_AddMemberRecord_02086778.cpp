#include <globaldefs.h>

extern "C" void* func_02086868(void*, void*);

struct Struct_02086778_2 {
    signed char unknown_0_0_ : 6;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
    char unknown_1_[0x23c - 1];
};

struct Struct_02086778 {
    char unknown_0_[0xf80];
    struct Struct_02086778_2 unknown_f80_[13];
    unsigned char unknown_2c8c_;
};

// Main, originally func_02086778 (USA 0x02086778, EUR 0x02086788, JPN 0x02087098)
extern "C" ARM int Party_AddMemberRecord(void* map, struct Entry02086778* buf, unsigned char c, unsigned char d) {
    struct Container02086778* m = (struct Container02086778*)map;
    signed char best = -1;
    signed char i = 0;
    int start = 0;
    for (i = 0; i < 16; i++) {
        bool found = start;
        unsigned char k = start;
        for (; k < m->count; k++) {
            if (i == m->elems[k].id) {
                found = true;
                break;
            }
        }
        if (!var4) {
            var1 = var2;
            break;
        }
    }
    if (var1 < 0) {
        return 0;
    }
    arg1->unknown_0_0_ = var1;
    arg1->unknown_0_6_ = arg2;
    arg1->unknown_0_7_ = arg3;
    func_02086868(&var0->unknown_f80_[var0->unknown_2c8c_], arg1);
    var0->unknown_2c8c_++;
    return 1;
}