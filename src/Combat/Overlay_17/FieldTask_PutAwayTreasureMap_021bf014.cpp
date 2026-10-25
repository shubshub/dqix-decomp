#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_02072a68 { short unknown_0_; void* unknown_4_; };
struct Struct_02072a68_2 { Struct_02072a68* unknown_0_; short unknown_4_; };
struct Struct_ov017_021bf014 { char unknown_0_[8]; int unknown_8_; Struct_02072a68_2 unknown_c_; SafeAllocator unknown_14_; int unknown_28_; };
struct Struct_02046574_2;
#if defined(jpn)
enum { Enum_ov017_021bf014_92 = 0x28, Enum_ov017_021bf014_712 = 0x218, Enum_ov017_021bf014_2456 = 0x868,
       Enum_ov017_021bf014_2464 = 0x870, Enum_ov017_021bf014_6578 = 0x17e2, Enum_ov017_021bf014_800 = 0x1f4 };
extern const char data_ov017_021d86d4[];
#else
enum { Enum_ov017_021bf014_92 = 0x5c, Enum_ov017_021bf014_712 = 0x2c8, Enum_ov017_021bf014_2456 = 0x998,
       Enum_ov017_021bf014_2464 = 0x9a0, Enum_ov017_021bf014_6578 = 0x19b2, Enum_ov017_021bf014_800 = 0x320 };
#endif

struct Obj020d7aa0;
struct Obj020397cc;
extern AllocatorUnion g_mainAllocator;
extern char data_ov017_021d7ec0[];
extern char data_ov017_021d7ed5[];
extern "C" void func_0202ae18();
Obj02046574* MessageSystem_GetInstance();
extern "C" void* Zone3D_GetInstance();
unsigned char* GetFieldIfFlag4_020100f8(char*);
Obj020d7aa0* TextQueue_GetInstance();
void TextQueue_Reset(Obj020d7aa0*);
void GameObject_DisableControl(Obj020397cc*, int);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(TableA68*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(Obj02046574*);
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);
char* FindEntryByKey_02072a68(TableA68*, int);
extern "C" void func_0204500c(Obj02046574*, char*, int
#if !defined(jpn)
    , int
#endif
);
extern "C" int func_020457e0(Obj02046574*);
void ClearAllTreasureMapUnknownBits_020116c8(void*);
void SetCombatModeFromCase020dc2d0(int);
void MessageSystem_Reset(char*);
void GameObject_EnableControl(void*);
void FieldTask_EndPutAwayTreasureMap(char*);

// Overlay 17, originally func_ov017_021bf014 (USA/EUR 0x021bf014, JPN 0x021bf5d0)
extern "C" ARM void FieldTask_PutAwayTreasureMap(GrottoDialogState* self) {
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    GetGameResources();
    Obj02046574* controller = MessageSystem_GetInstance();
    Zone3D_GetInstance();
    GrottoStruct* grotto = game->GetGrottoStruct();
    GameObject* combatant = game->GetUnknownGameObject();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)game);
    if (self->state == 0) {
        TextQueue_Reset(TextQueue_GetInstance());
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        ClearIntAt0x23c_020a27b8(field);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, TextHeapSize);
        self->allocator.CreateTypeA(buffer, TextHeapSize);
#if defined(jpn)
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d86d4, 0);
#else
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7ec0, data_ov017_021d7ed5, 0);
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
        MessageSystem_SetStringArgument(controller, 0, game->GetUnknownGameObject()->baseStats_->name);
        BlankFunction02094b30(FontBankLoader_GetInstance(), 0x203, 0);
        self->state = 2;
    }
    if (self->state == 2) {
        if (!AlwaysTrue02094b4c(FontBankLoader_GetInstance())) return;
        if (grotto->activeMapData.GetDiscoveryState() == DiscoveryState_Undiscovered) self->state = 3;
        else self->state = 4;
    } else if (self->state == 3) {
        char* text = (*reinterpret_cast<char**>(reinterpret_cast<char*>(controller) + TextOffset));
        strcpy(text, FindEntryByKey_02072a68(&self->text, 1));
        func_0204500c(controller, text, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(var1) + Enum_ov017_021bf014_6578)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(var1) + Enum_ov017_021bf014_712)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(var1) + Enum_ov017_021bf014_2456)) = 1;
        arg0->unknown_8_ = 5;
    } else if (arg0->unknown_8_ == 4) {
        char* var9 = (*reinterpret_cast<char**>(reinterpret_cast<char*>(var1) + Enum_ov017_021bf014_92));
        strcpy(var9, func_02072a68(&arg0->unknown_c_, 2));
        func_0204500c(var1, var9, 0
#if !defined(jpn)
            , 0xe3
#endif
        );
        (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(controller) + ChoiceFlagOffset)) = 0;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + DialogOffset)) = 1;
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + ChoiceOffset)) = 0;
        self->state = 5;
    } else if (self->state == 5) {
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        if ((*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + DialogOffset))) return;
        grotto->unknown_0[2] = 1;
        int result = func_020457e0(controller);
        if (result == 0) self->state = 6;
        else if (result == 1) self->state = 9;
    } else if (self->state == 6) {
        ClearAllTreasureMapUnknownBits_020116c8(game);
        SetCombatModeFromCase020dc2d0(0);
        self->state = 7;
    } else if (self->state == 7) {
        self->state = 8;
    } else if (self->state == 8) {
        GameObject_DisableControl((Obj020397cc*)combatant, 1);
        if (!(*reinterpret_cast<int*>(reinterpret_cast<char*>(controller) + PendingOffset))) self->state = 9;
    } else if (self->state == 9) {
        MessageSystem_Reset((char*)controller);
        GameObject_EnableControl(combatant);
        FontBankLoader* global = FontBankLoader_GetInstance();
        BlankFunction02094b38(global, 0x203);
        FontBankLoader_CancelLoads(global);
        FieldTask_EndPutAwayTreasureMap((char*)self);
    }
}
