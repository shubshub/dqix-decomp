#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov004_02153978;
extern "C" void* func_ov023_021f6590(void*);
extern "C" unsigned int func_ov023_021f6f08(Struct_ov004_02153978*);
typedef void* (*Type_ov004_0215513c)(void*, int);

// USA: func_ov004_0215513c
#pragma optimize_for_size off
extern "C" ARM int func_ov004_0215513c(void* obj, short* pB, short* arg2, short* arg3) {
    *arg3 = -1;
    short v = *arg3;
    *arg2 = v;
    *pB = v;
    void* result = ((Type_ov004_0215513c)func_ov023_021f6590)(obj, 5);
    if (!result) return (int)result;
    unsigned int kind = func_ov023_021f6f08((Struct_ov004_02153978*)result);
    switch (kind) {
        case 0x1a:
            *pB = 0;
            return 0;
        case 0x1b:
            *arg2 = 8;
            return 8;
        case 0x1c:
            kind = 9;
            *arg2 = 9;
            break;
    }
    return kind;
}
