#include <globaldefs.h>

// Zone3D's pending field tasks byte (Zone3D_StartPendingFieldTask starts them)
#if defined(jpn)
enum { kPendingFieldTasksOffset = 0x2784 };
#else
enum { kPendingFieldTasksOffset = 0x2744 };
#endif

// Main, originally TestFlagBitAt0x2744_0201bfc0 (USA 0x0201bfc0, EUR 0x0201bfd0, JPN 0x0201bd38)
ARM int Zone3D_IsFieldTaskPending(unsigned char* zone, int task) {
    return zone[kPendingFieldTasksOffset] & (1 << task);
}
