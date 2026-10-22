#include <globaldefs.h>

struct Entry0204254c;
Entry0204254c* Font_FindCharacter(int key, int tableIdx);

// USA: func_02067f9c  (semantic: CheckFlagOrEntryBit02067f9c)
extern "C" ARM int func_02067f9c(int* a, int b, int c) {
    if (a != 0) {
        int v = *(int*)((char*)a + 8);
        unsigned int bit = ((unsigned int)v << 3) >> 31;
        if (bit != 0) {
            return 1;
        }
    }
    if (b == 0) {
        return 0;
    }
    Entry0204254c* e = Font_FindCharacter(b, c);
    if (e != 0) {
        signed char byte5 = *((signed char*)e + 5);
        return (byte5 << 25) >> 31;
    }
    return 0;
}
