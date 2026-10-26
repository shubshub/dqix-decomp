#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_02161e30;
struct PartyState;
struct Container_021dae60;
struct SearchStruct;
struct S_10088;
struct Struct_ov026_021dc8fc_4;

struct Struct_ov026_021d8ba0_6 {
    char pad0[0x1c];
    signed char state;
};

struct Struct_ov026_021dd3dc_2 {
    char pad0[0x14];
    unsigned int flags;
};

struct CombatantView {
    char pad0[0x138];
    Struct_ov026_021dd3dc_2* status;
};

struct Struct_ov026_021de6cc {
    short v[4];
};

struct Struct_ov026_021dd3dc {
    char data[0x48];
};

struct Struct_ov000_021643d4_3 {
    char data[0x68];
    Struct_ov026_021dd3dc sub;
};

extern "C" const Struct_ov026_021de6cc data_ov026_021de6cc;
extern "C" const Struct_ov026_021de6cc data_ov026_021de6d4;

extern "C" SearchStruct* LinkSession_GetInstance();
extern "C" int func_ov000_0215fc60(char*);
extern "C" int LinkSession_IsActive(int*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Container_021dae60*, int);
extern "C" int LinkSession_IsSlotMember(SearchStruct*, int);
extern "C" int func_020546a8(void*);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov026_021dce1c(Struct_ov026_021dc8fc_4*);
extern "C" int func_020882f8(unsigned char*);
extern "C" int func_ov000_0215f7a8(Struct_ov000_02161e30*, short*, unsigned char);
extern "C" int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
extern "C" void func_020ac4c0(void*);
extern "C" void func_020a0780(struct Struct_020a0780*, unsigned int);
extern "C" void func_020a0068(struct Struct_020a0068*, unsigned int);
extern "C" void func_020a07b0(struct Struct_020a07b0*, unsigned int);
extern "C" void func_020a00a4(struct Struct_020a00a4*, unsigned int);
extern "C" void func_020ac494(void*);

// USA: func_ov026_021dd3dc
extern "C" ARM int func_ov026_021dd3dc(Struct_ov000_02161e30* battle, PartyState* party, Container_021dae60* list) {
    Struct_ov026_021de6cc var0;
    Struct_ov026_021de6cc var1;
    short var2[4];
    int var3[4];
    Struct_ov000_021643d4_3 blk;
    GameState* gs = GameState::GetInstance();
    SearchStruct* link = LinkSession_GetInstance();
    int i;
    int result;
    int count = 0;
    if (func_ov000_0215fc60((char*)battle) != 0) {
        return 1;
    }
    if (LinkSession_IsActive((int*)link) == 0 || func_020a35e0((unsigned char*)party, count)) {
        result = 0;
        for (i = 0; i < 4; i++) {
            if (!func_020a35e0((unsigned char*)party, i)) continue;
            if (i != 0 && !func_0200ff58(gs, i)) continue;
            Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60(list, i);
            if (!slot) continue;
            if (slot->state == 6) {
                result = 1;
                break;
            }
        }
        if (result == 0) {
            for (i = 0; i < 4; i++) {
                if (!func_020a35e0((unsigned char*)party, i)) continue;
                if (i != 0 && !func_0200ff58(gs, i)) continue;
                GameObject* c = gs->GetCombatantByIndex(i);
                if (!c) continue;
                if ((((CombatantView*)c)->status->flags & 0x80019) == 0) {
                    result = 2;
                    break;
                }
            }
        }
        var3[count] = result;
        count++;
    }
    if (LinkSession_IsActive((int*)link)) {
        for (i = 1; i < 4; i++) {
            if (!func_020a35e0((unsigned char*)party, i)) continue;
            if (func_0200ff58(gs, i)) continue;
            GameObject* c = gs->GetCombatantByIndex(i);
            if (!c) continue;
            Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60(list, i);
            if (!slot) continue;
            int r = 0;
            if (slot->state == 6) {
                r = 1;
            } else if ((((CombatantView*)c)->status->flags & 0x80019) == 0) {
                r = 2;
            }
            var3[count] = r;
            count++;
        }
    }
    int any = 0;
    for (int j = 0; j < count; j++) {
        if (var3[j] == 1) any = 1;
    }
    if (any) {
        for (int j = 0; j < count; j++) {
            if (var3[j] == 2) return 4;
        }
    }
    result = 1;
    for (int j = 0; j < count; j++) {
        if (var3[j] == 1) {
            var0 = data_ov026_021de6cc;
            int n = 0;
            int k;
            for (k = 0; k < 4; k++) {
                if (!func_020a35e0((unsigned char*)party, k)) continue;
                if (LinkSession_IsSlotMember(link, k)) {
                    var0.v[n] = k;
                    n++;
                }
            }
            for (k = 0; k < 4; k++) {
                if (!func_020a35e0((unsigned char*)party, k)) continue;
                GameObject* m = func_0200ff58(gs, k);
                if (!m) continue;
                if (LinkSession_IsSlotMember(link, func_020546a8(m))) {
                    var0.v[n] = k;
                    n++;
                }
            }
            var1 = data_ov026_021de6d4;
            int x;
            int var23 = 0;
            for (x = 0; x < n; x++) {
                short id = var0.v[x];
                GameObject* c = gs->GetCombatantByIndex(id);
                if (!c) continue;
                if (func_02010088((S_10088*)c)) continue;
                if (func_ov026_021dce1c((Struct_ov026_021dc8fc_4*)c)) continue;
                if (func_020882f8((unsigned char*)((CombatantView*)c)->status)) continue;
                if ((((CombatantView*)c)->status->flags & 0x80000) == 0) {
                    var1.v[var23] = id;
                    var23++;
                }
            }
            if (func_ov000_0215f7a8(battle, var1.v, var23)) {
                result = 2;
            } else {
                result = 3;
            }
            break;
        }
    }
    if (result != 1) {
        func_020ac4c0(&blk);
        Struct_ov026_021dd3dc* sub = &blk.sub;
        func_020a0780((Struct_020a0780*)&blk, 1);
        func_020a0068((Struct_020a0068*)sub, 1);
        if (result == 2) {
            int n = func_ov000_0215e9fc(battle, var2, 4, 0);
            int found = 0;
            for (int j = 0; j < n; j++) {
                GameObject* c = gs->GetCombatantByIndex(var2[j]);
                if (!c) continue;
                if (func_02010088((S_10088*)c)) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                func_020a07b0((Struct_020a07b0*)&blk, 1);
                func_020a00a4((Struct_020a00a4*)sub, 1);
            }
        }
        func_020ac494(&blk);
    }
    return result;
}
