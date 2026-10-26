#include <globaldefs.h>

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" struct Elem0205a3d0* SpriteEntryList_Find(struct Container0205a3d0* c, int key);

// Main, originally SetEntryPosition_020e27ec (USA 0x020e27ec, EUR 0x020e27fc, JPN 0x020e438c)
extern "C" ARM void SpriteEntryList_SetPosition(struct Container0205a3d0* c, int key, short a, short b) {
    struct Elem0205a3d0* e = SpriteEntryList_Find(c, key);
    if (e != NULL) {
        *(short*)((char*)e + 0x4) = a;
        *(short*)((char*)e + 0x6) = b;
    }
}
