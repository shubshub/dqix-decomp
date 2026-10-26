#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"

extern "C" void func_020a1df8(int value);
extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void func_ov004_0216fa08(void* node);
extern "C" void func_ov004_0216fa74(void* node, unsigned char value);
extern "C" int func_ov004_0216f990(int mode, int key, int flag);
extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* msg, int id);
extern "C" void func_ov017_021b7104(void* node, void* msg);
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_020469b4(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_02196e58_2 {
    unsigned char kind;
    unsigned char actor;
    unsigned short id;
    unsigned short value;
    unsigned short unknown_6_;
    int f8;
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char unknown_13_;
    int f14;
};

struct Struct_ov017_02196e58 {
#if defined(jpn)
    unsigned char pad0[0x34a6];
#else
    unsigned char pad0[0x36b6];
#endif
    unsigned short monsterIndex;
    unsigned char unknown_36b8_[0x36fc - 0x36b8];
    struct TailList020469b4* list;
    unsigned char unknown_3700_[0x3718 - 0x3700];
    struct TailNode020469b4* node;
#if defined(jpn)
    unsigned char unknown_350c_[0x3954 - 0x350c];
#else
    unsigned char unknown_371c_[0x3b74 - 0x371c];
#endif
    struct TailNode020469b4* unknown_3b74_;
};

// USA: func_ov017_02196e58
extern "C" ARM void func_ov017_02196e58(struct Struct_ov017_02196e58* work) {
    GameState* bs = GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    GameObject* monster = bs->GetFieldMonsterByIndex(work->monsterIndex);
    if (monster == NULL) {
        return;
    }
    func_020a1df8(4);
    func_ov004_0216fa08(work->unknown_3b74_);
    *(unsigned short*)((unsigned char*)work->unknown_3b74_ + 8) = work->monsterIndex;
    func_ov004_0216fa74(work->unknown_3b74_, 1);
    func_020469b4(work->list, work->unknown_3b74_);
    func_ov017_021b6f18(work->node);

    struct Struct_ov017_02196e58_2 msg;
    func_ov017_02196c08((unsigned char*)&msg);
    msg.kind = 1;
    msg.actor = GameState_GetProtagonistIndex(bs);
    msg.value = *(unsigned short*)((unsigned char*)monster + 0x16a);
    msg.id = work->monsterIndex;
    msg.f12 = lighting->timeOfDayIndex_;

    Zone3D* zone = Zone3D_GetInstance();
    ActiveGrottoClass* grotto = NULL;
    if (zone != NULL) {
#if defined(jpn)
        grotto = &zone->grotto_;
#else
        grotto = &zone->grotto_;
#endif
    }
    DetailedTreasureMapData* detail = NULL;
    if (grotto != NULL) {
        detail = grotto->GetDetailedData();
    }
    func_ov017_021b6e70(&msg, msg.id);
    if (msg.fc) {
        if (detail != NULL) {
            msg.f8 = func_ov004_0216f990(1, detail->regular_.bossMonsterID_, 0);
        }
    } else if (msg.unknown_d_ && detail != NULL) {
        msg.f8 = func_ov004_0216f990(2, detail->legacy_.bossID_, detail->legacy_.stats_.alternateVersion);
    }
    func_ov017_021b7104(work->node, &msg);
    func_020469b4(work->list, work->node);
}
