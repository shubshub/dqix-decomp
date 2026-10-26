#include <globaldefs.h>

struct Struct_020b1d70;
struct Struct_020b1d70_2;
extern "C" int func_020b1d70(struct Struct_020b1d70* arg0, struct Struct_020b1d70_2** arg1, int arg2, int arg3, int arg4, unsigned short arg5);

extern char* data_ov031_02290d38;

// USA: func_ov031_0223c898
extern "C" ARM int func_ov031_0223c898(struct Struct_020b1d70* arg0, int arg1, int arg2, int arg3, unsigned short arg4, int index) {
    struct Struct_020b1d70_2** var0 = (struct Struct_020b1d70_2**)(data_ov031_02290d38 + index * 8);
    return func_020b1d70(arg0, var0, arg1, arg2, arg3, arg4);
}
