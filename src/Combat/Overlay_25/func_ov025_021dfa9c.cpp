#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" int func_ov000_02160f9c(void* obj);
struct Struct_ov000_0215440c_2;
struct Struct_ov000_02160094;
extern "C" struct Struct_ov000_02160094* func_ov000_02160094(struct Struct_ov000_0215440c_2* list, int index);
struct Struct_ov000_0215440c;
struct Struct_ov000_021600f8;
extern "C" struct Struct_ov000_021600f8* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" int func_02048bd0(unsigned char* obj);
extern "C" short func_ov000_0215ffa0(void* obj);
extern "C" int func_02048ae0(void* obj, int type, void* out, int flag);

// USA: func_ov025_021dfa9c
extern "C" ARM int func_ov025_021dfa9c(void* obj, void* base) {
    GameState* battle = GameState::GetInstance();
    void* slot = func_ov000_02160f20(obj);
    int count = func_ov000_02160f9c(obj);
    struct Struct_ov000_02160094* node = func_ov000_02160094((struct Struct_ov000_0215440c_2*)slot, 0);
    int flagVal;
    GameObject* combatant;
    char* target;
    struct Struct_ov000_02160094* node2;
    struct Struct_ov000_021600f8* nodeA;
    struct Struct_ov000_021600f8* nodeB;
    int localBuf[2];
    int result;

    if (node == NULL) goto fail;
    flagVal = *(unsigned short*)slot;
    combatant = battle->GetCombatantByIndex(*(unsigned short*)((char*)node + 0x20));
    if (combatant == NULL) goto fail;
    if (count <= 0) goto fail;
    if (flagVal != 1) goto fail;
    if (!func_02048bd0((unsigned char*)combatant)) goto fail;

    target = (char*)base + 0x21c + 0x8000 + (count - 1) * 0x28;
    if (target == NULL) goto fail;

    node2 = func_ov000_02160094((struct Struct_ov000_0215440c_2*)target, 0);
    if (node2 == NULL) goto fail;
    if (*(unsigned short*)((char*)node2 + 0x20) != *(unsigned short*)((char*)node + 0x20)) goto fail;

    nodeA = func_ov000_021600f8((struct Struct_ov000_0215440c*)slot, 0);
    nodeB = func_ov000_021600f8((struct Struct_ov000_0215440c*)target, 0);
    if (nodeA == NULL || nodeB == NULL) goto fail;
    if (*(short*)((char*)nodeA + 0xe) != *(short*)((char*)nodeB + 0xe)) goto fail;
    if (*(unsigned short*)target != 1) goto fail;

    if (*(short*)((char*)nodeB + 0xe) != func_ov000_0215ffa0(nodeB)) goto fail;

    result = func_02048ae0(combatant, flagVal, &localBuf[0], 2);
    if (result >= 2) return localBuf[1];

fail:
    return 0;
}
