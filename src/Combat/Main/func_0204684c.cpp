#include <globaldefs.h>
#include "Filesystem/Pac.h"
#include "std_library_functions.h"

extern "C" void* Pac_GetFile(struct PacRecord* rec, int index, void** out, int* out44);

// USA: FindMatchingRecords0204684c
extern "C" ARM int FindMatchingRecords0204684c(struct PacRecord* table, const char* name, void** outData, int maxCount, int* outField44, void** outRec) {
    int count = 0;
    int index;
    for (index = 0; ; index++) {
        int field44;
        void* recOut;
        void* data = Pac_GetFile(table, index, &recOut, &field44);
        if (data == 0) break;
        {
            char* p = (char*)recOut;
            char c;
            while ((c = *p) != 0) {
                if (c == '.') { p++; break; }
                p++;
            }
            if (strcmp(name, p) == 0) {
                outData[count] = data;
                if (outRec != 0) outRec[count] = recOut;
                if (outField44 != 0) outField44[count] = field44;
                count++;
                if (count >= maxCount) break;
            }
        }
    }
    return count;
}
