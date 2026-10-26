#include <globaldefs.h>

struct Obj0201b600;
struct Struct_0201b600;
struct Struct02013380 { unsigned short unk0; unsigned short flags; };

extern "C" Struct_0201b600* func_0201b600(Obj0201b600*, int, unsigned short);

// USA: func_0201bd74
extern "C" ARM int func_0201bd74(Obj0201b600* obj, unsigned int arg1, int arg2) {
    Struct_0201b600* elem = func_0201b600(obj, arg2, arg1);
    if (elem != 0) {
        return (((Struct02013380*)elem)->flags & 4) == 0;
    }
    return 0;
}
