#include <globaldefs.h>

// The key list header Keyboard_FindKeyByAction walks: the keys (0x14 bytes each) and their capacity and count, then
// the page grids (8 bytes each: pages mask, columns, rows, cell count, key ids) and their capacity and count. The
// keys and grids are allocated by func_ov003_0215e750 / func_ov003_0215e85c and appended by the layout
// script's opcodes (func_ov003_0215e790 / func_ov003_0215e898), which stop at the capacity.
struct KeyboardLayout { int keys; short keyCapacity; short count; int grids; short gridCapacity; short gridCount; };

// Overlay 3, originally ResetStruct_0215e6d8 (USA/EUR 0x0215e6d8; JPN not identified)
extern "C" ARM void KeyboardLayout_Init(KeyboardLayout* layout) {
    layout->keys = 0;
    layout->keyCapacity = 0;
    layout->count = 0;
    layout->grids = 0;
    layout->gridCapacity = 0;
    layout->gridCount = 0;
}
