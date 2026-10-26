#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206ef48
extern "C" ARM int func_0206ef48(Struct_0206ef48* table, MonsterDefinition* definition) {
    definition->name = func_0206ef94(table, definition->name, 0);
#if !defined(jpn)
    definition->unknown_14_ = func_0206ef94(table, definition->unknown_14_, 0);
#endif
    definition->unknown_4_ = func_0206ef94(table, definition->unknown_4_, 0);
    return 1;
}
