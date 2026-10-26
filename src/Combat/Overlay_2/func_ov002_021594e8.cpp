#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct SePlayer;
struct Struct_02048350_2;
extern "C" void *func_02079e2c(char *p, int key);
extern "C" GameObject *func_0200ff94(GameState *gs, int id);
extern "C" int *LinkSession_GetInstance(void);
extern "C" void *__clear(void *dst, int count);
extern "C" int GameState_GetPartyOrder(char *dst, void *src);
extern "C" void func_02048350(struct Struct_02048350_2 *p, int a);
extern "C" int LinkSession_IsActive(int *p);
extern "C" void SePlayer_Play(struct SePlayer *p, int a, int b);
extern "C" void func_ov002_02157ce0(char *p);
extern "C" void func_ov002_021536e0(void *p);
extern "C" int func_ov002_021536ec(void *a, void *b, int c);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_021c9e00(signed char a, int b, int c, int d);
extern "C" int g_sePlayer;

struct Struct_ov002_021594e8_3 {
    char *name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct Struct_01ff91ac_26 {
    unsigned char a[4];
    unsigned char active;
    unsigned char pad;
};
struct Struct_ov002_021594e8 {
    short id;
    signed char actor;
    unsigned char count;
    signed char ids[4];
    struct Struct_01ff91ac_26 first[4];
    struct Struct_01ff91ac_26 second[4];
    int tail;
};
struct Struct_ov002_021594e8_2 {
#if defined(jpn)
    char pad0[0x1a80];
    int state;
    int nextState;
    char unknown_1a88_[0x1aee - 0x1a88];
#else
    char pad0[0x1bb8];
    int state;
    int nextState;
    char unknown_1bc0_[0x1c26 - 0x1bc0];
#endif
    short command;
    short msgId;
    short msgId2;
};

// USA: func_ov002_021594e8
extern "C" ARM void func_ov002_021594e8(struct Struct_ov002_021594e8_2 *p, short cmd, signed char actor, int target) {
    struct Struct_ov002_021594e8 st;
    struct Struct_ov002_021594e8 var1;
    unsigned char buf[4];
    void *ctx;
    void *ctx2;

    p->command                        = cmd;
    GameState *gs                     = GameState::GetInstance();
    ActionDataTables* tbl                         = func_020797dc();
    struct Struct_ov002_021594e8_3 *var7 = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)tbl, p->command);
    GameObject *comb                  = func_0200ff94(gs, actor);
    int *checkPtr                     = LinkSession_GetInstance();
    int flagA                         = 0;
    if (p->state == RG(0x17, 0x18)) {
        p->msgId  = 0x232d;
        p->msgId2 = 0x232b;
        int res   = 0;
        if (p->command == 0x22) {
            func_ov002_02157ce0((char *) &st);
            func_ov002_02157ce0((char *) &st);
            struct Struct_ov002_021594e8_3 *entry = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)tbl, p->command);
            if (entry != NULL) {
                __clear(buf, 4);
                int n = GameState_GetPartyOrder((char *) gs, buf);
                if (entry->b10 & 1) {
                    st.id    = p->command;
                    st.actor = actor;
                    st.count = n;
                    for (int i = 0; i < n; i++) {
                        st.ids[i] = buf[i];
                    }
                    func_ov002_021536e0(&ctx);
                    ctx = tbl;
                    res = func_ov002_021536ec(&ctx, &st, 0);
                }
            }
        } else {
            struct Struct_ov002_021594e8_3 *entry = (struct Struct_ov002_021594e8_3 *) func_02079e2c((char*)tbl, p->command);
            if (entry != NULL && (entry->b10 & 1)) {
                func_ov016_0218b5c0(res, -1);
                func_ov002_02157ce0((char *) &var1);
                func_ov002_02157ce0((char *) &var1);
                var1.id     = p->command;
                var1.actor  = actor;
                var1.count  = 1;
                var1.ids[0] = target;
                func_ov002_021536e0(&ctx2);
                ctx2 = tbl;
                res  = func_ov002_021536ec(&ctx2, &var1, res);
            }
        }
        if (res != 0) {
            if (p->command == 0x1f || p->command == 0x1e || p->command == 0x20 || p->command == 0x21) {
                p->msgId2 = 0x2339;
                flagA     = 1;
            } else if (p->command == 0x23) {
                p->msgId2 = 0x794c;
                flagA     = 1;
            } else if (p->command == 0x22) {
                p->msgId2 = 0x2339;
                flagA     = 1;
            }
        }
        SePlayer_Play((struct SePlayer *) &g_sePlayer, 0x64, 0);
        p->state     = RG(0x26, 0x29);
        p->nextState = RG(0x17, 0x18);
    }
    if (flagA != 0) {
        func_02048350((struct Struct_02048350_2 *) comb, var7->lo8);
        if (LinkSession_IsActive(checkPtr) != 0) {
            func_ov017_021c9e00(actor, 0, 0, 1);
        }
    }
}
