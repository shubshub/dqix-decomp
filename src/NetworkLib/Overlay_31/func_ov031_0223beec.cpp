#include <globaldefs.h>

struct Struct_ov031_0223beec { unsigned short field0; unsigned char field2; unsigned char unknown_3_; int field4[64]; };
extern "C" Struct_ov031_0223beec* func_ov031_0223beb8(int n);

// USA: func_ov031_0223beec
extern "C" ARM void func_ov031_0223beec(int n, int base, int stride) {
    Struct_ov031_0223beec* arr = func_ov031_0223beb8(n);
    for (int i = 0; i < n; i++) {
        arr->field4[i] = base;
        base += stride;
    }
    arr->unknown_3_ = n;
}
