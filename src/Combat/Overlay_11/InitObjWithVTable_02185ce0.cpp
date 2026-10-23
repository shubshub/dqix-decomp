#include <globaldefs.h>

void SpriteContext_Init(char* obj);
extern int data_ov023_021feb40;

// USA: func_ov011_02185ce0
ARM void* InitObjWithVTable_02185ce0(void* obj) {
    *(void**)obj = &data_ov023_021feb40;
    SpriteContext_Init((char*)obj + 0x24);
    return obj;
}
