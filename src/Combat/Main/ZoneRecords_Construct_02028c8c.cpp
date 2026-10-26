#include <globaldefs.h>

#if defined(jpn)
enum { kZoneRecordSize = 0x314 };
#else
enum { kZoneRecordSize = 0x318 };
#endif
enum { kZoneRecordCount = 4 };

extern "C" void ZoneRecord_Destroy(void* record);
extern "C" void ZoneRecord_Construct(void* record);

extern "C" void __cxa_vec_ctor(void* array, int count, int size, void* constructor, void* destructor);
extern "C" void ZoneRecords_Reset(void* records);

// Main, originally InitObjectWithCallbacks02028c8c (USA 0x02028c8c, EUR 0x02028c9c, JPN 0x020284dc)
extern "C" ARM void* ZoneRecords_Construct(void* records) {
    __cxa_vec_ctor(records, kZoneRecordCount, kZoneRecordSize, (void*)ZoneRecord_Construct, (void*)ZoneRecord_Destroy);
    ZoneRecords_Reset(records);
    return records;
}
