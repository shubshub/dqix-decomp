#include <globaldefs.h>

void BackupPairTableToBuffer_020bb700(int* out);
void ReadGlobalPair020bb910(int* dst);

// Main, originally BackupPairTables0207dfac (USA 0x0207dfac, EUR 0x0207dfbc, JPN 0x0207ed2c)
ARM void VramState_Save(char* obj) {
    BackupPairTableToBuffer_020bb700((int*)(obj + 0x28));
    ReadGlobalPair020bb910((int*)(obj + 0x60));
}
