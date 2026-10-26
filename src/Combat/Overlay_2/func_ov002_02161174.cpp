#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#define func_ov002_02161234 func_ov002_02162114
#else
#define RG(u, j) (u)
#endif

extern "C" int MessageSystem_GetInstance();
extern "C" void func_ov002_0215be00(void* base, int a, int b, int c);
extern "C" void func_ov002_02161234(void* base, void* dst, int flag);

struct S020466c8;
extern "C" void func_020466c8(struct S020466c8* p, int v);

#if defined(jpn)
extern "C" void func_0204500c(void* field, void* buf, int p2);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif

struct Struct_ov002_02161174 { char pad[RG(0xbb8, 0xa80)]; int field; };
struct Struct_ov002_02161174_2 { char pad[RG(0x998, 0x868)]; int unknown_998_; };
struct Struct_ov002_02161174_3 { char pad[RG(0x9ca, 0x7fb)]; unsigned char unknown_9ca_; };
struct Struct_ov002_02161174_4 { char pad[RG(0xbd0, 0xa98)]; void* buf; };

// USA: func_ov002_02161174
extern "C" ARM void func_ov002_02161174(char* base) {
    int field = MessageSystem_GetInstance();

    func_ov002_0215be00(base, ((struct Struct_ov002_02161174*)(base + 0x1000))->field & 0xff, 0, 0xf);

    if (*(unsigned char*)(base + 0x1000 + RG(0xc31, 0xaf9)) != 0) {
        memcpy(((struct Struct_ov002_02161174_4*)(base + 0x1000))->buf, *(void**)(base + 0x1000 + RG(0xbd4, 0xa9c)), RG(0x960, 0x800));
    } else {
        memset(((struct Struct_ov002_02161174_4*)(base + 0x1000))->buf, 0, RG(0x960, 0x800));
        func_ov002_02161234(base, ((struct Struct_ov002_02161174_4*)(base + 0x1000))->buf, 0);
    }

    func_020466c8((struct S020466c8*)field, *(int*)(*(int*)base + 0x10));
#if defined(jpn)
    func_0204500c((void*)field, ((struct Struct_ov002_02161174_4*)(base + 0x1000))->buf, 0);
#else
    func_0204500c((void*)field, ((struct Struct_ov002_02161174_4*)(base + 0x1000))->buf, 0, 0xe3);
#endif
    ((struct Struct_ov002_02161174_2*)field)->unknown_998_ = 1;

    if (*(short*)(base + RG(0x1c28, 0x1af0)) == 0x232b) {
        ((struct Struct_ov002_02161174_3*)(field + 0x1000))->unknown_9ca_ = 0;
    }
}
