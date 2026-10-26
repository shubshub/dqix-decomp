#include <globaldefs.h>

extern "C" int func_020d0840(void);
extern "C" int func_020d0834(void);
void UnlockCardReadManager(unsigned short, int);
typedef void (*Type_020d0050)(int, int);

// USA: func_020d0050
extern "C" ARM void func_020d0050(int a) {
    if (!func_020d0840()) {
        func_020d0834();
    }
    ((Type_020d0050)&UnlockCardReadManager)(a, 2);
}
