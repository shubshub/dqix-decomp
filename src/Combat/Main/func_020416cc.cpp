#include <globaldefs.h>

struct Struct_020416cc {
    int value;
};

struct Struct_020416cc_2 {
    char unk[0x18];
    struct Struct_020416cc* unknown_18_;
};

// USA: func_020416cc
extern "C" ARM int func_020416cc(struct Struct_020416cc_2* holder) {
    struct Struct_020416cc* var0 = holder->unknown_18_;
    return var0 != 0 ? var0->value : 0;
}
