#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov023_021eae0c
extern "C" ARM int func_ov023_021eae0c(void* obj) {
    unsigned char buf[0xb0];
    func_020ac4c0(buf);
    func_ov017_021d6134(obj, *(int*)(buf + 0xac));
    return 1;
}
