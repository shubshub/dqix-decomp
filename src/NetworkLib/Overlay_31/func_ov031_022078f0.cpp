#include <globaldefs.h>

extern "C" int func_ov031_02207180(void* v);
extern "C" int func_ov031_02207970(void* obj, void* v);

struct Struct_ov031_022078f0 {
	char pad0[0x70];
	short unknown_70_;
	char unknown_72_;
	signed char unknown_73_;
};

// USA: func_ov031_022078f0
extern "C" ARM int func_ov031_022078f0(Struct_ov031_022078f0* obj, void* v) {
	if (func_ov031_02207180(obj)) {
		return ~0x1b;
	}
	signed char f = obj->unknown_73_;
	int match = 1;
	if (f != 0) {
		if (f != 4) {
			match = 0;
		}
	}
	if (!match) {
		return ~0x1b;
	}
	int ok = 0;
	if (obj == NULL) goto checkOk;
	if (!(obj->unknown_70_ & 1)) goto checkOk;
	ok = 1;
checkOk:
	if (!ok) {
		return ~0x26;
	}
	if (*(volatile short*)&obj->unknown_70_ & 2) {
		return ~0x1b;
	}
	return func_ov031_02207970(obj, v);
}
