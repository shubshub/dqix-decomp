#include <globaldefs.h>
#include "GameState/GameState.h"


struct Vec3_0202445c { int x; int y; int z; };

// The MapDisplay fields this sets (header: displayMode, scale, cameraX, cameraZ)
struct Obj0202445c {
    char pad0[0x14];
    int displayMode;
    char pad1[0x20];
    int scale;
    char pad2[0x570];
    int cameraX;
    int cameraZ;
};

enum {
    kDisplayModeBand = 3,   // the camera's z stays 0 within a band around the leader
    kDisplayModeXY = 4,     // the camera follows the leader's x and y
    kBandAbove = 0x37000,   // 55 pixels, divided by the scale
    kBandBelow = 0x1e000,   // 30 pixels
};

// Puts the map camera on the leader's position
// Main, originally func_0202445c (USA 0x0202445c, EUR 0x0202446c, JPN 0x02023e30)
extern "C" ARM void MapDisplay_CenterOnLeader(struct Obj0202445c* obj) {
    GameState* game = GameState::GetInstance();
    if (game == 0) return;
    GameObject* leader = game->GetLeader();
    if (leader == 0) return;

    struct Vec3_0202445c* leaderPosition = (struct Vec3_0202445c*)((char*)leader + 0x44);
    obj->cameraX = leaderPosition->x;
    obj->cameraZ = leaderPosition->z;

    if (obj->displayMode == kDisplayModeBand) {
        int above = fix32_Divide((fix32_t)(kBandAbove), (fix32_t)obj->scale);
        int below = fix32_Divide((fix32_t)(kBandBelow), (fix32_t)obj->scale);
        if (obj->cameraZ < 0) {
            if (obj->cameraZ < -above) {
                obj->cameraZ = -(above + obj->cameraZ);
            } else {
                obj->cameraZ = 0;
            }
        } else if (obj->cameraZ > 0) {
            if (obj->cameraZ > below) {
                obj->cameraZ = obj->cameraZ - below;
            } else {
                obj->cameraZ = 0;
            }
        } else {
            obj->cameraZ = 0;
        }
    } else if (obj->displayMode == kDisplayModeXY) {
        obj->cameraZ = leaderPosition->y;
    }
}
