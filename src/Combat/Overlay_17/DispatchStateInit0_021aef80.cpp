#include <globaldefs.h>
#include "Resource/Brightness.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202b900(void* arr, void* buf);
struct ElementArray0202bad4;
struct Element0202bad4;
int GetField0xc_0202bae4(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
extern "C" int memcmp(void* a, void* b, int n);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
void* GlobalFlags_GetInstance(void);
int* GetGlobal02109030_020936f8(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_02094030(int*, short, short, signed char);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void FlagWord_SetBits(unsigned int* p, unsigned int mask);

// USA: func_ov017_021aef80  (semantic: DispatchStateInit0_021aef80)
extern "C" ARM unsigned char func_ov017_021aef80(void* self) {
    GameResources* flags = GetGameResources();
    void* arr = func_0202ae18();
    int status = func_0202b900(arr, (char*)self + 9);
    int i;
    for (i = 0; i < 6; i++);

    if (status >= 0) {
        int count = GetField0xc_0202bae4(arr);
        int j;
        for (j = 0; j < count; j++) {
            struct Element0202bad4* el = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)arr, j);
            if (el != NULL) {
                int k;
                for (k = 0; k < 6; k++);
                memcmp((char*)el + 4, (char*)self + 9, 6);
            }
        }
    }

    if (status < 0) {
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x8020);
        int* g = GetGlobal02109030_020936f8();
        ResetAndSetFlag0x3c9Bit0_020939dc(g);
        func_02094030(g, 4, -1, 0);
        return 3;
    }

    SetFlags00(flags, 0x40);
    *(short*)((char*)self + 0x12) = 0;
    DispatchWithGlobalContext020daf9c(1, 1, 0, 1);
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 0x800000);
    return 1;
}
