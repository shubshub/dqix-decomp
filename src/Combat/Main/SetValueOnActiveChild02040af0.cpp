#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

struct NpcWalker;
void NpcWalker_SetFacing(NpcWalker*, int);

// USA: func_02040af0
ARM void SetValueOnActiveChild02040af0(Entry_203dce4* entry, int value) {
    if (entry->child14) {
        NpcWalker_SetFacing((NpcWalker*)entry->child14, value);
        return;
    }
    if (entry->child18) {
        *(int*)((char*)entry->child18 + 0xb0) = value;
        return;
    }
    if (entry->child1c) {
#if defined(jpn)
        *(int*)((char*)entry->child1c + 0x2c8) = value;
#else
        *(int*)((char*)entry->child1c + 0x2d4) = value;
#endif
    }
}
