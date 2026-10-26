#include <globaldefs.h>

#include "Resource/MonsterDefinition.h"

// USA: func_0206ef94
extern "C" ARM char* func_0206ef94(Struct_0206ef48* table, char* arg1, char* arg2) {
    int var0 = 1;
    int offset = arg1 - (char*)0;
    if (offset != -1) {
        if (table->strings != 0) {
            var0 = 0;
        }
    }
    if (!var0) {
        return table->strings + offset;
    }
    return arg2;
}
