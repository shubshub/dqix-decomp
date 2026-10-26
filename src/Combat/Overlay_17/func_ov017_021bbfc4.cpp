#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Graphics/LightingManager.h>
#include <World/Zone3D.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"



struct Struct_02013fb4;
struct Struct_020213fc;
struct Struct_0204bd7c;
struct Struct_02071488 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[2];
    unsigned char unknown_4_, unknown_5_, unknown_6_, unknown_7_, unknown_8_;
    char unknown_9_[3];
    unsigned short unknown_c_, unknown_e_;
    char unknown_10_[0x34];
};
struct Struct_ov017_021bbfc4_4 { char unknown_0_[0x1c]; Vector3i unknown_1c_; short unknown_28_; unsigned short unknown_2a_; };
struct Struct_ov017_021bbfc4_5 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    unsigned short unknown_8_, unknown_a_;
    Struct_02071488 unknown_c_;
    unsigned short unknown_50_;
    short unknown_52_;
    Vector3i unknown_54_;
    short unknown_60_;
    char unknown_62_[0x12];
    int unknown_74_;
#if defined(jpn)
    char unknown_78_[0x18];
#else
    char unknown1_78_[0x1c];
#endif
    int unknown_94_;
    unsigned char unknown_98_;
    char unknown_99_[3];
    unsigned char unknown_9c_;
    char unknown_9d_[3];
    Struct_ov017_021bbfc4_4 unknown_a0_;
    char unknown_cc_[0x31];
    unsigned char unknown_fd_;
    char unknown_fe_[3];
    unsigned char unknown_101_, unknown_102_;
    char unknown_103_[3];
    unsigned char unknown_106_;
    char unknown_107_[0xf];
    signed char unknown_116_;
    char unknown_117_;
    unsigned short unknown_118_;
    char unknown_11a_[0x5e];
    unsigned char unknown_178_0_ : 1;
    unsigned char unknown_178_1_ : 7;
    unsigned char unknown_179_, unknown_17a_, unknown_17b_;
    float unknown_17c_;
};
struct Struct_ov017_021bbfc4 { char unknown_0_[0x8c]; unsigned char unknown_8c_[0x2a6]; unsigned char unknown_332_; };
struct Struct_ov017_021bbfc4_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_[4];
    unsigned char unknown_7_;
    char unknown_8_[8];
    Vector3i unknown_10_;
    short unknown_1c_;
    char unknown_1e_[2];
    int unknown_20_;
    char unknown_24_[0x3c];
    unsigned char unknown_60_;
    char unknown_61_[0xd];
    unsigned char unknown_6e_;
};
#if defined(jpn)
struct Struct_ov017_021bbfc4_3 { char unknown_0_[0x5a4c]; unsigned char unknown_5cac_; char unknown_5a4d_[0x6fb4 - 0x5a4d]; int unknown_71f4_; };
#else
struct Struct_ov017_021bbfc4_3 { char unknown_0_[0x5cac]; unsigned char unknown_5cac_; char unknown_5cad_[0x1547]; int unknown_71f4_; };
#endif
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" int* LinkSession_GetInstance();
unsigned char* GameState_GetFollowCamera(char*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_020531f0(GameObject*);
extern "C" void func_ov017_021bb27c(Struct_ov017_021bbfc4_5*);
extern "C" void* GetMainBG1CharacterBase();
extern "C" void* GetMainBG1ScreenBase();
extern "C" int func_0208dc00(Struct_02013fb4*, int, int);
void SetBrightness(GameResources*, int, int);
Ticket021bbfc4* GameState_GetZoneTransition(GameState*);
void MapDisplay_SetHoldSubScreenDark(SetFlagStruct*, int);
void InitStruct02070378(char*);
int RunScriptAndAdjustObj02071488(StreamHeader*, int, int, Obj02071488*);
unsigned int* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void* Scenario_GetInstance();
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
int Scenario_TestFlag(int, unsigned char*, int);
ColorHolder0204bd7c* GameObject_GetFloorAttribute(void*);
int ConvertColorToDecimalOffset30000(ColorHolder0204bd7c*);
extern "C" int LinkSession_IsGuest(int*);
int GameState_GetStoryChapter(char*);
int GameState_GetStoryPart(char*);
int GameState_GetStoryStep(char*);
TimeOfDay ConvertToTimeOfDay(float);
void GameState_SetStoryChapter(char*, int);
void GameState_SetStoryPart(char*, int);
void GameState_SetStoryStep(char*, int);
int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_ov017_021d0924(int, int, int, unsigned short);
extern "C" void func_ov017_021bc6e0(Struct_ov017_021bbfc4_5*, int, int);
extern "C" int func_0209c3ac(char*);
extern "C" void func_0209c2e0(void*, int, int);
void SetMainBrightness(GameResources*, int, int);
extern char g_bgmPlayer[];

// USA: func_ov017_021bbfc4
extern "C" ARM int func_ov017_021bbfc4(LoadEvent021bbfc4* self) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = GetGameResources();
    int* search = LinkSession_GetInstance();
    GameObject* original = game->GetLeader();
    GameState_GetFollowCamera((char*)game);
    Zone3D* zone = Zone3D_GetInstance();
    if (IsSubBrightnessTransitionActive(resources)) return self->next;
    for (int i = 0; i < 4; ++i) {
        GameObject* member = game->GetPartyMemberByIndex(i);
        if (member) func_020531f0(member);
    }
    if (!var1->GetTaskStatus(arg0->unknown_74_)) return arg0->unknown_a_;
    if (var1->GetDetailedTaskStatus(arg0->unknown_74_) != BackgroundLoader::TaskStatus_Complete) {
        var1->RemoveTask(arg0->unknown_74_);
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }
    for (int var8 = 0; var8 < 4; ++var8) {
        GameObject* var9 = var0->GetPartyMemberByIndex(var8);
        if (var9) func_020531f0(var9);
    }
    void* var10 = GetMainBG1CharacterBase();
    if (var10) memset(var10, 0, 0x20);
    void* var11 = GetMainBG1ScreenBase();
    if (var11) memset(var11, 0, 0x600);
    void* var12;
    unsigned int var13;
    var1->GetLoadedFileByID(arg0->unknown_74_, &var12, &var13);
    if (arg0->unknown_9c_) {
        if (!func_0208dc00((Struct_02013fb4*)var12, var13, (int)&arg0->unknown_a0_)) {
            SetBrightness(var2, 0, 0x28);
            var1->RemoveTask(arg0->unknown_74_);
            func_ov017_021bb27c(arg0);
            arg0->unknown_1_ = 1;
            return arg0->unknown_a_;
        }
        memcpy(&self->position, &self->source.position, 12);
        self->rotation = self->source.rotation;
        self->script.moved = 1;
        if (self->source.zone != zone->currentZoneID_) {
            loader->RemoveTask(self->task);
            Ticket021bbfc4* ticket = GameState_GetZoneTransition(game);
            MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
            InitStruct02070378((char*)ticket);
            ticket->zone = self->source.zone;
            ticket->pending = 1;
            func_ov017_021bb27c(self);
            self->inactive = 1;
            return self->next;
        }
    } else if (!func_02071488((Struct_02013fb4*)var12, var13, arg0->unknown_8_, &arg0->unknown_c_)) {
        SetBrightness(var2, 0, 0x28);
        var1->RemoveTask(arg0->unknown_74_);
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }
    loader->RemoveTask(self->task);
    if (self->flags & 0x100) FlagWord_SetBits(GlobalFlags_GetInstance(), 1);
    self->copiedParameter = self->script.parameter;
    int transition;
    int restart;
    int reposition;
    int exists;
    Flags021bbfc4* flags = (Flags021bbfc4*)Scenario_GetInstance();
    if (self->reset) Scenario_SetFlag(flags, flags->bits, self->key + 0x38e, 0);
    exists = 0;
    if (Scenario_TestFlag((int)flags, flags->bits, self->key + 0x38e)) exists = 1;
    if (exists) {
        SetBrightness(resources, 0, 0x28);
        ((GameView021bbfc4*)game)->pending = 0;
        func_ov017_021bb27c(self);
        self->inactive = 1;
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 0);
        return self->next;
    }
    transition = 0;
    restart = 0;
    reposition = 0;
    if (self->reset) transition = 1;
    if (self->flags & 0x80) self->script.zone = ConvertColorToDecimalOffset30000(GameObject_GetFloorAttribute(original));
    if (self->script.zone != zone->currentZoneID_) transition = 1;
    if (LinkSession_IsGuest(search) && self->hasTime) {
        if (self->chapter != GameState_GetStoryChapter((char*)game) || self->entry != GameState_GetStoryPart((char*)game) || self->slot != GameState_GetStoryStep((char*)game) || ConvertToTimeOfDay(self->dayTimer) != game->GetTimeOfDay()) {
            GameState_SetStoryChapter((char*)game, self->chapter);
            GameState_SetStoryPart((char*)game, self->entry);
            GameState_SetStoryStep((char*)game, self->slot);
            game->SetDayTimer(self->dayTimer);
            LightingManager* lighting = LightingManager::GetInstance();
            lighting->dayNightTimer_ = game->GetDayTimer();
            lighting->timeOfDayIndex_ = game->GetTimeOfDay();
            if (!transition) reposition = 1;
            transition = 1;
            restart = 1;
        }
    }
    int entry = GameState_GetStoryPart((char*)game);
    int chapter = GameState_GetStoryChapter((char*)game);
    int current = chapter * 1000 + entry;
    unsigned int nextChapter = self->script.chapter;
    unsigned int nextEntry = self->script.entry;
    int next = nextChapter * 1000 + nextEntry;
    if (!transition && !self->script.skip && nextChapter <= 19 && (nextChapter && nextEntry) && current < next) {
        GameState_SetStoryChapter((char*)game, nextChapter);
        GameState_SetStoryPart((char*)game, self->script.entry);
        if (LinkSession_IsActive(search)) {
            if (LinkSession_IsGuest(search)) { reposition = restart = 1; }
        }
        if (LinkSession_IsHostOrSolo(search)) {
            int chapter = GameState_GetStoryChapter((char*)game);
            int entry = GameState_GetStoryPart((char*)game);
            int slot = GameState_GetStoryStep((char*)game);
            func_ov017_021d0924(2, flags->index, 0, (unsigned short)((chapter << 10) | (entry << 5) | slot));
        }
        var15 = 1;
    }
    if (self->restart || ((GameView021bbfc4*)game)->restart) restart = 1;
    if (transition) {
        Ticket021bbfc4* ticket = GameState_GetZoneTransition(game);
        InitStruct02070378((char*)ticket);
        ticket->zone = self->script.zone;
        ticket->parameter = self->parameter;
        ticket->pending = 1;
        if (reposition) {
            GameObject* player = game->GetLeader();
            ticket->position = player->obj3D_.position_;
            ticket->rotation = player->obj3D_.rotation_.y;
            ticket->positioned = 1;
        }
        if (TestFlags00(resources, 0x1000)) ticket->flags |= 9;
        ticket->restart = restart;
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
        func_ov017_021bb27c(self);
        self->inactive = 1;
        return self->next;
    }
    if (LinkSession_IsActive(search) && self->script.request && self->searchIndex < 0 && LinkSession_IsHostOrSolo(search)) func_ov017_021bc6e0(self, -1, self->flags);
    self->status = GetField0xcd0209c3ac(g_bgmPlayer);
    if (self->script.kind == 3) func_0209c2e0(g_bgmPlayer, 0, 0);
    if (((self->flags & 1) || (self->flags & 4)) && !self->restart) {
        int brightness = GetBrightness((GameResources*)resources, false);
        if (brightness > 0) SetMainBrightness(resources, 16, 30);
        else SetMainBrightness(resources, -16, 30);
        self->ready = 1;
        self->done = 1;
    }
    if (arg0->unknown_fd_ && arg0->unknown_106_) arg0->unknown_106_ = 0;
    arg0->unknown_fd_ = 0;
    return TestFlags00(var2, 0x1000) ? 13 : 12;
}
