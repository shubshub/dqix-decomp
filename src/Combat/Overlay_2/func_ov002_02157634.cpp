#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"




struct ItemTable;
struct Struct020a8170 {
    char pad[0xc];
    unsigned short count;
};
struct Element02157634 {
    int unk0;
    int unk4;
    unsigned int lo4 : 4;
    unsigned int kind : 5;
    unsigned int rest : 23;
    int unkc;
    int unk10;
    short key;
    short pad16;
    short id;
};
struct TableEntry {
    char* name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
    int unkc;
    int unk10;
    unsigned int lo28 : 28;
    unsigned int type : 4;
    unsigned int lo5 : 5;
    unsigned int group : 7;
    unsigned int rest18 : 20;
};
struct MenuFlags {
    unsigned char on : 1;
    unsigned char rest : 7;
};
struct BattleMenu {
#if defined(jpn)
    char pad0[0x750];
    char container7ec[0xb4];
    char alloc8a0[0x127c];
#else
    char pad0[0x7ec];
    char container7ec[0xb4];
    char alloc8a0[0x1318];
#endif
    int state;
    int nextState;
    int timer;
    char pad1bc4[0x24];
    short f1be8;
    char pad1bea[0x36];
    signed char actor;
    signed char target;
    short command;
    char pad1c24[4];
    short msgId;
    short msgId2;
    char pad1c2c[2];
    unsigned char f1c2e;
#if defined(jpn)
    char pad1c2f[0x41];
#else
    char pad1c2f[0x45];
#endif
    int wait;
    char pad1c78[2];
    unsigned char waitMode;
    unsigned char waitKind;
    char pad1c7c[7];
    unsigned char group;
    unsigned char type;
    struct MenuFlags flags;
    char pad1c86[0x40];
    unsigned char cc6;
    unsigned char cc7;
    char stateArray[0x3c];
#if defined(jpn)
    char pad1d04[0x6dc];
#else
    char pad1d04[0x770];
#endif
    struct Struct020a8170* anim;
    char pad2478[0x10];
    short prompt;
    unsigned char showPrompt;
};
struct StateSlot {
    unsigned char a[4];
    unsigned char active;
    unsigned char pad;
};
struct StateArray {
    short id;
    signed char actor;
    unsigned char count;
    signed char ids[4];
    struct StateSlot first[4];
    struct StateSlot second[4];
    int tail;
};

extern "C" struct Element02157634* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void* func_02079e2c(char* p, int key);
extern "C" int func_0201b868(void* p, int id);
extern "C" void func_ov017_021a6b9c(void* a, int b);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* gs);
extern "C" void* GameState_GetParty(GameState* gs);
extern "C" unsigned char GameState_GetPartyOrder(char* obj, void* dst);
extern "C" void func_ov002_02157ce0(char* p);
extern "C" void func_020a8170(struct Struct020a8170* p);
extern "C" void* __clear(void* dst, int count);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsGuest(void* p);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" unsigned char* Scenario_GetInstance(void);
extern "C" void func_020a818c(void* p, void* allocator);
extern "C" void func_020a8304(void* p);
extern "C" int func_ov017_021ab860(signed char a, int b);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov002_021536e0(void* p);
extern "C" int func_ov002_021536ec(void* a, void* b, int c);
extern "C" void func_ov002_0215a7b4(char* self, int type, int key, int extra, unsigned char flag);
extern "C" void func_ov002_0216c42c(void* ctx, void* buf, void* entry);
extern "C" void func_ov002_02159900(char* base, char* arr, int any);

#if defined(jpn)
enum { regionalState6 = 7, regionalState7 = 8, regionalState14 = 0x15, regionalState26 = 0x29, regionalState2b = 0x2e };
#else
enum { regionalState6 = 6, regionalState7 = 7, regionalState14 = 0x14, regionalState26 = 0x26, regionalState2b = 0x2b };
#endif

