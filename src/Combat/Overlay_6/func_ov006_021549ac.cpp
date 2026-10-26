#include <globaldefs.h>

#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct Struct_020dbd9c {
    char unk_0[0x10];
    int state_;
    unsigned char unk_14;
};

struct Struct_ov006_02154614_2 {
    char unk_0[0x774];
    unsigned short flags_;
    char unknown_776_[0x7];
    signed char unknown_77d_;
    char unknown_77e_[0x1d];
    unsigned char unknown_79b_0_ : 1;
    unsigned char unknown_79b_1_ : 1;
};

struct Struct_ov006_02156e54 {
    char unk_0[0x7c];
};

struct Struct_ov006_021537d0 {
    short id_;
};

struct Struct_ov006_021555b0 {
    short id_;
    unsigned short unknown_2_0_ : 1;
    unsigned short unknown_2_1_ : 1;
    unsigned short unknown_2_2_ : 14;
};

struct Struct_ov006_02154614 {
#if !defined(jpn)
    char names_[3][0x80];
#endif
    SafeAllocator* allocators_;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    SafeAllocator unknown_18c_;
    void* previousCamera_;
    void* canvasBuffer_;
    unsigned char* unknown_1a8_;
    void* itemNames_;
    void* texts_;
    Struct_ov006_021537d0* unknown_1b4_;
    Struct_ov006_021537d0* nextRecipe_;
    int unknown_1bc_;
    Struct_ov006_021555b0* unknown_1c0_;
    unsigned char* unknown_1c4_;
    void* layout_;
    void* backgrounds_;
    void* canvases_;
    void* menu_;
    void* item_;
    void* nextItem_;
    void* sprites_;
    char renderer_[0x54];
    Object3D unknown_238_;
    Object3D pot_;
    Object3D unknown_390_;
    Object3D effect_;
    Object3D steam_;
    char unknown_594_[0x38];
    char camera_[0x2c8];
    Struct_ov006_02156e54 ingredients_[4];
    SafeAllocator unknown_a84_[4];
    int task_;
    int unknown_ad8_;
    unsigned char state_;
    unsigned char unknown_add_;
    unsigned char unknown_ade_;
    unsigned char unknown_adf_;
    unsigned char unknown_ae0_;
    unsigned char unknown_ae1_;
    unsigned short flags_;
    Struct_ov006_02154614_2 window_;
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
    char partNames_[0x18];
    Struct_020dbd9c unknown_12a0_;
    short itemId_;
    signed char unknown_12ba_;
    unsigned char unknown_12bb_;
    unsigned char unknown_12bc_;
    unsigned char unknown_12bd_;
};

struct Struct_0207fc6c;

typedef void (Struct_ov006_02154614::*Type_02000c9c_7)();
struct Struct_ov006_0215ff94 { Type_02000c9c_7 e[3]; };
extern struct Struct_ov006_0215ff94 data_ov006_0215ff94;
extern Type_02000c9c_7 __ptmf_null;

extern "C" void func_ov006_02156bd8(Struct_ov006_02154614* self);
extern "C" void func_0207fc6c(Struct_0207fc6c* menu, int ticks);
extern "C" void func_ov006_02156fdc(Struct_ov006_02154614* self);
extern "C" void func_ov006_02156d70(Struct_ov006_02154614* self);
extern "C" void func_ov006_02155068(Struct_ov006_02154614* self);

// USA: func_ov006_021549ac
extern "C" ARM void func_ov006_021549ac(Struct_ov006_02154614* self, int ticks) {
    func_ov006_02156bd8(self);
    Struct_0207fc6c* menu = (Struct_0207fc6c*)self->menu_;
    if (menu != 0)
        func_0207fc6c(menu, ticks);
    func_ov006_02156fdc(self);
    func_ov006_02156d70(self);
    struct Struct_ov006_0215ff94 var1;
    var1 = data_ov006_0215ff94;
    var1.e[2] = __ptmf_null;
    if (var1.e[self->state_] != 0) {
        (self->*var1.e[self->state_])();
        func_ov006_02155068(self);
    }
}
