#include <globaldefs.h>

struct Struct_0207fdcc {
    char unk[0xc4];
    unsigned char key;
    char unk2[0x1b];
};

struct Struct_0207fdcc_2 {
#if defined(jpn)
    char unk[0x24];
#else
    char unk[0x30];
#endif
    struct Struct_0207fdcc* elems;
    char unk2[5];
    unsigned char count;
};

// USA: func_02081da8
extern "C" ARM struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key) {
    unsigned char count = obj->count;
    struct Struct_0207fdcc* p = obj->elems;
    unsigned char i;
    for (i = 0; i < count; i++) {
        if (key == p->key) {
            return p;
        }
        p++;
    }
    return NULL;
}
