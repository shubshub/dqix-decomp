#include <globaldefs.h>
#include "Combat/Main/MessageSlotTable.h"

extern "C" void func_020dd8b4(int, int, int, int);

// USA: func_020ddaf4
extern "C" ARM void func_020ddaf4(int a, int b, int c, int d, int e, int f) {
    func_020dd8b4(a, b, c, 0);
    func_020dd9b4((Struct_020dd7ac*)a, (unsigned int)d, (void*)e, (void*)f);
}
