#include <globaldefs.h>
#include "Filesystem/Pac.h"
#include "Filesystem/FileIO.h"

extern "C" int FindMatchingRecords0204684c(struct PacRecord* table, const char* name, void** outData, int maxCount, int* outField44, void** outRec);

// USA: func_ov023_021fad20
extern "C" ARM int func_ov023_021fad20(const void* narcBuffer, const char* name, const void** outData, unsigned int* outSize) {
    if (FindFilesInNarcBySubstring(narcBuffer, name, outData, outSize, 1) != 0) {
        return 1;
    }
    return FindMatchingRecords0204684c((struct PacRecord*)narcBuffer, name, (void**)outData, 1, (int*)outSize, NULL) != 0;
}
