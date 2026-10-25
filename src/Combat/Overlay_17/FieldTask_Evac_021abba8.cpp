#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021abba8_340 = 0x148 };
#else
enum { Enum_ov017_021abba8_340 = 0x154 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"



struct Struct_02018300_3;
struct Struct_02038598_5;
struct Struct_0203d028;
struct Struct_02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_0201bdac_2;
struct Struct_0201bdac;

struct Struct_ov017_021abba8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3i unknown_2c_;
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    Vector3i unknown_44_;
};

struct Struct_ov017_021abba8 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned char unknown_8_;
    char unknown_9_;
    short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    char unknown_e_[2];
    SafeAllocator unknown_10_;
    int unknown_24_;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
int ListContainsId(ListHead02046b60* list, int id);
extern "C" void func_ov017_021ac2a8(void* obj);
extern "C" void func_02046a8c(void* list, void* node);
int IsField0Null_02046b08(void** obj);
int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(int g);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void VramState_Rewind(Foo0207df50* p);
extern "C" int func_02057e6c(void* mgr, int id, SafeAllocator* alloc, void* data, unsigned int length, Foo0207df50* fields);
void CopyCountedBytesToIntArray02010834(Base02010834* base, int index, int* out, int* outCount);
extern "C" int func_0202c508(void* p);
void FindNodeAndProcess02057fb4(void* list, int id, void* params);
void SePlayer_LoadExtraArchiveB(void* obj, int arg1, int arg2);
void SePlayer_PlayExtra(void* obj, int a, int b);
void SetBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
void CallListIfFlagsSet_02197528(void);
void GameObject_EnableControl(void* obj);
void SePlayer_UnloadExtraArchiveB(void* obj);
extern "C" void* Scenario_GetInstance(void);
extern "C" void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value);
int CheckBitsInField0x63dc_02011b50(void* obj, int mask);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int v);
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v);
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int v);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void AllocateAndCopyBuf20_021689d8(SafeAllocator* a, void* target);

extern char data_ov017_021d78da;
extern char data_ov017_021d78f1;
extern char g_sePlayer;
extern AllocatorUnion g_mainAllocator;

