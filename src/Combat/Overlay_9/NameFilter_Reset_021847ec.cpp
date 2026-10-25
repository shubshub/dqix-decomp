#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#include "std_library_functions.h"
#include "Resource/NameFilter.h"

struct SyntaxCharacter { char text[5]; };
#if !defined(jpn)
extern struct SyntaxCharacter NameFilter_syntaxCharacters[];
#endif
int Font_FindCharacterIndex(int key, int tableIdx);

#if defined(jpn)
extern "C" int func_ov009_02185888(NameFilter*);
#endif

// Overlay 9, originally func_ov009_021847ec (USA/EUR 0x021847ec, JPN 0x02185850)
extern "C" ARM void NameFilter_Reset(struct NameFilter* self) {
    memset(&self->patterns, 0, 0xc);
    self->reservedNamesData = 0;
    self->reservedNamesSize = 0;
#if defined(jpn)
    self->tasks[0] = -1;
    self->tasks[1] = -1;
    func_ov009_02185888(self);
#else
    unsigned char* out = &self->letterClassId;
    int i;
    for (i = 0; i < 15; i++) { // one per syntax character
        *out++ = (unsigned char)Font_FindCharacterIndex((int)&NameFilter_syntaxCharacters[i], 1);
    }
#endif
}
