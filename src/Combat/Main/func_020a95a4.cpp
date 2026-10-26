#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0208660c;
struct Struct_02061c04_23;
struct Struct_020838c4;
struct Obj0205e9f4;

struct BattleMemberData {
    unsigned char data[0x23c];
};

struct BattleData {
    unsigned char head[0xc];
    unsigned char unknown_c_[0x130];
    unsigned char unknown_13c_[0x98];
    unsigned char roster[0xe04 - 0x1d4];
    unsigned char unknown_e04_[0xc];
    unsigned char unknown_e10_[0xbc];
    unsigned char unknown_ecc_[0x5e];
    unsigned char unknown_f2a_[0xf68 - 0xf2a];
    int unknown_f68_;
    int unknown_f6c_;
    int unknown_f70_;
    int unknown_f74_;
    unsigned char ids[4];
    unsigned char idCount;
    unsigned char unknown_f7d_;
    unsigned char unknown_f7e_[2];
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char unknown_2c8d_[7];
    unsigned int areaId;
};

struct FieldSubState {
    unsigned char unk0[0x1b48];
    int unknown_1b48_;
    int unknown_1b4c_;
};

struct FieldState {
    unsigned char unk0[RG(0x840, 0x860)];
    FieldSubState sub;
    unsigned char unknown_2390_[RG(0x2774 - 0x2390, 0x27b4 - 0x23b0)];
    Vector3i savedPos;
    int unknown_2780_;
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
    unsigned char unknown_2789_[0x2794 - 0x2789];
    int unknown_2794_;
    unsigned char unknown_2798_[0x27b4 - 0x2798];
    unsigned short unknown_27b4_;
    unsigned short unknown_27b6_;
    unsigned char unknown_27b8_[0x27d0 - 0x27b8];
    unsigned char unknown_27d0_;
};

struct Struct_020a95a4_3 {
    unsigned char unk0[0x4a8];
    unsigned char unknown_4a8_[0x1a];
};

struct Struct_ov004_02170174 {
    unsigned char v[6];
};

struct Struct_020a95a4_4 {
    unsigned char unk0[RG(0x63dc, 0x617c)];
    unsigned char unknown_63dc_;
    unsigned char unknown_63dd_[RG(0x74fe - 0x63dd, 0x72be - 0x617d)];
    Struct_ov004_02170174 unknown_74fe_;
    unsigned char unknown_7504_[RG(0x7e74 - 0x7504, 0x7c34 - 0x72c4)];
    int unknown_7e74_;
};

struct MonsterRecord {
    unsigned char unk0[0x454];
    unsigned char name[0x10];
    unsigned char unknown_464_[0x568 - 0x464];
    short id;
    unsigned char unknown_56a_[RG(0x94c - 0x56a, 0x8b4 - 0x56a)];
    int state;
    unsigned char unknown_950_[0x964 - 0x950];
};

struct BattleSave {
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char ids[4];
    unsigned char idCount;
    struct Name { unsigned char v[0x12]; } names[4];
    unsigned char unknown_1d5a_[2];
    unsigned char head[0x1d4];
    unsigned short unknown_1f30_[0x3f0];
    unsigned char unknown_2710_[0x3f0];
    unsigned char unknown_2b00_[8];
    unsigned char unknown_2b08_[0x128];
    int unknown_2c30_;
    int unknown_2c34_;
    int unknown_2c38_;
    int unknown_2c3c_;
    int zero;
    unsigned char unknown_2c44_[7];
    unsigned char unknown_2c4b_;
    unsigned short areaId;
    unsigned short unknown_2c4e_;
    unsigned short words[4];
    unsigned char globalByte;
    unsigned char globalByte2;
    unsigned char unknown_2c5a_;
    unsigned char unknown_2c5b_;
    unsigned short dir;
    short angle;
    Vector3i pos;
    int value;
    int extra;
    unsigned char flag;
    unsigned char countA;
    unsigned char countB;
    unsigned char unknown_2c77_;
    Struct_ov004_02170174 name;
    unsigned char unknown_2c7e_[2];
    int unknown_2c80_;
    int unknown_2c84_;
    unsigned char unknown_2c88_[0x1a];
    unsigned char unknown_2ca2_;
    unsigned char unknown_2ca3_[5];
};

extern "C" void* GameState_GetParty(GameState* gs);
extern "C" void* LinkSession_GetInstance(void);
extern "C" FieldState* Zone3D_GetInstance(void);
extern "C" Struct_020a95a4_3* func_02094d6c(void);
extern "C" void func_020a93e0(char* param0);
extern "C" void func_02082d6c(void* dst, void* src);
extern "C" int func_020838c4(struct Struct_020838c4* s, int value);
extern "C" void func_020a093c(struct Struct_0208660c* obj, int a, int b, short c);
extern "C" int func_020a0a08(struct Struct_02061c04_23* map, int key, int amount);
extern "C" void func_0207c258(void* p);
extern "C" unsigned short* func_0207c5f8(unsigned char* roster, unsigned int idx);
extern "C" unsigned char* func_0207c60c(void* roster, unsigned int idx);
extern "C" short func_0207c620(unsigned char* roster, unsigned int idx);
extern "C" void func_0207c6a8(unsigned char* base, unsigned int index, unsigned char value);
extern "C" unsigned short* GameState_GetPlayerLocation(char* gs, unsigned int idx);
extern "C" void func_0209ca70(void* obj, int val);
extern "C" void func_0205e9f4(struct Obj0205e9f4* obj, int state);

