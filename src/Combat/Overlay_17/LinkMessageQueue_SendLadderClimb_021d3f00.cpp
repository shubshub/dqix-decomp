#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
struct SearchStruct;
int LinkSession_IsSlotLost(struct SearchStruct* s, int idx);
void* LinkMessageQueue_GetInstance(void);
unsigned char GameState_GetLeaderIndex(GameState* bs);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d3f00 {
    unsigned char fA;
    unsigned char fB;
    unsigned char nibLo : 4;
    unsigned char nibHi : 4;
    unsigned char fResult;
    int fWord;
};

struct Msg021d3f00 {
    unsigned char tag;
    unsigned char pad1[3];
    struct Sub021d3f00 sub;
    unsigned char pad2[8];
};

// Overlay 17, originally func_ov017_021d3f00 (USA/EUR 0x021d3f00, JPN 0x021d4354)
extern "C" ARM void LinkMessageQueue_SendLadderClimb(SubBlock02038508* obj, unsigned char b, unsigned char c) {
    if (!obj) return;
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    if (LinkSession_IsSlotLost((struct SearchStruct*)search, 0)) return;
    void* p = LinkMessageQueue_GetInstance();

    struct Msg021d3f00 msg;
    struct Sub021d3f00* sub = &msg.sub;
    msg.tag = 0x3b;
    sub->fA = obj->command;
    sub->fB = obj->reversed;
    sub->nibLo = b;
    sub->nibHi = c;
    sub->fWord = obj->unknown48;
    sub->fResult = GameState_GetLeaderIndex(bs);
    func_0205e330(p, &msg, 0);
}
