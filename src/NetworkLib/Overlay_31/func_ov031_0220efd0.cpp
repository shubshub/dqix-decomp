#include <globaldefs.h>

extern "C" int func_ov031_0220d60c(void);
extern "C" int func_020d5bfc(int a0, void* a1, void* a2, unsigned int a3);
extern "C" int func_ov031_0220f2cc(void);

extern "C" {
    int func_ov031_0220f2e0(void* p);
    int func_ov031_0220f330(void* p);
}

extern int data_ov031_0224e54c;

// USA: func_ov031_0220efd0
extern "C" ARM void func_ov031_0220efd0(void) {
    int base = func_ov031_0220d60c();
    if (base == 0) return;
    if (*(int*)((char*)base + 0x2260) != 9) return;
    if (*(unsigned char*)((char*)base + 0x226b) == 1) return;
    if (func_ov031_0220f2e0(&data_ov031_0224e54c) == 0) return;
    int var1 = func_020d5bfc((int)func_ov031_0220f2cc,
        (void*)((char*)base + 0x2144), (void*)((char*)base + 0xf00), 0);
    if (var1 == 2) return;
    func_ov031_0220f330(&data_ov031_0224e54c);
}
