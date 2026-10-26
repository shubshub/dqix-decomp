#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;

struct Struct_020bc0a4 {
    unsigned char pad[0x34];
    unsigned short type;
    unsigned short unknown_36_;
    unsigned short id;
};

// USA: func_020bc0a4
extern "C" ARM int func_020bc0a4(int id) {
    int count = 0;
    SignedAllocatorHeader* e = data_0210f3d8.ElementAfter(NULL);
    if (e != NULL) {
        do {
            Struct_020bc0a4* entry = (Struct_020bc0a4*)e;
            if (entry->type == 1 && entry->id == id) count++;
            e = data_0210f3d8.ElementAfter(e);
        } while (e != NULL);
    }
    return count;
}
