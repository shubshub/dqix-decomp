#include <globaldefs.h>

struct Struct_0209b8d4 {
    unsigned int value : 12;
    unsigned int rest : 20;
    unsigned int pad;
};
struct Struct_0209afd4_6 {
    unsigned short id;
    unsigned short pad2;
    struct Struct_0209b8d4 unknown_4_[6];
    unsigned char pad3[0x18];
};

// USA: func_0209b8d4
extern "C" ARM struct Struct_0209b8d4* func_0209b8d4(struct Struct_0209afd4_6* table, int key, int id, int* out) {
    int i, j;
    for (i = 0; i < 6; i++) {
        if (id == table[i].id) {
            *out = i;
            for (j = 0; j < 6; j++) {
                if (key == (int)table[i].unknown_4_[j].value) {
                    return &table[i].unknown_4_[j];
                }
            }
        }
    }
    return NULL;
}
