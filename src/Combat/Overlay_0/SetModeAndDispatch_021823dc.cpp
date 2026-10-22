#include <globaldefs.h>

struct SePlayer;
extern struct SePlayer g_sePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void SetOrInitField_02182498(void* objRaw, int flag);

// USA: func_ov000_021823dc  (semantic: SetModeAndDispatch_021823dc)
extern "C" ARM void func_ov000_021823dc(unsigned char* obj, int val) {
    if (val > 3) {
        val = 3;
    }
    if (val > 0) {
        unsigned char old = obj[0x6e8];
        if (val == old) {
            if (*(short*)(obj + 0x600 + 0xea) != 0) {
                return;
            }
        }
        obj[0x6e9] = old;
        obj[0x6e8] = val;
        *(short*)(obj + 0x600 + 0xea) = 0x1e;
        *(short*)(obj + 0x600 + 0xec) = 0;
        if (val == 1) {
            SePlayer_Play(&g_sePlayer, 0x1a, 0);
            return;
        }
        if (val == 2) {
            SePlayer_Play(&g_sePlayer, 0x17, 0);
            return;
        }
        SePlayer_Play(&g_sePlayer, 0x18, 0);
        return;
    }
    if (obj[0x6e8] != 0) {
        SetOrInitField_02182498(obj, 1);
        return;
    }
    obj[0x6e9] = 0;
    obj[0x6e8] = 0;
    *(short*)(obj + 0x600 + 0xea) = 0;
}
