#include <globaldefs.h>

struct Struct_02085768 { unsigned int b0 : 1; };

// USA: func_02085768
extern "C" ARM int func_02085768(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return ((struct Struct_02085768*)(obj + 0x2f8))->b0 != 0;
}
