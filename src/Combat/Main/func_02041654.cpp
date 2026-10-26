#include <globaldefs.h>

struct Struct_02041654 {
    char unk0[0x54];
    int field54;
#if defined(jpn)
    char unknown_58_[0x26c];
#else
    char unknown1_58_[0x278];
#endif
    unsigned short flags;
    char unknown_2d2_[0x2];
    int unknown_2d4_;
};

// USA: func_02041654
extern "C" ARM int func_02041654(struct Struct_02041654* obj) {
    if (obj->flags & 0x2) {
        return obj->unknown_2d4_;
    }
    return obj->field54;
}
