#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};
struct ByteSearchStruct;

extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);
extern "C" signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* obj, int value);

// USA: func_0202c600
extern "C" ARM void func_0202c600(struct SearchStruct* obj, int value) {
    int idx = LinkSession_FindAidOfSlot(obj, value);
    if (idx < 0) {
        idx = LinkSession_FindPreviousAidOfSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) &= ~(1 << idx);
}
