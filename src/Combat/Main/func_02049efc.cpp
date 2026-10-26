#include <globaldefs.h>

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);

struct Struct_02049efc {
    unsigned char pad[0x56];
    unsigned char unknown_56_;
};
struct Struct_02049efc_2 {
    unsigned char pad[0x13c];
    struct Struct_02049efc* sub;
};

// USA: func_02049efc
extern "C" ARM void func_02049efc(struct Struct_02049efc_2* obj) {
    if (obj->sub == NULL) return;
    if (func_02010088((struct S_10088*)obj)) {
        obj->sub->unknown_56_ = 0;
    }
}
