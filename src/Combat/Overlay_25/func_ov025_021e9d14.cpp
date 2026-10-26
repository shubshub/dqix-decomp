#include <globaldefs.h>
#include "GameState/GameState.h"

struct SePlayer;
struct Obj0203a48c;
struct Obj0203a588;
struct Obj02176150;

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char f10;
    unsigned char unknown_11_;
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

struct Struct_ov025_021e9d14_4 {
    char pad0[0xc];
    short amount;
};

struct Struct_ov025_021e9d14_5 {
    char pad0[0x14];
    struct Struct_ov025_021e9d14_4* unknown_14_;
    char pad18[0x1c - 0x18];
    short targetId;
    unsigned short unknown_1e_;
    unsigned short actorId;
    char unknown_22_[0x24 - 0x22];
    unsigned short value;
    char unknown_26_[0x30 - 0x26];
    struct Struct_ov025_021e9d14_5* next;
};

struct Struct_ov025_021e9d14_6 {
    char pad0[0x10];
    struct Struct_ov025_021e9d14_5* head;
};

struct Struct_ov025_021e9d14 {
    char pad0[6];
    unsigned short value;
};

struct Struct_ov025_021e9d14_2 {
    char pad0[0x130];
    struct Struct_ov025_021e9d14* gauge;
};

struct Struct_ov025_021e9d14_3 {
    char pad0[0xe];
    unsigned short value;
};

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f20(void* work);
extern "C" int func_ov025_021def24(void* work);
extern "C" void* func_ov000_02160f08(void* work);
extern "C" void* func_ov000_0215feb4(char* base, int threshold, int slot);
extern "C" struct Struct_ov025_021e9d14_3* func_ov025_021dafd0(char* obj, int id);
extern "C" struct Obj0203a588* NumberPopups_GetInstance(void);
struct Vec3Int0203a48c;
extern "C" void NumberPopups_Add(Obj0203a48c*, int, Vec3Int0203a48c*, int, int, int);
extern "C" void* func_02057924(void);
extern "C" void func_02078484(struct Struct_02078398_2* p);
extern "C" void func_02057fb4(void* list, int id, void* config);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void func_ov000_02176150(struct Obj02176150* obj, unsigned short val);

extern struct SePlayer g_sePlayer;

// USA: func_ov025_021e9d14
extern "C" ARM void func_ov025_021e9d14(void) {
    void* work = func_ov000_02160130();
    struct Struct_ov025_021e9d14_6* slot = (struct Struct_ov025_021e9d14_6*)func_ov000_02160f20(work);
    if (func_ov025_021def24(work) != 0) {
        return;
    }
    GameState* battle = GameState::GetInstance();
    char* entries = (char*)func_ov000_02160f08(func_ov000_02160130());
    struct Struct_ov025_021e9d14_5* node = slot->head;
    if (func_ov000_0215feb4((char*)node, 0, 5) != NULL) {
        return;
    }
    for (; node != NULL; node = node->next) {
        int id = node->actorId;
        unsigned short value = node->value;
        struct Struct_ov025_021e9d14_3* entry = func_ov025_021dafd0(entries, id);
        GameObject* actor = battle->GetCombatantByIndex(id);
        if (actor == NULL) {
            continue;
        }
        if (node->unknown_14_ != NULL) {
            int amount = -node->unknown_14_->amount;
            if (amount > 0) {
                struct Obj0203a48c* popups = (struct Obj0203a48c*)NumberPopups_GetInstance();
                Vector3fix pos = actor->obj3D_.position_;
                pos.y += actor->obj3D_.GetHeight();
                NumberPopups_Add(popups, amount, (Vec3Int0203a48c*)&pos, 3, 0, 0);
                void* list = func_02057924();
                struct Struct_02078398_2 req;
                func_02078484(&req);
                req.offset.y += actor->obj3D_.GetHeight() / 2;
                req.objectId = id;
                func_02057fb4(list, 0x10, &req);
                SePlayer_Play(&g_sePlayer, 0x65, 0);
            }
        }
        int isPartyMember = (id >= 0 && id <= 3) ? 1 : 0;
        if (!isPartyMember && node->unknown_14_ != NULL) {
            value = node->unknown_1e_;
            entry = func_ov025_021dafd0(entries, node->targetId);
            actor = battle->GetCombatantByIndex(node->targetId);
        }
        if (entry != NULL && actor != NULL) {
            func_ov000_02176150((struct Obj02176150*)entry, value);
            entry->value = value;
            ((struct Struct_ov025_021e9d14_2*)actor)->gauge->value = value;
        }
    }
}
