#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;

struct Struct_020bc0f8 {
    unsigned char pad[0x34];
    unsigned short type;
    unsigned short unknown_36_;
    unsigned short unknown_38_;
    unsigned short unknown_3a_;
};

// USA: func_020bc0f8
extern "C" ARM int func_020bc0f8(int a, int b) {
    int count = 0;
    SignedAllocatorHeader* e = data_0210f3d8.ElementAfter(NULL);
    if (e != NULL) {
        do {
            Struct_020bc0f8* entry = (Struct_020bc0f8*)e;
            if (entry->type == 2 && entry->unknown_38_ == a && entry->unknown_3a_ == b) count++;
            e = data_0210f3d8.ElementAfter(e);
        } while (e != NULL);
    }
    return count;
}
