#if defined(jpn)
#define R(j,u) (j)
#define func_ov024_021f6f10 func_ov024_021f5c80
#define data_ov023_021ff5b4 data_ov023_021fe83c
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(TaggedNumber02184c30*);
extern "C" int MessageSystem_GetInstance();

// USA: func_ov011_02188158
extern "C" ARM int func_ov011_02188158(TaggedNumber02184c30* a) {
    int v = func_ov011_02184c30(a);
    unsigned char* g = (unsigned char*)MessageSystem_GetInstance();
    *(unsigned char*)(g + 0x1000 + R(0x7fb, 0x9ca)) = (v != 0) ? 1 : 0;
    return 1;
}
