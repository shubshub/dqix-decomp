#include <globaldefs.h>

struct Struct_ov024_021f6a1c;
extern "C" void func_ov024_021f6a1c(struct Struct_ov024_021f6a1c* obj, void* src);

struct Struct_ov024_021fd088 { unsigned int w[3]; };

// USA: func_ov024_021fd088
extern "C" ARM void func_ov024_021fd088(void* obj, float arg1, int a2) {
	char* base = (char*)obj;
	struct Struct_ov024_021fd088 local = *(struct Struct_ov024_021fd088*)(base + 0x65c);
	short v = *(short*)(*(char**)(base + 0x64c) + 0x32);
	*(float*)&local.w[0] = (float)v;
	unsigned char var3 = ((unsigned char*)&local)[7];
	((unsigned char*)&local)[4] = (unsigned char)a2;
	int var4 = (int)((float)var3 * arg1 / 100.0f);
	((unsigned char*)&local)[8] = 5;
	((unsigned char*)&local)[7] = (unsigned char)var4;
	func_ov024_021f6a1c((struct Struct_ov024_021f6a1c*)*(void**)(base + 0x658), &local);
}
