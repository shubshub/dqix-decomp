#include <globaldefs.h>

extern "C" void func_ov001_02164578(int a, int b, void* c, int d, float e);
extern int data_ov001_02165884;

struct Struct_ov001_02159a00 {
	char pad0[0x10];
	int f10;
	int f14;
	int f18;
	char pad1[0x1c - 0x1c];
	int f1c;
	char pad2[0x3c - 0x20];
	int* f3c;
};

struct Struct_ov001_02159a00_2 {
	char pad0[0x70];
	int unknown_70_;
};

// USA: func_ov001_02159a00
extern "C" ARM int func_ov001_02159a00(struct Struct_ov001_02159a00* self, struct Struct_ov001_02159a00_2* obj) {
	if (self->f18 == 0) {
		float f = (float)self->f14;
		func_ov001_02164578(data_ov001_02165884, obj->unknown_70_, &self->f1c, self->f10, f);
		if (self->f3c != NULL) {
			int v = *self->f3c;
			if (v == 0xd || v == 0xf) {
				return 0;
			}
		}
		self->f18 = 1;
		return 1;
	}
	return 0;
}
