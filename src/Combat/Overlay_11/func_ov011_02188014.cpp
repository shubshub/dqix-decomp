#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" void* MessageSystem_GetInstance();
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

// USA: func_ov011_02188014
extern "C" ARM int func_ov011_02188014(struct TaggedNumber02184c30* params, int count) {
    int value = func_ov011_02184c30(&params[0]);
    *(int*)((char*)MessageSystem_GetInstance() + R(0x86c, 0x99c)) = value;
    return 1;
}
