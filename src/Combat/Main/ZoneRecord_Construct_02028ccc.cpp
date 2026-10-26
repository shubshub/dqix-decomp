#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

ARM void NodeGraph_Reset(struct InitStruct* graph);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* s);

// ZoneRecord sub-objects; jpn has no second allocator at +0x14, so they start 4 bytes earlier
#if defined(jpn)
enum { kGraphOffset = 0x14, kUnknown60Offset = 0x5c, kUnknown124Offset = 0x120, kUnknown304Offset = 0x300 };
#else
enum { kGraphOffset = 0x18, kUnknown60Offset = 0x60, kUnknown124Offset = 0x124, kUnknown304Offset = 0x304 };
#endif

// Main, originally InitializeSubObjects02028ccc (USA 0x02028ccc, EUR 0x02028cdc, JPN 0x0202851c)
ARM void* ZoneRecord_Construct(void* record) {
    NodeGraph_Reset((struct InitStruct*)((char*)record + kGraphOffset));
    ClearBuffer0209bc84((char*)record + kUnknown60Offset);
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)record + kUnknown124Offset));
    ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)record + kUnknown304Offset));
    return record;
}
