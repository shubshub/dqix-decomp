#include <globaldefs.h>

// The key list header Keyboard_FindKeyByAction walks: the keys at +0 and their count at +6.
struct ResetLayout_0215e6d8 { int keys; short unk_4; short count; int unk_8; short unk_c; short unk_e; };

// Overlay 3, originally ResetStruct_0215e6d8 (USA/EUR 0x0215e6d8; JPN not identified)
ARM void KeyboardLayout_Init(ResetLayout_0215e6d8* s) {
    s->keys = 0;
    s->unk_4 = 0;
    s->count = 0;
    s->unk_8 = 0;
    s->unk_c = 0;
    s->unk_e = 0;
}
