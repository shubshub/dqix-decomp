#include "Graphics/OBJImage.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"
#include <globaldefs.h>

// USA: func_02076738
extern "C" ARM int func_02076738(Struct_02075cdc *resource, const unsigned char *stream, int) {
    unsigned int var0;
    int var1;
    unsigned int var2;
    unsigned short var3;
    unsigned int entryIndex;
    int var5;
    if (resource->unknown_5e_ == 0) {
        var5 = (int) (DISPCNT & 0x300010);
    } else {
        var5 = (int) (DISPCNTSUB & 0x300010);
    }

    switch (var5) {
        case 0: return 0;
        case 0x10: var1 = 5; break;
        case 0x100010: var1 = 6; break;
        case 0x200010: var1 = 7; break;
        case 0x300010: var1 = 8; break;
        default: return 0;
    }

    unsigned short groupCount = 0;
    unsigned int format       = 0;
    memcpy(&groupCount, stream, 2);
    memcpy(&format, stream + 2, 2);
    stream += 4;

    var2 = 0;
    var3   = 0;
    while (var3 < groupCount) {
        unsigned short var8;
        unsigned short var9;
        unsigned int var10;
        memcpy(&var8, stream, 2);
        memcpy(&var9, stream + 2, 2);
        memcpy(&var10, stream + 4, 4);
        stream += 8;

        entryIndex    = 0;
        var0 = (1u << var1) - 1;

        while (entryIndex < var10) {
            unsigned short var11, var12, var13, var14;
            memcpy(&var11, stream, 2);
            memcpy(&var12, stream + 2, 2);
            memcpy(&var13, stream + 4, 2);
            memcpy(&var14, stream + 6, 2);

            stream += 8;
            unsigned int var15 = (8 << var13) * (8 << var14);
            if (format == 3) var15 = var15 >> 1;
            stream += var15;
            var2 += (var15 + var0) & ~var0;
            entryIndex++;
        }
        var3++;
    }
    return var2;
}
