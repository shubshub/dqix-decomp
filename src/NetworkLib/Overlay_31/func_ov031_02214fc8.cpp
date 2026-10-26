#include <globaldefs.h>

extern "C" int func_ov031_02214520(int mode);
extern "C" int func_ov031_02215150(char* obj);
extern "C" int func_ov031_02214d38(char* obj);
extern "C" void func_ov031_02214b64(int kind);

// USA: func_ov031_02214fc8
extern "C" ARM int func_ov031_02214fc8(char* obj, int mode) {
	switch (mode) {
	case 3: {
		unsigned char count = *(unsigned char*)(obj + 0xd12);
		if (count != 0 || *(unsigned short*)(obj + 0xd00 + 0x16) != 0) {
			if (func_ov031_02214520(1) != 0) {
				mode = 4;
			} else {
				mode = func_ov031_02215150(obj);
			}
		} else {
			unsigned int nibble = ((unsigned int)(unsigned char)obj[0xd0b] << 24) >> 28;
			if (nibble >= 1) {
				mode = 6;
			} else {
				mode = func_ov031_02214d38(obj);
			}
		}
		break;
	}
	case 4:
		mode = func_ov031_02215150(obj);
		break;
	case 5: {
		unsigned int nibble = ((unsigned int)(unsigned char)obj[0xd0b] << 24) >> 28;
		if (nibble >= 1) {
			mode = 6;
		} else {
			mode = func_ov031_02214d38(obj);
		}
		break;
	}
	}

	func_ov031_02214b64(mode);
	return mode;
}
