#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov025_021def24_1804 = 0x8fc };
#else
enum { Enum_ov025_021def24_1804 = 0x70c };
#endif

// USA: func_ov025_021def24
extern "C" ARM int func_ov025_021def24(void* obj) {
	unsigned char* base = (unsigned char*)obj;
	return *(int*)(base + 0x7000 + Enum_ov025_021def24_1804);
}
