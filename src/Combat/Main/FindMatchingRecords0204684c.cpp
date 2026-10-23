#include <globaldefs.h>
#include "std_library_functions.h"

struct Rec020467f0 {
    char tag;
    char pad1[0x3f];
    int size40;
    int field44;
    int size48;
};

extern void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44);

// USA: func_0204684c
ARM int FindMatchingRecords0204684c(struct Rec020467f0* table, const char* name, void** outData, int maxCount, int* outField44, void** outRec) {
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
