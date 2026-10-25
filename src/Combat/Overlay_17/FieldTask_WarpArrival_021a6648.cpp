#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"

struct Struct_02018300_3;
struct Struct_0203d028 { char unknown_0_[0x70]; };
struct Struct_ov017_021a6648 {
    Struct_0203d028 unknown_0_[0x1c];
    Struct_0203d028 unknown_c40_;
};
struct Struct_02038598_4;
struct Struct_020d7aa0_2;
struct Struct_02038598_5;
struct Struct_ov017_021a6648_2 {
    char unknown_0_; unsigned char unknown_1_; char unknown_2_[6];
    unsigned char unknown_8_, unknown_9_, unknown_a_, unknown_b_, unknown_c_, unknown_d_; short unknown_e_;
    SafeAllocator unknown_10_; int unknown_24_[10]; int unknown_4c_[2];
};
struct Struct_ov017_021a6648_3 {
    char unknown_0_[0x10]; unsigned char unknown_10_;
    unsigned char unknown_11_0_:1, unknown_11_1_:1, unknown_11_2_:1, unknown_11_3_:1, unknown_11_4_:1, unknown_11_5_:1, unknown_11_6_:1, unknown_11_7_:1;
    short unknown_12_, unknown_14_, unknown_16_, unknown_18_, unknown_1a_, unknown_1c_, unknown_1e_;
    int unknown_20_, unknown_24_, unknown_28_; Vector3i unknown_2c_;
    int unknown_38_, unknown_3c_, unknown_40_; Vector3i unknown_44_;
};
extern "C" void* func_02057924();
unsigned int* GlobalFlags_GetInstance();
void GameObject_DisableControl(Obj020397cc*, int);
int IsField0Null_02046b08(void**);
void FlagWord_SetBits(unsigned int*, unsigned int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
void VramState_Rewind(Foo0207df50*);
void NNS_GfdGetFrmTexVramState(int*);
void NNS_GfdGetFrmPlttVramState(int*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Foo0207df50*);
void FindNodeAndProcess02057fb4(void*, int, void*);
void SePlayer_LoadExtraArchiveB(void*, int, int);
void SePlayer_PlayExtra(void*, int, int);
void GameObject_EnableControl(void*);
void SePlayer_UnloadExtraArchiveB(void*);
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
void SetCombatModeFromCase020dc2d0(int);
void RegisterNodeAndNotify_0219593c();
Obj020d7aa0* TextQueue_GetInstance();
void TextQueue_Reset(Obj020d7aa0*);
int ListContainsId(ListHead02046b60*, int);
extern "C" void func_02046a8c(ListHead02046b60*, void*);
extern "C" void func_ov017_021a6b30(Transition021a6648*);
extern const char* data_ov017_021d771c[3];
extern AllocatorUnion g_mainAllocator;
extern unsigned char data_ov017_021d6aa8[9];
extern Vector3i data_ov017_021d6ab4;
extern char data_ov017_021d7778[], data_ov017_021d777a[];
extern char g_sePlayer;
extern unsigned char data_ov017_021d6aa9[9], data_ov017_021d6aaa[9];

// Overlay 17, originally func_ov017_021a6648 (USA/EUR 0x021a6648, JPN 0x021a6fec)
extern "C" ARM void FieldTask_WarpArrival(Transition021a6648* self, ListHead02046b60* list) {
    GameState* game = GameState::GetInstance();
    GameObject* leader = game->GetUnknownGameObject();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* manager = func_02057924();
    unsigned int* flags = GlobalFlags_GetInstance();
    if (self->state == 0) {
        leader->obj3D_.MakeHidden();
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        if (!IsField0Null_02046b08((void**)resources->unknown_ptr_array_3700[0])) return;
        SetFlags00(resources, 0x10);
        FlagWord_SetBits(flags, 1);
        func_020a0cc4(0x7000);
        self->task = loader->QueueLoadFile(data_ov017_021d771c[self->kind], 0);
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x7000), 0x7000);
        self->allocator.Reset();
        BattleStateTable021a6648* table = (BattleStateTable021a6648*)resources->vramStates_;
        Foo0207df50* fields = &table->transition;
        VramState_Rewind(fields);
        NNS_GfdGetFrmTexVramState(self->backup);
        NNS_GfdGetFrmPlttVramState(self->pair);
        void* copy = self->allocator.Allocate(length);
        memcpy(copy, data, length);
        CleanInvalidateCacheRange(copy, length);
        func_02057e6c(manager, 0xc, &self->allocator, copy, length, fields);
        self->state++;
    } else if (self->state == 2) {
        SetMainBrightness(resources, 0, 0x1e);
        self->timer = 0;
        self->state++;
    } else if (self->state == 3) {
        self->timer += game->GetTickCount();
        if (self->timer <= data_ov017_021d6aa8[self->kind * 3]) return;
        loader->RemoveTask(self->task);
        self->task = -1;
        Vector3i scale = data_ov017_021d6ab4;
        EventParams021a6648 params;
        params.name[0] = 0;
        params.enabled = 1;
        params.field_12 = 0;
        params.field_14 = -1; params.field_16 = -1; params.field_18 = -1; params.field_1a = -1;
        params.field_1c = -0x1000;
        params.field_20 = 0; params.field_24 = 0; params.field_28 = 0;
        params.position.x = 0; params.position.y = 0; params.position.z = 0;
        params.field_38 = 0; params.field_3c = 0; params.field_40 = 0;
        params.scale.x = 0x1000; params.scale.y = 0x1000; params.scale.z = 0x1000;
        params.bit0 = 0; params.bit1 = 0; params.bit2 = 1; params.bit3 = 0;
        params.bit4 = 0; params.bit5 = 0; params.bit6 = 0; params.bit7 = 0;
        if (self->kind == 2) sprintf(params.name, data_ov017_021d7778);
        else sprintf(params.name, data_ov017_021d777a);
        params.position = leader->obj3D_.position_;
        params.scale = scale;
        params.enabled = 1;
        FindNodeAndProcess02057fb4(manager, 0xc, &params);
        if (self->kind == 2) {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xa3, 0xa3);
            SePlayer_PlayExtra(&g_sePlayer, 5, 0);
        } else {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xb2, 0xb2);
            SePlayer_PlayExtra(&g_sePlayer, 2, 0);
        }
        self->timer = 0;
        self->state++;
    } else if (self->state == 4) {
        self->timer += game->GetTickCount();
        if (self->timer < data_ov017_021d6aa9[self->kind * 3]) return;
        leader->obj3D_.MakeVisible();
        self->state++;
    } else if (self->state == 5) {
        self->timer += game->GetTickCount();
        if (self->timer < data_ov017_021d6aaa[self->kind * 3]) return;
        GameObject_EnableControl(leader);
        SePlayer_UnloadExtraArchiveB(&g_sePlayer);
        ClearFlags00(resources, 0x10);
        FlagWord_ClearBits((FlagWord020466f4*)flags, 1);
        SetCombatModeFromCase020dc2d0(0);
        if (self->reset) {
            RegisterNodeAndNotify_0219593c();
            TextQueue_Reset(TextQueue_GetInstance());
        }
        if (!arg0->unknown_b_ && func_02046b60(arg1, 0xa)) {
            func_02046a8c(arg1, var2->unknown_ptr_3718);
            ClearFlags00(var2, 0x800);
        }
        if (!self->skipLists && ListContainsId(list, 0x40)) func_02046a8c(list, resources->fieldTasks_[0x27]);
        func_ov017_021a6b30(self);
        self->done = 1;
    }
}
