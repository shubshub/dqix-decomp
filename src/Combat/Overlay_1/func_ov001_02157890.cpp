#include <globaldefs.h>

extern "C" int func_ov001_021570b4(void* p);

struct Struct_ov001_02157570_2 {
	unsigned char pad0[0x38c];
	int x;
	int y;
	int z;
};
struct Struct_ov001_02157570 {
	int x;
	int y;
	int z;
};

extern "C" void func_ov001_02157570(struct Struct_ov001_02157570_2* src, struct Struct_ov001_02157570* dst);

// USA: func_ov001_02157890
extern "C" ARM void func_ov001_02157890(char* d, struct Struct_ov001_02157570* v1, struct Struct_ov001_02157570* v2) {
	if (*(int*)(d + 0x8c0) != 0) {
		int flagA = 0;
		int var1 = 0;
		if (func_ov001_021570b4(d + 0x188) != 0) {
			flagA = 1;
		}
		if (func_ov001_021570b4(d + 0x524) != 0) {
			var1 = 1;
		}
		if (flagA != 0 && var1 != 0) {
			*(int*)(d + 0x8c0) = 0;
		}
		func_ov001_02157570((struct Struct_ov001_02157570_2*)(d + 0x188), v1);
		func_ov001_02157570((struct Struct_ov001_02157570_2*)(d + 0x524), v2);
	}
}
