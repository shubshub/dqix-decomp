#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov023_021fddb8 { int key; int index; };
extern struct Struct_ov023_021fddb8 data_ov023_021fddb8[];
extern int data_ov023_021ffa4c[];
extern "C" void func_ov017_021d4cc0(void* obj, void* a, int b);

// USA: func_ov023_021eb000
extern "C" ARM void func_ov023_021eb000(void* obj) {
    memset(data_ov023_021ffa4c, 0, 0x4b0);
    struct Struct_ov023_021fddb8* e;
    for (e = data_ov023_021fddb8; e != 0; e++) {
        if (e->key == 0) break;
        if (e->index >= 0 && e->index < 0x12c) {
            if (data_ov023_021ffa4c[e->index] != 0) {
                for (;;) {}
            }
            data_ov023_021ffa4c[e->index] = e->key;
        }
    }
    func_ov017_021d4cc0(obj, data_ov023_021ffa4c, 0x12c);
}
