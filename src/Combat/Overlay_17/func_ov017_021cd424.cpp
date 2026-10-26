#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);

struct Struct_ov000_021633b8 {
    unsigned short f0;
    unsigned short f2 : 15;
    unsigned short flag : 1;
    unsigned char f4;
    signed char unknown_5_;
};
extern "C" void func_ov000_021633b8(char* obj, Struct_ov000_021633b8* src);
extern "C" void func_ov000_02163404(void* work, unsigned char val);
extern "C" void func_ov000_02160fa8(void* work, int mask);
typedef void (*Type_ov017_021cd424)(void*, int);

struct Struct_ov017_021cd424 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Struct_ov017_021cd424_2 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    signed char fielda;
    unsigned char unknown_b_;
    signed char fieldc;
};

// USA: func_ov017_021cd424
extern "C" ARM void func_ov017_021cd424(int unused0, Struct_ov017_021cd424_2* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    Struct_ov017_021cd424* r = (Struct_ov017_021cd424*)func_ov017_021b8478(h);
    if (r->field8 != src->field4) return;
    unsigned char* work = (unsigned char*)func_ov017_021b8468(h);
    if (!work) return;
    Struct_ov000_021633b8 e;
    e.f0 = src->field6;
    e.f2 = src->field8;
    e.f4 = src->unknown_b_;
    e.unknown_5_ = src->fieldc;
    func_ov000_021633b8((char*)work, &e);
    if (src->fielda >= 0) {
        ((Type_ov017_021cd424)func_ov000_02163404)(work, src->fielda);
    }
    func_ov000_02160fa8(work, 0x8000);
}
