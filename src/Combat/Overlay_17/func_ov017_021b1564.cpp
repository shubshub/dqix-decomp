#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <NitroSDK/Cache.h>
#include <std_library_functions.h>
#include "Resource/Brightness.h"

struct Struct_02109bf4_4;
struct Struct_0209c3b4_2;
struct Struct_02018300_3;
struct Struct_020979c0;
struct Struct_02074b64;
struct Struct_02074bd0;
struct Struct_02074bf4;
struct Struct_0203d028;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_ov017_021b1564_7 {
    unsigned char unknown_0_, unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_020979c0* unknown_1c_;
    char unknown_20_[0x10];
    unsigned char unknown_30_, unknown_31_;
    char unknown_32_[2];
    unsigned int unknown_34_, unknown_38_;
    unsigned int unknown_3c_, unknown_40_, unknown_44_;
    unsigned char unknown_48_, unknown_49_, unknown_4a_;
};
struct Struct_ov017_021b1564_8 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    signed char* unknown_5c_;
#if defined(jpn)
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
};
struct Overlay006021b1564 { char pad_0[0x394]; unsigned short flags; char pad_396[0x9e]; unsigned char result; };
struct BufferTail021b1564 { char pad_0[0x1000]; char work[1]; };
struct Buffer021b1564 { char pad_0[0x820]; BufferTail021b1564 tail; };
struct PlayerView021b1564 { char pad_0[0xae]; short angle; };
struct ResourceBlock021b1564 { char initial[0x5b0]; char restored[1]; };
struct EntryNode021b1564 { char pad_0[0x114]; void* entry; char pad_118[0xc]; int id; char pad_128[0x11]; unsigned char active; };
unsigned int* GetDataPtr02114e04_020d6c00();
Controller021b1564* GetGlobalField0x1c020421a0();
unsigned char* GetFieldIfFlag4_020100f8(char*);
void ClearIntAt0x23c_020a27b8(unsigned char*);
void CancelPendingAction020397cc(Obj020397cc*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, signed char*, int);
enum { Enum_ov017_021b1564_248832 = 0x3b000, Enum_ov017_021b1564_255008 = 0x3c820 };
#else
extern "C" void func_0204500c(void*, signed char*, int, int);
enum { Enum_ov017_021b1564_248832 = 0x3cc00, Enum_ov017_021b1564_255008 = 0x3e420 };
#endif
extern "C" void func_02043204(char*);
extern "C" int func_020457e0(void*);
extern "C" void func_020a27ac(void*);
void SetBrightness(GameResources*, int, int);
extern "C" void func_0209c678(Struct_02109bf4_4*, int);
extern "C" void func_020466e4(unsigned int*, unsigned int);
int IsBrightnessTransitionActive(GameResources*);
extern "C" void func_020dc2bc();
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void func_02043124(void*);
extern "C" void func_020a1df8(int);
extern "C" void func_020a1ef0(int);
extern "C" void func_ov017_021b1ca8(int);
extern "C" void func_020979c0(Struct_020979c0*, unsigned char);
extern "C" void func_ov006_02157a60(Struct_ov017_021b1564*);
extern "C" void func_ov006_021576a0(Struct_ov017_021b1564*, SafeAllocator*, void*);
extern "C" int func_02097a04(Struct_020979c0*);
extern "C" void func_02074af4(void*);
extern "C" void func_02074b64(Struct_02074b64*);
extern "C" void* func_0203cf4c();
extern "C" Zone3D* func_02012fe4();
extern "C" void func_0203e0a0(void*, unsigned short);
extern "C" void func_ov017_0219bf74();
extern "C" int func_020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
extern "C" void func_0203d008(unsigned char*);
extern "C" int func_ov006_02157d7c(Struct_ov017_021b1564*, unsigned int);
extern "C" void func_ov006_02157cc0(Struct_ov017_021b1564*);
extern "C" void func_02097b34(Struct_020979c0*);
extern "C" void func_ov017_021b14ec(Struct_ov017_021b1564_7*);
extern "C" void func_0209c3b4(Struct_0209c3b4_2*, int);
extern "C" void func_02074bd0(Struct_02074bd0*);
extern "C" void func_02074bf4(Struct_02074bf4*);
extern "C" void LoadToMainBG1CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG1ScreenData(void*, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(void*, int, unsigned int);
extern "C" void func_02012da4(AllocatorUnion*, void*);
extern "C" void func_ov017_0218f79c(void*);
void SetAndLockMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021921fc(Vector3i*, short, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021a2fa0(GameResources*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
extern "C" void func_0207df50(Struct_0203d028*);
extern "C" void func_0207df90(char*);
extern "C" void func_020432c4(void*);
extern "C" void func_0207dfac(char*);
void UnlockAndSetMainBrightness(GameResources*, int, int);
extern "C" int* func_0203df78(void*, int);
extern "C" void* func_02040528(int*);
extern "C" void func_ov017_021b8d1c(Struct_ov017_021b1564_6*);
extern "C" void func_020469b4(Struct_0201bdac_2*, Struct_0201bdac*);
extern "C" void func_020397c0(void*);
extern char data_02109bf4[];
extern AllocatorUnion data_02114e20;
extern Struct_ov017_021b1564* data_ov017_021d83ec;
#define REG_MAIN_DISPLAY (*(volatile unsigned int*)0x04000000)
#define REG_SUB_DISPLAY (*(volatile unsigned int*)0x04001000)

static inline int inline_ov017_021b1564(Zone3D* arg0) { SDK_NULL_ASSERT(arg0); return arg0->currentZoneID_; }

// USA: func_ov017_021b1564
extern "C" ARM void func_ov017_021b1564(Transition021b1564* self, TailList020469b4* list) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = game->GetResources();
    unsigned int* global = GetDataPtr02114e04_020d6c00();
    Controller021b1564* controller = GetGlobalField0x1c020421a0();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)game);
    GameObject* player = game->GetUnknownGameObject();
    if (field) ClearIntAt0x23c_020a27b8(field);
    if (self->stage == 0) {
        self->savedFlags = GetFlags00(resources);
        self->savedFlags4 = GetFlags04(resources);
        self->savedFlags8 = GetFlags08(resources);
        SetFlags04(resources, 0x40);
        if (!self->alternate) {
            GameObject* current = game->GetUnknownGameObject();
            if (current) CancelPendingAction020397cc((Obj020397cc*)current, 1);
            if (*controller->action) {
#if defined(jpn)
                func_0204500c(var3, var3->unknown_5c_, 0);
#else
                func_0204500c(var3, var3->unknown_5c_, 0, 0xe3);
#endif
                var3->unknown_998_ = 1;
            } else func_02043204((char*)var3);
            arg0->unknown_48_ = 100;
            return;
        }
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 100) {
        if (var3->unknown_998_) return;
        if (func_020457e0(var3) == 1) {
            func_02043204((char*)var3);
            arg0->unknown_1_ = 1;
            if (var4) func_020a27ac(var4);
            return;
        }
        func_02043204((char*)var3);
        SetBrightness(var1, -16, 16);
        func_0209c678((Struct_02109bf4_4*)data_02109bf4, 15);
        func_020466e4(var2, 1);
        arg0->unknown_48_ = 1;
        return;
    } else if (arg0->unknown_48_ == 1) {
        if (IsBrightnessTransitionActive(var1)) return;
        func_020dc2bc();
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 2) {
        func_020a0cc4(Enum_ov017_021b1564_255008);
        Struct_ov017_021b1564_3* var7 = (Struct_ov017_021b1564_3*)func_02012d88(&data_02114e20, Enum_ov017_021b1564_255008);
        if (!var7) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            if (var4) func_020a27ac(var4);
            return;
        }
        Struct_ov017_021b1564_2* var8 = &var7->unknown_820_;
        Struct_ov017_021b1564_8* var9 = func_020421a0();
        func_02043204((char*)var9);
        func_02043124(var9);
        arg0->unknown_8_.CreateTypeA(var7, Enum_ov017_021b1564_248832);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = (Struct_020979c0*)arg0->unknown_8_.Allocate(0x20);
        data_ov017_021d83ec = (Struct_ov017_021b1564*)arg0->unknown_8_.Allocate(0x438);
        if (!arg0->unknown_1c_ || !data_ov017_021d83ec) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            if (var4) func_020a27ac(var4);
            return;
        }
        func_020a1df8(6);
        func_020a1ef0(1);
        func_ov017_021b1ca8(1);
        func_020979c0(arg0->unknown_1c_, 2);
        func_ov006_02157a60(data_ov017_021d83ec);
        if (arg0->unknown_49_) data_ov017_021d83ec->unknown_394_ |= 2;
        func_ov006_021576a0(data_ov017_021d83ec, &arg0->unknown_8_, var8->unknown_1000_);
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 3) {
        if (!func_02097a04(arg0->unknown_1c_)) return;
        ++arg0->unknown_48_;
        arg0->unknown_30_ = 0;
        arg0->unknown_31_ = 0;
        func_02074af4(arg0->unknown_20_);
        arg0->unknown_34_ = (REG_MAIN_DISPLAY & 0x1f00) >> 8;
        func_02074b64((Struct_02074b64*)arg0->unknown_20_);
        arg0->unknown_38_ = (REG_SUB_DISPLAY & 0x1f00) >> 8;
        SetFlags04(var1, 0x8de);
        void* var10 = func_0203cf4c();
        Zone3D* var11 = func_02012fe4();
        func_0203e0a0(var10, var11->currentZoneID_);
        func_ov017_0219bf74();
        if (func_020981e4((int)var11->unk_840, inline_ov017_021b1564(var11))) {
            func_ov017_021a316c(var1);
            var1->allocator_array_38[7].Reset();
        }
        func_0203d008((unsigned char*)var10);
        SetFlags00(var1, 16);
        return;
    } else if (arg0->unknown_48_ == 4) {
        func_0203d008((unsigned char*)func_0203cf4c());
        unsigned int var12 = GameState::GetInstance()->GetTickCount();
        if (!func_ov006_02157d7c(data_ov017_021d83ec, var12)) return;
        arg0->unknown_4a_ = data_ov017_021d83ec->unknown_434_;
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 5) {
        if (arg0->unknown_49_) {
            func_ov006_02157cc0(data_ov017_021d83ec);
            func_02097b34(arg0->unknown_1c_);
            func_ov017_021b14ec(arg0);
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            if (var4) func_020a27ac(var4);
            return;
        }
        func_0209c3b4((Struct_0209c3b4_2*)data_02109bf4, 7);
        func_ov006_02157cc0(data_ov017_021d83ec);
        data_ov017_021d83ec = 0;
        func_ov017_021b1ca8(0);
        func_02097b34(arg0->unknown_1c_);
        func_02074bd0((Struct_02074bd0*)arg0->unknown_20_);
        REG_MAIN_DISPLAY = (REG_MAIN_DISPLAY & ~0x1f00) | (arg0->unknown_34_ << 8);
        func_02074bf4((Struct_02074bf4*)arg0->unknown_20_);
        REG_SUB_DISPLAY = (REG_SUB_DISPLAY & ~0x1f00) | (arg0->unknown_38_ << 8);
        void* var13 = func_02012d88(&data_02114e20, 0x800);
        if (var13) {
            memset(var13, 0, 0x800);
            CleanInvalidateCacheRange(var13, 0x20);
            LoadToMainBG1CharacterData(var13, 0, 0x20);
            LoadToMainBG2CharacterData(var13, 0, 0x20);
            CleanInvalidateCacheRange(var13, 0x800);
            LoadToMainBG1ScreenData(var13, 0, 0x800);
            LoadToMainBG2ScreenData(var13, 0, 0x800);
            func_02012da4(&data_02114e20, var13);
        }
        ClearFlags00(var1, ~0u);
        ClearFlags04(var1, ~0u);
        ClearFlags08(var1, ~0u);
        SetFlags00(var1, arg0->unknown_3c_);
        SetFlags04(var1, arg0->unknown_40_);
        SetFlags08(var1, arg0->unknown_44_);
        func_ov017_0218f79c(var1);
        SetAndLockMainBrightness(var1, -16, 1);
        func_ov017_021921fc(&var5->obj3D_.position_, ((Struct_ov017_021b1564_4*)var5)->unknown_ae_, 1);
        func_ov017_0219bd1c(1, 0, 0, 0);
        func_ov017_021a2fa0(var1);
        func_ov017_0219b624(var1);
        func_ov017_0219ba0c(var1, 0);
        Struct_ov017_021b1564_5* var14 = (Struct_ov017_021b1564_5*)var1->unknown_2cc_;
        Struct_ov017_021b1564_8* var15 = func_020421a0();
        func_0207df50((Struct_0203d028*)var14->unknown_5b0_);
        func_0207df90(var14->unknown_5b0_);
        func_020432c4(var15);
        func_0207dfac(var14->unknown_5b0_);
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 6) {
        func_ov017_021b14ec(arg0);
        if (arg0->unknown_49_) SetBrightness(var1, 0, 8);
        ++arg0->unknown_48_;
        return;
    } else if (arg0->unknown_48_ == 7) {
        int var16 = 0;
        if (arg0->unknown_49_) {
            if (!IsBrightnessTransitionActive(var1)) var16 = 1;
        } else {
            UnlockAndSetMainBrightness(var1, 0, 15);
            var16 = 1;
            if (!arg0->unknown_4a_) {
                int* var17 = func_0203df78(func_0203cf4c(), 100);
                void* var18;
                if (var17) var18 = func_02040528(var17);
                Struct_ov017_021b1564_6* var19 = (Struct_ov017_021b1564_6*)var1->unknown_ptr_array_36fc[5];
                func_ov017_021b8d1c(var19);
                var19->unknown_114_ = var18;
                var19->unknown_124_ = 0xc4;
                var19->unknown_139_ = 1;
                func_020469b4(arg1, (Struct_0201bdac*)var19);
            }
        }
        if (!var16) return;
        GameObject* var20 = var0->GetUnknownGameObject();
        if (var20) func_020397c0(var20);
        func_020a0c0c();
        arg0->unknown_1_ = 1;
    }
}
