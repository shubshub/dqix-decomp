#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0202b2f0;
struct Struct_0202bad4;
struct Struct_0202bad4_2;

extern "C" void* LinkSession_GetInstance(void);
extern "C" void LinkSession_End(void* ptr);
extern "C" void LinkSession_UpdateMemberCount(void* ptr);
unsigned short LinkSession_GetConnectedAids(struct SearchStruct* obj);
int GetConstant10_0202baec(void* search);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
void LinkSession_AddMember(struct SearchStruct* obj, int value);

struct Struct_ov003_02171640 {
    unsigned char unknown_0_;
    char unknown_1_[3];
    unsigned int unknown_4_;
    char unknown_8_[0x199 - 8];
    signed char unknown_199_;
};

// USA: func_ov003_02171640
extern "C" ARM void func_ov003_02171640(struct Obj02171640* obj) {
    GameState* battle = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    unsigned int dt = battle->GetEffectiveDeltaTime();

    if (dt < obj->timer) {
        obj->timer -= dt;
        unsigned short mask = LinkSession_GetConnectedAids((struct SearchStruct*)search);
        int count = GetConstant10_0202baec(search);
        for (int i = 1; i < count; i++) {
            if (mask & (1 << i)) {
                GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)search, i);
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
