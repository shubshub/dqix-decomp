#include <globaldefs.h>

extern "C" void func_ov015_0218c538(void *obj, int arg1);
extern "C" void func_ov015_0218c920(void *obj, int arg1);

struct Struct_ov015_02190090 {
    char pad0[0x1c];
    unsigned char state;
    char pad1[0x48 - 0x1c - 1];
    int counter;
};

// USA: func_ov015_02190090
extern "C" ARM void func_ov015_02190090(Struct_ov015_02190090 *obj) {
    obj->counter++;
    obj->counter %= 2;
    switch (obj->state) {
    case 0:
        func_ov015_0218c538(obj, 0);
        break;
    case 1:
        func_ov015_0218c920(obj, 0);
        break;
    }
}
