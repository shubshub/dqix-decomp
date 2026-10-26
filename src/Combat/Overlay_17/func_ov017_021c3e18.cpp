#if defined(jpn)
enum { Enum_ov017_021c3e18_32608 = 0x7c8c };
#else
enum { Enum_ov017_021c3e18_32608 = 0x7f60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c3e18 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
};

struct Struct_ov017_021c3e18_2 {
    unsigned char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov017_021c3e18_3 {
    unsigned char unknown_0_[3];
    unsigned char unknown_3_;
};

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
unsigned char GameState_GetLeaderIndex(GameState* gs);
void SetVec3_021c3f68(struct Vec3_021c3f68* obj, int x, int y, int z);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetSlot021677d8(void* work, int idx);
void EnqueueEventTag35_021d2ad0(short, int, int, int, unsigned char);
extern "C" int LinkSession_IsHostOrSolo(void* p);

// USA: func_ov017_021c3e18
extern "C" ARM void func_ov017_021c3e18(unsigned char arg) {
    unsigned short* mapId = Zone3D_GetInstance();
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    Party021c3e18* party = (Party021c3e18*)GameState_GetParty(gs);
    Battle021c3e18* battle = (Battle021c3e18*)res->unknown_ptr_3718;
    void* search = LinkSession_GetInstance();
    unsigned char self = GameState_GetLeaderIndex(gs);
    for (int i = 0; i < party->memberCount; i++) {
        unsigned char id = party->memberIds[i];
        if (id == self) {
            continue;
        }
        GameObject* var9 = var1->GetPartyMemberByIndex(var8);
        if (var9 == NULL) {
            continue;
        }
        Vector3i var10 = var9->obj3D_.position_;
        if (*var0 == 10000) {
            func_ov017_021c3f68((Struct_ov017_021c3e18*)&var10, 0xff000, 0, 0xff000);
        }
        if (var4->unknown_3_ != 0) {
            void* var11 = func_ov017_021b8468(var4);
            if (var11 != NULL) {
                var10 = *(Vector3i*)func_ov000_021677d8(var11, var8);
            }
        }
        EnqueueEventTag35_021d2ad0(member->obj3D_.actorIndex_, pos.x, pos.y, pos.z, arg);
    }
    if (LinkSession_IsHostOrSolo(search)) {
        Vector3i pos = *(Vector3i*)((char*)gs + RegionOffset7f60);
        EnqueueEventTag35_021d2ad0(0xce, pos.x, pos.y, pos.z, arg);
    }
}
