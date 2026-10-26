#include <globaldefs.h>

extern "C" void func_020b0318(int* p);
extern "C" int func_0205a1f0(void* a, void* b, int c);
extern "C" void func_020b0594(int local, int zero, int arg2, void* obj);
extern "C" void func_020b0368(int local, int arg1, int arg2, void* obj);

struct Obj0205aaf8 {
    int words[3];
    char unknown_c_[0x38 - 0xc];
    int field0x38;
    char unknown_3c_[0x44 - 0x3c];
    int field0x44;
    char unknown_48_[0x50 - 0x48];
    unsigned char unknown_50_;
};

// USA: func_0205aaf8
extern "C" ARM int func_0205aaf8(struct Obj0205aaf8* obj, void* param2, int param3) {
    int local;
    int var1;
    func_020b0318((int*)obj);
    if (func_0205a1f0(&local, param2, param3) != 0) {
        return 1;
    }
    var1 = (obj->unknown_50_ == 0) ? 1 : 2;
    if (obj->field0x38 == 4) {
        func_020b0594(local, 0, var1, obj);
    } else {
        func_020b0368(local, obj->field0x44, var1, obj);
    }
    return 0;
}
