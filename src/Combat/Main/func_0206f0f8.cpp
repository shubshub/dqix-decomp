#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f0f8
extern "C" ARM int func_0206f0f8(Struct_0206f01c* header) {
    return header->count * sizeof(MonsterDefinition);
}
