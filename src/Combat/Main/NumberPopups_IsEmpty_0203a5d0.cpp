#include <globaldefs.h>

// data_02104b6c, the battle's number popups: head (+0x6d0) and tail (+0x6d4) of the ring.
struct NumberPopupRing {
    char sprites[0x550];
    char popups[16][0x18];
    int head;
    int tail;
};

// Main, originally CheckFields6d0And6d4Equal_0203a5d0 (USA 0x0203a5d0, EUR 0x0203a5e0, JPN 0x0203a028)
extern "C" ARM int NumberPopups_IsEmpty(unsigned char* numberPopups) {
    return ((NumberPopupRing*)numberPopups)->head == ((NumberPopupRing*)numberPopups)->tail;
}
