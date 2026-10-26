#include <globaldefs.h>

struct Struct_ov031_02240410 {
    Struct_ov031_02240410* next;
};

// USA: func_ov031_02240410
extern "C" ARM void func_ov031_02240410(char* obj, int idx, Struct_ov031_02240410** arg2, int* arg3) {
    if (idx < 0x400) {
        *arg2 = NULL;
        *arg3 = idx;
        return;
    }
    int block = (idx - 0x400) >> 9;
    int count = block - 1;
    Struct_ov031_02240410* node = *(Struct_ov031_02240410**)(obj + 0x1c);
    if (block != 0) {
        do {
            node = node->next;
        } while (count-- != 0);
    }
    *arg2 = node;
    *arg3 = (idx - 0x400) & 0x1ff;
}
