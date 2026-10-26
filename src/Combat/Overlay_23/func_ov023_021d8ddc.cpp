#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Struct_0205d67c;
extern "C" int func_0205d67c(struct Struct_0205d67c*);

// USA: func_ov023_021d8ddc
extern "C" ARM void func_ov023_021d8ddc(void* obj, int* arg1) {
    GameState::GetInstance();
    unsigned char* var0 = (unsigned char*)obj + 0x124;
    unsigned char count = *((unsigned char*)obj + 0x128);
    memset((char*)obj + 0xdc, 0, 0x10);
    for (int i = 0; i < count; i++) {
        *(int*)((char*)obj + 0xdc + i * 4) = arg1[var0[i]];
    }
    int flag = func_0205d67c((struct Struct_0205d67c*)((char*)obj + 0x20));
    if (flag == 0) {
        *((unsigned char*)obj + 0x11c) = 0;
    } else {
        *((unsigned char*)obj + 0x11c) = 1;
    }
    *((unsigned char*)obj + 0x11a) = 1;
}
