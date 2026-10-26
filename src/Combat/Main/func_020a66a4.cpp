#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020a66a4_14076 = 0x34ec, Enum_020a66a4_1816 = 0x508 };
#else
enum { Enum_020a66a4_14076 = 0x36fc, Enum_020a66a4_1816 = 0x718 };
#endif
#include "GameState/GameState.h"

struct PointerField32c_ffc0;
extern "C" void* GameState_GetShip(struct PointerField32c_ffc0* obj);
struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);
struct S02046b1c;
extern "C" int func_02046b1c(struct S02046b1c* p);
struct Obj020a7eb8;
extern "C" void func_020a7eb8(struct Obj020a7eb8* obj);
extern "C" int func_ov017_021b8b54(void* obj);
extern "C" void* func_02057924(void* obj);
extern "C" void func_02057ab8(void* g, int arg);

struct Struct_020a66a4_2 {
    char pad0[Enum_020a66a4_14076];
    void* unknown_36fc_;
};

struct Struct_020a66a4_3 {
    char pad0[Enum_020a66a4_1816];
    void* unknown_718_;
};

// USA: func_020a66a4
extern "C" ARM void func_020a66a4(struct Struct_020a66a4_2* a0) {
    void* p;
    void* field;
    int headId;
    void* g;
    void* other;
    GameState* battle = GameState::GetInstance();
    field = a0->unknown_36fc_;
    p = GameState_GetShip((struct PointerField32c_ffc0*)battle);
    headId = FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)field);
    func_02046b1c((struct S02046b1c*)field);
    struct Struct_020a66a4_3* sub = (struct Struct_020a66a4_3*)((char*)a0 + 0x3000);
    other = sub->unknown_718_;
    g = func_02057924(sub);
    if (p == NULL) return;
    if (headId == 0xa && *((unsigned char*)other + 3) != 0) {
        if (func_ov017_021b8b54(other)) return;
    }
    func_020a7eb8((struct Obj020a7eb8*)p);
    func_02057ab8(g, 0xc9);
}
