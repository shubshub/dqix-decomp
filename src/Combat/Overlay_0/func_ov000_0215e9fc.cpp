#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct S_10088;
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" int func_ov000_0215fc60(char* base);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" int func_02010088(struct S_10088* obj);

struct Struct_ov000_0215e9fc {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};

struct Struct_ov000_0215e9fc_2 {
#if defined(jpn)
    unsigned char pad[0x144];
#else
    unsigned char pad[0x150];
#endif
    struct Struct_ov000_0215e9fc* sub;
};

// USA: func_ov000_0215e9fc
extern "C" ARM int func_ov000_0215e9fc(char* obj, short* out, int max, unsigned int flags) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    int n = GameState_GetPartyOrder((char*)gs, ids);
    int var3;
    int var4;
    int i;
    int id;
    GameObject* c;
    int count = 0;
    var4 = flags & 1;
    i = 0;
    var3 = flags & 8;
    for (; i < n; i++) {
        id = ids[i];
        if (func_ov000_0215fc60(obj) != 0 && id != 0) continue;
        if (!func_020a35e0(*(unsigned char**)(obj + 0x8e18), id)) continue;
        c = func_0200ff1c(gs, id);
        if (c == NULL) continue;
        if (func_ov000_02153c0c(c)) continue;
        if (var4 && func_02010088((struct S_10088*)c)) continue;
        if (var3) {
            int var9;
            struct Struct_ov000_0215e9fc* sub = ((struct Struct_ov000_0215e9fc_2*)c)->sub;
            if (sub != NULL) {
                var9 = sub->nibble != 0;
            } else {
                var9 = 0;
            }
            if (var9) continue;
        }
        out[count] = id;
        count++;
        if (count == max) return count;
    }
    return count;
}
