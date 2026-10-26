#include <globaldefs.h>

extern "C" ARM int func_ov031_0223e38c(unsigned char* dst, const signed char* src, int max);
extern const signed char data_ov031_022493c4[];

// USA: func_ov031_0223e454
extern "C" ARM int func_ov031_0223e454(unsigned char* dst, const signed char* src, int n) {
	unsigned char s[3];
	int total = 0;
	int var2 = func_ov031_0223e38c(s, src, n > 3 ? 3 : n);
	if (var2 > 0) {
		do {
			if (n < 3) s[2] = 0;
			if (n < 2) s[1] = 0;
			unsigned char a = s[0];
			unsigned char b = s[1];
			unsigned char c = s[2];
			int v0 = (a >> 2) & 0xff;
			int v1 = ((a << 4) | (b >> 4)) & 0x3f;
			int v2 = ((b << 2) | (c >> 6)) & 0x3f;
			int v3 = c & 0x3f;
			dst[0] = data_ov031_022493c4[v0];
			dst[1] = data_ov031_022493c4[v1];
			dst[2] = var2 > 1 ? data_ov031_022493c4[v2] : '*';
			src += var2;
			total += 4;
			dst[3] = var2 > 2 ? data_ov031_022493c4[v3] : '*';
			dst += 4;
			n -= var2;
		} while (n != 0 && (var2 = func_ov031_0223e38c(s, src, n > 3 ? 3 : n)) > 0);
	}
	*dst = 0;
	return total;
}
