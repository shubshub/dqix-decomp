#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f110
extern "C" ARM int func_0206f110(Struct_0206ef48* table, Type_0206f110 arg1) {
    int count;
    MonsterDefinition* definition = table->table.arr;
    int index;
    if (definition == NULL || (count = table->table.header.count) == 0 || arg1 == NULL) {
        return 0;
    }
    for (index = 0; index < count; index++, definition++) {
        arg1(table, definition);
    }
    return 1;
}
