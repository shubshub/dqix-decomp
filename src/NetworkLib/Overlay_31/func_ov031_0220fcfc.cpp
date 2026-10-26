#include <globaldefs.h>

struct Struct_ov031_0220fcfc {
	unsigned int words[6];
	char padding[0x414 - 0x18];
};

extern void* data_ov031_0224e580;

extern "C" int func_ov031_0220fe44(int (*fn)(int*));
extern "C" int func_ov031_0220ff34(int* obj);
extern "C" int func_ov031_0220ff18(void* obj);
extern "C" void func_ov031_0220fea0(void);
extern "C" void func_ov031_0220fed8(void);

// USA: func_ov031_0220fcfc
extern "C" ARM void func_ov031_0220fcfc(void) {
	Struct_ov031_0220fcfc hdr;
	unsigned int* q = (unsigned int*)&hdr;
	void* g = data_ov031_0224e580;
	q[0] = 0x10;
	q[1] = 0x44535359;
	q[2] = 0xd1;
	q[3] = *(int*)((char*)(*(void**)((char*)g + 0x24)) + 4);
	if (func_ov031_0220fe44(func_ov031_0220ff34) != 0) {
		if (func_ov031_0220ff18(&hdr) != 0) {
			func_ov031_0220fea0();
		}
	}
	func_ov031_0220fed8();
}
