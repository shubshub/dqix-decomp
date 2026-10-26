#include <globaldefs.h>
#include "Combat/SearchEntry.h"

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    char padding0[0x7c0];
    SearchEntry0202c178 ownRecord;  // this console's record (LinkSession_GetOwnRecord)
    char padding7d0[0x868];
    signed char slotOfAid[16];      // +0x1038
};

int LinkSession_IsSlotMember(struct SearchStruct* session, int slot);
unsigned short WH_GetCurrentAid(void);

// USA: func_0202be08
ARM int IsEntryFlagBit11Set_0202be08(struct SearchStruct* session, int slot) {
    SearchEntry0202c178* record;
    if (!LinkSession_IsSlotMember(session, slot)) {
        return 0;
    }
    if (slot == session->slotOfAid[WH_GetCurrentAid()]) {
        record = &session->ownRecord;
    } else {
        record = LinkSession_GetReceivedRecord(session, slot);
    }
    if (record == NULL) {
        return 0;
    }
    return record->bit11 != 0;
}
