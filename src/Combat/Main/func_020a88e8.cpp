#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_020a88e8_14092 = 0x34fc };
#else
enum { Enum_020a88e8_14092 = 0x370c };
#endif
struct Struct_020a88e8 { unsigned char pad0, key1, key2, pad3, pad4, unknown_5_, pad6, unknown_7_, key3, key4; };
struct Entry02019508 { unsigned short id, flags; signed char level:7; signed char other:1; };
struct Base02019508;
struct Struct_020a88e8_2 { char pad[3]; unsigned char unknown_3_; };
struct Struct_020a88e8_3 { char pad[Enum_020a88e8_14092]; Struct_020a88e8_2* trigger; };
extern "C" Base02019508* Zone3D_GetInstance();
extern "C" Entry02019508* Zone3D_FindSceneElement(Base02019508*, int, int);
extern "C" void func_020133b4(void*, int);
// USA: func_020a88e8
extern "C" ARM void func_020a88e8(Struct_020a88e8* self) {
    Base02019508* base = Zone3D_GetInstance();
    Entry02019508* first = Zone3D_FindSceneElement(base, self->key1, self->key2);
    Entry02019508* second = Zone3D_FindSceneElement(base, self->key3, self->key4);
    if (!first || !second) return;
    func_020133b4(first, 1);
    Struct_020a88e8_2* trigger = ((Struct_020a88e8_3*)GetGameResources())->trigger;
    if (self->unknown_5_) {
        unsigned char value = first->level;
        if (self->unknown_7_ || trigger->unknown_3_) { self->unknown_7_ = 0; value = 31; }
        else { value+=2; if (value > 31) value = 31; }
        first->level = (signed char)value;
    } else {
        if (self->unknown_7_ || trigger->unknown_3_) { first->level = 0; self->unknown_7_ = 0; }
        else if (first->level < 2) first->level = 0;
        else first->level = (signed char)(first->level-2);
    }
    if (first->level >= 10) second->flags|=4;
    else second->flags&=~4;
}
