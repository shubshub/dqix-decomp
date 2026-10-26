#include <globaldefs.h>

struct Struct_ov001_0215af34 { unsigned int type; Struct_ov001_0215af34* link; };
extern "C" void func_ov017_021d6148(Struct_ov001_0215af34* o, unsigned int v);
typedef void (*Type_ov001_0215af34)(Struct_ov001_0215af34*, float);

extern "C" float func_ov017_021d6110(void*);
extern "C" double atan2(double, double);

// USA: func_ov001_0215af8c
extern "C" ARM int func_ov001_0215af8c(void* obj) {
    float a = func_ov017_021d6110(obj);
    float b = func_ov017_021d6110((char*)obj + 0x8);
    double da = (double)a;
    double db = (double)b;
    float c = (float)atan2(da, db);
    ((Type_ov001_0215af34)func_ov017_021d6148)((Struct_ov001_0215af34*)((char*)obj + 0x10), c);
    return 1;
}
