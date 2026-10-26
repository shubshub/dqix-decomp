#include <globaldefs.h>

struct Struct_ov000_021761ec {
#if defined(jpn)
    char pad[0xf74];
#else
    char pad[0xd3c];
#endif
    int arr[8];
};

// USA: func_ov000_021761ec
extern "C" ARM int func_ov000_021761ec(char* base, int index) {
    if (index < 0 || index >= 8) index = 0;
    return ((struct Struct_ov000_021761ec*)(base + 0x1000))->arr[index];
}
