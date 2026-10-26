#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"
#include "std_library_functions.h"

// USA: func_0206f170
extern "C" ARM int func_0206f170(Struct_0206ef48* table, Struct_0206efd8* source,
                                      unsigned char* arg2, Type_0206f110 relocate) {
    int var0;
    *arg2 = 0;
    if (source == NULL) return 0;

    memcpy(&table->table.header, &source->header, sizeof(Struct_0206f01c));
    table->table.arr = reinterpret_cast<MonsterDefinition*>(source + 1);
    var0 = func_0206f0f8(&table->table.header);
    table->strings = reinterpret_cast<char*>(source) + (var0 + sizeof(Struct_0206f01c));
    if (table->table.header.relocated) {
        *arg2 = 1;
        return 1;
    }
    func_0206f110(table, relocate);
    table->table.header.relocated = 1;
    source->header.relocated = 1;
    return 1;
}
