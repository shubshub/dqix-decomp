#include <globaldefs.h>

extern "C" void GameObject_InitPartyMember(void*);

struct Struct_020415d8 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x2c2];
#else
    char unknown1_2_[0x2ce];
#endif
    unsigned short unknown_2d0_;
    char unknown_2d2_[2];
    int unknown_2d4_;
    char unknown_2d8_[0xc];
    int unknown_2e4_;
    unsigned char unknown_2e8_;
    char unknown_2e9_[3];
    int unknown_2ec_;
    unsigned char unknown_2f0_;
    char unknown_2f1_[3];
    int unknown_2f4_;
};

// USA: func_020415d8
extern "C" ARM void func_020415d8(struct Struct_020415d8* obj) {
    GameObject_InitPartyMember(obj);
    obj->unknown_2d0_ = 0;
    obj->unknown_2d4_ = 0;
    obj->unknown_2e4_ = 0;
    obj->unknown_2e8_ = 0;
    obj->unknown_2f4_ = 0;
    obj->unknown_2ec_ = 0x7a;
    obj->unknown_2f0_ = 0;
    obj->unknown_0_ |= 0x4000;
    obj->unknown_0_ &= ~0x80;
}
