#include <globaldefs.h>

struct Struct_ov014_02188ba0 {
	int unused0;
	int unused4;
	int unknown_8_;
	int unknown_c_;
	char* buf;
};

// USA: func_ov014_02188ba0
extern "C" ARM char* func_ov014_02188ba0(struct Struct_ov014_02188ba0* s, char* key, char* arg2) {
	int var0 = 1;
	int offset = (int)(key - (char*)0);
	if (offset != -1 && s->buf != NULL) {
		var0 = 0;
	}
	if (var0 == 0) {
		arg2 = s->buf + offset;
	}
	return arg2;
}
