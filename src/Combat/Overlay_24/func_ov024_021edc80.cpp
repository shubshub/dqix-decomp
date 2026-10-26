#include <globaldefs.h>

struct Struct_ov024_021edc80 {
	char unk[0x21];
	unsigned char state;
};

struct Struct_ov024_021eda78 {
	char unk[0x138];
	struct Struct_ov024_021edc80* inner;
};

// USA: func_ov024_021edc80
extern "C" ARM int func_ov024_021edc80(struct Struct_ov024_021eda78* obj) {
	int result = obj->inner->state == 4;
	return result != 0;
}
