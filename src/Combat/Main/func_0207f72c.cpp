#include <globaldefs.h>

struct Struct_0207f524 {
    void* entries;
    short count;
};

struct Struct_0207f72c;

union Struct_0207f72c_2 {
    short id;
    struct Struct_0207f72c* ptr;
};

struct Struct_0207f72c {
    char pad[0x18];
    union Struct_0207f72c_2 unknown_18_[4];
};

extern "C" void* func_0207f700(unsigned char* obj, short index);
extern "C" struct Struct_0207f72c* func_0207f6ac(struct Struct_0207f524* list, int id);

// USA: func_0207f72c
extern "C" ARM void func_0207f72c(struct Struct_0207f524* list) {
    short count = list->count;
    short i;
    for (i = 0; i < count; i++) {
        struct Struct_0207f72c* e = (struct Struct_0207f72c*)func_0207f700((unsigned char*)list, i);
        if (e != NULL) {
            e->unknown_18_[0].ptr = func_0207f6ac(list, e->unknown_18_[0].id);
            e->unknown_18_[1].ptr = func_0207f6ac(list, e->unknown_18_[1].id);
            e->unknown_18_[2].ptr = func_0207f6ac(list, e->unknown_18_[2].id);
            e->unknown_18_[3].ptr = func_0207f6ac(list, e->unknown_18_[3].id);
        }
    }
}
