#include <globaldefs.h>

struct SearchStruct {
    char pad[0x1038];
    signed char arr[16];
};

extern "C" int LinkSession_IsGuest(struct SearchStruct* obj, int value);
extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);

// USA: func_0202c69c
extern "C" ARM void func_0202c69c(struct SearchStruct* obj, int value) {
    if (LinkSession_IsGuest(obj, value)) return;
    {
        int idx = LinkSession_FindAidOfSlot(obj, value);
        *((unsigned char*)obj + 0x100f) &= ~(1 << idx);
    }
}
