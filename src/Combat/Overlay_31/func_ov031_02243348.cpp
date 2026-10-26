#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/WirelessScanDescriptor.h"
#include "Resource/Script.h"

struct Struct02030b7c {
    int field0;
    void* field4;
};

struct Struct_ov031_02291e04_2 {
    unsigned char count;
#if defined(jpn)
    unsigned char pad0[3];
#else
    unsigned char pad0[4];
#endif
    unsigned char field5;
#if defined(jpn)
    unsigned char pad1[0x2b];
#else
    unsigned char pad1[0x26];
#endif
    Struct_ov031_0220ec04_3* entries;
};

extern Struct_ov031_02291e04_2 data_ov031_02291e04;

// USA: func_ov031_02243348
extern "C" ARM int func_ov031_02243348(struct Struct02030b7c* s) {
    void* target = (void*)((Script::Parameter*)s)->ToString();
    int matched = 0;
    int i = 0;
    while (i < data_ov031_02291e04.count) {
        Struct_ov031_0220ec04_3* entry = func_ov031_0220ec04(i);
        if (strcmp((char*)entry->ssid, (char*)target) == 0) {
            memcpy(&data_ov031_02291e04.entries[matched], entry, sizeof(*entry));
            matched++;
            if (matched >= 8) break;
        }
        i++;
    }
    data_ov031_02291e04.field5 = matched;
    return 1;
}
