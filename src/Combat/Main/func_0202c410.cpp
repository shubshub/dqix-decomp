#include <globaldefs.h>
#if defined(jpn)
enum { Enum_0202c410_72 = 8 };
enum { Enum_0202c410_29950 = 0x72be };
#else
enum { Enum_0202c410_72 = 0x48 };
enum { Enum_0202c410_29950 = 0x74fe };
#endif

#include "GameState/GameState.h"

// USA: func_0202c410
extern "C" ARM void func_0202c410(void* obj) {
    *((unsigned char*)obj + 0x1029) |= Enum_0202c410_72;
    GameState* battleStruct = GameState::GetInstance();
    unsigned char buf[6];
    unsigned char* dst = buf;
    unsigned char* src = (unsigned char*)battleStruct + Enum_0202c410_29950;
    int n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
    dst = (unsigned char*)obj + 0x102c;
    src = buf;
    n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
}
