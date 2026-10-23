#include <globaldefs.h>

struct Obj0205d2bc;
void Window_TransferLayers(struct Obj0205d2bc*);

struct Container021e76a8 { char pad[0x5dc]; int field5dc; };

// USA: func_ov023_021e76a8
ARM void CallInitEntriesIfSet_021e76a8(struct Container021e76a8* obj) {
	if (obj->field5dc == 0) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x78));
}
