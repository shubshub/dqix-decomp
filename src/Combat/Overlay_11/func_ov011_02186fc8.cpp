#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(unsigned char* node, unsigned int id);

struct Struct_ov011_021844a4;
extern "C" int func_ov011_021844a4(struct Struct_ov011_021844a4* obj, void* p1, unsigned int size);

// USA: func_ov011_02186fc8
extern "C" ARM int func_ov011_02186fc8(struct TaggedNumber02184c30* arg0) {
    int key = func_ov011_02184c30(arg0);
    void* ctx = func_ov017_021b2164();
    if (func_ov011_021845f8((unsigned char*)ctx, key) == 0) return 0;
    int a = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    int b = func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 0x10));
    return func_ov011_021844a4((struct Struct_ov011_021844a4*)ctx, (void*)key, (a * b) << 5) == 0;
}
