#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Struct_02052e2c;
struct Struct_ov017_021b38c8_2 { char unknown_0_[0x70]; };
struct Struct_ov017_021b38c8_3 { Struct_ov017_021b38c8_2 unknown_0_[0x15]; Struct_ov017_021b38c8_2 unknown_930_; };
struct Struct_0206f81c_8 { char unknown_0_[0x18]; short unknown_18_; char unknown_1a_[6]; };
struct Struct_0206f81c { char unknown_0_[0x194]; Struct_0206f81c_8 unknown_194_[11]; };
struct Struct_ov017_021b38c8_4 {
    unsigned short unknown_0_, unknown_2_; SafeAllocator unknown_4_[11];
    char unknown_e0_[0x52c - 0xe0]; SafeAllocator unknown_52c_, unknown_540_;
};
struct Struct_ov017_021b38c8_5 {
#if defined(jpn)
    char unknown_0_[0x148];
#else
    char unknown1_0_[0x154];
#endif
    Struct_ov017_021b38c8_4* unknown_154_;
    Struct_ov017_021b38c8_4* inline_ov017_021b38c8_2() { return unknown_154_; }
};
struct Struct_ov017_021b38c8_6 { char unknown_0_[8]; short unknown_8_; char unknown_a_[0x18-0xa]; short unknown_18_, unknown_1a_; };
struct Struct_ov017_021b38c8 {
    char unknown_0_[8]; short unknown_8_; char unknown_a_;
    unsigned char unknown_b_;
    char unknown_c_[4]; int unknown_10_[11]; int unknown_3c_; int unknown_40_; int unknown_44_;
};
extern "C" Struct_0206f81c* func_02053c6c(unsigned char*);
extern "C" Struct_ov017_021b38c8_6* func_02052e2c(Struct_02052e2c*);
extern "C" void func_020543ec(char*, char*);
extern "C" void func_02072afc(int, int*, short*);
extern "C" Struct_0206f81c_8* func_02083554(Struct_0206f81c*, int);
extern "C" int func_02072e94(char*, int, int, Struct_0206f81c_8*, Struct_0206f81c_8*);
extern "C" void func_02072d58(int, char*, char*);
#if defined(jpn)
#define data_ov017_021d7a38 data_ov017_021d8188
#define data_ov017_021d7ace data_ov017_021d8210
#define data_ov017_021d7ad6 data_ov017_021d8218
#endif
extern const char* data_ov017_021d7a38[2];
extern char data_ov017_021d7ace[], data_ov017_021d7ad6[];
static inline int inline_ov017_021b38c8(int arg0, int arg1) { return (int)(((long long)arg0 * arg1 + 0x800) >> 12); }

