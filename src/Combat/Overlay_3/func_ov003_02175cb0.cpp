#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_02175cb0_4154 = 0xfb6 };
enum { Enum_ov003_02175cb0_4175 = 0xfcb };
enum { Enum_ov003_02175cb0_2164 = 0x7f0 };
enum { Enum_ov003_02175cb0_4156 = 0xfb8 };
#else
enum { Enum_ov003_02175cb0_4154 = 0x103a };
enum { Enum_ov003_02175cb0_4175 = 0x104f };
enum { Enum_ov003_02175cb0_2164 = 0x874 };
enum { Enum_ov003_02175cb0_4156 = 0x103c };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct ItemTable;
struct Element020de650 {
    char pad0[8];
    unsigned int kind : 4;
    char pad[0x18 - 0xc];
    short key;
};

struct Element020de650* ItemTable_Find(struct ItemTable* c, int key);
void* GameState_GetParty(GameState* battleStruct);
void ItemTable_Construct(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" void func_0207d134(void* buf, int key, int amount);
extern "C" void func_0207cf30(void* buf, int key, int amount, int arg);

// USA: func_ov003_02175cb0
extern "C" ARM int func_ov003_02175cb0(char* self, int arg) {
    *(unsigned char*)(self + kRegion104f) = 0;
    struct Element020de650* elem =
        ItemTable_Find((struct ItemTable*)(self + kRegion874), *(short*)(self + kRegion103a));
    if (elem == NULL) {
        return 0;
    }

    GameState_GetParty(GameState::GetInstance());

    char buf[0x38];
    ((SafeAllocator*)buf)->ResetAllocatorPointer();
    ItemTable_Construct(buf + 0x14);
    InitStruct0207cbe8(buf);
    InitStruct0207cbe8(buf);
    *(void**)(buf + 0x2c) = self + kRegion874;
    int ok = elem->kind <= 7;
    if (ok) {
        func_0207d134(buf, elem->key, *(signed char*)(self + kRegion103c));
    } else {
        func_0207cf30(var1, var0->unknown_16_, *(unsigned char*)(arg0 + Enum_ov003_02175cb0_4156), arg1);
    }
    func_0207cc0c(var1);
    return 0;
}
