#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

struct BattleState;
struct PartyState;
struct Obj02049f50;

struct Foo0207df50 {
    unsigned int a[10];
    unsigned int b[10];
    unsigned int c;
    unsigned int d;
    unsigned int p1[2];
    unsigned int p2[2];
};

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct BattleWork {
    char pad0[0x30];
    SafeAllocator alloc;
    char pad44[0x258];
    BattleState* battle;
    PartyState* party;
    char pad2a4[0x34bc];
    char list[0x1d72];
    unsigned short uiFlags;
    char pad54d4[0x223d];
    unsigned char fadeActive;
    signed char phase;
    char pad7713[0x1];
    short objId;
    short objIds[4];
    short objId771e;
    short objId7720;
    short objId7722;
    short objId7724;
    short objId7726;
    char pad7728[0x21];
    unsigned char reinitFlag;
    char pad774a[0x2];
    SafeAllocator cmdAlloc;
    Foo0207df50 stateB;
};

struct EffectKinds {
    unsigned char kinds[3];
};

struct Rodata021de6a0 {
    char pad0[0xa];
    EffectKinds effectKinds;
    char padd[0xb];
};

void CopyInternalFields0207df50(Foo0207df50* p);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
void SetForwardAndStore0205eb54(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
void ForwardField0xc0_0205eb80(void* obj);
void InitStruct02078484(InitStruct02078484Struct* req);
int FindNodeAndProcess02057fb4(void* list, int id, void* req);
void SetField41AndScaleSub02049f50(Obj02049f50* obj, int val, int count);
void ResetTwoFields021637c8(void* obj);
void UpdateFlag8AndBit4_021636ac(void* objRaw);
void ClearFlagIfParityMismatch02163710_02163710(void* obj, int flag);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char* work);

extern "C" {
void* func_02057924();
int func_02057e6c(void* list, int kind, SafeAllocator* alloc, void* data, unsigned int size, Foo0207df50* state);
void func_02057f00(void* obj, int index);
int func_ov000_021759f4(void* list);
void func_ov000_02175808(void* list);
void func_ov000_021626a0(BattleWork* self, int a, int b);
void func_ov000_02163894(BattleWork* self);
void func_ov000_02163928(BattleWork* self);
void func_ov026_021dc440(SafeAllocator* allocator, BattleWork* self, BattleState* battle, PartyState* party, const char* animName);
int func_ov026_021dc040(SafeAllocator* allocator, BattleWork* self, BattleState* battle, PartyState* party);
}

extern const char data_ov026_021dee0c[];
extern const char data_ov026_021dee23[];
extern const char data_ov026_021dee3a[];
extern const char data_ov026_021dedec[];
extern const Rodata021de6a0 data_ov026_021de6a0;
extern char g_sePlayer[];

