#include <globaldefs.h>

#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020dbd9c {
    char unknown_0_[0x10];
    int unknown_10_;
    unsigned char unknown_14_;
};

struct Struct_ov006_02154614_2 {
    char unknown_0_[0x774];
    unsigned short unknown_774_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unknown_0_[0x7c];
};

struct Struct_ov006_021537d0 {
    short unknown_0_;
};

struct Struct_ov006_021555b0 {
    short unknown_0_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char unknown_0_[3][0x80];
#endif
    SafeAllocator* unknown_180_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* unknown_1a0_;
    void* unknown_1a4_;
    unsigned char* unknown_1a8_;
    void* unknown_1ac_;
    void* unknown_1b0_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* unknown_1b8_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    void* unknown_1cc_;
    void* unknown_1d0_;
    void* unknown_1d4_;
    void* unknown_1d8_;
    void* unknown_1dc_;
    void* unknown_1e0_;
    char unknown_1e4_[0x54];
    Object3D unknown_238_;
    Object3D unknown_2e4_;
    Object3D unknown_390_;
    Object3D unknown_43c_;
    Object3D unknown_4e8_;
    char unknown_594_[0x38];
    char unknown_5cc_[0x2c8];
    Struct_ov006_02156e54 unknown_894_[4];
    SafeAllocator unknown_a84_[4];
    int unknown_ad4_;
    int unknown_ad8_;
    unsigned char unknown_adc_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short unknown_ae2_;
    Struct_ov006_02154614_2 unknown_ae4_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char unknown_1288_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short unknown_12b8_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

struct Struct_0207fc6c;

typedef void (AlchemyPot::*PMF021549ac)();
struct RawTable021549ac { PMF021549ac e[3]; };
extern struct RawTable021549ac data_ov006_0215ff94;
extern PMF021549ac __ptmf_null;

extern "C" void func_ov006_02156bd8(Struct_ov006_02154614* arg0);
extern "C" void func_0207fc6c(Struct_0207fc6c* arg0, int arg1);
extern "C" void func_ov006_02156fdc(Struct_ov006_02154614* arg0);
extern "C" void func_ov006_02156d70(Struct_ov006_02154614* arg0);
extern "C" void func_ov006_02155068(Struct_ov006_02154614* arg0);

// USA: func_ov006_021549ac
extern "C" ARM void func_ov006_021549ac(AlchemyPot* self, int ticks) {
    func_ov006_02156bd8(self);
    Obj0207fc6c* menu = (Obj0207fc6c*)self->menu_;
    if (menu != 0)
        CallFunc0204c87cOverEntries0207fc6c(menu, ticks);
    func_ov006_02156fdc(self);
    func_ov006_02156d70(self);
    struct RawTable021549ac updates;
    updates = data_ov006_0215ff94;
    updates.e[2] = __ptmf_null;
    if (updates.e[self->state_] != 0) {
        (self->*updates.e[self->state_])();
        func_ov006_02155068(self);
    }
}
