#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "Combat/MapDisplay.h"

#include "std_library_functions.h"


// Main, originally CopyStringToBuffer0201f634 (USA 0x0201f634, EUR 0x0201f644, JPN 0x0201f3c0)
extern "C" ARM int BmmpScript_SetBackgroundPattern(const Script::Parameter* paramsIn) {
    const Script::Parameter* params = paramsIn;
    strcpy(((MapDisplay*)data_020fdc4c.currentObject)->name, params[0].ToString());
    return 1;
}
