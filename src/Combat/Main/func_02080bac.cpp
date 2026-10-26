#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f524;

struct Struct_02080bac {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

extern "C" struct Struct_02080bac* func_0207f0ac(struct Struct_0207f0ac* list, int id);
extern "C" void func_0207f7cc(struct Struct_0207f524* list, int id, int mask);

// USA: func_02080bac
extern "C" ARM void func_02080bac(void* obj, int id) {
    struct Struct_02080bac* sub;
    short i;
    sub = func_0207f0ac((struct Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        func_0207f7cc((struct Struct_0207f524*)((char*)obj + 4), sub->keys[i], 1);
    }
}
