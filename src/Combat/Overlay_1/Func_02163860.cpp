#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* a);
extern "C" void func_ov017_021d6134(void* param, int val);
int* FindFreeSlot_0215a818(int* outIdx);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
extern int g_sePlayer;

// USA: func_ov001_02163860  (semantic: Func_02163860)
extern "C" ARM int func_ov001_02163860(void* param, int mode) {
    int id = func_ov017_021d60f4(param);
    if (mode >= 2) {
        int outIdx;
        int* slot = FindFreeSlot_0215a818(&outIdx);
        if (slot != NULL) {
            DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, id, (int)slot);
        }
        func_ov017_021d6134((char*)param + 8, outIdx);
    } else {
        DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, id, 0);
    }
    return 1;
}
