#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"
#include "Combat/MapDisplay.h"


// Main, originally SetScaledFieldFromTaggedValue0201f600 (USA 0x0201f600, EUR 0x0201f610, JPN 0x0201f38c)
ARM int BmmpScript_SetScale(Script::Parameter* paramsIn) {
    const Script::Parameter* params = paramsIn;
    float scale = 4096.0f * params[0].ToFloat();
    ((MapDisplay*)data_020fdc4c.currentObject)->scale = (int)scale;
    return 1;
}
