#include <globaldefs.h>

void LockCardReadManager(unsigned short, int);
typedef void (*Type_020d0040)(int, int);

// USA: func_020d0040
extern "C" ARM void func_020d0040(int x) {
    ((Type_020d0040)&LockCardReadManager)(x, 2);
}
