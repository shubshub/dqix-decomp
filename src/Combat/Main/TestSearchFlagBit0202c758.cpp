#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};

signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);

// USA: func_0202c758
ARM int TestSearchFlagBit0202c758(struct SearchStruct* obj, int value) {
    int bit = LinkSession_FindAidOfSlot(obj, value);
    return *((unsigned char*)obj + 0x1010) & (1 << bit);
}
