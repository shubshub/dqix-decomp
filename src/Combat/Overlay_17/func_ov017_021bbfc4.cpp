#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Graphics/LightingManager.h>
#include <World/Zone3D.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"



struct StreamHeader;
struct SetFlagStruct;
struct ColorHolder0204bd7c;
struct Struct_02071488 {
    unsigned char chapter, entry;
    char unknown_2_[2];
    unsigned char kind, moved, request, unknown_7_, unknown_8_;
    char unknown_9_[3];
    unsigned short parameter, zone;
    char unknown_10_[0x34];
};
struct Struct_ov017_021bbfc4_4 { char unknown_0_[0x1c]; Vector3i position; short rotation; unsigned short zone; };
struct Struct_ov017_021bbfc4_5 {
    unsigned char kind, unknown_1_;
    char unknown_2_[6];
    unsigned short parameter, next;
    Struct_02071488 script;
    unsigned short flags;
    short key;
    Vector3i position;
    short rotation;
    char unknown_62_[0x12];
    int task;
#if defined(jpn)
    char unknown_78_[0x18];
#else
    char unknown1_78_[0x1c];
#endif
    int status;
    unsigned char reset;
    char unknown_99_[3];
    unsigned char unknown_9c_;
    char unknown_9d_[3];
    Struct_ov017_021bbfc4_4 source;
    char unknown_cc_[0x31];
    unsigned char restart;
    char unknown_fe_[3];
    unsigned char unknown_101_, done;
    char unknown_103_[3];
    unsigned char unknown_106_;
    char unknown_107_[0xf];
    signed char searchIndex;
    char unknown_117_;
    unsigned short unknown_118_;
    char unknown_11a_[0x5e];
    unsigned char hasTime : 1;
    unsigned char reserved : 7;
    unsigned char chapter, entry, slot;
    float dayTimer;
};
struct Flags021bbfc4 { char unknown_0_[0x8c]; unsigned char bits[0x2a6]; unsigned char index; };
struct Ticket021bbfc4 {
    unsigned short zone;
    unsigned char pending;
    char unknown_3_[4];
    unsigned char unknown_7_;
    char unknown_8_[8];
    Vector3i position;
    short rotation;
    char unknown_1e_[2];
    int parameter;
    char unknown_24_[0x3c];
    unsigned char restart;
    char unknown_61_[0xd];
    unsigned char flags;
};
#if defined(jpn)
struct Struct_ov017_021bbfc4_3 { char unknown_0_[0x5a4c]; unsigned char restart; char unknown_5a4d_[0x6fb4 - 0x5a4d]; int pending; };
#else
struct Struct_ov017_021bbfc4_3 { char unknown_0_[0x5cac]; unsigned char restart; char unknown_5cad_[0x1547]; int pending; };
#endif
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" int* LinkSession_GetInstance();
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void func_020531f0(GameObject*);
extern "C" void func_ov017_021bb27c(Struct_ov017_021bbfc4_5*);
extern "C" void* GetMainBG1CharacterBase();
extern "C" void* GetMainBG1ScreenBase();
extern "C" int func_0208dc00(StreamHeader*, int, int);
void SetBrightness(GameResources*, int, int);
extern "C" Ticket021bbfc4* GameState_GetZoneTransition(GameState*);
extern "C" void MapDisplay_SetHoldSubScreenDark(SetFlagStruct*, int);
extern "C" void func_02070378(char*);
extern "C" int func_02071488(StreamHeader*, int, int, Struct_02071488*);
extern "C" unsigned int* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void* Scenario_GetInstance();
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" ColorHolder0204bd7c* GameObject_GetFloorAttribute(void*);
extern "C" int func_0204bd7c(ColorHolder0204bd7c*);
extern "C" int LinkSession_IsGuest(int*);
extern "C" int GameState_GetStoryChapter(char*);
extern "C" int GameState_GetStoryPart(char*);
extern "C" int GameState_GetStoryStep(char*);
TimeOfDay ConvertToTimeOfDay(float);
extern "C" void GameState_SetStoryChapter(char*, int);
extern "C" void GameState_SetStoryPart(char*, int);
extern "C" void GameState_SetStoryStep(char*, int);
extern "C" int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsHostOrSolo(int*);
extern "C" void func_ov017_021d0924(int, int, int, unsigned short);
extern "C" void func_ov017_021bc6e0(Struct_ov017_021bbfc4_5*, int, int);
extern "C" int func_0209c3ac(char*);
extern "C" void func_0209c2e0(void*, int, int);
void SetMainBrightness(GameResources*, int, int);
extern char g_bgmPlayer[];

