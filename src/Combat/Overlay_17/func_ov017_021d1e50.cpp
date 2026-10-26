#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021cd748_6 { char unknown_0_[4]; unsigned short unknown_4_; unsigned short unknown_6_; unsigned short unknown_8_; unsigned short unknown_a_; short unknown_c_; short unknown_e_; short unknown_10_; };
struct Struct_ov017_021d1e50 { unsigned short unknown_0_; char unknown_2_[5]; unsigned char unknown_7_; char unknown_8_[8]; Vector3i unknown_10_; unsigned short unknown_1c_; char unknown_1e_[0x43]; unsigned char unknown_61_; };
struct Struct_ov017_021d1e50_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x27f6];
#else
    char unknown1_2_[0x27b6];
#endif
    Vector3i unknown_27b8_;
};
struct Struct_0201bdac_2;
struct Struct_0201bdac { char unknown_0_[8]; };
struct Struct_ov017_021d1e50_3 : Struct_0201bdac {
    unsigned short unknown_8_;
#if defined(jpn)
    char unknown_a_[0xf7];
#else
    char unknown1_a_[0xfb];
#endif
    unsigned char unknown_105_;
};
struct SearchStruct0202c1a4;
int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
int FieldTaskQueue_IsEmpty(void**);
extern "C" TransitionZone* Zone3D_GetInstance();
extern "C" void func_ov017_021baedc(TransitionNode*, int);
void SetField11c_021bbbf8(void*, unsigned short);
int GameState_GetStoryChapter(char*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void* GameState_GetZoneTransition(GameState*);
void InitStruct02070378(char*);
void GameState_SetZoneTransition(void*, const void*);
void FieldTask_InitEnterZone(unsigned char*, int);
void InitAndAppendState61_021a65c4(void*, unsigned char, int);

// USA: func_ov017_021d1e50
extern "C" ARM void func_ov017_021d1e50(int unused, TransitionEvent* event, GameState* game, GameResources* resources, SearchStruct0202c1a4* search) {
    TransitionHeader* header;
    int follow;
    int id;
    int first;
    TailList020469b4* list;
    TransitionNode* node;
    if (!LinkSession_GetOwnSlot(search)) return;
    list = (TailList020469b4*)resources->fieldTaskQueue_;
    if (!FieldTaskQueue_IsEmpty((void**)list)) return;
    TransitionZone* zone = Zone3D_GetInstance();
    id = zone->id;
    if (id != 0x1901 && id != 0x1902 && id != 0x1903 && id != 0x1904) return;
    if (event->first || event->second) {
        node = (TransitionNode*)resources->unknown_ptr_array_371c[6];
        func_ov017_021baedc(node, 1);
        first = event->first;
        int second = event->second;
        if (!first) { first = second; second = 0; }
        node->first = first;
        SetField11c_021bbbf8(node, second);
        if (GameState_GetStoryChapter((char*)game) >= 0x13 && first == 0x7345 && (unsigned int)(id - 0x1901) <= 3) node->special = 1;
        AppendNodeToTail(list, node);
    } else {
        header = (TransitionHeader*)GameState_GetZoneTransition(game);
        InitStruct02070378((char*)header);
        follow = 1;
        header->active = 1;
        if (event->type) {
            switch (event->type) {
            case 1:
                var0->unknown_0_ = 0x1198;
                var1 = 0;
                var0->unknown_1c_ = 0;
                var0->unknown_10_.x = -0xd000;
                var0->unknown_10_.y = 0x4333;
                var0->unknown_10_.z = -0xd000;
                break;
            case 2:
                var0->unknown_0_ = 0x4e27;
                var0->unknown_1c_ = 0;
                var0->unknown_10_.x = -0x2b000;
                var0->unknown_10_.y = 0x14cc;
                var0->unknown_10_.z = -0x22000;
                break;
            case 4:
                var0->unknown_0_ = 0x4e42;
                var0->unknown_1c_ = 0;
                var0->unknown_10_.x = 0x4000;
                var0->unknown_10_.y = 0x14cc;
                var0->unknown_10_.z = 0x41000;
                break;
            case 3:
                var0->unknown_0_ = 0x10cd;
                var0->unknown_1c_ = 0x3244;
                var1 = 0;
                var0->unknown_10_.x = 0;
                var0->unknown_10_.y = -0x6ccc;
                var0->unknown_10_.z = 0;
                break;
            case 5:
                var0->unknown_0_ = 0x1130;
                var0->unknown_1c_ = 0x3244;
                var1 = 0;
                var0->unknown_10_.x = 0;
                var0->unknown_10_.y = -0x5ccc;
                var0->unknown_10_.z = 0x1000;
                break;
            }
            GameState_SetZoneTransition(game, header);
            unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone(node, 0);
            AppendNodeToTail(list, (TailNode020469b4*)node);
            if (follow) InitAndAppendState61_021a65c4(resources, 1, 0);
        } else if (event->target) {
            header->direct = 1;
            header->target = event->target;
            header->angle = 0;
            header->position.x = 0x100000;
            header->position.y = 0;
            header->position.z = 0x100000;
            Vector3i position;
            position.x = event->x << 7;
            position.y = event->y << 7;
            position.z = event->z << 7;
            zone->position = position;
            GameState_SetZoneTransition(game, header);
            unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone(node, 0);
            AppendNodeToTail(list, (TailNode020469b4*)node);
            InitAndAppendState61_021a65c4(resources, follow, 0);
        }
    }
}
