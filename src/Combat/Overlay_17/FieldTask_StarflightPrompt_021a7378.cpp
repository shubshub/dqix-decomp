#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
enum { IntroResourceSize = 0x1000 };
#else
enum { IntroResourceSize = 0x1400 };
#endif
#include "Resource/FontBankLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/Graphics.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "Resource/GameResources.h"

struct MessageWindow {
#if defined(jpn)
    char pad0[0x868];
#else
    char pad0[0x998];
#endif
    int active;
    char unknown_99c_[0x9a0 - 0x99c];
    int busy;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    unsigned char unknown_19ae_;
    char unknown_19af_[0x19b2 - 0x19af];
    unsigned char unknown_19b2_;
};

struct FieldGlobals {
#if defined(jpn)
    char pad0[0x27f8];
#else
    char pad0[0x27b8];
#endif
    Vector3i unknown_27b8_;
    char unknown_27c4_[0x27d0 - 0x27c4];
    unsigned char unknown_27d0_;
};

struct CameraState {
    char pad0[0x44];
    Vector3i position;
    char unknown_50_[0x13c - 0x50];
    int mode;
};

struct CameraParams {
    unsigned short angle;
    unsigned char flag2;
    unsigned char pad3[2];
    unsigned char flag5;
    unsigned char pad6;
    unsigned char flag7;
    unsigned char pad8[0x10 - 0x8];
    int distance;
    int height;
    int offset;
    unsigned short unknown_1c_;
    unsigned char pad1e[0x61 - 0x1e];
    unsigned char unknown_61_;
};

struct TailList020469b4;
struct TailNode020469b4;

struct Struct_ov017_021a7378_2 {
    char pad0[4];
    unsigned short count;
};

struct Container020e0310;
struct PointerField330_ffd0;
struct Obj020d7aa0;
struct Struct_0204bef4;
struct Struct_0205faf4_7;

struct BattleIntro {
    unsigned char field0;
    unsigned char done;
    char pad2[0x8 - 0x2];
    int state;
    int mode;
    int counter;
    int unknown_14_;
    int kind;
    unsigned int unknown_1c_;
    int taskId;
#if defined(jpn)
    unsigned char controls[0x1ec - 0x24];
#else
    unsigned char controls[0x25c - 0x24];
#endif
    SafeAllocator allocator;
    char container[0x10];
};

extern "C" unsigned char* GameState_GetFollowCamera(char* obj);
extern "C" MessageWindow* MessageSystem_GetInstance();
extern "C" FieldGlobals* Zone3D_GetInstance(void);
extern "C" CameraState* GameState_GetStarflight(PointerField330_ffd0* obj);
extern "C" void func_0205c904(unsigned char* obj, int value);
extern "C" void* TextQueue_GetInstance(void);
extern "C" void TextQueue_Reset(Obj020d7aa0* obj);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020ae38c(unsigned char* obj);
extern "C" void func_020ae380(unsigned char* obj);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void KeyTable_Load(void* dest, SafeAllocator* allocator, void* fileData, unsigned int size);
extern "C" int KeyTable_Get(Container020e0310* c, int key);
extern "C" void func_020a28a0(unsigned char* obj, unsigned char mask);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" int func_020457e0(MessageWindow* window);
extern "C" CameraParams* GameState_GetZoneTransition(GameState* gs);
extern "C" void func_02070378(char* obj);
extern "C" void* GameObject_GetFloorAttribute(void* obj);
extern "C" int func_0204bedc(unsigned short* obj);
extern "C" int func_0204bef4(Struct_0204bef4* obj);
extern "C" void FieldTask_InitEnterZone(unsigned char* obj, int flag);
extern "C" void func_020469b4(TailList020469b4* list, TailNode020469b4* node);
extern "C" void func_ov017_021a65c4(void* scene, unsigned char kind, int arg);
extern "C" void func_ov017_021baedc(TailNode020469b4* node, int flag);
extern "C" void func_ov017_021d1c2c(unsigned char a, unsigned short b);
extern "C" void func_ov017_021d1dc0(unsigned short, int, int*, int, int);
extern "C" void* func_02094d6c(void);
extern "C" Struct_ov017_021a7378_2* func_02096134(Struct_0205faf4_7* table, int id);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void func_0205ce50(unsigned char* obj);
extern "C" void func_ov017_021a79f0(BattleIntro* self);

extern AllocatorUnion g_mainAllocator;
#if defined(jpn)
extern const char data_ov017_021d7bd4[];
#else
extern const char data_ov017_021d7798[];
extern const char data_ov017_021d77b2[];
#endif

