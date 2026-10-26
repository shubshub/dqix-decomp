#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee70Struct;

ARM void NodeGraph_Reset(struct InitStruct* s);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void ZeroWordAndByte0206ee70(struct ZeroWordAndByte0206ee70Struct* s);

// Main, originally FinalizeSubObjects02028cfc (USA 0x02028cfc, EUR 0x02028d0c, JPN 0x0202854c)
ARM void* ZoneRecord_Destroy(void* obj) {
#if defined(jpn)
    ZeroWordAndByte0206ee70((struct ZeroWordAndByte0206ee70Struct*)((char*)obj + 0x300));
#else
    ZeroWordAndByte0206ee70((struct ZeroWordAndByte0206ee70Struct*)((char*)obj + 0x304));
#endif
#if defined(jpn)
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x120));
#else
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x124));
#endif
#if defined(jpn)
    ClearBuffer0209bc84((char*)obj + 0x5c);
#else
    ClearBuffer0209bc84((char*)obj + 0x60);
#endif
#if defined(jpn)
    NodeGraph_Reset((struct InitStruct*)((char*)obj + 0x14));
#else
    NodeGraph_Reset((struct InitStruct*)((char*)obj + 0x18));
#endif
    return obj;
}
