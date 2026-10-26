#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define R(j,u) (j)
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
#if defined(jpn)
#else
#endif
extern "C" void func_ov008_02187278(void* obj, char* dst, int mode, void* extra);

struct Struct_ov008_02184968 {
    char pad[0xb8];
    char* bufPtr;
    char pad2[0xb18 - 0xbc];
    int flags;
};

// USA: func_ov008_021873ac
extern "C" ARM void func_ov008_021873ac(struct Struct_ov008_02184968* obj, int arg1) {
    if (arg1 == 0) {
        if (!(obj->flags & 0x800)) return;
        memset(obj->bufPtr, 0, R(0x800,0x960));
        func_ov008_02187278(obj, obj->bufPtr, arg1, 0);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 1, (int)obj->bufPtr, 1, 0);
#endif
        obj->flags &= ~0x800;
    } else if (arg1 == 1) {
        if (!(obj->flags & 0x1000)) return;
        memset(obj->bufPtr, 0, R(0x800,0x960));
        func_ov008_02187278(obj, obj->bufPtr, arg1, 0);
#if defined(jpn)
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->bufPtr, 1);
#else
        Window_SetPaneText((struct StructA0205d5d0*)((char*)obj + 0x130), 2, (int)obj->bufPtr, 1, 0);
#endif
        obj->flags &= ~0x1000;
    }
}
