#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

extern "C" void func_ov009_02188c2c(CharacterCreationUI* self);
extern "C" void func_ov009_02188d9c(CharacterCreationUI* self);
extern "C" void func_ov009_02188e70(CharacterCreationUI* self, int val);
extern "C" void applyCreationChoice(CharacterCreationUI* self, int val);
extern "C" int func_ov009_02188ee8(CharacterCreationUI* self);
#if defined(jpn)
extern "C" ARM void func_ov009_021867bc(unsigned char *arg0, int arg1);
#define func_ov009_021855dc func_ov009_021867bc
#else
extern "C" ARM void func_ov009_021855dc(unsigned char *arg0, int arg1);
#endif

// USA: func_ov009_021869d8
extern "C" ARM void func_ov009_021869d8(Struct_ov009_021842a0* arg0) {
	unsigned char var0 = arg0->unknown_c59_;
	if (var0 == 0) {
		func_ov009_02188c2c(arg0);
		func_ov009_02188d9c(arg0);
		int var1 = arg0->unknown_da3_;
		unsigned char var2 = arg0->unknown_dae_[var1];
		func_ov009_02188e70(arg0, var2);
		arg0->unknown_d9c_ |= 1;
		arg0->unknown_c59_ = arg0->unknown_c59_ + 1;
		return;
	}
	if (var0 == 1) {
		if (arg0->unknown_d9c_ & 0x80) {
			return;
		}
		int idx = self->sex;
		unsigned char val = self->hairColor[idx];
		applyCreationChoice(self, val);
		self->step = self->step + 1;
		return;
	}
	if (var0 != 2) {
		return;
	}
	int var5 = func_ov009_02188ee8(arg0);
	if (var5 == -2) {
		func_ov009_021855dc((unsigned char*)arg0, 5);
		return;
	}
	if (var5 == -3) {
		func_ov009_021855dc((unsigned char*)arg0, 3);
		return;
	}
	if (var5 < 0x65 || var5 > 0x6c) {
		return;
	}
	int var6 = arg0->unknown_da3_;
	int var7 = var5 - 0x64;
	signed char *var8 = arg0->unknown_da0_;
	if (var7 > var8[var6]) {
		return;
	}
	if (var7 == arg0->unknown_c58_) {
		return;
	}
	func_ov009_021855dc((unsigned char*)arg0, var7 & 0xff);
}
