#include <globaldefs.h>

extern "C" int func_ov031_02206e0c(void* obj);
extern "C" ARM int func_ov031_022077cc(int a, unsigned int* out);

struct Struct_ov031_02240fc8 {
    char pad0[8];
    int field8;
    int fieldc;
    char pad1[0x24 - 0xc - 4];
    char* field24;
};

// USA: func_ov031_02240fc8
extern "C" ARM int func_ov031_02240fc8(Struct_ov031_02240fc8* obj) {
    char* p = obj->field24;
    int idx = obj->fieldc;
    signed char saved = p[idx];
    p[idx] = 0;
    int off = (obj->field8 != 0) ? 8 : 7;
    char* base = obj->field24;
    unsigned int var5;
    int var6;
    if (func_ov031_022077cc((int)(base + off), &var5) != 0) {
        var6 = (int)var5;
    } else {
        int v = func_ov031_02206e0c(base + off);
        if (v == 0) return 0;
        unsigned int w = (unsigned int)v;
        var6 = (int)(((w >> 24) & 0xff) | ((w >> 8) & 0xff00) | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000));
    }
    obj->field24[obj->fieldc] = saved;
    return var6;
}
