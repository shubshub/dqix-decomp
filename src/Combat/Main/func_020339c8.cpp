#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020339c8_24 = 0x14 };
#else
enum { Enum_020339c8_24 = 0x18 };
#endif
#include "World/Object3D.h"

struct Struct_02028430_2 {
    unsigned char unknown_0_, unknown_1_, unknown_2_, unknown_3_;
    Vector3s unknown_4_; unsigned short unknown_a_;
    Struct_02028430_2** unknown_c_;
};
struct Struct_02028430 { unsigned char unknown_0_[4]; Struct_02028430_2* unknown_4_; };
struct Struct_020283fc;
struct Struct_020fdd44 {
    unsigned short unknown_0_; char unknown_2_[Enum_020339c8_24 - 2];
    Struct_02028430 unknown_18_; char unknown_20_[0x34 - 0x20];
    int unknown_34_; char unknown_38_[0x318 - 0x38];
};
struct Struct_020339c8 : Object3D {
    char unknown_ac_[0xb8 - 0xac]; unsigned short unknown_b8_;
    char unknown_ba_[8]; unsigned char unknown_c2_0_ : 6; unsigned char unknown_c2_6_ : 1;
};
Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);
ListEntry_02028430* GetListEntryChecked(List_02028430*, int);
int FindListIndexById(List_020283fc*, int);
extern "C" Vector3fix func_02034104(void*);
extern "C" int func_02028524(Struct_02028430*, const Vector3fix&);

// USA: func_020339c8
extern "C" ARM void func_020339c8(RoutedObject* self) {
    if (!self->routeEnabled_) return;
    Entry_02028bd0* table = ZoneRecords_GetInstance();
    Entry_02028bd0* entry = FindInlineEntryById(table, self->GetField06());
    if (!entry || !entry->active_) return;
    ListEntry_02028430* node = GetListEntryChecked(&entry->list_, self->routeIndex_);
    if (!node) return;
    if (self->unknown_0_ & 0x1200) {
        int index = func_02028524(&entry->list_, func_02034104(self));
        if (index > -1) self->routeIndex_ = index;
    } else if (node->adjacentCount_) {
        Vector3fix position = func_02034104(self);
        Vector3fix nodePosition;
        nodePosition.x = node->position_.x << 12;
        nodePosition.y = node->position_.y << 12;
        nodePosition.z = node->position_.z << 12;
        int distance = Vector3fix_Distance(&position, &nodePosition);
        int selected = -1;
        for (int i = 0; i < node->adjacentCount_; ++i) {
            Vector3fix adjacentPosition;
            adjacentPosition.x = node->adjacent_[i]->position_.x << 12;
            adjacentPosition.y = node->adjacent_[i]->position_.y << 12;
            adjacentPosition.z = node->adjacent_[i]->position_.z << 12;
            if (Vector3fix_Distance(&adjacentPosition, &position) < distance) selected = node->adjacent_[i]->id_;
        }
        if (var7 >= 0) {
            int var10 = func_020283fc((Struct_020283fc*)&var1->unknown_18_, var7);
            if (var10 > -1) arg0->unknown_b8_ = var10;
        }
    }
}
