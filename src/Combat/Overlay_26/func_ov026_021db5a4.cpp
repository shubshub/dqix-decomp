#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

struct Struct_ov000_02161e30;
struct PartyState;
struct Struct_02049f50;

struct Foo0207df50 {
    unsigned int a[10];
    unsigned int b[10];
    unsigned int c;
    unsigned int d;
    unsigned int p1[2];
    unsigned int p2[2];
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short f12;
    short objectId;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Struct_ov000_02160da0 {
    char pad0[0x30];
    SafeAllocator alloc;
    char unknown_44_[0x258];
    Struct_ov000_02161e30* battle;
    PartyState* party;
    char unknown_2a4_[0x34bc];
    char list[0x1d72];
    unsigned short unknown_54d2_;
    char unknown_54d4_[0x223d];
    unsigned char unknown_7711_;
    signed char phase;
    char unknown_7713_[0x1];
    short unknown_7714_;
    short unknown_7716_[4];
    short unknown_771e_;
    short unknown_7720_;
    short unknown_7722_;
    short unknown_7724_;
    short unknown_7726_;
    char unknown_7728_[0x21];
    unsigned char unknown_7749_;
    char unknown_774a_[0x2];
    SafeAllocator unknown_774c_;
    Foo0207df50 stateB;
};

struct Struct_ov026_021db5a4 {
    unsigned char kinds[3];
};

struct Struct_ov026_021de6a0 {
    char pad0[0xa];
    Struct_ov026_021db5a4 unknown_a_;
    char unknown_d_[0xb];
};

extern "C" void VramState_Rewind(Foo0207df50* p);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
extern "C" void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2);
extern "C" void func_0205eb90(void* obj, int a, int b);
extern "C" void SePlayer_UnloadExtraArchiveA(void* obj);
extern "C" void func_02078484(Struct_02078398_2* req);
extern "C" int func_02057fb4(void* list, int id, void* req);
extern "C" void func_02049f50(Struct_02049f50* obj, int val, int count);
extern "C" void func_ov000_021637c8(void* obj);
extern "C" void func_ov000_021636ac(void* objRaw);
extern "C" void func_ov000_02163710(void* obj, int flag);
extern "C" void func_ov000_02167e6c(unsigned char* work);

extern "C" {
void* func_02057924();
int func_02057e6c(void* list, int kind, SafeAllocator* alloc, void* data, unsigned int size, Foo0207df50* state);
void func_02057f00(void* obj, int index);
int func_ov000_021759f4(void* list);
void func_ov000_02175808(void* list);
void func_ov000_021626a0(Struct_ov000_02160da0* self, int a, int b);
void func_ov000_02163894(Struct_ov000_02160da0* self);
void func_ov000_02163928(Struct_ov000_02160da0* self);
void func_ov026_021dc440(SafeAllocator* allocator, Struct_ov000_02160da0* self, Struct_ov000_02161e30* battle, PartyState* party, const char* animName);
int func_ov026_021dc040(SafeAllocator* allocator, Struct_ov000_02160da0* self, Struct_ov000_02161e30* battle, PartyState* party);
}

extern const char data_ov026_021dee0c[];
extern const char data_ov026_021dee23[];
extern const char data_ov026_021dee3a[];
extern const char data_ov026_021dedec[];
extern const Struct_ov026_021de6a0 data_ov026_021de6a0;
extern char g_sePlayer[];

