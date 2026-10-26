#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021cff8c {
    int id;
    unsigned char idx;
    unsigned char count;
    short arr[4];
};

struct Struct_ov017_021cff8c_2 {
    unsigned char tag;
    unsigned char pad0[3];
    struct Struct_ov017_021cff8c sub;
};

// USA: func_ov017_021cff8c
extern "C" ARM void func_ov017_021cff8c(int id, int arg1) {
    void* mgr = LinkMessageQueue_GetInstance();
    GameState* battle = GameState::GetInstance();
    unsigned char* list = (unsigned char*)GameState_GetParty(battle);

    int found = 0;
    if (arg1) {
        found = 1;
    } else {
        int i;
        for (i = 0; i < list[0xf7c]; i++) {
            unsigned char* row = list + i;
            if (id == row[0xf78]) { found = 1; break; }
        }
    }
    if (!found) return;

    GameObject* c = func_0200ff1c(battle, id);
    if (!c) return;

    int field150 = func_02053c6c((unsigned char*)c);
    if (!field150) return;

    short* src = (short*)(field150 + 0x454);

    struct Struct_ov017_021cff8c_2 buf;
    struct Struct_ov017_021cff8c* var10 = &buf.sub;
    buf.tag = 0xa8;
    var10->id = id;
    var10->count = 4;
    var10->idx = 0;
    int i;
    for (i = 0; i < var10->count; i++) {
        var10->arr[i] = src[var10->idx + i];
    }
    func_0205e330(mgr, &buf, 0);

    unsigned char var12 = var10->count;
    int j = 0;
    var10->idx = var12;
    for (; j < var10->count; j++) {
        var10->arr[j] = src[var10->idx + j];
    }
    func_0205e330(mgr, &buf, 0);
}
