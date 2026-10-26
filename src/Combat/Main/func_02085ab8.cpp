#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_0201137c(char* base, int id);

struct Struct_02085ab8 {
    unsigned char pad[0x18];
    unsigned int unknown_18_0_ : 12;
    unsigned int category : 4;
    unsigned int unknown_1a_0_ : 16;
};

struct Struct_02085ab8_2 {
    unsigned int unknown_0_0_ : 4;
    unsigned int unknown_0_4_ : 5;
    unsigned int unknown_1_1_ : 23;
};

struct Struct_020e8c00 {
    int key;
    int val;
};
extern struct Struct_020e8c00 data_020e8c00[];

#if defined(jpn)
enum { Enum_02085ab8_2296 = 0x860 };
#else
enum { Enum_02085ab8_2296 = 0x8f8 };
#endif

// USA: func_02085ab8
extern "C" ARM int func_02085ab8(unsigned char* actor, struct Struct_02085ab8* p2) {
    GameState* bs = GameState::GetInstance();
    unsigned int category = p2->category;
    if (category == 2) {
        if ((actor[Enum_02085ab8_2296] & 0x80) == 0) {
            return 0;
        }
        return func_0201137c((char*)bs, 0x67);
    }

    int threshold = 0x21;
    if (*(short*)(actor + 0x2ac) > 0) {
        threshold = ((struct Struct_02085ab8_2*)(actor + 0x29c))->unknown_0_4_;
    }

    int matched = -1;
    struct Struct_020e8c00* entry = data_020e8c00;
    while (entry->key != matched) {
        if (entry->key == threshold) {
            matched = (short)entry->val;
            break;
        }
        entry++;
    }

    int total = 0;
    if (matched != -1) {
        if (func_02083b00(actor, matched)) {
            total += func_0201137c((char*)bs, matched);
        }
    }
    return total;
}
