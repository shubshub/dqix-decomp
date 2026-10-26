#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02092d18_32630 = 0x7ca2 };
#else
enum { Enum_02092d18_32630 = 0x7f76 };
#endif

#include "GameState/GameState.h"

struct Struct_02092cd0;

// USA: func_02092d18
extern "C" ARM int func_02092d18(Struct_02092cd0*, int value) {
    unsigned char* bs = (unsigned char*)GameState::GetInstance();
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (value == (bs + i)[Enum_02092d18_32630]) {
            return (signed char)i;
        }
    }
    return -1;
}
