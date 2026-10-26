#include <globaldefs.h>

#if defined(jpn)
#define OBJ_OFS 0x18
#else
#define OBJ_OFS 0
#endif

// USA: func_ov003_0215ca90
extern "C" ARM void func_ov003_0215ca90(void* obj, int v) {
    *(int*)((char*)obj + 0x3c8 + OBJ_OFS) = v;
    *(int*)((char*)obj + 0x3cc + OBJ_OFS) = v * (*((unsigned char*)obj + 0x3c3 + OBJ_OFS));
}
