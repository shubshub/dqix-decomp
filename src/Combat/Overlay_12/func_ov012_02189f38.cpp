// KEEP-NAME
#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov012_02189f38_4977 = 0x1341, kTextOffset = 0x1344, Enum_ov012_02189f38_2400 = 0x800, kWindowOffset = 0x90 };
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int);
#else
enum { Enum_ov012_02189f38_4977 = 0x1371, kTextOffset = 0x1374, Enum_ov012_02189f38_2400 = 0x960, kWindowOffset = 0xac };
extern "C" void Window_OpenPane(void*, void*, int, int, int, int, int, int);
#endif

extern "C" void func_ov012_021893b4(void*, int, int, int);
extern "C" void func_ov012_02189fb0(void*, void*, int);

// USA: func_ov012_02189f38
extern "C" ARM void func_ov012_02189f38(char* editor) {
    func_ov012_021893b4(editor, *(unsigned char*)(editor + Enum_ov012_02189f38_4977), 25, 10);
    void* text = *(void**)(editor + kTextOffset);
    memset(text, 0, Enum_ov012_02189f38_2400);
    func_ov012_02189fb0(editor, *(void**)(editor + kTextOffset), 0);
#if defined(jpn)
    Window_OpenPane(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 1, 0, 1, 0);
#else
    Window_OpenPane(editor + kWindowOffset, *(void**)(editor + kTextOffset), 0, 1, 0, 1, 0, 0);
#endif
}
