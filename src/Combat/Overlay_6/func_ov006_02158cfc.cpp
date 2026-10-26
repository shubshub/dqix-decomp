#if defined(jpn)
#define R(j,u) (j)
#define func_ov006_0215f3d8 func_ov006_021607f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov006_02158cfc { char pad[0x1c]; Struct_ov006_02158cfc *next; };
struct Struct_ov006_02158cfc_2 { char pad[R(0x24, 0x2c)]; Struct_ov006_02158cfc *head; Struct_ov006_02158cfc *unknown_30_; };

// USA: func_ov006_02158cfc
extern "C" ARM void func_ov006_02158cfc(Struct_ov006_02158cfc_2 *obj, Struct_ov006_02158cfc *target) {
	Struct_ov006_02158cfc *node = obj->head;
	Struct_ov006_02158cfc *var1 = node;
	signed char idx = 0;
	while (node) {
		if (idx % 16 == 0) { var1 = node; idx = 0; }
		if (node == target) break;
		idx++;
		node = node->next;
	}
	obj->unknown_30_ = var1;
}
