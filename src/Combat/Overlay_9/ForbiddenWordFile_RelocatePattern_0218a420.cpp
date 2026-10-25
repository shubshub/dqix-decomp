#include <globaldefs.h>
#include "Resource/NameFilter.h"

// Overlay 9, originally func_ov009_0218a420 (USA/EUR 0x0218a420; JPN not identified)
extern "C" ARM int ForbiddenWordFile_RelocatePattern(ForbiddenWordFile* file, ForbiddenWordPattern* pattern)
{
    for (int var0 = 0; var0 < arg1->unknown_1e_; var0++)
    {
        bool var1 = true;
        int var2 = arg1->unknown_0_[var0] - (const char*)0;
        if (var2 != -1 && arg0->unknown_8_ != 0)
            var1 = false;
        arg1->unknown_0_[var0] = var1 ? 0 : arg0->unknown_8_ + var2;
    }
    return 1;
}
