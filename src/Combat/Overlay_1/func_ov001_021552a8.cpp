#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"
#include "std_library_functions.h"
#if defined(jpn)
#include "Filesystem/FileIO.h"
#endif

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_02043368_2;
struct Struct_02043368;
struct Struct_0208b8c4;
struct Struct_0203d028_6;
struct Struct_02020cb8_4;
struct Struct_02020aec;
struct Struct_0203d028;
struct Struct_020213fc;

struct Struct_ov001_021552a8_3 {
    char unknown_0_[0x3c];
    void* unknown_3c_;
    Struct_02043368_2* unknown_40_;
    char unknown_44_[8];
    unsigned short unknown_4c_;
    char unknown_4e_[2];
    unsigned char unknown_50_;
};

struct Struct_ov001_021552a8_4 {
    int unknown_0_;
    char unknown_4_[3];
    unsigned char unknown_7_;
    char unknown_8_[0x38];
    unsigned short unknown_40_;
    unsigned short unknown_42_;
    unsigned short unknown_44_;
    char unknown_46_[0x22];
};

struct Struct_ov001_021552a8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8];
    unsigned short unknown_a_;
    Struct_ov001_021552a8_4 unknown_c_;
    int unknown_74_;
#if !defined(jpn)
    int unknown_78_;
#endif
    SafeAllocator unknown_7c_;
    char unknown_90_[4];
    int unknown_94_;
    char unknown_98_[4];
    unsigned char unknown_9c_;
    char unknown_9d_[0x107 - 0x9d];
    unsigned char unknown_107_;
    char unknown_108_[8];
    int unknown_110_;
    char unknown_114_[0xc];
    void* unknown_120_;
    SafeAllocator unknown_124_;
    char unknown_138_[0x30];
    Struct_ov001_021552a8_3* unknown_168_;
    void* unknown_16c_;
    Struct_02043368_2* unknown_170_;
};

struct Struct_ov001_021552a8_2 {
    char unknown_0_[0x45b];
    unsigned char unknown_45b_[0x20];
};

char* GetFieldIfFlag4_020100f8(char* obj);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void func_ov017_021bb27c(void* obj);
extern "C" void func_0208b9a0(void* obj, unsigned char flag);
char* GetGlobalField0x1c020421a0(void);
void InitAllocatorsAndBuffers0208b8c4(Obj0208b8c4* obj, SafeAllocator* alloc);
void* GetGlobalPtr021075f4_0203cf4c(void);
void* EmptyStub0203d004(void* p);
void InitPool020401fc(Pool020401fc* pool, unsigned int count, SafeAllocator* alloc);
void Sprite_Init(Struct0205a198* p);
void ClearField0And40205a234(ClearTarget0205a234* p);
void SpriteContext_Init(char* p);
int Pac_CountFiles(ActiveEntry02046900* entry);
void* Pac_GetFile(Rec020467f0* rec, int index, void** out, int* out44);
extern "C" int SpriteContext_LoadFile(void* obj, void* data, int arg2, void* arg3);
extern "C" void func_ov001_0215a850(SafeAllocator* alloc);
extern "C" void func_ov001_0215a8dc(void);
extern "C" void func_ov001_021538d4(int arg0, void* arg1, SafeAllocator* arg2);
extern "C" void func_ov001_0215aa14(SafeAllocator* arg0);
extern "C" void func_ov001_0215aaa8(int arg0, int arg1);
extern "C" void func_ov001_0215acf8(int arg0, int arg1);
extern "C" void func_0207df50(Struct_0203d028* arg0);
extern "C" int func_ov001_02153948(unsigned short arg0);
extern "C" Struct_ov001_021552a8_2* func_0205ec34(void);
extern "C" void* func_02012fe4(void);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
extern "C" void* func_0202ae18(void);
extern "C" void* func_02010828(GameState* arg0);
extern "C" void* func_020d6c00(void);
extern "C" void func_02019568(void* arg0, int arg1);
extern "C" Object3D* func_ov017_021bdbc0(unsigned char* arg0);
extern "C" void func_020a27a0(void* arg0);
extern "C" void func_020a27b8(unsigned char* arg0);
extern "C" void func_020213fc(Struct_020213fc* arg0, int arg1);

