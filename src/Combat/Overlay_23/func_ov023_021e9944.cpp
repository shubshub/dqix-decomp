#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9944
extern "C" ARM int func_ov023_021e9944(void* obj) {
    unsigned char buf[0xb0];
    func_020ac4c0(buf);
    unsigned int v = *(unsigned int*)(buf + 0x8);
    func_ov017_021d6134(obj, v >> 0x18);
    return 1;
}
