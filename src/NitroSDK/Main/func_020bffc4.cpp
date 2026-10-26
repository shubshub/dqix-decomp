#include <globaldefs.h>

extern "C" int func_020bd8ac(unsigned int index);

struct Struct_020c0044;
extern "C" int func_020c0044(struct Struct_020c0044 *obj, unsigned int index);
extern "C" void *func_020c00b8(void *obj);
struct Struct_020c00c8;
extern "C" int func_020c00c8(struct Struct_020c00c8 *obj, int b, int c, int d);
extern "C" int func_020c0100(void *obj);
extern "C" int func_020c0110(char *obj, void *arg);
extern "C" void func_020c0138(void);
extern "C" int func_020c013c(char *obj, void *dst, int length, int offset);
extern "C" void func_020c0158(void);

// USA: func_020bffc4
extern "C" ARM void func_020bffc4(void *obj, unsigned int id) {
    int val = func_020bd8ac(id);
    if (val == 0) {
        *(void **)((char *)obj + 0x164) = (void *)func_020c0044;
        *(void **)((char *)obj + 0x168) = (void *)func_020c00b8;
        *(void **)((char *)obj + 0x16c) = (void *)func_020c00c8;
        *(void **)((char *)obj + 0x170) = (void *)func_020c0100;
    } else {
        *(void **)((char *)obj + 0x164) = (void *)func_020c0110;
        *(void **)((char *)obj + 0x168) = (void *)func_020c0138;
        *(void **)((char *)obj + 0x16c) = (void *)func_020c013c;
        *(void **)((char *)obj + 0x170) = (void *)func_020c0158;
    }
}
