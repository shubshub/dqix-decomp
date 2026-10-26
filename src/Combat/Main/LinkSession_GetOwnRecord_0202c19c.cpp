#include <globaldefs.h>

// The link session's send buffer: this console's own record.
enum { kSendBufferOffset = 0x7c0 };

// Main, originally GetSubstructAt0x7c0_0202c19c (USA 0x0202c19c, EUR 0x0202c1ac, JPN 0x0202bd4c)
ARM void* LinkSession_GetOwnRecord(void* session) {
    return (char*)session + kSendBufferOffset;
}
