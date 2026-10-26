#include <globaldefs.h>

extern "C" void LinkSession_End(void* session);

// Main, originally Forward0202aff4 (USA 0x0202aff4, EUR 0x0202b004, JPN 0x0202aba4)
extern "C" ARM void LinkSession_Close(void* session) {
    LinkSession_End(session);
}
