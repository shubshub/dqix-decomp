#include <globaldefs.h>

// USA: func_ov031_0223ff7c
extern "C" ARM char func_ov031_0223ff7c(char c) {
	int v = (unsigned char)(c + 1);
	if (v == '{') {
		v = '0';
	} else if (v == '[') {
		v = 'a';
	} else if (v == ':') {
		v = 'A';
	}
	return (char)v;
}
