#include <globaldefs.h>

extern "C" int func_ov031_02206f08(int a, int b);

// USA: func_ov031_02207538
extern "C" ARM int func_ov031_02207538(unsigned int* a, unsigned int* b) {
	unsigned int wb = *b;
	unsigned int wa = *a;
	unsigned int sa = ((wa >> 24) & 0xff) | ((wa >> 8) & 0xff00) | ((wa << 8) & 0xff0000) | ((wa << 24) & 0xff000000);
	unsigned int sb = ((wb >> 24) & 0xff) | ((wb >> 8) & 0xff00) | ((wb << 8) & 0xff0000) | ((wb << 24) & 0xff000000);
	return func_ov031_02206f08((int)sa, (int)sb);
}
