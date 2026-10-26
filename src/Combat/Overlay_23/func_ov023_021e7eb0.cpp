#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/TryApplyElemFields.h"
#include "Resource/CharacterCreationUI.h"

namespace {
struct Struct_ov023_021e7eb0 {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknown_134_[0x5d8 - 0x78 - sizeof(CreationWindow)];
    char* text;
};
}

class Struct_ov023_021e7eb0_2 { public: virtual void inline_ov023_021e7eb0(); };
typedef void (Struct_ov023_021e7eb0_2::*Type_0200f3a4_4)();
struct Struct_ov023_021fd7e4 { Type_0200f3a4_4 unknown_0_[3]; };
#if defined(jpn)
#define data_ov023_021fd7e4 data_ov023_021fca68
#endif
extern const Struct_ov023_021fd7e4 data_ov023_021fd7e4;

extern "C" void func_02046380(void*);
extern "C" int MessageSystem_GetInstance(void);

// USA: func_ov023_021e7eb0
// JPN: func_ov023_021e8094
extern "C" ARM void func_ov023_021e7eb0(Struct_ov023_021e7eb0_2 *obj) {
	Struct_ov023_021e7eb0* state = ((Struct_ov023_021e7eb0*)(obj));
	Struct_ov023_021fd7e4 table = data_ov023_021fd7e4;
	int g = MessageSystem_GetInstance();
	for (unsigned char i = 0; i < 3; i++) {
		func_02046380((void*)g);
#if defined(jpn)
		memset(state->text, 0, 0x800);
#else
		memset(state->text, 0, 0x960);
#endif
		(obj->*table.unknown_0_[i])();
		Window_SetPaneText(((StructA0205d5d0*)(&state->window)), i, ((int)(state->text)), 1
#if !defined(jpn)
			, 0
#endif
		);
	}
}

#if defined(jpn)
#undef data_ov023_021fd7e4
#endif
