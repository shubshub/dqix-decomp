#include <globaldefs.h>

struct ActiveEntry02046900 {
    signed char active;
    char pad[0x47];
    int stride;
};

// Main, originally CountActiveEntries (USA 0x02046900, EUR 0x02046910, JPN 0x02047720)
ARM int Pac_CountFiles(struct ActiveEntry02046900* entry) {
    int count = 0;
    while (entry->active ? 1 : 0) {
        count++;
        entry = (struct ActiveEntry02046900*)((char*)entry + entry->stride);
    }
    return count;
}
