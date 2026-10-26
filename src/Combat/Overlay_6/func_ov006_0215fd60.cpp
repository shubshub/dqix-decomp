#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_0215fd60_332 = 0x140 };
#else
enum { Enum_ov006_0215fd60_332 = 0x14c };
#endif

extern "C" void __clear(void* buf, int len);
extern "C" void func_02071da4(void* obj, short* arg1, unsigned char* bufA, int val);

// USA: func_ov006_0215fd60
extern "C" ARM void func_ov006_0215fd60(void* obj, short* arr1, unsigned char* arr2, int val) {
	short var0[3];
	unsigned char bufA[3];
	__clear(var0, 6);
	__clear(bufA, 3);
	for (unsigned char i = 0; i < 3; i++) {
		short id = arr1[i];
		if (id > 0) {
			for (unsigned char j = 0; j < 3; j++) {
				short w = var0[j];
				if (id == w) {
					var0[j] = id;
					bufA[j] = (unsigned char)(bufA[j] + arr2[i]);
					break;
				}
				if (w <= 0) {
					var0[j] = id;
					bufA[j] = arr2[i];
					break;
				}
			}
		}
	}
	func_02071da4((char*)obj + Enum_ov006_0215fd60_332, var0, bufA, val);
}
