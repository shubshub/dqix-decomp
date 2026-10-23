#include <globaldefs.h>

void ItemTable_Init(void* obj);

// USA: func_0207cbe8
ARM void InitStruct0207cbe8(char* obj) {
    ItemTable_Init(obj + 0x14);
    *(int*)(obj + 0x2c) = 0;
    *(int*)(obj + 0x30) = 0;
    *(int*)(obj + 0x34) = 0;
}
