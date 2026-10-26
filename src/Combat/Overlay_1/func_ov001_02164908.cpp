#include <globaldefs.h>
#include "World/Object3D.h"

struct S02037418;
struct Struct_0203fc84;
extern "C" void func_0203fc84(struct Struct_0203fc84* obj, int value);

struct Struct_ov001_02164908 {
    int type;
    char pad[8];
    void* unknown_c_;
};

struct Struct_ov001_02164908_2 {
    char pad[0x14];
    void* unknown_14_;
    void* unknown_18_;
};

// USA: func_ov001_02164908
extern "C" ARM int func_ov001_02164908(struct Struct_ov001_02164908* arr, int idx, int val) {
    struct Struct_ov001_02164908* e;
    void* p;
    void* q;
    if (idx < 0 || idx >= 0x20) return 0;
    e = &arr[idx];
    switch (e->type) {
    case 0:
    case 1:
    case 4:
    case 5:
        p = e->unknown_c_;
        if (p == 0) return 0;
        ((Object3D*)((struct S02037418*)p))->SetInheritedAlpha(val);
        return 1;
    case 6:
        p = e->unknown_c_;
        if (p == 0) return 0;
        q = ((struct Struct_ov001_02164908_2*)p)->unknown_18_;
        if (q == 0) return 0;
        ((Object3D*)((struct S02037418*)q))->SetInheritedAlpha(val);
        return 1;
    case 2:
        p = e->unknown_c_;
        if (p == 0) return 0;
        q = ((struct Struct_ov001_02164908_2*)p)->unknown_14_;
        if (q == 0) return 0;
        func_0203fc84((struct Struct_0203fc84*)q, val);
    default:
        return 0;
    }
}
