#include <globaldefs.h>

struct Struct_ov024_021f6820;
extern "C" void func_ov024_021f6820(struct Struct_ov024_021f6820*, short, char, char);

struct Struct_ov024_021f68c8 {
	short f0;
	char f2;
	char f3;
	float f4;
	char pad[4];
};

// USA: func_ov024_021f68c8
extern "C" ARM void func_ov024_021f68c8(struct Struct_ov024_021f68c8* arr) {
	for (int i = 0; i < 4; i++) {
		func_ov024_021f6820((struct Struct_ov024_021f6820*)&arr[i], 0, -1, 0);
		arr[i].f4 = -1.0f;
	}
}
