#include <globaldefs.h>

struct Rec020467f0 {
    char tag;
    char pad1[0x3f];
    int size40;
    int field44;
    int size48;
};

// Main, originally FindRecordByIndex (USA 0x020467f0, EUR 0x02046800, JPN 0x02047610)
ARM void* Pac_GetFile(struct Rec020467f0* rec, int index, void** out, int* out44) {
    int i;
    if (rec == NULL) return NULL;
    i = 0;
    while (rec->tag != 0) {
        if (index == i) {
            int size = rec->size40;
            if (out44 != NULL) *out44 = rec->field44;
            *out = rec;
            return (char*)rec + size;
        }
        rec = (struct Rec020467f0*)((char*)rec + rec->size48);
        i++;
    }
    return NULL;
}
