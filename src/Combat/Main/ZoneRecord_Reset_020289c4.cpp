#include <globaldefs.h>
// jpn has no second allocator at +0x14, so everything after it is 4 bytes earlier
#if defined(jpn)
#define SUBOBJECT_OFFSET(x) ((x) - 4)
#else
#define SUBOBJECT_OFFSET(x) (x)
#endif

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

extern "C" ARM void NodeGraph_Reset(struct InitStruct* graph);
extern "C" ARM void func_0209bffc(void* obj);
extern "C" ARM void func_0209bc84(void* obj);
extern "C" ARM void func_0209af34(struct ResetObject0209af34Struct* obj);
extern "C" ARM void* func_0206efc4(void* obj);
extern "C" ARM void func_0206ee60(struct ZeroWordAndByte0206ee60Struct* s);
extern "C" ARM void func_020a8e88(void* p);

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct BigRecord020289c4 {
    unsigned short zoneId;
    unsigned short slotIndex : 2;
    unsigned short inUse : 1;
    unsigned short unknown3 : 1;
    unsigned short searchedLootables : 12;
    unsigned short openedDoors;
    unsigned short unknown6;
    unsigned int unknown8;
    unsigned char loaded;
    signed char unknownD;
};

enum { kGraphOffset = 0x18 };

// Main, originally InitializeSubObjectsAndFields020289c4 (USA 0x020289c4, EUR 0x020289d4, JPN 0x0202821c)
extern "C" ARM void ZoneRecord_Reset(struct BigRecord020289c4* record) {
    record->inUse = 0;
    record->unknown3 = 0;
    record->zoneId = 0;
    record->unknown8 = 0;
    record->unknown6 = 0;
    record->loaded = 0;
    record->searchedLootables = 0;
    record->openedDoors = 0;
    record->unknownD = -1;
    NodeGraph_Reset((struct InitStruct*)((char*)record + SUBOBJECT_OFFSET(kGraphOffset)));
    func_0209bffc((char*)record + SUBOBJECT_OFFSET(0x44));
    func_0209bc84((char*)record + SUBOBJECT_OFFSET(0x60));
    func_0209af34((struct ResetObject0209af34Struct*)((char*)record + SUBOBJECT_OFFSET(0x124)));
    func_0206efc4((char*)record + SUBOBJECT_OFFSET(0x2f8));
    func_0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)record + SUBOBJECT_OFFSET(0x304)));
    func_020a8e88((char*)record + SUBOBJECT_OFFSET(0x30c));
}
