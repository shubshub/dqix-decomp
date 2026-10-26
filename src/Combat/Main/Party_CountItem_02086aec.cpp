#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086aec {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_02083994;
extern "C" int func_02083994(struct Struct_02083994* s, int value);

struct Struct_0206f81c;
struct Struct_0206f81c_8;
extern "C" struct Struct_0206f81c_8* func_02083554(struct Struct_0206f81c* c, int id);

extern "C" short func_02086bf4(char* obj, int key);

// Main, originally SumCombatantKeyMatches02086aec (USA 0x02086aec, EUR 0x02086afc, JPN 0x0208740c)
extern "C" ARM short Party_CountItem(struct Obj02086aec* obj, int key) {
    short var0;
    GameState* bs;
    unsigned char i;
    GameObject* c;
    void* x;
    if (key < 0) {
        return 0;
    }
    var0 = 0;
    bs = GameState::GetInstance();
    for (i = 0; i < obj->count; i++) {
        c = func_0200ff1c(bs, obj->ids[i]);
        if (c != NULL) {
            x = (void*)func_02053c6c((unsigned char*)c);
            if (x != NULL) {
                var0 = var0 + func_02083994((struct Struct_02083994*)x, key);
                if (func_02083554((struct Struct_0206f81c*)x, key) != NULL) {
                    var0 = var0 + 1;
                }
            }
        }
    }
    return var0 + func_02086bf4((char*)obj, key);
}
