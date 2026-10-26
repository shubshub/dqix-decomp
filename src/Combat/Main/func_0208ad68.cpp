#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0208ad68_1744 = 0x4c0 };
#else
enum { Enum_0208ad68_1744 = 0x6d0 };
#endif

#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_020482e0_2 {
    unsigned int flags;
    unsigned short count;
};
struct Struct_020482e0 {
    char pad[0x130];
    struct Struct_020482e0_2* sub;
};
extern "C" int func_020482e0(struct Struct_020482e0* c, int amount, int force);

extern "C" void func_02026f08(unsigned char* base, int index, int value);
extern "C" void func_02026f20(int a, int index);

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_0208ad68
extern "C" ARM void func_0208ad68(void* obj, int id) {
    GameState* bs = GameState::GetInstance();
    char* base = (char*)GetGameResources() + 0x3000;
    int* target = *(int**)(base + Enum_0208ad68_1744);
    struct Struct_020482e0* c = (struct Struct_020482e0*)bs->GetPartyMemberByIndex(id);
    unsigned char amount = ((unsigned char*)obj)[5];
    unsigned short var5 = c->sub->count;
    func_020482e0(c, amount, 0);
    unsigned short var6 = c->sub->count;
    if (var5 != var6) {
        func_02026f08((unsigned char*)target, id, 1);
        func_02026f20((int)target, id);
    }
    if (LinkSession_IsActive((int*)LinkSession_GetInstance())) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
}
