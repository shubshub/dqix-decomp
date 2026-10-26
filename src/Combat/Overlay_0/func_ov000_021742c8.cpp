#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Background_TransferMap(void*, int);
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);

#if defined(jpn)
enum { Enum_ov000_021742c8_7538 = 0x1faa };
#else
enum { Enum_ov000_021742c8_7538 = 0x1d72 };
#endif

// USA: func_ov000_021742c8
extern "C" ARM void func_ov000_021742c8(void* obj) {
    unsigned short flags = *(unsigned short*)((char*)obj + Enum_ov000_021742c8_7538);
    if (!(flags & 0x40)) return;
    if (flags & 0x80) {
        Background_TransferMap((char*)obj + 0x8c4, 0);
        return;
    }
    Background_TransferMap((char*)obj + 0x8a4, 0);
    Background_TransferMap((char*)obj + 0x8c4, 0);
    Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x188));
}
