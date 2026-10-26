#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"
#include "Resource/GridCursor.h"

struct InitTarget0205cfd4 { char pad[0xbc]; };
struct Obj02092aa4 { char pad[0x3c]; };
#if defined(jpn)
struct Struct_0203c0cc { char unknown_0_[0x38]; };
enum { Enum_ov000_021723a8_1096 = 0x488, Enum_ov000_021723a8_9 = 5 };
#else
struct Struct_0203c0cc { char unknown_0_[0x18]; };
enum { Enum_ov000_021723a8_1096 = 0x448, Enum_ov000_021723a8_9 = 9 };
#endif

void ItemTable_Init(void* obj);
void Background_Init(struct BackgroundGraphics* obj);
void Window_Init(struct InitTarget0205cfd4* obj);
void GridCursor_Init(struct GridCursor* obj);
extern "C" void WindowPane_Init(void* obj);
void InitObj02092aa4(Obj02092aa4* obj, int mode);
void SpriteContext_Init(char* obj);
extern "C" void* LinkSession_GetInstance(GameState* gs);
int GameState_GetProtagonistIndex(GameState* gs);
void CachedTextLabel_Init(struct State0xc0cc* obj);

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

struct Battle021723a8 {
    char pad0[0x20];
    int f20;
    char pad24[0x68 - 0x24];
    int f68;
    signed char order[4];
    char pad70[0x7c - 0x70];
    struct Obj02092aa4 obj7c;
    char padb8[0xd0 - 0xb8];
    char listD0[0xe8 - 0xd0];
    char listE8[0x11c - 0xe8];
    char obj11c[0x170 - 0x11c];
    int f170;
    int f174;
    int f178;
    int f17c;
    volatile unsigned short savedBg0Cnt;
    volatile unsigned short savedBg1Cnt;
    int f184;
    struct InitTarget0205cfd4 obj188;
    char pad244[0x244 - 0x188 - sizeof(struct InitTarget0205cfd4)];
    struct GridCursor obj244;
    char pad284[0x284 - 0x244 - sizeof(struct GridCursor)];
    char slots284[7][0xe0];
    struct BackgroundGraphics lists[3];
    char pad904[4];
    int f908;
    int f90c;
    int f910;
    int f914;
    int f918;
    int f91c;
    int f920;
    int f924;
    int f928;
    int f92c;
    char pad930[4];
    int f934;
    char pad938[4];
    int f93c;
    int f940;
    int f944;
    char pad948[0x950 - 0x948];
    int f950;
    unsigned char f954;
    unsigned char f955;
    unsigned char f956;
    char pad957;
    struct Entry021723a8 entries[4];
    SafeAllocator alloc1a78;
    SafeAllocator alloc1a8c;
    SafeAllocator alloc1aa0;
    SafeAllocator alloc1ab4;
    SafeAllocator alloc1ac8;
    SafeAllocator alloc1adc;
    int f1af0;
    char pad1af4[4];
    SafeAllocator alloc1af8;
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
    Window_Init(&self->obj188);
    GridCursor_Init(&self->obj244);
    for (int i = 0; i < 7; i++) {
        WindowPane_Init(self->slots284[i]);
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
    LinkSession_GetInstance(gs);
    int id = GameState_GetProtagonistIndex(gs);
    if (id < 0) {
        id = 0;
    }
    self->f17c = id;
    func_ov000_0217228c(self);
    CachedTextLabel_Init(&self->state1b54);
    CachedTextLabel_Init(&self->state1b6c);
    for (int i = 0; i < regionalStates1b84; i++) {
        CachedTextLabel_Init(&self->states1b84[i]);
    }
#if !defined(jpn)
    for (int i = 0; i < 3; i++) {
        CachedTextLabel_Init(&self->states1b0c[i]);
    }
#endif
    for (int i = 0; i < 8; i++) {
        CachedTextLabel_Init(&self->states1c5c[i]);
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
    func_ov000_0217feb0(self, 0, -1);
    func_ov000_0217feb0(self, 1, GameState_GetProtagonistIndex(gs));
    func_ov000_02174b14(self);
    self->f1d7c = 0;
    self->f1d78 = 0;
    self->f950 = 0;
    self->f954 = 0;
    self->f955 = 0;
    self->f956 = 0;
}