extern AllocatorUnion data_02114e20;
extern char data_02109bf4;
#if defined(jpn)
extern const char data_ov001_021661d7[];
extern const char data_ov001_021661dc[];
#endif

static inline void inline_ov001_021552a8(Struct_ov001_021552a8_3* arg0, Struct_02043368_2* arg1, unsigned short arg2) {
    arg0->unknown_40_ = arg1;
    arg0->unknown_4c_ = arg2;
}

// USA: func_ov001_021552a8
extern "C" ARM int func_ov001_021552a8(Struct_ov001_021552a8* arg0) {
    char* var0;
    GameState* var1 = GameState::GetInstance();
    GameResources* var2 = GetGameResources();
    BackgroundLoader* var3 = BackgroundLoader::GetInstance();
    char* var4 = func_020100f8((char*)var1);
    GameObject* var5 = var1->GetUnknownGameObject();
    var0 = var2->unknown_2cc_;

    if (var3->GetTaskStatus(arg0->unknown_74_) == 0) {
        return arg0->unknown_a_;
    }
#if !defined(jpn)
    if (var3->GetTaskStatus(arg0->unknown_78_) == 0) {
        return arg0->unknown_a_;
    }
#endif
    if (arg0->unknown_c_.unknown_44_ & 0x200) {
        if (var3->GetTaskStatus(arg0->unknown_110_) == 0) {
            return arg0->unknown_a_;
        }
    }
#if defined(jpn)
    if (var3->GetDetailedTaskStatus(arg0->unknown_74_) != 2) {
#else
    if (var3->GetDetailedTaskStatus(arg0->unknown_74_) != 2 || var3->GetDetailedTaskStatus(arg0->unknown_78_) != 2) {
#endif
        SignedAllocatorHeader* var6 = arg0->unknown_7c_.GetSignedAllocator();
        arg0->unknown_7c_.Destroy();
        func_02012da4(&data_02114e20, var6);
        var3->RemoveTask(arg0->unknown_74_);
#if !defined(jpn)
        var3->RemoveTask(arg0->unknown_78_);
#endif
        var3->RemoveTask(arg0->unknown_110_);
        func_0209c2e0(&data_02109bf4, arg0->unknown_94_, 0);
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }

    void* var7;
#if !defined(jpn)
    void* var8;
#endif
    unsigned int var9;
#if !defined(jpn)
    unsigned int var10;
#endif
    var3->GetLoadedFileByID(arg0->unknown_74_, &var7, &var9);
#if !defined(jpn)
    var3->GetLoadedFileByID(arg0->unknown_78_, &var8, &var10);
#endif

    if (arg0->unknown_c_.unknown_44_ & 2) {
        arg0->unknown_120_ = arg0->unknown_7c_.Allocate(0xe4);
        func_0208b9a0(arg0->unknown_120_, 0);
        char* var11 = func_020421a0();
        arg0->unknown_124_.CreateTypeA(arg0->unknown_7c_.Allocate(0xa000), 0xa000);
        arg0->unknown_124_.Reset();
        func_0208b8c4((Struct_0208b8c4*)arg0->unknown_120_, &arg0->unknown_124_);
#if defined(jpn)
        *(void**)(var11 + 0x4c) = arg0->unknown_120_;
#else
        *(void**)(var11 + 0x8c) = arg0->unknown_120_;
#endif
    }
    if ((arg0->unknown_c_.unknown_44_ & 1) || (arg0->unknown_c_.unknown_44_ & 4)) {
        func_020401fc((Struct_0203d028_6*)func_0203d004(func_0203cf4c()), 0xc, &arg0->unknown_7c_);
    }
    if (self->params.flags & 0x200) {
        self->allocator.GetMaxPossibleAllocation();
        self->entries = (Struct0205a198*)self->allocator.Allocate(0x230);
        self->list = (List021552a8*)self->allocator.Allocate(0x54);
        self->slots = self->allocator.Allocate(8);
        for (int i = 0; i < 0xe; i++) {
            Sprite_Init((Struct0205a198*)((char*)self->entries + i * 0x28));
        }
        ClearField0And40205a234((ClearTarget0205a234*)self->slots);
        SpriteContext_Init((char*)self->list);
        self->list->active = 0;
        SetListEntries(self->list, self->entries, 0xe);
        self->list->slots = self->slots;

        void* out;
        void* dataC;
        unsigned int lengthC;
        int size;
        loader->GetLoadedFileByID(self->taskC, &dataC, &lengthC);
        int count = Pac_CountFiles((ActiveEntry02046900*)dataC);
        for (int j = 0; j < count; j++) {
            void* rec = Pac_GetFile((Rec020467f0*)dataC, j, &out, &size);
            SpriteContext_LoadFile(self->list, rec, size, &self->allocator);
        }
        var3->RemoveTask(arg0->unknown_110_);
        arg0->unknown_110_ = -1;
    }

#if defined(jpn)
    const void* var8;
    unsigned int var10;
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661d7, &var8, &var10, 1) == 0) {
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }
    func_ov001_0215a850(&arg0->unknown_7c_);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var8, 0, &arg0->unknown_7c_);
