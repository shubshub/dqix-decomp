#include <globaldefs.h>

#if defined(jpn)
#define func_020ca390 func_020cbe5c
#endif

extern "C" void func_020ca390(int a, void* buf, unsigned int size);
extern "C" int func_020d4f7c(int a, int b, int c);
extern "C" void func_ov031_022359e0(void* obj);
extern "C" int func_020d4848(void* src);
extern "C" unsigned short func_020d4be8(void);
extern "C" int func_ov031_022358b4(void);

extern char* data_ov031_02290cf8;

struct Struct_ov031_02249204 { unsigned int v[17]; };
extern Struct_ov031_02249204 data_ov031_02249204;

// USA: func_ov031_022357e8
extern "C" ARM int func_ov031_022357e8(void) {
	func_020ca390(0, data_ov031_02290cf8 + 0x1300, 0x348);

	int r = func_020d4f7c((int)data_ov031_02290cf8, (int)func_ov031_022359e0, 3);
	if (r != 2) return 0;

	char* var1;
	do {
		var1 = data_ov031_02290cf8;
		func_020d4848(var1 + 0x28c + 0x1400);
		var1 = data_ov031_02290cf8;
	} while (*(unsigned short*)(var1 + 0x1600 + 0x8c) != 2);

	*(Struct_ov031_02249204*)(var1 + 0x1648) = data_ov031_02249204;
	*(unsigned int*)(var1 + 0x1648) = (unsigned int)(var1 + 0xf00);

	*(unsigned short*)(data_ov031_02290cf8 + 0x1600 + 0x50) = func_020d4be8();

	return func_ov031_022358b4() != 0;
}
