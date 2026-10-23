#include <globaldefs.h>

void RestorePairTableFromBuffer_020bb740(int* out);
void WriteGlobalPair020bb92c(int* src);

// Main, originally RestorePairTables0207df90 (USA 0x0207df90, EUR 0x0207dfa0, JPN 0x0207ed10)
ARM void VramState_Restore(char* obj) {
    RestorePairTableFromBuffer_020bb740((int*)(obj + 0x28));
    WriteGlobalPair020bb92c((int*)(obj + 0x60));
}
