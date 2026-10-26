#include <globaldefs.h>

extern "C" void func_ov023_021ecdfc(void*);
struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
struct Cont0205d228;
extern "C" void Window_DrawPanes(Cont0205d228*);
struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);
extern "C" void func_ov023_021ecf78(void*);

// USA: func_ov023_021eb4b8
extern "C" ARM void func_ov023_021eb4b8(void* obj) {
    if (*(unsigned char*)((char*)obj + 0x431) == 0) return;
    func_ov023_021ecdfc(obj);
    Window_ClearLayers((Cont0205d1e0*)((char*)obj + 0xc4));
    Window_DrawPanes((Cont0205d228*)((char*)obj + 0xc4));
    Window_FlushLayers((Cont0205d274*)((char*)obj + 0xc4));
    func_ov023_021ecf78(obj);
}
