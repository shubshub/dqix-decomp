#include <globaldefs.h>

struct InitStruct;
struct ResetObject0209af34Struct;
struct Struct_02028cfc;

extern "C" ARM void NodeGraph_Reset(struct InitStruct* s);
extern "C" ARM void func_0209bc84(void* obj);
extern "C" ARM void func_0209af34(struct ResetObject0209af34Struct* obj);
extern "C" ARM void func_0206ee70(struct Struct_02028cfc* s);

// Main, originally FinalizeSubObjects02028cfc (USA 0x02028cfc, EUR 0x02028d0c, JPN 0x0202854c)
extern "C" ARM void* ZoneRecord_Destroy(void* obj) {
#if defined(jpn)
    func_0206ee70((struct Struct_02028cfc*)((char*)obj + 0x300));
#else
    func_0206ee70((struct Struct_02028cfc*)((char*)obj + 0x304));
#endif
#if defined(jpn)
    func_0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x120));
#else
    func_0209af34((struct ResetObject0209af34Struct*)((char*)obj + 0x124));
#endif
#if defined(jpn)
    func_0209bc84((char*)obj + 0x5c);
#else
    func_0209bc84((char*)obj + 0x60);
#endif
#if defined(jpn)
    NodeGraph_Reset((struct InitStruct*)((char*)obj + 0x14));
#else
    NodeGraph_Reset((struct InitStruct*)((char*)obj + 0x18));
#endif
    return obj;
}
