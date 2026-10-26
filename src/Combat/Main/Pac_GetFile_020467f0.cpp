#include <globaldefs.h>
#include "Filesystem/Pac.h"

// Main, originally FindRecordByIndex (USA 0x020467f0, EUR 0x02046800, JPN 0x02047610)
extern "C" ARM void* Pac_GetFile(struct PacRecord* record, int index, void** outRecord, int* outSize) {
    int i;
    if (record == NULL) return NULL;
    i = 0;
    while (record->name[0] != 0) {
        if (index == i) {
            int headerSize = record->headerSize;
            if (outSize != NULL) *outSize = record->dataSize;
            *outRecord = record;
            return (char*)record + headerSize;
        }
        record = (struct PacRecord*)((char*)record + record->stride);
        i++;
    }
    return NULL;
}
