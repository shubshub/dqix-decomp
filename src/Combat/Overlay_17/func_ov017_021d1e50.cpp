#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct Struct_ov017_021cd748_6 { char pad[4]; unsigned short type; unsigned short target; unsigned short first; unsigned short second; short x; short y; short z; };
struct TransitionHeader { unsigned short target; char pad2[5]; unsigned char active; char pad8[8]; Vector3i position; unsigned short angle; char pad1e[0x43]; unsigned char direct; };
struct TransitionZone {
    unsigned short id;
#if defined(jpn)
    char pad[0x27f6];
#else
    char pad[0x27b6];
#endif
    Vector3i position;
};
struct TailList020469b4;
struct TailNode020469b4 { char unknown_0_[8]; };
struct Struct_ov017_021d1e50_3 : TailNode020469b4 {
    unsigned short first;
#if defined(jpn)
    char pad[0xf7];
#else
    char pad[0xfb];
#endif
    unsigned char special;
};
struct SearchStruct0202c1a4;
extern "C" int LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" int FieldTaskQueue_IsEmpty(void**);
extern "C" TransitionZone* Zone3D_GetInstance();
extern "C" void func_ov017_021baedc(Struct_ov017_021d1e50_3*, int);
extern "C" void func_ov017_021bbbf8(void*, unsigned short);
extern "C" int GameState_GetStoryChapter(char*);
extern "C" void func_020469b4(TailList020469b4*, TailNode020469b4*);
extern "C" void* GameState_GetZoneTransition(GameState*);
extern "C" void func_02070378(char*);
extern "C" void GameState_SetZoneTransition(void*, const void*);
extern "C" void FieldTask_InitEnterZone(unsigned char*, int);
extern "C" void func_ov017_021a65c4(void*, unsigned char, int);

// USA: func_ov017_021d1e50
extern "C" ARM void func_ov017_021d1e50(int unused, Struct_ov017_021cd748_6* event, GameState* game, GameResources* resources, SearchStruct0202c1a4* search) {
    TransitionHeader* header;
    int follow;
    int id;
    int first;
    TailList020469b4* list;
    Struct_ov017_021d1e50_3* node;
    if (!LinkSession_GetOwnSlot(search)) return;
    list = (TailList020469b4*)resources->fieldTaskQueue_;
    if (!FieldTaskQueue_IsEmpty((void**)list)) return;
    TransitionZone* zone = Zone3D_GetInstance();
    id = zone->id;
    if (id != 0x1901 && id != 0x1902 && id != 0x1903 && id != 0x1904) return;
    if (event->first || event->second) {
        node = (Struct_ov017_021d1e50_3*)resources->unknown_ptr_array_371c[6];
        func_ov017_021baedc(node, 1);
        first = event->first;
        int second = event->second;
        if (!first) { first = second; second = 0; }
        node->first = first;
        func_ov017_021bbbf8(node, second);
        if (GameState_GetStoryChapter((char*)game) >= 0x13 && first == 0x7345 && (unsigned int)(id - 0x1901) <= 3) node->special = 1;
        func_020469b4(list, node);
    } else {
        header = (TransitionHeader*)GameState_GetZoneTransition(game);
        func_02070378((char*)header);
        follow = 1;
        header->active = 1;
        if (event->type) {
            switch (event->type) {
            case 1:
                header->target = 0x1198;
                follow = 0;
                header->angle = 0;
                header->position.x = -0xd000;
                header->position.y = 0x4333;
                header->position.z = -0xd000;
                break;
            case 2:
                header->target = 0x4e27;
                header->angle = 0;
                header->position.x = -0x2b000;
                header->position.y = 0x14cc;
                header->position.z = -0x22000;
                break;
            case 4:
                header->target = 0x4e42;
                header->angle = 0;
                header->position.x = 0x4000;
                header->position.y = 0x14cc;
                header->position.z = 0x41000;
                break;
            case 3:
                header->target = 0x10cd;
                header->angle = 0x3244;
                follow = 0;
                header->position.x = 0;
                header->position.y = -0x6ccc;
                header->position.z = 0;
                break;
            case 5:
                header->target = 0x1130;
                header->angle = 0x3244;
                follow = 0;
                header->position.x = 0;
                header->position.y = -0x5ccc;
                header->position.z = 0x1000;
                break;
            }
            GameState_SetZoneTransition(game, header);
            unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3700[3];
            FieldTask_InitEnterZone(node, 0);
            func_020469b4(list, (TailNode020469b4*)node);
            if (follow) func_ov017_021a65c4(resources, 1, 0);
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
            func_020469b4(list, (TailNode020469b4*)node);
            func_ov017_021a65c4(resources, follow, 0);
        }
    }
}
