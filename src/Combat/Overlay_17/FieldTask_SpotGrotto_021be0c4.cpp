#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021be0c4 { unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; int unknown_8_, unknown_c_; };
struct Struct_02046574_2 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    char* unknown_5c_;
#if defined(jpn)
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown_60_[0x938];
#endif
    int unknown_998_;
    char unknown_99c_[4];
    int unknown_9a0_;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x100a];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[3];
    unsigned char unknown_19b2_;
};
struct Struct_ov017_021be0c4_2 {
#if defined(jpn)
    char unknown_0_[0x26a4];
#else
    char unknown1_0_[0x2664];
#endif
    char unknown_2664_[4];
};
struct Obj020397cc;
extern "C" Context021be0c4* Zone3D_GetInstance();
extern "C" int* LinkSession_GetInstance();
Obj02046574* MessageSystem_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
void SePlayer_LoadExtraArchiveB(void*, int, int);
void SePlayer_PlayExtra(void*, int, int);
void SePlayer_UnloadExtraArchiveB(void*);
extern char g_sePlayer[];
extern "C" int func_0208f748(void*, int*);
extern "C" void __clear(void*, unsigned int);
extern "C" void Font_EncodeText(BaseCombatStats*, char*, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_02011744(GameState*);
const char* StandardStrings_Get(int);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#if defined(jpn)
extern char data_ov017_021d8658[];
#endif
int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_ov017_021cf730(int, int);
int GameState_GetProtagonistIndex(GameState*);
void EnqueueEventTag173_021d1810(int, int, signed char);
void ClearBitArray_02011408(void*);
void EnqueueEventTag167_021d3ec8();
void MessageSystem_Reset(char*);
void GameObject_EnableControl(void*);

// USA: FieldTask_SpotGrotto
// JPN: func_ov017_021be6bc
// Overlay 17, originally func_ov017_021be0c4 (USA/EUR 0x021be0c4, JPN 0x021be6bc)
extern "C" ARM void FieldTask_SpotGrotto(State021be0c4* state) {
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    Obj02046574* controller = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    GrottoStruct* grotto = game->GetGrottoStruct();
    if (state->step == 0) {
        GameObject_DisableControl((Obj020397cc*)game->GetLeader(), 1);
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b30(global, 0x203, 0);
        if (AlwaysTrue02094b4c(global)) state->step = 1;
    } else if (state->step == 1) {
        SetMainBrightness(resources, 0x10, 0xf);
        SePlayer_LoadExtraArchiveB(g_sePlayer, 0x83, 0x83);
        SePlayer_PlayExtra(g_sePlayer, 0, 0);
        state->step = 2;
    } else if (state->step == 2) {
        if (!IsMainBrightnessTransitionActive(resources)) {
            if (func_0208f748(Zone3D_GetInstance()->map, &grotto->entranceX)) {
                grotto->activeMapData.SetDiscoveryState(DiscoveryState_Discovered);
                if (grotto->activeMapData.DiscoveredBy[0] == 0) {
#if defined(jpn)
                    VectorizedInvertedMemcpy(var0->GetProtagonist()->baseStats_, var3->activeMapData.DiscoveredBy, 10);
#else
                    char name[10];
                    __clear(name, 10);
                    Font_EncodeText(game->GetProtagonist()->baseStats_, name, 1);
                    VectorizedInvertedMemcpy(name, grotto->activeMapData.DiscoveredBy, 10);
#endif
                }
                func_02011744(var0);
                arg0->unknown_8_ = 3;
            } else arg0->unknown_8_ = 5;
        }
    } else if (arg0->unknown_8_ == 3) {
        SetMainBrightness(var1, 0, 0xf);
        arg0->unknown_c_ = 0;
        arg0->unknown_8_ = 4;
    } else if (arg0->unknown_8_ == 4) {
        arg0->unknown_c_ += var0->GetTickCount();
        if (!IsMainBrightnessTransitionActive(var1) && arg0->unknown_c_ > 30) {
            char* var6 = var2->unknown_5c_;
#if defined(jpn)
            sprintf(buffer, data_ov017_021d8658, game->GetLeader()->baseStats_->name);
            func_0204500c((MessageSystem*)controller, buffer, 0);
#else
            sprintf(buffer, StandardStrings_Get(0x3f));
            MessageSystem_SetStringArgument(controller, 0, (char*)game->GetLeader()->baseStats_);
            func_0204500c((MessageSystem*)controller, buffer, 0, 0xe3);
#endif
            controller->field_19b2 = 0;
            controller->active = 1;
            int* field = LinkSession_GetInstance();
            if (LinkSession_IsActive(field) && LinkSession_IsHostOrSolo(field)) {
                func_ov017_021cf730(-1, 0);
                EnqueueEventTag173_021d1810(0x2713, -1, GameState_GetProtagonistIndex(game));
            }
            func_02011408(var0);
            func_ov017_021d3ec8();
            arg0->unknown_8_ = 5;
        }
    } else if (state->step == 5) {
        controller->field_19ae = 0;
        if (!controller->busy) {
            MessageSystem_Reset((char*)controller);
            GameObject_EnableControl(game->GetLeader());
            FontBankLoader* global = FontBankLoader_GetInstance();
            BlankFunction02094b38(global, 0x203);
            FontBankLoader_CancelLoads(global);
            SePlayer_UnloadExtraArchiveB(g_sePlayer);
            state->done = 1;
        }
    }
}
