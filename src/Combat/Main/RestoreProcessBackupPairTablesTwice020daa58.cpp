#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "std_library_functions.h"

struct Pair020daa58 { int a; int b; };

void VramState_Restore(char* obj);
void VramState_Save(char* obj);
extern "C" int func_02057924(void);
extern "C" int func_02057e6c(int, int, int, int, int, int);
extern const char data_020f28cb;

// USA: func_020daa58  (semantic: RestoreProcessBackupPairTablesTwice020daa58)
extern "C" ARM int func_020daa58(Pair020daa58* obj, GPCFile* gpc, int val1, int val2) {
    int x = func_02057924();
    int fd;
    int a = obj->a;
    int b = obj->b;
    if (!x || !a || !b) return 0;

    unsigned int fileSize = 0;
    void* fileData = NULL;
    char name[32];
    sprintf(name, &data_020f28cb, val1);
    if (GetUnknownGP2InnerFileDataByName(&fileData, &fileSize, gpc, name)) {
        fd = (int)fileData;
        VramState_Restore((char*)b);
        func_02057e6c(x, 0x14, a, fd, fileSize, b);
        VramState_Save((char*)b);
    }
    sprintf(name, &data_020f28cb, val2);
    if (GetUnknownGP2InnerFileDataByName(&fileData, &fileSize, gpc, name)) {
        fd = (int)fileData;
        VramState_Restore((char*)b);
        func_02057e6c(x, 0x15, a, fd, fileSize, b);
        VramState_Save((char*)b);
    }
    return 1;
}
