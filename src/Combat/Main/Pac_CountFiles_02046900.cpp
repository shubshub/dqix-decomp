#include <globaldefs.h>
#include "Filesystem/Pac.h"

// Main, originally CountActiveEntries (USA 0x02046900, EUR 0x02046910, JPN 0x02047720)
ARM int Pac_CountFiles(struct PacRecord* record) {
    int count = 0;
    while (record->name[0] ? 1 : 0) {
        count++;
        record = (struct PacRecord*)((char*)record + record->stride);
    }
    return count;
}
