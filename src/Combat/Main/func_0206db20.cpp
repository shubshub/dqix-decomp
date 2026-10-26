#include <globaldefs.h>

#include "Combat/NodeLookup.h"

// USA: func_0206db20
extern "C" ARM struct Struct_0206db20* func_0206db20(void* base, int key) {
    struct Struct_0206db20* node = *(struct Struct_0206db20**)base;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
