#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02154eec_504 = 0x1f4 };
enum { Enum_ov003_02154eec_516 = 0x200 };
#else
enum { Enum_ov003_02154eec_504 = 0x1f8 };
enum { Enum_ov003_02154eec_516 = 0x204 };
#endif

struct Struct_0207fcb8;
extern "C" unsigned int func_0207fcb8(Struct_0207fcb8*);
struct Struct_020e28dc;
extern "C" unsigned int func_020e28dc(Struct_020e28dc*);
struct Struct_020e2794_2;
extern "C" unsigned int func_020e2794(Struct_020e2794_2*, void*);
struct Struct_0207fd44_2;
extern "C" unsigned int func_0207fd44(Struct_0207fd44_2*);
extern "C" unsigned int func_ov023_021eb4b8(void*);
struct Struct_0207fd00;
extern "C" unsigned int func_0207fd00(Struct_0207fd00*);
extern "C" unsigned int func_0207fe80(unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" unsigned int func_ov003_0215501c(unsigned int);

// USA: func_ov003_02154eec
extern "C" ARM void func_ov003_02154eec(unsigned int self) {
    if (*(unsigned char*)((char*)self + Enum_ov003_02154eec_504) == 0) { return; }
    if (*(unsigned int*)((char*)self + Enum_ov003_02154eec_516) != 0) {
        func_ov023_021eb4b8((void*)(*(unsigned int*)((char*)self + Enum_ov003_02154eec_516)));
    } else {
        unsigned int obj = *(unsigned int*)((char*)self + 0x18);
        if (obj != 0) {
            func_0207fcb8((Struct_0207fcb8*)obj);
            func_0207fd00((Struct_0207fd00*)obj);
            func_0207fe80(obj, 2, 1, 1);
            func_0207fd44((Struct_0207fd44_2*)obj);
        }
    }
    if (*(unsigned int*)((char*)self + 0x1c) != 0 && func_020e28dc((Struct_020e28dc*)(*(unsigned int*)((char*)self + 0x1c))) != 0) {
        func_020e2794((Struct_020e2794_2*)(*(unsigned int*)((char*)self + 0x1c)), (void*)(self + 0x2c));
        return;
    }
    func_ov003_0215501c(self);
}
