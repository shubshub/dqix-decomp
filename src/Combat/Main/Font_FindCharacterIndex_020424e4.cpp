#include <globaldefs.h>

extern int data_0210782c[];
extern "C" int func_02001aec(int val, int key, int field5);

struct Entry020424e4 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

// Main, originally FindEntryIndexByKey020424e4 (USA 0x020424e4, EUR 0x020424f4; JPN not identified)
ARM int Font_FindCharacterIndex(int key, int tableIdx) {
    char* header;
    unsigned int i;
    if (key == 0) {
        return -1;
    }
    header = (char*)data_0210782c[tableIdx];
    for (i = 0; i < *(unsigned int*)(header + 4); i++) {
        struct Entry020424e4* e = *(struct Entry020424e4**)(header + 0x10) + i;
        if (func_02001aec(e->val, key, e->field5) == 0) {
            return i;
        }
    }
    return -1;
}
