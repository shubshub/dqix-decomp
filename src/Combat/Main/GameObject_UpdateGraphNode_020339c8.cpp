#include <globaldefs.h>
#if defined(jpn)
enum { kEntryPrefix = 0x14 };
#else
enum { kEntryPrefix = 0x18 };
#endif
#include "World/Object3D.h"

struct ListEntry_02028430 {
    unsigned char id_, unknown_1_, adjacentCount_, unknown_3_;
    Vector3s position_; unsigned short unknown_a_;
    ListEntry_02028430** adjacent_;
};
struct List_02028430 { unsigned char header_[4]; ListEntry_02028430* entries_; };
struct List_020283fc;
struct Entry_02028bd0 {
    unsigned short zoneId_; char pad2[kEntryPrefix - 2];
    List_02028430 routeNodes_; char pad20[0x34 - 0x20];
    int active_; char unknown_38_[0x318 - 0x38];
};
struct GameObjectFields : Object3D {
    char padAC[0xb8 - 0xac]; unsigned short routeIndex_;
    char padBA[8]; unsigned char c2_low : 6; unsigned char routeEnabled_ : 1;
};
extern "C" Entry_02028bd0* ZoneRecords_GetInstance();
extern "C" Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" ListEntry_02028430* NodeGraph_GetNode(List_02028430*, int);
extern "C" int NodeGraph_FindNodeIndexById(List_020283fc*, int);
extern "C" Vector3fix func_02034104(void*);
extern "C" int NodeGraph_FindClosestNodeManhattan(List_02028430*, const Vector3fix&);

// Main, originally func_020339c8 (USA 0x020339c8, EUR 0x020339d8, JPN 0x02033500)
extern "C" ARM void GameObject_UpdateGraphNode(GameObjectFields* self) {
    if (!self->routeEnabled_) return;
    Entry_02028bd0* zoneRecords = ZoneRecords_GetInstance();
    Entry_02028bd0* zoneRecord = ZoneRecords_Find(zoneRecords, self->GetField06());
    if (!zoneRecord || !zoneRecord->active_) return;
    ListEntry_02028430* currentNode = NodeGraph_GetNode(&zoneRecord->routeNodes_, self->routeIndex_);
    if (!currentNode) return;
    if (self->unknown_0_ & 0x1200) {
        int index = NodeGraph_FindClosestNodeManhattan(&zoneRecord->routeNodes_, func_02034104(self));
        if (index > -1) self->routeIndex_ = index;
    } else if (currentNode->adjacentCount_) {
        Vector3fix position = func_02034104(self);
        Vector3fix nodePosition;
        nodePosition.x = currentNode->position_.x << 12;
        nodePosition.y = currentNode->position_.y << 12;
        nodePosition.z = currentNode->position_.z << 12;
        int distance = Vector3fix_Distance(&position, &nodePosition);
        int closerNodeId = -1;
        for (int i = 0; i < currentNode->adjacentCount_; ++i) {
            Vector3fix adjacentPosition;
            adjacentPosition.x = currentNode->adjacent_[i]->position_.x << 12;
            adjacentPosition.y = currentNode->adjacent_[i]->position_.y << 12;
            adjacentPosition.z = currentNode->adjacent_[i]->position_.z << 12;
            if (Vector3fix_Distance(&adjacentPosition, &position) < distance) closerNodeId = currentNode->adjacent_[i]->id_;
        }
        if (closerNodeId >= 0) {
            int index = NodeGraph_FindNodeIndexById((List_020283fc*)&zoneRecord->routeNodes_, closerNodeId);
            if (index > -1) self->routeIndex_ = index;
        }
    }
}
