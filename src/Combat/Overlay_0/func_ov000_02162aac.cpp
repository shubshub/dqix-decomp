#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7e4
#define REGION_OFFSET_1 0x218
#define REGION_OFFSET_2 0x31c
#define REGION_OFFSET_3 0x3400
#else
#define REGION_OFFSET_0 0x5f4
#define REGION_OFFSET_1 0x29c
#define REGION_OFFSET_2 0x760
#define REGION_OFFSET_3 0x3000
#endif

struct Struct_ov000_02162aac {
    signed char f0;
    signed char f1;
    char pad2;
    unsigned char f3;
    signed char f4;
    char pad5;
    short unknown_6_;
    unsigned short f8;
};

extern "C" int func_ov000_021761ec(char* base, int index);
extern "C" void func_ov000_02174428(void* obj, int a, int f0, int f1, int arg4, int arg5, int f4, int f8);

// USA: func_ov000_02162aac
extern "C" ARM void func_ov000_02162aac(void* self, int a, struct Struct_ov000_02162aac* s) {
    int flags = *(int*)((char*)self + 0x5000 + REGION_OFFSET_0);
    if (!(flags & 0x10000)) {
        return;
    }
    if (flags & 0x800000) {
        return;
    }
    void* var1 = *(void**)((char*)self + REGION_OFFSET_1);
    int val1 = *(int*)((char*)var1 + 0x8000 + 0xe20);
    if (val1 == 0) {
        if (*(unsigned char*)((char*)var1 + 0x8000 + 0xe49) == 2) {
            return;
        }
    }
    int var3 = -1;
    int i = 0;
    while (i < 12) {
        int val = func_ov000_021761ec((char*)self + REGION_OFFSET_2 + REGION_OFFSET_3, i);
        if (s->f3 == val) {
            var3 = i;
            break;
        }
        i++;
    }
    func_ov000_02174428((char*)self + REGION_OFFSET_2 + REGION_OFFSET_3, a, s->f0, s->f1, (signed char)var3, s->unknown_6_, s->f4, s->f8);
}