// Overlay 17, originally func_ov017_021abba8 (USA/EUR 0x021abba8, JPN 0x021ac40c)
extern "C" ARM void FieldTask_Evac(Loader021abba8* self, ListHead02046b60* list) {
    GameState* gs = GameState::GetInstance();
    void* search = func_0202ae18();
    GameResources* res = GetGameResources();
    GameObject* leader = gs->GetUnknownGameObject();
    void* mgr = func_02057924();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int delta = gs->GetTickCount();

    if (self->state == 0) {
        GameObject_DisableControl((Obj020397cc*)leader, 1);
        if (ListContainsId(list, 0x4e)) {
            self->done = 1;
            func_ov017_021ac2a8(self);
            if (ListContainsId(list, 3)) {
                func_02046a8c(list, res->unknown_ptr_array_3700[3]);
            }
        } else if (IsField0Null_02046b08((void**)res->unknown_ptr_array_3700[0])) {
            SetFlags00(res, 0x10);
            FontBankLoader_CancelLoads(FontBankLoader_GetInstance());
            func_020a0cc4(0x2800);
            arg0->unknown_24_ = var5->QueueLoadFile(&data_ov017_021d78da, NULL);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 1) {
        if (var5->GetTaskStatus(arg0->unknown_24_) != 0) {
            if (var5->GetDetailedTaskStatus(arg0->unknown_24_) != 2) {
                var5->RemoveTask(arg0->unknown_24_);
                arg0->unknown_1_ = 1;
            }
            unsigned int length;
            void* data;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x2800), 0x2800);
            self->allocator.Reset();
            Foo0207df50* fields = (Foo0207df50*)(*(char**)((char*)gs->GetUnknownGameObject() + kContextPointerOffset) + 0x568);
            VramState_Rewind(fields);
            void* copy = self->allocator.Allocate(length);
            memcpy(copy, data, length);
            func_02057e6c(mgr, 5, &self->allocator, copy, length, fields);
            loader->RemoveTask(self->task);
            self->state++;
        }
    } else if (self->state == 2) {
        int count = 0;
        int ids[5];
        ObjParams02078484 params[5];
        if (self->active != 0) {
            CopyCountedBytesToIntArray02010834((Base02010834*)gs, leader->obj3D_.actorIndex_, ids, &count);
            for (int i = 0; i < count; i++) {
                self->members |= 1 << ids[i];
            }
            if (var0->GetGameObjectByIndex(0xce) && func_0202c508(var1)) {
                var12[var11] = 0xce;
                arg0->unknown_d_ |= 0x10;
                var11++;
            }
        } else {
            for (int var15 = 0; var15 < 5; var15++) {
                if (arg0->unknown_d_ & (1 << var15)) {
                    if (var15 != 4) {
                        var12[var11] = var15;
                    } else {
                        var12[var11] = 0xce;
                    }
                    var11++;
                }
            }
        }
        for (int var16 = 0; var16 < var11; var16++) {
            GameObject* var17 = var0->GetGameObjectByIndex(var12[var16]);
            if (var17) {
                var13[var16].unknown_0_ = 0;
                var13[var16].unknown_10_ = 1;
                var13[var16].unknown_12_ = 0;
                var13[var16].unknown_14_ = -1;
                var13[var16].unknown_16_ = -1;
                var13[var16].unknown_18_ = -1;
                var13[var16].unknown_1a_ = -1;
                var13[var16].unknown_1c_ = -0x1000;
                var13[var16].unknown_20_ = 0;
                var13[var16].unknown_24_ = 0;
                var13[var16].unknown_28_ = 0;
                var13[var16].unknown_2c_.x = 0;
                var13[var16].unknown_2c_.y = 0;
                var13[var16].unknown_2c_.z = 0;
                var13[var16].unknown_38_ = 0;
                var13[var16].unknown_3c_ = 0;
                var13[var16].unknown_40_ = 0;
                var13[var16].unknown_44_.x = 0x1000;
                var13[var16].unknown_44_.y = 0x1000;
                var13[var16].unknown_44_.z = 0x1000;
                var13[var16].unknown_11_0_ = 0;
                var13[var16].unknown_11_1_ = 0;
                var13[var16].unknown_11_2_ = 1;
                var13[var16].unknown_11_3_ = 0;
                var13[var16].unknown_11_4_ = 0;
                var13[var16].unknown_11_5_ = 0;
                var13[var16].unknown_11_6_ = 0;
                var13[var16].unknown_11_7_ = 0;
                var13[var16].unknown_2c_ = var17->obj3D_.position_;
                var13[var16].unknown_44_ = var17->obj3D_.GetScale();
                func_02057fb4(var4, 5, &var13[var16]);
            }
        }
        self->state++;
    } else if (self->state == 3) {
        self->timer += delta;
        if (self->timer > 8) {
            SePlayer_LoadExtraArchiveB(&g_sePlayer, 0xb1, 0xb1);
            SePlayer_PlayExtra(&g_sePlayer, 0, 0);
            self->state++;
        }
    } else if (arg0->unknown_8_ == 4) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0x32) {
            for (int var18 = 0; var18 < 5; var18++) {
                if (arg0->unknown_d_ & (1 << var18)) {
                    GameObject* var19 = var0->GetGameObjectByIndex(var18 != 4 ? var18 : 0xce);
                    if (var19) {
                        var19->obj3D_.EnableFlag(1);
                    }
                }
            }
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 5) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0x6e) {
            SetBrightness(var2, -0x10, 0x1e);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 6) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0xaa && !IsBrightnessTransitionActive(var2)) {
            for (int var20 = 0; var20 < 5; var20++) {
                if (arg0->unknown_d_ & (1 << var20)) {
                    GameObject* var21 = var0->GetGameObjectByIndex(var20 != 4 ? var20 : 0xce);
                    if (var21) {
                        var21->obj3D_.DisableFlag(1);
                    }
                }
            }
            ClearFlags00(res, 0x10);
            CallListIfFlagsSet_02197528();
            self->done = 1;
            GameObject_EnableControl(leader);
            func_ov017_021ac2a8(self);
            SePlayer_UnloadExtraArchiveB(&g_sePlayer);
            if (func_0202c508(search)) {
                unsigned char* flags = (unsigned char*)Scenario_GetInstance();
                Scenario_SetFlag(flags, flags + 0x8c, 0x113d, 1);
            }
            if (CheckBitsInField0x63dc_02011b50(gs, 1) && self->active != 0) {
                TailList020469b4* tail;
                unsigned char* node = (unsigned char*)res->fieldTasks_[0x14];
                tail = (TailList020469b4*)res->fieldTaskQueue_;
                InitObjState_021b2174(node);
                SetNameChecked_021b2ba0((S021b2ba0*)node, &data_ov017_021d78f1);
                SetFields30And34_021b2bd0(node, (int)AllocateAndCopyBuf20_021689d8, OVERLAY_ID(4));
                SetBit4_021b2bf4((S021b2bf4*)node, 1);
                SetBit5_021b2c0c((S021b2c0c*)node, 1);
                SetBit3_021b2bdc((S021b2bdc*)node, 0);
                AppendNodeToTail(tail, (TailNode020469b4*)node);
            }
        }
    }
}
