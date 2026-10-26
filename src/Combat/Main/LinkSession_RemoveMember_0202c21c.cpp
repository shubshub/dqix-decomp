#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};
struct ByteSearchStruct;

signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);
signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* obj, int value);
void ClearSearchFlagBit0202c69c(struct SearchStruct* obj, int value);
extern "C" void LinkSession_UpdateMemberCount(struct SearchStruct* obj);

// Main, originally RemoveSearchEntry0202c21c (USA 0x0202c21c, EUR 0x0202c22c, JPN 0x0202bdcc)
ARM void LinkSession_RemoveMember(struct SearchStruct* obj, int value) {
    int idx = LinkSession_FindAidOfSlot(obj, value);
    if (idx < 0) {
        idx = LinkSession_FindPreviousAidOfSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100c) &= ~(1 << idx);
    ClearSearchFlagBit0202c69c(obj, value);
    LinkSession_UpdateMemberCount(obj);
    obj->arr[idx] = 0;
}
