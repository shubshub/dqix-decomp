#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_020e38e4 { unsigned int val; unsigned char tag; };
struct TagValueEntry020e385c { unsigned int val; unsigned char tag; };

extern "C" void* func_020e3808(void);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* state);
extern "C" int func_020e38e4(struct Struct_020e38e4* entries, int tag, int val);
extern "C" struct TagValueEntry020e385c* func_020e385c(struct TagValueEntry020e385c* entries, int tag, int val);
extern "C" void func_0205e330(void* a, void* b, int c);

// USA: func_ov017_021cebcc
extern "C" ARM void func_ov017_021cebcc(int kind, int a1, int a2) {
	struct Struct_020e38e4* entries = (struct Struct_020e38e4*)func_020e3808();
	void* p = LinkMessageQueue_GetInstance();

	unsigned char buf[0x14];
	buf[0] = 0x34;
	unsigned char* b = buf + 4;
	b[0] = kind;
	*(int*)(b + 4) = a2;
	b[8] = a1;

	if (LinkSession_IsHostOrSolo(LinkSession_GetInstance()) != 0 && kind == 3) {
		b[1] = func_020e38e4(entries, a1, a2);
		struct TagValueEntry020e385c* found = func_020e385c((struct TagValueEntry020e385c*)entries, a1, a2);
		if (found != NULL) {
			memcpy(b + 4, found, 8);
		}
	}

	func_0205e330(p, buf, 0);
}
