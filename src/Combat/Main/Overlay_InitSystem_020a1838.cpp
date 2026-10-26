#include <globaldefs.h>
#include "NitroSDK/Filesystem/OverlayFSManagement.h"

struct Struct_01ffd34c;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
extern "C" void func_020a18d4(char* p);

extern struct Struct_01ffd34c data_01ffd34c;
extern unsigned char data_01ffd344;
extern unsigned char data_01ffd340;
extern char data_01ffd364[8][6];
extern struct OverlayMetadata data_01ffd394[35];
extern int data_01ffd348;

// Main, originally InitOverlaySystem_020a1838 (USA 0x020a1838, EUR 0x020a1848, JPN 0x020a35b0)
extern "C" ARM void Overlay_InitSystem(void) {
    unsigned int i;
    unsigned int j;

    ZeroInitializeMutex((Mutex*)&data_01ffd34c);
    data_01ffd344 = 1;
    data_01ffd340 = 0;

    for (i = 0; i < 8; i++) {
        func_020a18d4(data_01ffd364[i]);
    }

    for (j = 0; j < 0x23; j++) {
        LoadOverlayMetadata(&data_01ffd394[j], false, j);
    }

    data_01ffd348 = 0;
}
