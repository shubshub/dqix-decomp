#include <globaldefs.h>

extern void* data_ov031_0224e580;

extern "C" int func_ov031_022102c8(void);
extern "C" void func_ov031_02210314(int);
extern "C" void func_ov031_0220fdec(int, int*);

// USA: func_ov031_0220fe44
extern "C" ARM int func_ov031_0220fe44(int arg) {
    if (data_ov031_0224e580 == NULL) return 0;
    if (!func_ov031_022102c8()) return 0;
    *(int*)((char*)data_ov031_0224e580 + 0x2c) = 0;
    *(int*)((char*)data_ov031_0224e580 + 0x28) = arg;
    func_ov031_02210314((int)func_ov031_0220fdec);
    return 1;
}
