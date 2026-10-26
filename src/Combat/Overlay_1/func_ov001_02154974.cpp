#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_ov001_02154974 {
    unsigned char kind : 4;
    unsigned char index;
    short slot;
    char pad4[4];
    int key;
    char unknown_c_[0x11 - 0xc];
    char name[0x34 - 0x11];
    struct Struct_ov001_02154974* next;
};

struct Struct_ov001_02154974_2 {
    unsigned char type;
    char pad1[0x28 - 1];
    struct Struct_ov001_02154974_2* next;
};

struct Struct_ov001_02154974_3 {
#if defined(jpn)
    char pad0[0xcc];
#else
    char pad0[0xd0];
#endif
    struct Struct_ov001_02154974* nodes;
    struct Struct_ov001_02154974_2* others;
    char unknown_d8_[0xf8 - 0xd8];
    unsigned int mode : 27;
};

struct Struct_ov001_02154974_4 {
    char pad0[0x98];
    unsigned int flags;
};

struct Struct_ov001_02154974_5 {
    unsigned int flags;
    char pad4[0x18 - 4];
    GameObject* object;
};

struct Struct_ov001_02154974_6 {
    char pad0[0xd4];
    unsigned char active : 1;
};

extern "C" {
extern "C" struct Struct_ov001_02154974_4* func_0203cf4c(void);
extern "C" void func_0200fd48(GameState* gs, int id);
extern "C" struct Struct_ov001_02154974_5* func_0203df78(void* list, int key);
extern "C" int* func_0203dce4(void* list, int id);
extern "C" int func_02040404(void* container, const char* name);
extern "C" void func_0204039c(void* container, int index);
extern "C" void func_02040504(int* entry);
extern "C" void func_0203dd10(void* list, int index, int arg);
extern "C" void func_ov001_0215acd4(int index);
}

extern "C" void* func_0203d004(void* list);

#if defined(jpn)
#define data_ov001_02164bd1 data_ov001_02166171
#endif
extern char data_ov001_02164bd1[];

// USA: func_ov001_02154974
extern "C" ARM void func_ov001_02154974(struct Struct_ov001_02154974_3* self) {
    GameState* gs = GameState::GetInstance();
    struct Struct_ov001_02154974_4* global = func_0203cf4c();
    GameResources* base = GetGameResources();
    struct Struct_ov001_02154974_2* other;
    struct Struct_ov001_02154974* node;
    struct Struct_ov001_02154974* var5;
    int i;

    for (other = self->others; other != 0; other = other->next) {
        for (var5 = self->nodes; var5 != 0; var5 = var5->next) {
            if (var5->index != other->type) {
                continue;
            }
            if (var5->kind == 0 || var5->kind == 1 || var5->kind == 9 || var5->kind == 0xb || var5->kind == 0xc ||
                var5->kind == 0xd || var5->kind == 0xa || var5->kind == 4) {
                GameObject* obj = gs->GetGameObjectByIndex(var5->slot);
                if (obj != 0) {
                    Object3D* o = &obj->obj3D_;
                    unsigned char animFlags = o->animationFlags_;
                    const char* animName = (const char*)o->activeAnimationRecord_;
                    o->RemoveAnimationPackageByID(3);
                    if (o->SetAnimationByName(animName, animFlags) == false) {
                        o->SetAnimationByName(data_ov001_02164bd1, 0);
                    }
                }
            }
            break;
        }
    }

    i = 0;
    for (node = self->nodes; node != 0; node = node->next) {
        switch (node->kind) {
        case 5: {
            struct Struct_ov001_02154974_5* var11 = func_0203df78(global, node->key);
            if (var11 != 0) {
                var11->flags &= ~0x10000;
            }
            break;
        }
        case 4: {
            func_0200fd48(gs, node->slot);
            struct Struct_ov001_02154974_5* var12 = func_0203df78(global, node->key);
            if (var12 != 0 && var12->object != 0) {
                ((struct Struct_ov001_02154974_6*)var12->object)->active = 0;
                var12->flags &= ~0x10000;
            }
            break;
        }
        case 2:
        case 6:
        case 7:
        case 8:
            if (gs->GetGameObjectByIndex(node->slot) != 0) {
                func_0200fd48(gs, node->slot);
            }
            break;
        case 3: {
            int* entry = func_0203dce4(global, node->slot);
            if (entry != 0) {
                void* container = func_0203d004(global);
                func_0204039c(
                    container, func_02040404(container, node->name));
                func_02040504(entry);
                func_0203dd10(global, node->slot, i);
            }
            break;
        }
        case 13:
        case 12:
        case 11:
        case 10:
            break;
        }
        func_ov001_0215acd4(node->index);
    }

    if (self->mode == 0) {
        return;
    }
    if (self->mode & 1) {
        ClearFlags04(base, 8);
    }
    if (self->mode & 2) {
        ClearFlags04(base, 0x10);
    }
    if (self->mode & 4) {
        int j;
        for (j = 0; j < 4; j++) {
            GameObject* obj = gs->GetGameObjectByIndex(j);
            if (obj != 0) {
                obj->obj3D_.DisableFlag(1);
            }
        }
    }
    if (self->mode & 8) {
        ClearFlags04(base, 0x400);
    }
    if (self->mode & 0x20) {
        func_0203cf4c()->flags &= ~2;
    }
}
