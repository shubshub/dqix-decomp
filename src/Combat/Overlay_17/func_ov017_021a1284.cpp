#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Zone3D.h>
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
enum { Enum_ov017_021a1284_1253 = 0x4e1, Enum_ov017_021a1284_1276 = 0x4f8, Enum_ov017_021a1284_1588 = 0x56c, Enum_ov017_021a1284_1608 = 0x578, Enum_ov017_021a1284_716 = 0x27c, Enum_ov017_021a1284_14080 = 0x34f0, Enum_ov017_021a1284_1060 = 0x444, Enum_ov017_021a1284_95744 = 0x16c00, Enum_ov017_021a1284_336 = 0x144 };
#else
enum { Enum_ov017_021a1284_1253 = 0x4e5, Enum_ov017_021a1284_1276 = 0x4fc, Enum_ov017_021a1284_1588 = 0x634, Enum_ov017_021a1284_1608 = 0x648, Enum_ov017_021a1284_716 = 0x2cc, Enum_ov017_021a1284_14080 = 0x3700, Enum_ov017_021a1284_1060 = 0x424, Enum_ov017_021a1284_95744 = 0x17600, Enum_ov017_021a1284_336 = 0x150 };
#endif

struct Struct_0203d028;
struct Struct_02018300_3;
struct Struct_0203de2c_3;
struct Struct_02058564_2;
struct Struct_02048150;
struct Struct_ov017_021a1284_7;
struct Struct_ov017_021a1284_8 {
    char unknown_0_[4];
    SafeAllocator* unknown_4_;
    void* unknown_8_;
    SafeAllocator* unknown_c_;
    SafeAllocator* unknown_10_;
    SafeAllocator* unknown_14_;
    char unknown_18_[Enum_ov017_021a1284_1253 - 0x18];
    signed char unknown_4e5_;
    signed char unknown_4e6_;
    char unknown_4e7_[0x15];
    int unknown_4fc_;
    char unknown_500_[Enum_ov017_021a1284_1588 - Enum_ov017_021a1284_1276 - 4];
    unsigned short unknown_634_;
};
struct Struct_ov017_021a1284 {
    char unknown_0_[1];
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_ov017_021a1284_8* unknown_1c_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned char unknown_22_;
};
struct Struct_ov017_021a1284_2 { char unknown_0_[0x5b0]; };
struct Struct_ov017_021a1284_3 {
    char unknown_0_[Enum_ov017_021a1284_716];
    Struct_ov017_021a1284_2 unknown_2cc_;
    char unknown_87c_[1];
    char unknown_87d_[Enum_ov017_021a1284_14080 - Enum_ov017_021a1284_716 - 0x5b1];
    void** unknown_3700_;
};
struct Struct_ov017_021a1284_4 {
    char unknown_0_[Enum_ov017_021a1284_1060];
    int unknown_424_;
    char unknown_428_[0x418];
    char unknown_840_[1];
};
struct Struct_ov017_021a1284_5 {
    char unknown_0_[0xb0];
    unsigned short unknown_b0_;
    unsigned short unknown_b2_;
    unsigned short unknown_b4_;
    char unknown_b6_[Enum_ov017_021a1284_336 - 0xb6];
    void* unknown_150_;
};
struct Struct_ov017_021a1284_6 { char unknown_0_[0x56b]; unsigned char unknown_56b_0_ : 4; unsigned char unknown_56b_4_ : 4; };

