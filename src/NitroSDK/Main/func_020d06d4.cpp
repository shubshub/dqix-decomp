#include <globaldefs.h>

struct Struct_020d06d4 {
    int field0;
    int field4;
    char pad8[0x14];
    int field1c;
};

extern Struct_020d06d4* data_021118e0;

// USA: func_020d06d4
extern "C" ARM int func_020d06d4() {
    return data_021118e0->field4;
}
