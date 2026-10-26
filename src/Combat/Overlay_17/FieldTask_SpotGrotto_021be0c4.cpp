#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct State021be0c4 { unsigned char pad0, done; char pad2[6]; int step, elapsed; };
struct Obj02046574 {
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    char* buffer;
#if defined(jpn)
    char pad60[0x868 - 0x2c];
#else
    char pad60[0x938];
#endif
    int active;
    char unknown_99c_[4];
    int busy;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x100a];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[3];
    unsigned char unknown_19b2_;
};
struct Context021be0c4 {
#if defined(jpn)
    char pad[0x26a4];
#else
    char pad[0x2664];
#endif
    char map[4];
};
struct Obj020397cc;
extern "C" Context021be0c4* Zone3D_GetInstance();
extern "C" int* LinkSession_GetInstance();
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void SePlayer_LoadExtraArchiveB(void*, int, int);
extern "C" void SePlayer_PlayExtra(void*, int, int);
extern "C" void SePlayer_UnloadExtraArchiveB(void*);
extern char g_sePlayer[];
extern "C" int func_0208f748(void*, int*);
extern "C" void __clear(void*, unsigned int);
extern "C" void Font_EncodeText(BaseCombatStats*, char*, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);
extern "C" void func_02011744(GameState*);
extern "C" const char* StandardStrings_Get(int);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
#if defined(jpn)
extern char data_ov017_021d8658[];
#endif
extern "C" int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_ov017_021cf730(int, int);
extern "C" int GameState_GetProtagonistIndex(GameState*);
extern "C" void func_ov017_021d1810(int, int, signed char);
extern "C" void func_02011408(void*);
extern "C" void func_ov017_021d3ec8();
extern "C" void MessageSystem_Reset(char*);
extern "C" void GameObject_EnableControl(void*);

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
        func_02094b30(global, 0x203, 0);
        if (func_02094b4c(global)) state->step = 1;
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
                    VectorizedInvertedMemcpy(game->GetProtagonist()->baseStats_, grotto->activeMapData.DiscoveredBy, 10);
#else
                    char name[10];
                    __clear(name, 10);
                    Font_EncodeText(game->GetProtagonist()->baseStats_, name, 1);
                    VectorizedInvertedMemcpy(name, grotto->activeMapData.DiscoveredBy, 10);
#endif
                }
                func_02011744(game);
                state->step = 3;
            } else state->step = 5;
        }
    } else if (state->step == 3) {
        SetMainBrightness(resources, 0, 0xf);
        state->elapsed = 0;
        state->step = 4;
    } else if (state->step == 4) {
        state->elapsed += game->GetTickCount();
        if (!IsMainBrightnessTransitionActive(resources) && state->elapsed > 30) {
            char* buffer = controller->buffer;
#if defined(jpn)
            sprintf(buffer, data_ov017_021d8658, game->GetLeader()->baseStats_->name);
            func_0204500c((MessageSystem*)controller, buffer, 0);
#else
            sprintf(buffer, StandardStrings_Get(0x3f));
            MessageSystem_SetStringArgument(controller, 0, (char*)game->GetLeader()->baseStats_);
            func_0204500c((MessageSystem*)controller, buffer, 0, 0xe3);
#endif
            controller->unknown_19b2_ = 0;
            controller->active = 1;
            int* field = LinkSession_GetInstance();
            if (LinkSession_IsActive(field) && LinkSession_IsHostOrSolo(field)) {
                func_ov017_021cf730(-1, 0);
                func_ov017_021d1810(0x2713, -1, GameState_GetProtagonistIndex(game));
            }
            func_02011408(game);
            func_ov017_021d3ec8();
            state->step = 5;
        }
    } else if (state->step == 5) {
        controller->unknown_19ae_ = 0;
        if (!controller->busy) {
            MessageSystem_Reset((char*)controller);
            GameObject_EnableControl(game->GetLeader());
            FontBankLoader* global = FontBankLoader_GetInstance();
            func_02094b38(global, 0x203);
            FontBankLoader_CancelLoads(global);
            SePlayer_UnloadExtraArchiveB(g_sePlayer);
            state->done = 1;
        }
    }
}
