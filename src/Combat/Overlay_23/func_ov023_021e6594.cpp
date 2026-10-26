#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int GameState_GetStoryChapter(char* obj);
struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

struct Struct_ov023_021e6594 {
    unsigned int : 29;
    unsigned int unknown_3_5_ : 1;
    unsigned int : 2;
    signed int : 9;
    signed int field9 : 10;
    signed int : 13;
};

struct Struct_ov023_021e6594_2 {
    char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char : 7;
#if defined(jpn)
    char pad1[0x8b8 - 0x49d];
#else
    char pad1[0x950 - 0x49d];
#endif

    int unknown_950_;
};

// USA: func_ov023_021e6594
extern "C" ARM void func_ov023_021e6594(char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x543c, regionalOffset1=0x1314, regionalOffset2=0x144, regionalOffset3=0x1458, regionalOffset4=0x1498};
#else
 enum {regionalOffset0=0x569c, regionalOffset1=0x133c, regionalOffset2=0x150, regionalOffset3=0x1400, regionalOffset4=0x1440};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct Struct_ov023_021e6594* ext = (struct Struct_ov023_021e6594*)((char*)battleStruct + regionalOffset0);
    if (!ext->unknown_3_5_) {
        void* entry;
        if (GameState_GetStoryChapter((char*)battleStruct) == 1) {
            entry = func_02072a68((struct TableA68*)(obj + regionalOffset1), 0x50e9);
        } else {
            LinkSession_GetInstance();
            GameObject* combatant = battleStruct->GetProtagonist();
            struct Struct_ov023_021e6594_2* sub = *(struct Struct_ov023_021e6594_2**)((char*)combatant + regionalOffset2);
#if defined(jpn)
            int key = sub->unknown_950_ + 0x50dc;
#else
            int key = 0x50dc;
            if (sub->bit0 == 1) key += 0x32;
            key += sub->unknown_950_;
#endif

            entry = func_02072a68((struct TableA68*)(obj + regionalOffset1), (short)key);
        }
        memset(obj + regionalOffset3, 0, 0x40);
        int len = strlen((char*)entry);
        memcpy(obj + regionalOffset3, (char*)entry, len);
    }
    if (ext->field9 != 0x12c) return;
    memset(obj + regionalOffset4, 0, 0x40);
    void* entry2 = func_02072a68((struct TableA68*)(obj + regionalOffset1), 0x283c);
    int len2 = strlen((char*)entry2);
    memcpy(obj + regionalOffset4, (char*)entry2, len2);
}