extern unsigned char g_bgmPlayer[];
extern unsigned char g_sePlayer[];

// USA: func_020a95a4
#if defined(jpn)
extern "C" ARM int func_020a95a4(BattleSave* save, MonsterRecord* records) {
#else
extern "C" ARM int func_020a95a4(BattleSave* save, MonsterRecord* records, unsigned char* arg2) {
#endif
    GameState* gs = GameState::GetInstance();
    BattleData* battle = static_cast<BattleData*>(GameState_GetParty(gs));
    LinkSession_GetInstance();
    FieldState* field = Zone3D_GetInstance();
    GetGameResources();
    Struct_020a95a4_3* global = func_02094d6c();
#if !defined(jpn)
    func_020a93e0((char*)save);
#endif

    for (int i = 0; i < save->idCount; i++) {
        unsigned char id = save->ids[i];
        BattleMemberData* member = &save->members[save->memberCount + i];
        MonsterRecord* found = NULL;
        int j;
        for (j = 0; j < 4; j++) {
            if (id == records[j].id) {
                found = &records[j];
                break;
            }
        }
        if (found == NULL) {
            for (j = 0; j < 4; j++) {
                if (records[j].id < 0) {
                    found = &records[j];
                }
            }
        }
        if (found != NULL) {
            func_02082d6c(found, member);
            found->id = id;
            memcpy(found->name, &save->names[i], 0x10);
            func_020838c4((struct Struct_020838c4*)found, 0x5612);
            if (id == 0) {
                found->state = 5;
            }
        }
    }

    battle->memberCount = save->memberCount;
    memcpy(battle->members, save->members, save->memberCount * sizeof(BattleMemberData));
    memcpy(battle->ids, save->ids, 4);
    battle->idCount = save->idCount;
    memcpy(battle->head, save->head, sizeof(save->head));
    func_020a093c((struct Struct_0208660c*)battle->head, (int)battle->unknown_c_, (int)battle->unknown_13c_, 0x98);
    func_020a0a08((struct Struct_02061c04_23*)battle->head, 0x5612, 0x63);

    int total = 0;
    func_0207c258(battle->roster);
    for (int k = 0; k < 8; k++) {
        unsigned short* words = func_0207c5f8(battle->roster, k);
        unsigned char* bytes = func_0207c60c(battle->roster, k);
        short count = func_0207c620(battle->roster, k);
        memcpy(words, &save->unknown_1f30_[total], count * 2);
        memcpy(bytes, &save->unknown_2710_[total], count);
        total += count;
        func_0207c6a8(battle->roster, k, save->unknown_2b00_[k]);
    }

    memcpy(battle->unknown_e04_, save->unknown_2b08_, sizeof(save->unknown_2b08_));
    func_020a093c((struct Struct_0208660c*)battle->unknown_e04_, (int)battle->unknown_e10_, (int)battle->unknown_ecc_, 0x5e);
    battle->unknown_f6c_ = save->unknown_2c30_;
    battle->unknown_f68_ = save->unknown_2c34_;
    battle->unknown_f70_ = save->unknown_2c38_;
    battle->unknown_f74_ = save->unknown_2c3c_;
    memcpy(battle->unknown_2c8d_, save->unknown_2c44_, sizeof(save->unknown_2c44_));
    Struct_020a95a4_4* view = (Struct_020a95a4_4*)gs;
    battle->areaId = save->areaId;
    view->unknown_7e74_ = save->areaId;
    memcpy(GameState_GetPlayerLocation((char*)gs, 0), save->words, sizeof(save->words));
    func_0209ca70(g_bgmPlayer, save->globalByte);
    func_0205e9f4((struct Obj0205e9f4*)g_sePlayer, save->globalByte2);
    battle->unknown_f7d_ = save->unknown_2c5a_;
    view->unknown_63dc_ = save->unknown_2c5b_;
    field->unknown_2786_ = save->dir;
    field->unknown_2784_ = save->angle;
    field->savedPos = save->pos;
    field->unknown_2780_ = save->value;
    field->unknown_2794_ = save->extra;
    field->unknown_2788_ = save->flag;
    field->unknown_27b4_ = save->countA;
    field->unknown_27b6_ = save->countB;
    field->unknown_27d0_ = save->unknown_2c77_;
    view->unknown_74fe_ = save->name;
    FieldSubState* sub = &field->sub;
    sub->unknown_1b48_ = save->unknown_2c80_;
    sub->unknown_1b4c_ = save->unknown_2c84_;
    memcpy(global->unknown_4a8_, save->unknown_2c88_, sizeof(save->unknown_2c88_));
#if !defined(jpn)
    *arg2 = save->unknown_2ca2_;
#endif
    return 1;
}
