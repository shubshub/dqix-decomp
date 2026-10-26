#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" void func_ov008_02187278(void* obj, char* dst, int mode, void* extra);
extern "C" void Background_TransferMap(void* p, int flag);
extern "C" void func_ov023_021eb4f4(char* obj);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc*);
struct Struct_ov008_02184968;
extern "C" void func_ov008_021873ac(struct Struct_ov008_02184968* obj, int arg1);

struct Struct_ov008_02184968_2 {
    char pad0[0xb8];
    char* bufPtr;
    char pad1[0xb08 - 0xbc];
    char* unknown_b08_;
    char pad2[0xb10 - 0xb0c];
    signed char b10;
    char pad3[0xb18 - 0xb11];
    int unknown_b18_;
    char pad4[0xb24 - 0xb1c];
    int unknown_b24_;
};

// USA: func_ov008_02184968
extern "C" ARM void func_ov008_02184968(struct Struct_ov008_02184968_2* obj) {
    if (obj->b10 == 0 || obj->b10 == 1 || obj->b10 == 0xe) return;

    if (obj->unknown_b24_ == 0) {
        Background_TransferMap((char*)obj + 0xd0, 0);
    }
    if (obj->unknown_b08_ != 0) {
        func_ov023_021eb4f4(obj->unknown_b08_);
        return;
    }

    if (obj->unknown_b18_ & 0x800) {
        memset(obj->bufPtr, 0, LOW_REGION(0x800, 0x960));
        func_ov008_02187278(obj, obj->bufPtr, 0, 0);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1, 0);
#endif
        obj->unknown_b18_ &= ~0x800;
    }

    func_ov008_021873ac((struct Struct_ov008_02184968*)obj, 1);
    Window_TransferLayers((struct Obj0205d2bc*)((char*)obj + 0x130));
}
