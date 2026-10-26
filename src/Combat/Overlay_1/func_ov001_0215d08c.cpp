#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);

extern "C" void* func_0203cf4c(void);

struct Struct_0203dce4_2;
struct Struct_0203dce4;
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);

struct Struct_ov001_02165880_16 { int pad0; unsigned char* elems; };
extern struct Struct_ov001_02165880_16 data_ov001_02165880;

// USA: func_ov001_0215d08c
extern "C" ARM int func_ov001_0215d08c(void* self) {
    int idx1 = func_ov017_021d60f4(self);
    int idx2 = func_ov017_021d60f4((char*)self + 0x8);
    void* global = func_0203cf4c();
    int id = *(int*)(data_ov001_02165880.elems + idx1 * 0x10 + 0x4);
    struct Struct_0203dce4* entry = func_0203dce4((struct Struct_0203dce4_2*)global, id);
    if (entry == NULL) return 0;
    int val = *(int*)(data_ov001_02165880.elems + idx2 * 0x10 + 0xc);
    if (val == 0) return 0;
    *(int*)((char*)entry + 0x10) = val;
    return 1;
}
