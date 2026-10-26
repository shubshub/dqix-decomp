#include <globaldefs.h>

#include "GameState/GameState.h"

struct SearchStruct;

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void);
extern "C" int LinkSession_IsSlotLost(struct SearchStruct* obj, int value);
extern "C" void func_0207dcf0(int a);
extern "C" int memcmp(void* a, void* b, int c);
extern "C" void func_ov017_021c9c64(int a, int b);

struct Struct_0207d798 {
    unsigned short h0;
    short pad2;
    signed char unknown_4_;
    char pad5;
    unsigned short h6;
    signed char arr8[4];
};
extern "C" void func_0207d7c0(struct Struct_0207d798* o);

extern int data_020e8a4c;

// USA: func_0207dba8
extern "C" ARM void func_0207dba8(struct Struct_0207d798* list) {
    GameState* g = GameState::GetInstance();
    struct Struct_0207d798* e = list;
    int i = 0;
    int var3 = i;
    int var4 = 1;
    int var5 = i;
    int var6 = -1;
    for (; i < 4; i++, e++) {
        unsigned short h0 = e->h0;
        if (h0 != 0 && e->unknown_4_ < 0) {
            if (e->h6 < 0x3e8) {
                e->h6 = e->h6 + g->GetEffectiveDeltaTime();
            } else {
                int found = (memcmp(e->arr8, &data_020e8a4c, 4) == 0);
                if (found) {
                    func_ov017_021c9c64(h0, 0);
                    func_0207d7c0(e);
                }
            }
        } else {
            e->h6 = (unsigned short)var3;
        }
    }
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    if (LinkSession_IsHostOrSolo() == 0) return;
    int j;
    for (j = var4; j < 4; j++) {
        if (!LinkSession_IsSlotLost(search, j)) continue;
        struct Struct_0207d798* p = list;
        int k;
        for (k = var5; k < 4; p++, k++) {
            signed char* a = p->arr8;
            if (p->h0 == 0) continue;
            if (a[j] != var6) continue;
            a[j] = (signed char)var5;
            func_0207dcf0(p->h0);
        }
    }
}
