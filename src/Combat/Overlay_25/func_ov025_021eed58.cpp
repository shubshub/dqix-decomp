#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov025_021eed58 { char pad[0x18]; struct Struct_ov025_021eed58* next; };

// USA: func_ov025_021eed58
extern "C" ARM void func_ov025_021eed58(char* obj) {
    memset(obj, 0, 0xe0);
    *(int*)(obj + 0xe0) = 0;
    *(int*)(obj + 0xe4) = 0;
    for (int i = 0; i < 7; i++) {
        struct Struct_ov025_021eed58* e = (struct Struct_ov025_021eed58*)(obj + i * 0x1c);
        struct Struct_ov025_021eed58* n = (struct Struct_ov025_021eed58*)(obj + (i + 1) * 0x1c);
        e->next = n;
    }
    *(void**)(obj + 0xe4) = obj;
    *(int*)(obj + 0xdc) = 0;
}
