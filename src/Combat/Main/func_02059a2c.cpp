#include <globaldefs.h>

struct Struct_02059720 {
    char unk0[4];
    unsigned int field4;
    unsigned int field8;
    unsigned char flagC;
};

// USA: func_02059a2c
extern "C" ARM int func_02059a2c(struct Struct_02059720* state) {
    if (state->flagC != 0) return 0;
    return state->field8 <= state->field4;
}
