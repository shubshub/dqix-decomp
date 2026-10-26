#include <globaldefs.h>

struct Struct_ov031_02240410 { Struct_ov031_02240410* next; };
extern "C" void func_ov031_02240410(char* obj, int idx, Struct_ov031_02240410** arg2, int* arg3);
extern "C" signed char func_ov031_0224046c(void* obj, void** arg1, int* counter);

// USA: func_ov031_022405b8
extern "C" ARM int func_ov031_022405b8(char* obj, int start, int end) {
    if (start >= end) {
        goto fail;
    }
    {
        Struct_ov031_02240410* node;
        int var1;
        func_ov031_02240410(obj, start, &node, &var1);
        if (start >= end) {
            goto fail;
        }
        int i = start;
        do {
            signed char c = func_ov031_0224046c(obj, (void**)&node, &var1);
            if (c != 0x20) {
                return i;
            }
            i++;
        } while (i < end);
    }
fail:
    return -1;
}
