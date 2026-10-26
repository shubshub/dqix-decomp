#include <globaldefs.h>

struct Struct_ov015_02190d7c { char pad[0x1a8]; int arr[32]; int count; };

// USA: func_ov015_021931b4
extern "C" ARM void func_ov015_021931b4(struct Struct_ov015_02190d7c* s, int v) {
	s->arr[s->count++] = v;
}
