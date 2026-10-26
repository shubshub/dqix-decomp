#include <globaldefs.h>

struct Struct_ov023_021d8cb4 { unsigned int w[20]; };
struct Struct_ov023_021d8cb4_2 { unsigned int w[16]; };

// USA: func_ov023_021d8cb4
extern "C" ARM void func_ov023_021d8cb4(void* dst, void* src) {
	if (!src) return;
	char* base = (char*)src + 0x188;
	*(Struct_ov023_021d8cb4*)((char*)dst + 0x24) = *(Struct_ov023_021d8cb4*)(base + 4);
	*(Struct_ov023_021d8cb4_2*)((char*)dst + 0x74) = *(Struct_ov023_021d8cb4_2*)(base + 0x54);
	*((unsigned char*)dst + 0xb4) = *(unsigned char*)(base + 0x94);
	*((unsigned char*)dst + 0xb5) = *(unsigned char*)(base + 0x95);
	*((unsigned char*)dst + 0xb6) = *(unsigned char*)(base + 0x96);
	*((unsigned char*)dst + 0xb7) = *(unsigned char*)(base + 0x97);
	*(unsigned int*)((char*)dst + 0xb8) = *(unsigned int*)(base + 0x98);
	*(unsigned int*)((char*)dst + 0xbc) = *(unsigned int*)(base + 0x9c);
	*(short*)((char*)dst + 0xc0) = *(short*)(base + 0xa0);
	*(short*)((char*)dst + 0xc2) = *(short*)(base + 0xa2);
	*(short*)((char*)dst + 0xc4) = *(short*)(base + 0xa4);
	*(short*)((char*)dst + 0xc6) = *(short*)(base + 0xa6);
	*(short*)((char*)dst + 0xc8) = *(short*)(base + 0xa8);
	*(short*)((char*)dst + 0xca) = *(short*)(base + 0xaa);
	*(short*)((char*)dst + 0xcc) = *(short*)(base + 0xac);
	*(short*)((char*)dst + 0xce) = *(short*)(base + 0xae);
	*((unsigned char*)dst + 0xd0) = *(unsigned char*)(base + 0xb0);
	*((unsigned char*)dst + 0xd1) = *(unsigned char*)(base + 0xb1);
	*((unsigned char*)dst + 0xd2) = *(unsigned char*)(base + 0xb2);
	*((unsigned char*)dst + 0xd3) = *(unsigned char*)(base + 0xb3);
	*((unsigned char*)dst + 0xd4) = *(unsigned char*)(base + 0xb4);
	*((unsigned char*)dst + 0xd5) = *(unsigned char*)(base + 0xb5);
	*((unsigned char*)dst + 0xd6) = *(unsigned char*)(base + 0xb6);
	*((unsigned char*)dst + 0xd7) = *(unsigned char*)(base + 0xb7);
	*((unsigned char*)dst + 0xd8) = *(unsigned char*)(base + 0xb8);
	*((unsigned char*)dst + 0xd9) = *(unsigned char*)(base + 0xb9);
	*((unsigned char*)dst + 0xda) = *(unsigned char*)(base + 0xba);
	*((unsigned char*)dst + 0xdb) = *(unsigned char*)(base + 0xbb);
	*(void**)dst = (char*)src + 0xb8;
}
