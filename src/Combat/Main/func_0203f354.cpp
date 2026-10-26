#include <globaldefs.h>

struct Struct_0203f354 {
    char data[0x14];
};

struct Struct_0203f2b0_2 {
    char unk[6];
    unsigned short count;
    struct Struct_0203f354* elements;
};

// USA: func_0203f354
extern "C" ARM struct Struct_0203f354* func_0203f354(struct Struct_0203f2b0_2* list, unsigned int index) {
    if (list->count <= index) {
        return 0;
    }
    return &list->elements[index];
}
