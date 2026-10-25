#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* Zone3D_GetInstance(void);

void* ZoneFeatures_GetFirstOfType(unsigned char* obj, unsigned int index);

// USA: func_ov001_02160bc0
extern "C" ARM int func_ov001_02160bc0(void* arg0, int arg1) {
    int var0 = func_ov017_021d60f4(arg0);
    int var1 = func_ov017_021d60f4((char*)arg0 + 0x8);
    if (arg1 > 2) {
        func_ov017_021d60f4((char*)arg0 + 0x10);
    }
    Zone3D* list = (Zone3D*)Zone3D_GetInstance();
    ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&list->substruct_6c_, 2);
    while (node != NULL) {
        if ((node->unk_2c.type2.flags & 1) && node->unk_2c.type2.nodeId == a && node->unk_2c.type2.elementId == b) {
            node->unk_2c.type2.flags &= ~0x200;
            func_02018918(list, node);
        }
        var3 = var3->unknown_70_;
    }
    return 1;
}
