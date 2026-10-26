#include <globaldefs.h>
#include "NitroSDK/Memory.h"

extern "C" void VCountIrq_PushDisable(void);
extern "C" int WH_GetSystemState(void);
extern "C" int func_0202dcd4(int arg);
extern "C" int func_0202dcb4(int arg);
extern "C" void VCountIrq_PopDisable(void);

// Main, originally func_0202bf40 (USA 0x0202bf40, EUR 0x0202bf50, JPN 0x0202baf0)
extern "C" ARM void LinkSession_ShareRecords(void* obj) {
    VCountIrq_PushDisable();
    if (WH_GetSystemState() == 5) {
        if (func_0202dcd4((int)((char*)obj + 0x7c0))) {
            char* recs = (char*)obj + 0xbc0;
            for (unsigned short i = 0; i < 4; i++) {
                int r = func_0202dcb4(i);
                int off = i * 0x74;
                if (r != 0) {
                    VectorizedInvertedMemcpy((void*)r, recs + off, 0x74);
                    *(int*)((char*)obj + i * 4 + 0xfc4) = 1;
                } else {
                    *(unsigned short*)(recs + off) &= ~0x18;
                    *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
                }
            }
            *(int*)((char*)obj + 0xfc0) = 0;
        } else {
            for (unsigned short i = 0; i < 4; i++) *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
            *(int*)((char*)obj + 0xfc0) = 1;
        }
    } else {
        for (unsigned short i = 0; i < 4; i++) *(int*)((char*)obj + i * 4 + 0xfc4) = 0;
        *(int*)((char*)obj + 0xfc0) = 0;
    }
    VCountIrq_PopDisable();
}
