#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"

extern "C" {
    void* func_0202ae18(GrottoStruct* grotto);
    int func_0202c508(void* something);
    void* Zone3D_GetInstance(void);
}

struct FlagWord020466f4;
struct ListHead02046b60;
struct Obj020941b0;

struct StructWithNibble020dc2d0 {
    char pad[0xc];
    unsigned char nibbleLo : 4;
    unsigned char nibbleHi : 4;
};

void SetModeBasedOnCombatState020dc214(int mode);
int* GetGlobal02109030_020936f8(void);
void ReleaseHandleAndClearFlags(struct Obj020941b0* p);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
int ListContainsId(struct ListHead02046b60* list, int id);

#if defined(jpn)
enum { CombatModeListOffset = 0x4ec };
#else
enum { CombatModeListOffset = 0x6fc };
#endif

// USA: func_020dc2d0
ARM void SetCombatModeFromCase020dc2d0(int mode) {
    GameState* battle = GameState::GetInstance();
    GrottoStruct* grotto = battle->GetGrottoStruct();
    void* something = func_0202ae18(grotto);
    void* ptr = Zone3D_GetInstance();
    int flag1;
    int flag2;
    StructWithNibble020dc2d0* field8 = *(StructWithNibble020dc2d0**)((char*)ptr + 0x8);

    int base = ((int)GetGameResources());
    flag1 = 0;
    void* list = *(void**)(base + 0x3000 + CombatModeListOffset);
    flag2 = flag1;

    int listContains = ListContainsId((ListHead02046b60*)list, 0x43);
    if (listContains) {
        flag1 = 1;
    }

    if (grotto->unknown_0[0] != 0 && grotto->unknown_0[1] != 0) {
        if (func_0202c508(something) != 0 && field8 != NULL) {
            if (field8->nibbleLo == 0) {
                flag1 = 1;
            }
        }
    }

    if (mode == 1) {
        flag1 = 1;
    } else if (mode == 2) {
        flag1 = 0;
    } else if (mode == 3) {
        flag2 = 1;
    }

    if (flag1) {
        SetModeBasedOnCombatState020dc214(1);
    } else if (flag2) {
        SetModeBasedOnCombatState020dc214(2);
    } else {
        SetModeBasedOnCombatState020dc214(0);
    }

    ReleaseHandleAndClearFlags((Obj020941b0*)GetGlobal02109030_020936f8());
    FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x41);
}
