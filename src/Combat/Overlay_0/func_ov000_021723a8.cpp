#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

struct Struct_0205cfd4 { char unknown_0_[0xbc]; };
struct Struct_0205bef8 { char unknown_0_[0x40]; };
struct Struct_02092aa4 { char unknown_0_[0x3c]; };
#if defined(jpn)
struct Struct_0203c0cc { char unknown_0_[0x38]; };
enum { Enum_ov000_021723a8_1096 = 0x488, Enum_ov000_021723a8_9 = 5 };
#else
struct Struct_0203c0cc { char unknown_0_[0x18]; };
enum { Enum_ov000_021723a8_1096 = 0x448, Enum_ov000_021723a8_9 = 9 };
#endif

void ItemTable_Init(void* obj);
void Background_Init(struct List0204af64* obj);
void InitStruct0205cfd4(struct InitTarget0205cfd4* obj);
void GridCursor_Init(struct Struct_0205bef8* obj);
extern "C" void func_0204c684(void* obj);
void InitObj02092aa4(Obj02092aa4* obj, int mode);
void SpriteContext_Init(char* obj);
extern "C" void* func_0202ae18(GameState* gs);
int GetField0x3acValue_020100a8(GameState* gs);
void InitFields0x0_0203c0cc(struct State0xc0cc* obj);

struct Struct_ov000_021723a8;
extern "C" void func_ov000_0217228c(struct Struct_ov000_021723a8* arg0);
extern "C" void func_ov000_0216ff28(void* arg0);
extern "C" void func_ov000_0217feb0(struct Struct_ov000_021723a8* arg0, unsigned char arg1, int arg2);
extern "C" void func_ov000_02174b14(struct Struct_ov000_021723a8* arg0);

struct Struct_ov000_021723a8_2 {
    void* unknown_0_;
    void* unknown_4_;
    char unknown_8_[0x38 - 0x8];
    void* unknown_38_;
    char unknown_3c_[0x44 - 0x3c];
    int unknown_44_;
    int unknown_48_;
    char unknown_4c_[Enum_ov000_021723a8_1096 - 0x4c];
};

struct Struct_ov000_021723a8 {
    char unknown_0_[0x20];
    int unknown_20_;
    char unknown_24_[0x68 - 0x24];
    int unknown_68_;
    signed char unknown_6c_[4];
    char unknown_70_[0x7c - 0x70];
    struct Struct_02092aa4 unknown_7c_;
    char unknown_b8_[0xd0 - 0xb8];
    char unknown_d0_[0xe8 - 0xd0];
    char unknown_e8_[0x11c - 0xe8];
    char unknown_11c_[0x170 - 0x11c];
    int unknown_170_;
    int unknown_174_;
    int unknown_178_;
    int unknown_17c_;
    volatile unsigned short unknown_180_;
    volatile unsigned short unknown_182_;
    int unknown_184_;
    struct Struct_0205cfd4 unknown_188_;
    char unknown_244_[0x244 - 0x188 - sizeof(struct Struct_0205cfd4)];
    struct Struct_0205bef8 unknown1_244_;
    char unknown_284_[0x284 - 0x244 - sizeof(struct Struct_0205bef8)];
    char unknown1_284_[7][0xe0];
    struct Struct_02020cb8 unknown_8a4_[3];
    char unknown_904_[4];
    int unknown_908_;
    int unknown_90c_;
    int unknown_910_;
    int unknown_914_;
    int unknown_918_;
    int unknown_91c_;
    int unknown_920_;
    int unknown_924_;
    int unknown_928_;
    int unknown_92c_;
    char unknown_930_[4];
    int unknown_934_;
    char unknown_938_[4];
    int unknown_93c_;
    int unknown_940_;
    int unknown_944_;
    char unknown_948_[0x950 - 0x948];
    int unknown_950_;
    unsigned char unknown_954_;
    unsigned char unknown_955_;
    unsigned char unknown_956_;
    char unknown_957_;
    struct Struct_ov000_021723a8_2 unknown_958_[4];
    SafeAllocator unknown_1a78_;
    SafeAllocator unknown_1a8c_;
    SafeAllocator unknown_1aa0_;
    SafeAllocator unknown_1ab4_;
    SafeAllocator unknown_1ac8_;
    SafeAllocator unknown_1adc_;
    int unknown_1af0_;
    char unknown_1af4_[4];
    SafeAllocator unknown_1af8_;
#if !defined(jpn)
    struct Struct_0203c0cc unknown_1b0c_[3];
#endif
    struct Struct_0203c0cc unknown_1b54_;
    struct Struct_0203c0cc unknown_1b6c_;
    struct Struct_0203c0cc unknown_1b84_[Enum_ov000_021723a8_9];
    struct Struct_0203c0cc unknown_1c5c_[8];
    char unknown_1d1c_[0x1d5c - 0x1d1c];
    unsigned char unknown_1d5c_;
    char unknown_1d5d_;
    unsigned short unknown_1d5e_;
    unsigned char unknown_1d60_[8];
    signed char unknown_1d68_;
    unsigned char unknown_1d69_;
    char unknown_1d6a_;
    signed char unknown_1d6b_;
    signed char unknown_1d6c_;
    char unknown_1d6d_;
    signed char unknown_1d6e_;
    signed char unknown_1d6f_;
    unsigned char unknown_1d70_;
    char unknown_1d71_;
    unsigned short unknown_1d72_;
    char unknown_1d74_[4];
    unsigned char unknown_1d78_;
    unsigned char unknown_1d79_;
    unsigned char unknown_1d7a_;
    char unknown_1d7b_;
    int unknown_1d7c_;
    unsigned char unknown_1d80_;
    unsigned char unknown_1d81_;
};

