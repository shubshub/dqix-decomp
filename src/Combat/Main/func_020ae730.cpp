#include <globaldefs.h>

#include "World/Zone3D.h"

extern "C" void* Zone3D_GetInstance(void);
extern "C" void func_020ae694(int mode, int key1, unsigned short key2);
extern "C" void func_020ae4ec(int param0, int param1);

// USA: func_020ae730
extern "C" ARM void func_020ae730(int a) {
    if (((Zone3D*)Zone3D_GetInstance())->currentZoneID_ != 0x1edd) {
        return;
    }
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    ZoneFeatures::Opcode6aEntry* p = ZoneFeatures_GetEntry(&zone->substruct_6c_, 3);
    ZoneFeatures::Opcode6aEntry* q = ZoneFeatures_GetEntry(&zone->substruct_6c_, 4);
    if (p == NULL || q == NULL) {
        return;
    }
    if (a != 0) {
        p->unk_28 &= ~8;
        q->unk_28 &= ~8;
    } else {
        p->unk_28 |= 8;
        q->unk_28 |= 8;
    }
    func_020ae694(a, 0, 0x10);
    func_020ae4ec(6, a != 0);
}
