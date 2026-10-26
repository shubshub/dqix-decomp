#include <globaldefs.h>

struct Struct_0204166c;
#if defined(jpn)
extern "C" void func_02041bbc(struct Struct_0204166c* s);
#define func_020416c0 func_02041bbc
#else
extern "C" void func_020416c0(struct Struct_0204166c* s);
#endif

struct Foo0207df50;
extern "C" void VramState_Rewind(struct Foo0207df50* p);

struct CombatSlots02045cac {
#if defined(jpn)
    char pad0[0x884];
#else
    char pad0[0x9b4];
#endif
    int field9b4;
    unsigned char unknown_9b8_[0xe00];
    unsigned char unknown_17b8_[0x80];
#if defined(jpn)
    char unknown_1708_[0x17e0 - 0x1708];
#else
    char unknown_1838_[0x19b0 - 0x1838];
#endif
    unsigned char unknown_19b0_;
#if defined(jpn)
    char unknown_17e1_[0x1c4c - 0x17e1];
#else
    char unknown_19b1_[0x1e28 - 0x19b1];
#endif
    void* ptrField;
};

// Main, originally InitCombatSlots02045cac (USA 0x02045cac, EUR 0x02045cbc, JPN 0x02046948)
extern "C" ARM void MessageSystem_ResetGlyphs(struct CombatSlots02045cac* obj) {
    obj->unknown_19b0_ = 1;
#if defined(jpn)
    obj->field9b4 = 14;
#else
    obj->field9b4 = 0;
#endif
#if defined(jpn)
    for (int i = 14; i < 0x80; i++) {
#else
    for (int i = 0; i < 0x80; i++) {
#endif
        func_020416c0((struct Struct_0204166c*)(obj->unknown_9b8_ + i * 0x1c));
        obj->unknown_17b8_[i] = 0;
    }
    if (obj->ptrField != NULL) {
        VramState_Rewind((struct Foo0207df50*)obj->ptrField);
    }
}
