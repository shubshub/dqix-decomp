#include <globaldefs.h>

extern "C" int func_ov031_022415a8(const char* s);
extern "C" int func_ov031_0223ffb0(void* obj, const char* name, int len);
extern "C" int func_ov031_0223fe20(void* dst, void* arg1, const char* name, int size);

// USA: func_ov031_02240074
extern "C" ARM int func_ov031_02240074(int* obj, void* arg1, const char* name) {
	int result = 0;
	if (*obj != 0) {
		return result;
	}
	int len = func_ov031_022415a8(name);
	if (func_ov031_0223ffb0(obj, name, len) != 0) {
		result = func_ov031_0223fe20((char*)obj + 0x38, arg1, name, 0x18);
		if (result != 0) {
			void* p1 = *(void**)((char*)obj + 0x38);
			void* p2 = *(void**)p1;
			*(int*)((char*)p2 + 0x10) = len;
		}
	}
	return result;
}
