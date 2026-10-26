#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f524;

struct Struct_02080cec_2 {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

struct Struct_02080cec { char pad[0x13]; unsigned char flags; };

extern "C" struct Struct_02080cec_2* func_0207f0ac(struct Struct_0207f0ac* list, int id);
extern "C" struct Struct_02080cec* func_0207f6ac(struct Struct_0207f524* list, int id);

// USA: func_02080cec
extern "C" ARM void func_02080cec(void* obj, int id, int value) {
    struct Struct_02080cec_2* sub;
    unsigned char i;
    sub = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        struct Struct_02080cec* e = func_0207f6ac((struct Struct_0207f524*)((char*)obj + 4), sub->keys[i]);
        if (e != NULL) {
            e->flags = (e->flags & ~0xf0) | ((value & 0xf) << 4);
        }
    }
}
