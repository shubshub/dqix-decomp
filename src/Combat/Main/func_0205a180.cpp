#include <globaldefs.h>

struct Struct_0205a180_2 {
    int field0;
    int field4;
    int field8;
};

struct Struct_0205a180 {
    char unk0[4];
    struct Struct_0205a180_2* out;
    char unknown_8_[0xb6 - 8];
    short unknown_b6_;
};

// USA: func_0205a180
extern "C" ARM void func_0205a180(struct Struct_0205a180* state) {
    struct Struct_0205a180_2* out = state->out;
    if (out != NULL) {
        int value = state->unknown_b6_;
        out->field4 = 0;
        out->field8 = value;
    }
}
