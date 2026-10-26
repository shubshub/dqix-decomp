#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "World/BmdjScriptNode.h"
#include "std_library_functions.h"

// USA: func_0201e434
extern "C" ARM TileFeaturePlacementData* func_0201e434(ZoneFeatures* features, const char* name) {
    TileFeaturePlacementData* entry = features->unknown_30_;
    for (int i = 0; i < features->unknown_34_; i++, entry++) {
        if (strstr(entry->tilename, name) != NULL)
            return entry;
    }
    return NULL;
}
