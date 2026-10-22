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

struct Fields020a093c;
struct KeyMap020a0a08;
struct Slots020838c4;
struct Obj0205e9f4;

struct BattleMemberData {
    unsigned char data[0x23c];
};

struct BattleData {
    unsigned char head[0xc];
    unsigned char headKeys[0x130];
    unsigned char headValues[0x98];
    unsigned char roster[0xe04 - 0x1d4];
    unsigned char tactics[0xc];
    unsigned char tacticsKeys[0xbc];
    unsigned char tacticsValues[0x5e];
    unsigned char unkf2a[0xf68 - 0xf2a];
    int valueF68;
    int valueF6c;
    int valueF70;
    int valueF74;
    unsigned char ids[4];
    unsigned char idCount;
    unsigned char byteF7d;
    unsigned char unkf7e[2];
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char extraIds[7];
    unsigned int areaId;
};

struct FieldSubState {
    unsigned char unk0[0x1b48];
    int savedPosA;
    int savedPosB;
};

struct FieldState {
    unsigned char unk0[RG(0x840, 0x860)];
    FieldSubState sub;
    unsigned char unk2390[RG(0x2774 - 0x2390, 0x27b4 - 0x23b0)];
    Vector3i savedPos;
    int savedValue;
    short savedAngle;
    unsigned short savedDir;
    unsigned char savedFlag;
    unsigned char unk2789[0x2794 - 0x2789];
    int savedExtra;
    unsigned char unk2798[0x27b4 - 0x2798];
    unsigned short savedCountA;
    unsigned short savedCountB;
    unsigned char unk27b8[0x27d0 - 0x27b8];
    unsigned char savedCountC;
};

struct Global02109418 {
    unsigned char unk0[0x4a8];
    unsigned char block4a8[0x1a];
};

struct Bytes6 {
    unsigned char v[6];
};

struct GameStateLoadView {
    unsigned char unk0[RG(0x63dc, 0x617c)];
    unsigned char byte63dc;
    unsigned char unk63dd[RG(0x74fe - 0x63dd, 0x72be - 0x617d)];
    Bytes6 name74fe;
    unsigned char unk7504[RG(0x7e74 - 0x7504, 0x7c34 - 0x72c4)];
    int value7e74;
};

struct MonsterRecord {
    unsigned char unk0[0x454];
    unsigned char name[0x10];
    unsigned char unk464[0x568 - 0x464];
    short id;
    unsigned char unk56a[RG(0x94c - 0x56a, 0x8b4 - 0x56a)];
    int state;
    unsigned char unk950[0x964 - 0x950];
};

struct BattleSave {
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char ids[4];
    unsigned char idCount;
    struct Name { unsigned char v[0x12]; } names[4];
    unsigned char unk1d5a[2];
    unsigned char head[0x1d4];
    unsigned short rosterWords[0x3f0];
    unsigned char rosterBytes[0x3f0];
    unsigned char rosterFlags[8];
    unsigned char tactics[0x128];
    int valueF6c;
    int valueF68;
    int valueF70;
    int valueF74;
    int zero;
    unsigned char extraIds[7];
    unsigned char unk2c4b;
    unsigned short areaId;
    unsigned short zero2;
    unsigned short words[4];
    unsigned char globalByte;
    unsigned char globalByte2;
    unsigned char byteF7d;
    unsigned char byte63dc;
    unsigned short dir;
    short angle;
    Vector3i pos;
    int value;
    int extra;
    unsigned char flag;
    unsigned char countA;
    unsigned char countB;
    unsigned char countC;
    Bytes6 name;
    unsigned char unk2c7e[2];
    int posA;
    int posB;
    unsigned char block4a8[0x1a];
    unsigned char inspect;
    unsigned char unk2ca3[5];
};

