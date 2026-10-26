#include <globaldefs.h>

struct Struct_ov023_021e9b7c {
    char pad[0x18];
    unsigned int lo : 9;
    unsigned int val : 7;
};

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9b7c
extern "C" ARM int func_ov023_021e9b7c(void* obj) {
    char buf[0xb0];
    func_020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct Struct_ov023_021e9b7c*)buf)->val);
    return 1;
}
