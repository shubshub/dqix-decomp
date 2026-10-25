#include <globaldefs.h>
#include "GameState/GameState.h"

typedef unsigned char Type_020b1300;
typedef signed char Type_ov002_0215ab60;
typedef unsigned short Type_020b0a1c;
typedef unsigned int Type_020b11c8;

struct Struct_0204c610 {
    Type_020b1300 unknown_0_[0xc];
    short unknown_c_[18];
    short unknown_30_[18];
    short unknown_54_[18];
    short unknown_78_[18];
};
struct Struct_0205d0e0 : Struct_0204c610 {
    Type_020b1300 unknown_9c_[0xac - 0x9c];
    short unknown_ac_;
    short unknown_ae_;
    Type_020b1300 unknown_b0_[0xc5 - 0xb0];
    Type_020b1300 unknown_c5_;
    Type_020b1300 unknown_c6_[0xe0 - 0xc6];
};
struct Struct_0205d81c {
    Type_020b1300 unknown_0_[0x98];
    int unknown_98_;
    Struct_0205d0e0* unknown_9c_;
    Type_020b1300 unknown_a0_[0xb3 - 0xa0];
    Type_020b1300 unknown_b3_;
    Type_020b1300 unknown_b4_;
    Type_020b1300 unknown_b5_[3];
};
#if defined(jpn)
enum { Enum_ov002_0215ab60_3784 = 0xe20, Enum_ov002_0215ab60_6760 = 0x19c0, Enum_ov002_0215ab60_7278 = 0x1b32,
       Enum_ov002_0215ab60_25 = 0x1a, Enum_ov002_0215ab60_24 = 0x19, Enum_ov002_0215ab60_18 = 0x14, Enum_ov002_0215ab60_21 = 0x17 };
#else
enum { Enum_ov002_0215ab60_3784 = 0xec8, Enum_ov002_0215ab60_6760 = 0x1a68, Enum_ov002_0215ab60_7278 = 0x1c6e,
       Enum_ov002_0215ab60_25 = 0x19, Enum_ov002_0215ab60_24 = 0x18, Enum_ov002_0215ab60_18 = 0x12, Enum_ov002_0215ab60_21 = 0x15 };
#endif

struct Struct_ov002_0215ab60 {
    Type_020b1300 unknown_0_[Enum_ov002_0215ab60_3784];
    Struct_0205d81c unknown_ec8_;
    Type_020b1300 unknown_f80_[Enum_ov002_0215ab60_6760 - Enum_ov002_0215ab60_3784 - sizeof(Struct_0205d81c)];
    void* unknown_1a68_;
    Type_020b1300 unknown_1a6c_[Enum_ov002_0215ab60_7278 - Enum_ov002_0215ab60_6760 - 4];
    Type_ov002_0215ab60 unknown_1c6e_[5];
    Type_020b1300 unknown_1c73_;
#if !defined(jpn)
    Type_020b1300 unknown_1c74_[0x245c - 0x1c74];
    short unknown_245c_;
#endif
};
struct Struct_ov002_0215ab60_2 {
    Type_020b1300 unknown_0_[0x3c];
    Type_020b11c8 : 30;
    Type_020b11c8 unknown_3f_6_ : 1;
    Type_020b11c8 : 1;
};
extern "C" Struct_0205d0e0* func_0205d81c(Struct_0205d81c*, int);
extern "C" void func_0204c610(Struct_0204c610*, int, short*, short*, short*, short*);
extern "C" void func_ov002_02154bcc(int, int, void*, int, Type_020b1300, Type_020b1300);

#if !defined(jpn)
static inline short inline_ov002_0215ab60(Struct_0205d0e0* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_ac_; }
static inline short inline_ov002_0215ab60_2(Struct_0205d0e0* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_ae_; }
static inline short inline_ov002_0215ab60_3(Struct_ov002_0215ab60* arg0) { SDK_NULL_ASSERT(arg0); return arg0->unknown_245c_; }

#endif

static inline int inline_ov002_0215ab60_4(const short* arg0, short arg1) { SDK_NULL_ASSERT(arg0); return *arg0 + arg1; }
static inline short inline_ov002_0215ab60_5(short arg0, short arg1) { return arg1 + (arg0 + 3); }

// USA: func_ov002_0215ab60
// JPN: func_ov002_0215bf4c
extern "C" ARM void func_ov002_0215ab60(Struct_ov002_0215ab60* arg0) {
#if !defined(jpn)
    Struct_0205d0e0* var0 = func_0205d81c(&arg0->unknown_ec8_, 0x1a);
    if (var0 && !(var0->unknown_c5_ & 0x20)) {
        short var1 = inline_ov002_0215ab60_2(var0) * 8;
        short var2 = inline_ov002_0215ab60(var0) * 8;
        short var3 = var1 + 3;
        short var4 = inline_ov002_0215ab60_5(inline_ov002_0215ab60_3(arg0), var2);
        func_ov002_02154bcc(var4, var3, arg0->unknown_1a68_, 0x2a, 0xc, 0xff);
    }
#endif
    if (!FindElementByC40205d81c(&self->elements, BlockingKey)) {
        Elem_0205d81c* positions = FindElementByC40205d81c(&self->elements, PositionsKey);
        if (positions) {
            GameState* gameState = GameState::GetInstance();
            GameState_GetParty(gameState);
            u8 count = self->count;
            short originX = positions->xOrigin * 8;
            short originY = positions->yOrigin * 8;
            for (u8 i = 0; i < count; ++i) {
                s8 memberId = self->memberIds[i];
                GameObject* member = gameState->GetPartyMemberByIndex(memberId);
                if (member) {
                    short x, y, width, height;
                    short index = i + count + 1;
                    GetFourShortsAtIndex(positions, index, &x, &y, &width, &height);
                    int positionX = AddOrigin(&x, originX);
                    int positionY = AddOrigin(&y, originY);
                    u16 icon = ((FormationCombatStats*)member->baseStats_)->icon;
                    icon = icon + FirstIcon;
                    SetEntryFields02154bcc(positionX, positionY, self->entryList, icon, (u8)(i + 0x4c), 0xff);
                    GetFourShortsAtIndex(positions, (short)(index + count + 1), &x, &y, &width, &height);
                    SetEntryFields02154bcc(x + originX, y + originY, self->entryList, SecondIcon, (u8)(memberId + 0x50), (u8)(memberId + 9));
                }
            }
        }
    }
}
