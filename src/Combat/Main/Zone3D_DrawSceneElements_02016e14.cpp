#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Model3D.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/Graphics.h"
#include "World/Object3D.h"
#include "World/ZoneResourceTree.h"

// BmdjElementResource::kind (Zone3D_SetUpScriptNode: Zone3D_LoadElementModel sets up a model, Zone3D_LoadElementObject an Object3D)
enum {
    kElementResource_Model = 0,
    kElementResource_Object = 2,
};

// BmdjSceneElement::flags bit Zone3D_MarkDoorElements sets on every door's element
enum { kElementFlag_Door = 0x8 };

struct DrawnElement02016e14 {
    unsigned char trackerKey;
    unsigned char nodeId;
};

struct Zone3D02016e14 {
    char unknown0[0x8];
    Zone3D_StructPtr_8* pUnknownStruct_8_;
#if defined(jpn)
    char unknownC[0x852 - 0xc];
#else
    char unknownC[0x832 - 0xc];
#endif
    unsigned char timeOfDayChanged_;
    unsigned char refreshVisibility_;
#if defined(jpn)
    char unknown854[0x281c - 0x854];
#else
    char unknown834[0x27dc - 0x834];
#endif
    struct DrawnElement02016e14 drawnElements_[0x20];
    unsigned char drawnElementCount_;
};

struct BmdjElementResource02016e14 {
    short kind;
    short unknown2;
    Model3D* model;
};

struct BmdjSceneElement02016e14 {
    unsigned short id;
    unsigned short flags;
    signed char alpha : 7;
    signed char flag4 : 1;
    char unknown5;
    short angle;
    Vector3i position;
    Vector3i scale;
    ZoneResourceTreeRecord* source;
    struct BmdjElementResource02016e14* resource;
    struct BmdjSceneElement02016e14* parent;
    struct BmdjSceneElement02016e14* firstChild;
    struct BmdjSceneElement02016e14* next;
    char unknown34[0x4];
    short copiedAngle;
    char unknown3a[0x54 - 0x3a];
    Object3D* object;
};

void RenderConfig_SetObjectRotation(void* arg0);
extern "C" void Mat3x3_WriteRotationY(Matrix3x3* out, int sine, int cosine);

// Main, originally func_02016e14 (USA 0x02016e14, EUR 0x02016e24, JPN 0x02016bb4)
extern "C" ARM void Zone3D_DrawSceneElements(struct Zone3D02016e14* zone, BmdjScriptNode* scriptNode, struct BmdjSceneElement02016e14* element, int skipDraw) {
    GameState::GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    struct BmdjElementResource02016e14* resource = element->resource;
    ZoneResourceTreeRecord* source = element->source;
    int timeOfDay = lighting->timeOfDayIndex_;

    if ((zone->timeOfDayChanged_ != 0 || zone->refreshVisibility_ != 0) && zone->pUnknownStruct_8_ != NULL) {
        unsigned int unknownC = zone->pUnknownStruct_8_->unknown_c_low_;
        if (unknownC == 0 || unknownC == 7 || zone->refreshVisibility_ != 0) {
            if (!(source->flags & 0x10)) {
                if (source->flags & (1 << timeOfDay)) {
                    element->flags &= ~BmdjElementFlag_Hidden;
                } else {
                    element->flags |= BmdjElementFlag_Hidden;
                }
            }
        }
    }

    GXFIFO_DIFFUSE_AMBIENT = 0x7fff7fff;

    Model3D* model = NULL;
    Object3D* object = NULL;
    int skipChildren = 0;
    if (skipDraw == 0 && !(element->flags & BmdjElementFlag_Hidden) && resource != NULL) {
        if (resource->kind == kElementResource_Model) {
            model = resource->model;
        } else if (resource->kind == kElementResource_Object) {
            object = element->object;
            if (object != NULL) {
                model = object->pModel_;
            }
        }
    }

    if (model != NULL) {
        RenderConfig::SetObjectPosition(&element->position);

        int angle = element->angle;
        if (element->copiedAngle != 0) {
            angle = fix32ReduceAngle0To2Pi(angle + element->copiedAngle);
        }
        fix32_t cosine = fix32cos(angle);
        fix32_t sine = fix32sin(angle);
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        RenderConfig_SetObjectRotation(&rotation);

        Vector3i scale;
        scale.x = element->scale.x;
        scale.y = element->scale.y;
        scale.z = element->scale.z;
        RenderConfig::SetObjectScale(&scale);

        if ((element->flags & kElementFlag_Door) || element->flag4 != 0) {
            model->SetAlpha(element->alpha);
        }

        if (model->rawInternalModel_ != NULL) {
            LightingManager* manager = LightingManager::GetInstance();
            manager->ApplyAmbientColorToModel(model->rawInternalModel_);

            int drawn = 0;
            if (resource->kind == kElementResource_Model) {
                RenderConfig::SubmitToFifo();
                drawn = model->Draw(true);
            } else if (resource->kind == kElementResource_Object) {
                object->AdvanceEffects();
                drawn = object->DrawWithCurrentRenderConfig(true);
            }

            if (drawn) {
                zone->drawnElements_[zone->drawnElementCount_].trackerKey = (unsigned char)source->trackerKey;
                zone->drawnElements_[zone->drawnElementCount_].nodeId = (unsigned char)scriptNode->unknown0;
                zone->drawnElementCount_++;
            }
        }
    } else {
        skipChildren = 1;
    }
    if (element->firstChild != NULL) {
        Zone3D_DrawSceneElements(zone, scriptNode, element->firstChild, skipChildren);
    }
    if (element->next != NULL) {
        Zone3D_DrawSceneElements(zone, scriptNode, element->next, skipDraw);
    }
}
