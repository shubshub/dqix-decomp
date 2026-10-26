#include <globaldefs.h>

extern "C" void GameObject_Update(void* p);

// USA: func_02048144
ARM void Forward02048144(void* p) {
    GameObject_Update(p);
}
