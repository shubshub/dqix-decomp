#include <globaldefs.h>

// USA: func_ov013_02184338
extern "C" ARM void* func_ov013_02184338(void* base, unsigned int index) {
	void* result = NULL;
	char* arr = *(char**)((char*)base + 0x40);
	if (arr != NULL) {
		unsigned short count = *(unsigned short*)((char*)base + 0x4e);
		if (index < count) {
			result = arr + index * 0x28;
		}
	}
	return result;
}
