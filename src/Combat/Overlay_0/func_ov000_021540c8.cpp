#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

extern "C" void func_ov000_021540fc(void*, int, int, int);

// USA: func_ov000_021540c8
extern "C" ARM void func_ov000_021540c8(void* arg0, void* obj2, int val) {
    unsigned char* p = (unsigned char*)obj2;
    GameState::GetInstance();
    func_020797dc();
    int* q = *(int**)(p + 0x10);
    unsigned short a = *(unsigned short*)((char*)q + 0x20);
    unsigned short b = *(unsigned short*)(p + 0x0);
    func_ov000_021540fc(arg0, a, b, val);
}
