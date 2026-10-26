#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamHeader;
struct StreamState;

struct Struct_0201f040_3;

struct Struct_ov028_021d9ac0 { unsigned int key; int val; };
struct Struct_ov028_021d98e0 { int count; struct Struct_ov028_021d9ac0* list; };

struct Struct_ov028_021d9bc4_3 {
    void* field0;
    SafeAllocator* field4;
};
extern Struct_ov028_021d9bc4_3 data_ov028_021d9bc4;
extern struct Struct_ov028_021d9ac0 data_ov028_021d9ac0;

struct Struct_ov028_021d98e0_2 {
    char pad0[4];
    int field4;
    short field8;
};

// USA: func_ov028_021d98e0
extern "C" ARM void func_ov028_021d98e0(Struct_ov028_021d98e0_2* self, SafeAllocator* alloc, struct StreamHeader* header, int length) {
    char local[0x430];
    self->field4 = 0;
    self->field8 = 0;
    data_ov028_021d9bc4.field4 = alloc;
    data_ov028_021d9bc4.field0 = self;
    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct Struct_ov028_021d98e0*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov028_021d9ac0);
    ((Script*)((struct StreamState*)local))->Load(header, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