// USA: func_ov017_021bbfc4
extern "C" ARM int func_ov017_021bbfc4(Struct_ov017_021bbfc4_5* self) {
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
    if (!loader->GetTaskStatus(self->task)) return self->next;
    if (loader->GetDetailedTaskStatus(self->task) != BackgroundLoader::TaskStatus_Complete) {
        loader->RemoveTask(self->task);
        func_ov017_021bb27c(self);
        self->unknown_1_ = 1;
        return self->next;
    }
    for (int i = 0; i < 4; ++i) {
        GameObject* member = game->GetPartyMemberByIndex(i);
        if (member) func_020531f0(member);
    }
    void* character = GetMainBG1CharacterBase();
    if (character) memset(character, 0, 0x20);
    void* screen = GetMainBG1ScreenBase();
    if (screen) memset(screen, 0, 0x600);
    void* file;
    unsigned int length;
    loader->GetLoadedFileByID(self->task, &file, &length);
    if (self->unknown_9c_) {
        if (!func_0208dc00((StreamHeader*)file, length, (int)&self->source)) {
            SetBrightness(resources, 0, 0x28);
            loader->RemoveTask(self->task);
            func_ov017_021bb27c(self);
            self->unknown_1_ = 1;
            return self->next;
        }
        memcpy(&self->position, &self->source.position, 12);
        self->rotation = self->source.rotation;
        self->script.moved = 1;
        if (self->source.zone != zone->currentZoneID_) {
            loader->RemoveTask(self->task);
            Ticket021bbfc4* ticket = GameState_GetZoneTransition(game);
            MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
            func_02070378((char*)ticket);
            ticket->zone = self->source.zone;
            ticket->pending = 1;
            func_ov017_021bb27c(self);
            self->unknown_1_ = 1;
            return self->next;
        }
    } else if (!func_02071488((StreamHeader*)file, length, self->parameter, &self->script)) {
        SetBrightness(resources, 0, 0x28);
        loader->RemoveTask(self->task);
        func_ov017_021bb27c(self);
        self->unknown_1_ = 1;
        return self->next;
    }
    loader->RemoveTask(self->task);
    if (self->flags & 0x100) FlagWord_SetBits(GlobalFlags_GetInstance(), 1);
    self->unknown_118_ = self->script.parameter;
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
        ((Struct_ov017_021bbfc4_3*)game)->pending = 0;
        func_ov017_021bb27c(self);
        self->unknown_1_ = 1;
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 0);
        return self->next;
    }
    transition = 0;
    restart = 0;
    reposition = 0;
    if (self->reset) transition = 1;
    if (self->flags & 0x80) self->script.zone = func_0204bd7c(GameObject_GetFloorAttribute(original));
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
    unsigned int var25 = self->script.entry;
    int next = nextChapter * 1000 + var25;
    if (!transition && !self->script.unknown_8_ && nextChapter <= 19 && (nextChapter && var25) && current < next) {
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
        transition = 1;
    }
    if (self->restart || ((Struct_ov017_021bbfc4_3*)game)->restart) restart = 1;
    if (transition) {
        Ticket021bbfc4* ticket = GameState_GetZoneTransition(game);
        func_02070378((char*)ticket);
        ticket->zone = self->script.zone;
        ticket->parameter = self->parameter;
        ticket->pending = 1;
        if (reposition) {
            GameObject* player = game->GetLeader();
            ticket->position = player->obj3D_.position_;
            ticket->rotation = player->obj3D_.rotation_.y;
            ticket->unknown_7_ = 1;
        }
        if (TestFlags00(resources, 0x1000)) ticket->flags |= 9;
        ticket->restart = restart;
        MapDisplay_SetHoldSubScreenDark((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
        func_ov017_021bb27c(self);
        self->unknown_1_ = 1;
        return self->next;
    }
    if (LinkSession_IsActive(search) && self->script.request && self->searchIndex < 0 && LinkSession_IsHostOrSolo(search)) func_ov017_021bc6e0(self, -1, self->flags);
    self->status = func_0209c3ac(g_bgmPlayer);
    if (self->script.kind == 3) func_0209c2e0(g_bgmPlayer, 0, 0);
    if (((self->flags & 1) || (self->flags & 4)) && !self->restart) {
        int brightness = GetBrightness((GameResources*)resources, false);
        if (brightness > 0) SetMainBrightness(resources, 16, 30);
        else SetMainBrightness(resources, -16, 30);
        self->unknown_101_ = 1;
        self->done = 1;
    }
    if (self->restart && self->unknown_106_) self->unknown_106_ = 0;
    self->restart = 0;
    return TestFlags00(resources, 0x1000) ? 13 : 12;
}
