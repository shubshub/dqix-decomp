#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov000_02156558_336 = 0x144, Enum_ov000_02156558_2384 = 0x8b8 };
#else
enum { Enum_ov000_02156558_336 = 0x150, Enum_ov000_02156558_2384 = 0x950 };
#endif
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215fc60(char* base);
extern "C" int func_ov000_02155f9c(struct Random* arg0, int combatantId, int arg2);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_ov000_02156404(GameObject* combatant);
extern "C" int func_02083b00(unsigned char* obj, int index);
int NextRandomMax(struct Random* random, int maximum);

extern unsigned char data_ov000_02182ab8[];

// USA: func_ov000_02156558
extern "C" ARM int func_ov000_02156558(struct Random* arg0, int combatantId) {
    if (func_ov000_0215fc60((char*)arg0) != 0) {
        return 0;
    }

    GameState* bs = GameState::GetInstance();
    int inRange = (combatantId >= 0 && combatantId <= 3) ? 1 : 0;
    if (!inRange) {
        return 0;
    }

    if (func_ov000_02155f9c(arg0, combatantId, 0) != 0) {
        return 0;
    }

    GameObject* c = func_0200ff1c(bs, combatantId);
    if (c == 0) {
        return 0;
    }

    if (func_ov000_02156404(c)) {
        short val = *(short*)((char*)arg0 + 0x8e00 + 0x6e);
        if (val >= 0x32) {
            if (val < 0x4b) return 1;
        }
        return 0;
    }

    if (func_02083b00(*(unsigned char**)((char*)c + Enum_ov000_02156558_336), 0x36) == 0) {
        return 0;
    }

    int idx = *(int*)((char*)(*(void**)((char*)c + Enum_ov000_02156558_336)) + Enum_ov000_02156558_2384);
    int var5 = data_ov000_02182ab8[idx];
    return NextRandomMax(arg0, var5) == 1;
}