#else
    func_ov001_0215a850(&arg0->unknown_7c_);
    func_ov001_0215a8dc();
    func_ov001_021538d4((int)var7, 0, &arg0->unknown_7c_);
#endif
    func_ov001_0215aa14(&arg0->unknown_7c_);
    if (arg0->unknown_c_.unknown_44_ & 4) {
        func_ov001_0215aaa8(1, (int)&var2->allocator_array_38[7]);
    }
#if defined(jpn)
    if (FindFilesInNarcBySubstring(var7, data_ov001_021661dc, &var8, &var10, 1) != 0)
#endif
    func_ov001_0215acf8((int)var8, var10);
    GameObject* var20 = var1->GetPartyMemberByIndex(0);
    if (var20 != NULL && (**(unsigned int**)((char*)var20 + 0x130) & 1)) {
        arg0->unknown_107_ = 1;
    }
    var3->RemoveTask(arg0->unknown_74_);
#if !defined(jpn)
    var3->RemoveTask(arg0->unknown_78_);
#endif
    func_0207df50((Struct_0203d028*)(var0 + 0xbd0));

    if (func_ov001_02153948(arg0->unknown_c_.unknown_40_) == 0) {
        SignedAllocatorHeader* var21 = arg0->unknown_124_.GetSignedAllocator();
        if (var21 != NULL) {
            arg0->unknown_124_.Destroy();
            arg0->unknown_7c_.Free(var21);
        }
        SignedAllocatorHeader* var22 = arg0->unknown_7c_.GetSignedAllocator();
        arg0->unknown_7c_.Destroy();
        func_02012da4(&data_02114e20, var22);
        func_ov017_021bb27c(arg0);
        arg0->unknown_1_ = 1;
        return arg0->unknown_a_;
    }

    int var23;
    int var24;
    Struct_02013454* var25;
    Struct_ov001_021552a8_2* var26 = func_0205ec34();
    var25 = func_020196fc((Zone3D*)func_02012fe4(), 0);
    var24 = var25->unknown_4_.unknown_10_;
    if (var25 != NULL) {
        memset(var26->unknown_45b_, 0, sizeof(var26->unknown_45b_));
        for (var23 = 0; var23 < var24; var23++) {
            Struct_02016874_2* var27 = &var25->unknown_44_[var23];
            if (var27 != NULL && !(var27->unknown_2_ & 4)) {
                func_0206df6c(var26, var26->unknown_45b_, (unsigned char)var23, 1);
            }
        }
    }

    unsigned char var28 = arg0->unknown_9c_;
    Struct_ov001_021552a8_4 var29 = arg0->unknown_c_;
    GameState* var30 = GameState::GetInstance();
    GameResources* var31 = GetGameResources();
    void* var32 = (Zone3D*)func_02012fe4();
    func_0202ae18();
    func_02010828(var30);
    func_020d6c00();
    if (!(var29.unknown_44_ & 0x400)) {
        func_02019568(var32, var28);
    }
    *((char*)func_0205ec34() + 0x490) = -1;
    if (var29.unknown_7_ != 0) {
        Object3D* var33 = func_ov017_021bdbc0((unsigned char*)var31);
        if (var33 != NULL) {
            var33->MakeHidden();
        }
    }

    func_020a27a0(var4);
    func_020a27b8((unsigned char*)var4);
    *(short*)((char*)var5 + 0xb2) = 0;
    func_020213fc((Struct_020213fc*)var2->unknown_ptr_36d0, 0);
    return 3;
}
