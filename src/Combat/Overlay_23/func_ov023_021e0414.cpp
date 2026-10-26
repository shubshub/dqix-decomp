#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct ItemTable;
struct Element020de650_021e0414 {
    char pad0[8];
    unsigned int nibble : 4;
    unsigned int unknown_8_4_ : 28;
};
extern "C" Element020de650_021e0414* ItemTable_Find(struct ItemTable*, int);

extern "C" void func_ov023_021e20c0(void*);


extern int data_ov023_021fdc4c;
extern int data_ov023_021fdc61;

struct Struct_ov023_021e0414_2 {
    char pad0[0x48];
    ItemTable* field48;
    Element020de650_021e0414* field4c;
#if defined(jpn)
    char unknown_50_[0x6b8 - 0x50];
#else
    char unknown1_50_[0x73c - 0x50];
#endif

    int unknown_73c_;
    char unknown_740_[0x770 - 0x740];
    short field770;
    char unknown_772_[0x79a - 0x772];
    signed char unknown_79a_;
};

// USA: func_ov023_021e0414
extern "C" ARM int func_ov023_021e0414(struct Struct_ov023_021e0414_2* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    if (obj->field48 != NULL) {
        obj->field4c = ItemTable_Find(obj->field48, obj->field770);
    }
    Element020de650_021e0414* elem = obj->field4c;
    if (elem != NULL) {
        unsigned int nibble = elem->nibble;
        int var3 = (nibble <= 7);
        signed char flag = (var3 != 0);
        signed char b = obj->unknown_79a_;
        if (b != flag) {
            func_ov023_021e20c0((char*)obj + 0xcc);
            elem = obj->field4c;
            unsigned int var6 = elem->nibble;
            int var7 = (var6 <= 7);
            if (var7) {
                obj->unknown_73c_ = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&data_ov023_021fdc4c), (SafeAllocator*)(0));
            } else {
                obj->unknown_73c_ = ((BackgroundLoader*)(a))->QueueLoadFile((const char*)((int)&data_ov023_021fdc61), (SafeAllocator*)(0));
            }
        }
    }
    return 6;
}
