#include <globaldefs.h>

extern "C" void ZoneRecords_Reset(void* records);

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct Big02028894 {
    char pad[0x10];
    void* allocator;
#if !defined(jpn)
    void* secondAllocator;
#endif
    char pad2[0x318 - 0x18];
};

enum { kZoneRecordCount = 4, kSafeAllocatorSize = 0x14 };

// Main, originally InitEntries02028894 (USA 0x02028894, EUR 0x020288a4, JPN 0x020280fc)
ARM void ZoneRecords_Init(struct Big02028894* records, char* allocators, char* secondAllocators) {
    int i;
    ZoneRecords_Reset(records);
    for (i = 0; i < kZoneRecordCount; i++) {
        records[i].allocator = allocators + i * kSafeAllocatorSize;
#if !defined(jpn)
        records[i].secondAllocator = secondAllocators + i * kSafeAllocatorSize;
#endif
    }
}