void* GetPtrField0x2a04_02010828(GameState* gs);
extern "C" void* func_0202ae18(void);
extern "C" FieldState* func_02012fe4(void);
Global02109418* GetGlobal02109418_02094d6c(void);
extern "C" void func_020a93e0(char* param0);
extern "C" void func_02082d6c(void* dst, void* src);
int RemoveSlotValueAndCompact020838c4(struct Slots020838c4* s, int value);
void SetFields020a093c(struct Fields020a093c* obj, int a, int b, short c);
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);
extern "C" void func_0207c258(void* p);
unsigned short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* roster, unsigned int idx);
unsigned char* GetPointerAt0xbf0_0207c60c(void* roster, unsigned int idx);
short GetShortFromArray0xc10_0207c620(unsigned char* roster, unsigned int idx);
void SetByteInArray0xc28_0207c6a8(unsigned char* base, unsigned int index, unsigned char value);
unsigned short* GetField0x74deForValidIndex_020120a0(char* gs, unsigned int idx);
void SetModeClamped0209ca70(void* obj, int val);
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);

extern unsigned char data_02109bf4[];
extern unsigned char g_sePlayer[];

// USA: func_020a95a4
#if defined(jpn)
extern "C" ARM int func_020a95a4(BattleSave* save, MonsterRecord* records) {
#else
extern "C" ARM int func_020a95a4(BattleSave* save, MonsterRecord* records, unsigned char* inspect) {
#endif
    GameState* gs = GameState::GetInstance();
    BattleData* battle = static_cast<BattleData*>(GetPtrField0x2a04_02010828(gs));
    func_0202ae18();
    FieldState* field = func_02012fe4();
    GetGameResources();
    Global02109418* global = GetGlobal02109418_02094d6c();
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
            RemoveSlotValueAndCompact020838c4((struct Slots020838c4*)found, 0x5612);
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
    SetFields020a093c((struct Fields020a093c*)battle->head, (int)battle->headKeys, (int)battle->headValues, 0x98);
    DecrementKeyValue020a0a08((struct KeyMap020a0a08*)battle->head, 0x5612, 0x63);

    int total = 0;
    func_0207c258(battle->roster);
    for (int k = 0; k < 8; k++) {
        unsigned short* words = GetPointerFromArray0xbd0_0207c5f8(battle->roster, k);
        unsigned char* bytes = GetPointerAt0xbf0_0207c60c(battle->roster, k);
        short count = GetShortFromArray0xc10_0207c620(battle->roster, k);
        memcpy(words, &save->rosterWords[total], count * 2);
        memcpy(bytes, &save->rosterBytes[total], count);
        total += count;
        SetByteInArray0xc28_0207c6a8(battle->roster, k, save->rosterFlags[k]);
    }

    memcpy(battle->tactics, save->tactics, sizeof(save->tactics));
    SetFields020a093c((struct Fields020a093c*)battle->tactics, (int)battle->tacticsKeys, (int)battle->tacticsValues, 0x5e);
    battle->valueF6c = save->valueF6c;
    battle->valueF68 = save->valueF68;
    battle->valueF70 = save->valueF70;
    battle->valueF74 = save->valueF74;
    memcpy(battle->extraIds, save->extraIds, sizeof(save->extraIds));
    GameStateLoadView* view = (GameStateLoadView*)gs;
    battle->areaId = save->areaId;
    view->value7e74 = save->areaId;
    memcpy(GetField0x74deForValidIndex_020120a0((char*)gs, 0), save->words, sizeof(save->words));
    SetModeClamped0209ca70(data_02109bf4, save->globalByte);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)g_sePlayer, save->globalByte2);
    battle->byteF7d = save->byteF7d;
    view->byte63dc = save->byte63dc;
    field->savedDir = save->dir;
    field->savedAngle = save->angle;
    field->savedPos = save->pos;
    field->savedValue = save->value;
    field->savedExtra = save->extra;
    field->savedFlag = save->flag;
    field->savedCountA = save->countA;
    field->savedCountB = save->countB;
    field->savedCountC = save->countC;
    view->name74fe = save->name;
    FieldSubState* sub = &field->sub;
    sub->savedPosA = save->posA;
    sub->savedPosB = save->posB;
    memcpy(global->block4a8, save->block4a8, sizeof(save->block4a8));
#if !defined(jpn)
    *inspect = save->inspect;
#endif
    return 1;
}
