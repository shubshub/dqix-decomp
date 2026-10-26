#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/FieldTask.h"

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

// Overlay 17, originally InitObj_021adc58 (USA/EUR 0x021adc58, JPN 0x021ae460)
extern "C" ARM void FieldTask_InitOpenChest(OpenChestTask* self) {
	func_0204693c((struct ByteHeader0204693c*)self);
	self->kind = FieldTaskKind_OpenChest;
	self->step = OpenChestStep_Start;
	self->timer = 0;
	self->chestIndex = 0;
	self->delay = 0xf;
	self->fromZoneList = 0;
	self->ambush = 0;
	self->unknown28 = 0;
	self->unknown24 = 0;
	self->position.x = 0;
	self->position.y = 0;
	self->position.z = 0;
	self->special = 0;
	self->allocator.ResetAllocatorPointer();
}
