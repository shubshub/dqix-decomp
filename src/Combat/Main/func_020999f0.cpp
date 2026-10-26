#include <globaldefs.h>

struct Struct_020999f0_2 { char v[7]; };

struct Struct_020995f8_2 {
    unsigned short f0;
    unsigned short f2;
    unsigned char f4;
    struct Struct_020999f0_2 unknown_5_;
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char pad;
};

struct Struct_020999f0 {
    struct Struct_020995f8_2* data;
    int count;
    int cap;
};

// USA: func_020999f0
extern "C" ARM void func_020999f0(struct Struct_020999f0* list, struct Struct_020995f8_2* src) {
    int i = list->count;
    if (list->cap <= i) return;
    list->count = i + 1;
    {
        struct Struct_020995f8_2* elem = &list->data[i];
        elem->f0 = src->f0;
        elem->f2 = src->f2;
        elem->f4 = src->f4;
        elem->unknown_5_ = src->unknown_5_;
        elem->fc = src->fc;
        elem->unknown_d_ = src->unknown_d_;
        elem->fe = src->fe;
    }
}
