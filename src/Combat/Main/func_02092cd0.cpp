#include <globaldefs.h>

#if defined(jpn)
enum { Enum_02092cd0_32630 = 0x7ca2 };
#else
enum { Enum_02092cd0_32630 = 0x7f76 };
#endif

#include "GameState/GameState.h"

struct Struct_02092cd0;

// USA: func_02092cd0
extern "C" ARM unsigned int func_02092cd0(Struct_02092cd0*, int value) {
    unsigned char* bs = (unsigned char*)GameState::GetInstance();
    unsigned char count = 0;
    unsigned char i;
    for (i = 0; i < 4; i++) {
        if (value == (bs + i)[Enum_02092cd0_32630]) {
            count++;
        }
    }
    return count;
}
