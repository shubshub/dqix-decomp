#include <globaldefs.h>

struct Container020e0310;

extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_Append(char *dst, const char *src);

struct Struct_ov002_02160004 {
    char pad[0x6c];
    int id;
    int cur;
};

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#else
#define RG(usa, jpn) (usa)
#endif

// USA: func_ov002_02160004
extern "C" ARM void func_ov002_02160004(char *p, char *dst) {
    if (dst == NULL) {
        return;
    }

    struct Struct_ov002_02160004 *s = (struct Struct_ov002_02160004 *) (p + RG(0x2c8 + 0xc00, 0xe20));
    int *q      = &s->id;
    short cur   = q[1];
    short id    = q[0];
    if (cur == *(signed char *) (p + RG(0x1c00 + 0x73, 0x1b00 + 0x37))) {
        return;
    }

    int name = KeyTable_Get((struct Container020e0310 *) (p + RG(0x20, 8)), (short) (id + 0xfbe));
    Text_Append(dst, (const char *) name);
}
