#include <globaldefs.h>
#include "std_library_functions.h"

// One CachedTextTable entry
#if defined(jpn)
struct CachedTextEntry {
    short advanceX;
    short tileIndex;
    char text[10];
    unsigned char references;
    unsigned char unknownf;
};
#else
struct CachedTextEntry {
    unsigned char glyphIndices[0x20];  // the text as font character indices (Font_EncodeText)
    unsigned char length;              // characters in glyphIndices
    unsigned char width;               // in pixels, set by CachedTextEntry_Render
    short tileIndex;                   // first OBJ tile of the rendered text
    unsigned char references;
};
#endif

// Main, originally InitStruct0203be8c (USA 0x0203be8c, EUR 0x0203be9c, JPN 0x0203b8e4)
extern "C" ARM void CachedTextEntry_Clear(char* rawEntry) {
    CachedTextEntry* entry = (CachedTextEntry*)rawEntry;
#if defined(jpn)
    entry->advanceX = -1;
    entry->tileIndex = -1;
    memset(entry->text, 0, 10);
    entry->references = 0;
#else
    memset(entry->glyphIndices, 0, 0x20);
    entry->length = 0;
    entry->width = 0;
    entry->tileIndex = -1;
    entry->references = 0;
#endif
}
