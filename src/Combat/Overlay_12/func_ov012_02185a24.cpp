#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_ov023_021e7868(void*);
#define func_ov023_021e761c func_ov023_021e7868
const int kProfileWindowOffset = 0x90;
const int kProfileCardOffset = 0xd0c;
#else
const int kProfileWindowOffset = 0xac;
const int kProfileCardOffset = 0xd28;
#endif

struct Cont0205d274;
extern "C" void Window_FlushLayers(Cont0205d274*);
struct Cont0205d228;
extern "C" void Window_DrawPanes(Cont0205d228*);
struct Cont0205d1e0;
extern "C" void Window_ClearLayers(Cont0205d1e0*);
extern "C" void func_ov023_021e6b04(char*);
extern "C" void func_ov023_021e761c(void*);
extern "C" void func_0205da88(void*, int, int, int);
extern "C" void func_ov023_021e67f4(char*);
extern "C" void func_ov023_021e68cc(char*);
extern "C" void func_ov023_021e6a14(char*);
extern "C" void func_ov023_021e6a90(void*);

// USA: func_ov012_02185a24
extern "C" ARM void func_ov012_02185a24(char* obj) {
    func_ov023_021e761c(obj + kProfileCardOffset);
    Window_ClearLayers((Cont0205d1e0*)(obj + kProfileWindowOffset));
    Window_DrawPanes((Cont0205d228*)(obj + kProfileWindowOffset));
    func_0205da88(obj + kProfileWindowOffset, 1, 2, 1);
    func_0205da88(obj + kProfileWindowOffset, 1, 3, 1);
    func_0205da88(obj + kProfileWindowOffset, 2, 3, 0);
    Window_FlushLayers((Cont0205d274*)(obj + kProfileWindowOffset));
    func_ov023_021e67f4(obj);
    func_ov023_021e68cc(obj);
    func_ov023_021e6a14(obj);
    func_ov023_021e6a90(obj);
    func_ov023_021e6b04(obj);
}
