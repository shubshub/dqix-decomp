#include <globaldefs.h>

#include "std_library_functions.h"
#include "Resource/Font.h"

extern "C" FontCharacter *Font_FindCharacter(int key, int tableIdx);
extern "C" void func_02067f5c(signed char *text, int count);

// USA: func_0206819c
extern "C" ARM void func_0206819c(const char *source, char *destination, int tableIndex) {
    if (source == NULL) return;
    sprintf(destination, source);
    if (*source == 0) return;
    FontCharacter *entry = Font_FindCharacter(reinterpret_cast<int>(source), tableIndex);
    if (entry == NULL || !entry->lowercase_) return;
    func_02067f5c(reinterpret_cast<signed char *>(destination), entry->byteLength_);
}
