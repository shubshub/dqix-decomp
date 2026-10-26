#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020aca30_14076 = 0x34ec };
#else
enum { Enum_020aca30_14076 = 0x36fc };
#endif
#include "GameState/GameState.h"

extern "C" void func_020ae074(void* a);
struct PointerField330_ffd0;
extern "C" void* GameState_GetStarflight(struct PointerField330_ffd0* obj);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
struct S02046b1c;
extern "C" int func_02046b1c(struct S02046b1c* p);

struct Struct_020aca30 { char pad[Enum_020aca30_14076]; void* unknown_36fc_; };

// USA: func_020aca30
extern "C" ARM void func_020aca30(struct Struct_020aca30* a0) {
    GameState* battle = GameState::GetInstance();
    void* p;
    void* field = a0->unknown_36fc_;
    p = GameState_GetStarflight((struct PointerField330_ffd0*)battle);
    int headId = FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field);
    int f0 = func_02046b1c((struct S02046b1c*)field);
    if (p == NULL) return;
    if (headId == 0xa) {
        if (*((unsigned char*)f0 + 3) != 0) return;
    }
    func_020ae074(p);
}
