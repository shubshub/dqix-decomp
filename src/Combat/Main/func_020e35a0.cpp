#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" int func_ov017_02195760(int obj);
extern "C" void func_020e3778(unsigned char* p);
extern "C" void func_ov017_021ced48(int a, unsigned char b);
struct SearchStruct;
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);

// USA: func_020e35a0
extern "C" ARM void func_020e35a0(unsigned char* p) {
    GameState* battleStruct = GameState::GetInstance();
    int obj2 = ((int)GetGameResources());
    int* searchObj = LinkSession_GetInstance();
    if (!LinkSession_IsActive(searchObj)) return;

    if (LinkSession_IsHostOrSolo(searchObj)) {
        int i;
        if (func_ov017_02195760(obj2)) {
            for (i = 0; i < 4; i++) {
                if (p[0] & (1 << i)) {
                    if (i == 0) {
                        func_020e3778(p);
                    } else {
                        func_ov017_021ced48(1, (unsigned char)i);
                    }
                }
            }
            p[1] |= p[0];
            p[0] = 0;
        }
        for (i = 1; i < 4; i++) {
            if (!battleStruct->GetGameObjectByIndex(i) || LinkSession_IsSlotLost((struct SearchStruct*)searchObj, i)) {
                p[0] &= ~(1 << i);
                p[1] &= ~(1 << i);
            }
        }
    } else {
        if (LinkSession_IsSlotLost((struct SearchStruct*)searchObj, 0)) {
            p[2] = 1;
        }
    }
}
