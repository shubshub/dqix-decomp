#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

// A Script::Parameter (Resource/Script.h)
struct Variant02030b0c {
    int type;
    union { int i; float f; } value;
};
void MapDisplay_SetMapKey(char* a, char* b);
extern "C" void MapDisplay_AddImage(void* obj, int a, void* b, void* allocator);

// Main, originally SetDecodedStringEntry0201f528 (USA 0x0201f528, EUR 0x0201f538, JPN 0x0201f2b4)
ARM int BmmpScript_AddImage(struct Variant02030b0c* params) {
    int id = ((Script::Parameter*)params)->ToInt();
    void* name = (void*)((Script::Parameter*)(params + 1))->ToString();
    if (name == 0) return 0;
    MapDisplay_SetMapKey(data_020fdc4c.currentObject, (char*)name);
    MapDisplay_AddImage(data_020fdc4c.currentObject, id, name, data_020fdc4c.allocator);
    return 1;
}
