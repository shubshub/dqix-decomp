#include <globaldefs.h>

struct Struct_020daa20 {
    char unk[8];
    int field8;
};

// USA: func_020daa20
extern "C" ARM struct Struct_020daa20* func_020daa20(unsigned char* obj) {
    struct Struct_020daa20* e = (struct Struct_020daa20*)(obj + 0x14);
    unsigned char i = 0;
    while (i < 4) {
        if (e->field8 == -1) {
            return e;
        }
        i++;
        e++;
    }
    return NULL;
}
