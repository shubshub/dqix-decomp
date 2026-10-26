#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

struct Struct_02092aa4 {
    SafeAllocator allocator;
    char unknown_14_[0x2c - 0x14];
    int field2c;
    short unknown_30_;
    short field32;
    unsigned char field34;
    unsigned char unknown_35_;
    unsigned char unknown_36_;
    unsigned char unknown_37_;
    unsigned char field38;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
};

// USA: func_02092aa4
extern "C" ARM void func_02092aa4(Struct_02092aa4* obj, int param) {
    obj->allocator.ResetAllocatorPointer();
    KeyTable_Reset((struct Struct020dfc40*)((char*)obj + 0x14));

    obj->field2c = -1;
    obj->unknown_30_ = -1;
    obj->field32 = 0;
    obj->field34 = 0;
    obj->unknown_35_ = 0;
    obj->unknown_36_ = 0;
    obj->unknown_37_ = 0;
    obj->field38 = param;
    obj->unknown_39_ = 0;
    obj->unknown_3a_ = 0;
    obj->unknown_3b_ = 0;

    unsigned char* base = (unsigned char*)GameState_GetParty(GameState::GetInstance());
    unsigned char i;
    for (i = 0; i < base[0xf7c]; i++) {
        unsigned char* entry = base + i;
        if (entry[0xf78] == 0) {
            obj->unknown_37_ |= 1;
            return;
        }
    }
}
