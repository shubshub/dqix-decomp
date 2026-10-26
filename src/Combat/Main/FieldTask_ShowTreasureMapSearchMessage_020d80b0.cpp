#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"



struct Struct_02072a68;
struct TableA68 { Struct_02072a68* entries; short count; short field6; };
struct Obj020d8484 {
    unsigned char header[4];
    int field4;
    int state;
    TableA68 table;
    SafeAllocator allocator;
    int task;
};
struct Obj020397cc;
struct SePlayer;
extern SePlayer g_sePlayer;
extern AllocatorUnion g_mainAllocator;
extern char data_020f235c[];
extern char data_020f2371[];
extern "C" void LinkSession_GetInstance(GameState*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void* Scenario_GetInstance();
extern "C" int MessageSystem_GetInstance();
extern "C" int GameState_GetFollowCamera(char*);
extern "C" void func_020d8484(Obj020d8484*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_020a27b8(unsigned char*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(void*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void* func_02072a68(TableA68*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0)
extern char data_020f24b8[];
#else
extern "C" void func_0204500c(void*, char*, int, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0, 0xe3)
#endif
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" void func_020dc2d0(int);
struct Dialog020d80b0 {
#if defined(jpn)
    unsigned char field0[0x28];
    char* text;
    unsigned char field60[0x868-0x2c];
    int busy;
    unsigned char unknown_86c_[0x17e2-0x86c];
#else
    unsigned char field0[0x5c];
    char* text;
    unsigned char field60[0x998-0x60];
    int busy;
    unsigned char unknown_99c_[0x19b2-0x99c];
#endif
    unsigned char flag;
};
struct Bits020d80b0 { unsigned char field0[0x8c]; unsigned char flags[1]; };

// Main, originally func_020d80b0 (USA 0x020d80b0, EUR 0x020d80c0, JPN 0x020d9a24)
extern "C" ARM void FieldTask_ShowTreasureMapSearchMessage(Obj020d8484* self) {
    GameState* state = GameState::GetInstance();
    LinkSession_GetInstance(state);
    GameResources* resources = GetGameResources();
    Dialog020d80b0* dialog = (Dialog020d80b0*)MessageSystem_GetInstance();
    GameObject* object;
    Bits020d80b0* bits;
    Zone3D_StructPtr_8* zone = Zone3D_GetInstance()->pUnknownStruct_8_;
    GrottoStruct* grotto = state->GetGrottoStruct();
    object = state->GetLeader();
    bits = (Bits020d80b0*)Scenario_GetInstance();
    unsigned char* field = (unsigned char*)GameState_GetFollowCamera((char*)state);
    if (grotto->activeMapData.GetDiscoveryState() != 1) {
        self->state = 7;
        func_020d8484(self);
    }
    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)object, 1);
        func_020a27b8(field);
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x300), 0x300);
#if defined(jpn)
        self->task = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f24b8, 0);
#else
        self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f235c, data_020f2371, 0);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (BackgroundLoader::GetInstance()->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            func_020728ac(&self->table, &self->allocator, data, length, 0, 0, 0);
            BackgroundLoader::GetInstance()->RemoveTask(self->task);
            self->task = -1;
            func_02046380(dialog);
            func_02094b30(FontBankLoader_GetInstance(), 0x203, 0);
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (func_02094b4c(FontBankLoader_GetInstance())) {
            if (Scenario_TestFlag((int)bits, bits->flags, 0x119e)) self->state = 5;
            else {
                self->state = 3;
                Scenario_SetFlag(bits, bits->flags, 0x119e, 1);
            }
        }
    } else if (self->state == 3) {
        char* text = dialog->text;
        strcpy(text, (char*)func_02072a68(&self->table, 2));
        SHOW_TEXT_020d80b0(dialog, text);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 4;
    } else if (self->state == 4) {
        if (!dialog->busy) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            self->state = 5;
        }
    } else if (self->state == 5) {
        char* text = dialog->text;
        strcpy(text, (char*)func_02072a68(&self->table, 1));
        SHOW_TEXT_020d80b0(dialog, text);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 6;
    } else if (self->state == 6) {
        if (!dialog->busy) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            self->state = 7;
        }
    } else if (self->state == 7) {
        GameObject_EnableControl(object);
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b38(global, 0x203);
        FontBankLoader_CancelLoads(global);
        if (zone && !zone->unknown_c_low_) func_020d8484(self);
        else {
            SetSubBrightness(resources, -16, 15);
            self->state = 8;
        }
    } else if (self->state == 8) {
        if (!IsBrightnessTransitionActive(resources)) {
            func_020dc2d0(2);
            self->state = 9;
        }
    } else if (self->state == 9) func_020d8484(self);
}
