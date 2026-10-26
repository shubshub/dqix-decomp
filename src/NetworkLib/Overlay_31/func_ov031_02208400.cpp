#include <globaldefs.h>

struct Struct_ov031_02208400_2 {
	const char* name;
	int unknown_4_;
	unsigned char* unknown_8_;
	int unknown_c_;
	unsigned char* unknown_10_;
};

struct Struct_ov031_02208400 {
	unsigned char field_0x0[0x468];
	unsigned char digest[0x14];
	int digestLength;
	unsigned char field_0x480[0x124];
	unsigned char* signature;
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
extern "C" ARM int func_ov031_02208400(Struct_ov031_02208400* state, Struct_ov031_02208400_2* key) {
	unsigned short* var0;
	unsigned short* message;
	unsigned short* var2;
	unsigned short* var3;
	int words;
	int result;
	int i;
	int length;
	unsigned char* decoded;
	if (state->signature == 0 || state->unknown_5a8_ == 0 || key->unknown_10_ == 0 || key->unknown_c_ == 0 ||
	    key->unknown_8_ == 0 || key->unknown_4_ == 0)
		return 2;
	words = (key->unknown_4_ * 2) / 2;
	var0 = (unsigned short*)data_ov031_0224c994(words * 8);
	if (var0 == 0)
		return 2;
	message = var0 + words;
	var2 = message + words;
	var3 = var2 + words;
	func_ov031_0220c8d0(message, state->signature, state->unknown_5a8_, words);
	func_ov031_0220c8d0(var2, key->unknown_10_, key->unknown_c_, words);
	func_ov031_0220c8d0(var3, key->unknown_8_, key->unknown_4_, words);
	unsigned int priority = func_ov031_02207cf0();
	func_ov031_0220c2bc(var0, message, var2, words, var3);
	func_ov031_02207d3c(priority);
	decoded = (unsigned char*)message;
	func_ov031_0220c92c(decoded, var0, key->unknown_4_, words);
	result = 0;
	if (decoded[0] != 0 || decoded[1] != 1) {
		result = 2;
	} else {
		length = key->unknown_4_;
		i = 2;
		if (i < length) {
			do {
				if (decoded[i] != 0xff)
					break;
				i++;
			} while (i < length);
		}
		if (i + 1 >= length || decoded[i] != 0 || decoded[i + 1] != 0x30 ||
		    memcmp(state->digest, decoded + length - state->digestLength, state->digestLength) != 0)
			result = 2;
	}
	data_ov031_0224c9c0(var0);
	return result;
}
