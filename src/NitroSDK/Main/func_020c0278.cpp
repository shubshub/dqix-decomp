#include <globaldefs.h>

struct Struct_020bc2f0 {
    char unk0[8];
    int field8;
    int fieldC;
};

// USA: func_020c0278
extern "C" ARM int func_020c0278(struct Struct_020bc2f0* state) {
    return state->field8 >= state->fieldC;
}
