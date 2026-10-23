#include <globaldefs.h>

extern int data_0210782c[];

// Main, originally GetBoundedEntry020425b4 (USA 0x020425b4, EUR 0x020425c4; JPN not identified)
ARM void* Font_GetCharacter(int idx, int tableIdx) {
    char* t = (char*)data_0210782c[tableIdx];
    if (idx >= 0 && (unsigned int)idx < *(unsigned int*)(t + 0x4))
        return (void*)(*(int*)(t + 0x10) + (idx << 3));
    return NULL;
}
