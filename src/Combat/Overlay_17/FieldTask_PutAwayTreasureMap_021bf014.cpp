#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_02072a68 { short key; void* value; };
struct TableA68 { Struct_02072a68* entries; short count; };
struct GrottoDialogState { char pad[8]; int state; TableA68 text; SafeAllocator allocator; int task; };
struct Obj02046574;
#if defined(jpn)
enum { TextOffset = 0x28, Enum_ov017_021bf014_712 = 0x218, Enum_ov017_021bf014_2456 = 0x868,
       Enum_ov017_021bf014_2464 = 0x870, Enum_ov017_021bf014_6578 = 0x17e2, TextHeapSize = 0x1f4 };
extern const char data_ov017_021d86d4[];
#else
enum { TextOffset = 0x5c, Enum_ov017_021bf014_712 = 0x2c8, Enum_ov017_021bf014_2456 = 0x998,
       Enum_ov017_021bf014_2464 = 0x9a0, Enum_ov017_021bf014_6578 = 0x19b2, TextHeapSize = 0x320 };
#endif

struct Obj020d7aa0;
struct Obj020397cc;
extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d7ec0[];
extern char data_ov017_021d7ed5[];
extern "C" void LinkSession_GetInstance();
extern "C" Obj02046574* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance();
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" Obj020d7aa0* TextQueue_GetInstance();
extern "C" void TextQueue_Reset(Obj020d7aa0*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_020a27b8(unsigned char*);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(Obj02046574*);
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
extern "C" char* func_02072a68(TableA68*, int);
extern "C" void func_0204500c(Obj02046574*, char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_020457e0(Obj02046574*);
extern "C" void func_020116c8(void*);
extern "C" void func_020dc2d0(int);
extern "C" void MessageSystem_Reset(char*);
extern "C" void GameObject_EnableControl(void*);
extern "C" void FieldTask_EndPutAwayTreasureMap(char*);

// Overlay 17, originally func_ov017_021bf014 (USA/EUR 0x021bf014, JPN 0x021bf5d0)
extern "C" ARM void FieldTask_PutAwayTreasureMap(GrottoDialogState* self) {
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    GetGameResources();
    Obj02046574* controller = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    GrottoStruct* grotto = game->GetGrottoStruct();
    GameObject* combatant = game->GetLeader();
    unsigned char* field = GameState_GetFollowCamera((char*)game);
    if (self->state == 0) {
        TextQueue_Reset(TextQueue_GetInstance());
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        func_020a27b8(field);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, TextHeapSize);
        self->allocator.CreateTypeA(buffer, TextHeapSize);
#if defined(jpn)
        self->task = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d86d4, 0);
#else
        self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7ec0, data_ov017_021d7ed5, 0);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (!BackgroundLoader::GetInstance()->GetTaskStatus(self->task)) return;
        void* file;
        unsigned int length;
        BackgroundLoader::GetInstance()->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.Reset();
        func_020728ac(&self->text, &self->allocator, file, length, 0, 0, 0);
        BackgroundLoader::GetInstance()->RemoveTask(self->task);
        self->task = -1;
        func_02046380(controller);
        MessageSystem_SetStringArgument(controller, 0, game->GetLeader()->baseStats_->name);
        func_02094b30(FontBankLoader_GetInstance(), 0x203, 0);
        self->state = 2;
    }
    if (self->state == 2) {
        if (!func_02094b4c(FontBankLoader_GetInstance())) return;
        if (grotto->activeMapData.GetDiscoveryState() == DiscoveryState_Undiscovered) self->state = 3;
        else self->state = 4;
    } else if (self->state == 3) {
        char* text = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + TextOffset));
        strcpy(text, func_02072a68(&self->text, 1));
        func_0204500c(controller, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_6578)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_712)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_2456)) = 1;
        self->state = 5;
    } else if (self->state == 4) {
        char* text = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + TextOffset));
        strcpy(text, func_02072a68(&self->text, 2));
        func_0204500c(controller, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_6578)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_2456)) = 1;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_712)) = 0;
        self->state = 5;
    } else if (self->state == 5) {
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_2456))) return;
        grotto->unknown_0[2] = 1;
        int result = func_020457e0(controller);
        if (result == 0) self->state = 6;
        else if (result == 1) self->state = 9;
    } else if (self->state == 6) {
        func_020116c8(game);
        func_020dc2d0(0);
        self->state = 7;
    } else if (self->state == 7) {
        self->state = 8;
    } else if (self->state == 8) {
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        if (!(*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + Enum_ov017_021bf014_2464))) self->state = 9;
    } else if (self->state == 9) {
        MessageSystem_Reset((char*)controller);
        GameObject_EnableControl(combatant);
        FontBankLoader* global = FontBankLoader_GetInstance();
        func_02094b38(global, 0x203);
        FontBankLoader_CancelLoads(global);
        FieldTask_EndPutAwayTreasureMap((char*)self);
    }
}
