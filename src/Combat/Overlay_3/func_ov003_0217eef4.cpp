// KEEP-NAME
// USA: func_ov003_0217eef4
#include <globaldefs.h>

struct Struct_ov003_0217eef4 {
    unsigned char unknown[0x1c];
    void* child;
};

extern "C" void CharacterCreationUI_UpdateVBlank(void*);

extern "C" ARM void func_ov003_0217eef4(Struct_ov003_0217eef4* owner) {
    if (owner->child) {
        CharacterCreationUI_UpdateVBlank(owner->child);
    }
}
