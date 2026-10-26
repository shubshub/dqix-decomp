#include <globaldefs.h>

class Struct_ov002_021650d4 { public: virtual void inline_ov002_021650d4(); };
typedef void (Struct_ov002_021650d4::*Type_ov002_021650d4)();

struct Struct_ov023_021fd79c { Type_ov002_021650d4 unknown_0_[3]; };
extern const Struct_ov023_021fd79c data_ov023_021fd79c;

// USA: func_ov023_021e7bc4
extern "C" ARM void func_ov023_021e7bc4(Struct_ov002_021650d4 *obj, unsigned int selector, int idx) {
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
	Struct_ov023_021fd79c table = data_ov023_021fd79c;
	(obj->*table.unknown_0_[selector])();
}
