#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct ItemTable;
struct Element020de650_021e0414 {
    char pad0[8];
    unsigned int nibble : 4;
    unsigned int restBits : 28;
};
Element020de650_021e0414* ItemTable_Find(struct ItemTable*, int);

extern "C" void func_ov023_021e20c0(void*);


extern int data_ov023_021fdc4c;
extern int data_ov023_021fdc61;

struct Obj021e0414 {
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
    short unknown_770_;
    char unknown_772_[0x79a - 0x772];
    signed char unknown_79a_;
};

// USA: func_ov023_021e0414  (semantic: RefreshEntryElementAndDispatch_021e0414)
extern "C" ARM int func_ov023_021e0414(struct Obj021e0414* obj) {
    int a = (int)BackgroundLoader::GetInstance();
    if (obj->field48 != NULL) {
        obj->field4c = ItemTable_Find(obj->field48, obj->field770);
    }
    Struct_ov023_021e0414* var1 = arg0->unknown_4c_;
    if (var1 != NULL) {
        unsigned int var2 = var1->unknown_8_0_;
        int var3 = (var2 <= 7);
        signed char var4 = (var3 != 0);
        signed char var5 = arg0->unknown_79a_;
        if (var5 != var4) {
            func_ov023_021e20c0((char*)arg0 + 0xcc);
            var1 = arg0->unknown_4c_;
            unsigned int var6 = var1->unknown_8_0_;
            int var7 = (var6 <= 7);
            if (var7) {
                arg0->unknown_73c_ = ((BackgroundLoader*)(var0))->QueueLoadFile((const char*)((int)&data_ov023_021fdc4c), (SafeAllocator*)(0));
            } else {
                arg0->unknown_73c_ = ((BackgroundLoader*)(var0))->QueueLoadFile((const char*)((int)&data_ov023_021fdc61), (SafeAllocator*)(0));
            }
        }
    }
    return 6;
}