// USA: func_ov026_021db5a4
extern "C" ARM void func_ov026_021db5a4(BattleWork* self) {
    GameResources* res = GetGameResources();

    if (self->phase == 0) {
        if (func_ov000_021759f4(self->list)) {
            self->cmdAlloc.Reset();
            CopyInternalFields0207df50(&self->stateB);
            self->objId = self->objId771e = self->objId7720 = -1;
            SetBrightness(res, -0x10, 0xf);
            self->objId = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee0c, &self->cmdAlloc);
            self->objId771e = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee23, &self->cmdAlloc);
            self->objId7720 = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee3a, &self->cmdAlloc);
            self->phase = 1;
            self->reinitFlag = 1;
        }
    } else if (self->phase == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->objId771e) && loader->GetTaskStatus(self->objId7720) &&
            loader->GetTaskStatus(self->objId) && !IsBrightnessTransitionActive(res)) {
            short* idp;
            unsigned char* kp;
            int i;
            short ids[3] = {self->objId, self->objId771e, self->objId7720};
            EffectKinds kinds = data_ov026_021de6a0.effectKinds;
            kp = kinds.kinds;
            idp = ids;
            for (i = 0; i < 3; i++) {
                void* data;
                unsigned int size;
                loader->GetLoadedFileByID(*idp, &data, &size);
                func_02057e6c(func_02057924(), *kp, &self->cmdAlloc, data, size, &self->stateB);
                loader->RemoveTask(*idp);
                kp++;
                idp++;
            }
            self->objId = self->objId771e = self->objId7720 = -1;
            func_ov000_021626a0(self, 0x26, 1);
            func_ov000_021626a0(self, 0x27, 0);
            RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)self);
            self->phase = 2;
        }
    } else if (self->phase == 2) {
        InitStruct02078484Struct req;
        SetForwardAndStore0205eb54(g_sePlayer, 0x1b3, 0x1b3);
        DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 1, 0);
        self->fadeActive = 1;
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 0);
        SetFlags04((GameResources*)res, 0x100000);
        InitStruct02078484(&req);
        req.b0 = 1;
        req.f10 = 1;
        req.scale.x = 0x800;
        req.scale.y = 0x800;
        req.scale.z = 0x800;
        req.offset.x = 0;
        req.offset.z = 0;
        req.offset.y = -0xa000;
        self->objId7722 = FindNodeAndProcess02057fb4(func_02057924(), 0x1d, &req);
        self->objId7724 = FindNodeAndProcess02057fb4(func_02057924(), 0x1e, &req);
        self->objId7726 = 0;
        SetMainBrightness(res, 0, 0xf);
        self->phase = 3;
    } else if (self->phase == 3) {
        int done = 0;
        GameObject* obj = GameState::GetInstance()->GetGameObjectByIndex(self->objId7722);
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
            self->objId7726 = 0;
            SetMainBrightness(res, -0x10, 0xf);
            self->phase = 4;
        }
    } else if (self->phase == 4) {
        if (!IsBrightnessTransitionActive(res)) {
            SetMainBrightness(res, -0x10, 0);
            func_02057f00(func_02057924(), 0x1d);
            func_02057f00(func_02057924(), 0x1e);
            self->objId7722 = self->objId7724 = -1;
            func_ov000_021626a0(self, 0x26, 1);
            ClearFlags04((GameResources*)res, 0x100000);
            self->phase = 5;
        }
    } else if (self->phase == 5) {
        InitStruct02078484Struct req;
        ForwardField0xc0_0205eb80(g_sePlayer);
        self->fadeActive = 0;
        SetMainBrightness(res, -0x10, 0);
        GameState* gs = GameState::GetInstance();
        InitStruct02078484(&req);
        for (int i = 0; i < 4; i++) {
            GameObject* c = gs->GetCombatantByIndex(i);
            if (c != NULL) {
                SetField41AndScaleSub02049f50((Obj02049f50*)c, 0x1f, 0);
            }
            req.objectId = i;
            req.f10 = 0;
            self->objIds[i] = FindNodeAndProcess02057fb4(func_02057924(), 0x12, &req);
        }
        func_ov000_02175808(self->list);
        self->uiFlags |= 0x200;
        ResetTwoFields021637c8(self);
        func_ov026_021dc440(&self->cmdAlloc, self, self->battle, self->party, data_ov026_021dedec);
        func_ov000_02163894(self);
        UpdateFlag8AndBit4_021636ac(self);
        self->phase = 6;
        SetForwardAndStore0205eb54(g_sePlayer, 0x1b3, 0x1b3);
        DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 2, 0);
        self->fadeActive = 1;
    } else if (self->phase == 6) {
        func_ov000_02163928(self);
        if (func_ov026_021dc040(&self->alloc, self, self->battle, self->party)) {
            ClearFlagIfParityMismatch02163710_02163710(self, 0);
            self->phase = -1;
        }
    } else if (self->phase == -1) {
        func_ov000_02163928(self);
    }
}
