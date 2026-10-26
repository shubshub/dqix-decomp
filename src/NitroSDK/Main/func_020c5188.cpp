#include <globaldefs.h>

#if defined(jpn)
#define func_020c5188 func_020c6c54
#endif

extern "C" void func_020c6914(int cmd);

// USA: func_020c5188
extern "C" ARM void func_020c5188(int cmd) {
    *(int*)0x4000400 = 0x17;
    func_020c6914(cmd);
}
