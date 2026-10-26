#include <globaldefs.h>
#include "std_library_functions.h"

struct Header020dffb8;
extern "C" int KeyTable_GetEntriesSize(Header020dffb8* obj);

struct Container020dffc8;
struct Element020dffc8;
typedef int (*ElementCallback020dffc8)(Container020dffc8*, Element020dffc8*);
extern "C" int KeyTable_ForEachEntry(Container020dffc8* self, ElementCallback020dffc8 cb);

struct List020e0280 {
    unsigned int field0;
    void* field4;
    void* field8;
};

// Main, originally func_020e0280 (USA 0x020e0280, EUR 0x020e0290, JPN 0x020e1e54)
extern "C" ARM int KeyTable_LoadInPlaceWithCallback(struct List020e0280* self, struct List020e0280* src, unsigned char* outFlag, ElementCallback020dffc8 callback) {
    *outFlag = 0;
    if (src == 0) return 0;
    memcpy(self, src, 4);
    self->field4 = (char*)src + 4;
    self->field8 = (char*)src + (KeyTable_GetEntriesSize((Header020dffb8*)self) + 4);
    if ((unsigned int)self->field0 >> 31) {
        *outFlag = 1;
        return 1;
    }
    KeyTable_ForEachEntry((Container020dffc8*)self, callback);
    self->field0 = (self->field0 & ~0x80000000) | 0x80000000;
    src->field0 = (src->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
