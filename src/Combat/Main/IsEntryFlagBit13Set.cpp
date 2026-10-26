#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
unsigned short WH_GetCurrentAid(void);

// USA: func_0202be70
ARM int IsEntryFlagBit13Set_0202be70(struct SearchStruct* obj, int value) {
    void* entry;
    if (!LinkSession_IsSlotMember(obj, value)) {
        return 0;
    }
    if (value == *(signed char*)((char*)obj + WH_GetCurrentAid() + 0x1000 + 0x38)) {
        entry = (char*)obj + 0x7c0;
    } else {
        entry = LinkSession_GetReceivedRecord(obj, value);
    }
    if (entry == NULL) {
        return 0;
    }
    return (((unsigned int)*(unsigned short*)((char*)entry + 0x2) << 0x12) >> 31) != 0;
}