// USA: FieldTask_StarflightPrompt
// JPN: func_ov017_021a7d20
// Overlay 17, originally func_ov017_021a7378 (USA/EUR 0x021a7378, JPN 0x021a7d20)
extern "C" ARM void FieldTask_StarflightPrompt(BattleIntro* self, int arg) {
    GameState* gs = GameState::GetInstance();
    unsigned char* flags = GameState_GetFollowCamera((char*)gs);
    MessageWindow* window = MessageSystem_GetInstance();
    FieldGlobals* globals = Zone3D_GetInstance();
    CameraState* camera = GameState_GetStarflight((PointerField330_ffd0*)gs);
    func_0205c904(self->controls, gs->GetTickCount());

    if (self->state == 0) {
        TextQueue_Reset((Obj020d7aa0*)TextQueue_GetInstance());
        self->unknown_1c_ = (DISPCNT & 0x1f00) >> 8;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1100;
        func_020a0cc4(IntroResourceSize);
        func_020ae38c((unsigned char*)GameState_GetStarflight((PointerField330_ffd0*)gs));
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b30(g, 0x205, 0);
        if (func_02094b4c(g)) {
#if defined(jpn)
            self->taskId = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d7bd4, NULL);
#else
            self->taskId = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d7798, data_ov017_021d77b2, NULL);
#endif
            self->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, IntroResourceSize), IntroResourceSize);
            self->state = 1;
        }
    } else if (self->state == 1) {
        BackgroundLoader* var6 = BackgroundLoader::GetInstance();
        if (var6->GetTaskStatus(self->taskId)) {
            void* fileData;
            unsigned int size;
            var6->GetLoadedFileByID(self->taskId, &fileData, &size);
            self->allocator.Reset();
            KeyTable_Load(self->container, &self->allocator, fileData, size);
            var6->RemoveTask(self->taskId);
            self->taskId = -1;
            if (self->mode == 0) {
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x23), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x23), 0, 0xe3);
#endif
                self->state = 0xc8;
            } else {
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x24), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x24), 0, 0xe3);
#endif
                self->state = 0x12c;
            }
            window->unknown_19b2_ = 0;
            window->active = 1;
            func_020a28a0(flags, 2);
        }
    } else if (self->state == 0xc8) {
        if (window->busy == 0) {
            func_020a28b0(flags, 2);
            if (func_020457e0(window) == 0) {
                CameraParams* params = GameState_GetZoneTransition(gs);
                func_02070378((char*)params);
                params->flag2 = 1;
                params->flag7 = 1;
                params->flag5 = 1;
                params->angle = 0x1901;
                params->unknown_1c_ = 0x25c2;
                params->distance = 0x3800;
                params->height = 0x999;
                params->offset = -0x3800;
                self->state = 0x64;
                FieldTask_StarflightPrompt(self, arg);
            } else {
                self->state = 0x64;
                FieldTask_StarflightPrompt(self, arg);
            }
        }
    } else if (self->state == 0x12c) {
        if (window->busy == 0) {
            func_020a28b0(flags, 2);
            if (func_020457e0(window) == 0) {
                void* color = GameObject_GetFloorAttribute(camera);
                if (color != NULL && func_0204bedc((unsigned short*)color)) {
                    self->kind = 0;
                    self->state = 0x62;
                    camera->mode = 1;
                    FieldTask_StarflightPrompt(self, arg);
                } else {
                    window->active = 1;
#if defined(jpn)
                    func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x26), 0);
#else
                    func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x26), 0, 0xe3);
#endif
                    self->state = 0x12d;
                    func_020a28a0(flags, 2);
                }
            } else {
                window->active = 1;
#if defined(jpn)
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x25), 0);
#else
                func_0204500c((MessageSystem*)window, (const char*)KeyTable_Get((Container020e0310*)self->container, 0x25), 0, 0xe3);
#endif
                self->state = 0x12d;
                func_020a28a0(flags, 2);
            }
        }
    } else if (self->state == 0x12d) {
        if (window->busy == 0) {
            func_020a28b0(flags, 2);
            if (func_020457e0(window) == 0) {
                self->kind = 3;
                camera->mode = 2;
                self->state = 0x63;
            } else {
                self->state = 0x64;
                FieldTask_StarflightPrompt(self, arg);
            }
        }
    } else if (self->state == 0x62) {
        if (++self->counter > 0xf) {
            self->state = 0x63;
        }
    } else if (self->state == 0x63) {
        GameResources* res = GetGameResources();
        CameraParams* params;
        TailList020469b4* list = (TailList020469b4*)res->fieldTaskQueue_;
        TailNode020469b4* var14 = (TailNode020469b4*)res->unknown_ptr_array_371c[6];
        params = GameState_GetZoneTransition(gs);
        func_02070378((char*)params);
        params->flag7 = 1;
        void* color = GameObject_GetFloorAttribute(camera);
        switch (self->kind) {
        case 0: {
            params->unknown_61_ = 1;
            params->angle = func_0204bef4((Struct_0204bef4*)color);
            params->unknown_1c_ = 0;
            params->distance = 0x100000;
            params->height = 0;
            params->offset = 0x100000;
            globals->unknown_27b8_ = camera->position;
            GameState_SetZoneTransition(gs, params);
            TailNode020469b4* node = (TailNode020469b4*)res->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone((unsigned char*)node, 0);
            func_020469b4(list, node);
            func_ov017_021a65c4(res, 1, 0);
            break;
        }
        case 3:
            camera->mode = 2;
            func_ov017_021baedc(var14, 1);
            *(unsigned short*)((char*)var14 + 8) = 0x7346;
            func_020469b4(list, var14);
            break;
        }
        Vector3i pos;
        if (self->kind == 3) {
            func_ov017_021d1c2c(3, 0);
            func_ov017_021d1dc0(3, 0, (int*)&pos, 0x7346, 0);
        } else {
            pos = camera->position;
            func_ov017_021d1c2c(0, 0);
            func_ov017_021d1dc0(0, params->angle, (int*)&pos, 0, 0);
        }
        if (globals->unknown_27d0_ < 0xff) {
            globals->unknown_27d0_++;
        }
        Struct_ov017_021a7378_2* entry = func_02096134((Struct_0205faf4_7*)func_02094d6c(), 0xbc);
        if (entry != NULL && entry->count < 10) {
            entry->count++;
        }
        self->state = 0x64;
        MessageSystem_Reset((char*)window);
    } else if (self->state == 0x64) {
        window->unknown_19ae_ = 0;
        if (window->busy == 0) {
            MessageSystem_Reset((char*)window);
            func_0205ce50(self->controls);
            func_020ae380((unsigned char*)GameState_GetStarflight((PointerField330_ffd0*)gs));
            func_ov017_021a79f0(self);
            self->done = 1;
        }
    }
}
