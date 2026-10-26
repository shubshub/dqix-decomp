#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/GameResources.h"

struct Field150Holder02052e2c;
struct Struct_ov017_021b38c8_2 { char storage[0x70]; };
struct ResourceSlots021b38c8 { Struct_ov017_021b38c8_2 party[0x15]; Struct_ov017_021b38c8_2 unknown_930_; };
struct Struct_0206f81c_8 { char unknown_0_[0x18]; short id; char unknown_1a_[6]; };
struct Struct_0206f81c { char unknown_0_[0x194]; Struct_0206f81c_8 entries[11]; };
struct Struct_ov017_021b38c8_4 {
    unsigned short field_0, slot; SafeAllocator allocators[11];
    char unknown_e0_[0x52c - 0xe0]; SafeAllocator animationAllocator, unknown_540_;
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
struct Struct_ov017_021b38c8_6 { char unknown_0_[8]; short field_8; char unknown_a_[0x18-0xa]; short width, height; };
struct Struct_ov017_021b38c8 {
    char unknown_0_[8]; short combatant; char unknown_a_;
    unsigned char flags;
    char unknown_c_[4]; int tasks[11]; int unknown_3c_; int unknown_40_; int unknown_44_;
};
extern "C" Struct_0206f81c* func_02053c6c(unsigned char*);
extern "C" Struct_ov017_021b38c8_6* func_02052e2c(Field150Holder02052e2c*);
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
static inline int inline_ov017_021b38c8(int first, int second) { return (int)(((long long)first * second + 0x800) >> 12); }

// USA: func_ov017_021b38c8
extern "C" ARM int func_ov017_021b38c8(Struct_ov017_021b38c8* self) {
    SafeAllocator* allocators;
    Struct_0206f81c_8* entries;
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameObject* combatant = func_0200ff1c(game, self->combatant);
    if (!combatant) return 0;
    Struct_ov017_021b38c8_4* var5 = ((Struct_ov017_021b38c8_5*)combatant)->inline_ov017_021b38c8_2();
    if (!var5) return 0;
    Struct_0206f81c* data = func_02053c6c((unsigned char*)combatant);
    if (!data) return 0;
    Struct_ov017_021b38c8_6* scale = func_02052e2c((Field150Holder02052e2c*)combatant);
    if (!scale) return 0;
    if (!combatant->obj3D_.pModel_) {
        GameResources* resources = GetGameResources();
        int partyMember = 0;
        if (self->combatant >= 0 && self->combatant <= 3) partyMember = 1;
        char* slot;
        if (!partyMember) {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->vramStates_;
            slot = table->unknown_930_.storage;
        } else {
            ResourceSlots021b38c8* table = (ResourceSlots021b38c8*)resources->vramStates_;
            slot = table->party[var5->slot + 1].storage;
        }
        func_020543ec((char*)var5, slot);
    }
    int var13[11];
    short var14[12];
    func_02072afc(self->combatant, var13, var14);
    GameObject* object = game->GetGameObjectByIndex(var13[7]);
    if (object && var14[7] != object->obj3D_.unknown_2_) {
        GameObject* first = game->GetGameObjectByIndex(var13[3]);
        GameObject* second = game->GetGameObjectByIndex(var13[4]);
        if (first) first->obj3D_.unknown_2_ = -1;
        if (second) second->obj3D_.unknown_2_ = -1;
    }
    object = game->GetGameObjectByIndex(var13[1]);
    if (object && var14[1] != object->obj3D_.unknown_2_) {
        object = game->GetGameObjectByIndex(var13[0]);
        if (object) object->obj3D_.unknown_2_ = -1;
    }
    if (var14[0] != combatant->obj3D_.unknown_2_ && scale->field_8 < 0) {
        object = game->GetGameObjectByIndex(var13[5]);
        if (object) object->obj3D_.unknown_2_ = -1;
    }
    int var18 = self->flags & 2;
    object = game->GetGameObjectByIndex(var13[8]);
    if (object && var14[8] != object->obj3D_.unknown_2_) var18 = 1;
    int var19;
    int force = self->flags & 1;
    self->flags &= ~1;
    int changed = 0;
    var19 = 1;
    func_02083554(data, var14[7]);
    entries = data->entries;
    allocators = var5->allocators;
    for (int i = 0; i < 11; i++) {
        GameObject* object = game->GetGameObjectByIndex(var13[i]);
        if (!object) continue;
        if (!force) {
            int var24 = var14[i];
            int var25 = object->obj3D_.unknown_2_;
            if (var24 == var25) continue;
        }
        object->obj3D_.unknown_2_ = var14[i];
        if (var14[i] < 0) continue;
        Struct_0206f81c_8* entry = func_02083554(data, var14[i]);
        if (!entry) continue;
        char path[0x80];
        if (!func_02072e94(path, self->combatant, i, entry, entries)) {
            object->obj3D_.Initialize();
            object->obj3D_.unknown_2_ = var14[i];
            continue;
        }
        object->obj3D_.Destroy();
        allocators[i].Reset();
        if (var19) { loader->AddFence(); var19 = 0; }
        self->tasks[i] = loader->QueueLoadFileInGP2(data_ov017_021d7a38[0], path, &allocators[i]);
        if ((unsigned int)i <= 1) {
            int height = scale->height;
            short var29 = 0.065f * (float)inline_ov017_021b38c8(height, scale->width);
            short var30 = 0.065f * (float)height;
            object->obj3D_.SetScale(var29, var30, var29);
            var18 = 1;
        } else if (i == 2 || i == 3 || (unsigned int)(i - 7) <= 2) {
            int var31 = fix32_Divide(0x1000, inline_ov017_021b38c8(scale->height, scale->width));
            int var32 = fix32_Divide(0x1000, scale->height);
            int depth = var31;
            if (i == 2 || i == 3 || i == 7) {
                int var34 = scale->height - ((scale->height - 0x1000) >> 1);
                var31 = inline_ov017_021b38c8(var31, var34);
                var32 = inline_ov017_021b38c8(var32, var34);
                depth = inline_ov017_021b38c8(depth, var34);
            }
            object->obj3D_.SetScale(var31, var32, depth);
        }
        if (i == 8 || i == 1) var18 = 1;
        changed = 1;
    }
    if (var18) {
        char animation[0x28];
        char extra[0x28];
        char path[0x50];
        func_02072d58(self->combatant, animation, extra);
        if (self->flags & 4) {
            animation[0] = 'm';
            sprintf(path, data_ov017_021d7ace, animation);
            self->flags &= ~4;
        } else sprintf(path, data_ov017_021d7ad6, animation);
        combatant->obj3D_.RemoveAllAnimationPackages();
        var5->animationAllocator.Reset();
        var5->unknown_540_.Reset();
        self->unknown_3c_ = loader->QueueLoadFileInGP2(data_ov017_021d7a38[1], path, &var5->animationAllocator);
        sprintf(path, data_ov017_021d7ad6, extra);
        self->unknown_44_ = loader->QueueLoadFileInGP2(data_ov017_021d7a38[1], path, 0);
        changed = 1;
    }
    return changed;
}
