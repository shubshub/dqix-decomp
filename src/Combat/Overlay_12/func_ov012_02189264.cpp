#if defined(jpn)
enum { Enum_ov012_02189264_4976 = 0x1340, Enum_ov012_02189264_4892 = 0x1300, Enum_ov012_02189264_4900 = 0x1308, Enum_ov012_02189264_3368 = 0xd0c, Enum_ov012_02189264_5020 = 0x1364 };
#else
enum { Enum_ov012_02189264_4976 = 0x1370, Enum_ov012_02189264_4892 = 0x131c, Enum_ov012_02189264_4900 = 0x1324, Enum_ov012_02189264_3368 = 0xd28, Enum_ov012_02189264_5020 = 0x139c };
#endif

#include <globaldefs.h>
#include "Resource/Brightness.h"

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_ov023_021e7340(void* arg);
extern "C" void func_ov023_021e6594(void* self);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

// USA: func_ov012_02189264
extern "C" ARM void func_ov012_02189264(char* self) {
    GameResources* handle = GetGameResources();
    unsigned char state = *(unsigned char*)(self + Enum_ov012_02189264_4976);
    if (state == 0) {
        SetSubBrightness(handle, ~0xf, 0xf);
        (*(unsigned char*)(self + Enum_ov012_02189264_4976))++;
        return;
    }
    if (state != 1) return;
    if (IsSubBrightnessTransitionActive(handle) != 0) return;

    *(int*)(self + Enum_ov012_02189264_4892) = 0;
    *(int*)(self + Enum_ov012_02189264_4900) = 0;
    func_ov023_021e7340(self + Enum_ov012_02189264_3368);
    func_ov023_021e6594(self);
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);
    ClearFlags00(handle, 0x10);
    *(int*)(self + Enum_ov012_02189264_5020) = 1;
    *(unsigned char*)(self + Enum_ov012_02189264_4976) = 0;
}
