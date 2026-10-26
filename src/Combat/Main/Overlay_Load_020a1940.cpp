#include <globaldefs.h>
#include "NitroSDK/Filesystem/OverlayFSManagement.h"
#include "Resource/ResourceMutex.h"
#include "NitroSDK/Mutex.h"

extern "C" int Overlay_Unload(unsigned int id);
void DispatchByFlag020d9834(int flag);
bool LoadCompressedOverlay(const OverlayMetadata& overlay);
void DecompressAndStaticInitializeOverlay(const OverlayMetadata& overlay);

extern volatile int data_01ffd348;
struct Struct_01ffd364 {
    volatile signed char unknown_0_[6];
};
extern Struct_01ffd364 data_01ffd364[8];
extern volatile unsigned char data_01ffd340;
extern volatile unsigned char data_01ffd344;
extern Mutex data_01ffd34c;
extern OverlayMetadata data_01ffd394[35];

struct Struct_020e8f20_2 {
    int unknown_0_;
    int unknown_4_;
};
extern Struct_020e8f20_2 data_020e8f20[35];

// Main, originally func_020a1940 (USA 0x020a1940, EUR 0x020a1950, JPN 0x020a36b8)
extern "C" ARM int Overlay_Load(int id) {
    int result = 0;
    if ((unsigned int)id < 35) {
        OverlaySlotEntry* table;
        int rowIndex = data_01ffd348;
        table = data_020e8f20;
        OverlayMappingRow* const row = &data_01ffd364[rowIndex];
        int column = table[id].column;
        signed char mappedOverlay = row->entries[column];
        if (mappedOverlay != id) {
            Overlay_Unload(mappedOverlay);
            while (data_01ffd340 != 0) {
                func_020d9834(0);
            }
            data_01ffd340 = 1;
            LockResourceMutex();
            OverlayMetadata* const var6 = data_01ffd394;
            LoadCompressedOverlay(var6[arg0]);
            DecompressAndStaticInitializeOverlay(var6[arg0]);
            UnlockResourceMutex();
            data_01ffd340 = 0;
            if (data_01ffd344 != 0) {
                LockMutex(&data_01ffd34c);
            }
            var3->unknown_0_[var1[arg0].unknown_0_] = (signed char)arg0;
            if (data_01ffd344 != 0) {
                UnlockMutex(&data_01ffd34c);
            }
            var0 = 1;
        } else {
            var0 = 1;
        }
    }
    return var0;
}
