#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct Struct_0202bad4;
struct Struct_0202bad4_2;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void* ptr);
extern "C" void LinkSession_UpdateMemberCount(void* ptr);
extern "C" unsigned short LinkSession_GetConnectedAids(struct SearchStruct* obj);
extern "C" int func_0202baec(void* search);
extern "C" struct Struct_0202bad4* func_0202bad4(struct Struct_0202bad4_2* base, int index);
extern "C" void LinkSession_AddMember(struct SearchStruct* obj, int value);

struct Struct_ov003_02171640 {
    unsigned char state;
    char pad1[3];
    unsigned int timer;
    char pad8[0x199 - 8];
    signed char selected;
};

// USA: func_ov003_02171640
extern "C" ARM void func_ov003_02171640(struct Struct_ov003_02171640* obj) {
    GameState* battle = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    unsigned int var2 = battle->GetEffectiveDeltaTime();

    if (var2 < obj->timer) {
        obj->timer -= var2;
        unsigned short mask = LinkSession_GetConnectedAids((struct SearchStruct*)search);
        int count = func_0202baec(search);
        for (int i = 1; i < count; i++) {
            if (mask & (1 << i)) {
                func_0202bad4((struct Struct_0202bad4_2*)search, i);
                obj->selected = i;
                LinkSession_AddMember((struct SearchStruct*)search, (unsigned char)i);
                LinkSession_UpdateMemberCount(search);
                obj->state = 2;
                return;
            }
        }
    } else {
        obj->timer = 0;
        LinkSession_End(search);
        obj->state = 4;
    }
}
