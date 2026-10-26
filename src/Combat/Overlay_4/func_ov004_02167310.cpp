#include <globaldefs.h>

struct Struct_0208d994;
struct Struct_0208bf78_5;
struct Obj02046574;

extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_02046380(void* g);
extern "C" int func_ov004_021666bc(void*, int*);
extern "C" Struct_0208d994* func_0208d994(Struct_0208bf78_5*, int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);

#if defined(jpn)
extern void* data_ov004_0217101c[2];
#define CurrentBase0217101c data_ov004_0217101c[1]
#else
extern void* data_ov004_0217101c;
#define CurrentBase0217101c data_ov004_0217101c
#endif

// USA: func_ov004_02167310
extern "C" ARM int func_ov004_02167310(void* a) {
    void* list = CurrentBase0217101c;
    int g = MessageSystem_GetInstance();
    func_02046380((void*)g);
    int local;
    int key = func_ov004_021666bc(a, &local);
    Struct_0208d994* e = func_0208d994((Struct_0208bf78_5*)((char*)list + 0xc), key);
    if (e) {
        MessageSystem_SetStringArgument((Obj02046574*)g, 0, *(char**)((char*)e + 0x4));
    }
    return 0;
}
