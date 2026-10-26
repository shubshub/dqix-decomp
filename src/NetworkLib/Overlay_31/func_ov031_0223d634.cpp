#include <globaldefs.h>

struct Struct_ov031_0223d634 { unsigned short x, y, w, h; };
struct Struct_ov031_0223d634_2 { unsigned short f0, f1, f2, f3; };

extern "C" int func_ov031_0223d49c(struct Struct_ov031_0223d634_2* p);

// USA: func_ov031_0223d634
extern "C" ARM int func_ov031_0223d634(struct Struct_ov031_0223d634* box) {
	struct Struct_ov031_0223d634_2 range;
	int v = *(unsigned short*)0x27fffa8 & 0x8000;

	if (v >> 15) return 0;

	range.f0 = box->x;
	range.f1 = box->y;
	range.f2 = box->x + box->w;
	range.f3 = box->y + box->h;
	return func_ov031_0223d49c(&range);
}
