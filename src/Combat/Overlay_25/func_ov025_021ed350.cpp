#include <globaldefs.h>

// USA: func_ov025_021ed350
extern "C" ARM void func_ov025_021ed350(char* obj, int idx, unsigned short val) {
    *(unsigned short*)(obj + idx * 2 + 0x80) = val;
}
