#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void*);
struct Struct_ov002_0215505c_2;
extern "C" void func_ov023_021e1318(Struct_ov002_0215505c_2* obj);

// USA: func_ov023_021fc1f4
extern "C" ARM int func_ov023_021fc1f4(void* obj, void* unused, short arg2, short arg3) {
    func_ov023_021f6ed8(obj);
    *(unsigned short*)((char*)obj + 0x4) = 0x12;
    *(unsigned short*)((char*)obj + 0x6) = arg2;
    *(unsigned short*)((char*)obj + 0x8) = arg3;
    func_ov023_021e1318((Struct_ov002_0215505c_2*)((char*)obj + 0x20));
    return 1;
}
