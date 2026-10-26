#include <globaldefs.h>
#include "Resource/NameFilter.h"

// Overlay 9, originally func_ov009_0218a420 (USA/EUR 0x0218a420; JPN not identified)
extern "C" ARM int ForbiddenWordFile_RelocatePattern(ForbiddenWordFile* file, ForbiddenWordPattern* pattern)
{
    for (int i = 0; i < pattern->count_; i++)
    {
        bool none = true;
        int offset = pattern->words_[i] - (const char*)0;
        if (offset != -1 && file->texts_ != 0)
            none = false;
        pattern->words_[i] = none ? 0 : file->texts_ + offset;
    }
    return 1;
}
