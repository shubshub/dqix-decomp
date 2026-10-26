#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"


extern "C" int MessageSystem_GetInstance(void);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);
struct Struct_0209a9dc_2;
struct Struct_0209a9dc_3 { unsigned short id; unsigned short pad; };
extern "C" struct Struct_0209a9dc_3* func_0209a9dc(struct Struct_0209a9dc_2* h, int i);
extern "C" void* func_02079e2c(char* p, int key);
struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" void NameText_InitFromPartyMember(void* obj, int combatantId);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a);
#else
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_ov023_021f5228(int id);
extern "C" void* Scenario_GetInstance(void);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(struct Struct_ov023_021eeaac_2* s);
extern "C" void func_ov017_021ccea4(int a, unsigned char* b, int c);

struct Struct_ov023_021f2368 { unsigned char unknown_0_[0x14]; };

struct Struct_ov023_021f2368_2 {
    int counter;
    char pad0[0x12 - 0x4];
    unsigned char unknown_12_[4];
    char pad1[0x18 - 0x16];
    int id;
    struct Struct_ov023_021f2368 unknown_1c_[4];
    unsigned char unknown_6c_[4];
    int unknown_70_;
    char pad2[0xe5 - 0x74];
    signed char unknown_e5_;
};

extern "C" struct Struct_ov023_021f2368_2* _ZZ21inline_ov023_021f4c04vE1s;

struct Struct_ov023_021f2368_3 { unsigned short low : 7; unsigned short unknown_0_7_ : 9; };

// USA: func_ov023_021f2368
extern "C" ARM int func_ov023_021f2368(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x5af4, regionalOffset1=0x17e2, regionalOffset2=0x868, regionalOffset3=0x5900, regionalOffset4=0x8c, regionalOffset5=0x17fb, regionalOffset6=0x5958, Enum_ov023_021f2368_6574=0x17de, Enum_ov023_021f2368_6575=0x17df, regionalOffset9=0xe28};
#else
 enum {regionalOffset0=0x5904, regionalOffset1=0x19b2, regionalOffset2=0x998, regionalOffset3=0x5700, regionalOffset4=0x9c, regionalOffset5=0x19ca, regionalOffset6=0x5768, Enum_ov023_021f2368_6574=0x19ae, Enum_ov023_021f2368_6575=0x19af, regionalOffset9=0xeac};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct Struct_ov023_021f2368_2* g = _ZZ21inline_ov023_021f4c04vE1s;
    int state = MessageSystem_GetInstance();
    unsigned char* stateObj = (unsigned char*)state;
    (int)BackgroundLoader::GetInstance();
    int id = g->id;
    int contains = func_02086ef0((struct ArrayContainsByteStruct*)GameState_GetParty(battleStruct), id);

    if (g->counter == 0) {
        struct Struct_0209a9dc_3* e = func_0209a9dc((struct Struct_0209a9dc_2*)((char*)g + 0xf0),
            g->unknown_1c_[id].unknown_0_[g->unknown_70_]);
        if (e != NULL) {
            short val = *(short*)((char*)e + 2);
            ActionDataTables* tbl = func_020797dc();
            void* found = func_02079e2c((char*)tbl, val);
            if (found != NULL) {
#if defined(jpn)
                GameObject* var10;
                if ((var10 = func_0200ff1c(battleStruct, id)) != 0 && contains != 0) {
#else
                if (func_0200ff1c(battleStruct, id) != 0 && contains != 0) {
#endif

#if defined(jpn)
                    char* var11 = *(char**)((char*)var10 + 0x134);
                    char var12[0x100];
                    char* e1 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0xc);
                    sprintf(var12, e1, var11, *(char**)found);
                    char* e2 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0x22);
                    strcat(var12, e2);
                    func_0204500c(stateObj, var12, 1);

#else
                    char buf1[0xc];
                    char var16[0x80];
                    char* e1 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0xc);
                    sprintf(var16, e1);
                    char* e2 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0x22);
                    strcat(var16, e2);
                    NameText_InitFromPartyMember(buf1, id);
                    *(void**)(stateObj + 0x10) = buf1;
                    char* name = *(char**)found;
                    MessageSystem_SetStringArgument((struct Obj02046574*)stateObj, 1, name);
                    func_0204500c(stateObj, var16, 1, 0xe3);

#endif
                    stateObj[regionalOffset1] = 0;
                    *(int*)(stateObj + regionalOffset2) = 1;
                }
            }
        }
        g->unknown_70_ = g->unknown_70_ + 1;
        if (g->unknown_6c_[id] <= g->unknown_70_) {
            void* p2a04b = GameState_GetParty(battleStruct);
            GameObject* combatant = func_0200ff1c(battleStruct, id);
            unsigned char* field150 = (unsigned char*)func_02053c6c((unsigned char*)combatant);
            struct Struct_ov023_021f2368_3* pb = (struct Struct_ov023_021f2368_3*)(obj + id * 0x54 + regionalOffset3 + regionalOffset4);
            if (pb->unknown_0_7_ != 0) {
                g->unknown_e5_ = 0xc;
            } else if (func_02086ef0((struct ArrayContainsByteStruct*)p2a04b, id) &&
                       func_ov023_021f5228(id) != 0 &&
                       *(unsigned short*)(field150 + 0x564) != 0) {
                g->unknown_e5_ = 8;
                void* base = Scenario_GetInstance();
                if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[regionalOffset5] = 0;
                }
            } else {
                g->unknown_e5_ = 7;
                int found2 = 0;
                int i;
                for (i = g->id + 1; i < 4; i++) {
                    if (g->unknown_12_[i] != 0) {
                        found2 = 1;
                        break;
                    }
                }
                int var27 = func_ov023_021f4438(obj);
                if (found2 == 0 && var27 == 0 && *(int*)(obj + regionalOffset6) == 0) {
                    stateObj[Enum_ov023_021f2368_6574] = 0;
                    stateObj[regionalOffset5] = 0;
                    stateObj[Enum_ov023_021f2368_6575] = 0;
                }
            }
        } else {
            g->unknown_e5_ = -1;
        }
        g->counter = g->counter + 1;
    } else if (g->counter == 1) {
        if (func_ov023_021f4fc8() != 0) {
            signed char var28 = g->unknown_e5_;
            if (var28 >= 0) {
                func_ov023_021eefac((struct Struct_ov023_021eeaac_2*)g);
                func_ov017_021ccea4(id, (unsigned char*)&g->unknown_1c_[id], g->unknown_6c_[id]);
                return var28;
            } else {
                g->counter = 0;
            }
        }
    }
    return *(int*)(obj + regionalOffset9);
}
