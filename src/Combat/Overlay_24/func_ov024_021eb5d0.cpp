#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#if defined(jpn)
#define WORK_STRIDE_021eb5d0 0x488
#else
#define WORK_STRIDE_021eb5d0 0x448
#endif
#include "Combat/Overlay_0/GetCombatantByID.h"
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};

struct Struct_ov024_021eb5d0_15 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov024_021eb5d0_17 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Struct_ov024_021eb5d0_18 {
    unsigned int unknown_0_0_ : 8;
    unsigned int pair : 2;
    unsigned int unknown_1_2_ : 4;
    unsigned int elem : 8;
    unsigned int unknown_2_6_ : 6;
    unsigned int unknown_3_4_ : 1;
    unsigned int unknown_3_5_ : 3;
};

struct Struct_ov024_021eb5d0 {
    unsigned int unknown_0_0_ : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Struct_ov024_021eb5d0_2 {
    unsigned int unknown_0_0_ : 19;
    unsigned int group : 5;
    unsigned int rest : 8;
};

struct Struct_ov024_021eb5d0_3 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021eb5d0_4 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 7;
    unsigned int hi : 5;
};

struct Struct_ov024_021eaa50_2 {
    char pad0[4];
    struct Struct_ov024_021eb5d0_17 f4;
    struct Struct_ov024_021eb5d0_18 f8;
    char pad1[4];
    unsigned int f10;
    char pad2[4];
    struct Struct_ov024_021eb5d0 f18;
    struct Struct_ov024_021eb5d0_2 f1c;
    char pad3[8];
    struct Struct_ov024_021eb5d0_3 f28;
    struct Struct_ov024_021eb5d0_4 unknown_2c_;
};

struct Struct_ov024_021eb5d0_5 {
    char pad0[0xe];
    short unknown_e_;
    unsigned short f10;
    char pad1[5];
    unsigned char unknown_17_;
    char pad2[4];
    struct Struct_ov024_021eb5d0_15 f1c;
    unsigned char unknown_1d_;
    char pad3[2];
    int f20;
};

struct Struct_ov024_021eb5d0_6 {
    unsigned long long flags;
    void* f8;
    char pad0[0x13];
    unsigned char unknown_1f_;
};

struct Struct_ov024_021eb5d0_7 {
    char pad0[0x18];
    float f18;
    short f1c;
    short unknown_1e_;
    short f20;
    unsigned short f22;
    unsigned short f24;
};

struct Struct_ov024_021eb5d0_8 {
    char pad0[0x10];
    unsigned short f10;
};

struct Struct_ov024_021eb5d0_9 {
    short f0;
    unsigned short f2;
    char pad0[4];
    unsigned char f8;
    char pad1;
    unsigned char fa;
    struct Struct_ov024_021eb5d0_15 fb;
    struct Struct_ov024_021eb5d0_15 fc;
    char pad2[3];
    struct Struct_ov024_021eb5d0_7* f10;
    char pad3[4];
    unsigned short f18;
    char pad4[8];
    unsigned short f22;
    unsigned short f24;
};

struct Struct_ov024_021eaa50 {
    short f0;
    unsigned short f2;
    char pad0[5];
    unsigned char unknown_9_;
};

struct Struct_ov024_021ea4d0 {
    int f0;
    struct Struct_ov024_021eb5d0_9* f4;
    struct Struct_ov024_021eb5d0_7* f8;
    struct Struct_ov024_021eb5d0_5* fc;
    struct Struct_ov024_021eb5d0_10* f10;
    int f14;
    int f18;
    float f1c;
    unsigned char f20[8];
    unsigned char f28[0x10];
    unsigned char unknown_38_[4];
    unsigned char f3c[8];
    short unknown_44_;
    char pad0;
    unsigned char f47;
    char pad1[0x20];
    struct Struct_ov024_021eb5d0_6* f68;
    unsigned char f6c;
    unsigned char unknown_6d_;
    unsigned char unknown_6e_;
    unsigned char unknown_6f_;
    unsigned char unknown_70_;
    unsigned char unknown_71_;
    unsigned char unknown_72_;
    unsigned char unknown_73_;
    unsigned char unknown_74_;
    unsigned char unknown_75_;
    unsigned char unknown_76_;
    unsigned char unknown_77_;
    unsigned char unknown_78_;
    unsigned char unknown_79_;
};

struct Struct_ov024_021eb5d0_6;
typedef struct Struct_ov024_021eb5d0_6* (Struct_ov024_021ea4d0::*Type_02000c9c_6)(short a, short b, struct Struct_ov024_021eaa50_2* rec, int dmg, int* flags, int cnt);

struct Struct_ov024_021eb5d0_11 {
    unsigned short f0;
    unsigned short f2;
    char pad0[0x10];
    unsigned int f14;
    char pad1[0xa];
    unsigned short f22;
    char pad2[0x17];
    struct Struct_ov024_021eb5d0_15 unknown_3b_;
    struct Struct_ov024_021eb5d0_15 f3c;
};

struct Struct_ov024_021eb5d0_12 {
    char pad0[0x138];
    struct Struct_ov024_021eb5d0_11* unknown_138_;

#if defined(jpn)
    char pad1[8];
#else
    char pad1[0x14];
#endif
    unsigned char* f150;
};

struct Struct_ov024_021eb5d0_10 {
    char pad0[0x8e01];
    unsigned char unknown_8e01_;
    unsigned char unknown_8e02_;
    char pad1;
    short unknown_8e04_;
    signed char unknown_8e06_;
    char pad2[0x31];
    int unknown_8e38_;
    float unknown_8e3c_;
    float unknown_8e40_;
    char pad3[0x10];
    short unknown_8e54_;
    char pad4[0x18];
    unsigned short unknown_8e6e_;
    char pad5[0x24];
    unsigned char unknown_8e94_;
};

struct Struct_02000c9c_78 {
    unsigned char f0;
    char pad0;
    short f2;
    short f4;
    short unknown_6_;
};

struct Struct_ov024_021eb5d0_13 {
    int f0;
    int f4;
};

struct Struct_ov024_021eb5d0_14 {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int rest : 30;
};

