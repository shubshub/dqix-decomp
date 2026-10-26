#include <globaldefs.h>

struct Struct_02083e28_6 {
    char pad[0x1c];
    unsigned short f1c;
    unsigned short unknown_1e_;
    char pad2[0x6c - 0x20];
    unsigned short f6c;
    unsigned short unknown_6e_;
};

// USA: func_020863e0
extern "C" ARM void func_020863e0(struct Struct_02083e28_6* s) {
    if (s->f6c < s->f1c) s->f1c = s->f6c;
    if (s->unknown_6e_ < s->unknown_1e_) s->unknown_1e_ = s->unknown_6e_;
}
