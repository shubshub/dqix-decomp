#include <globaldefs.h>
#include "NitroSDK/Mutex.h"
#include "Resource/ResourceMutex.h"
#include "NitroSDK/Filesystem/OverlayFSManagement.h"

extern "C" void func_020d9834(int arg0);
extern "C" void func_020cd584(OverlayMetadata* arg0);

extern volatile int data_01ffd348;
extern volatile unsigned char data_01ffd344;
extern volatile unsigned char data_01ffd340;
extern signed char data_01ffd364;
extern Mutex data_01ffd34c;
extern struct OverlayMetadata data_01ffd394[35];

struct Struct_020e8f20 {
    int unknown_0_;
    int unknown_4_;
};
extern struct Struct_020e8f20 data_020e8f20[];

// Main, originally func_020a1bb4 (USA 0x020a1bb4, EUR 0x020a1bc4, JPN 0x020a392c)
extern "C" ARM int Overlay_Unload(unsigned int id) {
    int ok = 0;
    if (id < 0x23) {
    struct Entry020e8f20* table;
    int rowIdx = data_01ffd348;
    table = data_020e8f20;

    if (data_01ffd344) {
        LockMutex(&data_01ffd34c);
    }
#if defined(jpn)
    volatile signed char* var3 = &data_01ffd364 + var2 * 6;
#else
    signed char* var3 = ((__typeof__(&data_01ffd364))0x01FFD364) + var2 * 6;
#endif
    int var4 = var1[arg0].unknown_0_;
    var3[var4] = arg0 | 0x40;
    if (data_01ffd344) {
        UnlockMutex(&data_01ffd34c);
    }

    while (data_01ffd340) {
        func_020d9834(0);
    }

    data_01ffd340 = 1;
    LockResourceMutex();
    func_020cd584(&data_01ffd394[arg0]);
    UnlockResourceMutex();
    data_01ffd340 = 0;

    if (data_01ffd344) {
        LockMutex(&data_01ffd34c);
    }
    int var5 = var1[arg0].unknown_0_;
    var3[var5] = -1;
    if (data_01ffd344) {
        UnlockMutex(&data_01ffd34c);
    }

    var0 = 1;
    }
    return var0;
}
