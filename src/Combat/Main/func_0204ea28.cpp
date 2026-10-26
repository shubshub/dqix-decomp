#include <globaldefs.h>

// USA: func_0204ea28
extern "C" ARM int func_0204ea28(short x, short y, short minX, short arg3, short maxX, short arg5) {
    int result = 0;
    if (minX <= x && x < maxX && arg3 <= y && y < arg5) {
        result = 1;
    }
    return result;
}
