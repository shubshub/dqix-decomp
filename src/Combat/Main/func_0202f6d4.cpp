#include <globaldefs.h>

struct Struct_0202f6d4_2 {
    char unk0[0x8];
    int field8;
    int fieldc;
    int field10;
    int field14;
};

struct Struct_0202f6d4 {
    char unk0[0x440];
    struct Struct_0202f6d4_2* unknown_440_;
};

// USA: func_0202f6d4
extern "C" ARM void func_0202f6d4(struct Struct_0202f6d4* obj) {
    if (obj->unknown_440_ == 0) {
        return;
    }
    obj->unknown_440_->field10 = 0x1000;
    obj->unknown_440_->field14 = 0x1000;
    obj->unknown_440_->field8 = 3;
}
