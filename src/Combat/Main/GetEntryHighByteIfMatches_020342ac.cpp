#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "Resource/GameResources.h"

extern "C" void* LinkSession_GetInstance(void* obj);
int LinkSession_IsActive(int* obj);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
struct SearchStruct;
struct SearchStruct0202c1a4;
signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* obj);

struct FlagsByte0xc1_020342ac {
    unsigned char lowBits2 : 2;
};

// USA: func_020342ac  (semantic: GetEntryHighByteIfMatches_020342ac)
extern "C" ARM int func_020342ac(void* obj) {
    void* thing = LinkSession_GetInstance(obj);
    GetGameResources();
    if (!LinkSession_IsActive((int*)thing)) {
        goto fallback;
    }
    if (!LinkSession_IsHostOrSolo(thing)) {
        goto fallback;
    }
    short field4 = *(short*)((char*)obj + 4);
    if (!LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4)) {
        goto fallback;
    }
    field4 = *(short*)((char*)obj + 4);
    signed char cur = LinkSession_GetOwnSlot((struct SearchStruct0202c1a4*)thing);
    if (cur == field4) {
        goto fallback;
    }
    FlagsByte0xc1_020342ac* flags = (FlagsByte0xc1_020342ac*)((char*)obj + 0xc1);
    if (!(flags->lowBits2 & 2)) {
        goto fallback;
    }
    field4 = *(short*)((char*)obj + 4);
    SearchEntry0202c178* entry = LinkSession_GetReceivedRecord((struct SearchStruct*)thing, field4);
    return entry->flags.kind;
fallback:
    return *(unsigned char*)((char*)obj + 0xbe);
}
