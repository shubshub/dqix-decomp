#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"
#include "Resource/Script.h"

struct Struct_0201c1c8;

struct Struct_0201d530 {
    int unknown_0_;
    union { int unknown_0_; float unknown1_0_; } unknown_4_;
};

struct Element020de650;
struct ItemTable;
Element020de650* ItemTable_Find(struct ItemTable*, int);

struct Struct_ov023_021f5848 {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};

struct Struct_ov023_021f5848_2 {
    char unknown_0_[0xf8];
    short unknown_f8_;
    char unknown_fa_[2];
    unsigned short unknown_fc_;
    char unknown_fe_[0xe];
    struct Struct_ov023_021f5848 unknown_10c_;
};

struct Data021fff08_021f5848 {
    char pad0[1];
    unsigned char flag;
    char pad1[2];
    struct ItemTable* container;
    char pad2[4];
    struct Target021f5848* ptr;
};
extern struct Struct_ov023_021fff08_6 data_ov023_021fff08;

struct Struct_ov023_021f5848_3 { char unknown_0_[0x1a]; unsigned short unknown_1a_; };

// USA: func_ov023_021f5848
extern "C" ARM int func_ov023_021f5848(struct Struct_0201c1c8* arg0) {
    if (data_ov023_021fff08.unknown_1_ != 0) return 1;
    int var0 = ((Script::Parameter*)arg0)->ToInt();
    struct Struct_ov023_021f5848_2* var1 = data_ov023_021fff08.unknown_c_;
    if (var0 == var1->unknown_f8_) {
        if (data_ov023_021fff08.unknown_4_ == 0) {
            data_ov023_021fff08.unknown_1_ = 1;
            var1->unknown_10c_.unknown_0_0_ |= 2;
            return 0;
        }
        struct ElementHalf1a_021f5848* found = (struct ElementHalf1a_021f5848*)ItemTable_Find(data_ov023_021fff08.container, (short)v);
        if (found == 0) {
            data_ov023_021fff08.flag = 1;
            data_ov023_021fff08.ptr->bits.low13 |= 2;
            return 0;
        }
        GameState_GetParty(GameState::GetInstance());
        float a = ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)obj + 8)))->ToFloat();
        float b = ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)obj + 0x10)))->ToFloat();
        struct Random* rng = GetBTRandom();
        unsigned short half1a = found->half1a;
        float randVal = NextRandomFloatBetween(rng, a, b);
        int result = (int)((float)half1a * randVal);
        if (result >= data_ov023_021fff08.ptr->half0xfc || (data_ov023_021fff08.ptr->bits.low13 & 4) != 0) {
            data_ov023_021fff08.ptr->bits.low13 |= 1;
        } else {
            data_ov023_021fff08.unknown_c_->unknown_10c_.unknown_0_0_ |= 2;
        }
        data_ov023_021fff08.unknown_1_ = 1;
    }
    return 1;
}
