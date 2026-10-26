#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x21c
#define REGION_OFFSET_1 0x57e4
#else
#define REGION_OFFSET_0 0x2a0
#define REGION_OFFSET_1 0x55f4
#endif

struct Combatant020A36A8;
extern "C" int func_020a36a8(struct Combatant020A36A8*);
extern "C" int func_020a1fa8(void);
extern "C" void func_ov026_021dbf04(void*);

struct Struct0216377c { char pad[REGION_OFFSET_0]; unsigned char* unknown_2a0_; };

// USA: func_ov000_0216377c
extern "C" ARM void func_ov000_0216377c(struct Struct0216377c* obj, unsigned char val) {
    unsigned char* p = obj->unknown_2a0_;
    if (!p) return;
    p[0x2a] = val;
    if (func_020a36a8((struct Combatant020A36A8*)obj->unknown_2a0_)) {
        *(int*)((char*)obj + REGION_OFFSET_1) |= 0x40000000;
    }
    if (func_020a1fa8() == 3) {
        func_ov026_021dbf04(obj);
    }
}
