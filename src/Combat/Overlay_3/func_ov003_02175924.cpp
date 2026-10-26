#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { Enum_ov003_02175924_4175 = 0xfcb };
enum { kRegion874 = 0x7f0 };
enum { Enum_ov003_02175924_4156 = 0xfb8 };
#else
enum { kRegion103a = 0x103a };
enum { Enum_ov003_02175924_4175 = 0x104f };
enum { kRegion874 = 0x874 };
enum { Enum_ov003_02175924_4156 = 0x103c };
#endif

#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
struct ItemTable;
struct Element020de650;
extern "C" struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
extern "C" unsigned int func_ov003_02175898(char* obj, void* s);
extern "C" void func_ov003_02176798(void* obj);

// USA: func_ov003_02175924
extern "C" ARM int func_ov003_02175924(char* obj) {
    void* ptrField = GameState_GetParty(GameState::GetInstance());
    short key = *(short*)(obj + kRegion103a);
    struct Element020de650* elem = ItemTable_Find((struct ItemTable*)(obj + kRegion874), key);
    if (elem == 0) {
        return 0;
    }
    unsigned int ratio = func_ov003_02175898(obj, elem);
    unsigned int var4 = *(unsigned char*)(obj + Enum_ov003_02175924_4156) * ratio;
    unsigned int available = *(unsigned int*)((char*)ptrField + 0xf6c);
    if (available < var4) {
        return 0;
    }
    available = available - var4;
    *(unsigned int*)((char*)ptrField + 0xf6c) = available;
    func_ov003_02176798(obj);
    *(unsigned char*)(obj + Enum_ov003_02175924_4175) = 1;
    return 1;
}
