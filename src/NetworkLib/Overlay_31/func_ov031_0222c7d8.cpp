#include <globaldefs.h>

extern "C" void func_ov031_0223521c(void);
extern "C" void func_ov031_022238cc(void);
extern "C" int FastIntModulus(int arg0, int arg1);
extern "C" void func_ov031_0222c660(void);
extern "C" void func_ov031_0222c3b4(void);
extern "C" int FastIntDivide(int arg0, unsigned int arg1);
extern "C" void func_ov031_022351f8(int a);
extern "C" void func_ov031_02235204(void);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0223e2c0(int idx, void* obj);

struct Struct_ov031_0222c7d8 {
	unsigned char pad[0x38];
	int field38;
	unsigned char pad2[0x40 - 0x38 - 4];
	unsigned short field40;
	unsigned char pad3[0x53 - 0x40 - 2];
	unsigned char unknown_53_;
};
struct Struct_ov031_02290c8c_15 { unsigned char pad[2]; unsigned short field2; Struct_ov031_0222c7d8* field4; };
extern Struct_ov031_02290c8c_15 data_ov031_02290c8c;

// USA: func_ov031_0222c7d8
extern "C" ARM void func_ov031_0222c7d8(void* obj) {
	func_ov031_0223521c();
	func_ov031_022238cc();
	data_ov031_02290c8c.field2 += 4;
	int rem = FastIntModulus(data_ov031_02290c8c.field2, 0x1c);
	if (rem >= 4) {
		func_ov031_0222c660();
		return;
	}
	data_ov031_02290c8c.field2 -= rem;
	func_ov031_0222c3b4();
	int v = FastIntDivide(data_ov031_02290c8c.field2 * data_ov031_02290c8c.field4->unknown_53_, data_ov031_02290c8c.field4->field40);
	func_ov031_022351f8(v);
	func_ov031_02235204();
	func_ov031_0222c8cc();
	data_ov031_02290c8c.field4->field38 = 0;
	func_ov031_0223e2c0(0, obj);
}
