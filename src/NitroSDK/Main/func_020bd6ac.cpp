#include <globaldefs.h>

struct Struct_020bd6ac_2 { char unknown_0_[0x8c]; unsigned char* base; };
extern struct Struct_020bd6ac_2* data_02110370;

struct Struct_020bd6ac { int count; int offsets[1]; };

// USA: func_020bd6ac
extern "C" ARM void* func_020bd6ac(int index) {
    unsigned char* p = data_02110370->base;
    int var1 = *(int*)(p + 0x20);
    p = (var1 == 0) ? 0 : p + var1;
    if (p == 0) return 0;
    if (index < 0) return 0;
    struct Struct_020bd6ac* table = (struct Struct_020bd6ac*)p;
    if ((unsigned int)index >= (unsigned int)table->count) return 0;
    int var3 = table->offsets[index];
    unsigned char* var4 = *(unsigned char**)((char*)data_02110370 + 0x8c);
    return var3 == 0 ? 0 : var4 + var3;
}
