#include <globaldefs.h>

struct Struct_ov031_02227570 {
    unsigned int unknown_0_0_ : 4;
    unsigned int rest : 28;
};
extern int data_ov031_02250c0c;

// USA: func_ov031_02227570
extern "C" ARM int func_ov031_02227570(unsigned int mask) {
    struct Struct_ov031_02227570* s = (struct Struct_ov031_02227570*)((char*)&data_ov031_02250c0c + 0x8);
    return (mask & s->rest) != 0;
}
