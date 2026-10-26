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
struct Struct_ov017_021ac3b0_6 { unsigned short id; char pad2[0x1e]; short angle; };
struct Struct_ov017_021ac3b0_7 { char pad0[5]; signed char kind; };
struct Zone021ac3b0 { unsigned short id; char pad2[6]; Struct_ov017_021ac3b0_7* descriptor; };
struct Struct_ov017_021ac3b0_9 {
    const char* text; const char* unknown_4_; const char* completedText;
    void* data; unsigned short zone; short key; unsigned char kind, index, count, enabled;
};
struct Struct_ov017_021ac3b0 {
    short id; unsigned short bit0:1, unknown_2_1_:1, rest:14;
};
struct Event021ac3b0 {
    unsigned char pad0, done; char pad2[6]; Struct_ov017_021ac3b0_6* source;
    Struct_ov017_021ac3b0_9* info; SafeAllocator allocator; int task;
    unsigned char stage, cancelled;
};
struct Controller021ac3b0 {
#if defined(jpn)
    char pad0[0x28]; char* formatted; char* text; char unknown_30_[0x868 - 0x30];
    int active; char unknown_86c_[0x17e2 - 0x86c]; unsigned char unknown_19b2_;
#else
    char pad0[0x5c]; char* formatted; char* text; char unknown_64_[0x998 - 0x64];
    int active; char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
#endif
};
struct Flags021ac3b0 { char pad0[0x8c]; unsigned char bits[1]; };
struct Lookup021ac3b0 {
    char pad0[0xc]; int zone; char pad10[0x14]; int key; char pad28[0xc];
};
extern "C" Zone021ac3b0* Zone3D_GetInstance();
extern "C" Controller021ac3b0* MessageSystem_GetInstance();
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" int func_ov017_021959b4();
extern "C" void MessageSystem_Reset(char*);
extern "C" void func_ov017_021ac32c(Event021ac3b0*);
extern "C" int GameState_GetFollowCamera(char*);
extern "C" void func_020a28a0(unsigned char*, unsigned char);
extern "C" void SePlayer_Play(SePlayer*, int, int);
extern "C" void* TextQueue_GetInstance();
extern "C" int func_020d805c(BitFlags020d805c*);
extern "C" void TextQueue_Reset(Obj020d7aa0*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" void func_020a0cc4(unsigned int);
extern "C" void GameObject_SetFacing(Obj02033834*, int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_ov017_021acc8c(void*, StreamHeader*, int, int);
extern "C" Flags021ac3b0* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Text_Append(char*, const char*);
extern "C" const char* StandardStrings_Get(int);
extern "C" char* func_0206f504();
extern "C" void func_0206f510(char*);
extern "C" void func_0206f550(char*, char*, char*);
extern "C" int func_020ac2d4(int, void*, Struct_ov017_021ac3b0*, int);
extern "C" void func_020ac104(int, Struct_ov017_021ac3b0*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void GameObject_EnableControl(void*);
extern "C" int Scenario_RunTrigger(void*, int, void*);
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
        if (actor) func_020a28a0((unsigned char*)actor, 3);
        SePlayer_Play(&g_sePlayer, 1, 0);
        void* reset = TextQueue_GetInstance();
        if (func_020d805c((BitFlags020d805c*)reset)) TextQueue_Reset((Obj020d7aa0*)reset);
#if defined(jpn)
        func_0204500c(controller, data_ov017_021d7e88, 0);
#else
        func_0204500c(controller, data_ov017_021d7920, 0, 0xe3);
#endif
        controller->unknown_19b2_ = 0; controller->active = 1;
        func_02094b3c(global, 10);
        func_02094b30(global, 0x1f6, 1);
        self->stage++;
    } else if (self->stage == 1) {
        if (func_02094b4c(global)) self->stage++;
    } else if (self->stage == 2) {
        func_020a0cc4(0x2800);
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        GameObject_SetFacing((Obj02033834*)leader, fix32ReduceAngle0To2Pi(self->source->angle));
        Struct_ov017_021ac3b0_7* descriptor = zone->descriptor;
        char archive[0x50];
#if defined(jpn)
        sprintf(archive, data_ov017_021d7e96, descriptor->kind);
        self->task = loader->QueueLoadFile(archive, 0);
#else
        char filename[0x40];
        sprintf(archive, data_ov017_021d792f, descriptor->kind);
        sprintf(filename, data_ov017_021d7949, descriptor->kind);
        self->task = loader->QueueLoadFileInGP2(archive, filename, 0);
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
        Struct_ov017_021ac3b0_9* info = (Struct_ov017_021ac3b0_9*)self->allocator.Allocate(0x18);
        self->info = info;
        info->text = 0; info->unknown_4_ = 0; info->completedText = 0; info->data = 0;
        info->zone = 0; info->key = -1;
        info->kind = 0; info->index = 0; info->count = 0; info->enabled = 0;
        self->info->zone = state->id; self->info->key = self->source->id;
        func_ov017_021acc8c(&self->allocator, (StreamHeader*)file, length, (int)self->info);
        loader->RemoveTask(self->task); self->task = -1; self->stage = 4;
    } else if (self->stage == 4) {
        char* formatted = controller->formatted;
        char* text = controller->text;
        memset(formatted, 0, Enum_ov017_021ac3b0_2400); memset(text, 0, Enum_ov017_021ac3b0_2400);
        if (self->info->enabled) {
            const char* message = self->info->text;
            if (self->info->kind == 1) {
                Flags021ac3b0* flags = Scenario_GetInstance();
                if (Scenario_TestFlag((int)flags, flags->bits, 0x777)) {
                    message = self->info->unknown_4_;
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
        if (strlen(text) >= Enum_ov017_021ac3b0_2400) text[Enum_ov017_021ac3b0_2400 - 1] = 0;
        char* data = func_0206f504();
        func_0206f510(data); func_0206f550(data, text, formatted);
#if defined(jpn)
        func_0204500c(controller, formatted, 0);
#else
        func_0204500c(controller, formatted, 0, 0xe3);
#endif
        controller->active = 1; controller->unknown_19b2_ = 0; self->stage = 5;
    } else if (self->stage == 5) {
        if (controller->active) return;
        Flags021ac3b0* flags = Scenario_GetInstance();
        if (Scenario_TestFlag((int)flags, flags->bits, 0x777) && self->info->kind == 1 &&
            !Scenario_TestFlag((int)flags, flags->bits, self->info->index + 0x114c)) {
            unsigned char count = self->info->count;
            if (count) {
                Struct_ov017_021ac3b0* items = (Struct_ov017_021ac3b0*)self->allocator.Allocate(count * 4);
                for (unsigned char i = 0; i < count; i++) {
                    items[i].id = -1; items[i].bit0 = 0; items[i].unknown_2_1_ = 0; items[i].rest = 0;
                }
                if (func_020ac2d4(0, self->info->data, items, count)) {
                    for (unsigned char i = 0; i < count; i++) items[i].unknown_2_1_ = 1;
                    func_020ac104(0, items, count);
                }
            }
            Scenario_SetFlag(flags, flags->bits, self->info->index + 0x114c, 1);
        }
        FontBankLoader* state = FontBankLoader_GetInstance(); FontBankLoader_CancelLoads(state);
        func_02094b34(state, 0x6f, 0x1388, 1, 1);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (!func_02094b4c(FontBankLoader_GetInstance())) return;
        func_ov017_021ac32c(self); GameObject_EnableControl(leader); self->done = 1;
        Flags021ac3b0* flags = Scenario_GetInstance();
        Lookup021ac3b0 lookup;
        lookup.zone = zone->id; lookup.key = self->source->id;
        if (Scenario_RunTrigger(flags, 0x18, &lookup)) EventQuery_RunQueuedCommands(&lookup);
    }
}
