#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct TaggedNumber02184c30;
extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov023_021f6e90(char* obj, int idx, const void* src);

struct Struct_ov011_021882d4 {
    unsigned char count;
    unsigned char pad;
    unsigned short arr[8];
    short field12;
    short field14;
};

// USA: func_ov011_021882d4
extern "C" ARM int func_ov011_021882d4(struct TaggedNumber02184c30* arg0, int n) {
    Struct_ov011_021882d4 buf;
    int i;
    VectorizedMemset(&buf, 0, sizeof(buf));
    buf.field12 = -1;
    buf.field14 = -1;

    int v0 = func_ov011_02184c30(arg0);
    buf.field12 = (unsigned short)func_ov011_02184c30((struct TaggedNumber02184c30*)((char*)arg0 + 8));
    {
        struct TaggedNumber02184c30* p2 = (struct TaggedNumber02184c30*)((char*)arg0 + 0x10);
        arg0 = (struct TaggedNumber02184c30*)((char*)arg0 + 0x18);
        buf.field14 = (unsigned short)func_ov011_02184c30(p2);
    }

    buf.count = (unsigned char)(n - 3);
    for (i = 0; i < buf.count; i++) {
        int v = func_ov011_02184c30(arg0);
        arg0 = (struct TaggedNumber02184c30*)((char*)arg0 + 8);
        if (i < 8) buf.arr[i] = (unsigned short)v;
    }

    func_ov023_021f6e90((char*)func_ov011_021849c8(func_ov017_021b2164()), v0, &buf);
    return 1;
}
