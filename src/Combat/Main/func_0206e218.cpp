#include <globaldefs.h>

extern "C" void func_0206e164(void* obj, int i, int n);

// USA: func_0206e218
extern "C" ARM void func_0206e218(unsigned char* obj, int i) {
    unsigned char* arr;
    int idx;
    if (i >= 0xcc) return;
    if (i < 0) return;
    idx = i / 2;
    arr = obj + 0x2cc;
    arr[idx] |= (i % 2) ? 0x40 : 0x4;
    func_0206e164(obj, i, 1);
}
