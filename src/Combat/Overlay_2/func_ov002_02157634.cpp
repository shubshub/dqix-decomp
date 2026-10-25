#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"



struct Struct_ov002_02157634_5;
struct Struct_ov002_02157634_6 {
    char unknown_0_[0xc];
    unsigned short unknown_c_;
};
struct Struct_ov002_02157634_7 {
    int unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 5;
    unsigned int unknown_9_1_ : 23;
    int unknown_c_;
    int unknown_10_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
};
struct Struct_ov002_02157634_8 {
    char* unknown_0_;
    int unknown_4_;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 2;
    unsigned int unknown_9_4_ : 20;
    int unknown_c_;
    int unknown_10_;
    unsigned int unknown_14_0_ : 28;
    unsigned int unknown_17_4_ : 4;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};
struct Struct_ov002_02157634_9 {
    unsigned char unknown_0_0_ : 1;
    unsigned char unknown_0_1_ : 7;
};
struct Struct_ov002_02157634_2 {
#if defined(jpn)
#define func_ov002_0216c42c func_ov002_0216ca7c
#endif

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
    char unknown1_0_[0x7ec];
    char unknown_7ec_[0xb4];
    char unknown_8a0_[0x1318];
#endif
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    char unknown_1bc4_[0x24];
    short unknown_1be8_;
    char unknown_1bea_[0x36];
    signed char unknown_1c20_;
    signed char unknown_1c21_;
    short unknown_1c22_;
    char unknown_1c24_[4];
    short unknown_1c28_;
    short unknown_1c2a_;
    char unknown_1c2c_[2];
    unsigned char unknown_1c2e_;
#if defined(jpn)
    char unknown_1af7_[0x41];
#else
    char unknown_1c2f_[0x45];
#endif
    int unknown_1c74_;
    char unknown_1c78_[2];
    unsigned char unknown_1c7a_;
    unsigned char unknown_1c7b_;
    char unknown_1c7c_[7];
    unsigned char unknown_1c83_;
    unsigned char unknown_1c84_;
    struct Struct_ov002_02157634_9 unknown_1c85_;
    char unknown_1c86_[0x40];
    unsigned char unknown_1cc6_;
    unsigned char unknown_1cc7_;
    char unknown_1cc8_[0x3c];
#if defined(jpn)
    char unknown_1bc8_[0x6dc];
#else
    char unknown_1d04_[0x770];
#endif
    struct Struct_ov002_02157634_6* unknown_2474_;
    char unknown_2478_[0x10];
    short unknown_2488_;
    unsigned char unknown_248a_;
};
struct Struct_ov002_02157634_3 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    unsigned char unknown_5_;
};
struct Struct_ov002_02157634_4 {
    short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
    signed char unknown_4_[4];
    struct Struct_ov002_02157634_3 unknown_8_[4];
    struct Struct_ov002_02157634_3 unknown_20_[4];
    int unknown_38_;
};

