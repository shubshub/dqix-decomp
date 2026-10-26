#include <globaldefs.h>

struct Struct_ov017_021bd2f0 {
    unsigned short v[4];
};

struct Struct_ov017_021bd2f0_3 {
    unsigned char kind;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned char flag;
    unsigned char unknown_9_;
    Struct_ov017_021bd2f0 values;
};

struct Struct_ov017_021bd2f0_2 {
#if defined(jpn)
    unsigned char pad0[0xf8];
#else
    unsigned char pad0[0xfc];
#endif
    unsigned char dirty;
    unsigned char unknown_fd_[0x13c - 0xfd];
    unsigned char kind;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned short h4;
    unsigned short h6;
    unsigned char flag;
    unsigned char unknown_145_;
    Struct_ov017_021bd2f0 values;
};

// USA: func_ov017_021bd2f0
extern "C" ARM void func_ov017_021bd2f0(Struct_ov017_021bd2f0_2* obj, Struct_ov017_021bd2f0_3* params) {
    obj->kind = params->kind;
    obj->b1 = params->b1;
    obj->b2 = params->b2;
    obj->b3 = params->b3;
    obj->h4 = params->h4;
    obj->h6 = params->h6;
    obj->flag = params->flag;
    obj->values = params->values;
    obj->dirty = 1;
}
