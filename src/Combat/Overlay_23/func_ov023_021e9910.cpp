#include <globaldefs.h>

struct Struct_ov023_021e9910 {
    char pad[0xc];
    unsigned int lo : 14;
    unsigned int val : 14;
};

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9910
extern "C" ARM int func_ov023_021e9910(void* obj) {
    char buf[0xb0];
    func_020ac4c0(buf);
    func_ov017_021d6134(obj, ((struct Struct_ov023_021e9910*)buf)->val);
    return 1;
}
