#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020ac9ac_14076 = 0x34ec };
#else
enum { Enum_020ac9ac_14076 = 0x36fc };
#endif
#include "GameState/GameState.h"

extern "C" void* Zone3D_GetInstance(GameState* battleStruct);
struct PointerField330_ffd0;
extern "C" void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
struct S02046b1c;
extern "C" int func_02046b1c(struct S02046b1c* p);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020ad61c(void* p);
extern "C" void func_ov017_02193dc4(void* p);

struct Struct_020ac9ac { char pad[Enum_020ac9ac_14076]; void* unknown_36fc_; };

// USA: func_020ac9ac
extern "C" ARM void func_020ac9ac(struct Struct_020ac9ac* a0) {
    GameState* battle = GameState::GetInstance();
    void* p;
    int headId;
    void* field = a0->unknown_36fc_;
    Zone3D_GetInstance(battle);
    p = GameState_GetStarflight((struct PointerField330_ffd0*)battle);
    headId = FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field);
    int f0 = func_02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    if (headId == 3) {
        if (IsBrightnessTransitionActive((GameResources*)a0) == 0) return;
    }
    func_020ad61c(p);
    func_ov017_02193dc4(p);
}
