#include <globaldefs.h>

// USA: func_ov023_021e6158
extern "C" ARM void clearModelPart(char* obj, int index) {
    *(short*)(obj + index * 0xac + 0x2) = -1;
}
