#include <globaldefs.h>

extern "C" void* func_020e3580(void);

struct SearchStruct0202c1a4;
extern "C" signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

extern "C" void func_020e36c4(unsigned char* obj, int bit);
extern "C" void func_020e3778(unsigned char* p);
extern "C" void func_020e3748(unsigned char* obj, int bit);

struct Struct_ov017_021ced84 {
	unsigned char pad0[4];
	unsigned char mode;
	unsigned char unknown_5_;
};

// USA: func_ov017_021ced84
extern "C" ARM void func_ov017_021ced84(int bit, Struct_ov017_021ced84* evt, int arg2, int arg3, struct SearchStruct0202c1a4* extra) {
	unsigned char* obj = (unsigned char*)func_020e3580();
	signed char val = LinkSession_GetOwnSlot(extra);
	if (evt->unknown_5_ != val) {
		return;
	}
	if (evt->mode == 0) {
		func_020e36c4(obj, bit & 0xff);
		return;
	}
	if (evt->mode == 1) {
		func_020e3778(obj);
		return;
	}
	if (evt->mode != 2) {
		return;
	}
	func_020e3748(obj, bit & 0xff);
}
