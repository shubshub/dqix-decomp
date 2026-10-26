#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov001_02159d9c
extern "C" ARM void func_ov001_02159d9c(void* obj) {
	char* p = (char*)obj;
	*(int*)(p + 0x70) = -1;
	memset(p + 0x74, 0, 0xc);
	memset(p + 0x80, 0, 0xc);
	memset(p + 0xfc, 0, 0xc);
	*(float*)(p + 0x8c) = 31.0f;
	memset(p + 0xac, 0, 0xc);
	memset(p + 0xc4, 0, 0xc);
	*(int*)(p + 0xdc) = 0;
	memset(p + 0xb8, 0, 0xc);
	memset(p + 0xd0, 0, 0xc);
	*(int*)(p + 0xe0) = 0;
	*(int*)(p + 0x8) = 0;
	*(int*)(p + 0xc) = 0;
	*(int*)(p + 0x10) = 0;
	*(int*)(p + 0x14) = 0;
	*(int*)(p + 0x18) = 0;
	*(int*)(p + 0x1c) = 0;
	*(int*)(p + 0x20) = 0;
	*(int*)(p + 0x24) = 0;
	*(int*)(p + 0x28) = 0;
	*(int*)(p + 0x2c) = 0;
	*(int*)(p + 0x30) = 0;
	*(int*)(p + 0x34) = 0;
	*(int*)(p + 0x38) = 0;
	*(int*)(p + 0x3c) = 0;
	*(int*)(p + 0x40) = 0;
	*(int*)(p + 0x44) = 0;
	*(int*)(p + 0x48) = 0;
	*(int*)(p + 0x4c) = 0;
	*(int*)(p + 0x50) = 0;
	*(int*)(p + 0x54) = 0;
	*(int*)(p + 0x58) = 0;
	*(int*)(p + 0x5c) = 0;
	*(int*)(p + 0x60) = 0;
	*(int*)(p + 0x64) = 0;
	*(int*)(p + 0x68) = 0;
	*(int*)(p + 0x60) = 0;
	*(int*)(p + 0x90) = 0x1000;
}
