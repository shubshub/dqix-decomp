#include <globaldefs.h>

extern "C" int func_ov031_02213800(void* obj);
extern "C" int strncmp(const void*, const void*, unsigned int);

struct Struct_ov031_02213694 {
	unsigned char field0;
	unsigned char field1;
	unsigned char field2;
	unsigned char unknown_3_;
	char field4[0x20];
};

// USA: func_ov031_02213894
extern "C" ARM int func_ov031_02213894(char* obj, int count, struct Struct_ov031_02213694* arr) {
	if (*(unsigned short*)(obj + 0xa) == 0x20) {
		int r = func_ov031_02213800(obj);
		if (r > 0) return r;
	}
	int i = 0;
	if (count > 0) {
		unsigned short var2 = *(unsigned short*)(obj + 0xa);
		do {
			if ((unsigned char)var2 == arr->unknown_3_) {
				if (strncmp(obj + 0xc, arr->field4, var2) == 0) {
					return arr->field1;
				}
			}
			i++;
			arr++;
		} while (i < count);
	}
	return -1;
}