struct Struct_ov000_02184288_3 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_ov000_021723a8* unknown_8_;
};
extern struct Struct_ov000_02184288_3 data_ov000_02184288;

// USA: func_ov000_021723a8
extern "C" ARM void func_ov000_021723a8(struct Battle021723a8* self, int arg) {
    self->f20 = -1;
    self->alloc1a78.ResetAllocatorPointer();
    self->alloc1a8c.ResetAllocatorPointer();
    self->alloc1ab4.ResetAllocatorPointer();
    self->alloc1aa0.ResetAllocatorPointer();
    self->alloc1ac8.ResetAllocatorPointer();
    self->alloc1adc.ResetAllocatorPointer();
    self->alloc1af8.ResetAllocatorPointer();
    ItemTable_Init(self->listD0);
    ItemTable_Init(self->listE8);
    data_ov000_02184288.battle = self;
    self->f68 = 0;
    self->f178 = 0;
    self->f17c = -1;
    self->f1d72 = 0;
    self->f1d72 |= 2;
    self->f184 = 0;
    {
        volatile unsigned short* var0 = (volatile unsigned short*)0x4001008;
        volatile short var1, var2;
        {
            unsigned short var3 = var0[0];
            var1 = var3;
            arg0->unknown_180_ = var3;
            var1;
        }
        {
            unsigned short var4 = var0[1];
            var2 = var4;
            arg0->unknown_182_ = var4;
            var2;
        }
    }
    Background_Init(&self->lists[0]);
    Background_Init(&self->lists[1]);
    Background_Init(&self->lists[2]);
    InitStruct0205cfd4(&self->obj188);
    GridCursor_Init(&self->obj244);
    for (int i = 0; i < 7; i++) {
        func_0204c684(self->slots284[i]);
    }
    self->f1af0 = arg;
    InitObj02092aa4(&self->obj7c, 0);
    SpriteContext_Init(self->obj11c);
    self->f170 = 0;
    self->f174 = 0;
    self->f910 = 0;
    self->f934 = 0;
    self->f908 = 0;
    self->f90c = -1;
    self->f914 = 0;
    self->f918 = 0;
    self->f91c = 0;
    self->f920 = 0x100;
    self->f924 = 0x100;
    self->f928 = 0x100;
    self->f92c = 0;
    self->f1d5e = 0x10;
    self->f93c = 0;
    self->f940 = 0;
    self->f944 = 0;
    memset(self->flags1d60, 0, 8);
    self->sel1d68 = 0;
    self->flags1d60[self->sel1d68] = 1;
    self->f1d69 = 0;
    self->f1d6b = -1;
    self->f1d6c = -1;
    self->f1d6e = -1;
    self->f1d6f = -1;
    self->f1d70 = 0;
    self->f1d79 = 1;
    self->f1d80 = 0;
    self->f1d81 = 0;
    self->f1d5c = 0;
    self->f1d7a = 0;
    GameState* gs = GameState::GetInstance();
    func_0202ae18(gs);
    int id = GetField0x3acValue_020100a8(gs);
    if (id < 0) {
        id = 0;
    }
    arg0->unknown_17c_ = var7;
    func_ov000_0217228c(arg0);
    func_0203c0cc(&arg0->unknown_1b54_);
    func_0203c0cc(&arg0->unknown_1b6c_);
    for (int var8 = 0; var8 < Enum_ov000_021723a8_9; var8++) {
        func_0203c0cc(&arg0->unknown_1b84_[var8]);
    }
#if !defined(jpn)
    for (int var9 = 0; var9 < 3; var9++) {
        func_0203c0cc(&arg0->unknown_1b0c_[var9]);
    }
#endif
    for (int var10 = 0; var10 < 8; var10++) {
        func_0203c0cc(&arg0->unknown_1c5c_[var10]);
    }
    struct Struct_ov000_021723a8_2* var11;
    for (int var12 = 0; var12 < 4; var12++) {
        var11 = &arg0->unknown_958_[arg0->unknown_6c_[var12]];
        func_ov000_0216ff28(var11);
        var11->unknown_44_ = 0;
        var11->unknown_48_ = 0;
        var11->unknown_38_ = &arg0->unknown_188_;
        var11->unknown_4_ = arg0->unknown_b8_;
        var11->unknown_0_ = arg0->unknown_d0_;
    }
    func_ov000_0217feb0(arg0, 0, -1);
    func_ov000_0217feb0(arg0, 1, func_020100a8(var6));
    func_ov000_02174b14(arg0);
    arg0->unknown_1d7c_ = 0;
    arg0->unknown_1d78_ = 0;
    arg0->unknown_950_ = 0;
    arg0->unknown_954_ = 0;
    arg0->unknown_955_ = 0;
    arg0->unknown_956_ = 0;
}
