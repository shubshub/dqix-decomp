#include <globaldefs.h>
#include "Resource/GameResources.h"
#if defined(jpn)
enum { Enum_ov003_02171cac_1840 = 0x62c };
enum { Enum_ov003_02171cac_2888 = 0x928 };
#else
enum { Enum_ov003_02171cac_1840 = 0x730 };
enum { Enum_ov003_02171cac_2888 = 0xb48 };
#endif

extern "C" void* func_ov017_0219bf74(void);
extern "C" void func_ov017_021b1d44(void* p, int a, int b);

// USA: func_ov003_02171cac
extern "C" ARM void func_ov003_02171cac(unsigned char* obj) {
	unsigned char result;
	if (!(obj[Enum_ov003_02171cac_1840] & 2)) {
		result = 0;
	} else {
		unsigned char* p = (unsigned char*)GetGameResources() + 0x3000;
		void* five = *(void**)(p + Enum_ov003_02171cac_2888);
		void* var3 = func_ov017_0219bf74();
		func_ov017_021b1d44(five, 0x20, 1);
		*(void**)((unsigned char*)five + 8) = var3;
		result = 9;
	}
	obj[0] = result;
}
