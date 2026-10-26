#include <globaldefs.h>

extern "C" unsigned int GetSubBG0ScreenBase(void);
extern "C" unsigned int GetMainBG1ScreenBase(void);
extern "C" unsigned int GetMainBG2ScreenBase(void);

// USA: func_ov023_021db2b8
extern "C" ARM unsigned int func_ov023_021db2b8(int mode, int layer) {
    if (mode == 1) {
        return GetSubBG0ScreenBase();
    }
    if (layer != 0) {
        return GetMainBG1ScreenBase();
    }
    return GetMainBG2ScreenBase();
}
