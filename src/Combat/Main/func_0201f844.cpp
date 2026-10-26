#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;

// USA: func_0201f844
extern "C" ARM int func_0201f844(Script::Parameter* arg) {
    const Script::Parameter* parameters = arg;
    int v = parameters[0].ToInt();
    *(int*)(data_020fdc4c.currentObject + 0x14) = v;
    return 1;
}
