#include <globaldefs.h>

extern "C" void* func_ov006_02157368(void* obj, int key);

// USA: func_ov006_0215729c
extern "C" ARM void func_ov006_0215729c(void* obj) {
	void* e;
	e = func_ov006_02157368(obj, 0x50);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v &= ~1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0x4f);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v |= 1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0xe);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v &= ~1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0xf);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v |= 1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0x15);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v &= ~1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0x41);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v &= ~1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
	e = func_ov006_02157368(obj, 0x42);
	if (e != NULL) {
		unsigned char v = *(unsigned char*)((char*)e + 0x16);
		v &= ~1;
		*(unsigned char*)((char*)e + 0x16) = v;
	}
}
