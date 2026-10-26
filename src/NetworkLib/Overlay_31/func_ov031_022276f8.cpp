#include <globaldefs.h>


extern "C" void* func_ov031_0223cf4c(unsigned int id, unsigned int size);

struct Struct_ov031_022276b4;
extern "C" int func_ov031_022276b4(Struct_ov031_022276b4* p, unsigned int idx);
extern "C" int func_ov031_022275a0(void);

struct Struct_ov031_022276f8;
extern "C" void func_ov031_0223a4cc(void* obj, Struct_ov031_022276f8* p);
extern "C" int func_ov031_0223a718(void);
extern "C" void HaltSystem(void);
extern "C" void* func_ov031_0223e218(void* a, void* b, void* c, int d);

extern void* data_ov031_02290c44;
extern Struct_ov031_022276b4* data_ov031_02290c4c;

struct Struct_ov031_0224b66c { unsigned int words[7]; };
extern Struct_ov031_0224b66c data_ov031_0224b66c;

extern "C" void func_ov031_02227898(void);

// USA: func_ov031_022276f8
extern "C" ARM void func_ov031_022276f8(int arg0) {
	void* ptr = func_ov031_0223cf4c(0x1e2a4, 0x20);
	data_ov031_02290c44 = ptr;
	*(int*)((char*)ptr + 0x1e000 + 0x298) = arg0;
	*(unsigned char*)((char*)data_ov031_02290c44 + 0x1e000 + 0x2a0) = 0;
	*(unsigned char*)((char*)data_ov031_02290c44 + 0x1e000 + 0x2a1) = 0;

	Struct_ov031_0224b66c buf = data_ov031_0224b66c;
	buf.words[1] = func_ov031_022276b4(data_ov031_02290c4c, 0);
	buf.words[2] = func_ov031_022276b4(data_ov031_02290c4c, 1);
	*(unsigned char*)&buf.words[6] = (unsigned char)func_ov031_022275a0();

	func_ov031_0223a4cc(data_ov031_02290c44, (Struct_ov031_022276f8*)&buf);

	if (func_ov031_0223a718() == 0) {
		HaltSystem();
	}

	void* result = func_ov031_0223e218(0, (void*)func_ov031_02227898, 0, 0x78);
	*(void**)((char*)data_ov031_02290c44 + 0x1e000 + 0x29c) = result;
}
