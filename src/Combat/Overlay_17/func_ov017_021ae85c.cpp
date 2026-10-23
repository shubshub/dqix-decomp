#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/TextQueue.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "World/ZoneLootableRecord.h"
#include "Resource/GameResources.h"

struct Bytes02033b88;
struct Obj020397cc;
struct Obj02033b68;
struct SePlayer;
struct Vec3copy0202ec84;
struct Vec3Target0203a46c;
struct StructAt020473c8;
struct Container020dedd0 { unsigned int fields[4]; };
struct StructDE234_020de234 {
    int fields[4]; unsigned int low:10, mid:10, kind:8, unused:4;
};
struct Struct_02015ef4_5 { unsigned int unknown_0_[28]; };
struct Struct_ov017_021ae85c_4 { char unknown_0_[0x230]; Struct_02015ef4_5 unknown_230_; };
struct Struct_ov017_021ae85c_5 {
#if defined(jpn)
    char unknown_0_[0x620];
#else
    char unknown1_0_[0x600];
#endif
    Struct_02012fa4 unknown_600_[6];
#if defined(jpn)
    char unknown_950_[0x2794 - 0x950];
#else
    char unknown_930_[0x2754 - 0x930];
#endif
    Struct_0201099c_10 unknown_2754_;
};
struct Struct_ov017_021ae85c {
#if defined(jpn)
    char unknown_0_[0x228];
#else
    char unknown1_0_[0x2d8];
#endif
    int unknown_2d8_; char unknown_2dc_[0xa]; unsigned char unknown_2e6_;
};
struct Struct_ov017_021ae85c_2 {
    unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; unsigned char unknown_8_, unknown_9_;
    unsigned short unknown_a_; short unknown_c_; char unknown_e_[2]; int unknown_10_;
    Vector3fix unknown_14_; int unknown_20_, unknown_24_; Struct_02012fa4* unknown_28_; SafeAllocator unknown_2c_;
};
struct Struct_ov017_021ae85c_3 {
    SafeAllocator unknown_0_; char unknown_14_[0x18]; Struct_0201099c_10* unknown_2c_;
    int unknown_30_, unknown_34_;
};
extern "C" Struct_ov017_021ae85c_5* func_02012fe4();
extern "C" void* func_0202ae18();
extern "C" int func_0202c540(void*);
extern "C" void func_ov017_021aeea8(Event021ae85c*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetByteIfChanged02033b68(Obj02033b68*, int);
void SePlayer_Play(SePlayer*, int, int);
StructDE234_020de234* FindElementByKey020dedd0(Container020dedd0*, int);
int GetField0x3acValue_020100a8(GameState*);
unsigned short GetPreferredPackedField020de234(StructDE234_020de234*, int);
void SetByteField0x253_020397c0(void*);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
void CopyState0207dfc8(State0207dfc8*, State0207dfc8*);
void VramState_Restore(char*);
void Forward02047b30(void*, int, int, int);
void VramState_Save(char*);
Controller021ae85c* GetGlobalField0x1c020421a0();
extern "C" void __clear(void*, int);
extern "C" void* func_020de824(void*);
extern "C" void func_0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
void* GetGlobalResetObj020d7a50();
void* GetField0x3b0Value_020100bc(GameState*);
void ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
void SetVec3At0x1c(Vec3Target0203a46c*, int, int, int);
void RenderFlaggedIndexedEntry(StructAt020473c8*, int);
extern SePlayer g_sePlayer;
#if defined(jpn)
#define data_ov017_021d79a8 data_ov017_021d80dc
#endif
extern const char data_ov017_021d79a8[];
extern AllocatorUnion data_02114e20;
static inline Struct_ov017_021ae85c_4* inline_ov017_021ae85c(GameResources* arg0) {
    return (Struct_ov017_021ae85c_4*)arg0->unknown_2cc_;
}

// USA: func_ov017_021ae85c
extern "C" ARM void func_ov017_021ae85c(Struct_ov017_021ae85c_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_02012fe4();
    BackgroundLoader* var1 = BackgroundLoader::GetInstance();
    void* var2 = func_0202ae18();
    GameResources* var3 = GetGameResources();
    if (func_0202c540(var2)) {
        if (var3->unknown_42e2_) {
            func_ov017_021aeea8(arg0); arg0->unknown_1_ = 1; return;
        }
        if (arg0->unknown_9_ != 1) {
            if (arg0->unknown_9_ == 0) return;
            if (arg0->unknown_9_ == 2) { arg0->unknown_1_ = 1; return; }
        }
    }
    if (self->stage == 0) {
        GameObject* actor = game->GetUnknownGameObject();
        if (!actor) { func_ov017_021aeea8(self); self->done = 1; return; }
        SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
        CancelPendingAction020397cc((Obj020397cc*)actor, 1);
        self->timer = 5; self->stage = 1;
    } else if (self->stage == 1) {
        self->timer--;
        if (self->timer) return;
        GameObject* actor = game->GetUnknownGameObject();
        if (actor) SetByteIfChanged02033b68((Obj02033b68*)actor, 8);
        SePlayer_Play(&g_sePlayer, 0x5b, 0);
        self->stage = 2; self->timer = 30;
    } else if (self->stage == 2) {
        self->timer--;
        if (self->timer) return;
        Zone021ae85c* zone = func_02012fe4();
        StructDE234_020de234* entry = FindElementByKey020dedd0(&zone->container, self->key);
        if (entry) {
            self->sprite = &zone->sprites[GetField0x3acValue_020100a8(game)];
            MaybeInvoke0204719c_02047230(self->sprite);
            char filename[0x80];
            sprintf(filename, data_ov017_021d79a8, (signed char)entry->kind, GetPreferredPackedField020de234(entry, 0));
            self->task = loader->QueueLoadFile(filename, 0);
        } else {
            func_ov017_021aeea8(arg0); arg0->unknown_1_ = 1;
            func_020397c0(var0->GetUnknownGameObject()); return;
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* file = 0; unsigned int length = 0;
        loader->GetLoadedFileByID(self->task, &file, &length);
        if (file) {
            void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x100);
            if (buffer) {
                self->allocator.ResetAllocatorPointer();
                self->allocator.CreateTypeA(buffer, 0x100); self->allocator.Reset();
                MaybeInvoke0204719c_02047230(self->sprite); func_0204719c(self->sprite);
                State0207dfc8 saved;
                CopyState0207dfc8(&ResourceStateBuffer021ae85c(resources)->spriteTables, &saved);
                VramState_Restore((char*)&saved);
                Forward02047b30(self->sprite, (int)file, length, (int)&self->allocator);
                VramState_Save((char*)&saved);
            } else {
                func_ov017_021aeea8(arg0); arg0->unknown_1_ = 1;
                func_020397c0(var0->GetUnknownGameObject());
                var1->RemoveTask(arg0->unknown_10_); return;
            }
        }
        var1->RemoveTask(arg0->unknown_10_);
        Struct_0208cb08* var13 = func_02094a00();
        func_02094b3c(var13, 10);
        func_02094b30(var13, 0x1f9, 0);
        arg0->unknown_8_ = 4;
    } else if (arg0->unknown_8_ == 4) {
        if (!func_02094b4c(func_02094a00())) return;
        func_020421a0();
        char var14[0x80] = {};
        Struct_ov017_021ae85c_5* var15 = func_02012fe4();
        Struct_ov017_021ae85c_3 var16;
        var16.unknown_0_.ResetAllocatorPointer();
        func_020de824(var16.unknown_14_);
        func_0207cbe8((char*)&var16); func_0207cbe8((char*)&var16);
        var16.unknown_2c_ = &var15->unknown_2754_;
        if (func_0207d538(&var16, 2, (unsigned short)arg0->unknown_c_, var14, 1))
#if defined(jpn)
            func_020d7e10(func_020d7a50(), var14, 0, 0, 1);
#else
            func_020d7e10(func_020d7a50(), var14, 0, 0, 1, 1);
#endif
        SePlayer_Play(&g_sePlayer, 14, 0);
        self->stage = 5; self->timer = 20; self->fade = 61;
    } else if (self->stage == 5) {
        self->timer--;
        int tick = game->GetTickCount();
        void* camera = GetField0x3b0Value_020100bc(game);
        Vector3fix position = self->position;
        if (self->angle < 0x191e) self->angle += tick * 0x199;
        position.y += fix32sin(self->angle);
        int x, y;
        if (camera) {
            ComputeTwoFromVec3_0202ec84(camera, (Vec3copy0202ec84*)&position, &x, &y);
        }
        func_0203a46c((Struct_0203a46c*)arg0->unknown_28_, (var20 - 12) << 12, (var21 - 40) << 12, 0);
        func_020473c8((Struct_02015ef4_2*)arg0->unknown_28_, 1);
        if (!arg0->unknown_a_) { arg0->unknown_8_ = 6; arg0->unknown_a_ = 7; }
    } else if (arg0->unknown_8_ == 6) {
        arg0->unknown_a_--;
        int var22 = var0->GetTickCount();
        void* var23 = func_020100bc(var0);
        Vector3fix var24 = arg0->unknown_14_;
        var24.y += fix32sin(arg0->unknown_20_);
        if (arg0->unknown_24_) {
            int var25, var26;
            if (var23) {
                func_0202ec84(var23, (Struct_02015ef4*)&var24, &var25, &var26);
            }
            func_0203a46c((Struct_0203a46c*)arg0->unknown_28_, (var25 - 12) << 12, (var26 - 40) << 12, 0);
            func_020473c8((Struct_02015ef4_2*)arg0->unknown_28_, 1);
            arg0->unknown_24_ -= var22;
            arg0->unknown_28_->unknown_82_ = arg0->unknown_24_ > 31 ? 31 : arg0->unknown_24_;
            if (arg0->unknown_24_ < 0) arg0->unknown_24_ = 0;
        }
        if (!arg0->unknown_a_) { func_020421a0(); arg0->unknown_8_ = 7; }
        else if (arg0->unknown_a_ == 5) {
            GameObject* var27 = var0->GetUnknownGameObject();
            func_020397c0(var27); func_02033b68((Struct_02033b68*)var27, 0);
        }
    } else if (arg0->unknown_8_ == 7) {
        Struct_ov017_021ae85c* var28 = func_020421a0();
        var28->unknown_2d8_ = 0; var28->unknown_2e6_ = 1;
        func_02094ab0(func_02094a00());
        func_ov017_021aeea8(arg0); arg0->unknown_1_ = 1;
    }
}
