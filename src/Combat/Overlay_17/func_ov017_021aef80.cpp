#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int func_0202b900(void* arr, void* buf);
struct Struct_0202bad4_2;
struct Struct_0202bad4;
extern "C" int func_0202bae4(void* obj);
extern "C" struct Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2* base, int index);
extern "C" int memcmp(void* a, void* b, int n);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void* GlobalFlags_GetInstance(void);
extern "C" int* func_020936f8(void);
extern "C" void func_020939dc(void* obj);
extern "C" void func_02094030(int*, short, short, signed char);
extern "C" void func_020daf9c(int a, int b, int c, int d);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov017_021aef80
extern "C" ARM unsigned char func_ov017_021aef80(void* self) {
    GameResources* flags = GetGameResources();
    void* arr = LinkSession_GetInstance();
    int status = func_0202b900(arr, (char*)self + 9);
    int i;
    for (i = 0; i < 6; i++);

    if (status >= 0) {
        int count = func_0202bae4(arr);
        int j;
        for (j = 0; j < count; j++) {
            struct Struct_0202bad4* el = func_0202bad4((struct Struct_0202bad4_2*)arr, j);
            if (el != NULL) {
                int k;
                for (k = 0; k < 6; k++);
                memcmp((char*)el + 4, (char*)self + 9, 6);
            }
        }
    }

    if (status < 0) {
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
        int* g = func_020936f8();
        func_020939dc(g);
        func_02094030(g, 4, -1, 0);
        return 3;
    }

    SetFlags00(flags, 0x40);
    *(short*)((char*)self + 0x12) = 0;
    func_020daf9c(1, 1, 0, 1);
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x800000);
    return 1;
}