struct Struct_0203dce4_2;
extern "C" Struct_0203dce4_2* func_0203cf4c();
extern "C" Zone3D* func_02012fe4();
extern "C" Struct_02058564_2* func_02057924();
extern "C" int* func_0202ae18();
void* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" int func_02039850(void*);
extern "C" int func_020100a8(GameState*);
extern "C" void func_ov017_021a1178(GameResources*, int);
extern "C" void func_0203983c(unsigned char*, int);
extern "C" void func_02043204(char*);
extern "C" void func_0203d008(unsigned char*);
extern "C" void func_0203e0a0(Struct_0203dce4_2*, unsigned short);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void func_ov017_0219bf74();
extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_ov017_0219b938(GameResources*);
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov023_021e2dd8(Struct_ov017_021a1284_8*);
extern "C" void __clear(void*, unsigned int);
extern "C" int func_02011494(char*, void*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" void func_ov023_021e31b0(Struct_ov017_021a1284_7*, unsigned char*, int);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov023_021e338c(char*);
extern "C" void func_ov023_021e3030(Struct_ov017_021a1284_8*);
extern "C" void func_ov017_021a18c8(Struct_ov017_021a1284*);
extern "C" void func_ov017_0219b624(GameResources*);
void ClearField0x98Bit0_0203d018(unsigned char*);
void ReleaseRosterEntries0203de2c(Roster0203de2c*);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void ProcessSlotField58_021a2840(GameResources*);
void CleanupNodeList02058564(NodeList02058564*);
void SetField0x1e28_02042b30(void*, void*);
void VramState_Restore(char*);
extern "C" void func_020432c4(void*);
void VramState_Save(char*);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern "C" int func_0202b7d8(int*);
extern "C" int func_02086ef0(Struct_02048150*, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
extern "C" int func_02046b08(void**);
extern "C" void func_020732a8();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" unsigned char* func_020100f8(char*);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void func_020397c0(void*);
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021a1284
extern "C" ARM void func_ov017_021a1284(TransferEvent021a1284* self, void* unused) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = func_02012fe4();
    EntryList_203dce4* entries = GetGlobalPtr021075f4_0203cf4c();
    NodeList02058564* nodes = func_02057924();
    int* search = func_0202ae18();
    GameObject* player = game->GetUnknownGameObject();
    GameResources* resources = game->GetResources();
    void* global = GetGlobalField0x1c020421a0();
    CancelPendingAction020397cc((Obj020397cc*)player, 1);
    ((PlayerTransfer021a1284*)player)->field_b2 = 0;
    if (self->stage == 0) {
        SetBrightness(resources, -16, 15);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!IsBrightnessTransitionActive(resources)) self->stage = 2;
    } else if (self->stage == 2) {
        if (loader->GetNumQueuedTasks() > 0) return;
        if (GetByteField0x254_02039850(player)) {
            player->obj3D_.unknown_2_ = -1;
            ((PlayerTransfer021a1284*)player)->field_b0 = 0x324;
            ((PlayerTransfer021a1284*)player)->field_b4 = 0x189;
            player->obj3D_.SetHeight(0x1800);
            player->obj3D_.SetRadius(0x1000);
            ComputeAndCall_021a1178(resources, GetField0x3acValue_020100a8(game));
            SetBoolFlag0x254_0203983c((unsigned char*)player, 0);
        }
        unsigned char var9 = 0;
#if defined(jpn)
        func_0204500c((Struct_02021b84*)var8, (char*)&var9, 0);
#else
        func_0204500c((Struct_02021b84*)var8, (char*)&var9, 0, 0xe3);
#endif
        func_02043204((char*)var8);
        func_0203d008((unsigned char*)var3);
        func_0203e0a0(var3, var2->currentZoneID_);
        SetFlags00(var7, 0x10);
        func_020a0cc4(Enum_ov017_021a1284_95744);
        void* var10 = func_02012d88(&data_02114e20, Enum_ov017_021a1284_95744);
        if (!var10) {
            func_020a0c0c();
            arg0->unknown_22_ = 4;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var10, Enum_ov017_021a1284_95744);
        arg0->unknown_8_.Reset();
        func_ov017_0219bf74();
        SafeAllocator* var11;
        SafeAllocator* var12 = &var7->allocator_array_38[0];
        Struct_ov017_021a1284_2* var13 = &((Struct_ov017_021a1284_3*)var7)->unknown_2cc_;
        var12->Reset();
        func_0207df50((Struct_0203d028*)var13);
        func_ov017_0219b938(var7);
        SafeAllocator* var14 = &var7->allocator_array_38[5];
        var14->Reset();
        var11 = var12;
        if (((Struct_ov017_021a1284_4*)var2)->unknown_840_ && func_020981e4((int)((Struct_ov017_021a1284_4*)var2)->unknown_840_, var2->currentZoneID_)) {
            func_ov017_021a316c(var7);
            var11 = &var7->allocator_array_38[7];
            var11->Reset();
        }
        func_020a1df8(5);
        func_020a1ef0(1);
        arg0->unknown_1c_ = (Struct_ov017_021a1284_8*)var11->Allocate(Enum_ov017_021a1284_1608);
        arg0->unknown_1c_->unknown_4e5_ = arg0->unknown_20_;
        arg0->unknown_1c_->unknown_4fc_ = arg0->unknown_21_;
        func_ov023_021e2dd8(arg0->unknown_1c_);
        arg0->unknown_1c_->unknown_4_ = var12;
        arg0->unknown_1c_->unknown_c_ = var14;
        arg0->unknown_1c_->unknown_10_ = var11;
        arg0->unknown_1c_->unknown_14_ = &arg0->unknown_8_;
        arg0->unknown_1c_->unknown_8_ = var13;
        arg0->unknown_1c_->unknown_634_ |= 0x2000;
        if (arg0->unknown_1c_->unknown_4e5_ == 3) {
            unsigned char var15[4];
            __clear(var15, 4);
            unsigned char var16[4];
            unsigned char var17 = 0;
            for (int var18 = 0; var18 < 4; ++var18) var16[var18] = 0xff;
            int var19 = func_02011494((char*)var0, var15);
            for (int var20 = 0; var20 < var19; ++var20) {
                GameObject* var21 = func_0200ff1c(var0, var15[var20]);
                if (!var21) continue;
                Struct_ov017_021a1284_6* var22 = (Struct_ov017_021a1284_6*)((Struct_ov017_021a1284_5*)var21)->unknown_150_;
                int var23;
                if (var22) var23 = var22->unknown_56b_0_ ? 1 : 0;
                else var23 = 0;
                if (!var23) var16[var17++] = var15[var20];
            }
            func_ov023_021e31b0((Struct_ov017_021a1284_7*)arg0->unknown_1c_, var16, var17);
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (func_ov017_021959b4()) SetFlagt_021e338c_021e338c((char*)self->plugin);
        func_ov023_021e3030(self->plugin);
        if (self->plugin->result < 0) self->stage = 4;
    } else if (self->stage == 4) {
        func_ov017_021a18c8(self);
        func_ov017_021a316c(resources);
        resources->allocator_array_38[7].Reset();
        func_ov017_0219b624(resources);
        ClearField0x98Bit0_0203d018((unsigned char*)entries);
        ReleaseRosterEntries0203de2c((Roster0203de2c*)entries);
        ProcessCombatantsIfFlagged_0218f79c(resources);
        ProcessSlotField58_021a2840(resources);
        CleanupNodeList02058564(nodes);
        SetField0x1e28_02042b30(global, ((ResourceTransfer021a1284*)resources)->restored);
        CopyInternalFields0207df50((Foo0207df50*)((ResourceTransfer021a1284*)resources)->restored);
        VramState_Restore(((ResourceTransfer021a1284*)resources)->restored);
        func_020432c4(global);
        VramState_Save(((ResourceTransfer021a1284*)resources)->restored);
        ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GetPtrField0x2a04_02010828(game);
        for (int i = 0; i < 4; ++i) {
            if (func_ov017_0218f5a4(resources, i, 0, 0, 0) && CheckField0NonZero_0202b7d8(search) && ArrayContainsByte_02086ef0(party, i)) {
                func_ov017_021c3fb4(i, 1);
                func_ov017_021c4418(i, -1);
            }
        }
        ClearFlags00(var7, 0x10);
        func_ov017_0219ba0c(var7, 0);
        arg0->unknown_22_ = 5;
    } else if (arg0->unknown_22_ == 5) {
        if (!func_02046b08(((Struct_ov017_021a1284_3*)var7)->unknown_3700_)) return;
        func_020732a8();
        func_ov017_0219bd1c(1, 0, 0, 0);
        if (var2->currentZoneID_ == 0x2710 || var2->currentZoneID_ == 0x2774) {
            ClearFlags04(var7, 0x601fe);
            SetFlags04(var7, 0x10004);
        } else ClearFlags04(var7, 0x601fe);
        arg0->unknown_22_ = 6;
    } else if (arg0->unknown_22_ == 6) {
        if (((Struct_ov017_021a1284_4*)func_02012fe4())->unknown_424_) return;
        func_020a28b0(func_020100f8((char*)var0), 3);
        arg0->unknown_22_ = 7;
    } else if (arg0->unknown_22_ == 7) {
        if (arg0->unknown_20_ == 3) func_020397c0(var6);
        arg0->unknown_1_ = 1;
    }
}
