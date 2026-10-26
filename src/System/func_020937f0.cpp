#include <globaldefs.h>

#include "NitroSDK/VRAM.h"

// USA: func_020937f0
extern "C" ARM int func_020937f0(int engine) {
    int var0 = 0;
    if (engine == 0) {
        switch (GetMainObjVRAMBanks()) {
            case 0: var0 = 0; break;
            case VRAM_BANK_F:
            case VRAM_BANK_G: var0 = 16; break;
            case VRAM_BANK_E: var0 = 64; break;
            case VRAM_BANK_E | VRAM_BANK_F:
            case VRAM_BANK_E | VRAM_BANK_G: var0 = 80; break;
            case VRAM_BANK_A:
            case VRAM_BANK_B: var0 = 128; break;
            case VRAM_BANK_A | VRAM_BANK_B: var0 = 256; break;
            case VRAM_BANK_F | VRAM_BANK_G: var0 = 32; break;
            case VRAM_BANK_E | VRAM_BANK_F | VRAM_BANK_G: var0 = 96; break;
        }
    } else {
        switch (GetSubObjVRAMBanks()) {
            case 0: break;
            case VRAM_BANK_D: var0 = 128; break;
            case VRAM_BANK_I: var0 = 16; break;
        }
    }
    return var0 << 10;
}
