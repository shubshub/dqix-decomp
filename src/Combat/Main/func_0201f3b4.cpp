#if defined(jpn)
enum { Enum_0201f3b4_16 = 0xc };
#else
enum { Enum_0201f3b4_16 = 0x10 };
#endif

#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Struct_0201d530 {
    int type;
    union { int i; float f; } value;
};

struct Struct_0201f3b4;
extern "C" void func_02027b5c(struct Struct_0201f3b4* c, unsigned short h, unsigned char b, int w4, int w8);

extern "C" void Zone3D_GetInstance(void);

struct Struct_020fdc4c_2 {
    char pad[Enum_0201f3b4_16];
    void* field10;
};
extern struct Struct_020fdc4c_2 data_020fdc4c;

struct Struct_0201f3b4_2 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Struct_0201d530 v2;
    struct Struct_0201d530 v3;
};

// USA: func_0201f3b4
extern "C" ARM int func_0201f3b4(struct Struct_0201f3b4_2* arg0) {
    float c;
    int a = ((Script::Parameter*)&arg0->v0)->ToInt();
    int b = ((Script::Parameter*)&arg0->v1)->ToInt();
    c = ((Script::Parameter*)&arg0->v2)->ToFloat();
    float d = ((Script::Parameter*)&arg0->v3)->ToFloat();
    Zone3D_GetInstance();
    if (b == 0) return 1;
    float var4;
    if (d > 0.0f) {
        var4 = 4096.0f * d + 0.5f;
    } else {
        var4 = 4096.0f * d - 0.5f;
    }
    float var5;
    if (c > 0.0f) {
        var5 = 4096.0f * c + 0.5f;
    } else {
        var5 = 4096.0f * c - 0.5f;
    }
    func_02027b5c((struct Struct_0201f3b4*)data_020fdc4c.field10, (unsigned short)(a / 100), (unsigned char)b, (int)var5, (int)var4);
    return 1;
}
