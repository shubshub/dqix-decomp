#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e88c
ARM void ZoneFeatures::func_0201e88c(const Opcode7bEntry& src) {
    unsigned short count;
    Opcode7bEntry* dst;
    if (entries7b_ == NULL) {
        return;
    }
    count = arraySize7b_;
    arraySize7b_ = count + 1;
    dst = &entries7b_[count];
    dst->unknown_0_ = src.unknown_0_;
    dst->vector_c = src.vector_c;
    dst->unknown_18_ = src.unknown_18_;
    dst->minX = src.minX;
    dst->minZ = src.minZ;
    dst->maxX = src.maxX;
    dst->maxZ = src.maxZ;
}
