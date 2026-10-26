#include <globaldefs.h>

extern "C" void func_ov031_022157f8(int a, void *buf);
extern "C" int memcmp(void *a, void *b, int n);
extern char data_ov031_02249b3c;

// USA: func_ov031_02215718
extern "C" ARM int func_ov031_02215718(int a) {
	unsigned int buf[6];
	func_ov031_022157f8(a, buf);
	return memcmp(buf, &data_ov031_02249b3c, 8) == 0;
}
