#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_020a88e8_14092 = 0x34fc };
#else
enum { Enum_020a88e8_14092 = 0x370c };
#endif
struct Obj020a88e8 { unsigned char pad0, key1, key2, pad3, pad4, increase, pad6, instant, key3, key4; };
struct Entry02019508 { unsigned short id, flags; signed char level:7; signed char other:1; };
struct Base02019508;
struct Trigger020a88e8 { char pad[3]; unsigned char instant; };
struct Manager020a88e8 { char pad[kManagerPrefix]; Trigger020a88e8* trigger; };
extern "C" Base02019508* Zone3D_GetInstance();
Entry02019508* FindEntryByKeys02019508(Base02019508*, int, int);
void SetFlag0x80_020133b4(void*, int);
// USA: func_020a88e8
extern "C" ARM void func_020a88e8(Obj020a88e8* self) {
    Base02019508* base = Zone3D_GetInstance();
    Entry02019508* first = FindEntryByKeys02019508(base, self->key1, self->key2);
    Entry02019508* second = FindEntryByKeys02019508(base, self->key3, self->key4);
    if (!first || !second) return;
    SetFlag0x80_020133b4(first, 1);
    Trigger020a88e8* trigger = ((Manager020a88e8*)GetGameResources())->trigger;
    if (self->increase) {
        unsigned char value = first->level;
        if (self->instant || trigger->instant) { self->instant = 0; value = 31; }
        else { value+=2; if (value > 31) value = 31; }
        first->level = (signed char)value;
    } else {
        if (arg0->unknown_7_ || var3->unknown_3_) { var1->unknown_4_0_ = 0; arg0->unknown_7_ = 0; }
        else if (var1->unknown_4_0_ < 2) var1->unknown_4_0_ = 0;
        else var1->unknown_4_0_ = (signed char)(var1->unknown_4_0_-2);
    }
    if (var1->unknown_4_0_ >= 10) var2->unknown_2_|=4;
    else var2->unknown_2_&=~4;
}
