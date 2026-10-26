#include <globaldefs.h>

struct Struct_ov025_021ebb90_6 {
    int a;
    unsigned char b, c, d;
    int e, f, g, h, i, j;
    short k, l;
    int m, n;
    unsigned short o, p, q, r, s, t;
    unsigned char u, v, w;
    unsigned short x;
};

extern "C" void func_ov025_021ecb90(struct Struct_ov025_021ebb90_6* dst, struct Struct_ov025_021ebb90_6* src);

struct Struct_ov025_021ed0b8 {
    struct Struct_ov025_021ebb90_6 arr[12];
    unsigned char count;
};

// USA: func_ov025_021ed0b8
extern "C" ARM void func_ov025_021ed0b8(struct Struct_ov025_021ed0b8* obj, struct Struct_ov025_021ebb90_6* src) {
    int i;
    for (i = 0; i < 12; i++) {
        if (obj->arr[i].a == 0) {
            func_ov025_021ecb90(&obj->arr[i], src);
            obj->count++;
            return;
        }
    }
}
