#include <globaldefs.h>

extern "C" void CharacterCreationUI_Draw2D(void* obj);

// USA: func_ov003_0217eec4
ARM void CallCallbackIfField1c_0217eec4(int* obj) {
    if (obj[7] != 0) {
        CharacterCreationUI_Draw2D((void*)obj[7]);
    }
}
