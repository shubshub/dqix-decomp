#include <globaldefs.h>

extern "C" void func_ov031_02239bc0(int v);
extern "C" unsigned short func_020d4dd4(void);
extern "C" void* VectorizedInvertedMemcpy(void* dst, void* src, int n);
extern unsigned char* data_ov031_02290d20;

// USA: func_ov031_0223a698
extern "C" ARM void func_ov031_0223a698(void) {
    func_ov031_02239bc0(*(int*)(data_ov031_02290d20 + 0xac8));
    data_ov031_02290d20[0xa90] = 1;
    unsigned short idx = func_020d4dd4();
    *(unsigned short*)(data_ov031_02290d20 + 0x648) = idx;
    VectorizedInvertedMemcpy(*(void**)(data_ov031_02290d20 + 0xaa4), data_ov031_02290d20 + 0xa50, 0x40);
    data_ov031_02290d20[0xa93] = 0;
    *(int*)(data_ov031_02290d20 + 0x204) = 0;
    *(unsigned short*)(data_ov031_02290d20 + 0x648) += 1;
}
