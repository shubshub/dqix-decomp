#include <globaldefs.h>

struct Struct_ov001_0215af34 { unsigned int type; Struct_ov001_0215af34* link; };
extern "C" void func_ov017_021d6148(Struct_ov001_0215af34* o, unsigned int v);
typedef void (*Type_ov001_0215af34)(Struct_ov001_0215af34*, float);

extern "C" float func_ov017_021d6110(void*);
extern "C" double func_02009424(double);

// USA: func_ov001_0215af34
extern "C" ARM int func_ov001_0215af34(void* obj) {
    float a = func_ov017_021d6110(obj);
    float c = (float)func_02009424((double)(a));
    ((Type_ov001_0215af34)func_ov017_021d6148)((Struct_ov001_0215af34*)((char*)obj + 0x8), c);
    return 1;
}
