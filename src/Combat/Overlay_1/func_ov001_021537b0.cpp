#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct ResetStruct;
struct StreamState;
struct StreamHeader;
struct Struct_0201f040_3;

struct Struct_ov001_02165800_3 { int word0; SafeAllocator* unknown_4_; void* selfPtr; };
extern Struct_ov001_02165800_3 data_ov001_02165800;
extern int data_ov001_02164b80;
extern int data_ov001_02164b90;

struct Struct_ov001_021537b0 { int field0; int field4; };

// USA: func_ov001_021537b0
extern "C" ARM void func_ov001_021537b0(Struct_ov001_021537b0* self, SafeAllocator* alloc, struct StreamHeader* buffer, int length) {
    char local[0x430];
    self->field0 = 0;
    self->field4 = 0;
    data_ov001_02165800.word0 = 0;
    data_ov001_02165800.unknown_4_ = alloc;
    data_ov001_02165800.selfPtr = self;

    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov001_02164b80);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();

    self->field4 = data_ov001_02165800.word0;
    data_ov001_02165800.word0 = 0;
    void* mem = alloc->Allocate(self->field4 * 8);
    self->field0 = (int)mem;
    if (mem == NULL) {
        self->field4 = 0;
        return;
    }

    ((Script*)((struct ResetStruct*)local))->Initialize();
    ((Script*)((struct ResetStruct*)local))->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_ov001_02164b90);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct_0201f040_3*)local))->Execute();
}
