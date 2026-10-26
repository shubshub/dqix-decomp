#include <globaldefs.h>
#include "Graphics/AlphaTween.h"

struct Struct_02049fec;

// USA: func_02049fec
extern "C" ARM float func_02049fec(char* obj) {
    char* x = *(char**)(obj + 0x13c);
    if (x == NULL) return 0.0f;
    return ((AlphaTween*)((struct Struct_02049fec*)(x + 0x60)))->GetTarget();
}
