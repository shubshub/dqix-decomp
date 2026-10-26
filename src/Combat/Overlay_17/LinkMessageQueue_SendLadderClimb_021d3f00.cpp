#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct;
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* s, int idx);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* bs);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d3f00 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_0_ : 4;
    unsigned char unknown_2_4_ : 4;
    unsigned char fResult;
    int unknown_4_;
};

struct Struct_ov017_021d3f00_2 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Struct_ov017_021d3f00 sub;
    unsigned char pad2[8];
};

// Overlay 17, originally func_ov017_021d3f00 (USA/EUR 0x021d3f00, JPN 0x021d4354)
extern "C" ARM void LinkMessageQueue_SendLadderClimb(SubBlock02038508* obj, unsigned char b, unsigned char c) {
    if (!obj) return;
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    if (LinkSession_IsSlotLost((struct SearchStruct*)search, 0)) return;
    void* p = LinkMessageQueue_GetInstance();

    struct Struct_ov017_021d3f00_2 msg;
    struct Struct_ov017_021d3f00* sub = &msg.sub;
    msg.tag = 0x3b;
    sub->unknown_0_ = obj->command;
    sub->unknown_1_ = obj->reversed;
    sub->unknown_2_0_ = b;
    sub->unknown_2_4_ = c;
    sub->unknown_4_ = obj->unknown48;
    sub->fResult = GameState_GetLeaderIndex(bs);
    func_0205e330(p, &msg, 0);
}
