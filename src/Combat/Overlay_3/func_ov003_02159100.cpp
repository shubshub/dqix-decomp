#include <globaldefs.h>

struct Obj0205d2bc;
extern "C" void Window_TransferLayers(struct Obj0205d2bc* obj);
extern "C" void func_020e2d24(int* obj, int a, int b);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc* o);
struct Struct_020439b0;
extern "C" void func_020e2cc4(struct Struct_020439b0* obj, int enabled);
struct Struct_020e2834;
extern "C" void func_020e2834(struct Struct_020e2834* self);

// USA: func_ov003_02159100
extern "C" ARM void func_ov003_02159100(void* obj) {
    unsigned char* base = (unsigned char*)obj;

    if (*(signed char*)(base + 0x588) == 0) return;
    if (*(unsigned char*)(base + 0x587) != 0) return;

    Window_TransferLayers((struct Obj0205d2bc*)(base + 0xf4));

    if (*(void**)(base + 0x570) == NULL) return;

    unsigned char* r4 = *(unsigned char**)((char*)(*(void**)(base + 0x570)) + 0x10);
    int flag;
    func_020e2d24((int*)(r4 + 0x28), 0x11, 1);
    flag = func_020e28dc((struct Struct_020e28dc*)*(void**)(base + 0x570));
    func_020e2cc4((struct Struct_020439b0*)(r4 + 0x28), flag);
    func_020e2834((struct Struct_020e2834*)*(void**)(base + 0x570));
}
