#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"
#include "GameState/GameState.h"

extern "C" int MessageSystem_GetInstance();
extern "C" void func_02046380(void*);
extern "C" void* func_02011aa0(char* base, unsigned int index);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
extern "C" void func_020464e8(char* base, int index, char* src);

// USA: func_ov004_02165d74
extern "C" ARM int func_ov004_02165d74(void* a) {
    int g = MessageSystem_GetInstance();
    func_02046380((void*)g);
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetLeader();
    char buf[0x40];
    VectorizedMemset(buf, 0, 0x40);
    strcpy(buf, (char*)func_02011aa0((char*)bs, 0));
    if (combatant != NULL) {
        MessageSystem_SetStringArgument((struct Obj02046574*)g, 0, *(char**)((char*)combatant + 0x134));
    }
    func_020464e8((char*)g, 0, buf);
    return 0;
}
