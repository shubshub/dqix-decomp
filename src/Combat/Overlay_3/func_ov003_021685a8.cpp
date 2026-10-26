#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);

#if defined(jpn)
enum { flagOffset = 0x4e8, entriesOffset = 0xe0 };
#else
enum { flagOffset = 0x4ec, entriesOffset = 0xe4 };
#endif
struct Struct_ov003_021685a8 { char pad[flagOffset]; unsigned char unknown_4ec_; };

// USA: func_ov003_021685a8
extern "C" ARM void func_ov003_021685a8(struct Struct_ov003_021685a8* obj) {
	if (obj->unknown_4ec_ == 0) return;
	Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + entriesOffset));
}
