#include <globaldefs.h>

struct Struct_ov031_0220d9c8 {
	short a;
	short b;
	int c;
	int d;
	int e;
};
typedef void (*Type_ov031_0220d9c8)(Struct_ov031_0220d9c8*);

extern void* data_ov031_0224e53c;

// USA: func_ov031_0220d9c8
extern "C" ARM void func_ov031_0220d9c8(short a, short b, int c, int d, int e) {
	char* base = (char*)data_ov031_0224e53c;
	if (*(Type_ov031_0220d9c8*)(base + 0x227c) == 0) return;
	Struct_ov031_0220d9c8 msg;
	msg.a = a;
	msg.b = b;
	msg.c = c;
	msg.d = d;
	msg.e = e;
	(*(Type_ov031_0220d9c8*)(base + 0x227c))(&msg);
}
