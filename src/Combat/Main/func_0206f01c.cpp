#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

// USA: func_0206f01c
extern "C" ARM void func_0206f01c(Struct_0206ef48* table, SafeAllocator* allocator,
                                 Struct_0206efd8* source, unsigned int sourceLength) {
    int var0;
    int var1;
    if (allocator == NULL || source == NULL) return;

    memcpy(&table->table.header, &source->header, sizeof(Struct_0206f01c));
    var0 = func_0206f0f8(&table->table.header);
    var1 = table->table.header.unknown_1_4_;
    if (var0) {
        table->table.arr = static_cast<MonsterDefinition*>(allocator->Allocate(var0));
    } else {
        table->table.arr = NULL;
    }
    table->strings = var1 ? static_cast<char*>(allocator->Allocate(var1)) : NULL;
    if (table->table.arr != NULL) {
        memcpy(table->table.arr, source + 1, var0);
    }
    if (table->strings != NULL) {
        memcpy(table->strings, reinterpret_cast<char*>(source) +
               (func_0206f0f8(&table->table.header) + sizeof(Struct_0206f01c)), var1);
    }

    if (reinterpret_cast<void*>(func_0206ef48) != NULL) {
        func_0206f110(table, func_0206ef48);
    }
    table->table.header.relocated = 1;
}
