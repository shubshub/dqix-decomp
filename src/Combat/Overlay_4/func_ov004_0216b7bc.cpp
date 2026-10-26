#include <globaldefs.h>

extern "C" void* func_ov004_0216ae9c(void* a, int id);
extern "C" void func_ov023_021f8120(void* node);
extern "C" void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int arg9);
extern "C" void func_ov023_021f8960(char* base, short a, unsigned short b);
struct Struct_ov004_0216b7bc;
extern "C" ARM void func_ov011_02184ad8(Struct_ov004_0216b7bc* obj);

extern unsigned char data_ov004_02171034;

#if defined(jpn)
enum { Enum_ov004_0216b7bc_3 = 5, Enum_ov004_0216b7bc_2 = 0 };
#else
enum { Enum_ov004_0216b7bc_3 = 3, Enum_ov004_0216b7bc_2 = 2 };
#endif

// USA: func_ov004_0216b7bc
extern "C" ARM int func_ov004_0216b7bc(void* a, int type, int buf, int d) {
	void* node = func_ov004_0216ae9c(a, type);
	func_ov023_021f8120(node);
	switch (type) {
	case 0xd4:
		if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_3] == 0 || d == 1) {
			func_ov023_021f8960((char*)node, 0, 6);
		}
		func_ov023_021f7eb8(node, a, buf, 0, 0x10, 0x20, 8, 0, 1, 0);
		buf += 0x2800;
		break;
	case 0xd3:
		if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_3] == 4) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xa, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_2] == 0) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xb, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_2] == 1) {
			func_ov023_021f7eb8(node, a, buf, 8, 0xa, 0x18, 5, 0, 1, 0);
			buf += 0xf00;
		}
		break;
	case 0x3e8:
		if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_3] == 4) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xa, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_2] == 0) {
			func_ov023_021f7eb8(node, a, buf, 0x19, 0xb, 7, 5, 0, 1, 0);
			buf += 0x460;
		} else if (((unsigned char*)&data_ov004_02171034)[Enum_ov004_0216b7bc_2] == 1) {
			func_ov023_021f7eb8(node, a, buf, 0xc, 0xb, 0x14, 4, 0, 1, 0);
			buf += 0xa00;
		}
		break;
	}
	func_ov011_02184ad8((Struct_ov004_0216b7bc*)a);
	return buf;
}
