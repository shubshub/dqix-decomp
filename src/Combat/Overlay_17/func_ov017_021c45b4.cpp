#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void* func_02052a10(char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c45b4 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned char field4;
    char name[15];
};

// USA: func_ov017_021c45b4
extern "C" ARM void func_ov017_021c45b4(int combatantId) {
    GameState* bs = GameState::GetInstance();
    void* p = LinkMessageQueue_GetInstance();
    GameObject* c = func_0200ff1c(bs, combatantId);
    if (!c) return;

    struct Struct_ov017_021c45b4 buf;
    buf.tag = 3;
    buf.field4 = (unsigned char)combatantId;
#if defined(jpn)
    char* var4 = *(char**)((char*)c + 0x134);
#else
    char* var4 = (char*)func_02052a10((char*)c);
#endif
    strcpy(buf.name, var4);
    func_0205e330(p, &buf, 0);
}