// USA: func_ov002_02157634
extern "C" ARM void func_ov002_02157634(struct BattleMenu* p) {
    struct StateArray st;
    unsigned char buf[4];
    void* ctx;
    struct Element02157634* e = ItemTable_Find((struct ItemTable*)p->container7ec, p->command);
    if (e == 0) {
        return;
    }
    GameState* gs = GameState::GetInstance();
    p->nextState = p->state;
    p->timer = 0;
    int flag = 0;
    int next = regionalState26;
    if (p->state == regionalState6) {
        void* check = LinkSession_GetInstance();
        unsigned short* obj = (unsigned short*)Zone3D_GetInstance();
        unsigned short id = *obj;
        switch (e->id) {
        case 0x5612:
            if (LinkSession_IsGuest(check) != 0) {
                p->msgId = 0x797c;
                p->msgId2 = -1;
                p->state = regionalState26;
                p->nextState = 5;
                p->f1c2e = 1;
                return;
            }
            break;
        case 0x56f0:
            if (LinkSession_IsHostOrSolo(check) != 0) {
                if (func_0201b868(obj, id) != 0) {
                    func_ov017_021a6b9c(GetGameResources(), 1);
                    p->msgId = 0x7530;
                    p->msgId2 = -1;
                    p->nextState = regionalState2b;
                    next = regionalState26;
                } else {
                    p->msgId = 0x7530;
                    p->msgId2 = -1;
                    p->nextState = 5;
                    p->prompt = 0x7531;
                    p->showPrompt = 1;
                }
            } else {
                p->msgId = 0x7533;
                p->msgId2 = -1;
                p->nextState = 5;
                p->prompt = 0x7534;
                p->showPrompt = 1;
            }
            p->state = next;
            {
                unsigned char* bits = Scenario_GetInstance();
                Scenario_SetFlag(bits, bits + 0x8c, 0x1141, 1);
            }
            return;
        case 0x5603:
            ((SafeAllocator*)p->alloc8a0)->Reset();
            p->anim = (struct Struct020a8170*)((SafeAllocator*)p->alloc8a0)->Allocate(0x10);
            func_020a8170(p->anim);
            func_020a818c(p->anim, p->alloc8a0);
            func_020a8304(p->anim);
            if (p->anim->count == 0) {
                p->msgId2 = 0x7936;
                p->msgId2 = -1;
                p->prompt = 0x7919;
                p->showPrompt = 1;
                p->state = regionalState26;
                p->nextState = 5;
                ((SafeAllocator*)p->alloc8a0)->Reset();
                p->anim = 0;
            } else {
                p->state = regionalState14;
                p->timer = 0;
            }
            return;
        case 0x56f1:
            p->msgId = 0x792c;
            p->msgId2 = -1;
            p->state = regionalState26;
            p->nextState = 5;
            {
                unsigned int r = func_ov017_021ab860(p->actor, 1);
                if (r <= 1) {
                    p->msgId = 0x7936;
                    p->showPrompt = 1;
                    p->prompt = 0x7919;
                } else if (r == 3) {
                    p->showPrompt = 0;
                    p->prompt = -1;
                    p->nextState = regionalState2b;
                    func_ov002_0215a7b4((char*)p, p->actor, p->command, p->f1be8, 1);
                }
            }
            return;
        }
        {
            ActionDataTables* tbl = func_020797dc();
            int key = e->key;
            if (e->kind == 0x1f) {
                key = 0xfc;
            }
            struct TableEntry* entry = (struct TableEntry*)func_02079e2c((char*)tbl, key);
            if (entry != 0) {
                if (entry->b10 & 1) {
                    p->flags.on = 1;
                }
                p->group = entry->group;
                p->type = entry->type;
            }
        }
        if (p->type == 2 || p->type == 7) {
            next = regionalState7;
        } else {
            p->target = GameState_GetLeaderIndex(gs);
            flag = 1;
        }
    } else if (p->state == regionalState7) {
        flag = 1;
    }
    if (flag) {
        int res = 0;
        signed char actor = p->actor;
        signed char target = p->target;
        int ok;
        if (actor >= 0 && actor <= 3) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (!ok) {
            actor = GameState_GetLeaderIndex(gs);
        }
        ActionDataTables* tbl = func_020797dc();
        GameState_GetParty(gs);
        func_ov002_02157ce0((char*)&st);
        func_ov002_02157ce0((char*)&st);
        if (p->flags.on) {
            int key = e->key;
            if (e->kind == 0x1f) {
                key = 0xfc;
            }
            st.id = key;
            st.actor = actor;
            st.count = 1;
            st.ids[0] = target;
            struct TableEntry* entry = (struct TableEntry*)func_02079e2c((char*)tbl, key);
            if (entry != 0) {
                func_ov016_0218b5c0(0, -1);
                if (entry->type == 3) {
                    __clear(buf, 4);
                    st.count = GameState_GetPartyOrder((char*)gs, buf);
                    for (int i = 0; i < st.count; i++) {
                        st.ids[i] = buf[i];
                    }
                }
                func_ov002_021536e0(&ctx);
                ctx = tbl;
                res = func_ov002_021536ec(&ctx, &st, 0);
            }
            int found = 0;
            struct StateSlot* first = st.first;
            struct StateSlot* second = st.second;
            int i;
            for (i = 0; i < st.count; i++) {
                struct StateSlot* a = &first[i];
                struct StateSlot* b;
                if (a->active != 0 || (b = &second[i])->active != 0) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                func_ov002_0216c42c(p, &st, entry);
                p->cc6 = 1;
                p->cc7 = 0;
                func_ov002_02157ce0(p->stateArray);
                memcpy(p->stateArray, &st, 0x3c);
                p->msgId = -1;
                p->msgId2 = -1;
                p->state = regionalState26;
                p->nextState = regionalState26;
                p->prompt = -1;
                p->showPrompt = 0;
                p->waitMode = 1;
                p->waitKind = 0x14;
                p->wait = 0x1e;
                p->timer = 0;
                return;
            }
            if (res != 0) {
                func_ov002_0215a7b4((char*)p, p->actor, p->command, p->f1be8, 1);
            }
        }
        func_ov002_02159900((char*)p, (char*)&st, res);
        if (st.tail != 0) {
            p->state = regionalState26;
            p->nextState = regionalState2b;
            return;
        }
        p->state = regionalState26;
        p->nextState = 5;
    }
    p->state = next;
}
