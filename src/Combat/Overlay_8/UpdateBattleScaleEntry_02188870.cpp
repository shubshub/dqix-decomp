#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);

struct Container0205a3d0;
struct Container0205a330;

void SetEntryByte14ByKey0205a42c(struct Container0205a3d0* c, int key, int val);
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
void IterateEntries0205a330(struct Container0205a330* c, int arg);

struct Elem02188870 {
    char unk0[4];
    unsigned short f4;
    unsigned short f6;
    char unk8[0x15 - 8];
    unsigned char f15;
};
struct Elem02188870* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);


extern "C" void func_0205ae8c(void* obj);

struct Obj02188870 {
    char pad0[0x730];
    void* f730;
    char pad1[0x738 - 0x734];
    void* f738;
    char pad2[0xb18 - 0x73c];
    unsigned int flags_b18;
    char pad3[0xb29 - 0xb1c];
    unsigned char b29;
};

// USA: func_ov008_02188870  (semantic: UpdateBattleScaleEntry_02188870)
extern "C" ARM void func_ov008_02188870(struct Obj02188870* obj) {
    if (obj->f730 == 0) return;
    if (!(obj->flags_b18 & 8)) return;
    if (!(obj->flags_b18 & 0x80000)) return;

    GameState* battle = GameState::GetInstance();
    int sum = GridCursor_GetSelectedIndex((struct Struct_0205bb84*)((char*)obj + 0x750));
    short val = (short)(((sum - obj->b29) << 4) + 7);

    SetEntryByte14ByKey0205a42c((struct Container0205a3d0*)obj->f738, 0, 0x3f);
    SetEntryFlag2ByKey0205a370((struct Container0205a3d0*)obj->f738, 0);

    struct Elem02188870* e = FindEntryByHalfword0205a3d0((struct Container0205a3d0*)obj->f738, 0);
    if (e != NULL) {
        e->f15 |= 8;
    }

    unsigned int count = battle->GetTickCount();
    IterateEntries0205a330((struct Container0205a330*)obj->f738, count);

    e = FindEntryByHalfword0205a3d0((struct Container0205a3d0*)obj->f738, 0);
    if (e != NULL) {
        e->f4 = 4;
        e->f6 = val;
    }

    func_0205ae8c(obj->f730);
}
