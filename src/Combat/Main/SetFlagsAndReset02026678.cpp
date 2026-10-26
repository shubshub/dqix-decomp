#include <globaldefs.h>

void MapDisplay_ClearRedChests(char* obj);

// USA: func_02026678
ARM void SetFlagsAndReset02026678(char* obj) {
#if defined(jpn)
    *(unsigned char*)(obj + 0x90c) = 1;
    *(unsigned char*)(obj + 0x90d) = 0;
#else
    *(unsigned char*)(obj + 0x9b8) = 1;
    *(unsigned char*)(obj + 0x9b9) = 0;
#endif
    MapDisplay_ClearRedChests(obj);
}
