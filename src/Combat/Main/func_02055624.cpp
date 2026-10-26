#include "Graphics/Model3D.h"
#include <globaldefs.h>

// USA: func_02055624
extern "C" ARM void func_02055624(void* obj) {
    Model3D* x = *(Model3D**)((char*)obj + 0x1c);
    if (x == NULL) return;
    x->RestageTexturePalette();
}
