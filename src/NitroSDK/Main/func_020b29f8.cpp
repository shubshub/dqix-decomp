#include <globaldefs.h>

struct Struct_020b1300_2 {
    unsigned char* data;   /* 0x0 */
    signed char count;     /* 0x4 */
    unsigned char buf;     /* 0x5 */
};

// USA: func_020b29f8
extern "C" ARM int func_020b29f8(Struct_020b1300_2* r, int n) {
    int count = r->count;
    unsigned int buf = r->buf;
    int result;
    if (count < n) {
        int var3 = n - count;
        unsigned char* p = r->data;
        r->data = p + 1;
        unsigned char var5 = *p;
        r->buf = var5;
        r->count = 8;
        result = func_020b29f8(r, var3) | (buf << var3);
    } else {
        r->count = count - n;
        result = buf >> (count - n);
    }
    return result & (0xff >> (8 - n));
}
