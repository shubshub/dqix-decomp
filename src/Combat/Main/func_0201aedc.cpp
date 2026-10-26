#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "World/Zone3D.h"

extern "C" int ZoneId_IsGrottoBossFloor(int x);

struct Struct_0201aedc;

extern "C" void RenderConfig_SetObjectRotation(void* arg0);

struct Struct_02012fe4;
struct Vector3i;

#if defined(jpn)
enum { Enum_0201aedc_9652 = 0x25f4 };
#else
enum { Enum_0201aedc_9652 = 0x25b4 };
#endif

// USA: func_0201aedc
extern "C" ARM void func_0201aedc(Zone3D* p) {
    if (ZoneId_IsGrottoBossFloor(p->currentZoneID_)) return;

    char* buf = (char*)p + Enum_0201aedc_9652;

    BmdjScriptNode* node = Zone3D_GetScriptNode(p, 5);
    if (node != 0) {
        BmdjSceneElement* var2 = node->elements;
        unsigned short flags = var2->flags;
        if (!(flags & BmdjElementFlag_Hidden)) {
            BmdjElementResource* ptr2 = var2->resource;
            Model3D* var5 = ptr2->model;
            if (var5 != 0 && var5->rawInternalModel_ != 0) {
                void* obj = LightingManager::GetInstance();
                NSBXXInternalModel* var7 = var5->rawInternalModel_;
                ((LightingManager*)((Struct_0201aedc*)obj))->ApplyAmbientColorToModel(var7);
                RenderConfig_SetObjectRotation(buf + 0x48);
                RenderConfig::SetObjectPosition((Vector3i*)(buf + 0x6c));
                RenderConfig::SubmitToFifo();
                var5->Draw(1);
            }
        }
    }

    BmdjScriptNode* node2 = Zone3D_GetScriptNode(p, 4);
    if (node2 == 0) return;
    BmdjSceneElement* var9 = node2->elements;
    unsigned short flagsb = var9->flags;
    if (flagsb & BmdjElementFlag_Hidden) return;
    BmdjElementResource* var11 = var9->resource;
    Model3D* var12 = var11->model;
    if (var12 != 0 && var12->rawInternalModel_ != 0) {
        void* obj2 = LightingManager::GetInstance();
        NSBXXInternalModel* var14 = var12->rawInternalModel_;
        ((LightingManager*)((Struct_0201aedc*)obj2))->ApplyAmbientColorToModel(var14);
        RenderConfig_SetObjectRotation(buf + 0x14);
        RenderConfig::SetObjectPosition((Vector3i*)(buf + 0x38));
        RenderConfig::SubmitToFifo();
        var12->Draw(1);
    }
}
