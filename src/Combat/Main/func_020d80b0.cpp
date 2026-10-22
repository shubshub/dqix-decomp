#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct EntryA68;
struct TableA68 { EntryA68* entries; short count; short field6; };
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
extern AllocatorUnion data_02114e20;
extern char data_020f235c[];
extern char data_020f2371[];
extern "C" void func_0202ae18(GameState*);
extern "C" Zone3D* func_02012fe4();
extern "C" void* func_0205ec34();
int GetGlobalField0x1c020421a0();
int GetFieldIfFlag4_020100f8(char*);
void ShutdownObject020d8484(Obj020d8484*);
void CancelPendingAction020397cc(Obj020397cc*, int);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(void*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
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
void SetByteField0x253_020397c0(void*);
void SetCombatModeFromCase020dc2d0(int);
struct Dialog020d80b0 {
#if defined(jpn)
    unsigned char field0[0x28];
    char* text;
    unsigned char field60[0x868-0x2c];
    int busy;
    unsigned char field99c[0x17e2-0x86c];
#else
    unsigned char field0[0x5c];
    char* text;
    unsigned char field60[0x998-0x60];
    int busy;
    unsigned char field99c[0x19b2-0x99c];
#endif
    unsigned char flag;
};
struct Bits020d80b0 { unsigned char field0[0x8c]; unsigned char flags[1]; };

// USA: func_020d80b0
extern "C" ARM void func_020d80b0(Obj020d8484* self) {
    GameState* state = GameState::GetInstance();
    func_0202ae18(state);
    GameResources* resources = GetGameResources();
    Dialog020d80b0* dialog = (Dialog020d80b0*)GetGlobalField0x1c020421a0();
    GameObject* object;
    Bits020d80b0* bits;
    Zone3D_StructPtr_8* zone = func_02012fe4()->pUnknownStruct_8_;
    GrottoStruct* grotto = state->GetGrottoStruct();
    object = state->GetUnknownGameObject();
    bits = (Bits020d80b0*)func_0205ec34();
    unsigned char* field = (unsigned char*)GetFieldIfFlag4_020100f8((char*)state);
    if (grotto->activeMapData.GetDiscoveryState() != 1) {
        self->state = 7;
        ShutdownObject020d8484(self);
    }
    if (self->state == 0) {
        CancelPendingAction020397cc((Obj020397cc*)object, 1);
        ClearIntAt0x23c_020a27b8(field);
        self->allocator.CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0x300), 0x300);
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
            BlankFunction02094b30(GetGlobal02109400_02094a00(), 0x203, 0);
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) {
            if (TestBitInByteArray_0206dfb0((int)bits, bits->flags, 0x119e)) self->state = 5;
            else {
                self->state = 3;
                func_0206df6c(bits, bits->flags, 0x119e, 1);
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
        SetByteField0x253_020397c0(object);
        FontBankLoader* global = GetGlobal02109400_02094a00();
        BlankFunction02094b38(global, 0x203);
        func_02094ab0(global);
        if (zone && !zone->unknown_c_low_) ShutdownObject020d8484(self);
        else {
            SetSubBrightness(resources, -16, 15);
            self->state = 8;
        }
    } else if (self->state == 8) {
        if (!IsBrightnessTransitionActive(resources)) {
            SetCombatModeFromCase020dc2d0(2);
            self->state = 9;
        }
    } else if (self->state == 9) ShutdownObject020d8484(self);
}
