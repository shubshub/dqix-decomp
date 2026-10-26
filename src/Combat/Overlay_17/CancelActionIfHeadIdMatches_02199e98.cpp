#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagWord020466f4;
struct HeadNode02046b24;
struct Obj020397cc;

void GameObject_EnableControl(void* obj);
void* GlobalFlags_GetInstance(void);
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
void GameObject_DisableControl(struct Obj020397cc* obj, int arg1);
extern "C" void func_ov017_02199780(void* obj);

#if defined(jpn)
static const int kActive=0x3e60, kList=0x4ec;
#else
static const int kActive=0x4080, kList=0x6fc;
#endif

// USA: func_ov017_02199e98
ARM void CancelActionIfHeadIdMatches_02199e98(void* obj) {
    if (*(int*)((char*)obj + kActive) == 0) return;
    GameObject* combatant = GameState::GetInstance()->GetLeader();
    GameObject_EnableControl(combatant);
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0x400);
    func_ov017_02199780(obj);
    struct HeadNode02046b24** list = *(struct HeadNode02046b24***)((char*)obj + 0x3000 + kList);
    int id = FieldTaskQueue_GetCurrentKind(list);
    if (id != 0xa && id != 4 && id != 3 && id != 0x21 && id != 0x24) return;
    GameObject_DisableControl((struct Obj020397cc*)combatant, 1);
}
