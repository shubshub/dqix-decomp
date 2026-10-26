#include <globaldefs.h>

struct Struct_ov001_02158470 { char pad[0x1c]; int limit; };
struct Struct_ov001_02158470_2 { char pad[0x44]; int count; };

// USA: func_ov001_02158470
extern "C" ARM int func_ov001_02158470(Struct_ov001_02158470* arg0, Struct_ov001_02158470_2* cnt) {
	int cur = cnt->count;
	int max = arg0->limit;
	if (cur >= max) {
		cnt->count = 0;
		return 0;
	}
	cnt->count = cur + 1;
	return 1;
}
