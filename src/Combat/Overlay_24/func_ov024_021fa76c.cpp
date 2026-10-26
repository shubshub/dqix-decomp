#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);

extern "C" int func_ov024_021e6798(GameObject* combatant);

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

extern "C" int func_020882f8(unsigned char* obj);

struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);

struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);

struct Struct_021fa76c {
    char unk[0x138];
    unsigned char* unknown_138_;
};

// USA: func_ov024_021fa76c
extern "C" ARM int func_ov024_021fa76c(struct Struct_021fa76c* combatant) {
    if (func_02010088((struct S_10088*)combatant)) return 0;
    if (func_ov024_021e6798((GameObject*)combatant)) return 0;
    if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)combatant)) return 0;
    if (func_020882f8(combatant->unknown_138_)) return 0;
    if (func_ov024_021da9c8((struct Struct_ov024_021da670_8*)combatant)) return 0;
    return !func_ov024_021de25c((struct Struct_ov024_021de124*)combatant);
}