// USA: func_ov026_021db5a4
extern "C" ARM void func_ov026_021db5a4(Struct_ov000_02160da0* self) {
    GameResources* res = GetGameResources();

    if (self->phase == 0) {
        if (func_ov000_021759f4(self->list)) {
            self->unknown_774c_.Reset();
            VramState_Rewind(&self->stateB);
            self->unknown_7714_ = self->unknown_771e_ = self->unknown_7720_ = -1;
            SetBrightness(res, -0x10, 0xf);
            self->unknown_7714_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee0c, &self->unknown_774c_);
            self->unknown_771e_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee23, &self->unknown_774c_);
            self->unknown_7720_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee3a, &self->unknown_774c_);
            self->phase = 1;
            self->unknown_7749_ = 1;
        }
    } else if (self->phase == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->unknown_771e_) && loader->GetTaskStatus(self->unknown_7720_) &&
            loader->GetTaskStatus(self->unknown_7714_) && !IsBrightnessTransitionActive(res)) {
            short* var2;
            unsigned char* var3;
            int i;
            short ids[3] = {self->unknown_7714_, self->unknown_771e_, self->unknown_7720_};
            Struct_ov026_021db5a4 kinds = data_ov026_021de6a0.unknown_a_;
            var3 = kinds.kinds;
            var2 = ids;
            for (i = 0; i < 3; i++) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(*var2, &data, &size);
                func_02057e6c(func_02057924(), *var3, &self->unknown_774c_, data, size, &self->stateB);
                loader->RemoveTask(*var2);
                var3++;
                var2++;
            }
            self->unknown_7714_ = self->unknown_771e_ = self->unknown_7720_ = -1;
            func_ov000_021626a0(self, 0x26, 1);
            func_ov000_021626a0(self, 0x27, 0);
            func_ov000_02167e6c((unsigned char*)self);
            self->phase = 2;
        }
    } else if (self->phase == 2) {
        Struct_02078398_2 req;
        SePlayer_LoadExtraArchiveA(g_sePlayer, 0x1b3, 0x1b3);
        func_0205eb90(g_sePlayer, 1, 0);
        self->unknown_7711_ = 1;
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 0);
        SetFlags04((GameResources*)res, 0x100000);
        func_02078484(&req);
        req.b0 = 1;
        req.f10 = 1;
        req.scale.x = 0x800;
        req.scale.y = 0x800;
        req.scale.z = 0x800;
        req.offset.x = 0;
        req.offset.z = 0;
        req.offset.y = -0xa000;
        self->unknown_7722_ = func_02057fb4(func_02057924(), 0x1d, &req);
        self->unknown_7724_ = func_02057fb4(func_02057924(), 0x1e, &req);
        self->unknown_7726_ = 0;
        SetMainBrightness(res, 0, 0xf);
        self->phase = 3;
    } else if (self->phase == 3) {
        int done = 0;
        GameObject* obj = GameState::GetInstance()->GetGameObjectByIndex(self->unknown_7722_);
        if (obj != NULL) {
            int span = obj->obj3D_.normalizedAnimationTime_ - obj->obj3D_.prevFrameNormalizedAnimationTime_;
            if (span > 0) {
                int rate = fix32_Divide(obj->obj3D_.animationTime_ - obj->obj3D_.prevFrameAnimationTime_, span);
                int left = (int)(((long long)rate * (0x1000 - obj->obj3D_.normalizedAnimationTime_) + 0x800) >> 12);
                if (left <= 0x1e000) {
                    done = 1;
                }
            }
        }
        if (obj == NULL || done) {
            self->unknown_7726_ = 0;
            SetMainBrightness(res, -0x10, 0xf);
            self->phase = 4;
        }
    } else if (self->phase == 4) {
        if (!IsBrightnessTransitionActive(res)) {
            SetMainBrightness(res, -0x10, 0);
            func_02057f00(func_02057924(), 0x1d);
            func_02057f00(func_02057924(), 0x1e);
            self->unknown_7722_ = self->unknown_7724_ = -1;
            func_ov000_021626a0(self, 0x26, 1);
            ClearFlags04((GameResources*)res, 0x100000);
            self->phase = 5;
        }
    } else if (self->phase == 5) {
        Struct_02078398_2 req;
        SePlayer_UnloadExtraArchiveA(g_sePlayer);
        self->unknown_7711_ = 0;
        SetMainBrightness(res, -0x10, 0);
        GameState* gs = GameState::GetInstance();
        func_02078484(&req);
        for (int i = 0; i < 4; i++) {
            GameObject* c = gs->GetCombatantByIndex(i);
            if (c != NULL) {
                func_02049f50((Struct_02049f50*)c, 0x1f, 0);
            }
            req.objectId = i;
            req.f10 = 0;
            self->unknown_7716_[i] = func_02057fb4(func_02057924(), 0x12, &req);
        }
        func_ov000_02175808(self->list);
        self->unknown_54d2_ |= 0x200;
        func_ov000_021637c8(self);
        func_ov026_021dc440(&self->unknown_774c_, self, self->battle, self->party, data_ov026_021dedec);
        func_ov000_02163894(self);
        func_ov000_021636ac(self);
        self->phase = 6;
        SePlayer_LoadExtraArchiveA(g_sePlayer, 0x1b3, 0x1b3);
        func_0205eb90(g_sePlayer, 2, 0);
        self->unknown_7711_ = 1;
    } else if (self->phase == 6) {
        func_ov000_02163928(self);
        if (func_ov026_021dc040(&self->alloc, self, self->battle, self->party)) {
            func_ov000_02163710(self, 0);
            self->phase = -1;
        }
    } else if (self->phase == -1) {
        func_ov000_02163928(self);
    }
}
