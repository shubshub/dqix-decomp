#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int n);
#if !defined(jpn)
extern "C" void CachedTextTable_FindOrAddText(void* table, void* text, short* outIndex);
#endif
extern void* data_02105244;  // the CachedTextTable

extern "C" void CachedTextLabel_Release(char* label);

struct RefArray0xc6b8;
extern "C" void CachedTextTable_AddReference(struct RefArray0xc6b8* table, short index);

struct RefArray0xc6fc;
#if defined(jpn)
extern "C" void func_0203cbe4(struct RefArray0xc6fc* table, const short* indices);
#else
extern "C" void func_0203c6fc(struct RefArray0xc6fc* table, short index);
#endif

#if defined(jpn)
extern "C" void func_0203cb58(void*, void*);
extern "C" void func_0203bf00(void*, char*, void*, int);
extern "C" void CachedTextTable_FindOrAddText(void*, void*, void*, int);
enum {
    kTextSlotsSize = 0x14,          // the label's 10 cached entry indices
    kCharacterAdvanceOffset = 0x20, // the label's characterAdvance
    kFontPixelSize = 10             // the 10-pixel font CachedTextTable_FindOrAddText renders with
};
#endif
// A text label (Struct0203c1c8): its cached entry index
struct Obj0203c108 {
    char pad[0x14];
    short entryIndex;
};

// The previous text keeps a reference while the new one is looked up, so a label set to the text it already shows
// finds its own entry instead of rendering it again.
// Main, originally SwapGlobalEntry0203c108 (USA 0x0203c108, EUR 0x0203c118, JPN 0x0203bc54)
extern "C" ARM void CachedTextLabel_SetText(struct Obj0203c108* label, char* format) {
    if (data_02105244 != NULL && format != NULL && *format != 0) {
#if defined(jpn)
        char previousSlots[kTextSlotsSize];
        char text[0x80];
        memcpy(previousSlots, label, kTextSlotsSize);
        func_0203cb58(data_02105244, previousSlots);
        CachedTextLabel_Release((char*)label);
        __clear(text, 0x80);
        func_0203bf00(label, format, text, kFontPixelSize);
        *(int*)((char*)label + kCharacterAdvanceOffset) = kFontPixelSize;
        CachedTextTable_FindOrAddText(data_02105244, text, label, kFontPixelSize);
        func_0203cbe4(static_cast<RefArray0xc6fc*>(data_02105244),
                               reinterpret_cast<const short*>(previousSlots));
#else
        char text[0x100];
        __clear(text, 0x100);
        sprintf(text, format);
        short previousIndex = label->entryIndex;
        CachedTextTable_AddReference((struct RefArray0xc6b8*)data_02105244, previousIndex);
        CachedTextLabel_Release((char*)label);
        CachedTextTable_FindOrAddText(data_02105244, text, &label->entryIndex);
        func_0203c6fc((struct RefArray0xc6fc*)data_02105244, previousIndex);
#endif
    }
}
