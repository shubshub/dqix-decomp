#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* ptr, int size);
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" void func_ov017_021d6134(void*, int);

struct Struct_ov023_021ea630 { char pad[4]; unsigned short maxHP; };
struct Struct_ov023_021ea630_2 { unsigned short unknown_0_; char pad[0x130 - 2]; struct Struct_ov023_021ea630* current; };

// USA: func_ov023_021ea630
extern "C" ARM int func_ov023_021ea630(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char buf[4];
    __clear(buf, 4);
    int n = GameState_GetPartyOrder((char*)bs, buf);
    int count = 0;
    for (int i = 0; i < n; i++) {
        struct Struct_ov023_021ea630_2* c = (struct Struct_ov023_021ea630_2*)func_0200ff1c(bs, buf[i]);
        if (c == NULL) continue;
        if (c->unknown_0_ & 0x1000) continue;
        int hp = c->current->maxHP;
        if (hp <= 0) count++;
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
