#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"
#include "Resource/GridCursor.h"

struct InitTarget0205cfd4 { char pad[0xbc]; };
struct Struct_02092aa4 { char pad[0x3c]; };
#if defined(jpn)
struct State0xc0cc { char pad[0x38]; };
enum { Enum_ov000_021723a8_1096 = 0x488, Enum_ov000_021723a8_9 = 5 };
#else
struct State0xc0cc { char pad[0x18]; };
enum { Enum_ov000_021723a8_1096 = 0x448, Enum_ov000_021723a8_9 = 9 };
#endif

extern "C" void ItemTable_Init(void* obj);
extern "C" void Background_Init(struct BackgroundGraphics* obj);
extern "C" void Window_Init(struct InitTarget0205cfd4* obj);
extern "C" void GridCursor_Init(struct GridCursor* obj);
extern "C" void WindowPane_Init(void* obj);
extern "C" void func_02092aa4(Struct_02092aa4* obj, int mode);
extern "C" void SpriteContext_Init(char* obj);
extern "C" void* LinkSession_GetInstance(GameState* gs);
extern "C" int GameState_GetProtagonistIndex(GameState* gs);
extern "C" void CachedTextLabel_Init(struct State0xc0cc* obj);

struct Struct_ov000_021723a8;
extern "C" void func_ov000_0217228c(struct Struct_ov000_021723a8* obj);
extern "C" void func_ov000_0216ff28(void* entry);
extern "C" void func_ov000_0217feb0(struct Struct_ov000_021723a8* obj, unsigned char value, int id);
extern "C" void func_ov000_02174b14(struct Struct_ov000_021723a8* obj);

struct Struct_ov000_021723a8_2 {
    void* f0;
    void* f4;
    char pad8[0x38 - 0x8];
    void* unknown_38_;
    char unknown_3c_[0x44 - 0x3c];
    int unknown_44_;
    int unknown_48_;
    char unknown_4c_[Enum_ov000_021723a8_1096 - 0x4c];
};

struct Struct_ov000_021723a8 {
    char pad0[0x20];
    int f20;
    char pad24[0x68 - 0x24];
    int f68;
    signed char order[4];
    char unknown_70_[0x7c - 0x70];
    struct Struct_02092aa4 unknown_7c_;
    char unknown_b8_[0xd0 - 0xb8];
    char listD0[0xe8 - 0xd0];
    char listE8[0x11c - 0xe8];
    char obj11c[0x170 - 0x11c];
    int unknown_170_;
    int unknown_174_;
    int unknown_178_;
    int unknown_17c_;
    volatile unsigned short unknown_180_;
    volatile unsigned short unknown_182_;
    int unknown_184_;
    struct InitTarget0205cfd4 obj188;
    char unknown_244_[0x244 - 0x188 - sizeof(struct InitTarget0205cfd4)];
    struct GridCursor obj244;
    char pad284[0x284 - 0x244 - sizeof(struct GridCursor)];
    char slots284[7][0xe0];
    struct BackgroundGraphics lists[3];
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
    struct Struct_ov000_021723a8_2 entries[4];
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
    struct State0xc0cc states1b0c[3];
#endif
    struct State0xc0cc state1b54;
    struct State0xc0cc state1b6c;
    struct State0xc0cc states1b84[Enum_ov000_021723a8_9];
    struct State0xc0cc states1c5c[8];
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
    int f0;
    int limit;
    struct Struct_ov000_021723a8* battle;
};
extern struct Struct_ov000_02184288_3 data_ov000_02184288;

// USA: func_ov000_021723a8
extern "C" ARM void func_ov000_021723a8(struct Struct_ov000_021723a8* self, int arg) {
    self->f20 = -1;
    self->unknown_1a78_.ResetAllocatorPointer();
    self->unknown_1a8c_.ResetAllocatorPointer();
    self->unknown_1ab4_.ResetAllocatorPointer();
    self->unknown_1aa0_.ResetAllocatorPointer();
    self->unknown_1ac8_.ResetAllocatorPointer();
    self->unknown_1adc_.ResetAllocatorPointer();
    self->unknown_1af8_.ResetAllocatorPointer();
    ItemTable_Init(self->listD0);
    ItemTable_Init(self->listE8);
    data_ov000_02184288.battle = self;
    self->f68 = 0;
    self->unknown_178_ = 0;
    self->unknown_17c_ = -1;
    self->unknown_1d72_ = 0;
    self->unknown_1d72_ |= 2;
    self->unknown_184_ = 0;
    {
        volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
        volatile short v0, v1;
        {
            unsigned short raw = reg[0];
            v0 = raw;
            self->unknown_180_ = raw;
            v0;
        }
        {
            unsigned short raw = reg[1];
            v1 = raw;
            self->unknown_182_ = raw;
            v1;
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
    self->unknown_1af0_ = arg;
    func_02092aa4(&self->unknown_7c_, 0);
    SpriteContext_Init(self->obj11c);
    self->unknown_170_ = 0;
    self->unknown_174_ = 0;
    self->unknown_910_ = 0;
    self->unknown_934_ = 0;
    self->unknown_908_ = 0;
    self->unknown_90c_ = -1;
    self->unknown_914_ = 0;
    self->unknown_918_ = 0;
    self->unknown_91c_ = 0;
    self->unknown_920_ = 0x100;
    self->unknown_924_ = 0x100;
    self->unknown_928_ = 0x100;
    self->unknown_92c_ = 0;
    self->unknown_1d5e_ = 0x10;
    self->unknown_93c_ = 0;
    self->unknown_940_ = 0;
    self->unknown_944_ = 0;
    memset(self->unknown_1d60_, 0, 8);
    self->unknown_1d68_ = 0;
    self->unknown_1d60_[self->unknown_1d68_] = 1;
    self->unknown_1d69_ = 0;
    self->unknown_1d6b_ = -1;
    self->unknown_1d6c_ = -1;
    self->unknown_1d6e_ = -1;
    self->unknown_1d6f_ = -1;
    self->unknown_1d70_ = 0;
    self->unknown_1d79_ = 1;
    self->unknown_1d80_ = 0;
    self->unknown_1d81_ = 0;
    self->unknown_1d5c_ = 0;
    self->unknown_1d7a_ = 0;
    GameState* gs = GameState::GetInstance();
    LinkSession_GetInstance(gs);
    int id = GameState_GetProtagonistIndex(gs);
    if (id < 0) {
        id = 0;
    }
    self->unknown_17c_ = id;
    func_ov000_0217228c(self);
    CachedTextLabel_Init(&self->state1b54);
    CachedTextLabel_Init(&self->state1b6c);
    for (int i = 0; i < Enum_ov000_021723a8_9; i++) {
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
    struct Struct_ov000_021723a8_2* e;
    for (int i = 0; i < 4; i++) {
        e = &self->entries[self->order[i]];
        func_ov000_0216ff28(e);
        e->unknown_44_ = 0;
        e->unknown_48_ = 0;
        e->unknown_38_ = &self->obj188;
        e->f4 = self->unknown_b8_;
        e->f0 = self->listD0;
    }
    func_ov000_0217feb0(self, 0, -1);
    func_ov000_0217feb0(self, 1, GameState_GetProtagonistIndex(gs));
    func_ov000_02174b14(self);
    self->unknown_1d7c_ = 0;
    self->unknown_1d78_ = 0;
    self->unknown_950_ = 0;
    self->unknown_954_ = 0;
    self->unknown_955_ = 0;
    self->unknown_956_ = 0;
}
