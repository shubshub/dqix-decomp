#include <globaldefs.h>
#if defined(jpn)
enum { kEntryCount = 0x60, kEntrySize = 0x10 };
#else
enum { kEntryCount = 0x20, kEntrySize = 0x28 };
#endif
enum { kEntries = 4 };  // the entries follow the drawing buffer pointer

extern "C" void __cxa_vec_ctor(void* array, int count, int size, void* constructor, void* destructor);
extern "C" char* CachedTextEntry_Construct(char* entry);
extern "C" char* CachedTextEntry_Destroy(char* entry);
extern "C" void CachedTextTable_Clear(char* table);

// Main, originally InitBattleObject0203c2c0 (USA 0x0203c2c0, EUR 0x0203c2d0, JPN 0x0203c420)
extern "C" ARM char* CachedTextTable_Construct(char* table) {
    __cxa_vec_ctor(table + kEntries, kEntryCount, kEntrySize, (void*)CachedTextEntry_Construct, (void*)CachedTextEntry_Destroy);
    CachedTextTable_Clear(table);
    return table;
}
