#include <globaldefs.h>

struct Struct_0207f0ac_2 {
    short* entries;
    char unknown_4_[4];
    short id;
    short tileX;
    short tileY;
    char unknown_e_[5];
    unsigned char count;
    char unknown_14_[4];
};
struct Struct_0207f6ac;
struct Struct_0207f0ac { Struct_0207f0ac_2* entries; short count; };
struct Struct_0207f524 { Struct_0207f6ac* entries; short count; };
struct Struct_0208065c {
    void* table;
    Struct_0207f524 items;
    Struct_0207f0ac groups;
};

extern "C" Struct_0207f0ac_2* func_0207f0ac(Struct_0207f0ac* list, int id);
extern "C" void func_0207f7cc(struct Struct_0207f524* list, int id, int mask);

// USA: func_0208065c
extern "C" ARM void func_0208065c(void* obj, int id) {
    Struct_0208065c* menu = (Struct_0208065c*)obj;
    Struct_0207f0ac_2* group = func_0207f0ac(&menu->groups, id);
    if (group == NULL) return;
    for (unsigned char i = 0; i < group->count; i++) {
        func_0207f7cc(&menu->items, group->entries[i], 2);
    }
}
