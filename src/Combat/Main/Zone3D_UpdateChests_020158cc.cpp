#include <globaldefs.h>
#include "World/LootableContainer.h"
#include "World/Zone3D.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/HWRegisters.h"

void G3X_Reset();
extern "C" void G3X_ResetMtxStack();
void G3i_LookAt_(int, int, int, int, void*);
void G3i_OrthoW_(int, int, int, int, int, int, int, int, void*);
extern "C" int ZoneChest_UpdateOpening(Zone3D*, int);
extern const Vector3fix Zone3D_chestIconViewTarget;
extern const Vector3fix Zone3D_chestIconViewUp;

// Main, originally func_020158cc (USA 0x020158cc, EUR 0x020158dc, JPN 0x02015698)
extern "C" ARM void Zone3D_UpdateChests(Zone3D* self) {
    if (LootableContainerManager::GetMainInstance() != NULL &&
        self->pUnknownStruct_8_ != NULL) {
        Vector3fix target = Zone3D_chestIconViewTarget;
        Vector3fix eye = {0};
        Vector3fix up = Zone3D_chestIconViewUp;
        G3X_Reset();
        G3X_ResetMtxStack();
        GXFIFO_MATRIX_MODE = 0; // projection
        G3i_LookAt_((int)&eye, (int)&up, (int)&target, 1, NULL);
        G3i_OrthoW_(0, 0xc0000, 0, 0x100000,
            -0x400000, 0x400000, 0x400000, 1, NULL);
        GXFIFO_MATRIX_MODE = 2; // position+vector
        for (int i = 0; i < self->numChests_; ++i)
            ZoneChest_UpdateOpening(self, i);
    }
}
