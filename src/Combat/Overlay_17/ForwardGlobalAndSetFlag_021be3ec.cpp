#include <globaldefs.h>

extern int g_sePlayer;
void ForwardField0xc0_0205ebec(void* obj);

struct Obj_021be3ec { unsigned char field0; unsigned char field1; };

// USA: func_ov017_021be3ec
ARM void ForwardGlobalAndSetFlag_021be3ec(Obj_021be3ec* obj) {
	ForwardField0xc0_0205ebec(&g_sePlayer);
	obj->field1 = 1;
}
