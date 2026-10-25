#include <globaldefs.h>

struct Container0205a3d0;
void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b);

struct WinObj020e28f0 {
    char pad0[0x1c];
    unsigned short key;
    char pad1[2];
    struct Container0205a3d0* container;
};

// USA: func_020e28f0
ARM void SetEntryPositionFromObject(struct WinObj020e28f0* obj, short a, short b) {
    SpriteEntryList_SetPosition(obj->container, obj->key, a, b);
}
