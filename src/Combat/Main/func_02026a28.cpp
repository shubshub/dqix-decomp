#include <globaldefs.h>

struct Struct_02026a28_2 {
    unsigned short value;
    unsigned short type;
    unsigned char pad[24];
};

struct Struct_02026a28 {
#if defined(jpn)
    unsigned char pad0[0x6d4];
#else
    unsigned char pad0[0x780];
#endif
    unsigned char count;
    unsigned char pad1[9];
    struct Struct_02026a28_2 elems[1];
};

// USA: func_02026a28
extern "C" ARM int func_02026a28(struct Struct_02026a28* list) {
    unsigned char matches = 0;
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->elems[i].type == 1) {
            if (list->elems[i].value != 5) {
                matches = matches + 1;
            }
        }
    }
    return matches;
}
