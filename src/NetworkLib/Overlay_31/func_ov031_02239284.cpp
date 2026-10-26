#include <globaldefs.h>

struct Struct_ov031_02239284 { unsigned char pad0[2]; unsigned short flags2; };
extern Struct_ov031_02239284* data_ov031_02290d14;

// USA: func_ov031_02239284
extern "C" ARM int func_ov031_02239284(unsigned char* name) {
    Struct_ov031_02239284* hdr = data_ov031_02290d14;
    unsigned int mask = 1;
    unsigned short bit = mask;
    unsigned short flags2 = hdr->flags2;
    do {
        if (flags2 & (mask << bit)) {
            int off = (bit - 1) * 0x1e;
            unsigned char* entry = (unsigned char*)hdr + 0x24 + off;
            if (name[0] == entry[0] && name[1] == entry[1] && name[2] == entry[2] &&
                name[3] == entry[3] && name[4] == entry[4] && name[5] == entry[5]) {
                return *(unsigned short*)((char*)hdr + off + 0x2a);
            }
        }
        bit++;
    } while (bit < 2);
    return 0;
}
