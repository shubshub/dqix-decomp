#include <globaldefs.h>

struct Struct_020d06e8 {
    int field0;
    int field4;
    char pad8[0x14];
    int field1c;
};

extern Struct_020d06e8* data_021118e0;

// USA: func_020d06e8
extern "C" ARM int func_020d06e8() {
    return data_021118e0->field1c;
}
