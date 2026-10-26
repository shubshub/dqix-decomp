#include <globaldefs.h>

struct Struct_ov000_0216fe74 {
    char pad0[0x40];
    char* arr;
    char pad1[0xa];
    unsigned short count;
};

// USA: func_ov000_0216fe74
extern "C" ARM char* func_ov000_0216fe74(struct Struct_ov000_0216fe74* obj, unsigned int index) {
    char* result = NULL;
    char* arr = obj->arr;
    if (arr != NULL && index < obj->count) {
        result = arr + index * 0x28;
    }
    return result;
}
