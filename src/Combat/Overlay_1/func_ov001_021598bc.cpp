#include <globaldefs.h>

struct Struct_ov001_021598bc { char pad[0x10]; int limit; };
struct Struct_ov001_021598bc_2 { char pad[0x64]; int count; };

// USA: func_ov001_021598bc
extern "C" ARM int func_ov001_021598bc(Struct_ov001_021598bc* arg0, Struct_ov001_021598bc_2* cnt) {
	int cur = cnt->count;
	int max = arg0->limit;
	if (cur >= max) {
		cnt->count = 0;
		return 0;
	}
	cnt->count = cur + 1;
	return 1;
}
