#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void* obj);
extern "C" int LinkSession_IsActive(int* obj);
struct SearchStruct;

// USA: func_02034340
extern "C" ARM int func_02034340(void* obj) {
    void* thing = LinkSession_GetInstance(obj);
    GetGameResources();
    int result = 0;
    if (LinkSession_IsActive((int*)thing)) {
        short field4 = *(short*)((char*)obj + 4);
        if (LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4)) {
            field4 = *(short*)((char*)obj + 4);
            void* p = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
            unsigned int v = *(unsigned short*)((char*)p + 2);
            if ((v << 17) >> 31) result = 1;
        }
    }
    return result;
}
