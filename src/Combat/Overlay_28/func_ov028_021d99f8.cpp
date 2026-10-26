#include <globaldefs.h>

struct Struct_ov028_021d9208_3 {
    char pad4[4];
    void* arr;
    unsigned short size;
};

// USA: func_ov028_021d99f8
extern "C" ARM void* func_ov028_021d99f8(struct Struct_ov028_021d9208_3* list, unsigned int idx) {
    void* result = 0;
    if (idx < list->size) {
        result = (char*)list->arr + idx * 0xc;
    }
    return result;
}
