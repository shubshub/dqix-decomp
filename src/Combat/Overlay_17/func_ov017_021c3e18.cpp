#if defined(jpn)
enum { Enum_ov017_021c3e18_32608 = 0x7c8c };
#else
enum { Enum_ov017_021c3e18_32608 = 0x7f60 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021c3e18 {
    int x;
    int y;
    int z;
};

struct Party021c3e18 {
    unsigned char unk0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

struct Struct_ov017_021c3e18_3 {
    unsigned char unk0[3];
    unsigned char active;
};

extern "C" unsigned short* Zone3D_GetInstance(void);
extern "C" void* LinkSession_GetInstance(void);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* gs);
extern "C" void func_ov017_021c3f68(struct Struct_ov017_021c3e18* obj, int x, int y, int z);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* func_ov000_021677d8(void* work, int idx);
extern "C" void func_ov017_021d2ad0(short, int, int, int, unsigned char);
extern "C" int LinkSession_IsHostOrSolo(void* p);

// USA: func_ov017_021c3e18
extern "C" ARM void func_ov017_021c3e18(unsigned char arg) {
    unsigned short* mapId = Zone3D_GetInstance();
    GameState* gs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    Party021c3e18* party = (Party021c3e18*)GameState_GetParty(gs);
    Struct_ov017_021c3e18_3* battle = (Struct_ov017_021c3e18_3*)res->unknown_ptr_3718;
    void* search = LinkSession_GetInstance();
    unsigned char self = GameState_GetLeaderIndex(gs);
    for (int i = 0; i < party->memberCount; i++) {
        unsigned char id = party->memberIds[i];
        if (id == self) {
            continue;
        }
        GameObject* member = gs->GetPartyMemberByIndex(id);
        if (member == NULL) {
            continue;
        }
        Vector3i pos = member->obj3D_.position_;
        if (*mapId == 10000) {
            func_ov017_021c3f68((Struct_ov017_021c3e18*)&pos, 0xff000, 0, 0xff000);
        }
        if (battle->active != 0) {
            void* work = func_ov017_021b8468(battle);
            if (work != NULL) {
                pos = *(Vector3i*)func_ov000_021677d8(work, id);
            }
        }
        func_ov017_021d2ad0(member->obj3D_.actorIndex_, pos.x, pos.y, pos.z, arg);
    }
    if (LinkSession_IsHostOrSolo(search)) {
        Vector3i pos = *(Vector3i*)((char*)gs + Enum_ov017_021c3e18_32608);
        func_ov017_021d2ad0(0xce, pos.x, pos.y, pos.z, arg);
    }
}
