#include <globaldefs.h>

extern "C" void LinkSession_Reset(void* session);

// Main, originally InitReturnSelf0202c794 (USA 0x0202c794, EUR 0x0202c7a4, JPN 0x0202c304)
extern "C" ARM void* LinkSession_Construct(void* session) {
    LinkSession_Reset(session);
    return session;
}