struct Element02157634* ItemTable_Find(struct ItemTable* c, int key);
void* SearchBothTables02079e2c(char* p, int key);
int IsIdInSpecialSet0201b868(void* p, int id);
void Something_021a6b9c(void* a, int b);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
unsigned char GameState_GetLeaderIndex(GameState* gs);
void* GameState_GetParty(GameState* gs);
unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);
void InitStateArray02157ce0(char* p);
void ClearStruct020a8170(struct Struct020a8170* p);
extern "C" void* __clear(void* dst, int count);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void* func_0202ae18(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_0202c540(void* p);
extern "C" int func_0202c508(void* p);
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
enum { Enum_ov002_02157634_6 = 7, Enum_ov002_02157634_7 = 8, Enum_ov002_02157634_20 = 0x15, Enum_ov002_02157634_38 = 0x29, Enum_ov002_02157634_43 = 0x2e };
#else
enum { Enum_ov002_02157634_6 = 6, Enum_ov002_02157634_7 = 7, Enum_ov002_02157634_20 = 0x14, Enum_ov002_02157634_38 = 0x26, Enum_ov002_02157634_43 = 0x2b };
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
        void* check = func_0202ae18();
        unsigned short* obj = (unsigned short*)Zone3D_GetInstance();
        unsigned short id = *obj;
        switch (e->id) {
        case 0x5612:
            if (func_0202c540(var7) != 0) {
                arg0->unknown_1c28_ = 0x797c;
                arg0->unknown_1c2a_ = -1;
                arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
                arg0->unknown_1bbc_ = 5;
                arg0->unknown_1c2e_ = 1;
                return;
            }
            break;
        case 0x56f0:
            if (func_0202c508(var7) != 0) {
                if (func_0201b868(var8, var9) != 0) {
                    func_ov017_021a6b9c(GetGameResources(), 1);
                    arg0->unknown_1c28_ = 0x7530;
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_1bbc_ = Enum_ov002_02157634_43;
                    var6 = Enum_ov002_02157634_38;
                } else {
                    arg0->unknown_1c28_ = 0x7530;
                    arg0->unknown_1c2a_ = -1;
                    arg0->unknown_1bbc_ = 5;
                    arg0->unknown_2488_ = 0x7531;
                    arg0->unknown_248a_ = 1;
                }
            } else {
                arg0->unknown_1c28_ = 0x7533;
                arg0->unknown_1c2a_ = -1;
                arg0->unknown_1bbc_ = 5;
                arg0->unknown_2488_ = 0x7534;
                arg0->unknown_248a_ = 1;
            }
            arg0->unknown_1bb8_ = var6;
            {
                unsigned char* bits = Scenario_GetInstance();
                Scenario_SetFlag(bits, bits + 0x8c, 0x1141, 1);
            }
            return;
        case 0x5603:
            ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
            arg0->unknown_2474_ = (struct Struct_ov002_02157634_6*)((SafeAllocator*)arg0->unknown_8a0_)->Allocate(0x10);
            func_020a8170(arg0->unknown_2474_);
            func_020a818c(arg0->unknown_2474_, arg0->unknown_8a0_);
            func_020a8304(arg0->unknown_2474_);
            if (arg0->unknown_2474_->unknown_c_ == 0) {
                arg0->unknown_1c2a_ = 0x7936;
                arg0->unknown_1c2a_ = -1;
                arg0->unknown_2488_ = 0x7919;
                arg0->unknown_248a_ = 1;
                arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
                arg0->unknown_1bbc_ = 5;
                ((SafeAllocator*)arg0->unknown_8a0_)->Reset();
                arg0->unknown_2474_ = 0;
            } else {
                arg0->unknown_1bb8_ = Enum_ov002_02157634_20;
                arg0->unknown_1bc0_ = 0;
            }
            return;
        case 0x56f1:
            arg0->unknown_1c28_ = 0x792c;
            arg0->unknown_1c2a_ = -1;
            arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
            arg0->unknown_1bbc_ = 5;
            {
                unsigned int var11 = func_ov017_021ab860(arg0->unknown_1c20_, 1);
                if (var11 <= 1) {
                    arg0->unknown_1c28_ = 0x7936;
                    arg0->unknown_248a_ = 1;
                    arg0->unknown_2488_ = 0x7919;
                } else if (var11 == 3) {
                    arg0->unknown_248a_ = 0;
                    arg0->unknown_2488_ = -1;
                    arg0->unknown_1bbc_ = Enum_ov002_02157634_43;
                    func_ov002_0215a7b4((char*)arg0, arg0->unknown_1c20_, arg0->unknown_1c22_, arg0->unknown_1be8_, 1);
                }
            }
            return;
        }
        {
            Struct_02108e10* var12 = func_020797dc();
            int var13 = var3->unknown_14_;
            if (var3->unknown_8_4_ == 0x1f) {
                var13 = 0xfc;
            }
            struct Struct_ov002_02157634_8* var14 = (struct Struct_ov002_02157634_8*)func_02079e2c((char*)var12, var13);
            if (var14 != 0) {
                if (var14->unknown_9_2_ & 1) {
                    arg0->unknown_1c85_.unknown_0_0_ = 1;
                }
                arg0->unknown_1c83_ = var14->unknown_18_5_;
                arg0->unknown_1c84_ = var14->unknown_17_4_;
            }
        }
        if (arg0->unknown_1c84_ == 2 || arg0->unknown_1c84_ == 7) {
            var6 = Enum_ov002_02157634_7;
        } else {
            p->target = GameState_GetLeaderIndex(gs);
            flag = 1;
        }
    } else if (arg0->unknown_1bb8_ == Enum_ov002_02157634_7) {
        var5 = 1;
    }
    if (var5) {
        int var15 = 0;
        signed char var16 = arg0->unknown_1c20_;
        signed char var17 = arg0->unknown_1c21_;
        int var18;
        if (var16 >= 0 && var16 <= 3) {
            var18 = 1;
        } else {
            var18 = 0;
        }
        if (!ok) {
            actor = GameState_GetLeaderIndex(gs);
        }
        ActionDataTables* tbl = GetData02108e10_020797dc();
        GameState_GetParty(gs);
        InitStateArray02157ce0((char*)&st);
        InitStateArray02157ce0((char*)&st);
        if (p->flags.on) {
            int key = e->key;
            if (e->kind == 0x1f) {
                key = 0xfc;
            }
            var0.unknown_0_ = var20;
            var0.unknown_2_ = var16;
            var0.unknown_3_ = 1;
            var0.unknown_4_[0] = var17;
            struct Struct_ov002_02157634_8* var21 = (struct Struct_ov002_02157634_8*)func_02079e2c((char*)var19, var20);
            if (var21 != 0) {
                func_ov016_0218b5c0(0, -1);
                if (var21->unknown_17_4_ == 3) {
                    __clear(var1, 4);
                    var0.unknown_3_ = func_020114ec((char*)var4, var1);
                    for (int var22 = 0; var22 < var0.unknown_3_; var22++) {
                        var0.unknown_4_[var22] = var1[var22];
                    }
                }
                func_ov002_021536e0(&var2);
                var2 = var19;
                var15 = func_ov002_021536ec(&var2, &var0, 0);
            }
            int var23 = 0;
            struct Struct_ov002_02157634_3* var24 = var0.unknown_8_;
            struct Struct_ov002_02157634_3* var25 = var0.unknown_20_;
            int var26;
            for (var26 = 0; var26 < var0.unknown_3_; var26++) {
                struct Struct_ov002_02157634_3* var27 = &var24[var26];
                struct Struct_ov002_02157634_3* var28;
                if (var27->unknown_4_ != 0 || (var28 = &var25[var26])->unknown_4_ != 0) {
                    var23 = 1;
                    break;
                }
            }
            if (var23) {
                func_ov002_0216c42c(arg0, &var0, var21);
                arg0->unknown_1cc6_ = 1;
                arg0->unknown_1cc7_ = 0;
                func_ov002_02157ce0(arg0->unknown_1cc8_);
                memcpy(arg0->unknown_1cc8_, &var0, 0x3c);
                arg0->unknown_1c28_ = -1;
                arg0->unknown_1c2a_ = -1;
                arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
                arg0->unknown_1bbc_ = Enum_ov002_02157634_38;
                arg0->unknown_2488_ = -1;
                arg0->unknown_248a_ = 0;
                arg0->unknown_1c7a_ = 1;
                arg0->unknown_1c7b_ = 0x14;
                arg0->unknown_1c74_ = 0x1e;
                arg0->unknown_1bc0_ = 0;
                return;
            }
            if (var15 != 0) {
                func_ov002_0215a7b4((char*)arg0, arg0->unknown_1c20_, arg0->unknown_1c22_, arg0->unknown_1be8_, 1);
            }
        }
        func_ov002_02159900((char*)arg0, (char*)&var0, var15);
        if (var0.unknown_38_ != 0) {
            arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
            arg0->unknown_1bbc_ = Enum_ov002_02157634_43;
            return;
        }
        arg0->unknown_1bb8_ = Enum_ov002_02157634_38;
        arg0->unknown_1bbc_ = 5;
    }
    arg0->unknown_1bb8_ = var6;
}
