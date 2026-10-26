#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206ef40
extern "C" ARM int func_0206ef40(void* entry) {
    return static_cast<MonsterDefinition*>(entry)->monsterId;
}
