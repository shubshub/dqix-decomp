#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

extern "C" void* func_ov017_021b2164(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" void* func_0203cf4c(void);

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

struct Struct_ov011_021849bc;
extern "C" int func_ov011_021849bc(struct Struct_ov011_021849bc* obj, int mask);
extern "C" void func_ov011_021849ac(void* obj, unsigned int mask);

extern "C" void func_0203e0a0(void* g, unsigned short val);
extern "C" void* func_ov017_0219bf74(void);
extern "C" void func_ov017_021a27e8(void* controller);

struct Struct_0203cfb4;
extern "C" void func_0203cfb4(struct Struct_0203cfb4* obj);

extern "C" void func_ov017_021a316c(int obj);

extern "C" void func_ov017_0219b938(int obj);

// USA: func_ov011_02184cc0
extern "C" ARM int func_ov011_02184cc0(struct TaggedNumber02184c30* arg0) {
    int p1 = (int)GetGameResources();
    struct Struct_ov011_021849bc* obj2 = (struct Struct_ov011_021849bc*)func_ov017_021b2164();
    void* g = func_0203cf4c();
    void* s = Zone3D_GetInstance();

    switch (func_ov011_02184c30(arg0)) {
    case 0:
        if (func_ov011_021849bc(obj2, 1)) return 1;
        func_0203e0a0(g, *(unsigned short*)s);
        func_ov017_0219bf74();
        func_ov011_021849ac(obj2, 1);
        break;
    case 1:
        if (func_ov011_021849bc(obj2, 2)) return 1;
        func_0203e0a0(g, *(unsigned short*)s);
        func_ov017_021a27e8((void*)p1);
        func_0203cfb4((struct Struct_0203cfb4*)g);
        func_ov017_021a316c(p1);
        SetFlags04((GameResources*)p1, 8);
        SetFlags04((GameResources*)p1, 0x10);
        func_ov011_021849ac(obj2, 2);
        break;
    case 2:
        if (func_ov011_021849bc(obj2, 4)) return 1;
        func_ov017_0219b938(p1);
        ((SafeAllocator*)((void*)(p1 + 0x9c)))->Reset();
        func_ov011_021849ac(obj2, 4);
        break;
    }
    return 1;
}
