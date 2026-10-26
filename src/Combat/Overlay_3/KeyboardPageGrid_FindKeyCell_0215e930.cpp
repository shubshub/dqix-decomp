#include <globaldefs.h>

struct LookupTable0215e930 {
    char pad0;
    signed char unknown_1_;
    char pad2;
    signed char count;
    short* entries;
};

// Overlay 3, originally func_ov003_0215e930 (USA/EUR 0x0215e930; JPN not identified)
extern "C" ARM int KeyboardPageGrid_FindKeyCell(struct LookupTable0215e930* obj, short target, unsigned char* outMod, unsigned char* outDiv) {
    signed char count = obj->count;
    short* p = obj->entries;
    short i;
    for (i = 0; i < count; i++, p++) {
        if (*p == target) {
            *outMod = i % obj->unknown_1_;
            *outDiv = i / obj->unknown_1_;
            return 0;
        }
    }
    return 1;
}
