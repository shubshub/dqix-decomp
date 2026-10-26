#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"
struct SpriteContext0205ac40;

// USA: func_0205b174
extern "C" ARM int func_0205b174(SpriteContext0205ac40* unused, B174Outer* obj) {
    if (obj == 0) {
        return 0;
    }
    return ((unsigned int)obj->inner->flag >> 10) & 3;
}
