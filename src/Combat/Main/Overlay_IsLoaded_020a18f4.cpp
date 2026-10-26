#include <globaldefs.h>

extern int data_01ffd348;
extern signed char data_01ffd364;

struct Entry020e8f20 {
    int col;
    int pad;
};
extern struct Entry020e8f20 data_020e8f20[];

// Main, originally IsIndexMappedToSelf020a18f4 (USA 0x020a18f4, EUR 0x020a1904, JPN 0x020a366c)
ARM int Overlay_IsLoaded(unsigned int idx) {
    int result = 0;
    if (idx < 0x23) {
        signed char* row = &data_01ffd364 + data_01ffd348 * 6;
        result = ((int)idx == row[data_020e8f20[idx].col]);
    }
    return result;
}
