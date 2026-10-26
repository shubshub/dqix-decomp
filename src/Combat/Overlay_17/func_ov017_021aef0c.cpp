#include <globaldefs.h>

struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void func_020daf9c(int a, int b, int c, int d);

struct Obj021aef0c {
	char pad0[0x1];
	unsigned char field1;
	char pad1[6];
	unsigned char field8;
};

typedef unsigned char (*Type_0200f3a4)(Obj021aef0c* self);

struct Struct_ov017_021d6ad8 {
	Type_0200f3a4 unknown_0_[5];
};

extern Struct_ov017_021d6ad8 data_ov017_021d6ad8;

// USA: func_ov017_021aef0c
extern "C" ARM void func_ov017_021aef0c(Obj021aef0c* self, void* context) {
	Struct_ov017_021d6ad8 table = data_ov017_021d6ad8;
	self->field8 = table.unknown_0_[self->field8](self);

	if (self->field1 != 0) {
		FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x800000);
		func_020daf9c(0, 1, 0, 1);
	}
}
