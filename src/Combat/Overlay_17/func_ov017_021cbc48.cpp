#include <globaldefs.h>

extern "C" void func_ov017_021cbdcc(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cbc48 {
	unsigned short field0;
	unsigned short field2;
	int field4;
	unsigned char field8;
	signed char field9;
	unsigned char fielda;
	unsigned char unknown_b_;
	unsigned char fieldc;
	short unknown_e_;
};

struct Struct_ov017_021cbc48_2 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned short field6;
	int field8;
	unsigned char fieldc;
	signed char unknown_d_;
	unsigned char unknown_e_;
	unsigned char unknown_f_;
	unsigned char field10;
	unsigned char pad1;
	short field12;
};

// USA: func_ov017_021cbc48
extern "C" ARM void func_ov017_021cbc48(Struct_ov017_021cbc48* src) {
	func_ov017_021cbdcc(src);
	void* p = LinkMessageQueue_GetInstance();

	Struct_ov017_021cbc48_2 buf;
	buf.tag = 0x64;
	buf.field4 = src->field0;
	buf.field6 = src->field2;
	buf.field8 = src->field4;
	buf.fieldc = src->field8;
	buf.unknown_d_ = src->field9;
	buf.unknown_e_ = src->fielda;
	buf.unknown_f_ = src->unknown_b_;
	buf.field10 = src->fieldc;
	buf.field12 = src->unknown_e_;
	func_0205e330(p, &buf, 0);
}
