#include <globaldefs.h>

extern char data_0210f83c;

// USA: func_020bbf4c
extern "C" ARM void func_020bbf4c(int index, int value) {
    *(int*)(&data_0210f83c + index * 0x24) = (unsigned short)value;
}
