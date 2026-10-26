#include <globaldefs.h>

struct Struct_020e1288_2 {
    unsigned char pad0[0xa];
    unsigned char w;
    unsigned char h;
};

struct Struct_020e1288 {
    unsigned char pad0[8];
    struct Struct_020e1288_2* unknown_8_;
};

// USA: func_020e1288
extern "C" ARM int func_020e1288(struct Struct_020e1288* obj) {
    struct Struct_020e1288_2* d = obj->unknown_8_;
    if (d != NULL) {
        return (d->w * d->h) >> 1;
    }
    return 0;
}
