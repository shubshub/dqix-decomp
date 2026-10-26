#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_ov023_021fcfd0 {
	char pad0[0x1c];
	int result;
};

// USA: func_ov023_021fcfd0
extern "C" ARM int func_ov023_021fcfd0(struct Struct_ov023_021fcfd0 *obj) {
	((Object3D*)((char*)obj + 0x20))->AdvanceEffects();
	return obj->result;
}
