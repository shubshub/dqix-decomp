#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* Zone3D_GetInstance(void);

struct Entry_1f170 {
    short id;
    unsigned char flags;
    char pad3[0x8 - 0x3];
    struct Entry_1f170* next;
};

struct EntryList_1f170 {
    struct Entry_1f170* entries;
    int count;
};

struct Element_1f2cc {
    short key;
    short entryId;
    char pad4[0x20 - 0x4];
};

struct Manager_1f2cc {
    struct EntryList_1f170 entryList;
    char pad8[0xc - 0x8];
    struct Element_1f2cc* elements;
    int count;
};

extern "C" struct Element_1f2cc* BmdjScriptState_FindElementRecord(struct Manager_1f2cc* manager, int key);
extern "C" struct Entry_1f170* BmdjScriptState_FindResource(struct EntryList_1f170* list, int id);

struct Struct_ov001_021601f8_3 {
    char pad0[0x54];
    NSBXXInternalModel* model;
};

struct Struct_ov001_021601f8_4 {
    char pad0[0x8];
    struct Struct_ov001_021601f8_3* holder;
};

struct Struct_ov001_021601f8_5 {
    short type;
    unsigned short flags;
    union {
        struct Struct_ov001_021601f8_3* holder;
        struct Struct_ov001_021601f8_4* unknown1_4_;
    };
};

struct Struct_ov001_021601f8 {
    unsigned short key;
    char pad2[0x24 - 0x2];
    struct Struct_ov001_021601f8_5* obj;
    char pad28[0x2c - 0x28];
    struct Struct_ov001_021601f8* child;
    struct Struct_ov001_021601f8* sibling;
};

struct Struct_ov001_021601f8_2 {
    char pad0[0x98];
    int timeOfDay;
};

// USA: func_ov001_021601f8
extern "C" ARM void func_ov001_021601f8(struct Struct_ov001_021601f8* node, struct Manager_1f2cc* manager) {
    Zone3D_GetInstance();
    LightingManager* lighting = LightingManager::GetInstance();
    struct Struct_ov001_021601f8_5* obj = node->obj;
    int timeOfDay = ((struct Struct_ov001_021601f8_2*)lighting)->timeOfDay;
    struct Element_1f2cc* element = BmdjScriptState_FindElementRecord(manager, node->key);
    struct Entry_1f170* entry = BmdjScriptState_FindResource(&manager->entryList, element->entryId);
    struct Entry_1f170* variant = entry->next;
    while (variant != NULL) {
        if (variant->id == timeOfDay) {
            entry = variant;
            break;
        }
        variant = variant->next;
    }

    if (obj != NULL) {
        if (obj->type == 0 && obj->holder != NULL && obj->holder->model != NULL && !(obj->flags & 1)) {
            if (entry != NULL && !(entry->flags & 0x20)) {
                lighting->ModelTransformTintBrightnessContrast(obj->holder->model);
                obj->flags |= 1;
            }
        } else if (obj->type == 2 && obj->unknown1_4_ != NULL && obj->unknown1_4_->holder != NULL && obj->unknown1_4_->holder->model != NULL &&
                   !(obj->flags & 1)) {
            if (entry != NULL && !(entry->flags & 0x20)) {
                lighting->ModelTransformTintBrightnessContrast(obj->unknown1_4_->holder->model);
                obj->flags |= 1;
            }
        }
    }

    if (node->child != NULL) {
        func_ov001_021601f8(node->child, manager);
    }
    if (node->sibling != NULL) {
        func_ov001_021601f8(node->sibling, manager);
    }
}
