#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct Struct_02046574 { char c[0x40]; };

struct Obj02046574 {
    char pad[IS_JPN ? 0x37c : 0x4ac];
    struct Struct_02046574 names[16];
};

// Main, originally SetIndexedName02046574 (USA 0x02046574, EUR 0x02046584, JPN 0x02047418)
extern "C" ARM void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str) {
    if (str == NULL) return;
    if (index < 0) return;
    if (index >= 0x10) return;
    strncpy(obj->names[index].c, str, 0x3f);
    obj->names[index].c[0x3f] = 0;
}
