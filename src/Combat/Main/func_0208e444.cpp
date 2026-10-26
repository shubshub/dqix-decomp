#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0208e444_3290 = 0xa7a };
#else
enum { Enum_0208e444_3290 = 0xcda };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "Resource/GameResources.h"

struct Variant02030b0c;

struct Struct_02108fe4 {
    char pad[0xc];
    unsigned short* buf;
};
extern struct Struct_02108fe4 data_02108fe4;

// USA: func_0208e444
extern "C" ARM int func_0208e444(char* v) {
    unsigned char* p = (unsigned char*)GameState::GetInstance() + 0x5000;
    unsigned char var1 = p[Enum_0208e444_3290];
    unsigned char var2 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)v))->ToInt();
    v += 8;
    if (var1 == var2) {
        SafeAllocator* alloc = (SafeAllocator*)(((int)GetGameResources()) + 0x1a0);
        int buf = (int)alloc->Allocate(0x20);
        data_02108fe4.buf = (unsigned short*)buf;
        for (int i = 0; i < 0x10; i++) {
            unsigned short val = (unsigned short)((Script::Parameter*)((Variant02030b0c*)v))->ToInt();
            v += 8;
            *(unsigned short*)buf = val;
            buf += 2;
        }
    }
    return 1;
}
