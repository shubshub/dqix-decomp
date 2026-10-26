#include <globaldefs.h>

extern "C" int func_020ac4c0(void* dst);
extern "C" int func_ov017_021d60f4(void* obj);
extern "C" void func_ov017_021d6134(void* variant, int val);

// USA: func_ov023_021e9278
extern "C" ARM int func_ov023_021e9278(void* obj) {
    char buf[0xb0];
    func_020ac4c0(buf);
    int flag = 0;
    int idx = func_ov017_021d60f4(obj);
    unsigned int word = *(unsigned int*)(buf + 0x4c + (idx / 32) * 4);
    if (word & (1 << (idx % 32))) {
        flag = 1;
    }
    if (flag != 0) {
        func_ov017_021d6134((char*)obj + 8, 1);
    } else {
        func_ov017_021d6134((char*)obj + 8, 0);
    }
    return 1;
}
