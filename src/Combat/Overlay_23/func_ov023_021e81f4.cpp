#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_ov023_021e81f4 {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknown_134_[0x5d8 - 0x78 - sizeof(CreationWindow)];
    void* text;
};

struct Struct_ov023_021e802c;
extern "C" void func_ov023_021e8cc0(struct Struct_ov023_021e802c* obj);
extern "C" void func_ov023_021e8cdc(void* obj);

// USA: func_ov023_021e81f4
// JPN: func_ov023_021e83a0
extern "C" ARM void func_ov023_021e81f4(void* obj) {
    Struct_ov023_021e81f4* state = static_cast<Struct_ov023_021e81f4*>(obj);
#if defined(jpn)
    const int var1 = 0x800;
#else
    const int var1 = 0x960;
#endif
    memset(state->text, 0, var1);
    func_ov023_021e8cc0(static_cast<Struct_ov023_021e802c*>(obj));
    Window_SetPaneText(((StructA0205d5d0*)(&state->window)), 0xc, ((int)(state->text)),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );

    memset(state->text, 0, var1);
    func_ov023_021e8cdc(obj);
    Window_SetPaneText(((StructA0205d5d0*)(&state->window)), 0xd, ((int)(state->text)),
#if defined(jpn)
                              1
#else
                              0, 1
#endif
    );
}
