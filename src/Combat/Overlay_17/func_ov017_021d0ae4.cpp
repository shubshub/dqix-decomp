#include <globaldefs.h>

extern "C" int LinkSession_IsHostOrSolo(int p);
extern "C" void func_ov017_02192654(int a0, unsigned short f4, unsigned char arg2);
extern "C" void func_ov017_021a23b0(int a3, unsigned short f4);

struct Struct_ov017_021d0ae4 {
	unsigned char pad0[4];
	unsigned short f4;
	unsigned char unknown_6_;
};

// USA: func_ov017_021d0ae4
extern "C" ARM void func_ov017_021d0ae4(int a0, Struct_ov017_021d0ae4* obj, int arg2, int a3, int arg4) {
	if (LinkSession_IsHostOrSolo(arg4) != 0) {
		func_ov017_02192654(a0, obj->f4, obj->unknown_6_);
		return;
	}
	if (a0 != 0) {
		return;
	}
	func_ov017_021a23b0(a3, obj->f4);
}
