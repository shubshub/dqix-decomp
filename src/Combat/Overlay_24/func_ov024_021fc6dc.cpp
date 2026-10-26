#include <globaldefs.h>

extern "C" int func_ov024_021fe698(void* obj, int idx);
extern "C" void func_ov024_021fd954(void* obj, int mode);

// USA: func_ov024_021fc6dc
extern "C" ARM void func_ov024_021fc6dc(void* a1) {
    if (!func_ov024_021fe698(a1, 2)) return;
    if (!func_ov024_021fe698(a1, 5)) return;
    short idx = *(short*)((char*)(*(int**)((char*)a1 + 0x64c)) + 0x30);
    if (idx <= 0) return;
    if (idx > 5) return;
    int* entry = (int*)((char*)a1 + idx * 4);
    int val = *(int*)((char*)entry + 0x154);
    if (val < 0x5a) return;
    int r2 = *(int*)((char*)entry + 0x13c);
    if (r2 < 0x7d) return;
    *(int*)((char*)a1 + 0x16c) = r2;
    func_ov024_021fd954(a1, 13);
}
