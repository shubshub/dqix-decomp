#include <globaldefs.h>

struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc*);

struct Obj021d8c94 { char pad[0x11a]; unsigned char field11a; };

// USA: func_ov023_021d8c94
ARM void CallIfFieldNot0Or3_021d8c94(struct Obj021d8c94* obj) {
	unsigned char v = obj->field11a;
	if (v == 0 || v == 3) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x20));
}
