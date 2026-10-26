#include <globaldefs.h>


extern "C" void* func_ov031_0223cf4c(unsigned int arg0, unsigned int arg1);

struct Struct_ov031_022276b4;
extern "C" int func_ov031_022276b4(Struct_ov031_022276b4* arg0, unsigned int arg1);
extern "C" int func_ov031_022275a0(void);

struct Struct_ov031_022276f8;
extern "C" void func_ov031_0223a4cc(void* arg0, Struct_ov031_022276f8* arg1);
extern "C" int func_ov031_0223a718(void);
extern "C" void HaltSystem(void);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);

extern void* data_ov031_02290c44;
extern Struct_ov031_022276b4* data_ov031_02290c4c;

struct Struct_ov031_0224b66c { unsigned int unknown_0_[7]; };
extern Struct_ov031_0224b66c data_ov031_0224b66c;

extern "C" void func_ov031_02227898(void);

// USA: func_ov031_022276f8
extern "C" ARM void func_ov031_022276f8(int arg0) {
	void* var0 = func_ov031_0223cf4c(0x1e2a4, 0x20);
	data_ov031_02290c44 = var0;
	*(int*)((char*)var0 + 0x1e000 + 0x298) = arg0;
	*(unsigned char*)((char*)data_ov031_02290c44 + 0x1e000 + 0x2a0) = 0;
	*(unsigned char*)((char*)data_ov031_02290c44 + 0x1e000 + 0x2a1) = 0;

	Struct_ov031_0224b66c var1 = data_ov031_0224b66c;
	var1.unknown_0_[1] = func_ov031_022276b4(data_ov031_02290c4c, 0);
	var1.unknown_0_[2] = func_ov031_022276b4(data_ov031_02290c4c, 1);
	*(unsigned char*)&var1.unknown_0_[6] = (unsigned char)func_ov031_022275a0();

	func_ov031_0223a4cc(data_ov031_02290c44, (Struct_ov031_022276f8*)&var1);

	if (func_ov031_0223a718() == 0) {
		HaltSystem();
	}

	void* var2 = func_ov031_0223e218(0, (void*)func_ov031_02227898, 0, 0x78);
	*(void**)((char*)data_ov031_02290c44 + 0x1e000 + 0x29c) = var2;
}
