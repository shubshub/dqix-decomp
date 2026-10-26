#include <globaldefs.h>

struct Struct_ov024_021edca4 {
	char unk[0x21];
	unsigned char state;
};

struct Struct_ov024_021eda78_2 {
	char unk[0x138];
	struct Struct_ov024_021edca4* inner;
};

// USA: func_ov024_021edca4
extern "C" ARM int func_ov024_021edca4(struct Struct_ov024_021eda78_2* obj) {
	int result = obj->inner->state == 5;
	return result != 0;
}
