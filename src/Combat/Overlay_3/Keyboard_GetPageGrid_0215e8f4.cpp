#include <globaldefs.h>

struct ByteArray_0215e8f4 {
    char pad[8];
    unsigned char* data;
    char pad2[2];
    short count;
};

struct Keyboard {
    char pad0[4];
    struct ByteArray_0215e8f4* layout;
    char pad4[0x1e - 8];
    unsigned char page;
};

// Overlay 3, originally FindEntryByMask_0215e8f4 (USA/EUR 0x0215e8f4; JPN not identified)
extern "C" ARM void* Keyboard_GetPageGrid(struct Keyboard* self) {
    struct ByteArray_0215e8f4* arr = self->layout;
    unsigned char mask = self->page;
    unsigned char* p = arr->data;
    int count = arr->count;
    int i;
    for (i = 0; i < count; i++, p += 8) {
        if (*p & mask) {
            return p;
        }
    }
    return NULL;
}
