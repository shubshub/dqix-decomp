#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


extern "C" void func_0206b104(void* obj);
#if defined(jpn)
extern "C" void func_0206cba0(void* obj);
struct Struct_02065920 { unsigned char unused:2; unsigned char unknown_0_2_:1; };
#else
extern "C" void func_0206b224(void* obj, int val);
#endif

// USA: func_02065920
extern "C" ARM void func_02065920(unsigned char* obj, unsigned int amount) {
    if (
#if defined(jpn)
        ((Struct_02065920*)(obj + 0x17ff))->unknown_0_2_ != 0
#else
        (obj + 0x1000)[0x9d0] != 0
#endif
        || *(int*)(obj + (IS_JPN ? 0x870 : 0x9a0)) != 4) return;
    obj[(IS_JPN ? 0x7e2 : 0x912)] = 0;
    if (amount < (obj + 0x1000)[(IS_JPN ? 0x78d : 0x95f)]) {
        (obj + 0x1000)[(IS_JPN ? 0x78d : 0x95f)] -= amount;
        return;
    }
    (obj + 0x1000)[(IS_JPN ? 0x78d : 0x95f)] = 0;
    (obj + 0x1000)[(IS_JPN ? 0x7de : 0x9ae)] = 0;
    (obj + 0x1000)[(IS_JPN ? 0x7df : 0x9af)] = 0;
    (obj + 0x1000)[(IS_JPN ? 0x7fe : 0x9cd)] = 1;
    *(int*)(obj + (IS_JPN ? 0xc : 0x40)) = 0;
    *(int*)(obj + (IS_JPN ? 0x10 : 0x44)) = 0;
    func_0206b104(obj);
#if defined(jpn)
    func_0206cba0(obj);
    *(int*)(obj + 0x870) = 5;
#else
    *(int*)(obj + (IS_JPN ? 0x870 : 0x9a0)) = 5;
    func_0206b224(obj, 5);
#endif
}
