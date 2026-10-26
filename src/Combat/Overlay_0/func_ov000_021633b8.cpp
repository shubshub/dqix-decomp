#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5af0
#define REGION_OFFSET_1 0x5ac0
#else
#define REGION_OFFSET_0 0x5900
#define REGION_OFFSET_1 0x58d0
#endif


struct Struct_ov000_021633b8 { unsigned short f0; unsigned short f2; unsigned char f4; signed char unknown_5_; };

// USA: func_ov000_021633b8
extern "C" ARM void func_ov000_021633b8(char* obj, struct Struct_ov000_021633b8* src) {
    unsigned char* var0 = (unsigned char*)(obj + REGION_OFFSET_0);
    unsigned char idx = (*var0)++;
    struct Struct_ov000_021633b8* dest = (struct Struct_ov000_021633b8*)(obj + REGION_OFFSET_1) + idx;
    dest->f0 = src->f0;
    dest->f2 = src->f2;
    dest->f4 = src->f4;
    dest->unknown_5_ = src->unknown_5_;
}
