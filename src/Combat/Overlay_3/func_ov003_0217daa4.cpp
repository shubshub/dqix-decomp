#include <globaldefs.h>
#if defined(jpn)
enum { kRegion90 = 0x8c };
#else
enum { kRegion90 = 0x90 };
#endif

extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_0204359c(void* obj, int count);
extern "C" void func_020439b0(void* obj, int flag);
struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc* obj);

// USA: func_ov003_0217daa4
extern "C" ARM void func_ov003_0217daa4(char* obj) {
    int g = MessageSystem_GetInstance();
    func_0204359c((void*)g, 2);
    func_020439b0((void*)g, 0);
    struct Obj0205d2bc* p = *(struct Obj0205d2bc**)(obj + kRegion90);
    if (p == 0) return;
    if (*(signed char*)(obj + 4) == 2 || *(signed char*)(obj + 5) == 0) {
        Window_TransferLayers(p);
    }
}
