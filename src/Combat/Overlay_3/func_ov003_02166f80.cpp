#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02166f80_804 = 0x20c };
#else
enum { Enum_ov003_02166f80_804 = 0x324 };
#endif

struct Struct_0207fdcc_2;

struct Struct_0207fdcc {
    char unk[0xc5];
    unsigned char flags;
};

extern "C" struct Struct_0207fdcc* func_02081da8(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02166f80
extern "C" ARM void func_ov003_02166f80(void* self, int key, int set) {
    struct Struct_0207fdcc_2* obj = *(struct Struct_0207fdcc_2**)((char*)self + Enum_ov003_02166f80_804);
    struct Struct_0207fdcc* elem = func_02081da8(obj, key);
    if (elem == NULL) {
        return;
    }
    if (set) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    func_020813ec(*(void**)((char*)self + Enum_ov003_02166f80_804), key);
}
