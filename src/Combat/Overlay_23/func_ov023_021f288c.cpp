#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"


extern "C" void func_02046380(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
#if !defined(jpn)
extern "C" void func_0204500c(void* obj, char* buffer, int a, int b);
#endif
extern "C" int func_ov023_021f4438(void* obj);
extern "C" int func_ov023_021f4fc8(void);
extern "C" int func_ov023_021f5228(int id);
extern "C" int Scenario_TestFlag(int unused, unsigned char* arr, int index);

struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(struct ArrayContainsByteStruct* s, int val);

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);

struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(struct Struct_ov023_021eeaac_2* s);

struct Struct_ov023_021f288c_2 {
    int counter;
    char pad1[0x12 - 4];
    unsigned char unknown_12_[4];
    char pad2[0x18 - 0x16];
    int id;
};
extern "C" struct Struct_ov023_021f288c_2* _ZZ21inline_ov023_021f4c04vE1s;

struct Struct_ov023_021f288c { unsigned short low : 7; unsigned short unknown_0_7_ : 9; };

#if defined(jpn)
extern "C" void func_0204500c(void*,char*,int);
#endif
// USA: func_ov023_021f288c
extern "C" ARM int func_ov023_021f288c(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x5af4, regionalOffset1=0x17e2, regionalOffset2=0x868, regionalOffset3=0x17fb, regionalOffset4=0x17de, regionalOffset5=0x17df, regionalOffset6=0x5958, Enum_ov023_021f288c_3756=0xe28};
#else
 enum {regionalOffset0=0x5904, regionalOffset1=0x19b2, regionalOffset2=0x998, regionalOffset3=0x19ca, regionalOffset4=0x19ae, regionalOffset5=0x19af, regionalOffset6=0x5768, Enum_ov023_021f288c_3756=0xeac};
#endif
    char var0[0x100];
    GameState* battleStruct = GameState::GetInstance();
    struct Struct_ov023_021f288c_2* g = _ZZ21inline_ov023_021f4c04vE1s;
    int id = g->id;
    int state = MessageSystem_GetInstance();
    unsigned char* stateObj = (unsigned char*)state;
#if defined(jpn)

#else
    func_02046380();
#endif

    int flag8;
    if (g->counter == 0) {
        char* e1 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0xd);
#if defined(jpn)
        sprintf(var0, e1, ((struct Struct_ov023_021f288c*)(obj + id * 0x54 + 0x5900 + 0x8c))->unknown_0_7_);
#else
        sprintf(var0, e1);
#endif

        char* e2 = (char*)func_02072a68((struct TableA68*)(obj + regionalOffset0), 0x22);
        strcat(var0, e2);
#if defined(jpn)

#else
        struct Struct_ov023_021f288c* pb = (struct Struct_ov023_021f288c*)(obj + id * 0x54 + 0x5700 + 0x9c);
        int var10 = pb->unknown_0_7_;
        func_020465c0((struct StoreStruct*)stateObj, 0, var10);
#endif

#if defined(jpn)
        func_0204500c(stateObj, var0, 1);
#else
        func_0204500c(stateObj, var0, 1, 0xe3);
#endif

        stateObj[regionalOffset1] = 0;
        *(int*)(stateObj + regionalOffset2) = 1;
        g->counter = g->counter + 1;
    } else if (g->counter == 1) {
        void* p2a04 = GameState_GetParty(battleStruct);
        flag8 = 0;
        if (func_02086ef0((struct ArrayContainsByteStruct*)p2a04, id)) {
            if (func_ov023_021f5228(id)) {
                flag8 = 1;
                void* base = Scenario_GetInstance();
                if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, 0x119c)) {
                    stateObj[regionalOffset3] = 0;
                }
            }
        }
        int found = 0;
        int i;
        for (i = g->id + 1; i < 4; i++) {
            if (g->unknown_12_[i] != 0) {
                found = 1;
                break;
            }
        }
        int var15 = func_ov023_021f4438(obj);
        if (found == 0 && var15 == 0 && *(int*)(obj + regionalOffset6) == 0) {
            stateObj[regionalOffset4] = 0;
            stateObj[regionalOffset3] = 0;
            stateObj[regionalOffset5] = 0;
        }
        if (func_ov023_021f4fc8()) {
            func_ov023_021eefac((struct Struct_ov023_021eeaac_2*)g);
            return flag8 ? 8 : 7;
        }
    }
    return *(int*)(obj + Enum_ov023_021f288c_3756);
}
