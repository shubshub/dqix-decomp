#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

ARM void NodeGraph_Reset(struct InitStruct* graph);
ARM void ClearHalfword0x18_0209bffc(void* obj);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
void* Clear12Bytes0206efc4(void* obj);
ARM void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* s);
ARM void Clear12Bytes020a8e88(void* p);

struct ZoneRecordFlags {
    unsigned short slotIndex : 2;
    unsigned short inUse : 1;
    unsigned short unknown3 : 1;
    unsigned short searchedLootables : 12;
};

struct ZoneRecord {
    unsigned short zoneId;
    struct ZoneRecordFlags flags;
    unsigned short openedDoors;
    unsigned short unknown6;
    int unknown8;
    unsigned char loaded;
    signed char unknownD;
    unsigned short pad0e;
    int allocator;
#if !defined(jpn)
    int secondAllocator;
#endif
    unsigned char graph[0x2c];
    unsigned short unknown44;
    unsigned char pad46[0x1a];
    unsigned char unknown60[0xc0];
    unsigned char pad120[4];
    unsigned char unknown124[0x1d4];
    unsigned char unknown2f8[0xc];
    unsigned char unknown304[5];
    unsigned char pad309[3];
    unsigned char unknown30c[0xc];
};

enum { kZoneRecordCount = 4 };

// Main, originally func_020287b4 (USA 0x020287b4, EUR 0x020287c4, JPN 0x02028020)
extern "C" ARM void ZoneRecords_Reset(struct ZoneRecord* records) {
    int i;
    struct ZoneRecord* record;

    for (i = 0; i < kZoneRecordCount; i++) {
        record = &records[i];
        record->flags.inUse = 0;
        record->flags.unknown3 = 0;
        record->flags.slotIndex = 0;
        records[i].zoneId = 0;
        record->allocator = 0;
#if !defined(jpn)
        record->secondAllocator = 0;
#endif
        record->unknown8 = 0;
        record->unknown6 = 0;
        record->loaded = 0;
        record->flags.searchedLootables = 0;
        record->openedDoors = 0;
        record->unknownD = -1;
        NodeGraph_Reset((struct InitStruct*)record->graph);
        ClearHalfword0x18_0209bffc((void*)&record->unknown44);
        ClearBuffer0209bc84(record->unknown60);
        ResetObject0209af34((struct ResetObject0209af34Struct*)record->unknown124);
        Clear12Bytes0206efc4(record->unknown2f8);
        ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)record->unknown304);
        Clear12Bytes020a8e88(record->unknown30c);
        record->flags.slotIndex = i;
    }
}
