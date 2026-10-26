#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue840_860 = 0x860 };
#else
enum { kRegionValue840_860 = 0x840 };
#endif


struct Struct_0209859c;
extern "C" struct Struct_0209859c* func_0209859c(struct Struct_0209859c* list, void* key);
extern "C" void* Zone3D_GetInstance(void* obj);

struct Struct_ov003_02170d88_13 {
	unsigned char pad0[0x8];
	unsigned char keys[0x32][0x8];
	unsigned char pad1[0x198 - (0x8 + 0x32 * 0x8)];
	unsigned char unknown1_198_;
};

// USA: func_ov003_02171f80
extern "C" ARM void func_ov003_02171f80(struct Struct_ov003_02170d88_13* obj) {
	unsigned char* list = (unsigned char*)Zone3D_GetInstance(obj);
	unsigned char* key = obj->keys[0];
	int i = 0;
	while (i < 0x32) {
		if (func_0209859c((struct Struct_0209859c*)(list + kRegionValue840_860), key) == NULL) {
			memset(key, 0, 8);
			obj->unknown1_198_ -= 1;
		}
		i++;
		key += 8;
	}
}
