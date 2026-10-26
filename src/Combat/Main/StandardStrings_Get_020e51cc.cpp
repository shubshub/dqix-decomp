#include <globaldefs.h>
extern "C" int KeyTable_Get(struct Container020e0310 *, int);

extern int data_02153694;

// Main, originally CallFunc020e0434With02153694_020e51cc (USA 0x020e51cc, EUR 0x020e51dc; JPN not identified)
extern "C" ARM int StandardStrings_Get(int value) {
    return KeyTable_Get((struct Container020e0310 *)(&data_02153694), (int)(value));
}
