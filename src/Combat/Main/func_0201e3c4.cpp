#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "std_library_functions.h"

// USA: func_0201e3c4
ARM void ZoneFeatures::func_0201e3c4(const TileFeaturePlacementData& data) {
    int count = unknown_34_;
    TileFeaturePlacementData* dst;
    if (count >= unknown_38_) {
        return;
    }
    dst = &unknown_30_[count];
    dst->unknown_0_ = data.unknown_0_;
    COPY_ARRAY(dst->directionBitmasks, data.directionBitmasks);
    COPY_ARRAY(dst->tilename, data.tilename);
    unknown_34_++;
}
