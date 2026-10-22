#include <globaldefs.h>

struct Struct_0205ba68 {
    int field0;
    int field4;
    int field8;
    int fieldC;
    unsigned char field10;
    int field14;
    int field18;
    int field1C;
    int* field20;
    int* field24;
    int* field28;
    int* field2C;
};

// USA: func_0205ba68
ARM void SetupPointerTable0205ba68(struct Struct_0205ba68* s, int a, int b, int mode) {
    s->field8 = a;
    s->fieldC = b;
    s->field10 = mode;
    if (mode == 0) {
        s->field20 = &s->field8;
        s->field24 = &s->fieldC;
        s->field28 = &s->field18;
        s->field2C = &s->field1C;
    } else if (mode == 1) {
        s->field20 = &s->fieldC;
        s->field24 = &s->field8;
        s->field28 = &s->field1C;
        s->field2C = &s->field18;
    }
}
