#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"


int MessageSystem_GetInstance(void);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(struct ArrayContainsByteStruct* s, int val);
struct Holder0209a9dc;
struct Entry0209a9dc { unsigned short id; unsigned short pad; };
struct Entry0209a9dc* FindEntryById0209a9dc(struct Holder0209a9dc* h, int i);
void* SearchBothTables02079e2c(char* p, int key);
struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
void NameText_InitFromPartyMember(void* obj, int combatantId);
struct Obj02046574;
void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2);
#else
extern "C" void func_0204500c(void* arg0, char* arg1, int arg2, int arg3);
#endif

int GetFieldAt0x150_02053c6c(unsigned char* obj);
int CheckThresholdOverAny_021f5228(int id);
extern "C" void* Scenario_GetInstance(void);
int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(struct Struct_ov023_021eeaac_2* arg0);
extern "C" void func_ov017_021ccea4(int arg0, unsigned char* arg1, int arg2);

struct Struct_ov023_021f2368 { unsigned char unknown_0_[0x14]; };

struct Struct_ov023_021f2368_2 {
    int unknown_0_;
    char unknown_4_[0x12 - 0x4];
    unsigned char unknown_12_[4];
    char unknown_16_[0x18 - 0x16];
    int unknown_18_;
    struct Struct_ov023_021f2368 unknown_1c_[4];
    unsigned char unknown_6c_[4];
    int unknown_70_;
    char unknown_74_[0xe5 - 0x74];
    signed char unknown_e5_;
};

extern "C" struct Struct_ov023_021f2368_2* _ZZ21inline_ov023_021f4c04vE1s;

struct Struct_ov023_021f2368_3 { unsigned short unknown_0_0_ : 7; unsigned short unknown_0_7_ : 9; };

