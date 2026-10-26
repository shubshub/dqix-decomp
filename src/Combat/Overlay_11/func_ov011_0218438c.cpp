#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Brightness.h"

extern "C" void func_ov011_021842a0(void* obj);
extern "C" void func_02074af4(void* obj);

struct Struct_ov011_0218438c;
extern "C" void func_ov023_021f672c(struct Struct_ov011_0218438c* obj);

struct Struct_02074b64;
extern "C" void func_02074b64(struct Struct_02074b64* obj);

struct Struct_ov011_0218438c_2 {
    char pad0[0x9c];
    int f9c;
    int unknown_a0_;
    int unknown_a4_;
    int unknown_a8_;
    int unknown_ac_;
    int unknown_b0_;
    int unknown_b4_;
    char unknown_b8_[0x54];
    int unknown_10c_;
    int f110;
    int unknown_114_;
    char unknown_118_[0x72];
    char unknown_18a_[2];
    int unknown_18c_;
    int unknown_190_;
    char unknown_194_[0x10];
    unsigned char unknown_1a4_;
    unsigned char unknown_1a5_;
    char unknown_1a6_[2];
    int unknown_1a8_;
    int unknown_1ac_;
    short unknown_1b0_;
    short unknown_1b2_;
    int unknown_1b4_;
    int unknown_1b8_;
    short unknown_1bc_;
    short unknown_1be_;
    short unknown_1c0_;
    short unknown_1c2_;
    short unknown_1c4_;
    short unknown_1c6_;
    int unknown_1c8_;
    unsigned char unknown_1cc_;
    unsigned char unknown_1cd_;
    char unknown_1ce_[2];
    int unknown_1d0_;
    int unknown_1d4_;
    int unknown_1d8_;
    int unknown_1dc_;
};

// USA: func_ov011_0218438c
extern "C" ARM void func_ov011_0218438c(struct Struct_ov011_0218438c_2* obj) {
    func_ov011_021842a0(obj);
    obj->unknown_a8_ = 0;
    obj->unknown_ac_ = 0;
    obj->f9c = 0;
    obj->unknown_a0_ = 0;
    obj->unknown_a4_ = -1;
    obj->unknown_b0_ = 0;
    obj->unknown_b4_ = 0;
    memset(obj->unknown_b8_, 0, 0x54);
    obj->f110 = -1;
    obj->unknown_10c_ = 0;
    obj->unknown_114_ = 0;
    func_ov023_021f672c((struct Struct_ov011_0218438c*)((char*)obj + 0x118));
    obj->unknown_18c_ = -1;
    SetFlags04(GetGameResources(), 0xc0);
    obj->unknown_190_ = (*(unsigned short*)0x4000304 & 0x8000) >> 15;
    obj->unknown_1a4_ = 0;
    obj->unknown_1a5_ = 0;
    func_02074af4((char*)obj + 0x194);
    func_02074b64((struct Struct_02074b64*)((char*)obj + 0x194));
    obj->unknown_1a8_ = (*(unsigned int*)0x4000000 & 0x1f00) >> 8;
    obj->unknown_1ac_ = (*(unsigned int*)0x4001000 & 0x1f00) >> 8;
    obj->unknown_1b0_ = 0;
    obj->unknown_1b2_ = 0;
    obj->unknown_1b4_ = 0;
    obj->unknown_1b8_ = 0;
    obj->unknown_1bc_ = 0;
    obj->unknown_1be_ = 0;
    obj->unknown_1c0_ = 0;
    obj->unknown_1c2_ = 0;
    obj->unknown_1c4_ = 0;
    obj->unknown_1c6_ = 0;
    obj->unknown_1c8_ = 0;
    obj->unknown_1d0_ = 0;
    obj->unknown_1d4_ = 0;
    obj->unknown_1d8_ = 0;
    obj->unknown_1dc_ = 0;
    obj->unknown_1cc_ = 0;
    obj->unknown_1cd_ = 0;
}
