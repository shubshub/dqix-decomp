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
extern "C" unsigned int* func_020d6c00();
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" int func_02046b08(void**);
extern "C" void func_020466e4(unsigned int*, unsigned int);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_020bb700(int*);
extern "C" void func_020bb910(int*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Struct_0203d028*);
extern "C" void func_02057fb4(void*, int, void*);
extern "C" void func_0205ebc0(void*, int, int);
extern "C" void func_0205ebfc(void*, int, int);
extern "C" void func_020397c0(void*);
extern "C" void func_0205ebec(void*);
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" void func_020dc2d0(int);
extern "C" void func_ov017_0219593c();
extern "C" Struct_020d7aa0_2* func_020d7a50();
extern "C" void func_020d7aa0(Struct_020d7aa0_2*);
extern "C" int func_02046b60(Struct_02038598_5*, int);
extern "C" void func_02046a8c(Struct_02038598_5*, void*);
extern "C" void func_ov017_021a6b30(Struct_ov017_021a6648_2*);
extern const char* data_ov017_021d771c[3];
extern AllocatorUnion data_02114e20;
extern unsigned char data_ov017_021d6aa8[9];
extern Vector3i data_ov017_021d6ab4;
extern char data_ov017_021d7778[], data_ov017_021d777a[];
extern char g_sePlayer;
extern unsigned char data_ov017_021d6aa9[9], data_ov017_021d6aaa[9];

// USA: func_ov017_021a6648
extern "C" ARM void func_ov017_021a6648(Struct_ov017_021a6648_2* arg0, Struct_02038598_5* arg1) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = var0->GetUnknownGameObject();
    GameResources* var2 = GetGameResources();
    BackgroundLoader* var3 = BackgroundLoader::GetInstance();
    void* var4 = func_02057924();
    unsigned int* var5 = func_020d6c00();
    if (arg0->unknown_8_ == 0) {
        var1->obj3D_.MakeHidden();
        func_020397cc((Struct_02018300_3*)var1, 1);
        if (!func_02046b08((void**)var2->unknown_ptr_array_36fc[1])) return;
        SetFlags00(var2, 0x10);
        func_020466e4(var5, 1);
        func_020a0cc4(0x7000);
        self->task = loader->QueueLoadFile(data_ov017_021d771c[self->kind], 0);
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        self->allocator.CreateTypeA(AllocateAligned4_02012d88(&data_02114e20, 0x7000), 0x7000);
        self->allocator.Reset();
        BattleStateTable021a6648* table = (BattleStateTable021a6648*)resources->unknown_2cc;
        Foo0207df50* fields = &table->transition;
        CopyInternalFields0207df50(fields);
        BackupPairTableToBuffer_020bb700(self->backup);
        ReadGlobalPair020bb910(self->pair);
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
            SetForwardAndStore0205ebc0(&g_sePlayer, 0xa3, 0xa3);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 5, 0);
        } else {
            SetForwardAndStore0205ebc0(&g_sePlayer, 0xb2, 0xb2);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 2, 0);
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
        SetByteField0x253_020397c0(leader);
        ForwardField0xc0_0205ebec(&g_sePlayer);
        ClearFlags00(resources, 0x10);
        ClearFlags020466f4((FlagWord020466f4*)flags, 1);
        SetCombatModeFromCase020dc2d0(0);
        if (self->reset) {
            RegisterNodeAndNotify_0219593c();
            TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
        }
        if (!arg0->unknown_b_ && func_02046b60(arg1, 0xa)) {
            func_02046a8c(arg1, var2->unknown_ptr_3718);
            ClearFlags00(var2, 0x800);
        }
        if (!arg0->unknown_b_ && func_02046b60(arg1, 0x40)) func_02046a8c(arg1, var2->unknown_ptr_array_3afc[0x27]);
        func_ov017_021a6b30(arg0);
        arg0->unknown_1_ = 1;
    }
}
