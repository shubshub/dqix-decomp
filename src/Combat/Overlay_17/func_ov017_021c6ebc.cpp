#include <globaldefs.h>

#if defined(jpn)
enum { kRegionalFieldOffset = 0x508 };
#else
enum { kRegionalFieldOffset = 0x718 };
#endif
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
extern "C" void* func_ov017_021b8470(void* obj);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
struct Struct_020886dc_2;
extern "C" void func_02088818(struct Struct_020886dc_2* obj, unsigned short mode);

struct Struct_ov017_021c6ebc {
    unsigned short fieldA : 2;
    unsigned short fieldB : 4;
    unsigned short fieldC : 3;
    unsigned short state : 3;
    unsigned short : 4;
};

struct Struct_ov017_021c6ebc_2 {
    char pad0[4];
    unsigned short field4;
    unsigned short field6;
    struct Struct_ov017_021c6ebc unknown_8_;
    unsigned char fielda;
    unsigned char unknown_b_;
    unsigned short fieldc;
    unsigned short unknown_e_;
};

// USA: func_ov017_021c6ebc
extern "C" ARM void func_ov017_021c6ebc(int unused0, struct Struct_ov017_021c6ebc_2* src, GameState* battleStruct, unsigned char* base) {
    unsigned char* table = *(unsigned char**)(base + 0x3000 + kRegionalFieldOffset);
    unsigned char* obj = (unsigned char*)func_ov017_021b8478(table);
    if (obj == 0) {
        return;
    }
    if (func_ov017_021b8468(table) == 0) {
        return;
    }
    if (func_ov017_021b8470(table) == 0) {
        return;
    }
    if (*(signed char*)(obj + 0x2a) == GameState_GetProtagonistIndex(battleStruct)) {
        return;
    }
    if (*(unsigned short*)(obj + 8) != src->field4) {
        return;
    }
    GameObject* combatant = battleStruct->GetCombatantByIndex(src->field6);
    if (combatant == 0) {
        return;
    }
    struct Struct_ov017_021c6ebc* dst;
    unsigned char a = src->unknown_8_.fieldA;
    dst = (struct Struct_ov017_021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldA = a;
    unsigned char b = src->unknown_8_.fieldB;
    dst = (struct Struct_ov017_021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldB = b;
    unsigned char c = src->unknown_8_.fieldC;
    dst = (struct Struct_ov017_021c6ebc*)((unsigned char*)combatant->currentStats_ + 0x22);
    dst->fieldC = c;
    unsigned char st = src->unknown_8_.state;
    func_02088818((struct Struct_020886dc_2*)combatant->currentStats_, st);
    *((unsigned char*)combatant->currentStats_ + 0x24) = src->fielda;
    *(unsigned short*)((unsigned char*)combatant->currentStats_ + 4) = src->fieldc;
    *(unsigned short*)((unsigned char*)combatant->currentStats_ + 6) = src->unknown_e_;
}
