#include <globaldefs.h>

extern "C" int LoadToSubBG3ScreenData(int, int, unsigned int);

// USA: func_020bbb8c
extern "C" ARM int func_020bbb8c(int a, int b, unsigned int c) {
    return LoadToSubBG3ScreenData(a, b, c);
}
