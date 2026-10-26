#include <globaldefs.h>
#include <NitroSDK/Memory.h>

struct Struct_020b1d70;
extern "C" ARM int func_ov031_0223dd34(unsigned char* s, int len);
extern "C" void func_ov031_0223c8d4(Struct_020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx);

struct Struct_ov031_0222ff34 { unsigned char pad[0x14]; Struct_020b1d70* field14; };
struct Struct_ov031_02290ca0_12 { unsigned char pad[8]; Struct_ov031_0222ff34* field8; };
extern Struct_ov031_02290ca0_12 data_ov031_02290ca0;

// USA: func_ov031_0222ff34
extern "C" ARM void func_ov031_0222ff34(unsigned char* str, int idx) {
	unsigned short buf[0x11];
	VectorizedMemset(buf, 0, sizeof(buf));
	int len = func_ov031_0223dd34(str, 0x20);
	int n = len <= 0x10 ? len : 0x10;
	int i = 0;
	if (n > 0) {
		do {
			unsigned char c = str[i];
			if (c == ' ') buf[i] = 0xe01d;
			else buf[i] = c;
			i++;
		} while (i < n);
	}
	int y = idx * 0x1d + 2;
	if (len <= 0x10) y += 5;
	func_ov031_0223c8d4(data_ov031_02290ca0.field8->field14, 0x48, y, 2, 8, buf, 1);
	if (len <= 0x10) return;
	VectorizedMemset(buf, 0, sizeof(buf));
	len -= 0x10;
	int j = 0;
	if (len > 0) {
		do {
			unsigned char c = *(str + j + 0x10);
			if (c == ' ') buf[j] = 0xe01d;
			else buf[j] = c;
			j++;
		} while (j < len);
	}
	func_ov031_0223c8d4(data_ov031_02290ca0.field8->field14, 0x48, y + 0xc, 2, 8, buf, 1);
}
