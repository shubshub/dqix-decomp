#include <globaldefs.h>

struct Struct_02073ec4_3 {
    unsigned short key;
    unsigned char pad[0x1e];
};

struct Struct_02073ec4_2 {
    struct Struct_02073ec4_3 entries[6];
    int count;
};

// USA: func_0209bd94
extern "C" ARM struct Struct_02073ec4_3* func_0209bd94(struct Struct_02073ec4_2* table, int key) {
    int i;
    for (i = 0; i < table->count; i++) {
        if (key == table->entries[i].key) {
            return &table->entries[i];
        }
    }
    return NULL;
}
