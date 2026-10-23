#include <globaldefs.h>

struct List0204af64;
void Background_Init(struct List0204af64* obj);
struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);

// USA: func_ov003_0215376c  (semantic: InitCombatSubsystem_0215376c)
extern "C" ARM void func_ov003_0215376c(char* obj) {
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x4) = 0;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x10) = 0;
    Background_Init((struct List0204af64*)(obj + 0x18));
    int negOne;
    *(unsigned char*)(obj + 0x48) = 0;
    *(unsigned char*)(obj + 0x49) = 0;
    negOne = *(unsigned char*)(obj + 0x49) - 1;
    *(int*)(obj + 0x4c) = negOne;
    *(int*)(obj + 0x50) = negOne;
    *(int*)(obj + 0x54) = negOne;
    *(unsigned char*)(obj + 0x59) = negOne;
    *(unsigned char*)(obj + 0x5a) = 0;
    *(unsigned char*)(obj + 0x5b) = 0;
    *(unsigned char*)(obj + 0x5d) = 0;
    *(unsigned char*)(obj + 0x58) = 0;
    BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)(obj + 0x38));
}
