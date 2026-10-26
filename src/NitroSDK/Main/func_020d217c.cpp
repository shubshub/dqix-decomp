#include <globaldefs.h>

extern "C" void* func_020d2404(int);
struct Struct_020d217c_2;
extern "C" int func_020d248c(Struct_020d217c_2*);

struct Struct_020d217c {
    int field0;
    int type;
    int arg1;
    int arg2;
    int arg3;
    int arg4;
};

// USA: func_020d217c
// Kept as extern "C" func_020d217c: 18 decompiled EnqueueEvent/PostEvent/SubmitCommand
// wrappers reference this symbol directly, so the raw name must be preserved.
extern "C" ARM int func_020d217c(int type, int arg1, int arg2, int arg3, int arg4) {
    struct Struct_020d217c* node = (struct Struct_020d217c*)func_020d2404(1);
    if (node == NULL) return (int)node;
    node->type = type;
    node->arg1 = arg1;
    node->arg2 = arg2;
    node->arg3 = arg3;
    node->arg4 = arg4;
    return func_020d248c((Struct_020d217c_2*)node);
}
