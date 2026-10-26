#include <globaldefs.h>

typedef int (*Type_ov024_021f736c)(void*);

struct Struct_ov024_021f736c_2 {
    char pad[0x18];
    unsigned int unknown_18_;
};

struct Struct_ov024_021f736c {
    char pad[0x10];
    struct Struct_ov024_021f736c_2* unknown_10_;
};

extern Type_ov024_021f736c data_ov024_021ffda4[];

// USA: func_ov024_021f736c
extern "C" ARM int func_ov024_021f736c(struct Struct_ov024_021f736c* obj) {
    struct Struct_ov024_021f736c_2* inner = obj->unknown_10_;
    if (!inner) return 0;
    unsigned int idx = (inner->unknown_18_ << 5) >> 23;
    if (idx >= 0x42) return 0;
    Type_ov024_021f736c fn = data_ov024_021ffda4[idx];
    if (!fn) return 0;
    return fn(obj);
}
