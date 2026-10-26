#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215ec80(int a, short* buf, int max, int arg3, int extra);
extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021f5344 { int field0; };
struct Struct_ov024_021fee4c { short v[8]; };
extern struct Struct_ov024_021fee4c data_ov024_021fee4c;

// USA: func_ov024_021f5344
extern "C" ARM int func_ov024_021f5344(struct Struct_ov024_021f5344* obj, short id, int arg2, int* outFlag, short* arg4) {
    GameObject* c = func_ov000_021536f8(obj->field0, id);
    if (!c) return 0;
    int stateByte = *((unsigned char*)c + 0x17c);
    if (stateByte >= 3) return 0;
    struct Struct_ov024_021fee4c buf = data_ov024_021fee4c;
    int count = func_ov000_0215ec80(obj->field0, buf.v, 8, stateByte & 0xff, 1);
    int matched = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c2 = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c2) continue;
        if (!func_020882f8((unsigned char*)c2->currentStats_)) matched++;
    }
    if (matched != 8) return 0;
    *outFlag = 1;
    *arg4 = id;
    return 1;
}
