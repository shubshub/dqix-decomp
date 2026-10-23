#include <globaldefs.h>

int CheckField0NonZero020a10a8(int*);

// Main, originally AnySubObjectField0NonZero_0202eeb4 (USA 0x0202eeb4, EUR 0x0202eec4, JPN 0x0202ea24)
ARM int Camera_IsEasing(char* obj) {
    int result = 1;
    int inner = 1;
    if (CheckField0NonZero020a10a8((int*)(obj + 0x16c)) == 0) {
        if (CheckField0NonZero020a10a8((int*)(obj + 0x194)) == 0) inner = 0;
    }
    if (inner == 0) {
        if (CheckField0NonZero020a10a8((int*)(obj + 0x1bc)) == 0) result = 0;
    }
    return result;
}
