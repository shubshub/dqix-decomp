#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"



struct Struct_02072a68;
struct Struct_02072a68_2 { Struct_02072a68* unknown_0_; short unknown_4_; short unknown_6_; };
struct Struct_020d80b0_3 {
    unsigned char unknown_0_[4];
    int unknown_4_;
    int unknown_8_;
    Struct_02072a68_2 unknown_c_;
    SafeAllocator unknown_14_;
    int unknown_28_;
};
struct Obj020397cc;
struct SePlayer;
extern SePlayer g_sePlayer;
extern AllocatorUnion g_mainAllocator;
extern char data_020f235c[];
extern char data_020f2371[];
extern "C" void func_0202ae18(GameState*);
extern "C" Zone3D* Zone3D_GetInstance();
extern "C" void* Scenario_GetInstance();
int MessageSystem_GetInstance();
int GetFieldIfFlag4_020100f8(char*);
void ShutdownObject020d8484(Obj020d8484*);
void GameObject_DisableControl(Obj020397cc*, int);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(void*);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void* FindEntryByKey_02072a68(TableA68*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0)
extern char data_020f24b8[];
#else
extern "C" void func_0204500c(void*, char*, int, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0, 0xe3)
#endif
void SePlayer_Play(SePlayer*, int, int);
void GameObject_EnableControl(void*);
void SetCombatModeFromCase020dc2d0(int);
struct Dialog020d80b0 {
#if defined(jpn)
    unsigned char unknown_0_[0x28];
    char* unknown_5c_;
    unsigned char unknown_2c_[0x868-0x2c];
    int unknown_998_;
    unsigned char unknown_86c_[0x17e2-0x86c];
#else
    unsigned char unknown1_0_[0x5c];
    char* unknown_5c_;
    unsigned char unknown_60_[0x998-0x60];
    int unknown_998_;
    unsigned char unknown_99c_[0x19b2-0x99c];
#endif
    unsigned char unknown_19b2_;
};
struct Struct_020d80b0_2 { unsigned char unknown_0_[0x8c]; unsigned char unknown_8c_[1]; };

// Main, originally func_020d80b0 (USA 0x020d80b0, EUR 0x020d80c0, JPN 0x020d9a24)
extern "C" ARM void FieldTask_ShowTreasureMapSearchMessage(Obj020d8484* self) {
    GameState* state = GameState::GetInstance();
    func_0202ae18(state);
    GameResources* resources = GetGameResources();
    Dialog020d80b0* dialog = (Dialog020d80b0*)MessageSystem_GetInstance();
    GameObject* object;
    Bits020d80b0* bits;
    Zone3D_StructPtr_8* zone = Zone3D_GetInstance()->pUnknownStruct_8_;
    GrottoStruct* grotto = state->GetGrottoStruct();
    object = state->GetUnknownGameObject();
    bits = (Bits020d80b0*)Scenario_GetInstance();
    unsigned char* field = (unsigned char*)GetFieldIfFlag4_020100f8((char*)state);
    if (grotto->activeMapData.GetDiscoveryState() != 1) {
        self->state = 7;
        ShutdownObject020d8484(self);
    }
    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)object, 1);
        ClearIntAt0x23c_020a27b8(field);
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x300), 0x300);
#if defined(jpn)
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f24b8, 0);
#else
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f235c, data_020f2371, 0);
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
            BlankFunction02094b30(FontBankLoader_GetInstance(), 0x203, 0);
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(FontBankLoader_GetInstance())) {
            if (Scenario_TestFlag((int)bits, bits->flags, 0x119e)) self->state = 5;
            else {
                self->state = 3;
                Scenario_SetFlag(bits, bits->flags, 0x119e, 1);
            }
        }
    } else if (self->state == 3) {
        char* text = dialog->text;
        strcpy(text, (char*)FindEntryByKey_02072a68(&self->table, 2));
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
        strcpy(text, (char*)FindEntryByKey_02072a68(&self->table, 1));
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
        BlankFunction02094b38(global, 0x203);
        FontBankLoader_CancelLoads(global);
        if (zone && !zone->unknown_c_low_) ShutdownObject020d8484(self);
        else {
            SetSubBrightness(var1, -16, 15);
            arg0->unknown_8_ = 8;
        }
    } else if (arg0->unknown_8_ == 8) {
        if (!IsBrightnessTransitionActive(var1)) {
            func_020dc2d0(2);
            arg0->unknown_8_ = 9;
        }
    } else if (arg0->unknown_8_ == 9) func_020d8484(arg0);
}
