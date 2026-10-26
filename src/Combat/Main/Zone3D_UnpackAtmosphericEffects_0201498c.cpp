#include <globaldefs.h>
#include "World/Zone3D.h"
#include "NitroSDK/NSBXX/NSBXX.h"

// Main, originally AccumulateHandleStats0201498c (USA 0x0201498c, EUR 0x0201499c, JPN 0x02014758)
ARM int Zone3D_UnpackAtmosphericEffects(void* zoneRaw) {
    Zone3D* zone = static_cast<Zone3D*>(zoneRaw);
    AtmosphericEffectSet* effects = &zone->atmosphericEffects_;
    if (!effects->IsArchiveLoaded())
        return 0;

    effects->ProcessArchive(effects, zone->pAllocator_68_, zone->vramState_);
    AtmosphericEffect* effect = effects->GetFirstEffect();
    while (effect != NULL) {
        Model3D* model = effect->object_.pModel_;
        if (model != NULL) {
            NSBXXTex* texture = model->GetTEX0();
            if (texture != NULL) {
                zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
            }
        }
        effect = effect->pNext_;
    }
    return 1;
}
