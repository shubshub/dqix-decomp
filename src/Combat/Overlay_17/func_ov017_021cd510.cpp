#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
bool GetTreasureMapTypeFromItemID(unsigned short itemID, unsigned char* out);
extern "C" void func_ov000_0216341c(void* work, unsigned char b1, unsigned char b2, short h);
extern "C" void func_ov000_02163404(void* work, unsigned char val);
extern "C" void func_ov000_02160fa8(void* work, int mask);
typedef void (*Type_ov017_021cd424)(void*, int);
typedef void (*Type_ov017_021cd510)(void*, unsigned char, unsigned char, unsigned short);

struct Struct_ov017_021cd510 { unsigned char pad0[8]; unsigned short field8; };
struct Struct_ov017_021cd510_2 { unsigned char pad0[4]; unsigned short field4; unsigned short field6; signed char field8; };

// USA: func_ov017_021cd510
extern "C" ARM void func_ov017_021cd510(int unused0, Struct_ov017_021cd510_2* src, int arg2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    Struct_ov017_021cd510* r = (Struct_ov017_021cd510*)func_ov017_021b8478(h);
    if (r->field8 != src->field4) return;

    unsigned char buf[4];
    if (!GetTreasureMapTypeFromItemID(src->field6, buf)) return;

    unsigned char* work = (unsigned char*)func_ov017_021b8468(h);
    if (!work) return;

    ((Type_ov017_021cd510)func_ov000_0216341c)(work, buf[0], buf[1], *(unsigned short*)(buf + 2));

    if (src->field8 >= 0) {
        ((Type_ov017_021cd424)func_ov000_02163404)(work, src->field8);
    }
    func_ov000_02160fa8(work, 0x8000);
}
