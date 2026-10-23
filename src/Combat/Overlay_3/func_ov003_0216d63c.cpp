#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "World/Object3D.h"

#if defined(jpn)
enum { Enum_ov003_0216d63c_1040 = 0x428 };
enum { Enum_ov003_0216d63c_2016 = 0x768 };
enum { Enum_ov003_0216d63c_3848 = 0xd8c };
enum { Enum_ov003_0216d63c_4708 = 0x10f4 };
enum { Enum_ov003_0216d63c_3852 = 0xd90 };
enum { Enum_ov003_0216d63c_4800 = 0x1150 };
enum { Enum_ov003_0216d63c_4716 = 0x10fc };
enum { Enum_ov003_0216d63c_5128 = 0x1298 };
enum { Enum_ov003_0216d63c_5119 = 0x128f };
#else
enum { Enum_ov003_0216d63c_1040 = 0x410 };
enum { Enum_ov003_0216d63c_2016 = 0x7e0 };
enum { Enum_ov003_0216d63c_3848 = 0xf08 };
enum { Enum_ov003_0216d63c_4708 = 0x1264 };
enum { Enum_ov003_0216d63c_3852 = 0xf0c };
enum { Enum_ov003_0216d63c_4800 = 0x12c0 };
enum { Enum_ov003_0216d63c_4716 = 0x126c };
enum { Enum_ov003_0216d63c_5128 = 0x1408 };
enum { Enum_ov003_0216d63c_5119 = 0x13ff };
#endif

struct Struct_0201099c_14 {
	char unknown_0_[0x18];
};
struct Struct_020a9ea4 {
	char unknown_0_[8];
};

void SpriteContext_Init(char* obj);
void KeyTable_Reset(struct Struct020dfc40* p);
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern "C" void func_ov003_0215c650(void* obj);
extern "C" void func_ov003_0216ffbc(void* obj);
extern "C" void func_ov003_02170b74(void* obj);

struct Struct_ov003_0216d63c {
	unsigned int unknown_0_;
	unsigned short unknown_4_;
	unsigned short unknown_6_;
	unsigned short unknown_8_;
	unsigned short unknown_a_;
	int unknown_c_;
	int unknown_10_;
	char unknown_14_[Enum_ov003_0216d63c_1040 - 0x14];
	char unknown_410_[Enum_ov003_0216d63c_2016 - Enum_ov003_0216d63c_1040];
	char unknown_7e0_[Enum_ov003_0216d63c_3848 - Enum_ov003_0216d63c_2016];
	void* unknown_f08_;
	char unknown_f0c_[Enum_ov003_0216d63c_4708 - Enum_ov003_0216d63c_3852];
	int unknown_1264_;
	int unknown_1268_;
	char unknown_126c_[Enum_ov003_0216d63c_4800 - Enum_ov003_0216d63c_4716];
	int unknown_12c0_;
	int unknown_12c4_;
	int unknown_12c8_;
	int unknown_12cc_;
	int unknown_12d0_;
	SafeAllocator unknown_12d4_[4];
	struct Struct_0201099c_14 unknown_1324_;
	Object3D unknown_133c_;
	unsigned char unknown_13e8_;
	unsigned char unknown_13e9_;
	unsigned char unknown_13ea_;
	unsigned char unknown_13eb_;
	unsigned char unknown_13ec_;
	unsigned char unknown_13ed_;
	unsigned char unknown_13ee_;
	unsigned char unknown_13ef_;
	int unknown_13f0_;
	int unknown_13f4_;
	char unknown_13f8_[4];
	signed char unknown_13fc_[3];
	char unknown_13ff_[Enum_ov003_0216d63c_5128 - Enum_ov003_0216d63c_5119];
	int unknown_1408_;
	struct Struct_020a9ea4 unknown_140c_;
};

// USA: func_ov003_0216d63c
extern "C" ARM void func_ov003_0216d63c(struct Scene0216d63c* self) {
	self->savedPlanes = (DISPCNT & 0x1f00) >> 8;
	self->field4 = 0;
	self->field6 = 0;
	self->field8 = 0;
	self->field13ec = 0;
	self->fieldA = 0;
	self->fieldC = 0;
	self->field10 = 0;
	func_ov003_0215c650(self->sub14);
	func_ov003_0216ffbc(self->sub410);
	func_ov003_02170b74(self->sub7e0);
	self->activeSub = self->sub410;
	self->field1264 = 0;
	self->field1268 = 0;
	SpriteContext_Init(self->sub126c);
	self->field12c0 = 0;
	self->field12c4 = 0;
	self->field12c8 = 0;
	self->field12cc = 0;
	self->field12d0 = 0;
	self->allocs[0].ResetAllocatorPointer();
	self->allocs[1].ResetAllocatorPointer();
	self->allocs[2].ResetAllocatorPointer();
	self->allocs[3].ResetAllocatorPointer();
	KeyTable_Reset(&self->texts);
	self->object.Initialize();
	self->field13e8 = 0;
	self->field13e9 = 0;
	self->field13ea = 0;
	self->field13eb = 1;
	self->field13ef = 0;
	self->field13f0 = 0;
	self->field13ee = 0;
	self->field13f4 = -1;
	memset(self->field13fc, -1, 3);
	self->field1408 = 0;
	self->field13ed = 0;
	ClearStruct020a9ea4(&self->field140c);
}
