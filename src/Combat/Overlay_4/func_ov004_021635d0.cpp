#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/TreasureMapMetadata.h"

extern char* data_ov004_02171010;
extern "C" unsigned char func_020119f8(char* obj, void* dst);

// USA: func_ov004_021635d0
extern "C" ARM int func_ov004_021635d0(int* arg0, int* arg1) {
#if defined(jpn)
 enum { Enum_ov004_021635d0_2292 = 0x9f4 };
#else
 enum { Enum_ov004_021635d0_2292 = 0x8f4 };
#endif
    if (arg0 == NULL) return 0;
    if (arg1 == NULL) return 0;
    int var0 = -1;
    unsigned char result = func_020119f8((char*)GameState::GetInstance(), NULL);
    int i;
    if (result != 0) {
        for (i = 0; i < *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_021635d0_2292); i++) {
            TreasureMapMetadata* var3 = (TreasureMapMetadata*)(data_ov004_02171010 + i * 0x1c);
            if (var3->GetDiscoveryState() == DiscoveryState_Cleared) {
                var0 = i;
                break;
            }
        }
    } else {
        for (i = 0; i < *(unsigned char*)(data_ov004_02171010 + 0x1000 + Enum_ov004_021635d0_2292); i++) {
            TreasureMapMetadata* var4 = (TreasureMapMetadata*)(data_ov004_02171010 + i * 0x1c);
            if (var4->GetInitialByteUnknownBit()) {
                var0 = i;
                break;
            }
        }
    }
    if (var0 < 0) return 0;
    int q = var0 / 8;
    int rem = var0 - q * 8;
    if (rem < 0) rem = 0;
    *arg0 = q;
    *arg1 = rem;
    return 1;
}
