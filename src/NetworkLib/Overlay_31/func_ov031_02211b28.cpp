#include <globaldefs.h>

struct Struct_ov031_02211b28 {
	int magic;
	int value;
};

// USA: func_ov031_02211b28
extern "C" ARM void* func_ov031_02211b28(Struct_ov031_02211b28* h, int value) {
	h->magic = 0x4457434d;
	h->value = value;
	return (char*)h + 0x20;
}
