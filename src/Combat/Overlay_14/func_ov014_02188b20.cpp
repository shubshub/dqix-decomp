#include <globaldefs.h>

struct Struct_ov014_02188b20 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short unknown_6_;
    char pad[0xc - 8];
    char* fc;
};

extern "C" int func_ov014_02188ba0(struct Struct_ov014_02188b20* obj, int val, int flag);

// USA: func_ov014_02188b20
extern "C" ARM int func_ov014_02188b20(struct Struct_ov014_02188b20* obj, int arg1) {
    if (obj == 0 || arg1 != 0) return 0;

    unsigned short n0 = obj->f0;
    char* base = obj->fc;
    unsigned short n1 = obj->f2;
    char* p = base + n0 * 4;
    unsigned short n2 = obj->f4;
    p = p + n1 * 4;
    p = p + n2 * 2;
    int off = (int)(p - base);
    off = (off + 3) & ~3;
    int zero = 0;
    unsigned short count = obj->unknown_6_;
    int* arr = (int*)(base + off);
    int i = 0;

    while (i < count) {
        *arr = func_ov014_02188ba0(obj, *arr, zero);
        arr++;
        i++;
    }
    return 1;
}
