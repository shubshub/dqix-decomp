#include <globaldefs.h>

struct Obj021d8c60 { char pad[0x11a]; unsigned char field11a; };

struct Cont0205d1e0;
void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d228;
void Window_DrawPanes(Cont0205d228*);
struct Cont0205d274;
void Window_FlushLayers(Cont0205d274*);

// USA: func_ov023_021d8c60
ARM void CallIfFieldNot0Or3_021d8c60(struct Obj021d8c60* obj) {
	unsigned char v = obj->field11a;
	if (v == 0 || v == 3) return;
	Window_ClearLayers((Cont0205d1e0*)((char*)obj + 0x20));
	Window_DrawPanes((Cont0205d228*)((char*)obj + 0x20));
	Window_FlushLayers((Cont0205d274*)((char*)obj + 0x20));
}
