// KEEP-NAME
// USA: func_ov003_0217eef4
#include <globaldefs.h>

struct Obj0217eef4 {
    unsigned char unknown[0x1c];
    void* child;
};

extern "C" void CharacterCreationUI_UpdateVBlank(void*);

ARM void CallIfField1CSet_0217eef4(Obj0217eef4* owner) {
    if (owner->child) {
        CharacterCreationUI_UpdateVBlank(owner->child);
    }
}
