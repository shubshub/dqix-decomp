#include <globaldefs.h>

extern "C" int func_020ac460(void* dst);

// USA: func_ov023_021ed6cc
extern "C" ARM bool func_ov023_021ed6cc(int idx) {
    unsigned int block[15];
    func_020ac460(block);
    int q = idx / 32;
    int r = idx % 32;
    int flag = 0;
    if (block[q] & (1 << r)) flag = 1;
    return flag != 0;
}
