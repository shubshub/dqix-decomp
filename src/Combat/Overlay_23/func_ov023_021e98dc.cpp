#include <globaldefs.h>

struct Struct_ov023_021e98dc {
    char pad[0x10];
    unsigned int lo : 9;
    unsigned int val : 14;
};

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e98dc
extern "C" ARM int func_ov023_021e98dc(void* obj) {
    char buf[0xb0];
    func_020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct Struct_ov023_021e98dc*)buf)->val);
    return 1;
}
