#include <globaldefs.h>

#include "std_library_functions.h"
#include "Resource/Font.h"

FontCharacter *Font_FindCharacter(int key, int tableIdx);
void ToUpperBounded_02067f5c(signed char *text, int count);

// USA: func_0206819c
ARM void CopyTextAndUppercaseIfFlagged0206819c(const char *source, char *destination, int tableIndex) {
    if (source == NULL) return;
    sprintf(destination, source);
    if (*source == 0) return;
    FontCharacter *entry = Font_FindCharacter(reinterpret_cast<int>(source), tableIndex);
    if (entry == NULL || !entry->lowercase_) return;
    ToUpperBounded_02067f5c(reinterpret_cast<signed char *>(destination), entry->byteLength_);
}
