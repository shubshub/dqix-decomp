#include <globaldefs.h>

class Struct_ov012_0218adac { public: virtual void inline_ov012_0218adac(); };
typedef void (Struct_ov012_0218adac::*Type_ov012_0218adac)();

struct Struct_ov023_021fd7b4 { Type_ov012_0218adac unknown_0_[3]; };
extern const Struct_ov023_021fd7b4 data_ov023_021fd7b4;

// USA: func_ov023_021e7c58
extern "C" ARM void func_ov023_021e7c58(Struct_ov012_0218adac *obj, unsigned int selector, int idx) {
	char *base = (char*)obj;
	if (*(int*)(base + 0x5d4) == 0) return;
	if (*(int*)(base + 0x5dc) == 0) return;

	int inRange;
	if (idx < 0) goto zero;
	if (idx <= 3) {
		inRange = 1;
		goto check;
	}
zero:
	inRange = 0;
check:
	if (inRange == 0) return;

	*(int*)(base + 0x5f0) = idx;
	Struct_ov023_021fd7b4 table = data_ov023_021fd7b4;
	(obj->*table.unknown_0_[selector])();
}
