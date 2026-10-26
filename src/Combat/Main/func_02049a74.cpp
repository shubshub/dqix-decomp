#include <globaldefs.h>

extern "C" int func_02048bd0(unsigned char* obj);
extern "C" int func_02048c68(unsigned char* obj);
struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_02049ee8(unsigned char* obj);

struct Struct_02049a74 {
    unsigned char pad1[0x20];
    unsigned int flags;
    unsigned char pad2[0x56 - 0x24];
    unsigned char unknown_56_;
};

struct Struct_02048f64 {
    unsigned char pad[0x13c];
    struct Struct_02049a74* sub;
};

// USA: func_02049a74
extern "C" ARM void func_02049a74(struct Struct_02048f64* obj) {
    if (obj->sub == NULL) return;
    if (func_02048bd0((unsigned char*)obj)) return;
    if (func_02048c68((unsigned char*)obj)) return;
    if (obj->sub->unknown_56_ == 0) return;
    if (func_02010088((struct S_10088*)obj)) return;
    if (func_02049ee8((unsigned char*)obj)) {
        obj->sub->flags |= 4;
    }
}
