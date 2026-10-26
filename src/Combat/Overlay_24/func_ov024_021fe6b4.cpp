#include <globaldefs.h>

struct Struct_ov024_021fd1bc {
    char unk[0x3c];
    int value;
};

// USA: func_ov024_021fe6b4
extern "C" ARM void func_ov024_021fe6b4(struct Struct_ov024_021fd1bc* obj, int val) {
    obj->value = val;
    *((unsigned char*)obj + 0x40) = *((unsigned char*)obj + val + 0x10);
}
