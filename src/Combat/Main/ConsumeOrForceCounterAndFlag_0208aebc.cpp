#include <globaldefs.h>

#if defined(jpn)
enum { kTargetOffset = 0x4c0 };
#else
enum { kTargetOffset = 0x6d0 };
#endif

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Sub130_020482e0 {
    unsigned int flags;
    unsigned short count;
};
struct Combatant020482e0 {
    char pad[0x130];
    struct Sub130_020482e0* sub;
};
int ConsumeCounter020482e0(struct Combatant020482e0* c, int amount, int force);

void SetBoolFlagAt558_02026f08(unsigned char* base, int index, int value);
void SetArrayEntryFlag02026f20(int a, int index);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_0208aebc  (semantic: ConsumeOrForceCounterAndFlag_0208aebc)
extern "C" ARM void func_0208aebc(void* obj, int id) {
    GameState* bs = GameState::GetInstance();
    char* base = (char*)GetGameResources() + 0x3000;
    struct Combatant020482e0* c;
    void* p;
    int* target;
    unsigned short oldCount;

    target = *(int**)(base + kTargetOffset);
    c = (struct Combatant020482e0*)bs->GetPartyMemberByIndex(id);
    p = LinkSession_GetInstance();
    oldCount = c->sub->count;

    if (LinkSession_IsHostOrSolo(p) == 0) {
        c->sub->count = 1;
    } else {
        unsigned char amount = ((unsigned char*)obj)[5];
        ConsumeCounter020482e0(c, amount, 0);
    }

    unsigned short newCount = c->sub->count;
    if (oldCount != newCount) {
        SetBoolFlagAt558_02026f08((unsigned char*)target, id, 1);
        SetArrayEntryFlag02026f20((int)target, id);
    }

    if (LinkSession_IsActive((int*)p)) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
}
