#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_ov023_021e7fe4 {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknown_134_[0x5d8 - 0x78 - sizeof(CreationWindow)];
    void* text;
};

extern "C" void func_ov023_021e868c(void*);

// USA: func_ov023_021e7fe4
// JPN: func_ov023_021e81bc
extern "C" ARM void func_ov023_021e7fe4(void* obj) {
    Struct_ov023_021e7fe4* state = static_cast<Struct_ov023_021e7fe4*>(obj);
#if defined(jpn)
    const int var1 = 0x800;
#else
    const int var1 = 0x960;
#endif
    memset(state->text, 0, var1);
    func_ov023_021e868c(obj);
    Window_SetPaneText(((StructA0205d5d0*)(&state->window)), 0xb, ((int)(state->text)), 1
#if !defined(jpn)
                              , 0
#endif
    );
}
