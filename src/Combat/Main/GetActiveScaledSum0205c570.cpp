#include <globaldefs.h>

struct Struct_0205bd04;
int GetScaledSumIfActive0205bd04(struct Struct_0205bd04*);
struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84*);

struct Struct_0205c570 {
    char pad0[0x50];
    unsigned char field50;
    char pad51[0x94 - 0x51];
    unsigned char field94;
    unsigned char field95;
};

// USA: func_0205c570
ARM int GetActiveScaledSum0205c570(struct Struct_0205c570* s) {
    int result = -1;
    if (s->field94 != 0 && s->field50 != 0) {
        result = GetScaledSumIfActive0205bd04((struct Struct_0205bd04*)((char*)s + 0x4));
    }
    if (s->field95 == 0) {
        return result;
    }
    return GridCursor_GetSelectedIndex((struct Struct_0205bb84*)((char*)s + 0x54));
}
