#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_020696bc(int p1, int* out, int count);
extern "C" int MessageSystem_GetInstance(void);

struct Struct_020699c4 { void* dst; };

// USA: func_020699c4
extern "C" ARM int func_020699c4(struct Struct_020699c4* ctx, int p1) {
    int buf[3];
    char* g;

    func_020696bc(p1, buf, 3);

    g = (char*)MessageSystem_GetInstance();
    unsigned short v = (unsigned short)buf[2];
    int b1 = (buf[1] != 0);
    int b0 = (buf[0] != 0);
    g[0x1000 + 0x9c6] = b0;
    g[0x1000 + 0x9c7] = b1;
    *(unsigned short*)(g + 0x1800 + 0x7e) = v;

    void* d = ctx->dst;
    unsigned short stage = 0xff1b;
    memcpy(d, &stage, 2);

    return 2;
}
