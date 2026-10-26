#include <globaldefs.h>

struct Struct_0209a594_2 {
    #if defined(jpn)
    unsigned short id : 12;
    unsigned short unknown_1_4_ : 4;
#else
    unsigned short id : 11;
    unsigned short unknown_1_3_ : 5;
#endif
    char rest[10];
};

struct Struct_0209a594 {
    struct Struct_0209a594_2* entries;
    int count;
};

// USA: func_0209a594
extern "C" ARM struct Struct_0209a594_2* func_0209a594(struct Struct_0209a594* self, int id) {
    int i;
    struct Struct_0209a594_2* table = self->entries;
    if (table == 0) return 0;
    if (id >= 0x11f) return 0;
    if (table[id].id == id) {
        return &table[id];
    }
    for (i = 0; i < self->count; i++) {
        if (table[i].id == id) {
            return &table[i];
        }
    }
    return 0;
}
