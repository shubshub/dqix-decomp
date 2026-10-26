#include <globaldefs.h>

struct Struct_020096ac {
    unsigned char unknown_0_;
    char pad1;
    unsigned short param2;
    unsigned char count;
    unsigned char digits[0x20];
};

// USA: func_020096ac
extern "C" ARM void func_020096ac(Struct_020096ac* obj, unsigned long long value) {
    obj->unknown_0_ = 0;
    obj->count = 0;
    if (value != 0) {
        do {
            obj->digits[obj->count++] = value % 10;
            value /= 10;
        } while (value != 0);
    }
    unsigned char* p = obj->digits;
    unsigned char* end = p + obj->count;
    unsigned char* q = end - 1;
    if (p < q) {
        do {
            unsigned char t = *q;
            unsigned char u = *p;
            *p++ = t;
            *q-- = u;
        } while (p < q);
    }
    obj->param2 = obj->count - 1;
}
