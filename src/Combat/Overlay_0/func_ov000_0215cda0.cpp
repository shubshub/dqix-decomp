#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"

struct Struct_02049b54_2;
extern "C" int func_ov000_0215eb1c(void* p0, short* ids, int count, int flag);
extern "C" Vector3i func_02049b54(struct Struct_02049b54_2* obj);

struct Struct_ov000_02182c34 { short ids[8]; };
extern struct Struct_ov000_02182c34 data_ov000_02182c34;

// USA: func_ov000_0215cda0
extern "C" ARM int func_ov000_0215cda0(void* p0) {
    struct Struct_ov000_02182c34 list = data_ov000_02182c34;
    int result = -1;
    int count = func_ov000_0215eb1c(p0, list.ids, 8, 1);
    Vector3i best;
    for (int i = 0; i < count; i++) {
        short id = list.ids[i];
        GameState* gs = GameState::GetInstance();
        GameObject* c = gs->GetCombatantByIndex(id);
        if (c != NULL) {
            Vector3i pos = func_02049b54((struct Struct_02049b54_2*)c);
            if (result > 0) {
                if (pos.x < best.x) {
                    best = pos;
                    result = list.ids[i];
                }
            } else {
                result = list.ids[i];
                best = pos;
            }
        }
    }
    return result;
}
