#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d0808_14096 = 0x3500 };
#else
enum { Enum_ov017_021d0808_14096 = 0x3710 };
#endif

extern "C" void func_ov017_021b996c(int a, int b, unsigned char c, unsigned char d, unsigned short e);
extern "C" void func_ov017_021b9a98(int a, int b, unsigned char c, unsigned char d, unsigned short e);

struct Struct_ov017_021d0808 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	unsigned char pad1;
	unsigned short field8;
};

// USA: func_ov017_021d0808
extern "C" ARM void func_ov017_021d0808(int arg0, Struct_ov017_021d0808* evt, int arg2, unsigned char* base) {
	int var0 = *(int*)(base + Enum_ov017_021d0808_14096);
	if (evt->field6 == 0) {
		func_ov017_021b996c(var0, arg0, evt->field4, evt->field5, evt->field8);
	} else if (evt->field6 == 1) {
		func_ov017_021b9a98(var0, arg0, evt->field4, evt->field5, evt->field8);
	}
}
