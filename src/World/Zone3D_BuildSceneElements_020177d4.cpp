#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneResourceTree.h"
#include <globaldefs.h>
#include "Resource/GameResources.h"

// BmdjElementResource::kind (Zone3D_SetUpScriptNode: Zone3D_LoadElementModel sets up a model, Zone3D_LoadElementTerrainMesh a terrain mesh,
// Zone3D_LoadElementObject an Object3D)
enum {
    kElementResource_Model = 0,
    kElementResource_Terrain = 1,
    kElementResource_Object = 2,
};

// Main, originally func_020177d4 (USA 0x020177d4, EUR 0x020177e4, JPN 0x02017574)
extern "C" ARM void Zone3D_BuildSceneElements(Zone3D *zone, void *scriptNode, SafeAllocator *allocator) {
    ZoneResourceTree *tree = static_cast<ZoneResourceTree *>(scriptNode);
    GameState::GetInstance();
    LightingManager *lighting = LightingManager::GetInstance();
    Manager_1f2a4 *records    = reinterpret_cast<Manager_1f2a4 *>(&tree->resources.records);
    int count                 = records->count;
    tree->nodes = static_cast<ZoneResourceRuntimeNode *>(allocator->Allocate(count * sizeof(ZoneResourceRuntimeNode)));
    if (tree->nodes == NULL) return;

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source   = reinterpret_cast<ZoneResourceTreeRecord *>(BmdjScriptState_GetElementRecord(records, i));
        ZoneResourceRuntimeNode *element = &tree->nodes[i];
        BmdjSceneElement_Init(reinterpret_cast<InitTarget02013018 *>(element));
        element->key = source->key;
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source   = reinterpret_cast<ZoneResourceTreeRecord *>(BmdjScriptState_GetElementRecord(records, i));
        ZoneResourceRuntimeNode *element = &tree->nodes[i];
        int parentKey                    = source->parentKey;
        if (parentKey > -1) {
            for (int j = 0; j < count; j++) {
                ZoneResourceRuntimeNode *parent = &tree->nodes[j];
                if (source->parentKey == parent->key) {
                    element->parent = parent;
                    BmdjSceneElement_AddChild(reinterpret_cast<ListNode *>(parent), reinterpret_cast<ListNode *>(element));
                    break;
                }
            }
        } else if (i != 0) {
            BmdjSceneElement_AppendSibling(reinterpret_cast<Node020130e0 *>(tree->nodes), reinterpret_cast<Node020130e0 *>(element));
        }
    }

    int timeOfDay        = lighting->timeOfDayIndex_;
    void *overrideObject = GetGameResources()->unknown_ptr_3718;
    if (overrideObject != NULL && IsField600B4Zero_021b8b54(overrideObject)) {
        unsigned char *overrideData = static_cast<unsigned char *>(func_ov017_021b8478(overrideObject));
        timeOfDay                   = overrideData[5];
    }

    for (int i = 0; i < count; i++) {
        ZoneResourceTreeRecord *source   = reinterpret_cast<ZoneResourceTreeRecord *>(BmdjScriptState_GetElementRecord(records, i));
        ZoneResourceRuntimeNode *element = &tree->nodes[i];
        element->source                  = source;
        element->movementSpeed           = 0;
        Vector3i position                = source->position;
        if (element->parent == NULL) Vector3fix_Add(&position, &tree->position, &position);

        if (source->flags & 0x10)
            element->flags |= BmdjElementFlag_Hidden;
        else if (source->flags & (1 << timeOfDay))
            element->flags &= ~BmdjElementFlag_Hidden;
        else
            element->flags |= BmdjElementFlag_Hidden;

        if (source->trackerKey < 0) {
            element->tracker = &tree->resources.trackers[source->key];
        } else {
            int index =
                BmdjScriptState_FindResourceIndex(reinterpret_cast<Table_1f1b0 *>(&tree->resources.records), source->trackerKey);
            if (index >= 0) element->tracker = &tree->resources.trackers[index];
        }

        Struct02012ff0 *resource = element->tracker;
        if (resource != NULL) {
            if (resource->field0 == kElementResource_Model && resource->field4 == 0) element->tracker = NULL;
            if (resource->field0 == kElementResource_Terrain && resource->field4 == 0) element->tracker = NULL;
            if (resource->field0 == kElementResource_Object && resource->field4 == 0) element->tracker = NULL;
            if (resource->field0 == kElementResource_Object && element->tracker != NULL) {
                element->object = static_cast<Object3D *>(allocator->Allocate(sizeof(Object3D)));
                if (element->object == NULL) {
                    element->tracker = NULL;
                } else {
                    element->object->Initialize();
                    resource->field4->ShallowCloneTo(element->object);
                }
            }
        }
    }
    BmdjSceneElement_ComputeTreeTransforms(tree->nodes);
}
