#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov017_021cf078_2128 = 0x7b8 };
#else
enum { Enum_ov017_021cf078_2128 = 0x850 };
#endif

extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cf078 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

struct Struct_ov017_021cf078_2 {
    Struct_ov017_021cf078 items[3];
};

struct Struct_ov017_021cf078_3 {
    unsigned int lo : 8;
    unsigned int unknown_1_0_ : 3;
    unsigned int hi : 1;
    unsigned int rest : 20;
};

struct Struct_ov017_021cf078_4 {
    unsigned char tag;
    unsigned char pad0[3];
    struct {
        Struct_ov017_021cf078 items[3];
        Struct_ov017_021cf078_3 unknown_c_;
    } data;
};

// USA: func_ov017_021cf078
extern "C" ARM void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag) {
    void* p = LinkMessageQueue_GetInstance();
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, combatantId);
    if (!combatant) return;

    int var3 = func_02053c6c((unsigned char*)combatant);
    if (!var3) return;

    Struct_ov017_021cf078_2* arr = (Struct_ov017_021cf078_2*)((char*)var3 + Enum_ov017_021cf078_2128);
    Struct_ov017_021cf078_2* src = &arr[slot];

    Struct_ov017_021cf078_4 buf;
    buf.tag = 0x15;
    Struct_ov017_021cf078* dst = buf.data.items;
    dst[0].a = src->items[0].a;
    dst[0].b = src->items[0].b;
    dst[0].c = src->items[0].c;
    dst[1].a = src->items[1].a;
    dst[1].b = src->items[1].b;
    dst[1].c = src->items[1].c;
    dst[2].a = src->items[2].a;
    dst[2].b = src->items[2].b;
    dst[2].c = src->items[2].c;
    Struct_ov017_021cf078_3* var8 = (Struct_ov017_021cf078_3*)(dst + 3);
    var8->lo = slot;
    var8->unknown_1_0_ = combatantId;
    var8->hi = flag;

    func_0205e330(p, &buf, 0);
}
