#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void CharacterModel_SetAngle(void* obj, unsigned int val);
extern "C" void func_ov023_021e616c(char* obj);
extern "C" int CharacterModel_Load(int a, int b, int c, int d, int e);

struct Struct_ov023_021fc71c {
    unsigned char bit0 : 1;
    unsigned char unknown_0_1_ : 7;
};

// USA: func_ov023_021fc71c
extern "C" ARM void func_ov023_021fc71c(void* obj, int id, int arg2) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(battle, id);
    unsigned char bit0 = ((struct Struct_ov023_021fc71c*)((char*)obj + 0x1864))->bit0;
    int idx = (bit0 + 1) % 2;
    int mul = idx * 0xc20;
    char* base = (char*)obj + 0x20;
    if (arg2 != 0) {
        CharacterModel_SetAngle(base + mul, 0x1eb);
    }
    func_ov023_021e616c(base + mul);
    int fieldVal = func_02053c6c((unsigned char*)combatant);
    CharacterModel_Load((int)(base + mul), fieldVal, id, 1, 0);
    *(unsigned char*)((int)obj + 0x1864) |= 8;
}
