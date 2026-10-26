#include <globaldefs.h>
struct Struct_0205a254_3 { unsigned short duration; unsigned short field2; };
struct Elem0205a3d0 {
    int mode; int field4; unsigned short key, count;
    Struct_0205a254_3* frames;
    unsigned short index, elapsed;
    unsigned char field14, flags; unsigned short unknown_16_;
};
struct Container0205a3d0;
extern "C" Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);
extern "C" void func_0205a3ac(Container0205a3d0*, int);
// USA: func_0205a254
extern "C" ARM void func_0205a254(Container0205a3d0* container, int key, int delta) {
    Struct_0205a254_3* frames;
    unsigned short elapsed;
    int var2;
    unsigned short var3 = delta;
    Elem0205a3d0* entry = SpriteEntryList_Find(container, key);
    if (!entry) return;
    if (!(entry->flags & 2) || !entry->mode) return;
    entry->elapsed += var3;
    frames = entry->frames;
    var2 = entry->index;
    const unsigned short& duration = frames[var2].duration;
    elapsed = entry->elapsed;
    if (duration <= elapsed) {
        entry->elapsed = elapsed - duration;
        switch (entry->mode) {
        case 0: break;
        case 1:
            entry->index++;
            elapsed = entry->index;
            if (entry->count > elapsed) return;
            {
                entry->index = elapsed - 1;
                entry->elapsed = frames[var2].duration;
                func_0205a3ac(container, entry->key);
            }
            break;
        case 2:
            entry->index++;
            if (entry->count <= entry->index) entry->index = 0;
            break;
        case 3: break;
        case 4: break;
        }
    }
}
