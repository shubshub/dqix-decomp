#include <globaldefs.h>

extern "C" int memcmp(void* a, void* b, int n);
extern char data_ov031_02249b48;

// USA: func_ov031_022157c4
ARM int IsEqualToData8_022157c4(void *p) {
	return memcmp(p, &data_ov031_02249b48, 8) == 0;
}
