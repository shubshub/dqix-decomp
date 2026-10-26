#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Graphics/Animation3D.h"
#include "Graphics/Vector.h"
#include "World/ZoneResourceTree.h"

struct SePlayer;
void SePlayer_Play(SePlayer *, int, int);
int IsAnimationActive0209ca2c(void *);

extern SePlayer g_sePlayer;
extern char g_bgmPlayer[];
extern char data_020ef1f3[];  // "open"
extern char data_020ef1f8[];  // "open2"
extern char data_020ef1fe[];  // "close"
extern char data_020ef204[];  // "close2"

// Main, originally func_02015554 (USA 0x02015554, EUR 0x02015564, JPN 0x02015320)
extern "C" ARM void BmdjSceneElement_Update(void *zone, void *sceneElement) {
    ZoneResourceRuntimeNode *element = static_cast<ZoneResourceRuntimeNode *>(sceneElement);
    GameState *gameState           = GameState::GetInstance();
    Struct02012ff0 *resource       = element->tracker;
    if (!resource || !resource->field4) return;
    fix32_t delta = gameState->GetAnimationDeltaTime();
    if (resource->field0 == 0) {   // a model (Zone3D_SetUpScriptNode's Zone3D_LoadElementModel): advance its four animations
        if (resource->field8) resource->field8->AdvanceTimer(delta);
        if (resource->fieldc) resource->fieldc->AdvanceTimer(delta);
        if (resource->field10) resource->field10->AdvanceTimer(delta);
        if (resource->field14) resource->field14->AdvanceTimer(delta);

        short angle = element->angle;
        if (angle != fix32ReduceAngle0To2Pi(element->targetAngle)) {
            fix32_t distance = fix32SignedAngleDistance(angle, element->targetAngle);
            fix32_t step     = ((long long) element->rotationSpeed * delta + 0x800) >> 12;
            if (distance > 0) {
                if (distance < step)
                    element->angle = element->targetAngle;
                else
                    element->angle += step;
            } else if (distance < 0) {
                if (-distance < step)
                    element->angle = element->targetAngle;
                else
                    element->angle -= step;
            }
            element->angle = fix32ReduceAngle0To2Pi(element->angle);
        } else if (element->rotationSpeed != 0) {
            if (element->flags & 0x10) {
                element->rotationSpeed = 0;
            } else if (element->flags & 0x80) {
                element->flags &= ~0x80;
                element->rotationSpeed = 0;
            } else if (element->remaining > 0) {
                int remaining = element->remaining - 3;
                if (remaining < 0) {
                    remaining            = 0;
                    element->rotationSpeed = 0;
                }
                element->remaining = remaining;
                if (element->remaining == 0) element->flags |= BmdjElementFlag_Hidden;
            }
        }
        if (element->movementSpeed != 0) {
            if (Vector3fix_Distance(&element->position, &element->targetPosition) < element->movementSpeed) {
                element->position      = element->targetPosition;
                element->movementSpeed = 0;
            } else {
                Vector3fix step = element->direction;
                Vector3fixMultiplyScalar(&step, element->movementSpeed, &step);
                Vector3fix_Add(&element->position, &step, &element->position);
            }
        }
    }
    if ((element->flags & 0x100) && element->object) {
        if (element->animationState == 0) {
            element->object->SetAnimationPlaybackSpeed(0x1800, 0);
            if (element->object->SetAnimationByName(data_020ef1f3, 1))
                SePlayer_Play(&g_sePlayer, 0x12, 0);
            else if (element->object->SetAnimationByName(data_020ef1f8, 1))
                SePlayer_Play(&g_sePlayer, 0x62, 0);
            element->animationState = 1;
        } else if (element->animationState == 1) {
            if (element->object->HasAnimationStopped()) {
                element->delay          = 500;
                element->animationState = 2;
            }
        } else if (element->animationState == 2) {
            unsigned int deltaTime = gameState->GetEffectiveDeltaTime();
            if (deltaTime < element->delay) {
                element->delay -= deltaTime;
            } else if (!IsAnimationActive0209ca2c(g_bgmPlayer)) {
                if (element->object->SetAnimationByName(data_020ef1fe, 5))
                    SePlayer_Play(&g_sePlayer, 0x13, 0);
                else if (element->object->SetAnimationByName(data_020ef204, 5))
                    SePlayer_Play(&g_sePlayer, 0x62, 0);
                element->flags &= ~0x100;
            }
        }
    }
}
