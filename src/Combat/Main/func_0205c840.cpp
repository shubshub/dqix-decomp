#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0205c73c;
extern "C" void func_0205c73c(struct Struct_0205c73c* p);
struct Struct_0205c53c;
extern "C" void func_0205c564(struct Struct_0205c53c* s);
struct Struct_02042c68;
extern "C" void func_02042fcc(struct Struct_02042c68* p);
extern "C" int MessageSystem_GetInstance(void);
#if defined(jpn)
extern "C" void func_020471d0(void* base, int a, void* dest, int size);
#else
extern "C" void func_020462d0(void* base, void* dest, int size);
#endif

// USA: func_0205c840
extern "C" ARM void func_0205c840(char* obj) {
    unsigned char* base = (unsigned char*)MessageSystem_GetInstance();
    base[RG(0x19b0, 0x17e0)] = 0;

    func_0205c73c((struct Struct_0205c73c*)(obj + 0x4));
    func_0205c564((struct Struct_0205c53c*)(obj + 0x1c));
    func_02042fcc((struct Struct_02042c68*)(obj + 0xb4));

    *(int*)(obj + 0xd0) = 0;

    if (*(unsigned char*)(obj + RG(0x232, 0x1c2)) != 0) {
        unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
        for (int i = 0; i < *(unsigned char*)(obj + RG(0x232, 0x1c2)); i++) {
            unsigned short idx = *(unsigned short*)(obj + RG(0x220, 0x1b0) + i * 2);
#if defined(jpn)
            func_020471d0(g, 0xc, (unsigned short*)(obj + 0x120) + idx, 0x100);
#else
            func_020462d0(g, (unsigned short*)(obj + 0x120) + idx, 0x100);
#endif
        }
    }

    memset(obj + 0x120, 0, RG(0x100, 0x90));
    memset(obj + RG(0x220, 0x1b0), 0, 0x10);

    *(short*)(obj + RG(0x230, 0x1c0)) = 0;
    *(unsigned char*)(obj + RG(0x232, 0x1c2)) = 0;
    *(unsigned char*)(obj + RG(0x233, 0x1c3)) = 0;
    *(unsigned char*)(obj + RG(0x234, 0x1c4)) = 0;
}
