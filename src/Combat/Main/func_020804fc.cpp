#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f524;

struct Struct_020804fc_2 {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

struct Struct_020804fc {
    char pad[0x2a];
    unsigned char flags;
};

extern "C" struct Struct_020804fc_2* func_0207f0ac(struct Struct_0207f0ac* list, int id);
extern "C" struct Struct_020804fc* func_0207f6ac(struct Struct_0207f524* list, int id);

// USA: func_020804fc
extern "C" ARM void func_020804fc(void* obj, int id) {
    struct Struct_020804fc_2* sub;
    unsigned char i;
    sub = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        struct Struct_020804fc* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 4), sub->keys[i]);
        if (e != NULL) {
            e->flags &= ~4;
        }
    }
}
