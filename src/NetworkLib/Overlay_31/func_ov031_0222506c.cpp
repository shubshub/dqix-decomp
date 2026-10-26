#include <globaldefs.h>

struct Struct_ov031_0222506c { int a; int b; };
struct Struct_ov031_02222c18 { int pad0, pad1; Struct_ov031_0222506c* arr; };
extern "C" Struct_ov031_0222506c* func_ov031_0223baa0(Struct_ov031_02222c18* obj, int idx);
extern "C" int func_ov031_0223bdb0(int a, int b, int c);

struct Struct_ov031_0223bcc8 { unsigned int pad0; unsigned short h4; unsigned short pad6; };
struct Struct_ov031_02222ce4 { unsigned char pad0[8]; Struct_ov031_0223bcc8* list; unsigned char count; };
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4* obj, int idx, int val);

extern "C" void func_ov031_0223bbd8(void* a, int b, int c, int d);

extern unsigned short data_ov031_02248ac8[];
extern unsigned short data_ov031_02248aca[];

struct Struct_ov031_0222506c_2 { unsigned char pad[0x114]; Struct_ov031_02222c18* unknown_114_; unsigned char pad2[0x121 - 0x118]; signed char unknown_121_; };
extern Struct_ov031_0222506c_2* data_ov031_02250bfc;

// USA: func_ov031_0222506c
extern "C" ARM void func_ov031_0222506c(void) {
	Struct_ov031_0222506c_2* obj = data_ov031_02250bfc;
	signed char key = obj->unknown_121_;
	char code;
	switch (key) {
	case 0x2f: code = 'B'; break;
	case 0x30: code = 'A'; break;
	case 0x31: code = 'C'; break;
	case 0x32: code = 'A'; break;
	case 0x33:
	case 0x34: code = 'E'; break;
	default: code = '@'; break;
	}

	Struct_ov031_0222506c* elem = func_ov031_0223baa0(obj->unknown_114_, 0);
	func_ov031_0223bdb0(0, code, (int)elem);

	func_ov031_0223bcc8((Struct_ov031_02222ce4*)data_ov031_02250bfc->unknown_114_, -1, 2);

	int idx = data_ov031_02250bfc->unknown_121_ * 2;
	unsigned short a = data_ov031_02248ac8[idx];
	unsigned short b = data_ov031_02248aca[idx];
	func_ov031_0223bbd8(data_ov031_02250bfc->unknown_114_, -1, a, b);
}
