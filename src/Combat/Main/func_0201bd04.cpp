#include <globaldefs.h>

struct Obj0201b600;
struct Struct_0201b600;
struct Struct02013380 { unsigned short unk0; unsigned short flags; };

extern "C" Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);
extern "C" void BmdjSceneElement_SetShown(Struct02013380* obj, int unused, int clear4);

// USA: func_0201bd04
extern "C" ARM void func_0201bd04(Obj0201b600* obj, unsigned int arg1, int arg2) {
    Struct_0201b600* elem = func_0201b600(obj, arg2, arg1);
    int flag = 0;
    if (arg2 >= 0) flag = arg2 & 0xff;
    if (elem == 0) return;
    BmdjSceneElement_SetShown((Struct02013380*)elem, flag, 1);
}
