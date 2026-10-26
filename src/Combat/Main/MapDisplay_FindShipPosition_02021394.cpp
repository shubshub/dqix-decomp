#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02021394_2720 = 0x9d4 };
#else
enum { Enum_02021394_2720 = 0xaa0 };
#endif

struct Struct_02021394 {
    unsigned short key1;
    unsigned char key2;
    unsigned char pad3;
    short val1;
    short val2;
};

struct Container02021394 {
    unsigned char pad[Enum_02021394_2720];
    unsigned short count;
    struct Struct_02021394 entries[1];
};

// Main, originally FindEntryByKeyPair02021394 (USA 0x02021394, EUR 0x020213a4, JPN 0x02020f88)
extern "C" ARM int MapDisplay_FindShipPosition(struct Container02021394* c, int key1, int key2, short* out1, short* out2) {
    int i;
    for (i = 0; i < c->count; i++) {
        struct Struct_02021394* p = &c->entries[i];
        if (p->key1 == key1 && p->key2 == key2) {
            *out1 = p->val1;
            *out2 = p->val2;
            return 1;
        }
    }
    return 0;
}
