#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
struct Struct_ov011_02184c4c;
extern "C" float func_ov011_02184c4c(struct Struct_ov011_02184c4c* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void func_ov023_021fa078(void* obj, void* ctx, unsigned short val, int* arg3, int p5, int p6);

// USA: func_ov011_02186018
extern "C" ARM int func_ov011_02186018(struct TaggedNumber02184c30* arg0) {
    int key = func_ov011_02184c30(arg0);
    int arr[3];
    arr[0] = (int)(4096.0f * func_ov011_02184c4c((struct Struct_ov011_02184c4c*)((char*)arg0 + 8)));
    arr[1] = (int)(4096.0f * func_ov011_02184c4c((struct Struct_ov011_02184c4c*)((char*)arg0 + 0x10)));
    arr[2] = (int)(4096.0f * func_ov011_02184c4c((struct Struct_ov011_02184c4c*)((char*)arg0 + 0x18)));
    int p5 = (int)(4096.0f * func_ov011_02184c4c((struct Struct_ov011_02184c4c*)((char*)arg0 + 0x20)));
    int p6 = (int)(4096.0f * func_ov011_02184c4c((struct Struct_ov011_02184c4c*)((char*)arg0 + 0x28)));
    void* base = func_ov017_021b2164();
    void* var5 = func_ov011_021849c8(base);
    if (!func_ov023_021f6880(var5, key)) return 0;
    void* node2 = func_ov023_021f6880(var5, 0xffff);
    if (!node2) return 0;
    func_ov023_021fa078(node2, base, key, arr, p5, p6);
    return 1;
}
