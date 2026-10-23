#include <globaldefs.h>

extern "C" void VramState_Reserve(void* p, int a, int b);
extern int data_ov023_021fd6ac[];
extern int data_ov023_021fd6fc[];

// Overlay 23, originally InitBlockArray_021e4fd8 (USA/EUR 0x021e4fd8, JPN 0x021e51bc)
ARM void CharacterModel_ReserveVram(void* obj) {
    char* base;
    int i;
    base = (char*)obj + 0x394;
    i = 0;
    base = base + 0x400;
    for (; i < 10; i++) {
        VramState_Reserve(base + i * 0x70, data_ov023_021fd6ac[i], data_ov023_021fd6fc[i]);
    }
}
