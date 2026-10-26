#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int LinkSession_IsGuest(struct SearchStruct* obj, int value);
signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);

// USA: func_0202c718
ARM void ClearSearchFlagBit0202c718(struct SearchStruct* obj, int value) {
    if (LinkSession_IsGuest(obj, value)) return;
    {
        int idx = LinkSession_FindAidOfSlot(obj, value);
        *((unsigned char*)obj + 0x1010) &= ~(1 << idx);
    }
}
