#include <globaldefs.h>

struct S021babf8 { unsigned char pad[0x1c]; void* f1c; };

extern "C" void func_ov003_02158d4c(void*);
extern "C" void func_ov017_021ba94c(S021babf8*);

// USA: func_ov017_021babf8
extern "C" ARM void func_ov017_021babf8(S021babf8* obj) {
    void* p = obj->f1c;
    if (p) func_ov003_02158d4c(p);
    func_ov017_021ba94c(obj);
    ((unsigned char*)obj)[1] = 1;
}
