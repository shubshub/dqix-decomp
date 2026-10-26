#include <globaldefs.h>

extern "C" int func_020ac460(void* dst);
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov023_021e9190
extern "C" ARM int func_ov023_021e9190(void* obj) {
    unsigned int block[15];
    func_020ac460(block);
    int flag = 0;
    int idx = func_ov017_021d60f4(obj);
    int q = idx / 32;
    int r = idx % 32;
    if (block[q] & (1 << r)) flag = 1;
    if (flag) {
        func_ov017_021d6134((char*)obj + 8, 1);
    } else {
        func_ov017_021d6134((char*)obj + 8, 0);
    }
    return 1;
}
