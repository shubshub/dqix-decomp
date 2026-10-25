#include <globaldefs.h>

struct Struct_ov031_02208400_2 {
	const char* unknown_0_;
	int unknown_4_;
	unsigned char* unknown_8_;
	int unknown_c_;
	unsigned char* unknown_10_;
};

struct Struct_ov031_02208400 {
	unsigned char unknown_0_[0x468];
	unsigned char unknown_468_[0x14];
	int unknown_47c_;
	unsigned char unknown_480_[0x124];
	unsigned char* unknown_5a4_;
	int unknown_5a8_;
};

extern "C" void func_ov031_0220c8d0(unsigned short*, unsigned char*, int, int);
extern "C" void func_ov031_0220c92c(unsigned char*, unsigned short*, int, int);
extern "C" unsigned int func_ov031_02207cf0();
extern "C" void func_ov031_02207d3c(unsigned int);
extern "C" void func_ov031_0220c2bc(unsigned short*, unsigned short*, unsigned short*, int, unsigned short*);
extern "C" int memcmp(void*, void*, int);
extern void* (*data_ov031_0224c994)(unsigned int);
extern int (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_02208400
extern "C" ARM int func_ov031_02208400(Struct_ov031_02208400* arg0, Struct_ov031_02208400_2* arg1) {
	unsigned short* var0;
	unsigned short* var1;
	unsigned short* var2;
	unsigned short* var3;
	int var4;
	int var5;
	int var6;
	int var7;
	unsigned char* var8;
	if (arg0->unknown_5a4_ == 0 || arg0->unknown_5a8_ == 0 || arg1->unknown_10_ == 0 || arg1->unknown_c_ == 0 ||
	    arg1->unknown_8_ == 0 || arg1->unknown_4_ == 0)
		return 2;
	var4 = (arg1->unknown_4_ * 2) / 2;
	var0 = (unsigned short*)data_ov031_0224c994(var4 * 8);
	if (var0 == 0)
		return 2;
	var1 = var0 + var4;
	var2 = var1 + var4;
	var3 = var2 + var4;
	func_ov031_0220c8d0(var1, arg0->unknown_5a4_, arg0->unknown_5a8_, var4);
	func_ov031_0220c8d0(var2, arg1->unknown_10_, arg1->unknown_c_, var4);
	func_ov031_0220c8d0(var3, arg1->unknown_8_, arg1->unknown_4_, var4);
	unsigned int var9 = func_ov031_02207cf0();
	func_ov031_0220c2bc(var0, var1, var2, var4, var3);
	func_ov031_02207d3c(var9);
	var8 = (unsigned char*)var1;
	func_ov031_0220c92c(var8, var0, arg1->unknown_4_, var4);
	var5 = 0;
	if (var8[0] != 0 || var8[1] != 1) {
		var5 = 2;
	} else {
		var7 = arg1->unknown_4_;
		var6 = 2;
		if (var6 < var7) {
			do {
				if (var8[var6] != 0xff)
					break;
				var6++;
			} while (var6 < var7);
		}
		if (i + 1 >= length || decoded[i] != 0 || decoded[i + 1] != 0x30 ||
		    memcmp(state->digest, decoded + length - state->digestLength, state->digestLength) != 0)
			result = 2;
	}
	data_ov031_0224c9c0(var0);
	return var5;
}
