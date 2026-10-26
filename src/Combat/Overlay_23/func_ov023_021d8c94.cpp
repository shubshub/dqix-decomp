#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);

struct Struct_ov000_02160ad0 { char pad[0x11a]; unsigned char unknown_11a_; };

// USA: func_ov023_021d8c94
extern "C" ARM void func_ov023_021d8c94(struct Struct_ov000_02160ad0* obj) {
	unsigned char v = obj->unknown_11a_;
	if (v == 0 || v == 3) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x20));
}
