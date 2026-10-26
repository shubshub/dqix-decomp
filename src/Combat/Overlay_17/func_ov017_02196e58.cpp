#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"

void PushInputLogA_020a1df8(int value);
int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" Zone3D* Zone3D_GetInstance(void);
extern "C" void func_ov004_0216fa08(void* node);
extern "C" void func_ov004_0216fa74(void* node, unsigned char value);
extern "C" int func_ov004_0216f990(int mode, int key, int flag);
extern "C" void func_ov017_021b6f18(void* node);
void InitStruct_02196c08(unsigned char* obj);
extern "C" bool func_ov017_021b6e70(void* msg, int id);
extern "C" void func_ov017_021b7104(void* node, void* msg);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct Struct_ov017_02196e58_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    int unknown_14_;
};

struct Struct_ov017_02196e58 {
#if defined(jpn)
    unsigned char unknown_0_[0x34a6];
#else
    unsigned char unknown1_0_[0x36b6];
#endif
    unsigned short unknown_36b6_;
    unsigned char unknown_36b8_[0x36fc - 0x36b8];
    struct Struct_0201bdac_2* unknown_36fc_;
    unsigned char unknown_3700_[0x3718 - 0x3700];
    struct Struct_0201bdac* unknown_3718_;
#if defined(jpn)
    unsigned char unknown_350c_[0x3954 - 0x350c];
#else
    unsigned char unknown_371c_[0x3b74 - 0x371c];
#endif
    struct Struct_0201bdac* unknown_3b74_;
};

// USA: func_ov017_02196e58
extern "C" ARM void func_ov017_02196e58(struct Work02196e58* work) {
    GameState* bs = GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    GameObject* monster = bs->GetFieldMonsterByIndex(work->monsterIndex);
    if (monster == NULL) {
        return;
    }
    func_020a1df8(4);
    func_ov004_0216fa08(arg0->unknown_3b74_);
    *(unsigned short*)((unsigned char*)arg0->unknown_3b74_ + 8) = arg0->unknown_36b6_;
    func_ov004_0216fa74(arg0->unknown_3b74_, 1);
    func_020469b4(arg0->unknown_36fc_, arg0->unknown_3b74_);
    func_ov017_021b6f18(arg0->unknown_3718_);

    struct NodeMsg msg;
    InitStruct_02196c08((unsigned char*)&msg);
    msg.kind = 1;
    msg.actor = GameState_GetProtagonistIndex(bs);
    msg.value = *(unsigned short*)((unsigned char*)monster + 0x16a);
    msg.id = work->monsterIndex;
    msg.f12 = lighting->timeOfDayIndex_;

    Zone3D* zone = Zone3D_GetInstance();
    ActiveGrottoClass* grotto = NULL;
    if (zone != NULL) {
#if defined(jpn)
        var5 = &var4->grotto_;
#else
        var5 = &var4->grotto_;
#endif
    }
    DetailedTreasureMapData* var6 = NULL;
    if (var5 != NULL) {
        var6 = var5->GetDetailedData();
    }
    func_ov017_021b6e70(&var3, var3.unknown_2_);
    if (var3.unknown_c_) {
        if (var6 != NULL) {
            var3.unknown_8_ = func_ov004_0216f990(1, var6->regular_.bossMonsterID_, 0);
        }
    } else if (var3.unknown_d_ && var6 != NULL) {
        var3.unknown_8_ = func_ov004_0216f990(2, var6->legacy_.bossID_, var6->legacy_.stats_.alternateVersion);
    }
    func_ov017_021b7104(arg0->unknown_3718_, &var3);
    func_020469b4(arg0->unknown_36fc_, arg0->unknown_3718_);
}
