#include <globaldefs.h>

struct Struct_0203f008_2 {
    char unk[0x38];
    int flag;
};

struct Struct_02040468 {
    unsigned int count;
    int unk4;
    struct Struct_0203f008_2* elements;
};

// USA: func_02040468
extern "C" ARM struct Struct_0203f008_2* func_02040468(struct Struct_02040468* list, int index) {
    struct Struct_0203f008_2* elements = list->elements;
    struct Struct_0203f008_2* element;
    if (elements == 0) {
        return 0;
    }
    if (index < 0 || list->count <= (unsigned int)index) {
        return 0;
    }
    element = &elements[index];
    if (element->flag < 0) {
        element = 0;
    }
    return element;
}
