#include <globaldefs.h>
#include "World/BmdjScriptNode.h"
#include "std_library_functions.h"

// USA: func_02019f24
extern "C" ARM TileFeaturePlacementData* func_02019f24(TileFeaturePlacementData* destination, const TileFeaturePlacementData* source) {
    destination->unknown_0_ = source->unknown_0_;
    COPY_ARRAY(destination->directionBitmasks, source->directionBitmasks);
    COPY_ARRAY(destination->tilename, source->tilename);
    return destination;
}
