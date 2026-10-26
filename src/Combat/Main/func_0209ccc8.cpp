#include <globaldefs.h>

struct Struct_0209cb94_2 {
    int value;
};

struct Struct_0209cb94 {
    struct Struct_0209cb94_2* buffer;
    unsigned char count;
    unsigned char capacity;
};

// USA: func_0209ccc8
extern "C" ARM void func_0209ccc8(struct Struct_0209cb94* list, struct Struct_0209cb94_2* value) {
    unsigned char count = list->count;
    if (count < (unsigned int)list->capacity) {
        list->count = count + 1;
        list->buffer[count] = *value;
    }
}
