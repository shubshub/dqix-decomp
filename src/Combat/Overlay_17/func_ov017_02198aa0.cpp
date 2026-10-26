#include <globaldefs.h>
#include "World/ZoneLifecycle.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct BitField0203402c;
struct Vec3copy0202ec84;
struct TailList020469b4;
struct TailNode020469b4;
struct Position02198aa0 { int x,y,z; };
struct GrottoView02198aa0 { unsigned char padding0[8]; signed char offset; unsigned char padding9[3]; int entranceZone; Position02198aa0 position; };
struct Event02198aa0 { unsigned char kind; unsigned char padding1[19]; };
struct State02198aa0 { unsigned short zoneId; unsigned char padding2[5]; unsigned char field7; unsigned char padding8[4]; unsigned char fieldC; unsigned char paddingD[15]; unsigned short angle; };
int MessageSystem_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" void* Zone3D_GetInstance();
int GameObject_IsGesturing(signed char*);
int GameObject_IsSinking(BitField0203402c*);
int LinkSession_IsActive(int*);
extern "C" int LinkSession_IsGuest(void*);
void InitObj0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(void*, Event02198aa0*);
int Camera_WorldToScreen(void*, Vec3copy0202ec84*, int*, int*);
void* GameState_GetZoneTransition(GameState*);
void InitStruct02070378(char*);
void FieldTask_InitEnterZone(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void InitByteHeader_021be0a0(unsigned char*);

// USA: func_ov017_02198aa0
extern "C" ARM void func_ov017_02198aa0(GameResources* self) {
    GameState* game = GameState::GetInstance();
    GameObject* actor = game->GetLeader();
    void* camera = game->GetCamera();
    GameResources* resources = GetGameResources();
    MessageSystem* controller = (MessageSystem*)MessageSystem_GetInstance();
    void* search = LinkSession_GetInstance();
    void* zone = Zone3D_GetInstance();
    GrottoStruct* grotto = game->GetGrottoStruct();
    unsigned char discovery = grotto->activeMapData.GetDiscoveryState();
    unsigned char mapType = grotto->activeMapData.GetMapType();
    unsigned char environment = grotto->activeEnviron;
    if (GameObject_IsGesturing((signed char*)actor) || !grotto->unknown_0[0]) return;
    if (((GrottoView02198aa0*)grotto)->entranceZone != actor->obj3D_.GetField06() || controller->mode) return;
    if (IsBrightnessTransitionActive(resources)) return;
    if (GameObject_IsSinking((BitField0203402c*)actor)) return;
    if (discovery != 2 && discovery != 3 && LinkSession_IsActive((int*)search) && LinkSession_IsGuest(search)) return;
    Position02198aa0 entrance = ((GrottoView02198aa0*)grotto)->position;
    int inside = 0;
    if (entrance.x - 0x2666 < actor->obj3D_.position_.x && actor->obj3D_.position_.x < entrance.x + 0x2666 &&
          entrance.z - 0x2666 < actor->obj3D_.position_.z && actor->obj3D_.position_.z < entrance.z + 0x2666 &&
          entrance.y - 0x1000 < actor->obj3D_.position_.y && actor->obj3D_.position_.y < entrance.y + 0x1000) inside = 1;
    if (!inside) return;
    Event02198aa0 event;
    InitObj0219a674((unsigned char*)&event);
    event.kind = 4;
    func_ov017_0219b33c(self, &event);
    int proceed = 0;
    if (g_keyManager.TestKeysPressed(1)) proceed = 1;
    int cursorX = -1;
    int cursorY = -1;
    if (g_touchInput.released_ && (unsigned int)g_touchInput.prevTimeHeld_ < 10) { cursorX = g_touchInput.prevX_; cursorY = g_touchInput.prevY_; }
    {
        int screenX, screenY;
        Camera_WorldToScreen(camera, (Vec3copy0202ec84*)&actor->obj3D_.position_, &screenX, &screenY);
        if (cursorX > 0x70 && cursorX < 0x90 && cursorY > 0x28 && cursorY < 0x60) proceed = 1;
        else if (screenX - 12 < cursorX && cursorX < screenX + 12 && screenY - 12 < cursorY && cursorY < screenY + 12) proceed = 0;
    }
    if (!proceed) return;
    if ((unsigned char)(discovery + 254) <= 1) {
        MaybeClearGrottoState0201bfd4(static_cast<Zone3D*>(zone));
        State02198aa0* state = (State02198aa0*)GameState_GetZoneTransition(game);
        InitStruct02070378((char*)state);
        state->field7 = 1;
        state->fieldC = 1;
        if (mapType == 2) {
            switch (environment) {
            case 1: state->zoneId = 0xa08d; break;
            case 2: state->zoneId = 0xa0f1; break;
            case 3: state->zoneId = 0xa155; break;
            case 4: state->zoneId = 0xa1b9; break;
            case 5: state->zoneId = 0xa21d; break;
            default: state->zoneId = 0xa08d; break;
            }
            unsigned short var20 = ((Struct_ov017_02198aa0_2*)var7)->unknown_8_;
            var19->unknown_0_ += var20;
            var19->unknown_1c_ = 0x323d;
        } else {
            var19->unknown_0_ = 0x9c41;
        }
        GameState_SetZoneTransition(game, state);
        TailList020469b4* list = (TailList020469b4*)resources->fieldTaskQueue_;
        unsigned char* node = (unsigned char*)resources->unknown_ptr_array_3700[3];
        FieldTask_InitEnterZone(node, 0);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    } else {
        TailList020469b4* list = (TailList020469b4*)self->fieldTaskQueue_;
        unsigned char* node = (unsigned char*)resources->fieldTasks_[26];
        InitByteHeader_021be0a0(node);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    }
}
