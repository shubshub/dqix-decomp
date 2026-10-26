#include <globaldefs.h>

struct Struct_ov023_021dcb70 {
    char pad[0x8];
    unsigned int field8 : 4;
};

extern unsigned char data_ov023_021fd563[2];

// USA: func_ov023_021dcb70
extern "C" ARM unsigned char func_ov023_021dcb70(struct Struct_ov023_021dcb70* p) {
    unsigned int field;
    if (p == NULL) return 0;
    field = p->field8;
    return data_ov023_021fd563[field <= 7 ? 1 : 0];
}
