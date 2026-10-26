#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };

struct Struct_020a14fc;
extern "C" void func_020a14fc(struct Struct_020a14fc* obj, void* flag, int count);

struct Struct_020a10cc {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
};

struct Struct_02109d94 {
    unsigned char flags;
    char pad1;
    unsigned short unknown_2_;
    struct Struct_020a14fc* obj;
    void* flag;
    int cond;
};
extern struct Struct_02109d94 data_02109d94;

// USA: func_020a10cc
extern "C" ARM int func_020a10cc(struct Struct_020a10cc* arg0) {
    unsigned short sum = 0;
    unsigned short a = (unsigned short)((Script::Parameter*)&arg0->v0)->ToInt();
    unsigned short b = (unsigned short)((Script::Parameter*)&arg0->v1)->ToInt();
    unsigned short c = (unsigned short)((Script::Parameter*)&arg0->v2)->ToInt();
    unsigned short d = (unsigned short)((Script::Parameter*)&arg0->v3)->ToInt();

    if (data_02109d94.flags & 1) sum += a;
    if (data_02109d94.flags & 2) sum += b;
    if (data_02109d94.flags & 4) sum += c;
    if (data_02109d94.flags & 8) sum += d;

    if (data_02109d94.cond != 0 && data_02109d94.unknown_2_ != 0) {
        sum = data_02109d94.unknown_2_;
    }

    func_020a14fc(data_02109d94.obj, data_02109d94.flag, sum);
    return 1;
}
