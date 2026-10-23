#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#include "std_library_functions.h"

struct SyntaxCharacter { char text[5]; };
#if !defined(jpn)
extern struct SyntaxCharacter NameFilter_syntaxCharacters[];
#endif
int Font_FindCharacterIndex(int key, int tableIdx);

struct NameFilter {
#if !defined(jpn)
    char reservedNames[0x18];   // text table of res.nat
#endif
    char patterns[0xc];         // ForbiddenWordFile of tv.nat (jpn: a different checker)
    int reservedNamesData;
    short reservedNamesSize;
#if defined(jpn)
    unsigned short field12;
    int tasks[2];
    int field1c;
#else
    unsigned char syntaxIds[15]; // font-1 indexes of NameFilter_syntaxCharacters
#endif
};

#if defined(jpn)
extern "C" int func_ov009_02185888(NameFilter*);
#endif

// Overlay 9, originally func_ov009_021847ec (USA/EUR 0x021847ec, JPN 0x02185850)
extern "C" ARM void NameFilter_Reset(struct NameFilter* self) {
    memset(self->patterns, 0, 0xc);
    self->reservedNamesData = 0;
    self->reservedNamesSize = 0;
#if defined(jpn)
    self->tasks[0] = -1;
    self->tasks[1] = -1;
    func_ov009_02185888(self);
#else
    unsigned char* out = self->syntaxIds;
    int i;
    for (i = 0; i < 15; i++) { // one per syntax character
        *out++ = (unsigned char)Font_FindCharacterIndex((int)&NameFilter_syntaxCharacters[i], 1);
    }
#endif
}
