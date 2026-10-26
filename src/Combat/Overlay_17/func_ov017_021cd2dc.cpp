#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void func_ov000_02163344(void* obj, int a1, short a2, unsigned char a3, unsigned short a4, unsigned short a5);
typedef void (*Type_ov017_021cd2dc)(void*, int, unsigned short, unsigned int, unsigned short, unsigned short);

struct Struct_ov017_021cd2dc {
    unsigned char pad[4];
    unsigned short field4 : 16;
    unsigned short field6;
    unsigned short field8;
    unsigned short unknown_a_0_ : 4;
    unsigned short unknown_a_4_ : 12;
    unsigned short unknown_c_0_ : 4;
    unsigned short unknown_c_4_ : 12;
};
struct Struct_ov017_021cd2dc_2 { unsigned char pad[8]; unsigned short field8; };

// USA: func_ov017_021cd2dc
extern "C" ARM void func_ov017_021cd2dc(int unused0, Struct_ov017_021cd2dc* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    obj += 0x3000;
    void* work = *(void**)(obj + regionalOffset0);
    Struct_ov017_021cd2dc_2* r = (Struct_ov017_021cd2dc_2*)func_ov017_021b8478(work);
    if (*(unsigned short*)((char*)r + 8) != src->field4) return;

    void* p = func_ov017_021b8468(work);
    if (!p) return;

    unsigned short var3 = src->unknown_c_0_;
    unsigned short var4 = src->unknown_a_4_;
    unsigned short field6 = src->field6;
    unsigned short field8 = src->field8;

    ((Type_ov017_021cd2dc)func_ov000_02163344)(p, field6, field8, src->unknown_a_0_, var3, var4);
}
