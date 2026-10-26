#include <globaldefs.h>

struct Struct_0204aa28 {
    unsigned int baseOffset;
    short firstTile;
    char unknown6[4];
    unsigned char unknown_a_;
};

// USA: func_0204aa28
extern "C" ARM unsigned int func_0204aa28(struct Struct_0204aa28* layout) {
    int var0 = 5;
    if (layout->unknown_a_) {
        var0 = 6;
    }
    return layout->baseOffset + (layout->firstTile << var0);
}
