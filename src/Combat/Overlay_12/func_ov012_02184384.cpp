#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02184384 func_ov012_021853f8
#endif
#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif

#include "GameState/GameState.h"

struct Struct_ov012_02184384 {
    unsigned int lo : 19;
    signed int value : 11;
    unsigned int hi : 2;
};

// USA: func_ov012_02184384
extern "C" ARM int func_ov012_02184384(unsigned short* arr, int count) {
    char* base = (char*)GameState::GetInstance() + R(0x543c, 0x569c);
    int value = ((struct Struct_ov012_02184384*)(base + 4))->value;
    int i;
    for (i = 0; i < count; i++) {
        if (value == arr[i]) return i;
    }
    return -1;
}
