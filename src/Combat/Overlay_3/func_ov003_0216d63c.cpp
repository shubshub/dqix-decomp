#include <globaldefs.h>
#include "Resource/KeyTable.h"
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
enum { kRegionValue126C_10FC = 0x10fc };
enum { Enum_ov003_0216d63c_5128 = 0x1298 };
enum { Enum_ov003_0216d63c_5119 = 0x128f };
#else
enum { Enum_ov003_0216d63c_1040 = 0x410 };
enum { Enum_ov003_0216d63c_2016 = 0x7e0 };
enum { Enum_ov003_0216d63c_3848 = 0xf08 };
enum { Enum_ov003_0216d63c_4708 = 0x1264 };
enum { Enum_ov003_0216d63c_3852 = 0xf0c };
enum { Enum_ov003_0216d63c_4800 = 0x12c0 };
enum { kRegionValue126C_10FC = 0x126c };
enum { Enum_ov003_0216d63c_5128 = 0x1408 };
enum { Enum_ov003_0216d63c_5119 = 0x13ff };
#endif

struct Struct020a9ea4 {
	char data[8];
};

extern "C" void SpriteContext_Init(char* obj);
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);
extern "C" void func_020a9ea4(struct Struct020a9ea4* p);
extern "C" void func_ov003_0215c650(void* obj);
extern "C" void func_ov003_0216ffbc(void* obj);
extern "C" void func_ov003_02170b74(void* obj);

struct Struct_ov003_0216d63c {
	unsigned int unknown_0_;
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fieldA;
	int fieldC;
	int field10;
	char sub14[Enum_ov003_0216d63c_1040 - 0x14];
	char unknown_410_[Enum_ov003_0216d63c_2016 - Enum_ov003_0216d63c_1040];
	char unknown_7e0_[Enum_ov003_0216d63c_3848 - Enum_ov003_0216d63c_2016];
	void* unknown_f08_;
	char unknown_f0c_[Enum_ov003_0216d63c_4708 - Enum_ov003_0216d63c_3852];
	int unknown_1264_;
	int unknown_1268_;
	char sub126c[Enum_ov003_0216d63c_4800 - kRegionValue126C_10FC];
	int unknown_12c0_;
	int unknown_12c4_;
	int unknown_12c8_;
	int unknown_12cc_;
	int unknown_12d0_;
	SafeAllocator allocs[4];
	struct Struct020dfc40 texts;
	Object3D object;
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
	struct Struct020a9ea4 unknown_140c_;
};

// USA: func_ov003_0216d63c
extern "C" ARM void func_ov003_0216d63c(struct Struct_ov003_0216d63c* self) {
	self->unknown_0_ = (DISPCNT & 0x1f00) >> 8;
	self->field4 = 0;
	self->field6 = 0;
	self->field8 = 0;
	self->unknown_13ec_ = 0;
	self->fieldA = 0;
	self->fieldC = 0;
	self->field10 = 0;
	func_ov003_0215c650(self->sub14);
	func_ov003_0216ffbc(self->unknown_410_);
	func_ov003_02170b74(self->unknown_7e0_);
	self->unknown_f08_ = self->unknown_410_;
	self->unknown_1264_ = 0;
	self->unknown_1268_ = 0;
	SpriteContext_Init(self->sub126c);
	self->unknown_12c0_ = 0;
	self->unknown_12c4_ = 0;
	self->unknown_12c8_ = 0;
	self->unknown_12cc_ = 0;
	self->unknown_12d0_ = 0;
	self->allocs[0].ResetAllocatorPointer();
	self->allocs[1].ResetAllocatorPointer();
	self->allocs[2].ResetAllocatorPointer();
	self->allocs[3].ResetAllocatorPointer();
	KeyTable_Reset(&self->texts);
	self->object.Initialize();
	self->unknown_13e8_ = 0;
	self->unknown_13e9_ = 0;
	self->unknown_13ea_ = 0;
	self->unknown_13eb_ = 1;
	self->unknown_13ef_ = 0;
	self->unknown_13f0_ = 0;
	self->unknown_13ee_ = 0;
	self->unknown_13f4_ = -1;
	memset(self->unknown_13fc_, -1, 3);
	self->unknown_1408_ = 0;
	self->unknown_13ed_ = 0;
	func_020a9ea4(&self->unknown_140c_);
}
