#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* p);

extern "C" void* func_0203cf4c(void);

struct Struct_0203dce4_2;
struct Struct_0203dce4;
extern "C" struct Struct_0203dce4* func_0203dce4(struct Struct_0203dce4_2* list, int id);

struct Struct_ov001_02165880_17 { int pad0; unsigned char* elems; };
extern struct Struct_ov001_02165880_17 data_ov001_02165880;

// USA: func_ov001_0215d0f4
extern "C" ARM int func_ov001_0215d0f4(void* ctx) {
    int idx = func_ov017_021d60f4(ctx);
    unsigned char* elem = data_ov001_02165880.elems + idx * 0x10;
    int id = *(int*)(elem + 0x4);
    struct Struct_0203dce4* entry = func_0203dce4(
        (struct Struct_0203dce4_2*)func_0203cf4c(), id);
    if (entry == NULL) return 0;
    *(int*)((char*)entry + 0x10) = 0;
    return 1;
}
