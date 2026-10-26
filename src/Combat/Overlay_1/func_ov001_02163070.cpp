#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);
extern "C" int func_020aad1c(int a, int b, int c, int d);
extern "C" void func_ov017_021d6134(void* obj, int flag);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);

struct Struct_ov001_021658b8_15 { char pad[0x4b4]; int unknown_4b4_; int unknown_4b8_; };
extern struct Struct_ov001_021658b8_15 data_ov001_021658b8;

// USA: func_ov001_02163070
extern "C" ARM int func_ov001_02163070(void* obj) {
    if (data_ov001_021658b8.unknown_4b4_ == 0) {
        return 0;
    }
    unsigned int* p = (unsigned int*)GlobalFlags_GetInstance();
    FlagWord_SetBits(p, 0x80);
    int r = func_020aad1c(data_ov001_021658b8.unknown_4b4_, data_ov001_021658b8.unknown_4b8_, 0xa, 0);
    int cond = (r != 0);
    func_ov017_021d6134(obj, cond == 0);
    if (cond != 0) {
        FlagWord_ClearBits((FlagWord020466f4*)p, 0x80);
    }
    return 1;
}
