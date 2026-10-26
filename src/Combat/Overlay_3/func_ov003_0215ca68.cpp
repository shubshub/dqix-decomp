#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
extern "C" void func_ov003_0215db2c(void* obj);

#if defined(jpn)
enum { flagOffset = 0x3d4, entriesOffset = 0xb0 };
#else
enum { flagOffset = 0x3bc, entriesOffset = 0x98 };
#endif
struct Struct_ov003_0215ca68 { char pad[flagOffset]; unsigned char unknown_3bc_; };

// USA: func_ov003_0215ca68
extern "C" ARM void func_ov003_0215ca68(struct Struct_ov003_0215ca68* obj) {
	if (obj->unknown_3bc_ == 0) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + entriesOffset));
	func_ov003_0215db2c(obj);
}
