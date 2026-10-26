#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);

struct Struct_ov002_02155f4c { char pad[0x5dc]; int unknown_5dc_; };

// USA: func_ov023_021e76a8
extern "C" ARM void func_ov023_021e76a8(struct Struct_ov002_02155f4c* obj) {
	if (obj->unknown_5dc_ == 0) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x78));
}