struct Struct_ov024_021eb5d0_16 {
    char pad0[0x22];
    signed char f22;
};

#define IN_RANGE_021eb5d0(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

extern "C" Type_02000c9c_6 data_ov024_021ff508[0x51];
extern "C" Type_02000c9c_6 __ptmf_null;
extern "C" int data_ov024_02200144;
struct Struct_ov024_021fe718 {
    short v[8];
};
extern "C" struct Struct_ov024_021fe718 data_ov024_021fe718;
extern "C" float data_ov024_021fe738[4];
extern "C" struct Struct_ov024_021fe718 data_ov024_021fe788;
struct Struct_ov024_021fe8f0 {
    short v[32];
};
extern "C" struct Struct_ov024_021fe8f0 data_ov024_021fe8f0;

extern "C" struct Struct_ov024_021eaa50_2* func_02079e2c(char*, int);
extern "C" void* func_02079ee0(void* table, int key);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int func_ov000_021540c8(void*, void*, int);
extern "C" int func_ov000_0215440c(void* world, void* src, void* out);
extern "C" int func_ov024_021eaa50(struct Struct_ov024_021ea4d0* self, struct Struct_ov024_021eaa50* src, struct Struct_ov024_021eaa50_2* rec, int arg3);
extern "C" short func_ov000_0215cda0(void* world);
extern "C" int func_ov024_021e8dc0(struct Struct_ov024_021ea4d0* self, int id, struct Struct_ov024_021eaa50_2* rec, short* list, int count);
extern "C" int GameObject_GetPartyMemberLevel(void* p);
struct Random;
float NextRandomFloatScaled(Random*, float, float, int);
int NextRandomMax(Random*, int);
struct GameObject;
extern "C" int func_ov024_021eadfc(GameObject*);
extern "C" int func_ov000_0215a124(void* world, int id, int amount);
extern "C" int func_02083b00(unsigned char* arr, int bit);
extern "C" unsigned int func_020dd290(void* obj, unsigned int v);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" int func_ov024_021eb47c(Struct_ov024_021ea4d0*, int);
extern "C" void func_020ac4c0(void* p);
struct Struct_020a0530;
extern "C" void func_020a0530(Struct_020a0530*, unsigned int);
struct Struct_020a01b8;
extern "C" void func_020a01b8(Struct_020a01b8*, unsigned int);
extern "C" void func_020ac494(void* p);
extern "C" int func_ov000_02159c58(void* world, int v);
struct Struct_020a0674;
extern "C" void func_020a0674(Struct_020a0674*, unsigned int);
struct Struct_020a017c;
extern "C" void func_020a017c(Struct_020a017c*, unsigned int);
struct Struct_ov000_0215440c;
extern "C" struct Struct_ov024_021eb5d0_5* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct Struct_ov024_021ea4d0_2;
extern "C" int func_ov024_021ea4d0(Struct_ov024_021ea4d0*, Struct_ov024_021ea4d0_2*);
extern "C" int func_ov024_021ea500(struct Struct_ov024_021ea4d0* self, struct Struct_ov024_021eaa50_2* rec, int id);
extern "C" int func_ov000_02156cc4(void* world, int id, struct Struct_ov024_021eaa50_2* rec, int n);
struct S_10088;
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov024_021e6798(GameObject*);
extern "C" struct Struct_ov024_021eb5d0_5* func_ov000_0215e938(void* world);
struct Struct_ov000_0215fef0;
extern "C" void func_ov000_0215fef0(Struct_ov000_0215fef0*);
extern "C" short func_ov000_02154c68(void* world, int id, struct Struct_ov024_021eaa50_2* rec);
extern "C" int func_ov024_021e9b74(struct Struct_ov024_021ea4d0* self, int a, short* b, struct Struct_ov024_021eaa50_2* rec);
extern "C" int func_ov024_021e9f68(struct Struct_ov024_021ea4d0* self, short* a, short* b, struct Struct_ov024_021eaa50_2* rec, unsigned char* flag);
extern "C" int func_ov024_021ea584(struct Struct_ov024_021ea4d0* self, int a, int b, struct Struct_ov024_021eaa50_2* rec);
extern "C" void func_ov000_0215cd80(void* world);
extern "C" int func_ov000_02156f98(void* world, int id, struct Struct_ov024_021eaa50_2* rec);
extern "C" int func_ov000_02156e30(void* world, int a, int b, struct Struct_ov024_021eaa50_2* rec);
extern "C" int func_ov000_02156648(void* world, int a, int b, struct Struct_ov024_021eb5d0_5* n, struct Struct_ov024_021eaa50_2* rec, struct Struct_ov024_021eb5d0_9* list, int flag);
int GetAttackBaseDamage(int*, int, int, int*, int*);
extern "C" void func_ov024_021da550(int* p);
extern "C" int func_ov024_021da55c(int* p, void* world, unsigned short a, unsigned short b, int n, struct Struct_ov024_021eaa50_2* rec, int arg6);
extern "C" unsigned char* func_02053c6c(unsigned char*);
extern "C" float func_02074948(int v);
extern "C" int func_ov024_021e67c8(struct Struct_ov024_021ea4d0* self, int a, int b);
extern "C" int func_ov024_021e6948(struct Struct_ov024_021ea4d0* self, int a, int b, int c);
extern "C" int func_ov024_021e6a90(struct Struct_ov024_021ea4d0* self, int a, int b, struct Struct_ov024_021eaa50_2* rec, unsigned short arg4);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" void func_ov000_02159eac(void* world, void* entry, unsigned char kind);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215ffc4(void* node, void* entry, int v);
extern "C" int func_ov000_021573a8(void* world, int id, int target, int arg3);
extern "C" struct Struct_ov024_021eb5d0_6* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215ccbc(void* world, struct Struct_ov024_021eb5d0_6* e, void* c, short a, short b, int d, unsigned long long f, unsigned char h);
extern "C" struct Struct_ov024_021eb5d0_8* func_ov000_0215fff4(void* node, int a, int b);
extern "C" int func_ov000_02157288(void* world, int id, struct Struct_ov024_021eaa50_2* rec);
extern "C" void func_ov000_0215cd44(void* world, void* entry, void* c, int a, unsigned long long f, int e);
struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);
extern "C" short func_ov000_0215a1d4(void* world, int id, int amount, short* out);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_ov000_0215fe84(void* obj, void* entry, int v);
extern "C" void func_ov024_021e4c04(struct Struct_ov024_021ea4d0* self, int id, int target, struct Struct_ov024_021eaa50_2* rec, int arg4);
extern "C" void func_ov024_021e556c(struct Struct_ov024_021ea4d0* self, int id, int target, struct Struct_ov024_021eaa50_2* rec, int arg4);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" int func_ov024_021eb1ec(void*, int);
extern "C" int func_ov024_021eb2b4(struct Struct_ov024_021ea4d0* self);
extern "C" int func_ov024_021eb344(struct Struct_ov024_021ea4d0* self, int id, int arg2);
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov024_021eb3e0(struct Struct_ov024_021ea4d0* self, int id);
extern "C" void func_ov000_0215af54(void* world, int id, int v);
struct Struct_0208978c;
extern "C" void func_0208978c(Struct_0208978c*, short);
extern "C" int func_ov000_0215eb1c(void* world, short* buf, int count, int flag);
extern "C" int func_ov024_021eb08c(struct Struct_ov024_021ea4d0* self, int id, int target, int kind);
extern "C" void func_ov000_0215a908(void* world, int id);
extern "C" int func_ov000_02155f9c(void* world, int id, int v);
extern "C" void func_ov024_021e6060(struct Struct_ov024_021ea4d0* self, int id, struct Struct_ov024_021eaa50_2* rec, int v);
extern "C" void func_ov024_021e6104(struct Struct_ov024_021ea4d0* self, int id, struct Struct_ov024_021eaa50_2* rec);
extern "C" void func_ov024_021e62cc(struct Struct_ov024_021ea4d0* self, int id, struct Struct_ov024_021eaa50_2* rec);
extern "C" int func_02085038(char*);
extern "C" int func_ov000_02159d24(void* world, int id);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov024_021eb5d0_7* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_020881ac(void* p);
extern "C" void func_02088234(void* p);
extern "C" void func_ov024_021e80e4(struct Struct_ov024_021ea4d0* self, struct Struct_ov024_021eb5d0_9* list, struct Struct_ov024_021eaa50_2* rec, int a, int b, struct Struct_ov024_021eaa50_2* c);
extern "C" unsigned short func_ov024_021e99d8(struct Struct_ov024_021ea4d0* self, struct Struct_ov024_021eb5d0_9* list, struct Struct_ov024_021eaa50_2* rec);
extern "C" void* func_ov000_02160130();
extern "C" char* func_ov000_02160f08(void* p);
extern "C" int func_020ddb38(int a, int b, void* slot, void* world);
extern "C" int func_ov000_0215fd24(int, int);
extern "C" void func_ov017_021c3fb4(unsigned short a, int b);
extern "C" void func_ov000_021584e8(void* world, void* a, void* b, void* c, int d, int e);
extern "C" void PartyMember_RecalculateStats(unsigned char* p, int v);
void ApplyCombatantBuffs(int, int);
struct GameState;
extern "C" void* GameState_GetParty(GameState*);

