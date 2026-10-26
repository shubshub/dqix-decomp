#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02055660_2;
extern "C" bool func_020556dc(void** out, SafeAllocator* alloc);
extern "C" void func_020556cc(struct Struct_02055660_2* p, int a, int b, int c);
extern "C" void func_02056d80(void* obj);

struct Struct_02055718 {
    int f0;
    void* f4;
    int f8;
    int fc;
};

// USA: func_02055718
extern "C" ARM int func_02055718(Struct_02055718* p, int a, int b) {
    if (a == 0) return 0;
    if (b == 0) return 0;
    p->f0 = b;
    p->f8 = a;
    if (func_020556dc(&p->f4, (SafeAllocator*)p->f0)) {
        func_020556cc((struct Struct_02055660_2*)p->f4, p->fc, p->f8, p->f0);
        func_02056d80(p->f4);
    }
    return 1;
}
