#include <globaldefs.h>
#include "std_library_functions.h"

extern char* data_02105244;  // the CachedTextTable
extern "C" void CachedTextTable_ReleaseText(char* table, short* indexPtr);

// Offsets in a text label (Struct0203c1c8)
#if defined(jpn)
enum {
    kTextSlotsSize = 0x14,   // textSlots[10] at +0
    kAffineWord = 0x30,      // affineIndex : 16, unknown32 : 8, unknown33 : 8
    kUnknown32Bits = 0xff0000
};
#else
enum { kEntryIndex = 0x14 };
#endif

// Main, originally ReleaseGlobalEntry0203c198 (USA 0x0203c198, EUR 0x0203c1a8, JPN 0x0203bd00)
extern "C" ARM void CachedTextLabel_Release(char* label) {
    if (data_02105244 == NULL) return;
#if defined(jpn)
    CachedTextTable_ReleaseText(data_02105244, reinterpret_cast<short*>(label));
    memset(label, -1, kTextSlotsSize);
    *(unsigned int*)(label + kAffineWord) &= ~kUnknown32Bits;
#else
    CachedTextTable_ReleaseText(data_02105244, (short*)(label + kEntryIndex));
    *(short*)(label + kEntryIndex) = -1;
#endif
}
