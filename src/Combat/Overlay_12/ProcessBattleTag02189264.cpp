#if defined(jpn)
enum { kStepOffset = 0x1340, kFirstResetOffset = 0x1300, kSecondResetOffset = 0x1308, kCardOffset = 0xd0c, kFinishedOffset = 0x1364 };
#else
enum { kStepOffset = 0x1370, kFirstResetOffset = 0x131c, kSecondResetOffset = 0x1324, kCardOffset = 0xd28, kFinishedOffset = 0x139c };
#endif

#include <globaldefs.h>
#include "Resource/Brightness.h"

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" void func_ov023_021e7340(void* arg);
extern "C" void func_ov023_021e6594(void* self);
void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);

// USA: func_ov012_02189264  (semantic: ProcessBattleTag02189264)
extern "C" ARM void func_ov012_02189264(char* self) {
    GameResources* handle = GetGameResources();
    unsigned char state = *(unsigned char*)(self + kStepOffset);
    if (state == 0) {
        SetSubBrightness(handle, ~0xf, 0xf);
        (*(unsigned char*)(self + kStepOffset))++;
        return;
    }
    if (state != 1) return;
    if (IsSubBrightnessTransitionActive(handle) != 0) return;

    *(int*)(self + kFirstResetOffset) = 0;
    *(int*)(self + kSecondResetOffset) = 0;
    func_ov023_021e7340(self + kCardOffset);
    func_ov023_021e6594(self);
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);
    ClearFlags00(handle, 0x10);
    *(int*)(self + kFinishedOffset) = 1;
    *(unsigned char*)(self + kStepOffset) = 0;
}
