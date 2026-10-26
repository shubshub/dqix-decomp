#include <globaldefs.h>

struct Struct_020b0e6c;
extern "C" int func_020b0e6c(Struct_020b0e6c* obj, unsigned int key);

struct Struct_020b0eb4;
extern "C" void* func_020b0eb4(Struct_020b0eb4** slot, unsigned int key);

typedef int (*Type_020b0f00)(int*, int);

struct Struct_020b0f00 {
    void* slot;
    Type_020b0f00 next;
};

// USA: func_020b0f00
extern "C" ARM int func_020b0f00(Struct_020b0f00* obj, int base, int arg2, int* outPtr) {
    int local = arg2;
    int total = 0;
    Type_020b0f00 next = obj->next;
    int id = next(&local, base);
    if (id != 0) {
        do {
            if (id == 0xa) break;

            int val = func_020b0e6c((Struct_020b0e6c*)obj, id);
            if (val == 0xffff) {
                val = *(unsigned short*)((char*)obj->slot + 2);
            }
            void* entry = func_020b0eb4((Struct_020b0eb4**)obj, val);
            int fieldVal = *(signed char*)((char*)entry + 2);
            int delta = base + fieldVal;
            total = total + delta;
            id = next(&local, delta);
        } while (id != 0);
    }

    if (outPtr != 0) {
        outPtr[0] = (id == 0xa) ? local : 0;
    }
    if (total > 0) {
        total = total - base;
    }
    return total;
}
