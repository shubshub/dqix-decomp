#include <globaldefs.h>

extern "C" int LoadToSubBG2ScreenData(int, int, unsigned int);

// USA: func_020bbb98
extern "C" ARM int func_020bbb98(int a, int b, unsigned int c) {
    return LoadToSubBG2ScreenData(a, b, c);
}