// USA: func_ov023_021f2368
extern "C" ARM int func_ov023_021f2368(unsigned char* arg0) {
#if defined(jpn)
 enum {Enum_ov023_021f2368_23284=0x5af4, Enum_ov023_021f2368_6578=0x17e2, Enum_ov023_021f2368_2456=0x868, Enum_ov023_021f2368_22272=0x5900, Enum_ov023_021f2368_156=0x8c, Enum_ov023_021f2368_6602=0x17fb, Enum_ov023_021f2368_22376=0x5958, Enum_ov023_021f2368_6574=0x17de, Enum_ov023_021f2368_6575=0x17df, Enum_ov023_021f2368_3756=0xe28};
#else
 enum {Enum_ov023_021f2368_22788=0x5904, Enum_ov023_021f2368_6578=0x19b2, Enum_ov023_021f2368_2456=0x998, Enum_ov023_021f2368_22272=0x5700, Enum_ov023_021f2368_156=0x9c, Enum_ov023_021f2368_6602=0x19ca, Enum_ov023_021f2368_22376=0x5768, Enum_ov023_021f2368_6574=0x19ae, Enum_ov023_021f2368_6575=0x19af, Enum_ov023_021f2368_3756=0xeac};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct GlobalState021f2368* g = _ZZ17GetGlobal021ffefcvE1s;
    int state = MessageSystem_GetInstance();
    unsigned char* stateObj = (unsigned char*)state;
    (int)BackgroundLoader::GetInstance();
    int id = g->id;
    int contains = ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(battleStruct), id);

    if (var1->unknown_0_ == 0) {
        struct Struct_0209a9dc_3* var6 = func_0209a9dc((struct Struct_0209a9dc_2*)((char*)var1 + 0xf0),
            var1->unknown_1c_[var4].unknown_0_[var1->unknown_70_]);
        if (var6 != NULL) {
            short var7 = *(short*)((char*)var6 + 2);
            Struct_02108e10* var8 = func_020797dc();
            void* var9 = func_02079e2c((char*)var8, var7);
            if (var9 != NULL) {
#if defined(jpn)
                GameObject* var10;
                if ((var10 = func_0200ff1c(var0, var4)) != 0 && var5 != 0) {
#else
                if (func_0200ff1c(var0, var4) != 0 && var5 != 0) {
#endif

#if defined(jpn)
                    char* var11 = *(char**)((char*)var10 + 0x134);
                    char var12[0x100];
                    char* var13 = (char*)func_02072a68((struct Struct_02072a68_2*)(arg0 + Enum_ov023_021f2368_23284), 0xc);
                    sprintf(var12, var13, var11, *(char**)var9);
                    char* var14 = (char*)func_02072a68((struct Struct_02072a68_2*)(arg0 + Enum_ov023_021f2368_23284), 0x22);
                    strcat(var12, var14);
                    func_0204500c(var3, var12, 1);

#else
                    char buf1[0xc];
                    char msgBuf[0x80];
                    char* e1 = (char*)FindEntryByKey_02072a68((struct TableA68*)(obj + regionalOffset0), 0xc);
                    sprintf(msgBuf, e1);
                    char* e2 = (char*)FindEntryByKey_02072a68((struct TableA68*)(obj + regionalOffset0), 0x22);
                    strcat(msgBuf, e2);
                    NameText_InitFromPartyMember(buf1, id);
                    *(void**)(stateObj + 0x10) = buf1;
                    char* name = *(char**)found;
                    MessageSystem_SetStringArgument((struct Obj02046574*)stateObj, 1, name);
                    func_0204500c(stateObj, msgBuf, 1, 0xe3);

#endif
                    var3[Enum_ov023_021f2368_6578] = 0;
                    *(int*)(var3 + Enum_ov023_021f2368_2456) = 1;
                }
            }
        }
        g->field70 = g->field70 + 1;
        if (g->byteArr6c[id] <= g->field70) {
            void* p2a04b = GameState_GetParty(battleStruct);
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
            unsigned char* field150 = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
            struct PctBits021f2368* pb = (struct PctBits021f2368*)(obj + id * 0x54 + regionalOffset3 + regionalOffset4);
            if (pb->pct != 0) {
                g->e5 = 0xc;
            } else if (ArrayContainsByte_02086ef0((struct ArrayContainsByteStruct*)p2a04b, id) &&
                       CheckThresholdOverAny_021f5228(id) != 0 &&
                       *(unsigned short*)(field150 + 0x564) != 0) {
                g->e5 = 8;
                void* base = Scenario_GetInstance();
                if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[regionalOffset5] = 0;
                }
            } else {
                var1->unknown_e5_ = 7;
                int var25 = 0;
                int var26;
                for (var26 = var1->unknown_18_ + 1; var26 < 4; var26++) {
                    if (var1->unknown_12_[var26] != 0) {
                        var25 = 1;
                        break;
                    }
                }
                int var27 = func_ov023_021f4438(arg0);
                if (var25 == 0 && var27 == 0 && *(int*)(arg0 + Enum_ov023_021f2368_22376) == 0) {
                    var3[Enum_ov023_021f2368_6574] = 0;
                    var3[Enum_ov023_021f2368_6602] = 0;
                    var3[Enum_ov023_021f2368_6575] = 0;
                }
            }
        } else {
            var1->unknown_e5_ = -1;
        }
        var1->unknown_0_ = var1->unknown_0_ + 1;
    } else if (var1->unknown_0_ == 1) {
        if (func_ov023_021f4fc8() != 0) {
            signed char var28 = var1->unknown_e5_;
            if (var28 >= 0) {
                func_ov023_021eefac((struct Struct_ov023_021eeaac_2*)var1);
                func_ov017_021ccea4(var4, (unsigned char*)&var1->unknown_1c_[var4], var1->unknown_6c_[var4]);
                return var28;
            } else {
                var1->unknown_0_ = 0;
            }
        }
    }
    return *(int*)(arg0 + Enum_ov023_021f2368_3756);
}
