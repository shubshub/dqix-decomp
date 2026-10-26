#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02158184_505 = 0x1f5 };
enum { Enum_ov003_02158184_504 = 0x1f4 };
#else
enum { Enum_ov003_02158184_505 = 0x1f9 };
enum { Enum_ov003_02158184_504 = 0x1f8 };
#endif

extern "C" int func_ov003_021538e0(void*);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov003_02153874(void* obj);

// USA: func_ov003_02158184
extern "C" ARM void func_ov003_02158184(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char state = *(unsigned char*)(s + Enum_ov003_02158184_505);
    void* p4 = *(void**)(s + 4);

    if (state == 0) {
        signed char b = *(signed char*)((char*)p4 + 0x59);
        int ok = 0;
        if (b < 0) goto check;
        if (b <= 3) ok = 1;
    check:
        if (!ok) {
            *(unsigned char*)(s + Enum_ov003_02158184_504) = 7;
            return;
        }
        *(signed char*)((char*)p4 + 0x59) = -1;
        func_ov003_02153874(p4);
        *(unsigned char*)(s + Enum_ov003_02158184_505) = *(unsigned char*)(s + Enum_ov003_02158184_505) + 1;
        return;
    }
    if (state != 1) return;
    if (func_ov003_021538e0(p4) == 0) return;

    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    func_020dc2d0(0);
    *(unsigned char*)(s + Enum_ov003_02158184_504) = 7;
}
