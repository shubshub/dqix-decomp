#include <globaldefs.h>

struct Cont0205d1e0;
void Window_ClearLayers(struct Cont0205d1e0* obj);
struct Cont0205d228;
void Window_DrawPanes(struct Cont0205d228* obj);
extern "C" void func_0205da88(void* obj, int a, int b, int c);
struct Cont0205d274;
void Window_FlushLayers(struct Cont0205d274* obj);
extern "C" void func_ov003_0215c32c(void* obj);
extern "C" void func_ov003_0215c464(void* obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc* o);
struct Struct020e2794;
void UpdateEntryIfActive020e2794(struct Struct020e2794* self, void* b);

// USA: func_ov003_02159078  (semantic: RunEntryStateHooks_02159078)
extern "C" ARM void func_ov003_02159078(void* p) {
    char* obj = (char*)p;
    if (*(signed char*)(obj + 0x588) == 0) return;
    if (*(unsigned char*)(obj + 0x587) != 0) return;
    Window_ClearLayers((struct Cont0205d1e0*)(obj + 0xf4));
    Window_DrawPanes((struct Cont0205d228*)(obj + 0xf4));
    func_0205da88(obj + 0xf4, 1, 2, 1);
    Window_FlushLayers((struct Cont0205d274*)(obj + 0xf4));
    func_ov003_0215c32c(obj);
    func_ov003_0215c464(obj);
    if (*(void**)(obj + 0x570) == NULL) return;
    if (!GetInnerFlagBit0020e28dc((struct Outer020e28dc*)*(void**)(obj + 0x570))) return;
    UpdateEntryIfActive020e2794((struct Struct020e2794*)*(void**)(obj + 0x570), obj + 0x98);
}
