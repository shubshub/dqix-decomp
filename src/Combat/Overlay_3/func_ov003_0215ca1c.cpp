#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0215ca1c_956 = 0x3d4 };
enum { kRegion98 = 0xb0 };
#else
enum { Enum_ov003_0215ca1c_956 = 0x3bc };
enum { kRegion98 = 0x98 };
#endif

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
extern "C" void Window_DrawPanes(Cont0205d228*);
extern "C" void Window_FlushLayers(Cont0205d274*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov003_0215e2a8(char* base);

// USA: func_ov003_0215ca1c
extern "C" ARM void func_ov003_0215ca1c(char* obj) {
    if (*(unsigned char*)(obj + Enum_ov003_0215ca1c_956) == 0) return;
    Window_ClearLayers((Cont0205d1e0*)(obj + kRegion98));
    Window_DrawPanes((Cont0205d228*)(obj + kRegion98));
    func_0205da88(obj + kRegion98, 1, 2, 1);
    Window_FlushLayers((Cont0205d274*)(obj + kRegion98));
    func_ov003_0215e2a8(obj);
}
