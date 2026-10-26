#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};
struct ByteSearchStruct;

signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);
signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* obj, int value);

// USA: func_0202c600
ARM void ClearSearchFlagBit0202c600(struct SearchStruct* obj, int value) {
    int idx = LinkSession_FindAidOfSlot(obj, value);
    if (idx < 0) {
        idx = LinkSession_FindPreviousAidOfSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) &= ~(1 << idx);
}