// USA: func_ov017_021b38c8
extern "C" ARM int func_ov017_021b38c8(Reload021b38c8* self) {
    SafeAllocator* allocators;
    Entry02083554* entries;
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, self->combatant);
    if (!combatant) return 0;
    BattleAssets021b38c8* assets = ((Combatant021b38c8*)combatant)->GetAssets();
    if (!assets) return 0;
    Container02083554* data = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (!data) return 0;
    Scale021b38c8* scale = GetField150Ptr0x488_02052e2c((Field150Holder02052e2c*)combatant);
    if (!scale) return 0;
    if (!combatant->obj3D_.pModel_) {
        GameResources* resources = GetGameResources();
        int partyMember = 0;
        if (self->combatant >= 0 && self->combatant <= 3) partyMember = 1;
        char* slot;
        if (!partyMember) {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->vramStates_;
            slot = table->fallback.storage;
        } else {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->vramStates_;
            slot = table->party[assets->slot + 1].storage;
        }
        func_020543ec((char*)var5, var10);
    }
    int var13[11];
    short var14[12];
    func_02072afc(arg0->unknown_8_, var13, var14);
    GameObject* var15 = var2->GetGameObjectByIndex(var13[7]);
    if (var15 && var14[7] != var15->obj3D_.unknown_2_) {
        GameObject* var16 = var2->GetGameObjectByIndex(var13[3]);
        GameObject* var17 = var2->GetGameObjectByIndex(var13[4]);
        if (var16) var16->obj3D_.unknown_2_ = -1;
        if (var17) var17->obj3D_.unknown_2_ = -1;
    }
    var15 = var2->GetGameObjectByIndex(var13[1]);
    if (var15 && var14[1] != var15->obj3D_.unknown_2_) {
        var15 = var2->GetGameObjectByIndex(var13[0]);
        if (var15) var15->obj3D_.unknown_2_ = -1;
    }
    if (var14[0] != var4->obj3D_.unknown_2_ && var7->unknown_8_ < 0) {
        var15 = var2->GetGameObjectByIndex(var13[5]);
        if (var15) var15->obj3D_.unknown_2_ = -1;
    }
    int var18 = arg0->unknown_b_ & 2;
    var15 = var2->GetGameObjectByIndex(var13[8]);
    if (var15 && var14[8] != var15->obj3D_.unknown_2_) var18 = 1;
    int var19;
    int var20 = arg0->unknown_b_ & 1;
    arg0->unknown_b_ &= ~1;
    int var21 = 0;
    var19 = 1;
    func_02083554(var6, var14[7]);
    var1 = var6->unknown_194_;
    var0 = var5->unknown_4_;
    for (int var22 = 0; var22 < 11; var22++) {
        GameObject* var23 = var2->GetGameObjectByIndex(var13[var22]);
        if (!var23) continue;
        if (!var20) {
            int var24 = var14[var22];
            int var25 = var23->obj3D_.unknown_2_;
            if (var24 == var25) continue;
        }
        var23->obj3D_.unknown_2_ = var14[var22];
        if (var14[var22] < 0) continue;
        Struct_0206f81c_8* var26 = func_02083554(var6, var14[var22]);
        if (!var26) continue;
        char var27[0x80];
        if (!func_02072e94(var27, arg0->unknown_8_, var22, var26, var1)) {
            var23->obj3D_.Initialize();
            var23->obj3D_.unknown_2_ = var14[var22];
            continue;
        }
        var23->obj3D_.Destroy();
        var0[var22].Reset();
        if (var19) { var3->AddFence(); var19 = 0; }
        arg0->unknown_10_[var22] = var3->QueueLoadFileInGP2(data_ov017_021d7a38[0], var27, &var0[var22]);
        if ((unsigned int)var22 <= 1) {
            int var28 = var7->unknown_1a_;
            short var29 = 0.065f * (float)inline_ov017_021b38c8(var28, var7->unknown_18_);
            short var30 = 0.065f * (float)var28;
            var23->obj3D_.SetScale(var29, var30, var29);
            var18 = 1;
        } else if (var22 == 2 || var22 == 3 || (unsigned int)(var22 - 7) <= 2) {
            int var31 = fix32_Divide(0x1000, inline_ov017_021b38c8(var7->unknown_1a_, var7->unknown_18_));
            int var32 = fix32_Divide(0x1000, var7->unknown_1a_);
            int var33 = var31;
            if (var22 == 2 || var22 == 3 || var22 == 7) {
                int var34 = var7->unknown_1a_ - ((var7->unknown_1a_ - 0x1000) >> 1);
                var31 = inline_ov017_021b38c8(var31, var34);
                var32 = inline_ov017_021b38c8(var32, var34);
                var33 = inline_ov017_021b38c8(var33, var34);
            }
            var23->obj3D_.SetScale(var31, var32, var33);
        }
        if (var22 == 8 || var22 == 1) var18 = 1;
        var21 = 1;
    }
    if (var18) {
        char var35[0x28];
        char var36[0x28];
        char var37[0x50];
        func_02072d58(arg0->unknown_8_, var35, var36);
        if (arg0->unknown_b_ & 4) {
            var35[0] = 'm';
            sprintf(var37, data_ov017_021d7ace, var35);
            arg0->unknown_b_ &= ~4;
        } else sprintf(var37, data_ov017_021d7ad6, var35);
        var4->obj3D_.RemoveAllAnimationPackages();
        var5->unknown_52c_.Reset();
        var5->unknown_540_.Reset();
        arg0->unknown_3c_ = var3->QueueLoadFileInGP2(data_ov017_021d7a38[1], var37, &var5->unknown_52c_);
        sprintf(var37, data_ov017_021d7ad6, var36);
        arg0->unknown_44_ = var3->QueueLoadFileInGP2(data_ov017_021d7a38[1], var37, 0);
        var21 = 1;
    }
    return var21;
}
