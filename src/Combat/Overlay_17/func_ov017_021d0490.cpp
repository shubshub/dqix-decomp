#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/ZoneResourceTree.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" int GameState_GetStoryChapter(char* obj);
extern "C" int GameState_GetStoryPart(char* obj);
extern "C" int GameState_GetStoryStep(char* obj);
struct Struct_ov017_021d0490_4;
extern "C" Struct_ov017_021d0490_4* func_ov017_021b8470(void* obj);

struct Obj_021bd3a4;
extern "C" int func_ov017_021bd3a4(Obj_021bd3a4* obj);

struct Struct_ov017_021d0490_7 {
    unsigned char pad0[0x12];
    unsigned char visible;
    unsigned char unknown_13_[0x16 - 0x13];
    unsigned short id;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned short field_0x1c;
    unsigned char pad1e[0x52 - 0x1e];
    short unknown_52_;
#if defined(jpn)
    unsigned char unknown1_54_[0x98 - 0x54];
#else
    unsigned char unknown_54_[0x9c - 0x54];
#endif

    unsigned char busy;
};

struct Zone021d0490 {
    unsigned char pad0[2];
    unsigned char field_0x2;
    unsigned char unknown_3_;
};

struct Struct_ov017_021d0490_2 {
    unsigned char pad0[2];
    unsigned short field_0x2;
    unsigned char pad4[0xc - 4];
    int unknown_c_;
};

struct Struct_ov017_021d0490_3 {
    unsigned char pad0[0xc];
    int type;
};

struct Struct_ov017_021d0490_4 {
    unsigned char pad0[0x8e14];
    signed char unknown_8e14_;
    unsigned char unknown_8e15_[3];
    Struct_ov017_021d0490_3* mode;
};

struct Struct_ov017_021d0490_5 {
    unsigned char field_0x0;
    unsigned char field_0x1;
    unsigned char field_0x2;
    unsigned char mode : 2;
    unsigned char : 1;
    unsigned char kind : 2;
    unsigned char visible : 1;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
};

struct Struct_ov017_021d0490_6 {
    unsigned char tag;
    unsigned char pad[3];
    Struct_ov017_021d0490_5 payload;
};

static inline Struct_ov017_021d0490_7* inline_ov017_021d0490(GameResources* r) { return (Struct_ov017_021d0490_7*)r->unknown_ptr_array_371c[6]; }
static inline Zone021d0490* inline_ov017_021d0490_2(GameResources* r) { return (Zone021d0490*)r->unknown_ptr_3718; }
static inline Zone021d0490* GetOther(GameResources* r) { return (Zone021d0490*)r->fieldTasks_[13]; }

// USA: func_ov017_021d0490
extern "C" ARM void func_ov017_021d0490(int mode) {
    GameState* battle = GameState::GetInstance();
    void* link = LinkSession_GetInstance();
    unsigned short* data = (unsigned short*)Zone3D_GetInstance();
    GameResources* res = GetGameResources();
    Struct_ov017_021d0490_7* actor = inline_ov017_021d0490(res);
    Zone021d0490* zone = inline_ov017_021d0490_2(res);
    Zone021d0490* other = GetOther(res);
    void* queue = LinkMessageQueue_GetInstance();
    Struct_ov017_021d0490_6 packet;
    packet.tag = 0x97;
    Struct_ov017_021d0490_5* p = &packet.payload;

    if (LinkSession_IsHostOrSolo(link) != 0) {
        p->mode = mode;
        p->field_0x0 = GameState_GetStoryChapter((char*)battle);
        p->field_0x1 = GameState_GetStoryPart((char*)battle);
        p->field_0x2 = GameState_GetStoryStep((char*)battle);
        p->unknown_4_ = *data;
        Struct_ov017_021d0490_4* field = func_ov017_021b8470(zone);

        if (func_ov017_021bd3a4((Obj_021bd3a4*)actor) && actor->id != 0 && actor->busy == 0) {
            p->kind = 1;
            p->unknown_8_ = actor->id;
            p->unknown_a_ = actor->unknown_52_;
            p->unknown_c_ = actor->unknown_1a_;
            p->unknown_e_ = actor->unknown_18_;
            p->unknown_6_ = actor->field_0x1c;
            p->visible = actor->visible;
        } else if ((zone->unknown_3_ != 0 || (other->unknown_3_ != 0 && zone->field_0x2 != 0)) && field != NULL &&
                   field->unknown_8e14_ == 0) {
            Struct_ov017_021d0490_2* entry = (Struct_ov017_021d0490_2*)func_ov017_021b8478(zone);
            p->kind = 0;
            p->unknown_8_ = entry->unknown_c_;
            p->unknown_a_ = entry->field_0x2;
        } else if (zone->unknown_3_ != 0 && field->mode->type == 0x13) {
            p->kind = 1;
            p->unknown_8_ = 0x71e8;
            p->unknown_a_ = 0xffff;
            p->unknown_c_ = 0x199;
            p->unknown_e_ = 0x71e8;
            p->visible = 1;
        } else {
            p->kind = 2;
        }
    }
    func_0205e330(queue, &packet, 0);
}
