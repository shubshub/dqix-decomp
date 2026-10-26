#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


extern "C" int func_020e553c(void* a, int* b, int c, int d);
extern "C" int func_020e5334(int a, int b, int c, int d);

// USA: func_020e54bc
extern "C" ARM int func_020e54bc(int p0, void* p1, int p2, int p3, unsigned char p4, int p5) {
    int tmp;
    int result;
    int var2;

    if (p0 == 0 || p1 == NULL || p2 < 0) {
        return 0;
    }
    if (p4 != 0) {
        BackgroundLoader::AddLockGlobal();
    }
    var2 = func_020e553c(p1, &tmp, p3, p5);
    result = func_020e5334(p0, var2, tmp, p2);
    if (p4 != 0) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return result;
}
