#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Struct_0201d530 {
    int type;
    union { int i; float f; } value;
};

struct Element020de650;
struct ItemTable;
extern "C" Element020de650* ItemTable_Find(struct ItemTable*, int);

struct Struct_ov023_021f5848 {
    unsigned short unknown_0_0_ : 13;
    unsigned short unknown_1_5_ : 3;
};

struct Struct_ov023_021f5848_2 {
    char pad0[0xf8];
    short unknown_f8_;
    char pad1[2];
    unsigned short unknown_fc_;
    char pad2[0xe];
    struct Struct_ov023_021f5848 bits;
};

struct Struct_ov023_021fff08_6 {
    char pad0[1];
    unsigned char flag;
    char pad1[2];
    struct ItemTable* container;
    char pad2[4];
    struct Struct_ov023_021f5848_2* ptr;
};
extern struct Struct_ov023_021fff08_6 data_ov023_021fff08;

struct ElementHalf1a_021f5848 { char pad[0x1a]; unsigned short unknown_1a_; };

// USA: func_ov023_021f5848
extern "C" ARM int func_ov023_021f5848(struct Variant02030b0c* obj) {
    if (data_ov023_021fff08.flag != 0) return 1;
    int v = ((Script::Parameter*)obj)->ToInt();
    struct Struct_ov023_021f5848_2* ptr = data_ov023_021fff08.ptr;
    if (v == ptr->unknown_f8_) {
        if (data_ov023_021fff08.container == 0) {
            data_ov023_021fff08.flag = 1;
            ptr->bits.unknown_0_0_ |= 2;
            return 0;
        }
        struct ElementHalf1a_021f5848* found = (struct ElementHalf1a_021f5848*)ItemTable_Find(data_ov023_021fff08.container, (short)v);
        if (found == 0) {
            data_ov023_021fff08.flag = 1;
            data_ov023_021fff08.ptr->bits.unknown_0_0_ |= 2;
            return 0;
        }
        GameState_GetParty(GameState::GetInstance());
        float a = ((Script::Parameter*)((struct Struct_0201d530*)((char*)obj + 8)))->ToFloat();
        float b = ((Script::Parameter*)((struct Struct_0201d530*)((char*)obj + 0x10)))->ToFloat();
        struct Random* rng = GetBTRandom();
        unsigned short var6 = found->unknown_1a_;
        float var7 = NextRandomFloatBetween(rng, a, b);
        int result = (int)((float)var6 * var7);
        if (result >= data_ov023_021fff08.ptr->unknown_fc_ || (data_ov023_021fff08.ptr->bits.unknown_0_0_ & 4) != 0) {
            data_ov023_021fff08.ptr->bits.unknown_0_0_ |= 1;
        } else {
            data_ov023_021fff08.ptr->bits.unknown_0_0_ |= 2;
        }
        data_ov023_021fff08.flag = 1;
    }
    return 1;
}
