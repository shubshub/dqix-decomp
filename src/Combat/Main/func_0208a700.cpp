#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" int func_0208a03c(void* p0, int arg1, int id, int* outPtr, int p3);
extern "C" int func_ov000_02154a04(int field0, int id, int flag, int p3);

struct Struct_0208a700 { char pad[0x18]; unsigned short values[6]; };
struct Struct_0208a700_2 { char pad[0x148]; Struct_0208a700* table; };

enum Enum_0208a700 { Enum_0208a700_0 = 0, Enum_0208a700_1 = 1, Enum_0208a700_2 = 2, Enum_0208a700_5 = 5 };

// USA: func_0208a700
extern "C" ARM int func_0208a700(int* p0, int id, int* outPtr, int p3) {
    unsigned char i;
    GameState* bs;
    GameObject* combatant;
    struct ModifiableCombatStats* stats;
    unsigned char* var4;
    Enum_0208a700 none;
    Enum_0208a700 first;
    Enum_0208a700 last;
    Enum_0208a700 var8;
    int start;
    int end;
    unsigned char count;
    unsigned char offset;
    unsigned char j;
    unsigned char slot;
    Struct_0208a700* table;

    none = Enum_0208a700_0;
    first = Enum_0208a700_1;
    last = Enum_0208a700_5;
    var8 = Enum_0208a700_2;
    bs = GameState::GetInstance();
    combatant = func_0200fea4(bs, id);
    stats = combatant->currentStats_;
    table = ((Struct_0208a700_2*)combatant)->table;
    var4 = (unsigned char*)((char*)stats + 0x38);
    *var4 = *var4 % 2u;

    for (i = 0; i < 2; i++) {
        start = none;
        end = none;
        if (*var4 != 0) {
            start = first;
            end = last;
        }
        count = end - start + 1;
        offset = NextRandomMax((struct Random*)*p0, count);
        *var4 = *var4 + 1;
        *var4 = *var4 % 2u;
        for (j = 0; j < count; j++) {
            slot = start + offset;
            if (func_0208a03c(p0, slot, id, outPtr, p3) != 0) {
                return table->values[slot];
            }
            offset++;
            offset %= count;
        }
    }
    *outPtr = 0;
    *outPtr = func_ov000_02154a04(*p0, id, var8, p3);
    return var8;
}
