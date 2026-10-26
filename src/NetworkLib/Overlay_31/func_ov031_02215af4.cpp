#include <globaldefs.h>

// USA: func_ov031_02215af4
extern "C" ARM int func_ov031_02215af4(unsigned int c) {
	if (c >= 'A' && c <= 'Z') return c - 'A';
	if (c >= 'a' && c <= 'z') return (int)(c - 'a') + 26;
	if (c >= '0' && c <= '9') return (int)(c - '0') + 52;
	if (c == '+') return 62;
	if (c == '/') return 63;
	return (c == '=') ? 0 : -1;
}
