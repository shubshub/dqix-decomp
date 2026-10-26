#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);

struct Obj0203c108;
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" int func_ov000_021719f8(int* obj);

// USA: func_ov000_0217f480
extern "C" ARM void func_ov000_0217f480(char* self) {
    char* work = self + 8;
    memset(work + 8, 0, 8);
    *(work + 0x10) = 0;
    char idx = *(self + 0x18);
    *(work + 8 + idx) = 0xd;
    char idx2 = *(work + 0x10);
    idx2 = idx2 + 1;
    *(work + 0x10) = idx2;
    char var3 = *(self + 0x18);
    *(work + 8 + var3) = 0x64;
    *(work + 0x14) = 6;
    *(unsigned short*)(work + 0x1e) = 0;
    if (!func_ov000_021719f8((int*)self)) {
        int fmt = KeyTable_Get(*(struct Container020e0310**)(self + 4), 0x7531);
        CachedTextLabel_SetText((struct Obj0203c108*)(self + 0x50), (char*)fmt);
    }
    *(unsigned char*)(self + 0x24) &= ~4;
}
