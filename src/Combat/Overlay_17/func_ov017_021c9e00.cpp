#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021c9e00 {
    unsigned char id : 3;
    unsigned char flagA : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char flagC : 1;
    unsigned char field1;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    int fieldC;
};

struct Struct_ov017_021c9e00_2 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Struct_ov017_021c9e00 payload;
};

// USA: func_ov017_021c9e00
extern "C" ARM void func_ov017_021c9e00(int id, int flagA, int arg2, int flagC) {
    void* data = LinkMessageQueue_GetInstance();
    GameState* battle = GameState::GetInstance();

    int ok = (id >= 0) && (id <= 3);
    if (!ok) {
        return;
    }

    GameObject* c = func_0200ff1c(battle, id);
    if (c == NULL) {
        return;
    }

    struct Struct_ov017_021c9e00_2 evt;
    struct Struct_ov017_021c9e00* p = &evt.payload;
    evt.tag = 4;
    p->id = id;
    p->field2 = *(unsigned short*)(*(char**)((char*)c + 0x130) + 4);
    p->field6 = *(unsigned short*)(*(char**)((char*)c + 0x130) + 6);
    p->field4 = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x30);
    p->field8 = *(unsigned short*)(*(char**)((char*)c + 0x134) + 0x32);
    p->field1 = *(unsigned char*)(*(char**)((char*)c + 0x130) + 8);
    p->fieldC = *(int*)(*(char**)((char*)c + 0x130));
    p->flagA = flagA;
    p->unknown_0_4_ = arg2;
    p->flagC = flagC;

    func_0205e330(data, &evt, 0);
}
