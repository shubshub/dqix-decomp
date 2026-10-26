#include <globaldefs.h>

extern "C" int func_ov000_02156068(int a, int b, int c, int d);

// USA: func_ov024_021d8a40
extern "C" ARM int func_ov024_021d8a40(int* p0, int unused1, int id, int arg3, int unused4, int val) {
    int check = func_ov000_02156068(*p0, (short)id, 2, 0);
    if (check == 0) return val;
    return (int)((float)val * 1.5f);
}
