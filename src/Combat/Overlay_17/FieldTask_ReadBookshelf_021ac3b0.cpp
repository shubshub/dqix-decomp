#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"



#if defined(jpn)
enum { Enum_ov017_021ac3b0_2400 = 0x800 };
#else
enum { Enum_ov017_021ac3b0_2400 = 0x960 };
#endif

struct Obj020397cc;
struct Obj02033834;
struct SePlayer;
struct BitFlags020d805c;
struct Obj020d7aa0;
struct StreamHeader;
struct Source021ac3b0 { unsigned short id; char pad2[0x1e]; short angle; };
struct Descriptor021ac3b0 { char pad0[5]; signed char kind; };
struct Zone021ac3b0 { unsigned short id; char pad2[6]; Descriptor021ac3b0* descriptor; };
struct ScriptInfo021ac3b0 {
    const char* text; const char* alternateText; const char* completedText;
    void* data; unsigned short zone; short key; unsigned char kind, index, count, enabled;
};
struct Struct_ov017_021ac3b0 {
    short unknown_0_; unsigned short unknown_2_0_:1, unknown_2_1_:1, unknown_2_2_:14;
};
struct Struct_ov017_021ac3b0_2 {
    unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; Struct_ov017_021ac3b0_6* unknown_8_;
    Struct_ov017_021ac3b0_9* unknown_c_; SafeAllocator unknown_10_; int unknown_24_;
    unsigned char unknown_28_, unknown_29_;
};
struct Struct_ov017_021ac3b0_3 {
#if defined(jpn)
    char unknown_0_[0x28]; char* unknown_5c_; char* unknown_60_; char unknown_30_[0x868 - 0x30];
    int unknown_998_; char unknown_86c_[0x17e2 - 0x86c]; unsigned char unknown_19b2_;
#else
    char unknown1_0_[0x5c]; char* unknown_5c_; char* unknown_60_; char unknown_64_[0x998 - 0x64];
    int unknown_998_; char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
#endif
};
struct Struct_ov017_021ac3b0_4 { char unknown_0_[0x8c]; unsigned char unknown_8c_[1]; };
struct Struct_ov017_021ac3b0_5 {
    char unknown_0_[0xc]; int unknown_c_; char unknown_10_[0x14]; int unknown_24_; char unknown_28_[0xc];
};
extern "C" Zone021ac3b0* Zone3D_GetInstance();
Controller021ac3b0* MessageSystem_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int func_ov017_021959b4();
void MessageSystem_Reset(char*);
extern "C" void func_ov017_021ac32c(Event021ac3b0*);
int GameState_GetFollowCamera(char*);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
void SePlayer_Play(SePlayer*, int, int);
void* TextQueue_GetInstance();
int GetByte0x150Bit6(BitFlags020d805c*);
void TextQueue_Reset(Obj020d7aa0*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" void func_020a0cc4(unsigned int);
void GameObject_SetFacing(Obj02033834*, int);
extern "C" void ROMFilesystem_InitFileTables();
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void InitAndRunScript_021acc8c(void*, StreamHeader*, int, int);
extern "C" Flags021ac3b0* Scenario_GetInstance();
int Scenario_TestFlag(int, unsigned char*, int);
void Text_Append(char*, const char*);
const char* StandardStrings_Get(int);
char* GetData02108d18_0206f504();
void Init0206f510(char*);
extern "C" void func_0206f550(char*, char*, char*);
extern "C" int func_020ac2d4(int, void*, Item021ac3b0*, int);
extern "C" void func_020ac104(int, Item021ac3b0*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void GameObject_EnableControl(void*);
int Scenario_RunTrigger(void*, int, void*);
extern "C" void EventQuery_RunQueuedCommands(Lookup021ac3b0*);
extern SePlayer g_sePlayer;
#if defined(jpn)
extern const char data_ov017_021d7e88[], data_ov017_021d7e96[];
extern const char data_ov017_021d7eb0[], data_ov017_021d7ed2[];
#else
extern const char data_ov017_021d7920[], data_ov017_021d792f[], data_ov017_021d7949[];
#endif
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021ac3b0 (USA/EUR 0x021ac3b0, JPN 0x021acc14)
extern "C" ARM void FieldTask_ReadBookshelf(Event021ac3b0* self) {
    GameState* game = GameState::GetInstance();
    GetGameResources();
    GameObject* leader = game->GetLeader();
    Zone021ac3b0* zone = Zone3D_GetInstance();
    Controller021ac3b0* controller = MessageSystem_GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    FontBankLoader* global = FontBankLoader_GetInstance();
    GameObject_DisableControl((Obj020397cc*)leader, 1);
    if (!self->cancelled && func_ov017_021959b4()) {
        self->cancelled = 1; MessageSystem_Reset((char*)controller);
        func_ov017_021ac32c(self); self->done = 1; return;
    }
    if (self->stage == 0) {
        int actor = GameState_GetFollowCamera((char*)game);
        if (actor) SetFlagsAt0x244_020a28a0((unsigned char*)actor, 3);
        SePlayer_Play(&g_sePlayer, 1, 0);
        void* reset = TextQueue_GetInstance();
        if (GetByte0x150Bit6((BitFlags020d805c*)reset)) TextQueue_Reset((Obj020d7aa0*)reset);
#if defined(jpn)
        func_0204500c(var3, data_ov017_021d7e88, 0);
#else
        func_0204500c(var3, data_ov017_021d7920, 0, 0xe3);
#endif
        var3->unknown_19b2_ = 0; var3->unknown_998_ = 1;
        func_02094b3c(var5, 10);
        func_02094b30(var5, 0x1f6, 1);
        arg0->unknown_28_++;
    } else if (arg0->unknown_28_ == 1) {
        if (func_02094b4c(var5)) arg0->unknown_28_++;
    } else if (arg0->unknown_28_ == 2) {
        func_020a0cc4(0x2800);
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        GameObject_SetFacing((Obj02033834*)leader, fix32ReduceAngle0To2Pi(self->source->angle));
        Descriptor021ac3b0* descriptor = zone->descriptor;
        char archive[0x50];
#if defined(jpn)
        sprintf(var9, data_ov017_021d7e96, var8->unknown_5_);
        arg0->unknown_24_ = var4->QueueLoadFile(var9, 0);
#else
        char var10[0x40];
        sprintf(var9, data_ov017_021d792f, var8->unknown_5_);
        sprintf(var10, data_ov017_021d7949, var8->unknown_5_);
        arg0->unknown_24_ = var4->QueueLoadFileInGP2(var9, var10, 0);
#endif
        self->stage++;
    } else if (self->stage == 3) {
        if (!loader->GetTaskStatus(self->task)) return;
        if (loader->GetDetailedTaskStatus(self->task) != 2) {
            loader->RemoveTask(self->task); self->task = -1; self->done = 1;
            func_ov017_021ac32c(self); ROMFilesystem_InitFileTables(); return;
        }
        void* file; unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2800), 0x2800);
        self->allocator.Reset();
        Zone021ac3b0* state = Zone3D_GetInstance();
        ScriptInfo021ac3b0* info = (ScriptInfo021ac3b0*)self->allocator.Allocate(0x18);
        self->info = info;
        info->text = 0; info->alternateText = 0; info->completedText = 0; info->data = 0;
        info->zone = 0; info->key = -1;
        info->kind = 0; info->index = 0; info->count = 0; info->enabled = 0;
        self->info->zone = state->id; self->info->key = self->source->id;
        InitAndRunScript_021acc8c(&self->allocator, (StreamHeader*)file, length, (int)self->info);
        loader->RemoveTask(self->task); self->task = -1; self->stage = 4;
    } else if (self->stage == 4) {
        char* formatted = controller->formatted;
        char* text = controller->text;
        memset(formatted, 0, kTextBufferCapacity); memset(text, 0, kTextBufferCapacity);
        if (self->info->enabled) {
            const char* message = self->info->text;
            if (self->info->kind == 1) {
                Flags021ac3b0* flags = Scenario_GetInstance();
                if (Scenario_TestFlag((int)flags, flags->bits, 0x777)) {
                    message = self->info->alternateText;
                    if (Scenario_TestFlag((int)flags, flags->bits, self->info->index + 0x114c) && self->info->completedText)
                        message = self->info->completedText;
                }
            }
            if (message) Text_Append(text, message);
#if defined(jpn)
            else Text_Append(text, data_ov017_021d7eb0);
        } else Text_Append(text, data_ov017_021d7ed2);
#else
            else Text_Append(text, StandardStrings_Get(0x3f2));
        } else Text_Append(text, StandardStrings_Get(0x53));
#endif
        if (strlen(var16) >= Enum_ov017_021ac3b0_2400) var16[Enum_ov017_021ac3b0_2400 - 1] = 0;
        char* var19 = func_0206f504();
        func_0206f510(var19); func_0206f550(var19, var16, var15);
#if defined(jpn)
        func_0204500c(var3, var15, 0);
#else
        func_0204500c(var3, var15, 0, 0xe3);
#endif
        controller->active = 1; controller->field19b2 = 0; self->stage = 5;
    } else if (self->stage == 5) {
        if (controller->active) return;
        Flags021ac3b0* flags = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flags, flags->bits, 0x777) && self->info->kind == 1 &&
            !Scenario_TestFlag((int)flags, flags->bits, self->info->index + 0x114c)) {
            unsigned char count = self->info->count;
            if (count) {
                Item021ac3b0* items = (Item021ac3b0*)self->allocator.Allocate(count * 4);
                for (unsigned char i = 0; i < count; i++) {
                    items[i].id = -1; items[i].bit0 = 0; items[i].bit1 = 0; items[i].rest = 0;
                }
                if (func_020ac2d4(0, arg0->unknown_c_->unknown_c_, var22, var21)) {
                    for (unsigned char var24 = 0; var24 < var21; var24++) var22[var24].unknown_2_1_ = 1;
                    func_020ac104(0, var22, var21);
                }
            }
            Scenario_SetFlag(flags, flags->bits, self->info->index + 0x114c, 1);
        }
        FontBankLoader* state = FontBankLoader_GetInstance(); FontBankLoader_CancelLoads(state);
        BlankFunction02094b34(state, 0x6f, 0x1388, 1, 1);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
        func_ov017_021ac32c(self); GameObject_EnableControl(leader); self->done = 1;
        Flags021ac3b0* flags = Scenario_GetInstance();
        Lookup021ac3b0 lookup;
        lookup.zone = zone->id; lookup.key = self->source->id;
        if (Scenario_RunTrigger(flags, 0x18, &lookup)) EventQuery_RunQueuedCommands(&lookup);
    }
}
