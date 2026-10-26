#include <globaldefs.h>
#if defined(jpn)
enum { kBaseOffset = 0x2c4 };
enum { Enum_020ac3c8_29696 = 0x7000 };
#else
enum { kBaseOffset = 0x104 };
enum { Enum_020ac3c8_29696 = 0x7400 };
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

// USA: func_020ac3c8
extern "C" ARM int func_020ac3c8(unsigned int* dst, short* indices, int count) {
    char* base;
    int i;
    memset(dst, 0, 0x3c);
    base = (char*)GameState::GetInstance() + kBaseOffset;
    memcpy(dst, base + Enum_020ac3c8_29696, 0x3c);
    for (i = 0; i < count; i++) {
        short bit = indices[i];
        if (bit > 0) {
            dst[bit / 32] |= (1 << (bit % 32));
        }
    }
    memcpy(base + Enum_020ac3c8_29696, dst, 0x3c);
    return 1;
}
