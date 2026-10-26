#include <globaldefs.h>

struct Struct_020b1d70;
extern "C" int func_020c7170(char*, unsigned long, const char*, ...);
extern "C" int func_ov031_0223dd60(unsigned short* dst, unsigned char* src, int maxLen);
extern "C" void func_ov031_0223c8d4(Struct_020b1d70* a, int b, int c, int d, int e, unsigned short* counts, int idx);
extern const char data_ov031_0224bb7c[];

struct Struct_ov031_02230088 { unsigned char pad[0x14]; Struct_020b1d70* field14; };
struct Struct_ov031_02290ca0_13 { unsigned char pad[8]; Struct_ov031_02230088* field8; };
extern Struct_ov031_02290ca0_13 data_ov031_02290ca0;

// USA: func_ov031_02230088
extern "C" ARM void func_ov031_02230088(unsigned char* src, int idx) {
	unsigned short buf2[0x10];
	unsigned char buf[0x10];
	func_020c7170((char*)buf, 0x10, data_ov031_0224bb7c, src[0], src[1], src[2], src[3]);
	func_ov031_0223dd60(buf2, buf, 0x10);
	func_ov031_0223c8d4(data_ov031_02290ca0.field8->field14, 0x5f, idx * 0x1d + 8, 2, 7, buf2, 1);
}
