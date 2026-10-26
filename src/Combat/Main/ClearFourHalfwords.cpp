#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"

// USA: func_02032fb8
ARM void ClearFourHalfwords(struct Struct02032fb8* halfwords) {
    halfwords->x = 0;
    halfwords->y = 0;
    halfwords->z = 0;
    halfwords->w = 0;
}
