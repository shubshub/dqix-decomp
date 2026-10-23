#include <globaldefs.h>

extern "C" void CharacterCreationUI_Draw3D(void* obj);

// USA: func_ov003_0217eedc
ARM void CallCallbackIfField1c_0217eedc(int* obj) {
    if (obj[7] != 0) {
        CharacterCreationUI_Draw3D((void*)obj[7]);
    }
}
