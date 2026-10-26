#include <globaldefs.h>

struct Struct_ov023_021d8c60 { char pad[0x11a]; unsigned char unknown_11a_; };

struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d228;
extern "C" void Window_DrawPanes(Cont0205d228*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);

// USA: func_ov023_021d8c60
extern "C" ARM void func_ov023_021d8c60(struct Struct_ov023_021d8c60* obj) {
	unsigned char v = obj->unknown_11a_;
	if (v == 0 || v == 3) return;
	Window_ClearLayers((Cont0205d1e0*)((char*)obj + 0x20));
	Window_DrawPanes((Cont0205d228*)((char*)obj + 0x20));
	Window_FlushLayers((Cont0205d274*)((char*)obj + 0x20));
}
