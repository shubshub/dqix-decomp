#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { Enum_ov003_02171cf8_1840 = 0x62c };
enum { Enum_ov003_02171cf8_15176 = 0x3928 };
enum { Enum_ov003_02171cf8_14076 = 0x34ec };
enum { Enum_ov003_02171cf8_17556 = 0x41e4 };
#else
enum { Enum_ov003_02171cf8_1840 = 0x730 };
enum { Enum_ov003_02171cf8_15176 = 0x3b48 };
enum { Enum_ov003_02171cf8_14076 = 0x36fc };
enum { Enum_ov003_02171cf8_17556 = 0x4494 };
#endif


extern "C" void FieldTask_ConnectWifi(void* a, void* b);

struct Struct_ov003_02171cf8 {
	unsigned char unknown_0_;
	char pad1[Enum_ov003_02171cf8_1840 - 0x1];
	unsigned char unknown_730_;
	unsigned char unknown_731_;
	unsigned char unknown_732_;
	unsigned char unknown_733_;
};

// USA: func_ov003_02171cf8
extern "C" ARM void func_ov003_02171cf8(struct Struct_ov003_02171cf8* obj) {
	char* base = (char*)GetGameResources();
	char* p = *(char**)(base + Enum_ov003_02171cf8_15176);
	char* q = *(char**)(base + Enum_ov003_02171cf8_14076);
	FieldTask_ConnectWifi(p, q);
	if (*(int*)(base + Enum_ov003_02171cf8_17556) != 0) return;
	if (((unsigned char*)p)[0x28] != 0) {
		obj->unknown_730_ &= ~0x2;
		obj->unknown_733_ = 1;
	}
	base = (char*)GetGameResources();
	*(int*)(base + Enum_ov003_02171cf8_17556) = 1;
	obj->unknown_0_ = 0;
	obj->unknown_731_ = 2;
	obj->unknown_732_ = 3;
}
