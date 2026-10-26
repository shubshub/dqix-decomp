#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern char data_ov034_022a2a6c[12];

// USA: func_ov034_022a2180
extern "C" ARM void func_ov034_022a2180(void* buffer, unsigned int size, int arg) {
	((BackgroundLoader*)(&data_ov034_022a2a6c))->Populate(buffer, size, arg);
}
