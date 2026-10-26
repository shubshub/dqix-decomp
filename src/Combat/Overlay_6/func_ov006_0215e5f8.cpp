#include <globaldefs.h>

struct Struct_0207fdcc_2;

extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c04(struct Struct_0207fdcc_2* obj, int key);

struct Struct_ov006_0215e5f8 {
    char pad[0x394];
    unsigned short unknown_394_;
};

// USA: func_ov006_0215e5f8
extern "C" ARM void func_ov006_0215e5f8(struct Struct_ov006_0215e5f8* obj, struct Struct_0207fdcc_2* target, int flag, unsigned char* arg3) {
    if (target == NULL) {
        return;
    }
    if (flag != 0) {
        obj->unknown_394_ |= 0x80;
        *arg3 = 1;
        func_02080c20(target, 0xd);
        func_02080c20(target, 0xe);
        func_02080c20(target, 0xf);
        func_02080c20(target, 9);
    } else {
        obj->unknown_394_ &= ~0x80;
        *arg3 = 0;
        func_02080c04(target, 0xd);
        func_02080c04(target, 0xe);
        func_02080c04(target, 0xf);
        func_02080c04(target, 9);
    }
}
