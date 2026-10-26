#include <globaldefs.h>

struct Struct_ov031_022383fc {
	unsigned char pad0[0x1c];
	unsigned char unknown_1c_;
};
extern Struct_ov031_022383fc* data_ov031_02290d10;

struct Struct_ov031_022269d8;
struct Struct_ov031_02223268_2;
extern "C" Struct_ov031_02223268_2* func_ov031_0223baa0(Struct_ov031_022269d8* obj, int idx);
extern "C" void func_ov031_0223bdb0(int a, int b, void* c);
extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

struct Struct_ov031_02222ce4;
extern "C" ARM void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);

extern unsigned char data_ov031_022492fe[];
extern unsigned char data_ov031_022492ea[];
extern unsigned short data_ov031_02249364[];
extern unsigned short data_ov031_02249366[];

// USA: func_ov031_022383fc
extern "C" ARM void func_ov031_022383fc(int idx) {
	Struct_ov031_02223268_2* elem = func_ov031_0223baa0(
		*(Struct_ov031_022269d8**)((char*)data_ov031_02290d10 + 8 + idx * 4), 0);

	unsigned char var1 = data_ov031_02290d10->unknown_1c_;
	unsigned char v1 = *((unsigned char*)data_ov031_022492fe + var1 * 2 + idx);
	func_ov031_0223bdb0(0, v1 + 1, elem);

	unsigned char var3 = data_ov031_02290d10->unknown_1c_;
	Struct_ov031_022269d8* elem2 = *(Struct_ov031_022269d8**)((char*)data_ov031_02290d10 + 8 + idx * 4);
	unsigned char v2 = *((unsigned char*)data_ov031_022492ea + var3 * 2 + idx);
	unsigned short var6 = *(unsigned short*)((char*)data_ov031_02249364 + var3 * 8 + v2 * 4);
	unsigned short var7 = *(unsigned short*)((char*)data_ov031_02249366 + var3 * 8 + v2 * 4);
	func_ov031_0223bbd8(elem2, -1, var6, var7);

	void* var8 = *(void**)((char*)data_ov031_02290d10 + 8 + idx * 4);
	func_ov031_0223bcc8((Struct_ov031_02222ce4*)var8, -1, 0);
}
