#include <globaldefs.h>

struct Struct_ov031_022148e4 {
	unsigned char unknown_0_0_ : 7;
	unsigned char unknown_0_7_ : 1;
};

// USA: func_ov031_022148e4
extern "C" ARM int func_ov031_022148e4(void* obj) {
	unsigned char i;
	int result;
	result = 0;
	i = 0;
	unsigned int count = *(unsigned char*)((char*)obj + 0xd12);
	if (i < count) {
		do {
			Struct_ov031_022148e4* fb = (Struct_ov031_022148e4*)((char*)obj + 0x447 + i * 4);
			if (!fb->unknown_0_7_) {
				result = i;
				break;
			}
			i++;
		} while (i < count);
	}
	return result;
}
