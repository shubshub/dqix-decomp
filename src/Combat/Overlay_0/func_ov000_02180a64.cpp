#include <globaldefs.h>

extern "C" int func_ov000_021719f8(int* obj);

struct Struct_ov000_02180a64_3 {
    char pad0[0x10];
    signed char values[8];
    signed char unknown_18_;
    char unknown_19_[0x1c - 0x19];
    signed char state;
    char unknown_1d_[0x4c - 0x1d];
    int field4c;
#if defined(jpn)
    char unknown_50_[0x488 - 0x50];
#else
    char unknown1_50_[0x448 - 0x50];
#endif
};

struct Struct_ov000_02180a64 {
    unsigned short bit0 : 1;
    unsigned short unknown_0_1_ : 1;
    unsigned short bit2 : 1;
    unsigned short unknown_0_3_ : 1;
    unsigned short unknown_0_4_ : 1;
    unsigned short unknown_0_5_ : 1;
    unsigned short rest : 10;
};

struct Struct_ov000_02180a64_2 {
    char pad0[0x6c];
    signed char members[4];
    char unknown_70_[0x910 - 0x70];
    int unknown_910_;
    int unknown_914_;
    int unknown_918_;
    int unknown_91c_;
    int unknown_920_;
    int unknown_924_;
    int unknown_928_;
    char unknown_92c_[0x958 - 0x92c];
    Struct_ov000_02180a64_3 entries[4];
#if defined(jpn)
    char unknown_1b78_[0x1faa - 0x1b78];
#else
    char unknown_1a78_[0x1d72 - 0x1a78];
#endif
    Struct_ov000_02180a64 flags;
};

// USA: func_ov000_02180a64
extern "C" ARM void func_ov000_02180a64(Struct_ov000_02180a64_2* self) {
    int count;
    int var1;
    Struct_ov000_02180a64_3* e;
    int i;
    count = 0;
    var1 = 0;
    for (i = 0; i < 4; i++) {
        e = &self->entries[self->members[i]];
        if (e->field4c < 0) continue;
        if (func_ov000_021719f8((int*)e)) continue;
        count++;
        if (e->values[e->unknown_18_] < 100) continue;
        if (e->state == 6) var1++;
    }
    if (count != var1) return;
    self->unknown_920_ = 0x100;
    self->unknown_924_ = 0x100;
    self->unknown_928_ = 0x100;
    self->unknown_910_ = 0;
    self->unknown_914_ = 0;
    self->unknown_918_ = 0;
    self->unknown_91c_ = 0;
    self->flags.unknown_0_3_ = 0;
    self->flags.unknown_0_4_ = 0;
    self->flags.unknown_0_5_ = 1;
}
