#include <globaldefs.h>
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);
void ResetOrFindStopwatch_02027288(unsigned char* obj, int id);
extern "C" void func_0202738c(void* a, int b, int c, int d);

// USA: func_ov017_021c6034
ARM void ResetStopwatchesUnlessCurrent_021c6034(signed char* arr) {
#if defined(jpn)
 enum {regionalOffset0=0x4c0};
#else
 enum {regionalOffset0=0x6d0};
#endif
    struct SearchStruct0202c1a4* obj = (struct SearchStruct0202c1a4*)LinkSession_GetInstance();
    signed char idx = LinkSession_GetOwnSlot(obj);
    if (arr[idx] == 1) return;
    int t = (int)GetGameResources() + 0x3000;
    unsigned char* r5 = *(unsigned char**)(t + regionalOffset0);
    for (int i = 0; i < 4; i++) {
        if (arr[i] == 1) {
            ResetOrFindStopwatch_02027288(r5, i);
            func_0202738c(r5, 1, 1, i);
        }
    }
}
