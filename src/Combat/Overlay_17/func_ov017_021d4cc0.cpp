#include <globaldefs.h>

struct Struct_ov017_021d4cc0 {
    unsigned int unk0;
    unsigned int field4;
    unsigned int field8;
};

// USA: func_ov017_021d4cc0
extern "C" ARM void func_ov017_021d4cc0(Struct_ov017_021d4cc0* obj, unsigned int a, unsigned int b) {
    obj->field8 = a;
    obj->field4 = b;
}
