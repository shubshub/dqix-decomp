#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;
extern "C" void func_02027b10(void* obj, int value);

// USA: func_0201f390
extern "C" ARM int func_0201f390(Script::Parameter* arg) {
    const Script::Parameter* parameters = arg;
    int value = parameters[0].ToInt();
    func_02027b10(data_020fdc4c.currentObject, value);
    return 1;
}
