#include <globaldefs.h>
extern "C" void* func_020bd5e4(int);

extern "C" int func_020beed8(void* a, void* rec, unsigned char arg2, unsigned char arg3,
                             int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);

struct Struct_020bebb4 {
    char pad0[5];
    unsigned char field5;
    unsigned char field6;
};

// USA: func_020bebb4
extern "C" ARM int func_020bebb4(void* a, int key, int arg2) {
    struct Struct_020bebb4* rec = (struct Struct_020bebb4*)func_020bd5e4((int)(key));
    if (rec == NULL) return 0;
    return func_020beed8(a, rec, rec->field6, rec->field5, key, arg2, 0, 0, 0, 0);
}
