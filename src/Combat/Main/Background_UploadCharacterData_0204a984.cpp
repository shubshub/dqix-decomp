#include <globaldefs.h>
#include "std_library_functions.h"

typedef void (*Fn0204a984)(void*, int, int);

// Main, originally InvokeWithCopiedArg0204a984 (USA 0x0204a984, EUR 0x0204a994, JPN 0x0204b7a4)
ARM void Background_UploadCharacterData(int* a0, Fn0204a984 fn, char* ctx) {
    int tmp;
    if (ctx == NULL) return;
    memcpy(&tmp, ctx + 0xc, 4);
    fn((void*)(ctx + 0x10), *a0, tmp);
}
