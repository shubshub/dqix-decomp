#include <globaldefs.h>
#include "NitroSDK/Memory.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { Enum_ov003_0217daf0_20 = 0x10 };
enum { Enum_ov003_0217daf0_48 = 0x2c };
enum { Enum_ov003_0217daf0_49 = 0x2d };
enum { Enum_ov003_0217daf0_24 = 0x14 };
enum { Enum_ov003_0217daf0_52 = 0x30 };
enum { Enum_ov003_0217daf0_56 = 0x34 };
enum { kRegionValue3C_38 = 0x38 };
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue94_90 = 0x90 };
enum { Enum_ov003_0217daf0_152 = 0x94 };
enum { Enum_ov003_0217daf0_156 = 0x98 };
enum { Enum_ov003_0217daf0_160 = 0x9c };
enum { Enum_ov003_0217daf0_164 = 0xa0 };
enum { Enum_ov003_0217daf0_184 = 0xb4 };
enum { kRegionValueCC_C8 = 0xc8 };
#else
enum { Enum_ov003_0217daf0_20 = 0x14 };
enum { Enum_ov003_0217daf0_48 = 0x30 };
enum { Enum_ov003_0217daf0_49 = 0x31 };
enum { Enum_ov003_0217daf0_24 = 0x18 };
enum { Enum_ov003_0217daf0_52 = 0x34 };
enum { Enum_ov003_0217daf0_56 = 0x38 };
enum { kRegionValue3C_38 = 0x3c };
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue94_90 = 0x94 };
enum { Enum_ov003_0217daf0_152 = 0x98 };
enum { Enum_ov003_0217daf0_156 = 0x9c };
enum { Enum_ov003_0217daf0_160 = 0xa0 };
enum { Enum_ov003_0217daf0_164 = 0xa4 };
enum { Enum_ov003_0217daf0_184 = 0xb8 };
enum { kRegionValueCC_C8 = 0xcc };
#endif


extern "C" void SpriteContext_Init(char* obj);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(struct Struct020dfc40* p);

// USA: func_ov003_0217daf0
extern "C" ARM void func_ov003_0217daf0(char* obj) {
	*(int*)(obj + 0x0) = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
	*(unsigned char*)(obj + 0x4) = 0;
	*(unsigned char*)(obj + 0x5) = 0;
	*(unsigned char*)(obj + 0x6) = 0;
	*(short*)(obj + 0x8) = 1;
	*(int*)(obj + 0xc) = 0;
	*(int*)(obj + Enum_ov003_0217daf0_20) = 0;
	*(unsigned char*)(obj + Enum_ov003_0217daf0_48) = 0;
	*(unsigned char*)(obj + Enum_ov003_0217daf0_49) = 0;
	VectorizedMemset(obj + Enum_ov003_0217daf0_24, 0, 0x18);
	*(int*)(obj + Enum_ov003_0217daf0_52) = 0;
	*(int*)(obj + Enum_ov003_0217daf0_56) = 0;
	SpriteContext_Init(obj + kRegionValue3C_38);
	*(int*)(obj + kRegionValue90_8C) = 0;
	*(int*)(obj + kRegionValue94_90) = 0;
	*(int*)(obj + Enum_ov003_0217daf0_152) = 0;
	*(int*)(obj + Enum_ov003_0217daf0_156) = 0;
	*(int*)(obj + Enum_ov003_0217daf0_160) = 0;
	((SafeAllocator*)(obj + Enum_ov003_0217daf0_164))->ResetAllocatorPointer();
	((SafeAllocator*)(obj + Enum_ov003_0217daf0_184))->ResetAllocatorPointer();
	KeyTable_Reset((struct Struct020dfc40*)(obj + kRegionValueCC_C8));
}
