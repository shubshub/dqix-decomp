#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

#if defined(jpn)
enum { Enum_ov017_021baedc_0 = -0x4 };
#else
enum { Enum_ov017_021baedc_0 = 0x0 };
#endif

struct ByteHeader0204693c;
extern "C" void func_0204693c(struct ByteHeader0204693c* p);

struct Struct_ov017_021baedc;
extern "C" void func_ov017_021bb088(struct Struct_ov017_021baedc* p);

struct Struct_ov017_021baedc_2 { unsigned char bit0:1; unsigned char rest:7; };

// USA: func_ov017_021baedc
extern "C" ARM void func_ov017_021baedc(void* self, int flag) {
	char* base = (char*)self;
	func_0204693c((struct ByteHeader0204693c*)base);
	*(signed char*)(base + 0x0) = 4;
	*(short*)(base + 0x8) = 0;
	*(short*)(base + 0xa) = 0;
	*(int*)(base + 0x90 + Enum_ov017_021baedc_0) = 0;
	*(unsigned short*)(base + 0x11a + Enum_ov017_021baedc_0) = 0;
	*(short*)(base + 0x14e + Enum_ov017_021baedc_0) = -1;
	*(unsigned char*)(base + 0x9c + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x98 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x99 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x9a + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x9b + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0xcc + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0xcd + Enum_ov017_021baedc_0) = 0;
	*(signed char*)(base + 0xa0 + Enum_ov017_021baedc_0) = -1;
	*(int*)(base + 0x110 + Enum_ov017_021baedc_0) = -1;
	*(unsigned char*)(base + 0xfe + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x100 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x101 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x102 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x103 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x104 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x106 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x107 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x108 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x109 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x10a + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x10b + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x10c + Enum_ov017_021baedc_0) = 0;
	if (flag == 0) {
		*(unsigned char*)(base + 0x105 + Enum_ov017_021baedc_0) = 0;
	}
	if (flag == 0) {
		*(unsigned short*)(base + 0x11c + Enum_ov017_021baedc_0) = 0;
	}
	memset(base + 0xc, 0, 0x68);
	*(unsigned short*)(base + 0x114 + Enum_ov017_021baedc_0) = 0;
	func_ov017_021bb088((struct Struct_ov017_021baedc*)(base + 0xd0 + Enum_ov017_021baedc_0));
	if (TestFlags00(GetGameResources(), 0x1000) == 0) {
		((SafeAllocator*)(base + 0x7c + Enum_ov017_021baedc_0))->ResetAllocatorPointer();
	}
	*(int*)(base + 0x120 + Enum_ov017_021baedc_0) = 0;
	((SafeAllocator*)(base + 0x124 + Enum_ov017_021baedc_0))->ResetAllocatorPointer();
	memset(base + 0x13c + Enum_ov017_021baedc_0, 0, 0x12);
	memset(base + 0x150 + Enum_ov017_021baedc_0, 0, 0xa);
	*(int*)(base + 0x15c + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0xfd + Enum_ov017_021baedc_0) = 0;
	*(signed char*)(base + 0x116 + Enum_ov017_021baedc_0) = -1;
	*(int*)(base + 0x160 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x164 + Enum_ov017_021baedc_0) = 1;
	*(int*)(base + 0x170 + Enum_ov017_021baedc_0) = 0;
	*(int*)(base + 0x168 + Enum_ov017_021baedc_0) = 0;
	*(int*)(base + 0x16c + Enum_ov017_021baedc_0) = 0;
	*(int*)(base + 0x138 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0xff + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x174 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x175 + Enum_ov017_021baedc_0) = 0;
	((Struct_ov017_021baedc_2*)(base + 0x178 + Enum_ov017_021baedc_0))->bit0 = 0;
	((Struct_ov017_021baedc_2*)(base + 0x178 + Enum_ov017_021baedc_0))->rest = 0;
	*(unsigned char*)(base + 0x179 + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x17a + Enum_ov017_021baedc_0) = 0;
	*(unsigned char*)(base + 0x17b + Enum_ov017_021baedc_0) = 0;
	*(float*)(base + 0x17c + Enum_ov017_021baedc_0) = -1.0f;
	*(unsigned short*)(base + 0x184 + Enum_ov017_021baedc_0) = 0;
	memset(base + 0x188 + Enum_ov017_021baedc_0, 0, 0x30);
	memset(base + 0x1b8 + Enum_ov017_021baedc_0, 0, 0x10);
}
