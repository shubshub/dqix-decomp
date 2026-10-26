#include <globaldefs.h>

struct Struct_02049520_2;
extern "C" void func_02049550(struct Struct_02049520_2* p);

struct Struct_02049520 {
    unsigned char pad[0x20];
    unsigned int flags;
};
struct Struct_02048f64_3 {
    unsigned char pad[0x13c];
    struct Struct_02049520* sub;
};

// USA: func_02049520
extern "C" ARM void func_02049520(struct Struct_02048f64_3* obj) {
    struct Struct_02049520* sub = obj->sub;
    if (sub == NULL) return;
    func_02049550((struct Struct_02049520_2*)((unsigned char*)sub + 0x4e));
    obj->sub->flags &= ~0x4;
}
