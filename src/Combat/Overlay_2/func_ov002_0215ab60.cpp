#include <globaldefs.h>
#include "GameState/GameState.h"

typedef unsigned char Type_020b1300;
typedef signed char Type_ov002_0215ab60;
typedef unsigned short u16;
typedef unsigned int u32;

struct ShortArrays0204c610 {
    Type_020b1300 pad0[0xc];
    short x[18];
    short y[18];
    short width[18];
    short height[18];
};
struct Elem_0205d81c : ShortArrays0204c610 {
    Type_020b1300 unknown_9c_[0xac - 0x9c];
    short xOrigin;
    short unknown_ae_;
    Type_020b1300 unknown_b0_[0xc5 - 0xb0];
    Type_020b1300 flags;
    Type_020b1300 unknown_c6_[0xe0 - 0xc6];
};
struct Struct_0205d81c {
    Type_020b1300 pad0[0x98];
    int active;
    Elem_0205d81c* entries;
    Type_020b1300 unknown_a0_[0xb3 - 0xa0];
    Type_020b1300 count;
    Type_020b1300 selected;
    Type_020b1300 unknown_b5_[3];
};
#if defined(jpn)
enum { WindowOffset = 0xe20, Enum_ov002_0215ab60_6760 = 0x19c0, Enum_ov002_0215ab60_7278 = 0x1b32,
       Enum_ov002_0215ab60_25 = 0x1a, Enum_ov002_0215ab60_24 = 0x19, Enum_ov002_0215ab60_18 = 0x14, Enum_ov002_0215ab60_21 = 0x17 };
#else
enum { WindowOffset = 0xec8, Enum_ov002_0215ab60_6760 = 0x1a68, Enum_ov002_0215ab60_7278 = 0x1c6e,
       Enum_ov002_0215ab60_25 = 0x19, Enum_ov002_0215ab60_24 = 0x18, Enum_ov002_0215ab60_18 = 0x12, Enum_ov002_0215ab60_21 = 0x15 };
#endif

struct Struct_ov002_0215ab60 {
    Type_020b1300 pad0[WindowOffset];
    Struct_0205d81c elements;
    Type_020b1300 unknown_f80_[Enum_ov002_0215ab60_6760 - WindowOffset - sizeof(Struct_0205d81c)];
    void* entryList;
    Type_020b1300 unknown_1a6c_[Enum_ov002_0215ab60_7278 - Enum_ov002_0215ab60_6760 - 4];
    Type_ov002_0215ab60 memberIds[5];
    Type_020b1300 count;
#if !defined(jpn)
    Type_020b1300 unknown_1c74_[0x245c - 0x1c74];
    short xOffset;
#endif
};
struct Struct_ov002_0215ab60_2 {
    Type_020b1300 pad0[0x3c];
    u32 : 30;
    u32 icon : 1;
    u32 : 1;
};
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c*, int);
extern "C" void func_0204c610(ShortArrays0204c610*, int, short*, short*, short*, short*);
extern "C" void func_ov002_02154bcc(int, int, void*, int, Type_020b1300, Type_020b1300);

#if !defined(jpn)
static inline short inline_ov002_0215ab60(Elem_0205d81c* entry) { SDK_NULL_ASSERT(entry); return entry->xOrigin; }
static inline short inline_ov002_0215ab60_2(Elem_0205d81c* entry) { SDK_NULL_ASSERT(entry); return entry->unknown_ae_; }
static inline short inline_ov002_0215ab60_3(Struct_ov002_0215ab60* self) { SDK_NULL_ASSERT(self); return self->xOffset; }

#endif

static inline int inline_ov002_0215ab60_4(const short* value, short origin) { SDK_NULL_ASSERT(value); return *value + origin; }
static inline short inline_ov002_0215ab60_5(short offset, short x) { return x + (offset + 3); }

// USA: func_ov002_0215ab60
// JPN: func_ov002_0215bf4c
extern "C" ARM void func_ov002_0215ab60(Struct_ov002_0215ab60* self) {
#if !defined(jpn)
    Elem_0205d81c* entry = func_0205d81c(&self->elements, 0x1a);
    if (entry && !(entry->flags & 0x20)) {
        short y = inline_ov002_0215ab60_2(entry) * 8;
        short x = inline_ov002_0215ab60(entry) * 8;
        short positionY = y + 3;
        short positionX = inline_ov002_0215ab60_5(inline_ov002_0215ab60_3(self), x);
        func_ov002_02154bcc(positionX, positionY, self->entryList, 0x2a, 0xc, 0xff);
    }
#endif
    if (!func_0205d81c(&self->elements, Enum_ov002_0215ab60_25)) {
        Elem_0205d81c* positions = func_0205d81c(&self->elements, Enum_ov002_0215ab60_24);
        if (positions) {
            GameState* gameState = GameState::GetInstance();
            GameState_GetParty(gameState);
            Type_020b1300 count = self->count;
            short originX = positions->xOrigin * 8;
            short originY = positions->unknown_ae_ * 8;
            for (Type_020b1300 i = 0; i < count; ++i) {
                Type_ov002_0215ab60 memberId = self->memberIds[i];
                GameObject* member = gameState->GetPartyMemberByIndex(memberId);
                if (member) {
                    short x, y, width, height;
                    short index = i + count + 1;
                    func_0204c610(positions, index, &x, &y, &width, &height);
                    int positionX = inline_ov002_0215ab60_4(&x, originX);
                    int positionY = inline_ov002_0215ab60_4(&y, originY);
                    u16 icon = ((Struct_ov002_0215ab60_2*)member->baseStats_)->icon;
                    icon = icon + Enum_ov002_0215ab60_18;
                    func_ov002_02154bcc(positionX, positionY, self->entryList, icon, (Type_020b1300)(i + 0x4c), 0xff);
                    func_0204c610(positions, (short)(index + count + 1), &x, &y, &width, &height);
                    func_ov002_02154bcc(x + originX, y + originY, self->entryList, Enum_ov002_0215ab60_21, (Type_020b1300)(memberId + 0x50), (Type_020b1300)(memberId + 9));
                }
            }
        }
    }
}
