#include <globaldefs.h>
int Camera_GetKindFlags(int);

// USA: func_020100cc
ARM int GetFieldIfFlag2_020100cc(char* obj) {
    int p = *(int*)(obj + 0x3b0);
    if (p != 0) {
        if (Camera_GetKindFlags((int)(p)) & 2) {
            return *(int*)(obj + 0x3b0);
        }
    }
    return 0;
}
