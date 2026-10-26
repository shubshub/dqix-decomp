#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02178548_2204 = 0x818 };
enum { Enum_ov003_02178548_4102 = 0xf82 };
enum { Enum_ov003_02178548_4116 = 0xf90 };
enum { Enum_ov003_02178548_2101 = 0x7b1 };
enum { Enum_ov003_02178548_2048 = 0x700 };
enum { Enum_ov003_02178548_72 = 0xc4 };
enum { Enum_ov003_02178548_4096 = 0xf00 };
enum { Enum_ov003_02178548_58 = 0xb6 };
#else
enum { Enum_ov003_02178548_2204 = 0x89c };
enum { Enum_ov003_02178548_4102 = 0x1006 };
enum { Enum_ov003_02178548_4116 = 0x1014 };
enum { Enum_ov003_02178548_2101 = 0x835 };
enum { Enum_ov003_02178548_2048 = 0x800 };
enum { Enum_ov003_02178548_72 = 0x48 };
enum { Enum_ov003_02178548_4096 = 0x1000 };
enum { Enum_ov003_02178548_58 = 0x3a };
#endif


extern "C" short func_02080468(void* obj, int id);

// USA: func_ov003_02178548
extern "C" ARM void func_ov003_02178548(unsigned char* self) {
	void* var0 = *(void**)(self + Enum_ov003_02178548_2204);
	short var1 = func_02080468(var0, 3);
	short var2 = *(short*)(self + Enum_ov003_02178548_4102);
	int diff = var2 - var1;
	short mult = *(short*)(self + Enum_ov003_02178548_4116);
	short idx = (short)(mult * 6 + diff);

	unsigned char byteVal = *(unsigned char*)(self + Enum_ov003_02178548_2101);
	if ((int)byteVal <= (int)idx) {
		idx = (short)(byteVal - 1);
	}

	short v = *(short*)(self + Enum_ov003_02178548_2048 + idx * 2 + Enum_ov003_02178548_72);
	*(short*)(self + Enum_ov003_02178548_4096 + Enum_ov003_02178548_58) = v;

	short id2 = func_02080468(var0, 3);
	int rem = idx % 6;
#if defined(jpn)
	*(short*)(self + 0xf00 + 0x82) = (short)(rem + id2);
#else
	*(short*)(self + 0x1000 + 6) = (short)(rem + id2);
#endif
}
