#include <globaldefs.h>
#include "Resource/UiArrayEntry.h"

extern Struct_ov031_022276b4* data_ov031_02290c4c;
extern unsigned short data_ov031_02248976[];
extern unsigned short data_ov031_02248974[];

extern "C" void* func_ov031_0223c560(int a, int b);
extern "C" int func_ov031_022236d0(void);
extern "C" void func_ov031_0223c980(void* obj, int a, int b, int c, int d, int e, int f, int g);
extern "C" unsigned char func_ov031_02227548(void);
extern "C" void func_ov031_0223c7e8(void* obj, int a, int b, int c, int d, void* e);
extern "C" void func_ov031_0223caec(void* ptr);

// USA: func_ov031_02223614
extern "C" ARM void func_ov031_02223614(void* s, unsigned int idx) {
	void* obj = func_ov031_0223c560(0, 0);
	int lookup = func_ov031_022276b4(data_ov031_02290c4c, idx);
	int entry = func_ov031_022236d0();
	func_ov031_0223c980(obj, 0xd, 0x3c, 0xe6, 0x5e, 2, entry, lookup);
	unsigned char f1 = func_ov031_02227548();
	unsigned char f2 = func_ov031_02227548();
	func_ov031_0223c7e8(obj, data_ov031_02248974[f1 * 2], data_ov031_02248976[f2 * 2], 2, 0x209, s);
	func_ov031_0223caec(obj);
}
