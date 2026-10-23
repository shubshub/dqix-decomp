#include <globaldefs.h>
#include "NitroSDK/Cache.h"

struct Obj021e7b34 {
    char pad[0x5dc];
    int field5dc;
};

struct EntryList0204af14;
void* Background_GetScreen(EntryList0204af14*, unsigned int);

struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(Tilemap0204ae44*, int);

extern "C" int LoadToSubBG1ScreenData(int, int, unsigned int);

struct Entry021e7b34 {
    char pad0[8];
    int size;
    void* buffer;
};

// USA: func_ov023_021e7b34  (semantic: RefreshTilemapPalette_021e7b34)
extern "C" ARM int func_ov023_021e7b34(Obj021e7b34* obj, int idx) {
    if (obj->field5dc == 0) return 1;
    int valid = (idx >= 0 && idx <= 3) ? 1 : 0;
    if (!valid) return 1;
    EntryList0204af14* list = (EntryList0204af14*)((char*)obj + 0x154);
    void* entryPtr = Background_GetScreen(list, 0);
    if (entryPtr == NULL) return 1;
    FillTilemapPalette0204ae44((Tilemap0204ae44*)entryPtr, (unsigned short)(idx + 0xc));
    Entry021e7b34* entry = (Entry021e7b34*)entryPtr;
    void* buffer = entry->buffer;
    int size = entry->size;
    CleanInvalidateCacheRange(buffer, size);
    LoadToSubBG1ScreenData((int)buffer, 0, size);
    return 0;
}
