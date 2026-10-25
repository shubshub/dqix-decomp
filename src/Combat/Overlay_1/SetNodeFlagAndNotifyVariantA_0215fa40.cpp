#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* Zone3D_GetInstance(void);
void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);

// USA: func_ov001_0215fa40  (semantic: SetNodeFlagAndNotifyVariantA_0215fa40)
extern "C" ARM int func_ov001_0215fa40(char* args, int count) {
    int key0 = func_ov017_021d60f4(args);
    char* p = args + 0x8;
    args += 0x10;
    int key1 = func_ov017_021d60f4(p);
    int key2 = 1;
    int key3 = 1;
    if (count > 2) {
        key2 = func_ov017_021d60f4(args);
        args += 0x8;
    }
    if (count > 3) {
        key3 = func_ov017_021d60f4(args);
    }

    Zone3D* base = (Zone3D*)Zone3D_GetInstance();
    ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&base->substruct_6c_, 2);
    while (node != NULL) {
        if (!(node->unk_2c.type2.flags & 1) && node->unk_2c.type2.nodeId == key0 && node->unk_2c.type2.elementId == key1) {
            node->unk_2c.type2.flags = node->unk_2c.type2.flags | 0x200;
            Zone3D_OpenDoor(base, node, key2, key3, 0);
            BmdjSceneElement* entry = Zone3D_FindDoorElement(base, node);
            entry->flags |= 0x40;
        }
        node = node->pNext;
    }
    return 1;
}