// USA: func_ov024_021eb5d0
extern "C" ARM void func_ov024_021eb5d0(struct Struct_ov024_021ea4d0* self, struct Struct_ov024_021eb5d0_10* world, struct Struct_ov024_021eb5d0_9* list, struct Struct_ov024_021eaa50* src, unsigned char arg4) {
    struct Struct_ov024_021eb5d0_13 res;
    unsigned long long var1;
    unsigned long long var2;
    short var3;
    short var4;
    short s2;
    unsigned char c0;
    struct Struct_ov024_021fe8f0 var7;
    struct Struct_ov024_021fe718 var8;
    struct Struct_ov024_021fe718 var9;
    unsigned char var10[0xb0];
    unsigned char var11[0xb0];
    int var12 = data_ov024_02200144;
    if ((var12 & 1) == 0) {
        data_ov024_021ff508[0x1e] = __ptmf_null;
        data_ov024_021ff508[0x22] = __ptmf_null;
        data_ov024_021ff508[0x3b] = __ptmf_null;
        data_ov024_021ff508[0x3c] = __ptmf_null;
        data_ov024_02200144 = var12 | 1;
    }
    self->f10 = world;
    self->f4 = list;
    self->f8 = list->f10;
    struct BattleStruct* bs = (BattleStruct*)GameState::GetInstance();
    ActionDataTables* table = func_020797dc();
    struct Struct_ov024_021eaa50_2* rec = func_02079e2c((char*)table, self->f4->f0);
    if (rec == 0) return;
    self->unknown_6d_ = 1;
    self->unknown_6e_ = 0;
    self->f1c = 1.0f;
    self->f47 = 0;
    memset(self->f20, -1, 8);
    memset(self->f28, -1, 0x10);
    memset(self->unknown_38_, 0, 4);
    memset(self->f3c, 0, 8);
    self->f4->fb.b3 = 1;
    world->unknown_8e04_ = -1;
    world->unknown_8e06_ = -1;
    int group = rec->f18.kind;
    if (group >= 0x51) group = 0;
    if (data_ov024_021ff508[group] == 0) group = 0;
    void* w = self->f10;
    const short id = self->f4->f10->f20;
    struct Struct_ov024_021eb5d0_12* actor = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)w, id);
    short var20 = -1;
    if (data_ov024_021ff508[group] == 0) return;
    self->f4->f0 = func_ov024_021eaa50(self, src, rec, arg4);
    self->f4->f2 = src->f2;
    rec = func_02079e2c((char*)table, self->f4->f0);
    if (rec == 0) return;
    group = rec->f18.kind;
    if (group >= 0x51) group = 0;
    if (data_ov024_021ff508[group] == 0) group = 0;
    void* var21 = func_02079ee0(table, rec->f8.elem);
    var7 = data_ov024_021fe8f0;
    unsigned char count;
    if (IN_RANGE_021eb5d0(id)) count = func_ov000_021540c8(self->f10, src, (int)var7.v);
    else count = func_ov000_0215440c(self->f10, src, var7.v);
    if (rec->f4.id == 0xa8 || rec->f4.id == 0x14a) {
        if (id == var7.v[0]) {
            src->f0 = 0x3ac;
            src->unknown_9_ = 1;
            self->f4->f2 = rec->f4.id;
            self->f4->f0 = 0x3ac;
            rec = func_02079e2c((char*)table, self->f4->f0);
            if (rec == 0) return;
            group = rec->f18.kind;
            if (group >= 0x51) group = 0;
            if (data_ov024_021ff508[group] == 0) group = 0;
        }
    }
    if (rec->f4.id == 0xb7 || rec->f4.id == 0xb8) {
        if (id == var7.v[0]) {
            src->f0 = 0x3ad;
            src->unknown_9_ = 1;
            self->f4->f2 = rec->f4.id;
            self->f4->f0 = 0x3ad;
            rec = func_02079e2c((char*)table, self->f4->f0);
            if (rec == 0) return;
            group = rec->f18.kind;
            if (group >= 0x51) group = 0;
            if (data_ov024_021ff508[group] == 0) group = 0;
        }
    }
    if (rec->f4.id == 0x61) {
        count = 2;
        var7.v[1] = var7.v[0];
    }
    if (rec->f4.id == 0x79) {
        var7.v[count] = func_ov000_0215cda0(self->f10);
        count = count + 1;
    }
    self->unknown_78_ = 0;
    count = func_ov024_021e8dc0(self, id, rec, var7.v, count);
    res.f4 = 0;
    self->f14 = 0;
    self->unknown_44_ = -1;
    self->f10->unknown_8e38_ = 0;
    if (rec->f4.id == 0x200 || rec->f4.id == 0x20c) {
        struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, id);
        switch (rec->f4.id) {
        case 0x200:
            if (pc != 0) {
                int lvl = GameObject_GetPartyMemberLevel(pc);
                float scale = 1.0f + 0.01f * (11.0f + (float)(unsigned int)lvl);
                if (scale > 2.0f) scale = 2.0f;
                self->f10->unknown_8e3c_ = NextRandomFloatScaled((Random*)w, 1.1f, scale, 1);
                self->f4->f10->f18 = self->f10->unknown_8e3c_;
            }
            break;
        case 0x20c:
            self->f10->unknown_8e3c_ = NextRandomFloatScaled((Random*)w, 1.5f, 3.0f, 1);
            self->f10->unknown_8e40_ = self->f10->unknown_8e3c_;
            break;
        }
    }
    self->f6c = 0;
    if (rec->f4.id == 0x1ff || rec->f4.id == 0x20b) {
        int roll = NextRandomMax((Random*)self->f10, 0x64);
        int var27 = 0;
        switch (rec->f4.id) {
        case 0x1ff:
            var27 = 0x32;
            break;
        case 0x20b:
            var27 = 0x46;
            break;
        }
        if (roll < var27) self->f6c = 1;
    }
    unsigned char var28 = 0;
    self->unknown_71_ = var28;
    self->unknown_72_ = var28;
    self->unknown_73_ = var28;
    self->f10->unknown_8e54_ = var28;
    if (actor != 0) {
        self->f10->unknown_8e54_ = actor->unknown_138_->f2;
        if (!IN_RANGE_021eb5d0(id)) {
            if (actor->unknown_138_->f2 >= 0xff) self->unknown_6d_ = 0;
        }
        if (func_ov024_021eadfc((GameObject*)actor) != 0) self->unknown_6d_ = 0;
        if (arg4 != 0) self->unknown_6d_ = 0;
        if (rec->f8.unknown_3_4_ != 0) self->unknown_6d_ = 0;
        if (self->unknown_6d_ != 0) {
            var28 = 1;
            unsigned int var29 = rec->f8.unknown_0_0_;
            if (var29 >= 0xff) {
                var29 = actor->unknown_138_->f2;
                func_ov000_0215a124(self->f10, id, var29);
            } else {
                if (IN_RANGE_021eb5d0(id)) {
                    struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, id);
                    if (pc != 0 && func_02083b00(pc->f150, 0x106) != 0) var29 = func_020dd290(pc, var29);
                }
                func_ov000_0215a124(self->f10, id, var29);
            }
        }
    }
    if (id == GameState_GetProtagonistIndex((GameState*)bs)) {
        if (func_ov024_021eb47c(self, rec->f4.id) != 0) {
            func_020ac4c0(var10);
            func_020a0530((Struct_020a0530*)var10, 1);
            func_020a01b8((Struct_020a01b8*)(var10 + 0x68), 1);
            func_020ac494(var10);
        }
        if (func_ov000_02159c58(self->f10, (unsigned short)rec->f4.id) != 0) {
            func_020ac4c0(var11);
            func_020a0674((Struct_020a0674*)var11, 1);
            func_020a017c((Struct_020a017c*)(var11 + 0x68), 1);
            func_020ac494(var11);
        }
    }
    if (arg4 != 0) {
        count = src->unknown_9_;
        for (int k = 0; k < src->unknown_9_; k++) {
            var7.v[k] = func_ov000_021600f8((Struct_ov000_0215440c*)src, k)->unknown_e_;
        }
    }
    int var32 = 0;
    self->f18 = 0;
    int var33 = 0;
    unsigned char var34 = 1;
    unsigned char flagC = var32;
    int hit = var32;
    struct Struct_ov024_021eaa50_2* var37 = rec;
    if (func_ov024_021ea4d0(self, (Struct_ov024_021ea4d0_2*)rec) != 0) hit = 1;
    if (func_ov024_021ea500(self, rec, id) != 0) hit = 1;
    if (hit != 0) {
        var34 = 0;
        if (func_ov000_02156cc4(self->f10, id, rec, count) != 0) {
            flagC = 1;
            self->f4->fa |= 1;
        }
    }
    int i;
    short var39;
    unsigned char var40 = 0;
    self->unknown_79_ = 0;
    var39 = var40 - 1;
    for (i = var40; i < count; i++, self->f18 = self->f18 + 1) {
        if (func_02010088((S_10088*)actor) != 0) break;
        if (func_ov024_021e6798((GameObject*)actor) != 0) break;
        if (group == 0x21 && id == var7.v[i]) continue;
        self->fc = func_ov000_0215e938(self->f10);
        struct Struct_ov024_021eb5d0_5* var41 = self->fc;
        if (var41 == 0) return;
        func_ov000_0215fef0((Struct_ov000_0215fef0*)var41);
        var41->f20 = 0;
        self->fc->unknown_e_ = var7.v[i];
        int accum = 0;
        self->fc->unknown_17_ = self->fc->unknown_17_ + 1;
        self->unknown_70_ = 1;
        self->unknown_6f_ = 1;
        self->unknown_74_ = 0;
        self->f10->unknown_8e6e_ = NextRandomMax((Random*)self->f10, 0x64);
        var7.v[i] = func_ov000_02154c68(self->f10, var7.v[i], rec);
        self->fc->unknown_e_ = var7.v[i];
        if (rec->f4.id == 0x79 && self->f18 == (count - 1)) {
            struct Struct_ov024_021eb5d0_12* var43 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var7.v[i]);
            if (var43 == 0 || func_02010088((S_10088*)var43) != 0 ||
                func_ov024_021e6798((GameObject*)var43) != 0) {
                var7.v[i] = func_ov000_0215cda0(self->f10);
                if (var7.v[i] < 0) continue;
                self->fc->unknown_e_ = var7.v[i];
            }
        }
        if (group != 0x12 && group != 0x21) {
            struct Struct_ov024_021eb5d0_12* var44 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var7.v[i]);
            if (var44 == 0) continue;
            if (func_02010088((S_10088*)var44) != 0) continue;
        }
        int var45 = 0;
        var3 = id;
        var4 = var7.v[i];
        if (var39 != var7.v[i]) {
            self->unknown_79_ = 0;
            var39 = var4;
        }
        struct Struct_ov024_021eaa50_2* var46 = rec;
        int var47 = func_ov024_021e9b74(self, var3, &var4, rec);
        if (var47 != 0) {
            if (IN_RANGE_021eb5d0(var4)) self->f4->fc.b2 = 1;
            else self->f4->fc.unknown_0_5_ = 1;
        }
        if (self->unknown_79_ != 0 && var47 == 0) continue;
        self->unknown_76_ = 1;
        self->unknown_77_ = 0;
        c0 = 0;
        int tgt = var4;
        int var49 = func_ov024_021e9f68(self, &var3, &var4, rec, &c0);
        if (var49 != 0) var40 = 1;
        if (var3 != id) {
            var37 = rec;
            if (IN_RANGE_021eb5d0(tgt)) self->f4->fc.b2 = 1;
            else self->f4->fc.unknown_0_5_ = 1;
        }
        if (var49 == 0 && self->unknown_77_ == 0) func_ov024_021ea584(self, var3, var4, rec);
        else func_ov000_0215cd80(self->f10);
        if (group != 0x12 && group != 0x21) {
            struct Struct_ov024_021eb5d0_12* var50 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
            if (var50 == 0) continue;
            if (func_02010088((S_10088*)var50) != 0) continue;
        }
        if (var49 != 0) {
            var46 = func_02079e2c((char*)table, 1);
            var37 = var46;
            self->fc->unknown_1d_ = (self->fc->unknown_1d_ & ~1u) | 1;
            if (var46 != 0) var21 = func_02079ee0(table, var46->f8.elem);
        }
        if (var46 == 0) var46 = rec;
        if (var49 != 0 || self->unknown_77_ != 0 || c0 != 0) {
            if (var34 != 0) {
                if (rec->f4.id == 0x70 || rec->f4.id == 0x48) {
                    if (NextRandomMax((Random*)self->f10, 2) == 0) self->f4->fa |= 1;
                } else {
                    if (func_ov000_02156cc4(self->f10, id, rec, count) != 0) self->f4->fa |= 1;
                }
            } else {
                if (flagC != 0) self->f4->fa |= 1;
            }
            if (func_ov000_02156cc4(self->f10, var3, var46, count) != 0) {
                self->fc->f1c.unknown_0_7_ = 1;
                if (c0 != 0) self->f4->fa |= 0x40;
                else self->f4->fa |= 0x20;
                if (var20 < 0) var20 = var3;
            }
        } else {
            if (var34 != 0) {
                if (func_ov000_02156cc4(self->f10, var3, var46, count) != 0) {
                    self->fc->f1c.unknown_0_7_ = 1;
                    self->f4->fa |= 1;
                }
            } else {
                self->fc->f1c.unknown_0_7_ = flagC;
            }
        }
        unsigned char var51 = 0;
        if (func_ov000_02156f98(self->f10, var4, var46) != 0) {
            self->f4->fa |= 4;
            self->fc->f1c.b1 = 1;
        } else if (func_ov000_02156e30(self->f10, var3, var4, var46) != 0) {
            self->f4->fa |= 2;
            self->fc->f1c.b2 = 1;
        }
        self->f10->unknown_8e94_ = 0;
        unsigned char var52 = 0;
        if (var46->f4.id == 0x61 && self->f18 > 0) {
            var52 = 1;
            self->fc->f1c.b1 = 0;
            self->fc->f1c.b2 = 0;
            self->fc->f1c.unknown_0_7_ = 0;
        }
        unsigned char var53 = 0;
        if (var46->f4.id == 0x79 && self->f18 == (count - 1)) var53 = 1;
        if (func_ov000_02156648(self->f10, var3, var4, self->fc, var46, self->f4, var52) != 0) {
            int base = GetAttackBaseDamage((int*)self, var3, var4, (int*)var46, (int*)var21);
            func_ov024_021da550(&res.f0);
            var45 = func_ov024_021da55c(&res.f0, world, var3, var4, count, var46, base);
            if (var46->f4.id == 0x70 || var46->f4.id == 0x48) {
                if (var45 > 0) {
                    if (var49 != 0 || self->unknown_77_ != 0) self->f4->fa |= 0x20;
                    else self->f4->fa |= 1;
                    if (var20 < 0) var20 = var3;
                    self->fc->f1c.unknown_0_7_ = 1;
                    if (IN_RANGE_021eb5d0(var4)) {
                        struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, var4);
                        unsigned char* fld = func_02053c6c((unsigned char*)pc);
                        if (pc != 0 && fld != 0) {
                            if (*(short*)(fld + 0x2cc) > 0) {
                                if (func_02083b00(pc->f150, 0x28) != 0) {
                                    self->f4->fa |= 2;
                                    self->fc->f1c.b2 = 1;
                                }
                            }
                        }
                    }
                } else {
                    var45 = 0;
                }
            }
            if ((var46->f10 & 0x20000) != 0) {
                unsigned char var57 = 1;
                if (var46->f4.id == 1 || var46->f4.id == 2) {
                    if (IN_RANGE_021eb5d0(var3)) {
                        struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, var3);
                        if (pc != 0) {
                            struct Struct_ov024_021eb5d0_14* var59 = (struct Struct_ov024_021eb5d0_14*)(pc->f150 + 0x2f4);
                            if (var59 != 0) {
                                if (var59->b1 == 0) {
                                    if (var59->b0 == 0) var57 = 0;
                                }
                            }
                        }
                    } else {
                        var57 = 0;
                    }
                }
                if (var57 != 0) {
                    float mul = func_02074948((signed char)i);
                    var45 = (int)((float)var45 * mul);
                }
                if (var46->f4.id == 0x79) var45 = (int)(0.8f * (float)var45);
            }
            if (var52 != 0) {
                var45 = func_ov024_021e67c8(self, var3, var4);
            } else if (var53 != 0) {
                var45 = func_ov024_021e6948(self, var4, var33, (count - 1));
            } else {
                var45 = func_ov024_021e6a90(self, var3, var4, var46, (unsigned short)var45);
            }
            if (var46->f4.id == 0x79 && self->f18 != (count - 1) && var45 > 0) {
                if (var33 <= 0) var33 = var45;
            }
            var51 = 1;
            if (self->fc->f1c.b1 != 0 || self->fc->f1c.b2 != 0) {
                var51 = 0;
                var45 = 0;
                func_ov000_0215cd80(self->f10);
                void* arr = GameState_GetParty((GameState*)(BattleStruct*)GameState::GetInstance());
                if (self->fc->f1c.b2 != 0) {
                    if (func_02086ef0((ArrayContainsByteStruct*)arr, var4) != 0) {
                        func_ov000_0215a8d4((unsigned char*)self->f10, 6);
                    }
                }
            }
        } else {
            if (self->unknown_76_ != 0 && (var46->f10 & 0x2000) != 0) {
                struct Struct_ov024_021eb5d0_12* var62 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var3);
                if (var62 != 0) {
                    if (func_ov024_021da998((Struct_ov024_021da670_6*)var62) != 0 ||
                        func_ov024_021dd260((Struct_ov024_021dd028_5*)var62) != 0) {
                        self->f47 = 1;
                        if (func_ov024_021dd260((Struct_ov024_021dd028_5*)var62) != 0) self->f47 = 2;
                    }
                }
            }
            func_ov000_0215cd80(self->f10);
        }
        self->unknown_75_ = 1;
        struct Struct_ov024_021eb5d0_6* ent = (self->*data_ov024_021ff508[group])(var3, var4, var46, var45, &res.f4, var51);
        if (ent != 0) {
            int kind = 0;
            int extra = 0;
            if (self->fc->f1c.b2) { kind = 6; extra = 0x96; }
            if (self->fc->f1c.unknown_0_6_) { kind = 0xc; extra = 0x255; }
            if (self->fc->f1c.b1) { kind = 5; extra = 0x97; }
            if (self->fc->f1c.unknown_0_4_) { kind = 0xa; extra = 0x1b9; }
            if (self->fc->f1c.unknown_0_5_) { kind = 0x26; extra = 0x24d; }
            if (self->fc->f1c.b3) { kind = 9; extra = 0x2b; }
            if (kind > 0) func_ov000_02159eac(self->f10, ent, kind);
            if (extra > 0) func_ov000_0215a88c(self->f10, ent, (unsigned short)extra);
            func_ov000_0215ffc4(self->fc, ent, 0);
            self->f10->unknown_8e02_ = self->f10->unknown_8e02_ + 1;
            accum = accum + var45;
            self->unknown_74_ = 1;
            if (var49 == 0) var32 = var32 + var45;
        }
        if (accum > 0 && var49 == 0) {
            struct Struct_ov024_021eb5d0_12* var66 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
            if (var66 != 0) {
                if (var46->f18.kind == 1 || var46->f18.kind == 0x23) {
                    if ((var66->unknown_138_->f14 & 0x10000000) != 0) var66->unknown_138_->f22 = var66->unknown_138_->f22 | 0x4000;
                }
            }
            int mp = 0;
            if (var46->f4.id == 1 || var46->f4.id == 2) {
                mp = func_ov000_021573a8(self->f10, id, var4, accum);
                if (mp > 0) {
                    struct Struct_ov024_021eb5d0_12* var68 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
                    int var69 = 0;
                    if (var68 != 0) {
                        if (!IN_RANGE_021eb5d0(var4)) {
                            if (var68->unknown_138_->f2 < 0xff) var69 = func_ov000_0215a124(self->f10, var4, mp);
                        } else {
                            var69 = func_ov000_0215a124(self->f10, var4, mp);
                        }
                    }
                    struct Struct_ov024_021eb5d0_6* var70 = func_ov000_0215e958(self->f10);
                    if (var70 != 0) {
                        struct Struct_ov024_021eb5d0_12* var71 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
                        func_ov000_02159eac(self->f10, var70, 1);
                        func_ov000_02159eac(self->f10, var70, 0x2a);
                        func_ov000_0215ccbc(
                            self->f10, var70, var71, mp, var71->unknown_138_->f0, var69, var70->flags, 0);
                        func_ov000_0215ffc4(self->fc, var70, 1);
                        self->f10->unknown_8e02_ = self->f10->unknown_8e02_ + 1;
                        if (self->f68 != 0) {
                            var70->f8 = self->f68->f8;
                            var70->unknown_1f_ = self->f68->unknown_1f_;
                            self->f68->f8 = 0;
                            self->f68->unknown_1f_ = 0;
                            self->f68 = var70;
                        }
                    }
                    struct Struct_ov024_021eb5d0_8* var72 = func_ov000_0215fff4(self->fc, 0, 0);
                    if (var72 != 0) var72->f10 = var69;
                }
            }
            if (self->unknown_70_ != 0) {
                int var73 = func_ov000_02157288(self->f10, var4, var46);
                if (var73 > 0) {
                    struct Struct_ov024_021eb5d0_6* var74 = func_ov000_0215e958(self->f10);
                    if (var74 != 0) {
                        struct Struct_ov024_021eb5d0_12* var75 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
                        func_ov000_02159eac(self->f10, var74, 0x10);
                        func_ov000_02159eac(self->f10, var74, 0x19);
                        func_ov000_0215cd44(self->f10, var74, var75, 0, 0, 0);
                        func_ov000_0215a88c(self->f10, var74, (unsigned short)var73);
                        func_ov000_0215ffc4(self->fc, var74, 1);
                        self->f10->unknown_8e02_ = self->f10->unknown_8e02_ + 1;
                        func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)self, (int)self->fc);
                    }
                }
            }
            if (mp > 0 && var4 != id) {
                GetCombatantByID((int)self->f10, var4);
                struct Struct_ov024_021eb5d0_12* me = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, id);
                s2 = 0;
                short delta = func_ov000_0215a1d4(self->f10, id, mp, &s2);
                list->f10->f24 = delta;
                if (!IN_RANGE_021eb5d0(id)) {
                    if (me->unknown_138_->f2 >= 0xff) s2 = mp;
                }
                if (s2 > 0) {
                    unsigned short sel = func_ov024_021da644(id, 0x25f, 0x238);
                    struct Struct_ov024_021eb5d0_6* var79 = func_ov000_0215e958(self->f10);
                    if (var79 != 0) {
                        func_ov000_0215a88c(self->f10, var79, (unsigned short)sel);
                        var1 = 0;
                        func_ov000_02159eac(self->f10, &var1, 0x22);
                        func_ov000_0215ccbc(
                            self->f10, var79, me, -s2, me->unknown_138_->f0, delta, var1, 0);
                        func_ov000_0215fe84(self->f8, var79, 5);
                        self->f8->f1c = var4;
                        self->f8->unknown_1e_ = 0;
                        self->f10->unknown_8e02_ = self->f10->unknown_8e02_ + 1;
                    }
                }
            }
            if (var49 == 0) func_ov024_021e4c04(self, id, var4, rec, accum);
        }
        if (var49 == 0 && self->unknown_79_ == 0) func_ov024_021e556c(self, id, var4, rec, accum);
        if (self->unknown_74_ != 0 && self->unknown_6f_ != 0) {
            func_ov000_021600cc((Struct_ov000_0215767c_5*)list, (Struct_ov000_0215767c_4*)self->fc);
            self->f10->unknown_8e01_ = self->f10->unknown_8e01_ + 1;
        }
        if (IN_RANGE_021eb5d0(var4)) {
            struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, var4);
            if (pc != 0 && func_ov024_021eb1ec(self, var4) != 0) {
                int val = accum;
                if (rec->f18.kind != 1 && rec->f18.kind != 0x23) val = 0;
                int roll = NextRandomMax((Random*)self->f10, 0x64);
                unsigned int idx = func_ov024_021eb2b4(self) & 0xff;
                if (idx >= 4) idx = 3;
                float mult = data_ov024_021fe738[idx];
                int var85 = (int)(mult * (float)(unsigned int)(func_ov024_021eb344(self, var4, val) + rec->unknown_2c_.c));
                if (func_ov000_0215fc60((char*)self->f10) != 0) var85 = 0;
                if (roll < var85) {
                    pc->unknown_138_->unknown_3b_.b3 = 1;
                    func_ov024_021eb3e0(self, var4);
                    func_ov000_0215af54(self->f10, var4, 1);
                }
            }
        }
        if (!IN_RANGE_021eb5d0(id)) continue;
        if (IN_RANGE_021eb5d0(var4)) continue;
        struct Struct_ov024_021eb5d0_12* var86 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, var4);
        if (var86 == 0) continue;
        func_0208978c((Struct_0208978c*)var86->unknown_138_, id);
        if (rec->f18.sub == 2) var86->unknown_138_->f3c.b1 = 1;
    }
    if (IN_RANGE_021eb5d0(id)) {
        var8 = data_ov024_021fe788;
        int n = func_ov000_0215eb1c(self->f10, var8.v, 8, 1);
        for (int j = 0; j < n; j++) {
            unsigned char any = 0;
            if (rec->f1c.group == 5) {
                if (func_ov024_021eb08c(self, id, var8.v[j], 0x13) != 0) any = 1;
            }
            if (rec->f1c.group == 0xc) {
                if (func_ov024_021eb08c(self, id, var8.v[j], 0x14) != 0) any = 1;
            }
            if ((list->fa & 1) != 0) {
                if (func_ov024_021eb08c(self, id, var8.v[j], 0x18) != 0) any = 1;
            }
            if (any != 0) func_ov000_0215a908(self->f10, var8.v[j]);
        }
    }
    if (GetCombatantByID((int)self->f10, id) != 0 && func_ov000_02155f9c(self->f10, id, 0) == 0) {
        if (var40 == 0) {
            func_ov024_021e6060(self, id, rec, var32);
            func_ov024_021e6104(self, id, rec);
        }
        func_ov024_021e62cc(self, id, rec);
    }
    if (IN_RANGE_021eb5d0(id)) {
        var9 = data_ov024_021fe718;
        int m = func_ov000_0215eb1c(self->f10, var9.v, 8, 1);
        struct Struct_ov024_021eb5d0_12* pc = (struct Struct_ov024_021eb5d0_12*)(void*)func_0200ff1c((GameState*)bs, id);
        if (pc != 0 && m > 0 && func_ov024_021eb1ec(self, id) != 0) {
            int roll = NextRandomMax((Random*)self->f10, 0x64);
            unsigned int idx = func_ov024_021eb2b4(self) & 0xff;
            if (idx >= 4) idx = 3;
            float mult = data_ov024_021fe738[idx];
            int bonus = func_02085038((char*)pc->f150);
            int sum = func_ov000_02159d24(self->f10, id) + rec->unknown_2c_.c;
            int var97 = (int)(mult * (float)(unsigned int)(sum + bonus));
            if (func_ov000_0215fc60((char*)self->f10) != 0) var97 = 0;
            if (roll < var97) {
                pc->unknown_138_->unknown_3b_.b3 = 1;
                func_ov024_021eb3e0(self, id);
                func_ov000_0215af54(self->f10, id, 1);
            }
        }
    }
    if (func_ov024_021eb47c(self, rec->f4.id) != 0) {
        struct Struct_ov024_021eb5d0_12* me = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, id);
        if (me != 0) me->unknown_138_->unknown_3b_.b3 = 0;
    }
    if (func_ov000_02159c58(self->f10, (unsigned short)rec->f4.id) != 0) {
        for (int k = 0; k < list->f8; k++) {
            struct Struct_ov024_021eb5d0_7* nn = func_ov000_02160094((Struct_ov000_0215440c_2*)list, k);
            if (nn != 0) {
                struct Struct_ov024_021eb5d0_12* var101 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, nn->f20);
                if (var101 != 0) {
                    var101->unknown_138_->unknown_3b_.b2 = 1;
                    var101->unknown_138_->unknown_3b_.b3 = 0;
                }
            }
        }
    }
    if (self->f47 != 0) {
        struct Struct_ov024_021eb5d0_12* me = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, id);
        if (me != 0) {
            if (func_02010088((S_10088*)me) == 0 &&
                func_ov024_021e6798((GameObject*)me) == 0) {
                struct Struct_ov024_021eb5d0_6* var103 = func_ov000_0215e958(self->f10);
                if (var103 != 0) {
                    func_ov000_0215a88c(self->f10, var103, (unsigned short)0x1f1);
                    var2 = 0;
                    if (self->f47 > 1) func_ov000_02159eac(self->f10, &var2, 8);
                    func_ov000_0215cd44(self->f10, var103, me, 0, var2, 0);
                    func_ov000_0215fe84(list->f10, var103, 1);
                    self->f10->unknown_8e02_ = self->f10->unknown_8e02_ + 1;
                }
            }
            func_020881ac(me->unknown_138_);
            func_02088234(me->unknown_138_);
        }
    }
    if (self->unknown_6e_ == 0) {
        func_ov024_021e80e4(self, list, rec, (res.f4 & 2) != 0, var40, var37);
    }
    list->f18 = func_ov024_021e99d8(self, list, rec);
    if ((list->fa & 1) != 0) {
        list->f22 = func_ov024_021da644(list->f10->f20, rec->f28.c, rec->unknown_2c_.a);
    }
    if ((list->fa & 0x20) != 0) {
        list->f24 = func_ov024_021da644(var20, var37->f28.c, var37->unknown_2c_.a);
    }
    if ((list->fa & 0x40) != 0) {
        list->f24 = func_ov024_021da644(var20, var37->f28.c, var37->unknown_2c_.a);
    }
    struct Struct_ov024_021eb5d0_12* cur = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, list->f10->f20);
    if (cur != 0) {
        if (self->unknown_6d_ == 0 && var28 != 0) {
            short var105 = self->f10->unknown_8e54_;
            if (var105 > 0) cur->unknown_138_->f2 = var105;
        }
        for (int k = 0; k < list->f8; k++) {
            struct Struct_ov024_021eb5d0_7* nn = func_ov000_02160094((Struct_ov000_0215440c_2*)list, k);
            if (nn != 0) {
                struct Struct_ov024_021eb5d0_12* var108 = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, nn->f20);
                if (var108 != 0) {
                    nn->f22 = var108->unknown_138_->f0;
                    nn->f24 = var108->unknown_138_->f2;
                }
            }
        }
    }
    if (!IN_RANGE_021eb5d0((unsigned short)list->f10->f20)) return;
    if (rec->f18.sub != 3) return;
    unsigned char gate = 1;
    if (rec->f8.pair != 1 && self->f14 <= 0) gate = 0;
    if (gate == 0) return;
    char* var110 = func_ov000_02160f08(func_ov000_02160130());
    int who = (unsigned short)list->f10->f20;
    struct Struct_ov024_021eb5d0_16* slot;
    if (IN_RANGE_021eb5d0(who)) {
        for (int k = 0; k < 4; k++) {
            if (who == *(int*)(var110 + k * WORK_STRIDE_021eb5d0 + 0x9a4)) {
                slot = (struct Struct_ov024_021eb5d0_16*)(var110 + 0x158 + 0x800 + k * WORK_STRIDE_021eb5d0);
                goto found;
            }
        }
    }
    slot = 0;
found:
    var110 = var110 + 0xd0;
    if (var110 == 0) return;
    if (func_020ddb38(who, slot->f22, slot, self->f10) != 2) return;
    if (func_ov000_0215fd24((int)self->f10, list->f10->f20) != 0) {
        func_ov017_021c3fb4(list->f10->f20, 1);
    }
    struct Struct_ov024_021eb5d0_6* last = func_ov000_0215e958(self->f10);
    struct Struct_ov024_021eb5d0_12* lastc = (struct Struct_ov024_021eb5d0_12*)GetCombatantByID((int)self->f10, list->f10->f20);
    if (last == 0 || lastc == 0) return;
    func_ov000_021584e8(self->f10, last, lastc, list->f10, 0x258, 0);
    PartyMember_RecalculateStats(lastc->f150, 0);
    ApplyCombatantBuffs((int)self->f10, list->f10->f20);
}
