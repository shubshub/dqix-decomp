#include <globaldefs.h>

struct Struct_ov031_02227558 {
    unsigned int unknown_0_0_ : 4;
    unsigned int rest : 28;
};

extern int data_ov031_02250c0c;

// USA: func_ov031_02227558
extern "C" ARM unsigned int func_ov031_02227558(void) {
    struct Struct_ov031_02227558* s = (struct Struct_ov031_02227558*)((char*)&data_ov031_02250c0c + 0x8);
    return s->unknown_0_0_;
}
