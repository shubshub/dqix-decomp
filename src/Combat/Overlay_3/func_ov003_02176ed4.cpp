#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion874 = 0x7f0 };
enum { kRegion89c = 0x818 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion874 = 0x874 };
enum { kRegion89c = 0x89c };
#endif

#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState*);

struct Struct_0207fdcc_2;
extern "C" void func_02080c20(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c04(struct Struct_0207fdcc_2* obj, int key);
extern "C" void func_02080c68(void* obj, int id, int value);

struct ItemTable;
struct Element020de650 {
    char pad[8];
    unsigned int nibble : 4;
};
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);

struct Obj02086aec;
extern "C" short Party_CountItem(struct Obj02086aec* obj, int key);

struct Struct_02080fa8;
extern "C" void func_02080fa8(struct Struct_02080fa8* obj, int id, int value);

extern "C" void func_020813ec(void* obj, int key);

// USA: func_ov003_02176ed4
extern "C" ARM void func_ov003_02176ed4(char* self) {
    struct Struct_0207fdcc_2* var0 = *(struct Struct_0207fdcc_2**)(self + kRegion89c);
    struct Obj02086aec* battleSum = (struct Obj02086aec*)GameState_GetParty(GameState::GetInstance());
    func_02080c20(var0, 8);
    func_02080c68(var0, 8, 0);
    int flag = 0;
    struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(self + kRegion874), *(short*)(self + kRegion103a));
    if (elem != NULL) {
        int t = (elem->nibble <= 7) ? 1 : flag;
        flag = (t != 0);
    }
    if (flag != 0) {
        short key = *(short*)(self + kRegion103a);
        int sum = Party_CountItem(battleSum, key);
        func_02080fa8((struct Struct_02080fa8*)var0, 0x54, sum);
    } else {
        func_02080c04(var0, 8);
    }
    func_020813ec(var0, 8);
}
