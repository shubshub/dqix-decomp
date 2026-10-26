#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0208e2c0_3290 = 0xa7a };
#else
enum { Enum_0208e2c0_3290 = 0xcda };
#endif

#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct Entry02108ff4 {
    unsigned short a;
    unsigned char b;
    unsigned char c;
};
extern Entry02108ff4 data_02108ff4[];

// USA: func_0208e2c0
extern "C" ARM int func_0208e2c0(char* v) {
    unsigned char* var0 = (unsigned char*)GameState::GetInstance();
    Entry02108ff4* table = data_02108ff4;
    int var2 = ((Script::Parameter*)((Variant02030b0c*)v))->ToInt();
    v += 8;
    unsigned char id = (unsigned char)var2;
    var0 = var0 + 0x5000;
    for (int i = 0; i < 8; i++) {
        unsigned short var5 = (unsigned short)((Script::Parameter*)((Variant02030b0c*)v))->ToInt();
        unsigned char var6 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)(v + 8)))->ToInt();
        char* var7 = v + 0x10;
        v += 0x18;
        unsigned char var8 = (unsigned char)((Script::Parameter*)((Variant02030b0c*)var7))->ToInt();
        if (i == var0[Enum_0208e2c0_3290]) {
            table[id].a = var5;
            table[id].b = var6;
            table[id].c = var8;
            return 1;
        }
    }
    return 0;
}
