#include <globaldefs.h>
struct Struct_0205a254_3 { unsigned short unknown_0_; unsigned short unknown_2_; };
struct Struct_0205a254_2 {
    int unknown_0_; int unknown_4_; unsigned short unknown_8_, unknown_a_;
    Struct_0205a254_3* unknown_c_;
    unsigned short unknown_10_, unknown_12_;
    unsigned char unknown_14_, unknown_15_; unsigned short unknown_16_;
};
struct Container0205a3d0;
Elem0205a3d0* SpriteEntryList_Find(Container0205a3d0*, int);
void SetEntryFlag1ByKey0205a3ac(Container0205a3d0*, int);
// USA: func_0205a254
extern "C" ARM void func_0205a254(Container0205a3d0* container, int key, int delta) {
    Frame0205a254* frames;
    unsigned short elapsed;
    int frameOffset;
    unsigned short increment = delta;
    Elem0205a3d0* entry = SpriteEntryList_Find(container, key);
    if (!entry) return;
    if (!(entry->flags & 2) || !entry->mode) return;
    entry->elapsed += increment;
    frames = entry->frames;
    frameOffset = entry->index;
    const unsigned short& duration = frames[frameOffset].duration;
    elapsed = entry->elapsed;
    if (duration <= elapsed) {
        entry->elapsed = elapsed - duration;
        switch (entry->mode) {
        case 0: break;
        case 1:
            var4->unknown_10_++;
            var1 = var4->unknown_10_;
            if (var4->unknown_a_ > var1) return;
            {
                var4->unknown_10_ = var1 - 1;
                var4->unknown_12_ = var0[var2].unknown_0_;
                func_0205a3ac(arg0, var4->unknown_8_);
            }
            break;
        case 2:
            var4->unknown_10_++;
            if (var4->unknown_a_ <= var4->unknown_10_) var4->unknown_10_ = 0;
            break;
        case 3: break;
        case 4: break;
        }
    }
}
